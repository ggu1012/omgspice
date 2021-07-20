/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4temp.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
  * Authors: 2008- Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 04/06/2001.
 * Modified by Xuemei Xi, 10/05/2001.
 * Modified by Xuemei Xi, 11/15/2002.
 * Modified by Xuemei Xi, 05/09/2003.
 * Modified by Xuemei Xi, 03/04/2004.
 * Modified by Xuemei Xi, Mohan Dunga, 07/29/2005.
 * Modified by Mohan Dunga, 12/13/2006.
 * Modified by Mohan Dunga, Wenwei Yang, 05/18/2007.
 * Modified by Wenwei Yang, 07/31/2008.
 * Modified by Tanvir Morshed, Darsen Lu 03/27/2011
 **********/


#include "ngspice/ngspice.h"
#include "ngspice/smpdefs.h"
#include "ngspice/cktdefs.h"
#include "omibsim4def.h"
#include "ngspice/const.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"

#define Kb 1.3806226e-23
#define KboQ 8.617087e-5
#define EPS0 8.85418e-12
#define EPSSI 1.03594e-10
#define PI 3.141592654
#define MAX_EXP 5.834617425e14
#define MIN_EXP 1.713908431e-15
#define EXP_THRESHOLD 34.0
#define Charge_q 1.60219e-19
#define DELTA  1.0E-9
#define DEXP(A,B) {                                                        \
        if (A > EXP_THRESHOLD) {                                           \
            B = MAX_EXP*(1.0+(A)-EXP_THRESHOLD);                           \
        } else if (A < -EXP_THRESHOLD)  {                                  \
            B = MIN_EXP;                                                   \
        } else   {                                                         \
            B = exp(A);                                                    \
        }                                                                  \
    }

static int
omiBSIM4DioIjthVjmEval(
double Nvtm, double Ijth, double Isb, double XExpBV,
double *Vjm)
{
double Tb, Tc, EVjmovNv;

       Tc = XExpBV;
       Tb = 1.0 + Ijth / Isb - Tc;
       EVjmovNv = 0.5 * (Tb + sqrt(Tb * Tb + 4.0 * Tc));
       *Vjm = Nvtm * log(EVjmovNv);

return 0;
}


int
omiBSIM4temp(
GENmodel *inModel,
CKTcircuit *ckt)
{
omiBSIM4model *model = (omiBSIM4model*) inModel;
omiBSIM4instance *here;
struct bsim4SizeDependParam *pSizeDependParamKnot, *pLastKnot, *pParam=NULL;
double tmp, tmp1, tmp2, tmp3, Eg, Eg0, ni, epssub;
double T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, Lnew=0.0, Wnew;
double delTemp, Temp, TRatio, Inv_L, Inv_W, Inv_LW, Vtm0, Tnom;
double dumPs, dumPd, dumAs, dumAd, PowWeffWr;
double DMCGeff, DMCIeff, DMDGeff;
double Nvtms, Nvtmd, SourceSatCurrent, DrainSatCurrent;
double T10, T11;
double Inv_saref, Inv_sbref, Inv_sa, Inv_sb, rho, Ldrn, dvth0_lod;
double W_tmp, Inv_ODeff, OD_offset, dk2_lod, deta0_lod;
double lnl, lnw, lnnf, rbpbx, rbpby, rbsbx, rbsby, rbdbx, rbdby,bodymode;
double kvsat, wlod, sceff, Wdrn;
double V0, lt1, ltw, Theta0, Delt_vth, Vth_NarrowW, Lpe_Vb, Vth;
double n,n0, Vgsteff, Vgs_eff, niter, toxpf, toxpi, Tcen, toxe, epsrox, vddeot;
double vtfbphi2eot, phieot, TempRatioeot, Vtm0eot, Vtmeot,vbieot;

int Size_Not_Found, i;

    /*  loop through all the omiBSIM4 device models */
    for (; model != NULL; model = omiBSIM4nextModel(model))
    {    Temp = ckt->CKTtemp;
         if (model->omiBSIM4SbulkJctPotential < 0.1)
         {   model->omiBSIM4SbulkJctPotential = 0.1;
             fprintf(stderr, "Given pbs is less than 0.1. Pbs is set to 0.1.\n");
         }
         if (model->omiBSIM4SsidewallJctPotential < 0.1)
         {   model->omiBSIM4SsidewallJctPotential = 0.1;
             fprintf(stderr, "Given pbsws is less than 0.1. Pbsws is set to 0.1.\n");
         }
         if (model->omiBSIM4SGatesidewallJctPotential < 0.1)
         {   model->omiBSIM4SGatesidewallJctPotential = 0.1;
             fprintf(stderr, "Given pbswgs is less than 0.1. Pbswgs is set to 0.1.\n");
         }

         if (model->omiBSIM4DbulkJctPotential < 0.1)
         {   model->omiBSIM4DbulkJctPotential = 0.1;
             fprintf(stderr, "Given pbd is less than 0.1. Pbd is set to 0.1.\n");
         }
         if (model->omiBSIM4DsidewallJctPotential < 0.1)
         {   model->omiBSIM4DsidewallJctPotential = 0.1;
             fprintf(stderr, "Given pbswd is less than 0.1. Pbswd is set to 0.1.\n");
         }
         if (model->omiBSIM4DGatesidewallJctPotential < 0.1)
         {   model->omiBSIM4DGatesidewallJctPotential = 0.1;
             fprintf(stderr, "Given pbswgd is less than 0.1. Pbswgd is set to 0.1.\n");
         }

         if(model->omiBSIM4mtrlMod == 0)
         {
             if ((model->omiBSIM4toxeGiven) && (model->omiBSIM4toxpGiven) && (model->omiBSIM4dtoxGiven)
                 && (model->omiBSIM4toxe != (model->omiBSIM4toxp + model->omiBSIM4dtox)))
                 printf("Warning: toxe, toxp and dtox all given and toxe != toxp + dtox; dtox ignored.\n");
             else if ((model->omiBSIM4toxeGiven) && (!model->omiBSIM4toxpGiven))
               model->omiBSIM4toxp = model->omiBSIM4toxe - model->omiBSIM4dtox;
             else if ((!model->omiBSIM4toxeGiven) && (model->omiBSIM4toxpGiven)){
               model->omiBSIM4toxe = model->omiBSIM4toxp + model->omiBSIM4dtox;
                 if (!model->omiBSIM4toxmGiven)                        /* v4.7 */
                     model->omiBSIM4toxm = model->omiBSIM4toxe;
             }
         }
         else if(model->omiBSIM4mtrlCompatMod != 0) /* v4.7 */
         {
             T0 = model->omiBSIM4epsrox / 3.9;
             if ((model->omiBSIM4eotGiven) && (model->omiBSIM4toxpGiven) && (model->omiBSIM4dtoxGiven)
                 && (ABS(model->omiBSIM4eot * T0 - (model->omiBSIM4toxp + model->omiBSIM4dtox)) > 1.0e-20))
             {
                 printf("Warning: eot, toxp and dtox all given and eot * EPSROX / 3.9 != toxp + dtox; dtox ignored.\n");
             }
             else if ((model->omiBSIM4eotGiven) && (!model->omiBSIM4toxpGiven))
               model->omiBSIM4toxp = T0 * model->omiBSIM4eot - model->omiBSIM4dtox;
             else if ((!model->omiBSIM4eotGiven) && (model->omiBSIM4toxpGiven)){
               model->omiBSIM4eot = (model->omiBSIM4toxp + model->omiBSIM4dtox) / T0;
                 if (!model->omiBSIM4toxmGiven)
                     model->omiBSIM4toxm = model->omiBSIM4eot;
             }
         }

         if(model->omiBSIM4mtrlMod)
           {
             epsrox = 3.9;
             toxe = model->omiBSIM4eot;
             epssub = EPS0 * model->omiBSIM4epsrsub;
           }
         else
           {
             epsrox = model->omiBSIM4epsrox;
             toxe = model->omiBSIM4toxe;
             epssub = EPSSI;
           }


         model->omiBSIM4coxe = epsrox * EPS0 / toxe;
         if(model->omiBSIM4mtrlMod == 0 || model->omiBSIM4mtrlCompatMod != 0)
           model->omiBSIM4coxp = model->omiBSIM4epsrox * EPS0 / model->omiBSIM4toxp;

         if (!model->omiBSIM4cgdoGiven)
         {   if (model->omiBSIM4dlcGiven && (model->omiBSIM4dlc > 0.0))
                 model->omiBSIM4cgdo = model->omiBSIM4dlc * model->omiBSIM4coxe
                                  - model->omiBSIM4cgdl ;
             else
                 model->omiBSIM4cgdo = 0.6 * model->omiBSIM4xj * model->omiBSIM4coxe;
         }
         if (!model->omiBSIM4cgsoGiven)
         {   if (model->omiBSIM4dlcGiven && (model->omiBSIM4dlc > 0.0))
                 model->omiBSIM4cgso = model->omiBSIM4dlc * model->omiBSIM4coxe
                                  - model->omiBSIM4cgsl ;
             else
                 model->omiBSIM4cgso = 0.6 * model->omiBSIM4xj * model->omiBSIM4coxe;
         }
         if (!model->omiBSIM4cgboGiven)
             model->omiBSIM4cgbo = 2.0 * model->omiBSIM4dwc * model->omiBSIM4coxe;

         struct bsim4SizeDependParam *p = model->pSizeDependParamKnot;
         while (p) {
             struct bsim4SizeDependParam *next_p = p->pNext;
             FREE(p);
             p = next_p;
         }
         model->pSizeDependParamKnot = NULL;
         pLastKnot = NULL;

         Tnom = model->omiBSIM4tnom;
         TRatio = Temp / Tnom;

         model->omiBSIM4vcrit = CONSTvt0 * log(CONSTvt0 / (CONSTroot2 * 1.0e-14));
         model->omiBSIM4factor1 = sqrt(epssub / (epsrox * EPS0)* toxe);

         Vtm0 = model->omiBSIM4vtm0 = KboQ * Tnom;

         if(model->omiBSIM4mtrlMod==0)
         {
             Eg0 = 1.16 - 7.02e-4 * Tnom * Tnom / (Tnom + 1108.0);
             ni = 1.45e10 * (Tnom / 300.15) * sqrt(Tnom / 300.15)
                 * exp(21.5565981 - Eg0 / (2.0 * Vtm0));
         }
         else
         {
           Eg0 = model->omiBSIM4bg0sub - model->omiBSIM4tbgasub * Tnom * Tnom
                                      / (Tnom + model->omiBSIM4tbgbsub);
           T0 =  model->omiBSIM4bg0sub - model->omiBSIM4tbgasub * 90090.0225
                                      / (300.15 + model->omiBSIM4tbgbsub);
           ni = model->omiBSIM4ni0sub * (Tnom / 300.15) * sqrt(Tnom / 300.15)
                 * exp((T0 - Eg0) / (2.0 * Vtm0));
         }

         model->omiBSIM4Eg0 = Eg0;
         model->omiBSIM4vtm = KboQ * Temp;
         if(model->omiBSIM4mtrlMod == 0)
           Eg = 1.16 - 7.02e-4 * Temp * Temp / (Temp + 1108.0);
         else
           Eg = model->omiBSIM4bg0sub - model->omiBSIM4tbgasub * Temp * Temp
                                      / (Temp + model->omiBSIM4tbgbsub);
         if (Temp != Tnom)
         {   T0 = Eg0 / Vtm0 - Eg / model->omiBSIM4vtm;
             T1 = log(Temp / Tnom);
             T2 = T0 + model->omiBSIM4SjctTempExponent * T1;
             T3 = exp(T2 / model->omiBSIM4SjctEmissionCoeff);
             model->omiBSIM4SjctTempSatCurDensity = model->omiBSIM4SjctSatCurDensity
                                               * T3;
             model->omiBSIM4SjctSidewallTempSatCurDensity
                         = model->omiBSIM4SjctSidewallSatCurDensity * T3;
             model->omiBSIM4SjctGateSidewallTempSatCurDensity
                         = model->omiBSIM4SjctGateSidewallSatCurDensity * T3;

             T2 = T0 + model->omiBSIM4DjctTempExponent * T1;
             T3 = exp(T2 / model->omiBSIM4DjctEmissionCoeff);
             model->omiBSIM4DjctTempSatCurDensity = model->omiBSIM4DjctSatCurDensity
                                               * T3;
             model->omiBSIM4DjctSidewallTempSatCurDensity
                         = model->omiBSIM4DjctSidewallSatCurDensity * T3;
             model->omiBSIM4DjctGateSidewallTempSatCurDensity
                         = model->omiBSIM4DjctGateSidewallSatCurDensity * T3;
         }
         else
         {   model->omiBSIM4SjctTempSatCurDensity = model->omiBSIM4SjctSatCurDensity;
             model->omiBSIM4SjctSidewallTempSatCurDensity
                        = model->omiBSIM4SjctSidewallSatCurDensity;
             model->omiBSIM4SjctGateSidewallTempSatCurDensity
                        = model->omiBSIM4SjctGateSidewallSatCurDensity;
             model->omiBSIM4DjctTempSatCurDensity = model->omiBSIM4DjctSatCurDensity;
             model->omiBSIM4DjctSidewallTempSatCurDensity
                        = model->omiBSIM4DjctSidewallSatCurDensity;
             model->omiBSIM4DjctGateSidewallTempSatCurDensity
                        = model->omiBSIM4DjctGateSidewallSatCurDensity;
         }

         if (model->omiBSIM4SjctTempSatCurDensity < 0.0)
             model->omiBSIM4SjctTempSatCurDensity = 0.0;
         if (model->omiBSIM4SjctSidewallTempSatCurDensity < 0.0)
             model->omiBSIM4SjctSidewallTempSatCurDensity = 0.0;
         if (model->omiBSIM4SjctGateSidewallTempSatCurDensity < 0.0)
             model->omiBSIM4SjctGateSidewallTempSatCurDensity = 0.0;
         if (model->omiBSIM4DjctTempSatCurDensity < 0.0)
             model->omiBSIM4DjctTempSatCurDensity = 0.0;
         if (model->omiBSIM4DjctSidewallTempSatCurDensity < 0.0)
             model->omiBSIM4DjctSidewallTempSatCurDensity = 0.0;
         if (model->omiBSIM4DjctGateSidewallTempSatCurDensity < 0.0)
             model->omiBSIM4DjctGateSidewallTempSatCurDensity = 0.0;

         /* Temperature dependence of D/B and S/B diode capacitance begins */
         delTemp = ckt->CKTtemp - model->omiBSIM4tnom;
         T0 = model->omiBSIM4tcj * delTemp;
         if (T0 >= -1.0)
         {   model->omiBSIM4SunitAreaTempJctCap = model->omiBSIM4SunitAreaJctCap *(1.0 + T0); /*bug_fix -JX */
             model->omiBSIM4DunitAreaTempJctCap = model->omiBSIM4DunitAreaJctCap *(1.0 + T0);
         }
         else
         {   if (model->omiBSIM4SunitAreaJctCap > 0.0)
             {   model->omiBSIM4SunitAreaTempJctCap = 0.0;
                 fprintf(stderr, "Temperature effect has caused cjs to be negative. Cjs is clamped to zero.\n");
             }
             if (model->omiBSIM4DunitAreaJctCap > 0.0)
             {   model->omiBSIM4DunitAreaTempJctCap = 0.0;
                 fprintf(stderr, "Temperature effect has caused cjd to be negative. Cjd is clamped to zero.\n");
             }
         }
         T0 = model->omiBSIM4tcjsw * delTemp;
                   if (model->omiBSIM4SunitLengthSidewallJctCap < 0.0)/*4.6.2*/
                      {model->omiBSIM4SunitLengthSidewallJctCap = 0.0;
                           fprintf(stderr, "CJSWS is negative. Cjsws is clamped to zero.\n");}
                  if (model->omiBSIM4DunitLengthSidewallJctCap < 0.0)
                      {model->omiBSIM4DunitLengthSidewallJctCap = 0.0;
                           fprintf(stderr, "CJSWD is negative. Cjswd is clamped to zero.\n");}
         if (T0 >= -1.0)
         {   model->omiBSIM4SunitLengthSidewallTempJctCap = model->omiBSIM4SunitLengthSidewallJctCap *(1.0 + T0);
             model->omiBSIM4DunitLengthSidewallTempJctCap = model->omiBSIM4DunitLengthSidewallJctCap *(1.0 + T0);
         }
         else
         {   if (model->omiBSIM4SunitLengthSidewallJctCap > 0.0)
             {   model->omiBSIM4SunitLengthSidewallTempJctCap = 0.0;
                 fprintf(stderr, "Temperature effect has caused cjsws to be negative. Cjsws is clamped to zero.\n");
             }
             if (model->omiBSIM4DunitLengthSidewallJctCap > 0.0)
             {   model->omiBSIM4DunitLengthSidewallTempJctCap = 0.0;
                 fprintf(stderr, "Temperature effect has caused cjswd to be negative. Cjswd is clamped to zero.\n");
             }
         }
         T0 = model->omiBSIM4tcjswg * delTemp;
         if (T0 >= -1.0)
         {   model->omiBSIM4SunitLengthGateSidewallTempJctCap = model->omiBSIM4SunitLengthGateSidewallJctCap *(1.0 + T0);
             model->omiBSIM4DunitLengthGateSidewallTempJctCap = model->omiBSIM4DunitLengthGateSidewallJctCap *(1.0 + T0);
         }
         else
         {   if (model->omiBSIM4SunitLengthGateSidewallJctCap > 0.0)
             {   model->omiBSIM4SunitLengthGateSidewallTempJctCap = 0.0;
                 fprintf(stderr, "Temperature effect has caused cjswgs to be negative. Cjswgs is clamped to zero.\n");
             }
             if (model->omiBSIM4DunitLengthGateSidewallJctCap > 0.0)
             {   model->omiBSIM4DunitLengthGateSidewallTempJctCap = 0.0;
                 fprintf(stderr, "Temperature effect has caused cjswgd to be negative. Cjswgd is clamped to zero.\n");
             }
         }

         model->omiBSIM4PhiBS = model->omiBSIM4SbulkJctPotential
                           - model->omiBSIM4tpb * delTemp;
         if (model->omiBSIM4PhiBS < 0.01)
         {   model->omiBSIM4PhiBS = 0.01;
             fprintf(stderr, "Temperature effect has caused pbs to be less than 0.01. Pbs is clamped to 0.01.\n");
         }
         model->omiBSIM4PhiBD = model->omiBSIM4DbulkJctPotential
                           - model->omiBSIM4tpb * delTemp;
         if (model->omiBSIM4PhiBD < 0.01)
         {   model->omiBSIM4PhiBD = 0.01;
             fprintf(stderr, "Temperature effect has caused pbd to be less than 0.01. Pbd is clamped to 0.01.\n");
         }

         model->omiBSIM4PhiBSWS = model->omiBSIM4SsidewallJctPotential
                             - model->omiBSIM4tpbsw * delTemp;
         if (model->omiBSIM4PhiBSWS <= 0.01)
         {   model->omiBSIM4PhiBSWS = 0.01;
             fprintf(stderr, "Temperature effect has caused pbsws to be less than 0.01. Pbsws is clamped to 0.01.\n");
         }
         model->omiBSIM4PhiBSWD = model->omiBSIM4DsidewallJctPotential
                             - model->omiBSIM4tpbsw * delTemp;
         if (model->omiBSIM4PhiBSWD <= 0.01)
         {   model->omiBSIM4PhiBSWD = 0.01;
             fprintf(stderr, "Temperature effect has caused pbswd to be less than 0.01. Pbswd is clamped to 0.01.\n");
         }

         model->omiBSIM4PhiBSWGS = model->omiBSIM4SGatesidewallJctPotential
                              - model->omiBSIM4tpbswg * delTemp;
         if (model->omiBSIM4PhiBSWGS <= 0.01)
         {   model->omiBSIM4PhiBSWGS = 0.01;
             fprintf(stderr, "Temperature effect has caused pbswgs to be less than 0.01. Pbswgs is clamped to 0.01.\n");
         }
         model->omiBSIM4PhiBSWGD = model->omiBSIM4DGatesidewallJctPotential
                              - model->omiBSIM4tpbswg * delTemp;
         if (model->omiBSIM4PhiBSWGD <= 0.01)
         {   model->omiBSIM4PhiBSWGD = 0.01;
             fprintf(stderr, "Temperature effect has caused pbswgd to be less than 0.01. Pbswgd is clamped to 0.01.\n");
         } /* End of junction capacitance */


         if (model->omiBSIM4ijthdfwd <= 0.0)
         {   model->omiBSIM4ijthdfwd = 0.0;
             fprintf(stderr, "Ijthdfwd reset to %g.\n", model->omiBSIM4ijthdfwd);
         }
         if (model->omiBSIM4ijthsfwd <= 0.0)
         {   model->omiBSIM4ijthsfwd = 0.0;
             fprintf(stderr, "Ijthsfwd reset to %g.\n", model->omiBSIM4ijthsfwd);
         }
         if (model->omiBSIM4ijthdrev <= 0.0)
         {   model->omiBSIM4ijthdrev = 0.0;
             fprintf(stderr, "Ijthdrev reset to %g.\n", model->omiBSIM4ijthdrev);
         }
         if (model->omiBSIM4ijthsrev <= 0.0)
         {   model->omiBSIM4ijthsrev = 0.0;
             fprintf(stderr, "Ijthsrev reset to %g.\n", model->omiBSIM4ijthsrev);
         }

         if ((model->omiBSIM4xjbvd <= 0.0) && (model->omiBSIM4dioMod == 2))
         {   model->omiBSIM4xjbvd = 0.0;
             fprintf(stderr, "Xjbvd reset to %g.\n", model->omiBSIM4xjbvd);
         }
         else if ((model->omiBSIM4xjbvd < 0.0) && (model->omiBSIM4dioMod == 0))
         {   model->omiBSIM4xjbvd = 0.0;
             fprintf(stderr, "Xjbvd reset to %g.\n", model->omiBSIM4xjbvd);
         }

         if (model->omiBSIM4bvd <= 0.0)   /*4.6.2*/
         {   model->omiBSIM4bvd = 0.0;
             fprintf(stderr, "BVD reset to %g.\n", model->omiBSIM4bvd);
         }

         if ((model->omiBSIM4xjbvs <= 0.0) && (model->omiBSIM4dioMod == 2))
         {   model->omiBSIM4xjbvs = 0.0;
             fprintf(stderr, "Xjbvs reset to %g.\n", model->omiBSIM4xjbvs);
         }
         else if ((model->omiBSIM4xjbvs < 0.0) && (model->omiBSIM4dioMod == 0))
         {   model->omiBSIM4xjbvs = 0.0;
             fprintf(stderr, "Xjbvs reset to %g.\n", model->omiBSIM4xjbvs);
         }

         if (model->omiBSIM4bvs <= 0.0)
         {   model->omiBSIM4bvs = 0.0;
             fprintf(stderr, "BVS reset to %g.\n", model->omiBSIM4bvs);
         }


         /* loop through all the instances of the model */
         for (here = omiBSIM4instances(model); here != NULL;
              here = omiBSIM4nextInstance(here))
         {
              pSizeDependParamKnot = model->pSizeDependParamKnot;
              Size_Not_Found = 1;
              while ((pSizeDependParamKnot != NULL) && Size_Not_Found)
              {   if ((here->omiBSIM4l == pSizeDependParamKnot->Length)
                      && (here->omiBSIM4w == pSizeDependParamKnot->Width)
                      && (here->omiBSIM4nf == pSizeDependParamKnot->NFinger))
                  {   Size_Not_Found = 0;
                      here->pParam = pSizeDependParamKnot;
                      pParam = here->pParam; /*bug-fix  */
                  }
                  else
                  {   pLastKnot = pSizeDependParamKnot;
                      pSizeDependParamKnot = pSizeDependParamKnot->pNext;
                  }
              }

              /* stress effect */
              Ldrn = here->omiBSIM4l;
              Wdrn = here->omiBSIM4w / here->omiBSIM4nf;

              if (Size_Not_Found)
              {   pParam = TMALLOC(struct bsim4SizeDependParam, 1);
                  if (pLastKnot == NULL)
                      model->pSizeDependParamKnot = pParam;
                  else
                      pLastKnot->pNext = pParam;
                  pParam->pNext = NULL;
                  here->pParam = pParam;

                  pParam->Length = here->omiBSIM4l;
                  pParam->Width = here->omiBSIM4w;
                  pParam->NFinger = here->omiBSIM4nf;
                  Lnew = here->omiBSIM4l  + model->omiBSIM4xl ;
                  Wnew = here->omiBSIM4w / here->omiBSIM4nf + model->omiBSIM4xw;

                  T0 = pow(Lnew, model->omiBSIM4Lln);
                  T1 = pow(Wnew, model->omiBSIM4Lwn);
                  tmp1 = model->omiBSIM4Ll / T0 + model->omiBSIM4Lw / T1
                       + model->omiBSIM4Lwl / (T0 * T1);
                  pParam->omiBSIM4dl = model->omiBSIM4Lint + tmp1;
                  tmp2 = model->omiBSIM4Llc / T0 + model->omiBSIM4Lwc / T1
                       + model->omiBSIM4Lwlc / (T0 * T1);
                  pParam->omiBSIM4dlc = model->omiBSIM4dlc + tmp2;

                  T2 = pow(Lnew, model->omiBSIM4Wln);
                  T3 = pow(Wnew, model->omiBSIM4Wwn);
                  tmp1 = model->omiBSIM4Wl / T2 + model->omiBSIM4Ww / T3
                       + model->omiBSIM4Wwl / (T2 * T3);
                  pParam->omiBSIM4dw = model->omiBSIM4Wint + tmp1;
                  tmp2 = model->omiBSIM4Wlc / T2 + model->omiBSIM4Wwc / T3
                       + model->omiBSIM4Wwlc / (T2 * T3);
                  pParam->omiBSIM4dwc = model->omiBSIM4dwc + tmp2;
                  pParam->omiBSIM4dwj = model->omiBSIM4dwj + tmp2;

                  pParam->omiBSIM4leff = Lnew - 2.0 * pParam->omiBSIM4dl;
                  if (pParam->omiBSIM4leff <= 0.0)
                  {
                      SPfrontEnd->IFerrorf(ERR_FATAL,
                      "omiBSIM4: mosfet %s, model %s: Effective channel length <= 0",
                       model->omiBSIM4modName, here->omiBSIM4name);
                      return(E_BADPARM);
                  }

                  pParam->omiBSIM4weff = Wnew - 2.0 * pParam->omiBSIM4dw;
                  if (pParam->omiBSIM4weff <= 0.0)
                  {
                      SPfrontEnd->IFerrorf(ERR_FATAL,
                      "omiBSIM4: mosfet %s, model %s: Effective channel width <= 0",
                       model->omiBSIM4modName, here->omiBSIM4name);
                      return(E_BADPARM);
                  }

                  pParam->omiBSIM4leffCV = Lnew - 2.0 * pParam->omiBSIM4dlc;
                  if (pParam->omiBSIM4leffCV <= 0.0)
                  {
                      SPfrontEnd->IFerrorf(ERR_FATAL,
                      "omiBSIM4: mosfet %s, model %s: Effective channel length for C-V <= 0",
                       model->omiBSIM4modName, here->omiBSIM4name);
                      return(E_BADPARM);
                  }

                  pParam->omiBSIM4weffCV = Wnew - 2.0 * pParam->omiBSIM4dwc;
                  if (pParam->omiBSIM4weffCV <= 0.0)
                  {
                      SPfrontEnd->IFerrorf(ERR_FATAL,
                      "omiBSIM4: mosfet %s, model %s: Effective channel width for C-V <= 0",
                       model->omiBSIM4modName, here->omiBSIM4name);
                      return(E_BADPARM);
                  }

                  pParam->omiBSIM4weffCJ = Wnew - 2.0 * pParam->omiBSIM4dwj;
                  if (pParam->omiBSIM4weffCJ <= 0.0)
                  {
                      SPfrontEnd->IFerrorf(ERR_FATAL,
                      "omiBSIM4: mosfet %s, model %s: Effective channel width for S/D junctions <= 0",
                       model->omiBSIM4modName, here->omiBSIM4name);
                      return(E_BADPARM);
                  }


                  if (model->omiBSIM4binUnit == 1)
                  {   Inv_L = 1.0e-6 / pParam->omiBSIM4leff;
                      Inv_W = 1.0e-6 / pParam->omiBSIM4weff;
                      Inv_LW = 1.0e-12 / (pParam->omiBSIM4leff
                             * pParam->omiBSIM4weff);
                  }
                  else
                  {   Inv_L = 1.0 / pParam->omiBSIM4leff;
                      Inv_W = 1.0 / pParam->omiBSIM4weff;
                      Inv_LW = 1.0 / (pParam->omiBSIM4leff
                             * pParam->omiBSIM4weff);
                  }
                  pParam->omiBSIM4cdsc = model->omiBSIM4cdsc
                                    + model->omiBSIM4lcdsc * Inv_L
                                    + model->omiBSIM4wcdsc * Inv_W
                                    + model->omiBSIM4pcdsc * Inv_LW;
                  pParam->omiBSIM4cdscb = model->omiBSIM4cdscb
                                     + model->omiBSIM4lcdscb * Inv_L
                                     + model->omiBSIM4wcdscb * Inv_W
                                     + model->omiBSIM4pcdscb * Inv_LW;

                      pParam->omiBSIM4cdscd = model->omiBSIM4cdscd
                                     + model->omiBSIM4lcdscd * Inv_L
                                     + model->omiBSIM4wcdscd * Inv_W
                                     + model->omiBSIM4pcdscd * Inv_LW;

                  pParam->omiBSIM4cit = model->omiBSIM4cit
                                   + model->omiBSIM4lcit * Inv_L
                                   + model->omiBSIM4wcit * Inv_W
                                   + model->omiBSIM4pcit * Inv_LW;
                  pParam->omiBSIM4nfactor = model->omiBSIM4nfactor
                                       + model->omiBSIM4lnfactor * Inv_L
                                       + model->omiBSIM4wnfactor * Inv_W
                                       + model->omiBSIM4pnfactor * Inv_LW;
                  pParam->omiBSIM4tnfactor = model->omiBSIM4tnfactor                        /* v4.7 */
                                       + model->omiBSIM4ltnfactor * Inv_L
                                       + model->omiBSIM4wtnfactor * Inv_W
                                       + model->omiBSIM4ptnfactor * Inv_LW;
                  pParam->omiBSIM4xj = model->omiBSIM4xj
                                  + model->omiBSIM4lxj * Inv_L
                                  + model->omiBSIM4wxj * Inv_W
                                  + model->omiBSIM4pxj * Inv_LW;
                  pParam->omiBSIM4vsat = model->omiBSIM4vsat
                                    + model->omiBSIM4lvsat * Inv_L
                                    + model->omiBSIM4wvsat * Inv_W
                                    + model->omiBSIM4pvsat * Inv_LW;
                  pParam->omiBSIM4at = model->omiBSIM4at
                                  + model->omiBSIM4lat * Inv_L
                                  + model->omiBSIM4wat * Inv_W
                                  + model->omiBSIM4pat * Inv_LW;
                  pParam->omiBSIM4a0 = model->omiBSIM4a0
                                  + model->omiBSIM4la0 * Inv_L
                                  + model->omiBSIM4wa0 * Inv_W
                                  + model->omiBSIM4pa0 * Inv_LW;

                  pParam->omiBSIM4ags = model->omiBSIM4ags
                                  + model->omiBSIM4lags * Inv_L
                                  + model->omiBSIM4wags * Inv_W
                                  + model->omiBSIM4pags * Inv_LW;

                  pParam->omiBSIM4a1 = model->omiBSIM4a1
                                  + model->omiBSIM4la1 * Inv_L
                                  + model->omiBSIM4wa1 * Inv_W
                                  + model->omiBSIM4pa1 * Inv_LW;
                  pParam->omiBSIM4a2 = model->omiBSIM4a2
                                  + model->omiBSIM4la2 * Inv_L
                                  + model->omiBSIM4wa2 * Inv_W
                                  + model->omiBSIM4pa2 * Inv_LW;
                  pParam->omiBSIM4keta = model->omiBSIM4keta
                                    + model->omiBSIM4lketa * Inv_L
                                    + model->omiBSIM4wketa * Inv_W
                                    + model->omiBSIM4pketa * Inv_LW;
                  pParam->omiBSIM4nsub = model->omiBSIM4nsub
                                    + model->omiBSIM4lnsub * Inv_L
                                    + model->omiBSIM4wnsub * Inv_W
                                    + model->omiBSIM4pnsub * Inv_LW;
                  pParam->omiBSIM4ndep = model->omiBSIM4ndep
                                    + model->omiBSIM4lndep * Inv_L
                                    + model->omiBSIM4wndep * Inv_W
                                    + model->omiBSIM4pndep * Inv_LW;
                  pParam->omiBSIM4nsd = model->omiBSIM4nsd
                                   + model->omiBSIM4lnsd * Inv_L
                                   + model->omiBSIM4wnsd * Inv_W
                                   + model->omiBSIM4pnsd * Inv_LW;
                  pParam->omiBSIM4phin = model->omiBSIM4phin
                                    + model->omiBSIM4lphin * Inv_L
                                    + model->omiBSIM4wphin * Inv_W
                                    + model->omiBSIM4pphin * Inv_LW;
                  pParam->omiBSIM4ngate = model->omiBSIM4ngate
                                     + model->omiBSIM4lngate * Inv_L
                                     + model->omiBSIM4wngate * Inv_W
                                     + model->omiBSIM4pngate * Inv_LW;
                  pParam->omiBSIM4gamma1 = model->omiBSIM4gamma1
                                      + model->omiBSIM4lgamma1 * Inv_L
                                      + model->omiBSIM4wgamma1 * Inv_W
                                      + model->omiBSIM4pgamma1 * Inv_LW;
                  pParam->omiBSIM4gamma2 = model->omiBSIM4gamma2
                                      + model->omiBSIM4lgamma2 * Inv_L
                                      + model->omiBSIM4wgamma2 * Inv_W
                                      + model->omiBSIM4pgamma2 * Inv_LW;
                  pParam->omiBSIM4vbx = model->omiBSIM4vbx
                                   + model->omiBSIM4lvbx * Inv_L
                                   + model->omiBSIM4wvbx * Inv_W
                                   + model->omiBSIM4pvbx * Inv_LW;
                  pParam->omiBSIM4vbm = model->omiBSIM4vbm
                                   + model->omiBSIM4lvbm * Inv_L
                                   + model->omiBSIM4wvbm * Inv_W
                                   + model->omiBSIM4pvbm * Inv_LW;
                  pParam->omiBSIM4xt = model->omiBSIM4xt
                                   + model->omiBSIM4lxt * Inv_L
                                   + model->omiBSIM4wxt * Inv_W
                                   + model->omiBSIM4pxt * Inv_LW;
                  pParam->omiBSIM4vfb = model->omiBSIM4vfb
                                   + model->omiBSIM4lvfb * Inv_L
                                   + model->omiBSIM4wvfb * Inv_W
                                   + model->omiBSIM4pvfb * Inv_LW;
                  pParam->omiBSIM4k1 = model->omiBSIM4k1
                                  + model->omiBSIM4lk1 * Inv_L
                                  + model->omiBSIM4wk1 * Inv_W
                                  + model->omiBSIM4pk1 * Inv_LW;
                  pParam->omiBSIM4kt1 = model->omiBSIM4kt1
                                   + model->omiBSIM4lkt1 * Inv_L
                                   + model->omiBSIM4wkt1 * Inv_W
                                   + model->omiBSIM4pkt1 * Inv_LW;
                  pParam->omiBSIM4kt1l = model->omiBSIM4kt1l
                                    + model->omiBSIM4lkt1l * Inv_L
                                    + model->omiBSIM4wkt1l * Inv_W
                                    + model->omiBSIM4pkt1l * Inv_LW;
                  pParam->omiBSIM4k2 = model->omiBSIM4k2
                                  + model->omiBSIM4lk2 * Inv_L
                                  + model->omiBSIM4wk2 * Inv_W
                                  + model->omiBSIM4pk2 * Inv_LW;
                  pParam->omiBSIM4kt2 = model->omiBSIM4kt2
                                   + model->omiBSIM4lkt2 * Inv_L
                                   + model->omiBSIM4wkt2 * Inv_W
                                   + model->omiBSIM4pkt2 * Inv_LW;
                  pParam->omiBSIM4k3 = model->omiBSIM4k3
                                  + model->omiBSIM4lk3 * Inv_L
                                  + model->omiBSIM4wk3 * Inv_W
                                  + model->omiBSIM4pk3 * Inv_LW;
                  pParam->omiBSIM4k3b = model->omiBSIM4k3b
                                   + model->omiBSIM4lk3b * Inv_L
                                   + model->omiBSIM4wk3b * Inv_W
                                   + model->omiBSIM4pk3b * Inv_LW;
                  pParam->omiBSIM4w0 = model->omiBSIM4w0
                                  + model->omiBSIM4lw0 * Inv_L
                                  + model->omiBSIM4ww0 * Inv_W
                                  + model->omiBSIM4pw0 * Inv_LW;
                  pParam->omiBSIM4lpe0 = model->omiBSIM4lpe0
                                    + model->omiBSIM4llpe0 * Inv_L
                                     + model->omiBSIM4wlpe0 * Inv_W
                                    + model->omiBSIM4plpe0 * Inv_LW;
                  pParam->omiBSIM4lpeb = model->omiBSIM4lpeb
                                    + model->omiBSIM4llpeb * Inv_L
                                    + model->omiBSIM4wlpeb * Inv_W
                                    + model->omiBSIM4plpeb * Inv_LW;
                  pParam->omiBSIM4dvtp0 = model->omiBSIM4dvtp0
                                     + model->omiBSIM4ldvtp0 * Inv_L
                                     + model->omiBSIM4wdvtp0 * Inv_W
                                     + model->omiBSIM4pdvtp0 * Inv_LW;
                  pParam->omiBSIM4dvtp1 = model->omiBSIM4dvtp1
                                     + model->omiBSIM4ldvtp1 * Inv_L
                                     + model->omiBSIM4wdvtp1 * Inv_W
                                     + model->omiBSIM4pdvtp1 * Inv_LW;
                  pParam->omiBSIM4dvtp2 = model->omiBSIM4dvtp2                 /* v4.7  */
                                     + model->omiBSIM4ldvtp2 * Inv_L
                                     + model->omiBSIM4wdvtp2 * Inv_W
                                     + model->omiBSIM4pdvtp2 * Inv_LW;
                  pParam->omiBSIM4dvtp3 = model->omiBSIM4dvtp3                 /* v4.7  */
                                     + model->omiBSIM4ldvtp3 * Inv_L
                                     + model->omiBSIM4wdvtp3 * Inv_W
                                     + model->omiBSIM4pdvtp3 * Inv_LW;
                  pParam->omiBSIM4dvtp4 = model->omiBSIM4dvtp4                 /* v4.7  */
                                     + model->omiBSIM4ldvtp4 * Inv_L
                                     + model->omiBSIM4wdvtp4 * Inv_W
                                     + model->omiBSIM4pdvtp4 * Inv_LW;
                  pParam->omiBSIM4dvtp5 = model->omiBSIM4dvtp5                 /* v4.7  */
                                     + model->omiBSIM4ldvtp5 * Inv_L
                                     + model->omiBSIM4wdvtp5 * Inv_W
                                     + model->omiBSIM4pdvtp5 * Inv_LW;
                  pParam->omiBSIM4dvt0 = model->omiBSIM4dvt0
                                    + model->omiBSIM4ldvt0 * Inv_L
                                    + model->omiBSIM4wdvt0 * Inv_W
                                    + model->omiBSIM4pdvt0 * Inv_LW;
                  pParam->omiBSIM4dvt1 = model->omiBSIM4dvt1
                                    + model->omiBSIM4ldvt1 * Inv_L
                                    + model->omiBSIM4wdvt1 * Inv_W
                                    + model->omiBSIM4pdvt1 * Inv_LW;
                  pParam->omiBSIM4dvt2 = model->omiBSIM4dvt2
                                    + model->omiBSIM4ldvt2 * Inv_L
                                    + model->omiBSIM4wdvt2 * Inv_W
                                    + model->omiBSIM4pdvt2 * Inv_LW;
                  pParam->omiBSIM4dvt0w = model->omiBSIM4dvt0w
                                    + model->omiBSIM4ldvt0w * Inv_L
                                    + model->omiBSIM4wdvt0w * Inv_W
                                    + model->omiBSIM4pdvt0w * Inv_LW;
                  pParam->omiBSIM4dvt1w = model->omiBSIM4dvt1w
                                    + model->omiBSIM4ldvt1w * Inv_L
                                    + model->omiBSIM4wdvt1w * Inv_W
                                    + model->omiBSIM4pdvt1w * Inv_LW;
                  pParam->omiBSIM4dvt2w = model->omiBSIM4dvt2w
                                    + model->omiBSIM4ldvt2w * Inv_L
                                    + model->omiBSIM4wdvt2w * Inv_W
                                    + model->omiBSIM4pdvt2w * Inv_LW;
                  pParam->omiBSIM4drout = model->omiBSIM4drout
                                     + model->omiBSIM4ldrout * Inv_L
                                     + model->omiBSIM4wdrout * Inv_W
                                     + model->omiBSIM4pdrout * Inv_LW;
                  pParam->omiBSIM4dsub = model->omiBSIM4dsub
                                    + model->omiBSIM4ldsub * Inv_L
                                    + model->omiBSIM4wdsub * Inv_W
                                    + model->omiBSIM4pdsub * Inv_LW;
                  pParam->omiBSIM4vth0 = model->omiBSIM4vth0
                                    + model->omiBSIM4lvth0 * Inv_L
                                    + model->omiBSIM4wvth0 * Inv_W
                                    + model->omiBSIM4pvth0 * Inv_LW;
                  pParam->omiBSIM4ua = model->omiBSIM4ua
                                  + model->omiBSIM4lua * Inv_L
                                  + model->omiBSIM4wua * Inv_W
                                  + model->omiBSIM4pua * Inv_LW;
                  pParam->omiBSIM4ua1 = model->omiBSIM4ua1
                                   + model->omiBSIM4lua1 * Inv_L
                                   + model->omiBSIM4wua1 * Inv_W
                                   + model->omiBSIM4pua1 * Inv_LW;
                  pParam->omiBSIM4ub = model->omiBSIM4ub
                                  + model->omiBSIM4lub * Inv_L
                                  + model->omiBSIM4wub * Inv_W
                                  + model->omiBSIM4pub * Inv_LW;
                  pParam->omiBSIM4ub1 = model->omiBSIM4ub1
                                   + model->omiBSIM4lub1 * Inv_L
                                   + model->omiBSIM4wub1 * Inv_W
                                   + model->omiBSIM4pub1 * Inv_LW;
                  pParam->omiBSIM4uc = model->omiBSIM4uc
                                  + model->omiBSIM4luc * Inv_L
                                  + model->omiBSIM4wuc * Inv_W
                                  + model->omiBSIM4puc * Inv_LW;
                  pParam->omiBSIM4uc1 = model->omiBSIM4uc1
                                   + model->omiBSIM4luc1 * Inv_L
                                   + model->omiBSIM4wuc1 * Inv_W
                                   + model->omiBSIM4puc1 * Inv_LW;
                  pParam->omiBSIM4ud = model->omiBSIM4ud
                                  + model->omiBSIM4lud * Inv_L
                                  + model->omiBSIM4wud * Inv_W
                                  + model->omiBSIM4pud * Inv_LW;
                  pParam->omiBSIM4ud1 = model->omiBSIM4ud1
                                  + model->omiBSIM4lud1 * Inv_L
                                  + model->omiBSIM4wud1 * Inv_W
                                  + model->omiBSIM4pud1 * Inv_LW;
                  pParam->omiBSIM4up = model->omiBSIM4up
                                  + model->omiBSIM4lup * Inv_L
                                  + model->omiBSIM4wup * Inv_W
                                  + model->omiBSIM4pup * Inv_LW;
                  pParam->omiBSIM4lp = model->omiBSIM4lp
                                  + model->omiBSIM4llp * Inv_L
                                  + model->omiBSIM4wlp * Inv_W
                                  + model->omiBSIM4plp * Inv_LW;
                  pParam->omiBSIM4eu = model->omiBSIM4eu
                                  + model->omiBSIM4leu * Inv_L
                                  + model->omiBSIM4weu * Inv_W
                                  + model->omiBSIM4peu * Inv_LW;
                  pParam->omiBSIM4u0 = model->omiBSIM4u0
                                  + model->omiBSIM4lu0 * Inv_L
                                  + model->omiBSIM4wu0 * Inv_W
                                  + model->omiBSIM4pu0 * Inv_LW;
                  pParam->omiBSIM4ute = model->omiBSIM4ute
                                   + model->omiBSIM4lute * Inv_L
                                   + model->omiBSIM4wute * Inv_W
                                   + model->omiBSIM4pute * Inv_LW;
                /*high k mobility*/
                 pParam->omiBSIM4ucs = model->omiBSIM4ucs
                                  + model->omiBSIM4lucs * Inv_L
                                  + model->omiBSIM4wucs * Inv_W
                                  + model->omiBSIM4pucs * Inv_LW;
                  pParam->omiBSIM4ucste = model->omiBSIM4ucste
                           + model->omiBSIM4lucste * Inv_L
                                   + model->omiBSIM4wucste * Inv_W
                                   + model->omiBSIM4pucste * Inv_LW;

                  pParam->omiBSIM4voff = model->omiBSIM4voff
                                    + model->omiBSIM4lvoff * Inv_L
                                    + model->omiBSIM4wvoff * Inv_W
                                    + model->omiBSIM4pvoff * Inv_LW;
                  pParam->omiBSIM4tvoff = model->omiBSIM4tvoff
                                    + model->omiBSIM4ltvoff * Inv_L
                                    + model->omiBSIM4wtvoff * Inv_W
                                    + model->omiBSIM4ptvoff * Inv_LW;
                  pParam->omiBSIM4minv = model->omiBSIM4minv
                                    + model->omiBSIM4lminv * Inv_L
                                    + model->omiBSIM4wminv * Inv_W
                                    + model->omiBSIM4pminv * Inv_LW;
                  pParam->omiBSIM4minvcv = model->omiBSIM4minvcv
                                    + model->omiBSIM4lminvcv * Inv_L
                                    + model->omiBSIM4wminvcv * Inv_W
                                    + model->omiBSIM4pminvcv * Inv_LW;
                  pParam->omiBSIM4fprout = model->omiBSIM4fprout
                                     + model->omiBSIM4lfprout * Inv_L
                                     + model->omiBSIM4wfprout * Inv_W
                                     + model->omiBSIM4pfprout * Inv_LW;
                  pParam->omiBSIM4pdits = model->omiBSIM4pdits
                                     + model->omiBSIM4lpdits * Inv_L
                                     + model->omiBSIM4wpdits * Inv_W
                                     + model->omiBSIM4ppdits * Inv_LW;
                  pParam->omiBSIM4pditsd = model->omiBSIM4pditsd
                                      + model->omiBSIM4lpditsd * Inv_L
                                      + model->omiBSIM4wpditsd * Inv_W
                                      + model->omiBSIM4ppditsd * Inv_LW;
                  pParam->omiBSIM4delta = model->omiBSIM4delta
                                     + model->omiBSIM4ldelta * Inv_L
                                     + model->omiBSIM4wdelta * Inv_W
                                     + model->omiBSIM4pdelta * Inv_LW;
                  pParam->omiBSIM4rdsw = model->omiBSIM4rdsw
                                    + model->omiBSIM4lrdsw * Inv_L
                                    + model->omiBSIM4wrdsw * Inv_W
                                    + model->omiBSIM4prdsw * Inv_LW;
                  pParam->omiBSIM4rdw = model->omiBSIM4rdw
                                    + model->omiBSIM4lrdw * Inv_L
                                    + model->omiBSIM4wrdw * Inv_W
                                    + model->omiBSIM4prdw * Inv_LW;
                  pParam->omiBSIM4rsw = model->omiBSIM4rsw
                                    + model->omiBSIM4lrsw * Inv_L
                                    + model->omiBSIM4wrsw * Inv_W
                                    + model->omiBSIM4prsw * Inv_LW;
                  pParam->omiBSIM4prwg = model->omiBSIM4prwg
                                    + model->omiBSIM4lprwg * Inv_L
                                    + model->omiBSIM4wprwg * Inv_W
                                    + model->omiBSIM4pprwg * Inv_LW;
                  pParam->omiBSIM4prwb = model->omiBSIM4prwb
                                    + model->omiBSIM4lprwb * Inv_L
                                    + model->omiBSIM4wprwb * Inv_W
                                    + model->omiBSIM4pprwb * Inv_LW;
                  pParam->omiBSIM4prt = model->omiBSIM4prt
                                    + model->omiBSIM4lprt * Inv_L
                                    + model->omiBSIM4wprt * Inv_W
                                    + model->omiBSIM4pprt * Inv_LW;
                  pParam->omiBSIM4eta0 = model->omiBSIM4eta0
                                    + model->omiBSIM4leta0 * Inv_L
                                    + model->omiBSIM4weta0 * Inv_W
                                    + model->omiBSIM4peta0 * Inv_LW;
                  pParam->omiBSIM4teta0 = model->omiBSIM4teta0                 /* v4.7  */
                                    + model->omiBSIM4lteta0 * Inv_L
                                    + model->omiBSIM4wteta0 * Inv_W
                                    + model->omiBSIM4pteta0 * Inv_LW;
                  pParam->omiBSIM4etab = model->omiBSIM4etab
                                    + model->omiBSIM4letab * Inv_L
                                    + model->omiBSIM4wetab * Inv_W
                                    + model->omiBSIM4petab * Inv_LW;
                  pParam->omiBSIM4pclm = model->omiBSIM4pclm
                                    + model->omiBSIM4lpclm * Inv_L
                                    + model->omiBSIM4wpclm * Inv_W
                                    + model->omiBSIM4ppclm * Inv_LW;
                  pParam->omiBSIM4pdibl1 = model->omiBSIM4pdibl1
                                      + model->omiBSIM4lpdibl1 * Inv_L
                                      + model->omiBSIM4wpdibl1 * Inv_W
                                      + model->omiBSIM4ppdibl1 * Inv_LW;
                  pParam->omiBSIM4pdibl2 = model->omiBSIM4pdibl2
                                      + model->omiBSIM4lpdibl2 * Inv_L
                                      + model->omiBSIM4wpdibl2 * Inv_W
                                      + model->omiBSIM4ppdibl2 * Inv_LW;
                  pParam->omiBSIM4pdiblb = model->omiBSIM4pdiblb
                                      + model->omiBSIM4lpdiblb * Inv_L
                                      + model->omiBSIM4wpdiblb * Inv_W
                                      + model->omiBSIM4ppdiblb * Inv_LW;
                  pParam->omiBSIM4pscbe1 = model->omiBSIM4pscbe1
                                      + model->omiBSIM4lpscbe1 * Inv_L
                                      + model->omiBSIM4wpscbe1 * Inv_W
                                      + model->omiBSIM4ppscbe1 * Inv_LW;
                  pParam->omiBSIM4pscbe2 = model->omiBSIM4pscbe2
                                      + model->omiBSIM4lpscbe2 * Inv_L
                                      + model->omiBSIM4wpscbe2 * Inv_W
                                      + model->omiBSIM4ppscbe2 * Inv_LW;
                  pParam->omiBSIM4pvag = model->omiBSIM4pvag
                                    + model->omiBSIM4lpvag * Inv_L
                                    + model->omiBSIM4wpvag * Inv_W
                                    + model->omiBSIM4ppvag * Inv_LW;
                  pParam->omiBSIM4wr = model->omiBSIM4wr
                                  + model->omiBSIM4lwr * Inv_L
                                  + model->omiBSIM4wwr * Inv_W
                                  + model->omiBSIM4pwr * Inv_LW;
                  pParam->omiBSIM4dwg = model->omiBSIM4dwg
                                   + model->omiBSIM4ldwg * Inv_L
                                   + model->omiBSIM4wdwg * Inv_W
                                   + model->omiBSIM4pdwg * Inv_LW;
                  pParam->omiBSIM4dwb = model->omiBSIM4dwb
                                   + model->omiBSIM4ldwb * Inv_L
                                   + model->omiBSIM4wdwb * Inv_W
                                   + model->omiBSIM4pdwb * Inv_LW;
                  pParam->omiBSIM4b0 = model->omiBSIM4b0
                                  + model->omiBSIM4lb0 * Inv_L
                                  + model->omiBSIM4wb0 * Inv_W
                                  + model->omiBSIM4pb0 * Inv_LW;
                  pParam->omiBSIM4b1 = model->omiBSIM4b1
                                  + model->omiBSIM4lb1 * Inv_L
                                  + model->omiBSIM4wb1 * Inv_W
                                  + model->omiBSIM4pb1 * Inv_LW;
                  pParam->omiBSIM4alpha0 = model->omiBSIM4alpha0
                                      + model->omiBSIM4lalpha0 * Inv_L
                                      + model->omiBSIM4walpha0 * Inv_W
                                      + model->omiBSIM4palpha0 * Inv_LW;
                  pParam->omiBSIM4alpha1 = model->omiBSIM4alpha1
                                      + model->omiBSIM4lalpha1 * Inv_L
                                      + model->omiBSIM4walpha1 * Inv_W
                                      + model->omiBSIM4palpha1 * Inv_LW;
                  pParam->omiBSIM4beta0 = model->omiBSIM4beta0
                                     + model->omiBSIM4lbeta0 * Inv_L
                                     + model->omiBSIM4wbeta0 * Inv_W
                                     + model->omiBSIM4pbeta0 * Inv_LW;
                  pParam->omiBSIM4agidl = model->omiBSIM4agidl
                                     + model->omiBSIM4lagidl * Inv_L
                                     + model->omiBSIM4wagidl * Inv_W
                                     + model->omiBSIM4pagidl * Inv_LW;
                  pParam->omiBSIM4bgidl = model->omiBSIM4bgidl
                                     + model->omiBSIM4lbgidl * Inv_L
                                     + model->omiBSIM4wbgidl * Inv_W
                                     + model->omiBSIM4pbgidl * Inv_LW;
                  pParam->omiBSIM4cgidl = model->omiBSIM4cgidl
                                     + model->omiBSIM4lcgidl * Inv_L
                                     + model->omiBSIM4wcgidl * Inv_W
                                     + model->omiBSIM4pcgidl * Inv_LW;
                  pParam->omiBSIM4egidl = model->omiBSIM4egidl
                                     + model->omiBSIM4legidl * Inv_L
                                     + model->omiBSIM4wegidl * Inv_W
                                     + model->omiBSIM4pegidl * Inv_LW;
                  pParam->omiBSIM4rgidl = model->omiBSIM4rgidl                /* v4.7 New GIDL/GISL */
                                     + model->omiBSIM4lrgidl * Inv_L
                                     + model->omiBSIM4wrgidl * Inv_W
                                     + model->omiBSIM4prgidl * Inv_LW;
                  pParam->omiBSIM4kgidl = model->omiBSIM4kgidl                /* v4.7 New GIDL/GISL */
                                     + model->omiBSIM4lkgidl * Inv_L
                                     + model->omiBSIM4wkgidl * Inv_W
                                     + model->omiBSIM4pkgidl * Inv_LW;
                  pParam->omiBSIM4fgidl = model->omiBSIM4fgidl                /* v4.7 New GIDL/GISL */
                                     + model->omiBSIM4lfgidl * Inv_L
                                     + model->omiBSIM4wfgidl * Inv_W
                                     + model->omiBSIM4pfgidl * Inv_LW;
                  pParam->omiBSIM4agisl = model->omiBSIM4agisl
                                     + model->omiBSIM4lagisl * Inv_L
                                     + model->omiBSIM4wagisl * Inv_W
                                     + model->omiBSIM4pagisl * Inv_LW;
                  pParam->omiBSIM4bgisl = model->omiBSIM4bgisl
                                     + model->omiBSIM4lbgisl * Inv_L
                                     + model->omiBSIM4wbgisl * Inv_W
                                     + model->omiBSIM4pbgisl * Inv_LW;
                  pParam->omiBSIM4cgisl = model->omiBSIM4cgisl
                                     + model->omiBSIM4lcgisl * Inv_L
                                     + model->omiBSIM4wcgisl * Inv_W
                                     + model->omiBSIM4pcgisl * Inv_LW;
                  pParam->omiBSIM4egisl = model->omiBSIM4egisl
                                     + model->omiBSIM4legisl * Inv_L
                                     + model->omiBSIM4wegisl * Inv_W
                                     + model->omiBSIM4pegisl * Inv_LW;
                   pParam->omiBSIM4rgisl = model->omiBSIM4rgisl                /* v4.7 New GIDL/GISL */
                                     + model->omiBSIM4lrgisl * Inv_L
                                     + model->omiBSIM4wrgisl * Inv_W
                                     + model->omiBSIM4prgisl * Inv_LW;
                  pParam->omiBSIM4kgisl = model->omiBSIM4kgisl                /* v4.7 New GIDL/GISL */
                                     + model->omiBSIM4lkgisl * Inv_L
                                     + model->omiBSIM4wkgisl * Inv_W
                                     + model->omiBSIM4pkgisl * Inv_LW;
                  pParam->omiBSIM4fgisl = model->omiBSIM4fgisl                /* v4.7 New GIDL/GISL */
                                     + model->omiBSIM4lfgisl * Inv_L
                                     + model->omiBSIM4wfgisl * Inv_W
                                     + model->omiBSIM4pfgisl * Inv_LW;
                  pParam->omiBSIM4aigc = model->omiBSIM4aigc
                                     + model->omiBSIM4laigc * Inv_L
                                     + model->omiBSIM4waigc * Inv_W
                                     + model->omiBSIM4paigc * Inv_LW;
                  pParam->omiBSIM4bigc = model->omiBSIM4bigc
                                     + model->omiBSIM4lbigc * Inv_L
                                     + model->omiBSIM4wbigc * Inv_W
                                     + model->omiBSIM4pbigc * Inv_LW;
                  pParam->omiBSIM4cigc = model->omiBSIM4cigc
                                     + model->omiBSIM4lcigc * Inv_L
                                     + model->omiBSIM4wcigc * Inv_W
                                     + model->omiBSIM4pcigc * Inv_LW;
                  pParam->omiBSIM4aigs = model->omiBSIM4aigs
                                     + model->omiBSIM4laigs * Inv_L
                                     + model->omiBSIM4waigs * Inv_W
                                     + model->omiBSIM4paigs * Inv_LW;
                  pParam->omiBSIM4bigs = model->omiBSIM4bigs
                                     + model->omiBSIM4lbigs * Inv_L
                                     + model->omiBSIM4wbigs * Inv_W
                                     + model->omiBSIM4pbigs * Inv_LW;
                  pParam->omiBSIM4cigs = model->omiBSIM4cigs
                                     + model->omiBSIM4lcigs * Inv_L
                                     + model->omiBSIM4wcigs * Inv_W
                                     + model->omiBSIM4pcigs * Inv_LW;
                  pParam->omiBSIM4aigd = model->omiBSIM4aigd
                                     + model->omiBSIM4laigd * Inv_L
                                     + model->omiBSIM4waigd * Inv_W
                                     + model->omiBSIM4paigd * Inv_LW;
                  pParam->omiBSIM4bigd = model->omiBSIM4bigd
                                     + model->omiBSIM4lbigd * Inv_L
                                     + model->omiBSIM4wbigd * Inv_W
                                     + model->omiBSIM4pbigd * Inv_LW;
                  pParam->omiBSIM4cigd = model->omiBSIM4cigd
                                     + model->omiBSIM4lcigd * Inv_L
                                     + model->omiBSIM4wcigd * Inv_W
                                     + model->omiBSIM4pcigd * Inv_LW;
                  pParam->omiBSIM4aigbacc = model->omiBSIM4aigbacc
                                       + model->omiBSIM4laigbacc * Inv_L
                                       + model->omiBSIM4waigbacc * Inv_W
                                       + model->omiBSIM4paigbacc * Inv_LW;
                  pParam->omiBSIM4bigbacc = model->omiBSIM4bigbacc
                                       + model->omiBSIM4lbigbacc * Inv_L
                                       + model->omiBSIM4wbigbacc * Inv_W
                                       + model->omiBSIM4pbigbacc * Inv_LW;
                  pParam->omiBSIM4cigbacc = model->omiBSIM4cigbacc
                                       + model->omiBSIM4lcigbacc * Inv_L
                                       + model->omiBSIM4wcigbacc * Inv_W
                                       + model->omiBSIM4pcigbacc * Inv_LW;
                  pParam->omiBSIM4aigbinv = model->omiBSIM4aigbinv
                                       + model->omiBSIM4laigbinv * Inv_L
                                       + model->omiBSIM4waigbinv * Inv_W
                                       + model->omiBSIM4paigbinv * Inv_LW;
                  pParam->omiBSIM4bigbinv = model->omiBSIM4bigbinv
                                       + model->omiBSIM4lbigbinv * Inv_L
                                       + model->omiBSIM4wbigbinv * Inv_W
                                       + model->omiBSIM4pbigbinv * Inv_LW;
                  pParam->omiBSIM4cigbinv = model->omiBSIM4cigbinv
                                       + model->omiBSIM4lcigbinv * Inv_L
                                       + model->omiBSIM4wcigbinv * Inv_W
                                       + model->omiBSIM4pcigbinv * Inv_LW;
                  pParam->omiBSIM4nigc = model->omiBSIM4nigc
                                       + model->omiBSIM4lnigc * Inv_L
                                       + model->omiBSIM4wnigc * Inv_W
                                       + model->omiBSIM4pnigc * Inv_LW;
                  pParam->omiBSIM4nigbacc = model->omiBSIM4nigbacc
                                       + model->omiBSIM4lnigbacc * Inv_L
                                       + model->omiBSIM4wnigbacc * Inv_W
                                       + model->omiBSIM4pnigbacc * Inv_LW;
                  pParam->omiBSIM4nigbinv = model->omiBSIM4nigbinv
                                       + model->omiBSIM4lnigbinv * Inv_L
                                       + model->omiBSIM4wnigbinv * Inv_W
                                       + model->omiBSIM4pnigbinv * Inv_LW;
                  pParam->omiBSIM4ntox = model->omiBSIM4ntox
                                    + model->omiBSIM4lntox * Inv_L
                                    + model->omiBSIM4wntox * Inv_W
                                    + model->omiBSIM4pntox * Inv_LW;
                  pParam->omiBSIM4eigbinv = model->omiBSIM4eigbinv
                                       + model->omiBSIM4leigbinv * Inv_L
                                       + model->omiBSIM4weigbinv * Inv_W
                                       + model->omiBSIM4peigbinv * Inv_LW;
                  pParam->omiBSIM4pigcd = model->omiBSIM4pigcd
                                     + model->omiBSIM4lpigcd * Inv_L
                                     + model->omiBSIM4wpigcd * Inv_W
                                     + model->omiBSIM4ppigcd * Inv_LW;
                  pParam->omiBSIM4poxedge = model->omiBSIM4poxedge
                                       + model->omiBSIM4lpoxedge * Inv_L
                                       + model->omiBSIM4wpoxedge * Inv_W
                                       + model->omiBSIM4ppoxedge * Inv_LW;
                  pParam->omiBSIM4xrcrg1 = model->omiBSIM4xrcrg1
                                      + model->omiBSIM4lxrcrg1 * Inv_L
                                      + model->omiBSIM4wxrcrg1 * Inv_W
                                      + model->omiBSIM4pxrcrg1 * Inv_LW;
                  pParam->omiBSIM4xrcrg2 = model->omiBSIM4xrcrg2
                                      + model->omiBSIM4lxrcrg2 * Inv_L
                                      + model->omiBSIM4wxrcrg2 * Inv_W
                                      + model->omiBSIM4pxrcrg2 * Inv_LW;
                  pParam->omiBSIM4lambda = model->omiBSIM4lambda
                                      + model->omiBSIM4llambda * Inv_L
                                      + model->omiBSIM4wlambda * Inv_W
                                      + model->omiBSIM4plambda * Inv_LW;
                  pParam->omiBSIM4vtl = model->omiBSIM4vtl
                                      + model->omiBSIM4lvtl * Inv_L
                                      + model->omiBSIM4wvtl * Inv_W
                                      + model->omiBSIM4pvtl * Inv_LW;
                  pParam->omiBSIM4xn = model->omiBSIM4xn
                                      + model->omiBSIM4lxn * Inv_L
                                      + model->omiBSIM4wxn * Inv_W
                                      + model->omiBSIM4pxn * Inv_LW;
                  pParam->omiBSIM4vfbsdoff = model->omiBSIM4vfbsdoff
                                      + model->omiBSIM4lvfbsdoff * Inv_L
                                      + model->omiBSIM4wvfbsdoff * Inv_W
                                      + model->omiBSIM4pvfbsdoff * Inv_LW;
                  pParam->omiBSIM4tvfbsdoff = model->omiBSIM4tvfbsdoff
                                      + model->omiBSIM4ltvfbsdoff * Inv_L
                                      + model->omiBSIM4wtvfbsdoff * Inv_W
                                      + model->omiBSIM4ptvfbsdoff * Inv_LW;

                  pParam->omiBSIM4cgsl = model->omiBSIM4cgsl
                                    + model->omiBSIM4lcgsl * Inv_L
                                    + model->omiBSIM4wcgsl * Inv_W
                                    + model->omiBSIM4pcgsl * Inv_LW;
                  pParam->omiBSIM4cgdl = model->omiBSIM4cgdl
                                    + model->omiBSIM4lcgdl * Inv_L
                                    + model->omiBSIM4wcgdl * Inv_W
                                    + model->omiBSIM4pcgdl * Inv_LW;
                  pParam->omiBSIM4ckappas = model->omiBSIM4ckappas
                                       + model->omiBSIM4lckappas * Inv_L
                                       + model->omiBSIM4wckappas * Inv_W
                                        + model->omiBSIM4pckappas * Inv_LW;
                  pParam->omiBSIM4ckappad = model->omiBSIM4ckappad
                                       + model->omiBSIM4lckappad * Inv_L
                                       + model->omiBSIM4wckappad * Inv_W
                                       + model->omiBSIM4pckappad * Inv_LW;
                  pParam->omiBSIM4cf = model->omiBSIM4cf
                                  + model->omiBSIM4lcf * Inv_L
                                  + model->omiBSIM4wcf * Inv_W
                                  + model->omiBSIM4pcf * Inv_LW;
                  pParam->omiBSIM4clc = model->omiBSIM4clc
                                   + model->omiBSIM4lclc * Inv_L
                                   + model->omiBSIM4wclc * Inv_W
                                   + model->omiBSIM4pclc * Inv_LW;
                  pParam->omiBSIM4cle = model->omiBSIM4cle
                                   + model->omiBSIM4lcle * Inv_L
                                   + model->omiBSIM4wcle * Inv_W
                                   + model->omiBSIM4pcle * Inv_LW;
                  pParam->omiBSIM4vfbcv = model->omiBSIM4vfbcv
                                     + model->omiBSIM4lvfbcv * Inv_L
                                     + model->omiBSIM4wvfbcv * Inv_W
                                     + model->omiBSIM4pvfbcv * Inv_LW;
                  pParam->omiBSIM4acde = model->omiBSIM4acde
                                    + model->omiBSIM4lacde * Inv_L
                                    + model->omiBSIM4wacde * Inv_W
                                    + model->omiBSIM4pacde * Inv_LW;
                  pParam->omiBSIM4moin = model->omiBSIM4moin
                                    + model->omiBSIM4lmoin * Inv_L
                                    + model->omiBSIM4wmoin * Inv_W
                                    + model->omiBSIM4pmoin * Inv_LW;
                  pParam->omiBSIM4noff = model->omiBSIM4noff
                                    + model->omiBSIM4lnoff * Inv_L
                                    + model->omiBSIM4wnoff * Inv_W
                                    + model->omiBSIM4pnoff * Inv_LW;
                  pParam->omiBSIM4voffcv = model->omiBSIM4voffcv
                                      + model->omiBSIM4lvoffcv * Inv_L
                                      + model->omiBSIM4wvoffcv * Inv_W
                                      + model->omiBSIM4pvoffcv * Inv_LW;
                  pParam->omiBSIM4kvth0we = model->omiBSIM4kvth0we
                                      + model->omiBSIM4lkvth0we * Inv_L
                                      + model->omiBSIM4wkvth0we * Inv_W
                                      + model->omiBSIM4pkvth0we * Inv_LW;
                  pParam->omiBSIM4k2we = model->omiBSIM4k2we
                                      + model->omiBSIM4lk2we * Inv_L
                                      + model->omiBSIM4wk2we * Inv_W
                                      + model->omiBSIM4pk2we * Inv_LW;
                  pParam->omiBSIM4ku0we = model->omiBSIM4ku0we
                                      + model->omiBSIM4lku0we * Inv_L
                                      + model->omiBSIM4wku0we * Inv_W
                                      + model->omiBSIM4pku0we * Inv_LW;

                  pParam->omiBSIM4abulkCVfactor = 1.0 + pow((pParam->omiBSIM4clc
                                             / pParam->omiBSIM4leffCV),
                                             pParam->omiBSIM4cle);

                  T0 = (TRatio - 1.0);

                  PowWeffWr = pow(pParam->omiBSIM4weffCJ * 1.0e6, pParam->omiBSIM4wr) * here->omiBSIM4nf;

                  T1 = T2 = T3 = T4 = 0.0;
                  pParam->omiBSIM4ucs = pParam->omiBSIM4ucs * pow(TRatio, pParam->omiBSIM4ucste);
                  if(model->omiBSIM4tempMod == 0)
                  {
                      pParam->omiBSIM4ua = pParam->omiBSIM4ua + pParam->omiBSIM4ua1 * T0;
                      pParam->omiBSIM4ub = pParam->omiBSIM4ub + pParam->omiBSIM4ub1 * T0;
                      pParam->omiBSIM4uc = pParam->omiBSIM4uc + pParam->omiBSIM4uc1 * T0;
                      pParam->omiBSIM4ud = pParam->omiBSIM4ud + pParam->omiBSIM4ud1 * T0;
                      pParam->omiBSIM4vsattemp = pParam->omiBSIM4vsat - pParam->omiBSIM4at * T0;
                      T10 = pParam->omiBSIM4prt * T0;
                      if(model->omiBSIM4rdsMod)
                      {
                            /* External Rd(V) */
                            T1 = pParam->omiBSIM4rdw + T10;
                            T2 = model->omiBSIM4rdwmin + T10;
                            /* External Rs(V) */
                            T3 = pParam->omiBSIM4rsw + T10;
                            T4 = model->omiBSIM4rswmin + T10;
                      }
                      /* Internal Rds(V) in IV */
                      pParam->omiBSIM4rds0 = (pParam->omiBSIM4rdsw + T10)
                                            * here->omiBSIM4nf / PowWeffWr;
                      pParam->omiBSIM4rdswmin = (model->omiBSIM4rdswmin + T10)
                                               * here->omiBSIM4nf / PowWeffWr;
                  }
                  else
                  {
                      if (model->omiBSIM4tempMod == 3)
                      {
                          pParam->omiBSIM4ua = pParam->omiBSIM4ua * pow(TRatio, pParam->omiBSIM4ua1) ;
                            pParam->omiBSIM4ub = pParam->omiBSIM4ub * pow(TRatio, pParam->omiBSIM4ub1);
                            pParam->omiBSIM4uc = pParam->omiBSIM4uc * pow(TRatio, pParam->omiBSIM4uc1);
                            pParam->omiBSIM4ud = pParam->omiBSIM4ud * pow(TRatio, pParam->omiBSIM4ud1);
                      }
                      else
                      {
                          /* tempMod = 1, 2 */
                            pParam->omiBSIM4ua = pParam->omiBSIM4ua * (1.0 + pParam->omiBSIM4ua1 * delTemp) ;
                            pParam->omiBSIM4ub = pParam->omiBSIM4ub * (1.0 + pParam->omiBSIM4ub1 * delTemp);
                            pParam->omiBSIM4uc = pParam->omiBSIM4uc * (1.0 + pParam->omiBSIM4uc1 * delTemp);
                            pParam->omiBSIM4ud = pParam->omiBSIM4ud * (1.0 + pParam->omiBSIM4ud1 * delTemp);
                      }
                      pParam->omiBSIM4vsattemp = pParam->omiBSIM4vsat * (1.0 - pParam->omiBSIM4at * delTemp);
                      T10 = 1.0 + pParam->omiBSIM4prt * delTemp;
                      if(model->omiBSIM4rdsMod)
                      {
                            /* External Rd(V) */
                            T1 = pParam->omiBSIM4rdw * T10;
                            T2 = model->omiBSIM4rdwmin * T10;

                            /* External Rs(V) */
                            T3 = pParam->omiBSIM4rsw * T10;
                            T4 = model->omiBSIM4rswmin * T10;
                      }
                      /* Internal Rds(V) in IV */
                      pParam->omiBSIM4rds0 = pParam->omiBSIM4rdsw * T10 * here->omiBSIM4nf / PowWeffWr;
                      pParam->omiBSIM4rdswmin = model->omiBSIM4rdswmin * T10 * here->omiBSIM4nf / PowWeffWr;
                  }

                  if (T1 < 0.0)
                  {   T1 = 0.0;
                      printf("Warning: Rdw at current temperature is negative; set to 0.\n");
                  }
                  if (T2 < 0.0)
                  {   T2 = 0.0;
                      printf("Warning: Rdwmin at current temperature is negative; set to 0.\n");
                  }
                  pParam->omiBSIM4rd0 = T1 / PowWeffWr;
                  pParam->omiBSIM4rdwmin = T2 / PowWeffWr;
                  if (T3 < 0.0)
                  {   T3 = 0.0;
                      printf("Warning: Rsw at current temperature is negative; set to 0.\n");
                  }
                  if (T4 < 0.0)
                  {   T4 = 0.0;
                      printf("Warning: Rswmin at current temperature is negative; set to 0.\n");
                  }
                  pParam->omiBSIM4rs0 = T3 / PowWeffWr;
                  pParam->omiBSIM4rswmin = T4 / PowWeffWr;

                  if (pParam->omiBSIM4u0 > 1.0)
                      pParam->omiBSIM4u0 = pParam->omiBSIM4u0 / 1.0e4;

                  /* mobility channel length dependence */
                  T5 = 1.0 - pParam->omiBSIM4up * exp( - pParam->omiBSIM4leff / pParam->omiBSIM4lp);
                  pParam->omiBSIM4u0temp = pParam->omiBSIM4u0 * T5
                                      * pow(TRatio, pParam->omiBSIM4ute);
                  if (pParam->omiBSIM4eu < 0.0)
                  {   pParam->omiBSIM4eu = 0.0;
                      printf("Warning: eu has been negative; reset to 0.0.\n");
                  }
                  if (pParam->omiBSIM4ucs < 0.0)
                  {   pParam->omiBSIM4ucs = 0.0;
                      printf("Warning: ucs has been negative; reset to 0.0.\n");
                  }

                 pParam->omiBSIM4vfbsdoff = pParam->omiBSIM4vfbsdoff * (1.0 + pParam->omiBSIM4tvfbsdoff * delTemp);
                 pParam->omiBSIM4voff = pParam->omiBSIM4voff * (1.0 + pParam->omiBSIM4tvoff * delTemp);

                 pParam->omiBSIM4nfactor = pParam->omiBSIM4nfactor + pParam->omiBSIM4tnfactor * delTemp / Tnom;  /* v4.7 temp dep of leakage currents */
                        pParam->omiBSIM4voffcv = pParam->omiBSIM4voffcv * (1.0 + pParam->omiBSIM4tvoffcv * delTemp);   /*         v4.7 temp dep of leakage currents */
                 pParam->omiBSIM4eta0 = pParam->omiBSIM4eta0 + pParam->omiBSIM4teta0 * delTemp / Tnom;   /*         v4.7 temp dep of leakage currents */

                /* Source End Velocity Limit  */
                        if((model->omiBSIM4vtlGiven) && (model->omiBSIM4vtl > 0.0) )
                      {
                     if(model->omiBSIM4lc < 0.0) pParam->omiBSIM4lc = 0.0;
                     else   pParam->omiBSIM4lc = model->omiBSIM4lc ;
                     T0 = pParam->omiBSIM4leff / (pParam->omiBSIM4xn * pParam->omiBSIM4leff + pParam->omiBSIM4lc);
                     pParam->omiBSIM4tfactor = (1.0 - T0) / (1.0 + T0 );
                       }

                  pParam->omiBSIM4cgdo = (model->omiBSIM4cgdo + pParam->omiBSIM4cf)
                                    * pParam->omiBSIM4weffCV;
                  pParam->omiBSIM4cgso = (model->omiBSIM4cgso + pParam->omiBSIM4cf)
                                    * pParam->omiBSIM4weffCV;
                  pParam->omiBSIM4cgbo = model->omiBSIM4cgbo * pParam->omiBSIM4leffCV * here->omiBSIM4nf;

                  if (!model->omiBSIM4ndepGiven && model->omiBSIM4gamma1Given)
                  {   T0 = pParam->omiBSIM4gamma1 * model->omiBSIM4coxe;
                      pParam->omiBSIM4ndep = 3.01248e22 * T0 * T0;
                  }

                  pParam->omiBSIM4phi = Vtm0 * log(pParam->omiBSIM4ndep / ni)
                                   + pParam->omiBSIM4phin + 0.4;

                  pParam->omiBSIM4sqrtPhi = sqrt(pParam->omiBSIM4phi);
                  pParam->omiBSIM4phis3 = pParam->omiBSIM4sqrtPhi * pParam->omiBSIM4phi;

                  pParam->omiBSIM4Xdep0 = sqrt(2.0 * epssub / (Charge_q
                                     * pParam->omiBSIM4ndep * 1.0e6))
                                     * pParam->omiBSIM4sqrtPhi;
                  pParam->omiBSIM4sqrtXdep0 = sqrt(pParam->omiBSIM4Xdep0);

                  if(model->omiBSIM4mtrlMod == 0)
                    pParam->omiBSIM4litl = sqrt(3.0 * 3.9 / epsrox * pParam->omiBSIM4xj * toxe);
                  else
                    pParam->omiBSIM4litl = sqrt(model->omiBSIM4epsrsub/epsrox * pParam->omiBSIM4xj * toxe);

                  pParam->omiBSIM4vbi = Vtm0 * log(pParam->omiBSIM4nsd
                                   * pParam->omiBSIM4ndep / (ni * ni));

                  if (model->omiBSIM4mtrlMod == 0)
                  {
                    if (pParam->omiBSIM4ngate > 0.0)
                    {   pParam->omiBSIM4vfbsd = Vtm0 * log(pParam->omiBSIM4ngate
                                         / pParam->omiBSIM4nsd);
                     }
                    else
                      pParam->omiBSIM4vfbsd = 0.0;
                  }
                  else
                  {
                    T0 = Vtm0 * log(pParam->omiBSIM4nsd/ni);
                    T1 = 0.5 * Eg0;
                    if(T0 > T1)
                      T0 = T1;
                    T2 = model->omiBSIM4easub + T1 - model->omiBSIM4type * T0;
                    pParam->omiBSIM4vfbsd = model->omiBSIM4phig - T2;
                  }

                  pParam->omiBSIM4cdep0 = sqrt(Charge_q * epssub
                                     * pParam->omiBSIM4ndep * 1.0e6 / 2.0
                                     / pParam->omiBSIM4phi);

                  pParam->omiBSIM4ToxRatio = exp(pParam->omiBSIM4ntox
                                        * log(model->omiBSIM4toxref / toxe))
                                        / toxe / toxe;
                  pParam->omiBSIM4ToxRatioEdge = exp(pParam->omiBSIM4ntox
                                            * log(model->omiBSIM4toxref
                                            / (toxe * pParam->omiBSIM4poxedge)))
                                            / toxe / toxe
                                            / pParam->omiBSIM4poxedge / pParam->omiBSIM4poxedge;
                  pParam->omiBSIM4Aechvb = (model->omiBSIM4type == NMOS) ? 4.97232e-7 : 3.42537e-7;
                  pParam->omiBSIM4Bechvb = (model->omiBSIM4type == NMOS) ? 7.45669e11 : 1.16645e12;
                  pParam->omiBSIM4AechvbEdgeS = pParam->omiBSIM4Aechvb * pParam->omiBSIM4weff
                                          * model->omiBSIM4dlcig * pParam->omiBSIM4ToxRatioEdge;
                  pParam->omiBSIM4AechvbEdgeD = pParam->omiBSIM4Aechvb * pParam->omiBSIM4weff
                                          * model->omiBSIM4dlcigd * pParam->omiBSIM4ToxRatioEdge;
                  pParam->omiBSIM4BechvbEdge = -pParam->omiBSIM4Bechvb
                                          * toxe * pParam->omiBSIM4poxedge;
                  pParam->omiBSIM4Aechvb *= pParam->omiBSIM4weff * pParam->omiBSIM4leff
                                       * pParam->omiBSIM4ToxRatio;
                  pParam->omiBSIM4Bechvb *= -toxe;


                  pParam->omiBSIM4mstar = 0.5 + atan(pParam->omiBSIM4minv) / PI;
                  pParam->omiBSIM4mstarcv = 0.5 + atan(pParam->omiBSIM4minvcv) / PI;
                  pParam->omiBSIM4voffcbn =  pParam->omiBSIM4voff + model->omiBSIM4voffl / pParam->omiBSIM4leff;
                  pParam->omiBSIM4voffcbncv =  pParam->omiBSIM4voffcv + model->omiBSIM4voffcvl / pParam->omiBSIM4leff;

                  pParam->omiBSIM4ldeb = sqrt(epssub * Vtm0 / (Charge_q
                                    * pParam->omiBSIM4ndep * 1.0e6)) / 3.0;
                  pParam->omiBSIM4acde *= pow((pParam->omiBSIM4ndep / 2.0e16), -0.25);


                  if (model->omiBSIM4k1Given || model->omiBSIM4k2Given)
                  {   if (!model->omiBSIM4k1Given)
                      {
                          if ((!ckt->CKTcurJob) || (ckt->CKTcurJob->JOBtype < 9)) /* don't print in sensitivity */
                              fprintf(stdout, "Warning: k1 should be specified with k2.\n");
                          pParam->omiBSIM4k1 = 0.53;
                      }
                      if (!model->omiBSIM4k2Given)
                      {
                          if ((!ckt->CKTcurJob) || (ckt->CKTcurJob->JOBtype < 9)) /* don't print in sensitivity */
                              fprintf(stdout, "Warning: k2 should be specified with k1.\n");
                          pParam->omiBSIM4k2 = -0.0186;
                      }
                      if ((!ckt->CKTcurJob) || (ckt->CKTcurJob->JOBtype < 9)) { /* don't print in sensitivity */
                          if (model->omiBSIM4nsubGiven)
                              fprintf(stdout, "Warning: nsub is ignored because k1 or k2 is given.\n");
                          if (model->omiBSIM4xtGiven)
                              fprintf(stdout, "Warning: xt is ignored because k1 or k2 is given.\n");
                          if (model->omiBSIM4vbxGiven)
                              fprintf(stdout, "Warning: vbx is ignored because k1 or k2 is given.\n");
                          if (model->omiBSIM4gamma1Given)
                              fprintf(stdout, "Warning: gamma1 is ignored because k1 or k2 is given.\n");
                          if (model->omiBSIM4gamma2Given)
                              fprintf(stdout, "Warning: gamma2 is ignored because k1 or k2 is given.\n");
                      }
                  }
                  else
                  {   if (!model->omiBSIM4vbxGiven)
                          pParam->omiBSIM4vbx = pParam->omiBSIM4phi - 7.7348e-4
                                           * pParam->omiBSIM4ndep
                                           * pParam->omiBSIM4xt * pParam->omiBSIM4xt;
                      if (pParam->omiBSIM4vbx > 0.0)
                          pParam->omiBSIM4vbx = -pParam->omiBSIM4vbx;
                      if (pParam->omiBSIM4vbm > 0.0)
                          pParam->omiBSIM4vbm = -pParam->omiBSIM4vbm;

                      if (!model->omiBSIM4gamma1Given)
                          pParam->omiBSIM4gamma1 = 5.753e-12
                                              * sqrt(pParam->omiBSIM4ndep)
                                              / model->omiBSIM4coxe;
                      if (!model->omiBSIM4gamma2Given)
                          pParam->omiBSIM4gamma2 = 5.753e-12
                                              * sqrt(pParam->omiBSIM4nsub)
                                              / model->omiBSIM4coxe;

                      T0 = pParam->omiBSIM4gamma1 - pParam->omiBSIM4gamma2;
                      T1 = sqrt(pParam->omiBSIM4phi - pParam->omiBSIM4vbx)
                         - pParam->omiBSIM4sqrtPhi;
                      T2 = sqrt(pParam->omiBSIM4phi * (pParam->omiBSIM4phi
                         - pParam->omiBSIM4vbm)) - pParam->omiBSIM4phi;
                      pParam->omiBSIM4k2 = T0 * T1 / (2.0 * T2 + pParam->omiBSIM4vbm);
                      pParam->omiBSIM4k1 = pParam->omiBSIM4gamma2 - 2.0
                                      * pParam->omiBSIM4k2 * sqrt(pParam->omiBSIM4phi
                                      - pParam->omiBSIM4vbm);
                  }

                  if (!model->omiBSIM4vfbGiven)
                  {
                    if (model->omiBSIM4vth0Given)
                      {   pParam->omiBSIM4vfb = model->omiBSIM4type * pParam->omiBSIM4vth0
                                           - pParam->omiBSIM4phi - pParam->omiBSIM4k1
                                           * pParam->omiBSIM4sqrtPhi;
                      }
                      else
                      {
                        if ((model->omiBSIM4mtrlMod) && (model->omiBSIM4phigGiven) &&
                            (model->omiBSIM4nsubGiven))
                          {
                            T0 = Vtm0 * log(pParam->omiBSIM4nsub/ni);
                            T1 = 0.5 * Eg0;
                            if(T0 > T1)
                              T0 = T1;
                            T2 = model->omiBSIM4easub + T1 + model->omiBSIM4type * T0;
                            pParam->omiBSIM4vfb = model->omiBSIM4phig - T2;
                          }
                        else
                          {
                            pParam->omiBSIM4vfb = -1.0;
                          }
                      }
                  }
                   if (!model->omiBSIM4vth0Given)
                  {   pParam->omiBSIM4vth0 = model->omiBSIM4type * (pParam->omiBSIM4vfb
                                        + pParam->omiBSIM4phi + pParam->omiBSIM4k1
                                        * pParam->omiBSIM4sqrtPhi);
                  }

                  pParam->omiBSIM4k1ox = pParam->omiBSIM4k1 * toxe
                                    / model->omiBSIM4toxm;

                  tmp = sqrt(epssub / (epsrox * EPS0) * toxe * pParam->omiBSIM4Xdep0);
                    T0 = pParam->omiBSIM4dsub * pParam->omiBSIM4leff / tmp;
                  if (T0 < EXP_THRESHOLD)
                    {   T1 = exp(T0);
                            T2 = T1 - 1.0;
                            T3 = T2 * T2;
                      T4 = T3 + 2.0 * T1 * MIN_EXP;
                      pParam->omiBSIM4theta0vb0 = T1 / T4;
                  }
                  else
                      pParam->omiBSIM4theta0vb0 = 1.0 / (MAX_EXP - 2.0);

                   T0 = pParam->omiBSIM4drout * pParam->omiBSIM4leff / tmp;
                  if (T0 < EXP_THRESHOLD)
                         {   T1 = exp(T0);
                            T2 = T1 - 1.0;
                      T3 = T2 * T2;
                      T4 = T3 + 2.0 * T1 * MIN_EXP;
                      T5 = T1 / T4;
                  }
                  else
                      T5 = 1.0 / (MAX_EXP - 2.0); /* 3.0 * MIN_EXP omitted */
                  pParam->omiBSIM4thetaRout = pParam->omiBSIM4pdibl1 * T5
                                         + pParam->omiBSIM4pdibl2;

                  tmp = sqrt(pParam->omiBSIM4Xdep0);
                  tmp1 = pParam->omiBSIM4vbi - pParam->omiBSIM4phi;
                  tmp2 = model->omiBSIM4factor1 * tmp;

                  T0 = pParam->omiBSIM4dvt1w * pParam->omiBSIM4weff
                     * pParam->omiBSIM4leff / tmp2;
                  if (T0 < EXP_THRESHOLD)
                  {   T1 = exp(T0);
                      T2 = T1 - 1.0;
                      T3 = T2 * T2;
                      T4 = T3 + 2.0 * T1 * MIN_EXP;
                      T8 = T1 / T4;
                  }
                  else
                      T8 = 1.0 / (MAX_EXP - 2.0);
                  T0 = pParam->omiBSIM4dvt0w * T8;
                  T8 = T0 * tmp1;

                  T0 = pParam->omiBSIM4dvt1 * pParam->omiBSIM4leff / tmp2;
                  if (T0 < EXP_THRESHOLD)
                  {   T1 = exp(T0);
                      T2 = T1 - 1.0;
                      T3 = T2 * T2;
                      T4 = T3 + 2.0 * T1 * MIN_EXP;
                      T9 = T1 / T4;
                  }
                  else
                      T9 = 1.0 / (MAX_EXP - 2.0);
                  T9 = pParam->omiBSIM4dvt0 * T9 * tmp1;

                  T4 = toxe * pParam->omiBSIM4phi
                     / (pParam->omiBSIM4weff + pParam->omiBSIM4w0);

                  T0 = sqrt(1.0 + pParam->omiBSIM4lpe0 / pParam->omiBSIM4leff);
                  if((model->omiBSIM4tempMod == 1) || (model->omiBSIM4tempMod == 0))
                          T3 = (pParam->omiBSIM4kt1 + pParam->omiBSIM4kt1l / pParam->omiBSIM4leff)
                                     * (TRatio - 1.0);
                  if((model->omiBSIM4tempMod == 2)||(model->omiBSIM4tempMod == 3))
                        T3 = - pParam->omiBSIM4kt1 * (TRatio - 1.0);

                  T5 = pParam->omiBSIM4k1ox * (T0 - 1.0) * pParam->omiBSIM4sqrtPhi
                     + T3;
                  pParam->omiBSIM4vfbzbfactor = - T8 - T9 + pParam->omiBSIM4k3 * T4 + T5
                                             - pParam->omiBSIM4phi - pParam->omiBSIM4k1 * pParam->omiBSIM4sqrtPhi;

                  /* stress effect */

                      wlod = model->omiBSIM4wlod;
                      if (model->omiBSIM4wlod < 0.0)
                  {   fprintf(stderr, "Warning: WLOD = %g is less than 0. 0.0 is used\n",model->omiBSIM4wlod);
                             wlod = 0.0;
                  }
                  T0 = pow(Lnew, model->omiBSIM4llodku0);
                  W_tmp = Wnew + wlod;
                  T1 = pow(W_tmp, model->omiBSIM4wlodku0);
                  tmp1 = model->omiBSIM4lku0 / T0 + model->omiBSIM4wku0 / T1
                         + model->omiBSIM4pku0 / (T0 * T1);
                  pParam->omiBSIM4ku0 = 1.0 + tmp1;

                  T0 = pow(Lnew, model->omiBSIM4llodvth);
                  T1 = pow(W_tmp, model->omiBSIM4wlodvth);
                  tmp1 = model->omiBSIM4lkvth0 / T0 + model->omiBSIM4wkvth0 / T1
                       + model->omiBSIM4pkvth0 / (T0 * T1);
                  pParam->omiBSIM4kvth0 = 1.0 + tmp1;
                  pParam->omiBSIM4kvth0 = sqrt(pParam->omiBSIM4kvth0*pParam->omiBSIM4kvth0 + DELTA);

                  T0 = (TRatio - 1.0);
                  pParam->omiBSIM4ku0temp = pParam->omiBSIM4ku0 * (1.0 + model->omiBSIM4tku0 *T0) + DELTA;

                  Inv_saref = 1.0/(model->omiBSIM4saref + 0.5*Ldrn);
                  Inv_sbref = 1.0/(model->omiBSIM4sbref + 0.5*Ldrn);
                  pParam->omiBSIM4inv_od_ref = Inv_saref + Inv_sbref;
                  pParam->omiBSIM4rho_ref = model->omiBSIM4ku0 / pParam->omiBSIM4ku0temp * pParam->omiBSIM4inv_od_ref;

              } /* End of SizeNotFound */

              /*  stress effect */
              if( (here->omiBSIM4sa > 0.0) && (here->omiBSIM4sb > 0.0) &&
                        ((here->omiBSIM4nf == 1.0) || ((here->omiBSIM4nf > 1.0) && (here->omiBSIM4sd > 0.0))) )
              {          Inv_sa = 0;
                        Inv_sb = 0;

                         kvsat = model->omiBSIM4kvsat;
                  if (model->omiBSIM4kvsat < -1.0 )
                  {   fprintf(stderr, "Warning: KVSAT = %g is too small; -1.0 is used.\n",model->omiBSIM4kvsat);
                             kvsat = -1.0;
                      }
                      if (model->omiBSIM4kvsat > 1.0)
                      {   fprintf(stderr, "Warning: KVSAT = %g is too big; 1.0 is used.\n",model->omiBSIM4kvsat);
                         kvsat = 1.0;
                      }

                        for(i = 0; i < here->omiBSIM4nf; i++){
                           T0 = 1.0 / here->omiBSIM4nf / (here->omiBSIM4sa + 0.5*Ldrn + i * (here->omiBSIM4sd +Ldrn));
                            T1 = 1.0 / here->omiBSIM4nf / (here->omiBSIM4sb + 0.5*Ldrn + i * (here->omiBSIM4sd +Ldrn));
                           Inv_sa += T0;
                            Inv_sb += T1;
                  }
                  Inv_ODeff = Inv_sa + Inv_sb;
                  rho = model->omiBSIM4ku0 / pParam->omiBSIM4ku0temp * Inv_ODeff;
                  T0 = (1.0 + rho)/(1.0 + pParam->omiBSIM4rho_ref);
                  here->omiBSIM4u0temp = pParam->omiBSIM4u0temp * T0;

                  T1 = (1.0 + kvsat * rho)/(1.0 + kvsat * pParam->omiBSIM4rho_ref);
                  here->omiBSIM4vsattemp = pParam->omiBSIM4vsattemp * T1;

                  OD_offset = Inv_ODeff - pParam->omiBSIM4inv_od_ref;
                  dvth0_lod = model->omiBSIM4kvth0 / pParam->omiBSIM4kvth0 * OD_offset;
                  dk2_lod = model->omiBSIM4stk2 / pow(pParam->omiBSIM4kvth0, model->omiBSIM4lodk2) *
                                   OD_offset;
                  deta0_lod = model->omiBSIM4steta0 / pow(pParam->omiBSIM4kvth0, model->omiBSIM4lodeta0) *
                                     OD_offset;
                  here->omiBSIM4vth0 = pParam->omiBSIM4vth0 + dvth0_lod;

                  here->omiBSIM4eta0 = pParam->omiBSIM4eta0 + deta0_lod;
                  here->omiBSIM4k2 = pParam->omiBSIM4k2 + dk2_lod;
               } else {
                      here->omiBSIM4u0temp = pParam->omiBSIM4u0temp;
                      here->omiBSIM4vth0 = pParam->omiBSIM4vth0;
                      here->omiBSIM4vsattemp = pParam->omiBSIM4vsattemp;
                      here->omiBSIM4eta0 = pParam->omiBSIM4eta0;
                      here->omiBSIM4k2 = pParam->omiBSIM4k2;
              }

              /*  Well Proximity Effect  */
              if (model->omiBSIM4wpemod)
              { if( (!here->omiBSIM4scaGiven) && (!here->omiBSIM4scbGiven) && (!here->omiBSIM4sccGiven) )
                {   if((here->omiBSIM4scGiven) && (here->omiBSIM4sc > 0.0) )
                          {   T1 = here->omiBSIM4sc + Wdrn;
                        T2 = 1.0 / model->omiBSIM4scref;
                        here->omiBSIM4sca = model->omiBSIM4scref * model->omiBSIM4scref
                                        / (here->omiBSIM4sc * T1);
                        here->omiBSIM4scb = ( (0.1 * here->omiBSIM4sc + 0.01 * model->omiBSIM4scref)
                                        * exp(-10.0 * here->omiBSIM4sc * T2)
                                        - (0.1 * T1 + 0.01 * model->omiBSIM4scref)
                                        * exp(-10.0 * T1 * T2) ) / Wdrn;
                        here->omiBSIM4scc = ( (0.05 * here->omiBSIM4sc + 0.0025 * model->omiBSIM4scref)
                                        * exp(-20.0 * here->omiBSIM4sc * T2)
                                        - (0.05 * T1 + 0.0025 * model->omiBSIM4scref)
                                        * exp(-20.0 * T1 * T2) ) / Wdrn;
                    } else {
                        fprintf(stderr, "Warning: No WPE as none of SCA, SCB, SCC, SC is given and/or SC not positive.\n");
                    }
                }

                       if (here->omiBSIM4sca < 0.0)
                {
                    printf("Warning: SCA = %g is negative. Set to 0.0.\n", here->omiBSIM4sca);
                    here->omiBSIM4sca = 0.0;
                }
                if (here->omiBSIM4scb < 0.0)
                {
                    printf("Warning: SCB = %g is negative. Set to 0.0.\n", here->omiBSIM4scb);
                    here->omiBSIM4scb = 0.0;
                }
                if (here->omiBSIM4scc < 0.0)
                {
                    printf("Warning: SCC = %g is negative. Set to 0.0.\n", here->omiBSIM4scc);
                    here->omiBSIM4scc = 0.0;
                }
                if (here->omiBSIM4sc < 0.0)
                {
                    printf("Warning: SC = %g is negative. Set to 0.0.\n", here->omiBSIM4sc);
                    here->omiBSIM4sc = 0.0;
                }
                                /*4.6.2*/
                sceff = here->omiBSIM4sca + model->omiBSIM4web * here->omiBSIM4scb
                      + model->omiBSIM4wec * here->omiBSIM4scc;
                here->omiBSIM4vth0 += pParam->omiBSIM4kvth0we * sceff;
                here->omiBSIM4k2 +=  pParam->omiBSIM4k2we * sceff;
                  T3 =  1.0 + pParam->omiBSIM4ku0we * sceff;
                if (T3 <= 0.0)
                {         T3 = 0.0;
                        fprintf(stderr, "Warning: ku0we = %g is negatively too high. Negative mobility! \n", pParam->omiBSIM4ku0we);
                }
                here->omiBSIM4u0temp *= T3;
              }

            /* adding delvto  */
            here->omiBSIM4vth0 += here->omiBSIM4delvto;
            here->omiBSIM4vfb = pParam->omiBSIM4vfb + model->omiBSIM4type * here->omiBSIM4delvto;

            /* low field mobility multiplier */
            here->omiBSIM4u0temp = pParam->omiBSIM4u0temp * here->omiBSIM4mulu0;

            /* Instance variables calculation  */
            T3 = model->omiBSIM4type * here->omiBSIM4vth0
               - here->omiBSIM4vfb - pParam->omiBSIM4phi;
            T4 = T3 + T3;
            T5 = 2.5 * T3;
            here->omiBSIM4vtfbphi1 = (model->omiBSIM4type == NMOS) ? T4 : T5;
            if (here->omiBSIM4vtfbphi1 < 0.0)
                here->omiBSIM4vtfbphi1 = 0.0;

            here->omiBSIM4vtfbphi2 = 4.0 * T3;
            if (here->omiBSIM4vtfbphi2 < 0.0)
                here->omiBSIM4vtfbphi2 = 0.0;

            if (here->omiBSIM4k2 < 0.0)
            {   T0 = 0.5 * pParam->omiBSIM4k1 / here->omiBSIM4k2;
                here->omiBSIM4vbsc = 0.9 * (pParam->omiBSIM4phi - T0 * T0);
                if (here->omiBSIM4vbsc > -3.0)
                    here->omiBSIM4vbsc = -3.0;
                else if (here->omiBSIM4vbsc < -30.0)
                    here->omiBSIM4vbsc = -30.0;
            }
            else
                here->omiBSIM4vbsc = -30.0;
            if (here->omiBSIM4vbsc > pParam->omiBSIM4vbm)
                here->omiBSIM4vbsc = pParam->omiBSIM4vbm;
            here->omiBSIM4k2ox = here->omiBSIM4k2 * toxe
                              / model->omiBSIM4toxm;

            here->omiBSIM4vfbzb = pParam->omiBSIM4vfbzbfactor
                                +  model->omiBSIM4type * here->omiBSIM4vth0 ;

              here->omiBSIM4cgso = pParam->omiBSIM4cgso;
              here->omiBSIM4cgdo = pParam->omiBSIM4cgdo;

              lnl = log(pParam->omiBSIM4leff * 1.0e6);
              lnw = log(pParam->omiBSIM4weff * 1.0e6);
              lnnf = log(here->omiBSIM4nf);

              bodymode = 5;
              if( ( !model->omiBSIM4rbps0Given) ||
                  ( !model->omiBSIM4rbpd0Given) )
                bodymode = 1;
              else
                if( (!model->omiBSIM4rbsbx0Given && !model->omiBSIM4rbsby0Given) ||
                      (!model->omiBSIM4rbdbx0Given && !model->omiBSIM4rbdby0Given) )
                  bodymode = 3;

              if(here->omiBSIM4rbodyMod == 2)
                {
                  if (bodymode == 5)
                    {
                      rbsbx =  exp( log(model->omiBSIM4rbsbx0) + model->omiBSIM4rbsdbxl * lnl +
                                    model->omiBSIM4rbsdbxw * lnw + model->omiBSIM4rbsdbxnf * lnnf );
                      rbsby =  exp( log(model->omiBSIM4rbsby0) + model->omiBSIM4rbsdbyl * lnl +
                                    model->omiBSIM4rbsdbyw * lnw + model->omiBSIM4rbsdbynf * lnnf );
                      here->omiBSIM4rbsb = rbsbx * rbsby / (rbsbx + rbsby);


                      rbdbx =  exp( log(model->omiBSIM4rbdbx0) + model->omiBSIM4rbsdbxl * lnl +
                                    model->omiBSIM4rbsdbxw * lnw + model->omiBSIM4rbsdbxnf * lnnf );
                      rbdby =  exp( log(model->omiBSIM4rbdby0) + model->omiBSIM4rbsdbyl * lnl +
                                    model->omiBSIM4rbsdbyw * lnw + model->omiBSIM4rbsdbynf * lnnf );
                      here->omiBSIM4rbdb = rbdbx * rbdby / (rbdbx + rbdby);
                    }

                  if ((bodymode == 3)|| (bodymode == 5))
                    {
                      here->omiBSIM4rbps = exp( log(model->omiBSIM4rbps0) + model->omiBSIM4rbpsl * lnl +
                                             model->omiBSIM4rbpsw * lnw + model->omiBSIM4rbpsnf * lnnf );
                      here->omiBSIM4rbpd = exp( log(model->omiBSIM4rbpd0) + model->omiBSIM4rbpdl * lnl +
                                             model->omiBSIM4rbpdw * lnw + model->omiBSIM4rbpdnf * lnnf );
                    }

                  rbpbx =  exp( log(model->omiBSIM4rbpbx0) + model->omiBSIM4rbpbxl * lnl +
                                model->omiBSIM4rbpbxw * lnw + model->omiBSIM4rbpbxnf * lnnf );
                  rbpby =  exp( log(model->omiBSIM4rbpby0) + model->omiBSIM4rbpbyl * lnl +
                                model->omiBSIM4rbpbyw * lnw + model->omiBSIM4rbpbynf * lnnf );
                  here->omiBSIM4rbpb = rbpbx*rbpby/(rbpbx + rbpby);
                }


              if ((here->omiBSIM4rbodyMod == 1 ) || ((here->omiBSIM4rbodyMod == 2 ) && (bodymode == 5)) )
              {   if (here->omiBSIM4rbdb < 1.0e-3)
                      here->omiBSIM4grbdb = 1.0e3; /* in mho */
                  else
                      here->omiBSIM4grbdb = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbdb;
                  if (here->omiBSIM4rbpb < 1.0e-3)
                      here->omiBSIM4grbpb = 1.0e3;
                  else
                      here->omiBSIM4grbpb = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbpb;
                  if (here->omiBSIM4rbps < 1.0e-3)
                      here->omiBSIM4grbps = 1.0e3;
                  else
                      here->omiBSIM4grbps = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbps;
                  if (here->omiBSIM4rbsb < 1.0e-3)
                      here->omiBSIM4grbsb = 1.0e3;
                  else
                      here->omiBSIM4grbsb = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbsb;
                  if (here->omiBSIM4rbpd < 1.0e-3)
                      here->omiBSIM4grbpd = 1.0e3;
                  else
                      here->omiBSIM4grbpd = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbpd;

              }

              if((here->omiBSIM4rbodyMod == 2) && (bodymode == 3))
              {
                      here->omiBSIM4grbdb = here->omiBSIM4grbsb = model->omiBSIM4gbmin;
                  if (here->omiBSIM4rbpb < 1.0e-3)
                      here->omiBSIM4grbpb = 1.0e3;
                  else
                      here->omiBSIM4grbpb = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbpb;
                  if (here->omiBSIM4rbps < 1.0e-3)
                      here->omiBSIM4grbps = 1.0e3;
                  else
                      here->omiBSIM4grbps = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbps;
                  if (here->omiBSIM4rbpd < 1.0e-3)
                      here->omiBSIM4grbpd = 1.0e3;
                  else
                      here->omiBSIM4grbpd = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbpd;
              }

              if((here->omiBSIM4rbodyMod == 2) && (bodymode == 1))
              {
                      here->omiBSIM4grbdb = here->omiBSIM4grbsb = model->omiBSIM4gbmin;
                      here->omiBSIM4grbps = here->omiBSIM4grbpd = 1.0e3;
                  if (here->omiBSIM4rbpb < 1.0e-3)
                      here->omiBSIM4grbpb = 1.0e3;
                  else
                      here->omiBSIM4grbpb = model->omiBSIM4gbmin + 1.0 / here->omiBSIM4rbpb;
              }


              /*
               * Process geomertry dependent parasitics
               */

              here->omiBSIM4grgeltd = model->omiBSIM4rshg * (here->omiBSIM4xgw
                      + pParam->omiBSIM4weffCJ / 3.0 / here->omiBSIM4ngcon) /
                      (here->omiBSIM4ngcon * here->omiBSIM4nf *
                      (Lnew - model->omiBSIM4xgl));
              if (here->omiBSIM4grgeltd > 0.0)
                  here->omiBSIM4grgeltd = 1.0 / here->omiBSIM4grgeltd;
              else
              {   here->omiBSIM4grgeltd = 1.0e3; /* mho */
                  if (here->omiBSIM4rgateMod != 0)
                  printf("Warning: The gate conductance reset to 1.0e3 mho.\n");
              }

              DMCGeff = model->omiBSIM4dmcg - model->omiBSIM4dmcgt;
              DMCIeff = model->omiBSIM4dmci;
              DMDGeff = model->omiBSIM4dmdg - model->omiBSIM4dmcgt;

/*              if (here->omiBSIM4sourcePerimeterGiven)
              {   if (model->omiBSIM4perMod == 0)
                      here->omiBSIM4Pseff = here->omiBSIM4sourcePerimeter;
                  else
                      here->omiBSIM4Pseff = here->omiBSIM4sourcePerimeter
                                       - pParam->omiBSIM4weffCJ * here->omiBSIM4nf;
              }
              else
                  omiBSIM4PAeffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod, here->omiBSIM4min,
                                    pParam->omiBSIM4weffCJ, DMCGeff, DMCIeff, DMDGeff,
                                    &(here->omiBSIM4Pseff), &dumPd, &dumAs, &dumAd);
              if (here->omiBSIM4Pseff < 0.0) /4.6.2/
                      here->omiBSIM4Pseff = 0.0; */

        /* New Diode Model v4.7*/
              if (here->omiBSIM4sourcePerimeterGiven)
              {   /* given */
                  if (here->omiBSIM4sourcePerimeter == 0.0)
                          here->omiBSIM4Pseff = 0.0;
                  else if (here->omiBSIM4sourcePerimeter < 0.0)
                  {
                          printf("Warning: Source Perimeter is specified as negative, it is set to zero.\n");
                          here->omiBSIM4Pseff = 0.0;
                  } else
                  {
                          if (model->omiBSIM4perMod == 0)
                                  here->omiBSIM4Pseff = here->omiBSIM4sourcePerimeter;
                          else
                                  here->omiBSIM4Pseff = here->omiBSIM4sourcePerimeter
                                          - pParam->omiBSIM4weffCJ * here->omiBSIM4nf;
                  }
              } else /* not given */
                  omiBSIM4PAeffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod, here->omiBSIM4min,
                                    pParam->omiBSIM4weffCJ, DMCGeff, DMCIeff, DMDGeff,
                                    &(here->omiBSIM4Pseff), &dumPd, &dumAs, &dumAd);

              if (here->omiBSIM4Pseff < 0.0){ /* v4.7 final check */
                              here->omiBSIM4Pseff = 0.0;
                              printf("Warning: Pseff is negative, it is set to zero.\n");
              }
              /*  if (here->omiBSIM4drainPerimeterGiven)
              {   if (model->omiBSIM4perMod == 0)
                      here->omiBSIM4Pdeff = here->omiBSIM4drainPerimeter;
                  else
                      here->omiBSIM4Pdeff = here->omiBSIM4drainPerimeter
                                       - pParam->omiBSIM4weffCJ * here->omiBSIM4nf;
              }
              else
                  omiBSIM4PAeffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod, here->omiBSIM4min,
                                    pParam->omiBSIM4weffCJ, DMCGeff, DMCIeff, DMDGeff,
                                    &dumPs, &(here->omiBSIM4Pdeff), &dumAs, &dumAd);
               if (here->omiBSIM4Pdeff < 0.0) /4.6.2/
                      here->omiBSIM4Pdeff = 0.0; */

              if (here->omiBSIM4drainPerimeterGiven)
              {   /* given */
                  if (here->omiBSIM4drainPerimeter == 0.0)
                                here->omiBSIM4Pdeff = 0.0;
                  else if (here->omiBSIM4drainPerimeter < 0.0)
                  {
                                printf("Warning: Drain Perimeter is specified as negative, it is set to zero.\n");
                                here->omiBSIM4Pdeff = 0.0;
                  } else
                  {
                                if (model->omiBSIM4perMod == 0)
                                        here->omiBSIM4Pdeff = here->omiBSIM4drainPerimeter;
                                else
                                        here->omiBSIM4Pdeff = here->omiBSIM4drainPerimeter
                                                - pParam->omiBSIM4weffCJ * here->omiBSIM4nf;
                  }
              } else /* not given */
                  omiBSIM4PAeffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod, here->omiBSIM4min,
                    pParam->omiBSIM4weffCJ, DMCGeff, DMCIeff, DMDGeff,
                                    &dumPs, &(here->omiBSIM4Pdeff), &dumAs, &dumAd);

              if (here->omiBSIM4Pdeff < 0.0){
                      here->omiBSIM4Pdeff = 0.0; /*New Diode v4.7*/
                      printf("Warning: Pdeff is negative, it is set to zero.\n");
              }
              if (here->omiBSIM4sourceAreaGiven)
                  here->omiBSIM4Aseff = here->omiBSIM4sourceArea;
              else
                  omiBSIM4PAeffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod, here->omiBSIM4min,
                                    pParam->omiBSIM4weffCJ, DMCGeff, DMCIeff, DMDGeff,
                                    &dumPs, &dumPd, &(here->omiBSIM4Aseff), &dumAd);
              if (here->omiBSIM4Aseff < 0.0){
                  here->omiBSIM4Aseff = 0.0; /* v4.7 */
                  printf("Warning: Aseff is negative, it is set to zero.\n");
              }
              if (here->omiBSIM4drainAreaGiven)
                  here->omiBSIM4Adeff = here->omiBSIM4drainArea;
              else
                  omiBSIM4PAeffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod, here->omiBSIM4min,
                                    pParam->omiBSIM4weffCJ, DMCGeff, DMCIeff, DMDGeff,
                                    &dumPs, &dumPd, &dumAs, &(here->omiBSIM4Adeff));
              if (here->omiBSIM4Adeff < 0.0){
                  here->omiBSIM4Adeff = 0.0; /* v4.7 */
                  printf("Warning: Adeff is negative, it is set to zero.\n");
              }
              /* Processing S/D resistance and conductance below */
              if(here->omiBSIM4sNodePrime != here->omiBSIM4sNode)
              {
                 here->omiBSIM4sourceConductance = 0.0;
                 if(here->omiBSIM4sourceSquaresGiven)
                 {
                    here->omiBSIM4sourceConductance = model->omiBSIM4sheetResistance
                                               * here->omiBSIM4sourceSquares;
                 } else if (here->omiBSIM4rgeoMod > 0)
                 {
                    omiBSIM4RdseffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod,
                      here->omiBSIM4rgeoMod, here->omiBSIM4min,
                      pParam->omiBSIM4weffCJ, model->omiBSIM4sheetResistance,
                  DMCGeff, DMCIeff, DMDGeff, 1, &(here->omiBSIM4sourceConductance));
                 } else
                 {
                    here->omiBSIM4sourceConductance = 0.0;
                 }

                 if (here->omiBSIM4sourceConductance > 0.0)
                     here->omiBSIM4sourceConductance = 1.0
                                            / here->omiBSIM4sourceConductance;
                 else
                 {
                     here->omiBSIM4sourceConductance = 1.0e3; /* mho */
                     printf ("Warning: Source conductance reset to 1.0e3 mho.\n");
                 }
              } else
              {
                  here->omiBSIM4sourceConductance = 0.0;
              }

              if(here->omiBSIM4dNodePrime != here->omiBSIM4dNode)
              {
                 here->omiBSIM4drainConductance = 0.0;
                 if(here->omiBSIM4drainSquaresGiven)
                 {
                    here->omiBSIM4drainConductance = model->omiBSIM4sheetResistance
                                              * here->omiBSIM4drainSquares;
                 } else if (here->omiBSIM4rgeoMod > 0)
                 {
                    omiBSIM4RdseffGeo(here->omiBSIM4nf, here->omiBSIM4geoMod,
                      here->omiBSIM4rgeoMod, here->omiBSIM4min,
                      pParam->omiBSIM4weffCJ, model->omiBSIM4sheetResistance,
                  DMCGeff, DMCIeff, DMDGeff, 0, &(here->omiBSIM4drainConductance));
                 } else
                 {
                    here->omiBSIM4drainConductance = 0.0;
                 }

                 if (here->omiBSIM4drainConductance > 0.0)
                     here->omiBSIM4drainConductance = 1.0
                                           / here->omiBSIM4drainConductance;
                 else
                 {
                     here->omiBSIM4drainConductance = 1.0e3; /* mho */
                     printf ("Warning: Drain conductance reset to 1.0e3 mho.\n");
                  }
              } else
              {
                  here->omiBSIM4drainConductance = 0.0;
              }

               /* End of Rsd processing */


              Nvtms = model->omiBSIM4vtm * model->omiBSIM4SjctEmissionCoeff;
              if ((here->omiBSIM4Aseff <= 0.0) && (here->omiBSIM4Pseff <= 0.0))
              {   SourceSatCurrent = 0.0; /* v4.7 */
                  /* SourceSatCurrent = 1.0e-14; */
              }
              else
              {   SourceSatCurrent = here->omiBSIM4Aseff * model->omiBSIM4SjctTempSatCurDensity
                                   + here->omiBSIM4Pseff * model->omiBSIM4SjctSidewallTempSatCurDensity
                                   + pParam->omiBSIM4weffCJ * here->omiBSIM4nf
                                   * model->omiBSIM4SjctGateSidewallTempSatCurDensity;
              }
              if (SourceSatCurrent > 0.0)
              {   switch(model->omiBSIM4dioMod)
                  {   case 0:
                          if ((model->omiBSIM4bvs / Nvtms) > EXP_THRESHOLD)
                              here->omiBSIM4XExpBVS = model->omiBSIM4xjbvs * MIN_EXP;
                          else
                              here->omiBSIM4XExpBVS = model->omiBSIM4xjbvs * exp(-model->omiBSIM4bvs / Nvtms);
                          break;
                      case 1:
                          omiBSIM4DioIjthVjmEval(Nvtms, model->omiBSIM4ijthsfwd, SourceSatCurrent,
                                              0.0, &(here->omiBSIM4vjsmFwd));
                          here->omiBSIM4IVjsmFwd = SourceSatCurrent * exp(here->omiBSIM4vjsmFwd / Nvtms);
                          break;
                      case 2:
                          if ((model->omiBSIM4bvs / Nvtms) > EXP_THRESHOLD)
                          {   here->omiBSIM4XExpBVS = model->omiBSIM4xjbvs * MIN_EXP;
                              tmp = MIN_EXP;
                          }
                          else
                          {   here->omiBSIM4XExpBVS = exp(-model->omiBSIM4bvs / Nvtms);
                              tmp = here->omiBSIM4XExpBVS;
                              here->omiBSIM4XExpBVS *= model->omiBSIM4xjbvs;
                          }

                          omiBSIM4DioIjthVjmEval(Nvtms, model->omiBSIM4ijthsfwd, SourceSatCurrent,
                                                     here->omiBSIM4XExpBVS, &(here->omiBSIM4vjsmFwd));
                          T0 = exp(here->omiBSIM4vjsmFwd / Nvtms);
                          here->omiBSIM4IVjsmFwd = SourceSatCurrent * (T0 - here->omiBSIM4XExpBVS / T0
                                                + here->omiBSIM4XExpBVS - 1.0);
                          here->omiBSIM4SslpFwd = SourceSatCurrent
                                               * (T0 + here->omiBSIM4XExpBVS / T0) / Nvtms;

                          T2 = model->omiBSIM4ijthsrev / SourceSatCurrent;
                          if (T2 < 1.0)
                          {   T2 = 10.0;
                              fprintf(stderr, "Warning: ijthsrev too small and set to 10 times IsbSat.\n");
                          }
                          here->omiBSIM4vjsmRev = -model->omiBSIM4bvs
                                             - Nvtms * log((T2 - 1.0) / model->omiBSIM4xjbvs);
                          T1 = model->omiBSIM4xjbvs * exp(-(model->omiBSIM4bvs
                             + here->omiBSIM4vjsmRev) / Nvtms);
                          here->omiBSIM4IVjsmRev = SourceSatCurrent * (1.0 + T1);
                          here->omiBSIM4SslpRev = -SourceSatCurrent * T1 / Nvtms;
                          break;
                  default:
                          printf("Specified dioMod = %d not matched\n", model->omiBSIM4dioMod);
                  }
              }

              Nvtmd = model->omiBSIM4vtm * model->omiBSIM4DjctEmissionCoeff;
              if ((here->omiBSIM4Adeff <= 0.0) && (here->omiBSIM4Pdeff <= 0.0))
              {  /* DrainSatCurrent = 1.0e-14;         v4.7 */
                   DrainSatCurrent = 0.0;
              }
              else
              {   DrainSatCurrent = here->omiBSIM4Adeff * model->omiBSIM4DjctTempSatCurDensity
                                  + here->omiBSIM4Pdeff * model->omiBSIM4DjctSidewallTempSatCurDensity
                                  + pParam->omiBSIM4weffCJ * here->omiBSIM4nf
                                  * model->omiBSIM4DjctGateSidewallTempSatCurDensity;
              }
              if (DrainSatCurrent > 0.0)
              {   switch(model->omiBSIM4dioMod)
                  {   case 0:
                          if ((model->omiBSIM4bvd / Nvtmd) > EXP_THRESHOLD)
                          here->omiBSIM4XExpBVD = model->omiBSIM4xjbvd * MIN_EXP;
                          else
                          here->omiBSIM4XExpBVD = model->omiBSIM4xjbvd * exp(-model->omiBSIM4bvd / Nvtmd);
                          break;
                      case 1:
                          omiBSIM4DioIjthVjmEval(Nvtmd, model->omiBSIM4ijthdfwd, DrainSatCurrent,
                                              0.0, &(here->omiBSIM4vjdmFwd));
                          here->omiBSIM4IVjdmFwd = DrainSatCurrent * exp(here->omiBSIM4vjdmFwd / Nvtmd);
                          break;
                      case 2:
                          if ((model->omiBSIM4bvd / Nvtmd) > EXP_THRESHOLD)
                          {   here->omiBSIM4XExpBVD = model->omiBSIM4xjbvd * MIN_EXP;
                              tmp = MIN_EXP;
                          }
                          else
                          {   here->omiBSIM4XExpBVD = exp(-model->omiBSIM4bvd / Nvtmd);
                              tmp = here->omiBSIM4XExpBVD;
                              here->omiBSIM4XExpBVD *= model->omiBSIM4xjbvd;
                          }

                          omiBSIM4DioIjthVjmEval(Nvtmd, model->omiBSIM4ijthdfwd, DrainSatCurrent,
                                              here->omiBSIM4XExpBVD, &(here->omiBSIM4vjdmFwd));
                          T0 = exp(here->omiBSIM4vjdmFwd / Nvtmd);
                          here->omiBSIM4IVjdmFwd = DrainSatCurrent * (T0 - here->omiBSIM4XExpBVD / T0
                                              + here->omiBSIM4XExpBVD - 1.0);
                          here->omiBSIM4DslpFwd = DrainSatCurrent
                                               * (T0 + here->omiBSIM4XExpBVD / T0) / Nvtmd;

                          T2 = model->omiBSIM4ijthdrev / DrainSatCurrent;
                          if (T2 < 1.0)
                          {   T2 = 10.0;
                              fprintf(stderr, "Warning: ijthdrev too small and set to 10 times IdbSat.\n");
                          }
                          here->omiBSIM4vjdmRev = -model->omiBSIM4bvd
                                             - Nvtmd * log((T2 - 1.0) / model->omiBSIM4xjbvd); /* bugfix */
                          T1 = model->omiBSIM4xjbvd * exp(-(model->omiBSIM4bvd
                             + here->omiBSIM4vjdmRev) / Nvtmd);
                          here->omiBSIM4IVjdmRev = DrainSatCurrent * (1.0 + T1);
                          here->omiBSIM4DslpRev = -DrainSatCurrent * T1 / Nvtmd;
                          break;
                  default:
                          printf("Specified dioMod = %d not matched\n", model->omiBSIM4dioMod);
                  }
              }

                /* GEDL current reverse bias */
                T0 = (TRatio - 1.0);
                model->omiBSIM4njtsstemp = model->omiBSIM4njts * (1.0 + model->omiBSIM4tnjts * T0);
                model->omiBSIM4njtsswstemp = model->omiBSIM4njtssw * (1.0 + model->omiBSIM4tnjtssw * T0);
                model->omiBSIM4njtsswgstemp = model->omiBSIM4njtsswg * (1.0 + model->omiBSIM4tnjtsswg * T0);
                model->omiBSIM4njtsdtemp = model->omiBSIM4njtsd * (1.0 + model->omiBSIM4tnjtsd * T0);
                model->omiBSIM4njtsswdtemp = model->omiBSIM4njtsswd * (1.0 + model->omiBSIM4tnjtsswd * T0);
                model->omiBSIM4njtsswgdtemp = model->omiBSIM4njtsswgd * (1.0 + model->omiBSIM4tnjtsswgd * T0);
                T7 = Eg0 / model->omiBSIM4vtm * T0;
                T9 = model->omiBSIM4xtss * T7;
                DEXP(T9, T1);
                T9 = model->omiBSIM4xtsd * T7;
                DEXP(T9, T2);
                T9 = model->omiBSIM4xtssws * T7;
                DEXP(T9, T3);
                T9 = model->omiBSIM4xtsswd * T7;
                DEXP(T9, T4);
                T9 = model->omiBSIM4xtsswgs * T7;
                DEXP(T9, T5);
                T9 = model->omiBSIM4xtsswgd * T7;
                DEXP(T9, T6);
                                /*IBM TAT*/
                                if(model->omiBSIM4jtweff < 0.0)
                              {   model->omiBSIM4jtweff = 0.0;
                          fprintf(stderr, "TAT width dependence effect is negative. Jtweff is clamped to zero.\n");
                      }
                                T11 = sqrt(model->omiBSIM4jtweff / pParam->omiBSIM4weffCJ) + 1.0;

                T10 = pParam->omiBSIM4weffCJ * here->omiBSIM4nf;
                here->omiBSIM4SjctTempRevSatCur = T1 * here->omiBSIM4Aseff * model->omiBSIM4jtss;
                here->omiBSIM4DjctTempRevSatCur = T2 * here->omiBSIM4Adeff * model->omiBSIM4jtsd;
                here->omiBSIM4SswTempRevSatCur = T3 * here->omiBSIM4Pseff * model->omiBSIM4jtssws;
                here->omiBSIM4DswTempRevSatCur = T4 * here->omiBSIM4Pdeff * model->omiBSIM4jtsswd;
                here->omiBSIM4SswgTempRevSatCur = T5 * T10 * T11 * model->omiBSIM4jtsswgs;
                here->omiBSIM4DswgTempRevSatCur = T6 * T10 * T11 * model->omiBSIM4jtsswgd;

                /*high k*/
                /*Calculate VgsteffVth for mobMod=3*/
                if(model->omiBSIM4mobMod==3)
                {        /*Calculate n @ Vbs=Vds=0*/
                    V0 = pParam->omiBSIM4vbi - pParam->omiBSIM4phi;
                    lt1 = model->omiBSIM4factor1* pParam->omiBSIM4sqrtXdep0;
                    ltw = lt1;
                    T0 = pParam->omiBSIM4dvt1 * pParam->omiBSIM4leff / lt1;
                    if (T0 < EXP_THRESHOLD)
                      {
                        T1 = exp(T0);
                        T2 = T1 - 1.0;
                        T3 = T2 * T2;
                        T4 = T3 + 2.0 * T1 * MIN_EXP;
                        Theta0 = T1 / T4;
                      }
                    else
                      Theta0 = 1.0 / (MAX_EXP - 2.0);

                     tmp1 = epssub / pParam->omiBSIM4Xdep0;
                    here->omiBSIM4nstar = model->omiBSIM4vtm / Charge_q *
                      (model->omiBSIM4coxe        + tmp1 + pParam->omiBSIM4cit);
                    tmp2 = pParam->omiBSIM4nfactor * tmp1;
                    tmp3 = (tmp2 + pParam->omiBSIM4cdsc * Theta0 + pParam->omiBSIM4cit) / model->omiBSIM4coxe;
                    if (tmp3 >= -0.5)
                      n0 = 1.0 + tmp3;
                    else
                      {
                        T0 = 1.0 / (3.0 + 8.0 * tmp3);
                        n0 = (1.0 + 3.0 * tmp3) * T0;
                      }

                  T0 = n0 * model->omiBSIM4vtm;
                  T1 = pParam->omiBSIM4voffcbn;
                  T2 = T1/T0;
                  if (T2 < -EXP_THRESHOLD)
                  {   T3 = model->omiBSIM4coxe * MIN_EXP / pParam->omiBSIM4cdep0;
                      T4 = pParam->omiBSIM4mstar + T3 * n0;
                  }
                  else if (T2 > EXP_THRESHOLD)
                  {   T3 = model->omiBSIM4coxe * MAX_EXP / pParam->omiBSIM4cdep0;
                      T4 = pParam->omiBSIM4mstar + T3 * n0;
                  }
                  else
                  {  T3 = exp(T2)* model->omiBSIM4coxe / pParam->omiBSIM4cdep0;
                               T4 = pParam->omiBSIM4mstar + T3 * n0;
                  }
                  pParam->omiBSIM4VgsteffVth = T0 * log(2.0)/T4;

                }

                /* New DITS term added in 4.7 */
                T0 = -pParam->omiBSIM4dvtp3 * log(pParam->omiBSIM4leff);
                DEXP(T0, T1);
                pParam->omiBSIM4dvtp2factor = pParam->omiBSIM4dvtp5 + pParam->omiBSIM4dvtp2 * T1;

                if(model->omiBSIM4mtrlMod != 0 && model->omiBSIM4mtrlCompatMod == 0)
                {
                    /* Calculate TOXP from EOT */
                    /* Calculate Vgs_eff @ Vgs = VDD with Poly Depletion Effect */
                    Vtm0eot = KboQ * model->omiBSIM4tempeot;
                    Vtmeot  = Vtm0eot;
                    vbieot = Vtm0eot * log(pParam->omiBSIM4nsd
                                   * pParam->omiBSIM4ndep / (ni * ni));
                    phieot = Vtm0eot * log(pParam->omiBSIM4ndep / ni)
                                   + pParam->omiBSIM4phin + 0.4;
                    tmp2 = here->omiBSIM4vfb + phieot;
                    vddeot = model->omiBSIM4type * model->omiBSIM4vddeot;
                    T0 = model->omiBSIM4epsrgate * EPS0;
                    if ((pParam->omiBSIM4ngate > 1.0e18) && (pParam->omiBSIM4ngate < 1.0e25)
                        && (vddeot > tmp2) && (T0!=0))
                      {
                        T1 = 1.0e6 * CHARGE * T0 * pParam->omiBSIM4ngate /
                          (model->omiBSIM4coxe * model->omiBSIM4coxe);
                        T8 = vddeot - tmp2;
                        T4 = sqrt(1.0 + 2.0 * T8 / T1);
                        T2 = 2.0 * T8 / (T4 + 1.0);
                        T3 = 0.5 * T2 * T2 / T1;
                        T7 = 1.12 - T3 - 0.05;
                        T6 = sqrt(T7 * T7 + 0.224);
                        T5 = 1.12 - 0.5 * (T7 + T6);
                        Vgs_eff = vddeot - T5;
                      }
                    else
                      Vgs_eff = vddeot;

                    /* Calculate Vth @ Vds=Vbs=0 */

                    V0 = vbieot - phieot;
                    lt1 = model->omiBSIM4factor1* pParam->omiBSIM4sqrtXdep0;
                    ltw = lt1;
                    T0 = pParam->omiBSIM4dvt1 * model->omiBSIM4leffeot / lt1;
                    if (T0 < EXP_THRESHOLD)
                      {
                        T1 = exp(T0);
                        T2 = T1 - 1.0;
                        T3 = T2 * T2;
                        T4 = T3 + 2.0 * T1 * MIN_EXP;
                        Theta0 = T1 / T4;
                      }
                    else
                      Theta0 = 1.0 / (MAX_EXP - 2.0);
                    Delt_vth = pParam->omiBSIM4dvt0 * Theta0 * V0;
                    T0 = pParam->omiBSIM4dvt1w * model->omiBSIM4weffeot * model->omiBSIM4leffeot / ltw;
                    if (T0 < EXP_THRESHOLD)
                      {   T1 = exp(T0);
                      T2 = T1 - 1.0;
                      T3 = T2 * T2;
                      T4 = T3 + 2.0 * T1 * MIN_EXP;
                      T5 = T1 / T4;
                      }
                    else
                      T5 = 1.0 / (MAX_EXP - 2.0); /* 3.0 * MIN_EXP omitted */
                    T2 = pParam->omiBSIM4dvt0w * T5 * V0;
                    TempRatioeot =  model->omiBSIM4tempeot / model->omiBSIM4tnom - 1.0;
                    T0 = sqrt(1.0 + pParam->omiBSIM4lpe0 / model->omiBSIM4leffeot);
                    T1 = pParam->omiBSIM4k1ox * (T0 - 1.0) * sqrt(phieot)
                      + (pParam->omiBSIM4kt1 + pParam->omiBSIM4kt1l / model->omiBSIM4leffeot) * TempRatioeot;
                    Vth_NarrowW = toxe * phieot
                      / (model->omiBSIM4weffeot + pParam->omiBSIM4w0);
                    Lpe_Vb = sqrt(1.0 + pParam->omiBSIM4lpeb / model->omiBSIM4leffeot);
                    Vth = model->omiBSIM4type * here->omiBSIM4vth0 +
                      (pParam->omiBSIM4k1ox - pParam->omiBSIM4k1)*sqrt(phieot)*Lpe_Vb
                      - Delt_vth - T2 + pParam->omiBSIM4k3 * Vth_NarrowW + T1;

                    /* Calculate n */
                    tmp1 = epssub / pParam->omiBSIM4Xdep0;
                    here->omiBSIM4nstar = Vtmeot / Charge_q *
                      (model->omiBSIM4coxe        + tmp1 + pParam->omiBSIM4cit);
                    tmp2 = pParam->omiBSIM4nfactor * tmp1;
                    tmp3 = (tmp2 + pParam->omiBSIM4cdsc * Theta0 + pParam->omiBSIM4cit) / model->omiBSIM4coxe;
                    if (tmp3 >= -0.5)
                      n = 1.0 + tmp3;
                    else
                      {
                        T0 = 1.0 / (3.0 + 8.0 * tmp3);
                        n = (1.0 + 3.0 * tmp3) * T0;
                      }

                    /* Vth correction for Pocket implant */
                    if (pParam->omiBSIM4dvtp0 > 0.0)
                      {
                        T3 = model->omiBSIM4leffeot + pParam->omiBSIM4dvtp0 * 2.0;
                        if (model->omiBSIM4tempMod < 2)
                          T4 = Vtmeot * log(model->omiBSIM4leffeot / T3);
                        else
                          T4 = Vtm0eot * log(model->omiBSIM4leffeot / T3);
                        Vth -= n * T4;
                      }
                    Vgsteff = Vgs_eff-Vth;
                    /* calculating Toxp */
                        T3 = model->omiBSIM4type * here->omiBSIM4vth0
               - here->omiBSIM4vfb - phieot;
            T4 = T3 + T3;
            T5 = 2.5 * T3;

            vtfbphi2eot = 4.0 * T3;
            if (vtfbphi2eot < 0.0)
                vtfbphi2eot = 0.0;


                    niter = 0;
                    toxpf = toxe;
                    do
                      {
                        toxpi = toxpf;
                        tmp2 = 2.0e8 * toxpf;
                        T0 = (Vgsteff + vtfbphi2eot) / tmp2;
                        T1 = 1.0 + exp(model->omiBSIM4bdos * 0.7 * log(T0));
                        Tcen = model->omiBSIM4ados * 1.9e-9 / T1;
                        toxpf = toxe - epsrox/model->omiBSIM4epsrsub * Tcen;
                        niter++;
                      } while ((niter<=4)&&(ABS(toxpf-toxpi)>1e-12));
                      model->omiBSIM4toxp = toxpf;
                      model->omiBSIM4coxp = epsrox * EPS0 / model->omiBSIM4toxp;
                      }

              if (omiBSIM4checkModel(model, here, ckt))
              {
                  SPfrontEnd->IFerrorf(ERR_FATAL,
                      "detected during BSIM4.7.0 parameter checking for \n    model %s of device instance %s\n", model->omiBSIM4modName, here->omiBSIM4name);
                  return(E_BADPARM);
              }
         } /* End instance */
    }
    return(OK);
}
