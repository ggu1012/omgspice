/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4check.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 04/06/2001.
 * Modified by Xuemei Xi, 10/05/2001.
 * Modified by Xuemei Xi, 11/15/2002.
 * Modified by Xuemei Xi, 05/09/2003.
 * Modified by Xuemei Xi, 03/04/2004.
 * Modified by Xuemei Xi, 07/29/2005.
 * Modified by Mohan Dunga, 12/13/2006
 * Modified by Mohan Dunga, Wenwei Yang, 05/18/2007.
 * Modified by  Wenwei Yang, 07/31/2008 .
 * Modified by Tanvir Morshed, Darsen Lu 03/27/2011
 * Modified by Holger Vogt, 12/27/2020.
 **********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "omibsim4def.h"
#include "ngspice/trandefs.h"
#include "ngspice/const.h"
#include "ngspice/sperror.h"
#include "ngspice/devdefs.h"
#include "ngspice/suffix.h"
#include "ngspice/wordlist.h"
#include "ngspice/cpextern.h"



/* Check for correctness of the BSIM4.7 parameters:
   If parameter excursions are found, put the warning or error message into a wordlist. 
   Only then open a file omibsim4.out and print the data into the file. */
int
omiBSIM4checkModel(
omiBSIM4model *model,
omiBSIM4instance *here,
CKTcircuit *ckt)
{
    struct bsim4SizeDependParam *pParam;
    int Fatal_Flag = 0;
    FILE *fplog;
    wordlist* wl, *wlstart;

    pParam = here->pParam;

    if (cp_getvar("ng_nomodcheck", CP_BOOL, NULL, 0))
        return(0);

    wl = wlstart = TMALLOC(wordlist, 1);
    wl->wl_prev = NULL;
    wl->wl_next = NULL;
    wl->wl_word = tprintf("\nChecking parameters for BSIM 4.7 model %s\n", model->omiBSIM4modName);

    if ((here->omiBSIM4rgateMod == 2) || (here->omiBSIM4rgateMod == 3))
    {   if ((here->omiBSIM4trnqsMod == 1) || (here->omiBSIM4acnqsMod == 1)) {
            wl_append_word(&wl, &wl, tprintf("Warning: You've selected both Rg and charge deficit NQS; select one only.\n"));
        }
    }

    if (model->omiBSIM4toxe <= 0.0)
    {
         wl_append_word(&wl, &wl, tprintf("Fatal: Toxe = %g is not positive.\n",
            model->omiBSIM4toxe));
        Fatal_Flag = 1;
    }

    if (model->omiBSIM4toxp <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Toxp = %g is not positive.\n", model->omiBSIM4toxp));
        Fatal_Flag = 1;
    }

    if (model->omiBSIM4eot <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: EOT = %g is not positive.\n", model->omiBSIM4eot));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4epsrgate < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Epsrgate = %g is not positive.\n", model->omiBSIM4epsrgate));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4epsrsub < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Epsrsub = %g is not positive.\n", model->omiBSIM4epsrsub));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4easub < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Easub = %g is not positive.\n", model->omiBSIM4easub));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4ni0sub <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Easub = %g is not positive.\n", model->omiBSIM4ni0sub));
        Fatal_Flag = 1;
    }

    if (model->omiBSIM4toxm <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Toxm = %g is not positive.\n", model->omiBSIM4toxm));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4toxref <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Toxref = %g is not positive.\n", model->omiBSIM4toxref));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4lpe0 < -pParam->omiBSIM4leff)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Lpe0 = %g is less than -Leff.\n",
            pParam->omiBSIM4lpe0));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4lintnoi > pParam->omiBSIM4leff / 2)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Lintnoi = %g is too large - Leff for noise is negative.\n",
            model->omiBSIM4lintnoi));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4lpeb < -pParam->omiBSIM4leff)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Lpeb = %g is less than -Leff.\n",
            pParam->omiBSIM4lpeb));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4ndep <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Ndep = %g is not positive.\n",
            pParam->omiBSIM4ndep));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4phi <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Phi = %g is not positive. Please check Phin and Ndep\n",
            pParam->omiBSIM4phi));
        wl_append_word(&wl, &wl, tprintf("	   Phin = %g  Ndep = %g \n",
            pParam->omiBSIM4phin, pParam->omiBSIM4ndep));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4nsub <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Nsub = %g is not positive.\n",
            pParam->omiBSIM4nsub));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4ngate < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Ngate = %g Ngate is not positive.\n",
            pParam->omiBSIM4ngate));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4ngate > 1.e25)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Ngate = %g Ngate is too high\n",
            pParam->omiBSIM4ngate));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4xj <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Xj = %g is not positive.\n", pParam->omiBSIM4xj));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4dvt1 < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Dvt1 = %g is negative.\n", pParam->omiBSIM4dvt1));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4dvt1w < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Dvt1w = %g is negative.\n", pParam->omiBSIM4dvt1w));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4w0 == -pParam->omiBSIM4weff)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: (W0 + Weff) = 0 causing divided-by-zero.\n"));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4dsub < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Dsub = %g is negative.\n", pParam->omiBSIM4dsub));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4b1 == -pParam->omiBSIM4weff)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: (B1 + Weff) = 0 causing divided-by-zero.\n"));
        Fatal_Flag = 1;
    }
    if (here->omiBSIM4u0temp <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: u0 at current temperature = %g is not positive.\n",
            here->omiBSIM4u0temp));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4delta < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Delta = %g is less than zero.\n", pParam->omiBSIM4delta));
        Fatal_Flag = 1;
    }

    if (here->omiBSIM4vsattemp <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Vsat at current temperature = %g is not positive.\n",
            here->omiBSIM4vsattemp));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4pclm <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Pclm = %g is not positive.\n", pParam->omiBSIM4pclm));
        Fatal_Flag = 1;
    }

    if (pParam->omiBSIM4drout < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Drout = %g is negative.\n", pParam->omiBSIM4drout));
        Fatal_Flag = 1;
    }

    if (here->omiBSIM4m <= 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: multiplier = %g is not positive.\n", here->omiBSIM4m));
        Fatal_Flag = 1;
    }
    if (here->omiBSIM4nf < 1.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Number of finger = %g is smaller than one.\n", here->omiBSIM4nf));
        Fatal_Flag = 1;
    }

    if ((here->omiBSIM4sa > 0.0) && (here->omiBSIM4sb > 0.0) &&
        ((here->omiBSIM4nf == 1.0) || ((here->omiBSIM4nf > 1.0) && (here->omiBSIM4sd > 0.0))))
    {
        if (model->omiBSIM4saref <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Fatal: SAref = %g is not positive.\n", model->omiBSIM4saref));
            Fatal_Flag = 1;
        }
        if (model->omiBSIM4sbref <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Fatal: SBref = %g is not positive.\n", model->omiBSIM4sbref));
            Fatal_Flag = 1;
        }
    }

    if ((here->omiBSIM4l + model->omiBSIM4xl) <= model->omiBSIM4xgl)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: The parameter xgl must be smaller than Ldrawn+XL.\n"));
        Fatal_Flag = 1;
    }
    if (here->omiBSIM4ngcon < 1.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: The parameter ngcon cannot be smaller than one.\n"));
        Fatal_Flag = 1;
    }
    if ((here->omiBSIM4ngcon != 1.0) && (here->omiBSIM4ngcon != 2.0))
    {
        here->omiBSIM4ngcon = 1.0;
        wl_append_word(&wl, &wl, tprintf("Warning: Ngcon must be equal to one or two; reset to 1.0.\n"));
    }

    if (model->omiBSIM4gbmin < 1.0e-20)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Gbmin = %g is too small.\n", model->omiBSIM4gbmin));
    }

    /* Check saturation parameters */
    if (pParam->omiBSIM4fprout < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: fprout = %g is negative.\n", pParam->omiBSIM4fprout));
        Fatal_Flag = 1;
    }
    if (pParam->omiBSIM4pdits < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: pdits = %g is negative.\n", pParam->omiBSIM4pdits));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4pditsl < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: pditsl = %g is negative.\n", model->omiBSIM4pditsl));
        Fatal_Flag = 1;
    }

    /* Check gate current parameters */
    if (model->omiBSIM4igbMod) {
        if (pParam->omiBSIM4nigbinv <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Fatal: nigbinv = %g is non-positive.\n", pParam->omiBSIM4nigbinv));
            Fatal_Flag = 1;
        }
        if (pParam->omiBSIM4nigbacc <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Fatal: nigbacc = %g is non-positive.\n", pParam->omiBSIM4nigbacc));
            Fatal_Flag = 1;
        }
    }
    if (model->omiBSIM4igcMod) {
        if (pParam->omiBSIM4nigc <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Fatal: nigc = %g is non-positive.\n", pParam->omiBSIM4nigc));
            Fatal_Flag = 1;
        }
        if (pParam->omiBSIM4poxedge <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Fatal: poxedge = %g is non-positive.\n", pParam->omiBSIM4poxedge));
            Fatal_Flag = 1;
        }
        if (pParam->omiBSIM4pigcd <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Fatal: pigcd = %g is non-positive.\n", pParam->omiBSIM4pigcd));
            Fatal_Flag = 1;
        }
    }

    /* Check capacitance parameters */
    if (pParam->omiBSIM4clc < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Clc = %g is negative.\n", pParam->omiBSIM4clc));
        Fatal_Flag = 1;
    }

    /* Check overlap capacitance parameters */
    if (pParam->omiBSIM4ckappas < 0.02)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: ckappas = %g is too small.\n", pParam->omiBSIM4ckappas));
        pParam->omiBSIM4ckappas = 0.02;
    }
    if (pParam->omiBSIM4ckappad < 0.02)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: ckappad = %g is too small.\n", pParam->omiBSIM4ckappad));
        pParam->omiBSIM4ckappad = 0.02;
    }

    if (model->omiBSIM4vtss < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Vtss = %g is negative.\n",
            model->omiBSIM4vtss));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4vtsd < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Vtsd = %g is negative.\n",
            model->omiBSIM4vtsd));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4vtssws < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Vtssws = %g is negative.\n",
            model->omiBSIM4vtssws));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4vtsswd < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Vtsswd = %g is negative.\n",
            model->omiBSIM4vtsswd));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4vtsswgs < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Vtsswgs = %g is negative.\n",
            model->omiBSIM4vtsswgs));
        Fatal_Flag = 1;
    }
    if (model->omiBSIM4vtsswgd < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Fatal: Vtsswgd = %g is negative.\n",
            model->omiBSIM4vtsswgd));
        Fatal_Flag = 1;
    }


    if (model->omiBSIM4paramChk == 1)
    {
        /* Check L and W parameters */
        if (pParam->omiBSIM4leff <= 1.0e-9)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Leff = %g <= 1.0e-9. Recommended Leff >= 1e-8 \n",
                pParam->omiBSIM4leff));
        }

        if (pParam->omiBSIM4leffCV <= 1.0e-9)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Leff for CV = %g <= 1.0e-9. Recommended LeffCV >=1e-8 \n",
                pParam->omiBSIM4leffCV));
        }

        if (pParam->omiBSIM4weff <= 1.0e-9)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Weff = %g <= 1.0e-9. Recommended Weff >=1e-7 \n",
                pParam->omiBSIM4weff));
        }

        if (pParam->omiBSIM4weffCV <= 1.0e-9)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Weff for CV = %g <= 1.0e-9. Recommended WeffCV >= 1e-7 \n",
                pParam->omiBSIM4weffCV));
        }

        /* Check threshold voltage parameters */
        if (model->omiBSIM4toxe < 1.0e-10)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Toxe = %g is less than 1A. Recommended Toxe >= 5A\n", model->omiBSIM4toxe));
        }
        if (model->omiBSIM4toxp < 1.0e-10)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Toxp = %g is less than 1A. Recommended Toxp >= 5A\n", model->omiBSIM4toxp));
        }
        if (model->omiBSIM4toxm < 1.0e-10)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Toxm = %g is less than 1A. Recommended Toxm >= 5A\n", model->omiBSIM4toxm));
        }

        if (pParam->omiBSIM4ndep <= 1.0e12)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Ndep = %g may be too small.\n",
                pParam->omiBSIM4ndep));
        }
        else if (pParam->omiBSIM4ndep >= 1.0e21)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Ndep = %g may be too large.\n",
                pParam->omiBSIM4ndep));
        }

        if (pParam->omiBSIM4nsub <= 1.0e14)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Nsub = %g may be too small.\n",
                pParam->omiBSIM4nsub));
        }
        else if (pParam->omiBSIM4nsub >= 1.0e21)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Nsub = %g may be too large.\n",
                pParam->omiBSIM4nsub));
        }

        if ((pParam->omiBSIM4ngate > 0.0) &&
            (pParam->omiBSIM4ngate <= 1.e18))
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Ngate = %g is less than 1.E18cm^-3.\n",
                pParam->omiBSIM4ngate));
        }

        if (pParam->omiBSIM4dvt0 < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Dvt0 = %g is negative.\n", pParam->omiBSIM4dvt0));
        }

        if (fabs(1.0e-8 / (pParam->omiBSIM4w0 + pParam->omiBSIM4weff)) > 10.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: (W0 + Weff) may be too small.\n"));
        }

        /* Check subthreshold parameters */
        if (pParam->omiBSIM4nfactor < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Nfactor = %g is negative.\n", pParam->omiBSIM4nfactor));
        }
        if (pParam->omiBSIM4cdsc < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Cdsc = %g is negative.\n", pParam->omiBSIM4cdsc));
        }
        if (pParam->omiBSIM4cdscd < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Cdscd = %g is negative.\n", pParam->omiBSIM4cdscd));
        }
        /* Check DIBL parameters */
        if (here->omiBSIM4eta0 < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Eta0 = %g is negative.\n", here->omiBSIM4eta0));
        }

        /* Check Abulk parameters */
        if (fabs(1.0e-8 / (pParam->omiBSIM4b1 + pParam->omiBSIM4weff)) > 10.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: (B1 + Weff) may be too small.\n"));
        }


        /* Check Saturation parameters */
        if (pParam->omiBSIM4a2 < 0.01)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: A2 = %g is too small. Set to 0.01.\n",
                pParam->omiBSIM4a2));
            pParam->omiBSIM4a2 = 0.01;
        }
        else if (pParam->omiBSIM4a2 > 1.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: A2 = %g is larger than 1. A2 is set to 1 and A1 is set to 0.\n",
                pParam->omiBSIM4a2));
            pParam->omiBSIM4a2 = 1.0;
            pParam->omiBSIM4a1 = 0.0;
        }

        if (pParam->omiBSIM4prwg < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Prwg = %g is negative. Set to zero.\n",
                pParam->omiBSIM4prwg));
            pParam->omiBSIM4prwg = 0.0;
        }

        if (pParam->omiBSIM4rdsw < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Rdsw = %g is negative. Set to zero.\n",
                pParam->omiBSIM4rdsw));
            pParam->omiBSIM4rdsw = 0.0;
            pParam->omiBSIM4rds0 = 0.0;
        }

        if (pParam->omiBSIM4rds0 < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Rds at current temperature = %g is negative. Set to zero.\n",
                pParam->omiBSIM4rds0));
            pParam->omiBSIM4rds0 = 0.0;
        }

        if (pParam->omiBSIM4rdswmin < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Rdswmin at current temperature = %g is negative. Set to zero.\n",
                pParam->omiBSIM4rdswmin));
            pParam->omiBSIM4rdswmin = 0.0;
        }

        if (pParam->omiBSIM4pscbe2 <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Pscbe2 = %g is not positive.\n", pParam->omiBSIM4pscbe2));
        }

        if (pParam->omiBSIM4vsattemp < 1.0e3)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Vsat at current temperature = %g may be too small.\n", pParam->omiBSIM4vsattemp));
        }

        if ((model->omiBSIM4lambdaGiven) && (pParam->omiBSIM4lambda > 0.0))
        {
            if (pParam->omiBSIM4lambda > 1.0e-9)
            {
                wl_append_word(&wl, &wl, tprintf("Warning: Lambda = %g may be too large.\n", pParam->omiBSIM4lambda));
            }
        }

        if ((model->omiBSIM4vtlGiven) && (pParam->omiBSIM4vtl > 0.0))
        {
            if (pParam->omiBSIM4vtl < 6.0e4)
            {
                wl_append_word(&wl, &wl, tprintf("Warning: Thermal velocity vtl = %g may be too small.\n", pParam->omiBSIM4vtl));
            }

            if (pParam->omiBSIM4xn < 3.0)
            {
                wl_append_word(&wl, &wl, tprintf("Warning: back scattering coeff xn = %g is too small. Reset to 3.0 \n", pParam->omiBSIM4xn));
                pParam->omiBSIM4xn = 3.0;
            }

            if (model->omiBSIM4lc < 0.0)
            {
                wl_append_word(&wl, &wl, tprintf("Warning: back scattering coeff lc = %g is too small. Reset to 0.0\n", model->omiBSIM4lc));
                pParam->omiBSIM4lc = 0.0;
            }
        }

        if (pParam->omiBSIM4pdibl1 < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Pdibl1 = %g is negative.\n", pParam->omiBSIM4pdibl1));
        }
    }

    if (pParam->omiBSIM4pdibl2 < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Pdibl2 = %g is negative.\n", pParam->omiBSIM4pdibl2));
    }

    /* Check stress effect parameters */
    if ((here->omiBSIM4sa > 0.0) && (here->omiBSIM4sb > 0.0) &&
        ((here->omiBSIM4nf == 1.0) || ((here->omiBSIM4nf > 1.0) && (here->omiBSIM4sd > 0.0))))
    {
        if (model->omiBSIM4lodk2 <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: LODK2 = %g is not positive.\n", model->omiBSIM4lodk2));
        }
        if (model->omiBSIM4lodeta0 <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: LODETA0 = %g is not positive.\n", model->omiBSIM4lodeta0));
        }
    }

    /* Check gate resistance parameters */
    if (here->omiBSIM4rgateMod == 1)
    {
        if (model->omiBSIM4rshg <= 0.0)
            wl_append_word(&wl, &wl, tprintf("Warning: rshg should be positive for rgateMod = 1.\n"));
    }
    else if (here->omiBSIM4rgateMod == 2)
    {
        if (model->omiBSIM4rshg <= 0.0)
            wl_append_word(&wl, &wl, tprintf("Warning: rshg <= 0.0 for rgateMod = 2.\n"));
        else if (pParam->omiBSIM4xrcrg1 <= 0.0)
                wl_append_word(&wl, &wl, tprintf("Warning: xrcrg1 <= 0.0 for rgateMod = 2.\n"));
    }
    if (here->omiBSIM4rgateMod == 3)
    {
        if (model->omiBSIM4rshg <= 0.0)
            wl_append_word(&wl, &wl, tprintf("Warning: rshg should be positive for rgateMod = 3.\n"));
        else if (pParam->omiBSIM4xrcrg1 <= 0.0)
                wl_append_word(&wl, &wl, tprintf("Warning: xrcrg1 should be positive for rgateMod = 3.\n"));
    }

    /* Check capacitance parameters */
    if (pParam->omiBSIM4noff < 0.1)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Noff = %g is too small.\n", pParam->omiBSIM4noff));
    }

    if (pParam->omiBSIM4voffcv < -0.5)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Voffcv = %g is too small.\n", pParam->omiBSIM4voffcv));
    }

    if (pParam->omiBSIM4moin < 5.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Moin = %g is too small.\n", pParam->omiBSIM4moin));
    }
    if (pParam->omiBSIM4moin > 25.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Moin = %g is too large.\n", pParam->omiBSIM4moin));
    }
    if (model->omiBSIM4capMod == 2) {
        if (pParam->omiBSIM4acde < 0.1)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Acde = %g is too small.\n", pParam->omiBSIM4acde));
        }
        if (pParam->omiBSIM4acde > 1.6)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: Acde = %g is too large.\n", pParam->omiBSIM4acde));
        }
    }

    /* Check overlap capacitance parameters */
    if (model->omiBSIM4cgdo < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: cgdo = %g is negative. Set to zero.\n", model->omiBSIM4cgdo));
        model->omiBSIM4cgdo = 0.0;
    }
    if (model->omiBSIM4cgso < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: cgso = %g is negative. Set to zero.\n", model->omiBSIM4cgso));
        model->omiBSIM4cgso = 0.0;
    }
    if (model->omiBSIM4cgbo < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: cgbo = %g is negative. Set to zero.\n", model->omiBSIM4cgbo));
        model->omiBSIM4cgbo = 0.0;
    }
    /* v4.7 */
    if (model->omiBSIM4tnoiMod == 1 || model->omiBSIM4tnoiMod == 2) {
        if (model->omiBSIM4tnoia < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: tnoia = %g is negative. Set to zero.\n", model->omiBSIM4tnoia));
            model->omiBSIM4tnoia = 0.0;
        }
        if (model->omiBSIM4tnoib < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: tnoib = %g is negative. Set to zero.\n", model->omiBSIM4tnoib));
            model->omiBSIM4tnoib = 0.0;
        }

        if (model->omiBSIM4rnoia < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: rnoia = %g is negative. Set to zero.\n", model->omiBSIM4rnoia));
            model->omiBSIM4rnoia = 0.0;
        }
        if (model->omiBSIM4rnoib < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: rnoib = %g is negative. Set to zero.\n", model->omiBSIM4rnoib));
            model->omiBSIM4rnoib = 0.0;
        }
    }

    /* v4.7 */
    if (model->omiBSIM4tnoiMod == 2) { 
        if (model->omiBSIM4tnoic < 0.0) {
            wl_append_word(&wl, &wl, tprintf("Warning: tnoic = %g is negative. Set to zero.\n", model->omiBSIM4tnoic));
            model->omiBSIM4tnoic = 0.0;
        }
        if (model->omiBSIM4rnoic < 0.0) {
            wl_append_word(&wl, &wl, tprintf("Warning: rnoic = %g is negative. Set to zero.\n", model->omiBSIM4rnoic));
            model->omiBSIM4rnoic = 0.0;
        }
    }
    
    /* Limits of Njs and Njd modified in omiBSIM4.7 */
    if (model->omiBSIM4SjctEmissionCoeff < 0.1) {
        wl_append_word(&wl, &wl, tprintf("Warning: Njs = %g is less than 0.1. Setting Njs to 0.1.\n", model->omiBSIM4SjctEmissionCoeff));
            model->omiBSIM4SjctEmissionCoeff = 0.1;
    }
    else if (model->omiBSIM4SjctEmissionCoeff < 0.7) {
        wl_append_word(&wl, &wl, tprintf("Warning: Njs = %g is less than 0.7.\n", model->omiBSIM4SjctEmissionCoeff));
    }
    if (model->omiBSIM4DjctEmissionCoeff < 0.1)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Njd = %g is less than 0.1. Setting Njd to 0.1.\n", model->omiBSIM4DjctEmissionCoeff));
        model->omiBSIM4DjctEmissionCoeff = 0.1;
    }
    else if (model->omiBSIM4DjctEmissionCoeff < 0.7) {
        wl_append_word(&wl, &wl, tprintf("Warning: Njd = %g is less than 0.7.\n", model->omiBSIM4DjctEmissionCoeff));
    }

    if (model->omiBSIM4njtsstemp < 0.0) {
        wl_append_word(&wl, &wl, tprintf("Warning: Njts = %g is negative at temperature = %g.\n",
               model->omiBSIM4njtsstemp, ckt->CKTtemp));
    }
    if (model->omiBSIM4njtsswstemp < 0.0) {
        wl_append_word(&wl, &wl, tprintf("Warning: Njtssw = %g is negative at temperature = %g.\n",
                model->omiBSIM4njtsswstemp, ckt->CKTtemp));
    }
    if (model->omiBSIM4njtsswgstemp < 0.0) {
        wl_append_word(&wl, &wl, tprintf("Warning: Njtsswg = %g is negative at temperature = %g.\n",
                model->omiBSIM4njtsswgstemp, ckt->CKTtemp));
    }
    
    if (model->omiBSIM4njtsdGiven && model->omiBSIM4njtsdtemp < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Njtsd = %g is negative at temperature = %g.\n",
            model->omiBSIM4njtsdtemp, ckt->CKTtemp));
    }
    if (model->omiBSIM4njtsswdGiven && model->omiBSIM4njtsswdtemp < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Njtsswd = %g is negative at temperature = %g.\n",
            model->omiBSIM4njtsswdtemp, ckt->CKTtemp));
    }
    if (model->omiBSIM4njtsswgdGiven && model->omiBSIM4njtsswgdtemp < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: Njtsswgd = %g is negative at temperature = %g.\n",
            model->omiBSIM4njtsswgdtemp, ckt->CKTtemp));
    }

    if (model->omiBSIM4ntnoi < 0.0)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: ntnoi = %g is negative. Set to zero.\n", model->omiBSIM4ntnoi));
        model->omiBSIM4ntnoi = 0.0;
    }

    /* diode model */
    if (model->omiBSIM4SbulkJctBotGradingCoeff >= 0.99)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: MJS = %g is too big. Set to 0.99.\n", model->omiBSIM4SbulkJctBotGradingCoeff));
        model->omiBSIM4SbulkJctBotGradingCoeff = 0.99;
    }
    if (model->omiBSIM4SbulkJctSideGradingCoeff >= 0.99)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: MJSWS = %g is too big. Set to 0.99.\n", model->omiBSIM4SbulkJctSideGradingCoeff));
        model->omiBSIM4SbulkJctSideGradingCoeff = 0.99;
    }
    if (model->omiBSIM4SbulkJctGateSideGradingCoeff >= 0.99)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: MJSWGS = %g is too big. Set to 0.99.\n", model->omiBSIM4SbulkJctGateSideGradingCoeff));
        model->omiBSIM4SbulkJctGateSideGradingCoeff = 0.99;
    }

    if (model->omiBSIM4DbulkJctBotGradingCoeff >= 0.99)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: MJD = %g is too big. Set to 0.99.\n", model->omiBSIM4DbulkJctBotGradingCoeff));
        model->omiBSIM4DbulkJctBotGradingCoeff = 0.99;
    }
    if (model->omiBSIM4DbulkJctSideGradingCoeff >= 0.99)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: MJSWD = %g is too big. Set to 0.99.\n", model->omiBSIM4DbulkJctSideGradingCoeff));
        model->omiBSIM4DbulkJctSideGradingCoeff = 0.99;
    }
    if (model->omiBSIM4DbulkJctGateSideGradingCoeff >= 0.99)
    {
        wl_append_word(&wl, &wl, tprintf("Warning: MJSWGD = %g is too big. Set to 0.99.\n", model->omiBSIM4DbulkJctGateSideGradingCoeff));
        model->omiBSIM4DbulkJctGateSideGradingCoeff = 0.99;
    }
    if (model->omiBSIM4wpemod == 1)
    {
        if (model->omiBSIM4scref <= 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: SCREF = %g is not positive. Set to 1e-6.\n", model->omiBSIM4scref));
            model->omiBSIM4scref = 1e-6;
        }
        if (here->omiBSIM4sca < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: SCA = %g is negative. Set to 0.0.\n", here->omiBSIM4sca));
            here->omiBSIM4sca = 0.0;
        }
        if (here->omiBSIM4scb < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: SCB = %g is negative. Set to 0.0.\n", here->omiBSIM4scb));
            here->omiBSIM4scb = 0.0;
        }
        if (here->omiBSIM4scc < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: SCC = %g is negative. Set to 0.0.\n", here->omiBSIM4scc));
            here->omiBSIM4scc = 0.0;
        }
        if (here->omiBSIM4sc < 0.0)
        {
            wl_append_word(&wl, &wl, tprintf("Warning: SC = %g is negative. Set to 0.0.\n", here->omiBSIM4sc));
            here->omiBSIM4sc = 0.0;
        }
    }

    if (wlstart->wl_next) {
        if ((fplog = fopen("omibsim4.out", "w")) != NULL) {
            while (wlstart) {
                fprintf(fplog, "%s", wlstart->wl_word);
                fprintf(stderr, "%s", wlstart->wl_word);
                wlstart = wlstart->wl_next;
            }
            fclose(fplog);
        }
        else {
            while (wlstart) {
                fprintf(stderr, "%s", wlstart->wl_word);
                wlstart = wlstart->wl_next;
            }
        }
    }

    wl_free(wlstart);

    if ((strcmp(model->omiBSIM4version, "4.7.0")) && (strncmp(model->omiBSIM4version, "4.70", 4)) && (strncmp(model->omiBSIM4version, "4.7", 3)))
    {
        printf("Warning: This model is BSIM4.7.0; you specified a wrong version number '%s'.\n", model->omiBSIM4version);
    }

    return(Fatal_Flag);
}

