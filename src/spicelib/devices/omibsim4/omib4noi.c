/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4noi.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
  * Authors: 2008- Wenwei Yang,  Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 04/06/2001.
 * Modified by Xuemei Xi, 10/05/2001.
 * Modified by Xuemei Xi, 05/09/2003.
 * Modified by Xuemei Xi, 03/04/2004.
 * Modified by Xuemei Xi, 07/29/2005.
 * Modified by Mohan Dunga, 12/13/2006
 * Modified by Wenwei Yang, 07/31/2008.
 * Modified by Tanvir Morshed, Darsen Lu 03/27/2011
 **********/

#include "ngspice/ngspice.h"
#include "omibsim4def.h"
#include "ngspice/cktdefs.h"
#include "ngspice/iferrmsg.h"
#include "ngspice/noisedef.h"
#include "ngspice/suffix.h"
#include "ngspice/const.h"


/*
 * WDL: 1/f noise model has been smoothed out and enhanced with
 * bulk charge effect as well as physical N* equ. and necessary
 * conversion into the SI unit system.
 */

static double
Eval1ovFNoise(
double Vds,
omiBSIM4model *model,
omiBSIM4instance *here,
double freq, double temp)
{
struct bsim4SizeDependParam *pParam;
double cd, esat, DelClm, EffFreq, N0, Nl, Leff, Leffsq;
double T0=0.0, T1, T2, T3, T4, T5, T6, T7, T8, T9, Ssi;

    pParam = here->pParam;
    cd = fabs(here->omiBSIM4cd);
    Leff = pParam->omiBSIM4leff - 2.0 * model->omiBSIM4lintnoi;
    Leffsq = Leff * Leff;
    esat = 2.0 * here->omiBSIM4vsattemp / here->omiBSIM4ueff;
    if(model->omiBSIM4em<=0.0) DelClm = 0.0; /* flicker noise modified -JX  */
    else {
            T0 = ((((Vds - here->omiBSIM4Vdseff) / pParam->omiBSIM4litl)
                       + model->omiBSIM4em) / esat);
            DelClm = pParam->omiBSIM4litl * log (MAX(T0, N_MINLOG));
            if (DelClm < 0.0)        DelClm = 0.0;  /* bugfix */
    }
    EffFreq = pow(freq, model->omiBSIM4ef);
    T1 = CHARGE * CHARGE * CONSTboltz * cd * temp * here->omiBSIM4ueff;
    T2 = 1.0e10 * EffFreq * here->omiBSIM4Abulk * model->omiBSIM4coxe * Leffsq;
    N0 = model->omiBSIM4coxe * here->omiBSIM4Vgsteff / CHARGE;
    Nl = model->omiBSIM4coxe * here->omiBSIM4Vgsteff
       * (1.0 - here->omiBSIM4AbovVgst2Vtm * here->omiBSIM4Vdseff) / CHARGE;

    T3 = model->omiBSIM4oxideTrapDensityA
       * log(MAX(((N0 + here->omiBSIM4nstar) / (Nl + here->omiBSIM4nstar)), N_MINLOG));
    T4 = model->omiBSIM4oxideTrapDensityB * (N0 - Nl);
    T5 = model->omiBSIM4oxideTrapDensityC * 0.5 * (N0 * N0 - Nl * Nl);

    T6 = CONSTboltz * temp * cd * cd;
    T7 = 1.0e10 * EffFreq * Leffsq * pParam->omiBSIM4weff * here->omiBSIM4nf;
    T8 = model->omiBSIM4oxideTrapDensityA + model->omiBSIM4oxideTrapDensityB * Nl
       + model->omiBSIM4oxideTrapDensityC * Nl * Nl;
    T9 = (Nl + here->omiBSIM4nstar) * (Nl + here->omiBSIM4nstar);
    Ssi = T1 / T2 * (T3 + T4 + T5) + T6 / T7 * DelClm * T8 / T9;
    return Ssi;
}


int
omiBSIM4noise (
int mode, int operation,
GENmodel *inModel,
CKTcircuit *ckt,
Ndata *data,
double *OnDens)
{
NOISEAN *job = (NOISEAN *) ckt->CKTcurJob;

omiBSIM4model *model = (omiBSIM4model *)inModel;
omiBSIM4instance *here;
struct bsim4SizeDependParam *pParam;
double tempOnoise;
double tempInoise;
double noizDens[omiBSIM4NSRCS];
double lnNdens[omiBSIM4NSRCS];

double T0, T1, T2, T3, T4, T5, T6, T7, T8, T10, T11;
double Vds, Ssi, Swi;
double tmp=0.0, gdpr, gspr, npart_theta=0.0, npart_beta=0.0, igsquare, bodymode;

/* tnoiMod=2 (v4.7) */
double eta, Leff, Lvsat, gamma, delta, epsilon, GammaGd0=0.0;
double npart_c, sigrat=0.0, C0, omega, ctnoi=0.0;

int i;

double m;

    /* define the names of the noise sources */
    static char *omiBSIM4nNames[omiBSIM4NSRCS] =
    {   /* Note that we have to keep the order */
        ".rd",              /* noise due to rd */
        ".rs",              /* noise due to rs */
        ".rg",              /* noise due to rgeltd */
        ".rbps",            /* noise due to rbps */
        ".rbpd",            /* noise due to rbpd */
        ".rbpb",            /* noise due to rbpb */
        ".rbsb",            /* noise due to rbsb */
        ".rbdb",            /* noise due to rbdb */
        ".id",              /* noise due to id (for tnoiMod2: uncorrelated portion only) */
        ".1overf",          /* flicker (1/f) noise */
        ".igs",             /* shot noise due to IGS */
        ".igd",             /* shot noise due to IGD */
        ".igb",             /* shot noise due to IGB */
        ".corl",            /* contribution of correlated drain and induced gate noise */
        ""                  /* total transistor noise */
    };

    for (; model != NULL; model = omiBSIM4nextModel(model))
    {
         if(model->omiBSIM4tnoiMod != 2) {
             noizDens[omiBSIM4CORLNOIZ] = 0.0;
             lnNdens[omiBSIM4CORLNOIZ] = N_MINLOG;
         }
         for (here = omiBSIM4instances(model); here != NULL;
              here = omiBSIM4nextInstance(here))
         {    pParam = here->pParam;
              switch (operation)
              {  case N_OPEN:
                     /* see if we have to to produce a summary report */
                     /* if so, name all the noise generators */

                      if (job->NStpsSm != 0)
                      {   switch (mode)
                          {  case N_DENS:
                                  for (i = 0; i < omiBSIM4NSRCS; i++)
                                  {    NOISE_ADD_OUTVAR(ckt, data, "onoise.%s%s", here->omiBSIM4name, omiBSIM4nNames[i]);
                                  }
                                  break;
                             case INT_NOIZ:
                                  for (i = 0; i < omiBSIM4NSRCS; i++)
                                  {    NOISE_ADD_OUTVAR(ckt, data, "onoise_total.%s%s", here->omiBSIM4name, omiBSIM4nNames[i]);
                                       NOISE_ADD_OUTVAR(ckt, data, "inoise_total.%s%s", here->omiBSIM4name, omiBSIM4nNames[i]);
                                  }
                                  break;
                          }
                      }
                      break;
                 case N_CALC:
                      m = here->omiBSIM4m;
                      switch (mode)
                      {  case N_DENS:
                              if (model->omiBSIM4tnoiMod == 0)
                              {   if (model->omiBSIM4rdsMod == 0)
                                  {   gspr = here->omiBSIM4sourceConductance;
                                      gdpr = here->omiBSIM4drainConductance;
                                      if (here->omiBSIM4grdsw > 0.0)
                                          tmp = 1.0 / here->omiBSIM4grdsw; /* tmp used below */
                                      else
                                          tmp = 0.0;
                                  }
                                  else
                                  {   gspr = here->omiBSIM4gstot;
                                      gdpr = here->omiBSIM4gdtot;
                                      tmp = 0.0;
                                  }
                              }
                              else if(model->omiBSIM4tnoiMod == 1)
                              {   T5 = here->omiBSIM4Vgsteff / here->omiBSIM4EsatL;
                                  T5 *= T5;
                                  npart_beta = model->omiBSIM4rnoia * (1.0 + T5
                                             * model->omiBSIM4tnoia * pParam->omiBSIM4leff);
                                  npart_theta = model->omiBSIM4rnoib * (1.0 + T5
                                              * model->omiBSIM4tnoib * pParam->omiBSIM4leff);
                                  if(npart_theta > 0.9)
                                     npart_theta = 0.9;
                                  if(npart_theta > 0.9 * npart_beta)
                                     npart_theta = 0.9 * npart_beta; //4.6.2

                                  if (model->omiBSIM4rdsMod == 0)
                                  {   gspr = here->omiBSIM4sourceConductance;
                                      gdpr = here->omiBSIM4drainConductance;
                                  }
                                  else
                                  {   gspr = here->omiBSIM4gstot;
                                      gdpr = here->omiBSIM4gdtot;
                                  }

                                  if ((*(ckt->CKTstates[0] + here->omiBSIM4vds)) >= 0.0)
                                      gspr = gspr * (1.0 + npart_theta * npart_theta * gspr
                                           / here->omiBSIM4IdovVds);
                                  else
                                      gdpr = gdpr * (1.0 + npart_theta * npart_theta * gdpr
                                           / here->omiBSIM4IdovVds);
                              }
                              else
                              {   /* tnoiMod=2 (v4.7) */

                                  if (model->omiBSIM4rdsMod == 0)
                                  {   gspr = here->omiBSIM4sourceConductance;
                                      gdpr = here->omiBSIM4drainConductance;
                                  }
                                  else
                                  {   gspr = here->omiBSIM4gstot;
                                      gdpr = here->omiBSIM4gdtot;
                                  }

                              }

                              NevalSrc(&noizDens[omiBSIM4RDNOIZ],
                                       &lnNdens[omiBSIM4RDNOIZ], ckt, THERMNOISE,
                                       here->omiBSIM4dNodePrime, here->omiBSIM4dNode,
                                       gdpr * m);

                              NevalSrc(&noizDens[omiBSIM4RSNOIZ],
                                       &lnNdens[omiBSIM4RSNOIZ], ckt, THERMNOISE,
                                       here->omiBSIM4sNodePrime, here->omiBSIM4sNode,
                                       gspr * m);


                              if (here->omiBSIM4rgateMod == 1)
                              {   NevalSrc(&noizDens[omiBSIM4RGNOIZ],
                                       &lnNdens[omiBSIM4RGNOIZ], ckt, THERMNOISE,
                                       here->omiBSIM4gNodePrime, here->omiBSIM4gNodeExt,
                                       here->omiBSIM4grgeltd * m);
                              }
                              else if (here->omiBSIM4rgateMod == 2)
                              {
                                T0 = 1.0 + here->omiBSIM4grgeltd/here->omiBSIM4gcrg;
                                T1 = T0 * T0;
                                  NevalSrc(&noizDens[omiBSIM4RGNOIZ],
                                       &lnNdens[omiBSIM4RGNOIZ], ckt, THERMNOISE,
                                       here->omiBSIM4gNodePrime, here->omiBSIM4gNodeExt,
                                       here->omiBSIM4grgeltd * m / T1);
                              }
                              else if (here->omiBSIM4rgateMod == 3)
                              {   NevalSrc(&noizDens[omiBSIM4RGNOIZ],
                                       &lnNdens[omiBSIM4RGNOIZ], ckt, THERMNOISE,
                                       here->omiBSIM4gNodeMid, here->omiBSIM4gNodeExt,
                                       here->omiBSIM4grgeltd * m);
                              }
                              else
                              {    noizDens[omiBSIM4RGNOIZ] = 0.0;
                                   lnNdens[omiBSIM4RGNOIZ] =
                                          log(MAX(noizDens[omiBSIM4RGNOIZ], N_MINLOG));
                              }

                                    bodymode = 5;
                                    if (here->omiBSIM4rbodyMod == 2)
                                    {        if( ( !model->omiBSIM4rbps0Given) ||
                                      ( !model->omiBSIM4rbpd0Given) )
                                             bodymode = 1;
                                           else
                                     if( (!model->omiBSIM4rbsbx0Given && !model->omiBSIM4rbsby0Given) ||
                                          (!model->omiBSIM4rbdbx0Given && !model->omiBSIM4rbdby0Given) )
                                             bodymode = 3;
                                }

                              if (here->omiBSIM4rbodyMod)
                              {
                                if(bodymode == 5)
                                  {
                                    NevalSrc(&noizDens[omiBSIM4RBPSNOIZ],
                                             &lnNdens[omiBSIM4RBPSNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNodePrime, here->omiBSIM4sbNode,
                                             here->omiBSIM4grbps * m);
                                    NevalSrc(&noizDens[omiBSIM4RBPDNOIZ],
                                             &lnNdens[omiBSIM4RBPDNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNodePrime, here->omiBSIM4dbNode,
                                             here->omiBSIM4grbpd * m);
                                    NevalSrc(&noizDens[omiBSIM4RBPBNOIZ],
                                             &lnNdens[omiBSIM4RBPBNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNodePrime, here->omiBSIM4bNode,
                                             here->omiBSIM4grbpb * m);
                                    NevalSrc(&noizDens[omiBSIM4RBSBNOIZ],
                                             &lnNdens[omiBSIM4RBSBNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNode, here->omiBSIM4sbNode,
                                             here->omiBSIM4grbsb * m);
                                    NevalSrc(&noizDens[omiBSIM4RBDBNOIZ],
                                             &lnNdens[omiBSIM4RBDBNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNode, here->omiBSIM4dbNode,
                                             here->omiBSIM4grbdb * m);
                                  }
                                if(bodymode == 3)
                                  {
                                    NevalSrc(&noizDens[omiBSIM4RBPSNOIZ],
                                             &lnNdens[omiBSIM4RBPSNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNodePrime, here->omiBSIM4sbNode,
                                             here->omiBSIM4grbps * m);
                                    NevalSrc(&noizDens[omiBSIM4RBPDNOIZ],
                                             &lnNdens[omiBSIM4RBPDNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNodePrime, here->omiBSIM4dbNode,
                                             here->omiBSIM4grbpd * m);
                                    NevalSrc(&noizDens[omiBSIM4RBPBNOIZ],
                                             &lnNdens[omiBSIM4RBPBNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNodePrime, here->omiBSIM4bNode,
                                             here->omiBSIM4grbpb * m);
                                     noizDens[omiBSIM4RBSBNOIZ] = noizDens[omiBSIM4RBDBNOIZ] = 0.0;
                                     lnNdens[omiBSIM4RBSBNOIZ] =
                                       log(MAX(noizDens[omiBSIM4RBSBNOIZ], N_MINLOG));
                                     lnNdens[omiBSIM4RBDBNOIZ] =
                                       log(MAX(noizDens[omiBSIM4RBDBNOIZ], N_MINLOG));
                                  }
                                if(bodymode == 1)
                                  {
                                    NevalSrc(&noizDens[omiBSIM4RBPBNOIZ],
                                             &lnNdens[omiBSIM4RBPBNOIZ], ckt, THERMNOISE,
                                             here->omiBSIM4bNodePrime, here->omiBSIM4bNode,
                                             here->omiBSIM4grbpb * m);
                                    noizDens[omiBSIM4RBPSNOIZ] = noizDens[omiBSIM4RBPDNOIZ] = 0.0;
                                    noizDens[omiBSIM4RBSBNOIZ] = noizDens[omiBSIM4RBDBNOIZ] = 0.0;
                                    lnNdens[omiBSIM4RBPSNOIZ] =
                                      log(MAX(noizDens[omiBSIM4RBPSNOIZ], N_MINLOG));
                                    lnNdens[omiBSIM4RBPDNOIZ] =
                                      log(MAX(noizDens[omiBSIM4RBPDNOIZ], N_MINLOG));
                                    lnNdens[omiBSIM4RBSBNOIZ] =
                                      log(MAX(noizDens[omiBSIM4RBSBNOIZ], N_MINLOG));
                                    lnNdens[omiBSIM4RBDBNOIZ] =
                                      log(MAX(noizDens[omiBSIM4RBDBNOIZ], N_MINLOG));
                                  }
                              }
                              else
                              {   noizDens[omiBSIM4RBPSNOIZ] = noizDens[omiBSIM4RBPDNOIZ] = 0.0;
                                  noizDens[omiBSIM4RBPBNOIZ] = 0.0;
                                  noizDens[omiBSIM4RBSBNOIZ] = noizDens[omiBSIM4RBDBNOIZ] = 0.0;
                                  lnNdens[omiBSIM4RBPSNOIZ] =
                                          log(MAX(noizDens[omiBSIM4RBPSNOIZ], N_MINLOG));
                                  lnNdens[omiBSIM4RBPDNOIZ] =
                                          log(MAX(noizDens[omiBSIM4RBPDNOIZ], N_MINLOG));
                                  lnNdens[omiBSIM4RBPBNOIZ] =
                                          log(MAX(noizDens[omiBSIM4RBPBNOIZ], N_MINLOG));
                                  lnNdens[omiBSIM4RBSBNOIZ] =
                                          log(MAX(noizDens[omiBSIM4RBSBNOIZ], N_MINLOG));
                                  lnNdens[omiBSIM4RBDBNOIZ] =
                                          log(MAX(noizDens[omiBSIM4RBDBNOIZ], N_MINLOG));
                              }

                              if(model->omiBSIM4tnoiMod == 2)
                              {
                                  eta = 1.0 - here->omiBSIM4Vdseff * here->omiBSIM4AbovVgst2Vtm;
                                  T0 = 1.0 - eta;
                                  T1 = 1.0 + eta;
                                  T2 = T1 + 2.0 * here->omiBSIM4Abulk * model->omiBSIM4vtm / here->omiBSIM4Vgsteff;
                                  Leff = pParam->omiBSIM4leff;
                                  Lvsat = Leff * (1.0 + here->omiBSIM4Vdseff / here->omiBSIM4EsatL);
                                  T6 = Leff / Lvsat;

                                  T5 = here->omiBSIM4Vgsteff / here->omiBSIM4EsatL;
                                  T5 = T5 * T5;
                                  gamma = T6 * (0.5 * T1 + T0 * T0 / (6.0 * T2));
                                  T3 = T2 * T2;
                                  T4 = T0 * T0;
                                  T5 = T3 * T3;
                                  delta = (T1 / T3 - (5.0 * T1 + T2) * T4 / (15.0 * T5) + T4 * T4 / (9.0 * T5 * T2)) / (6.0 * T6 * T6 * T6);
                                  T7 = T0 / T2;
                                  epsilon = (T7 - T7 * T7 * T7 / 3.0) / (6.0 * T6);

                                  T8 = here->omiBSIM4Vgsteff / here->omiBSIM4EsatL;
                                  T8 *= T8;
                                  npart_c = model->omiBSIM4rnoic * (1.0 + T8
                                          * model->omiBSIM4tnoic * Leff);
                                  ctnoi = epsilon / sqrt(gamma * delta)
                                      * (2.5316 * npart_c);

                                  npart_beta = model->omiBSIM4rnoia * (1.0 + T8
                                      * model->omiBSIM4tnoia * Leff);
                                  npart_theta = model->omiBSIM4rnoib * (1.0 + T8
                                      * model->omiBSIM4tnoib * Leff);
                                  gamma = gamma * (3.0 * npart_beta * npart_beta);
                                  delta = delta * (3.75 * npart_theta * npart_theta);

                                  GammaGd0 = gamma * here->omiBSIM4noiGd0;
                                  C0 = here->omiBSIM4Coxeff * pParam->omiBSIM4weffCV * here->omiBSIM4nf * pParam->omiBSIM4leffCV;
                                  T0 = C0 / here->omiBSIM4noiGd0;
                                  sigrat = T0 * sqrt(delta / gamma);
                              }
                              switch(model->omiBSIM4tnoiMod)
                              {  case 0:
                                      T0 = here->omiBSIM4ueff * fabs(here->omiBSIM4qinv);
                                      T1 = T0 * tmp + pParam->omiBSIM4leff
                                         * pParam->omiBSIM4leff;
                                      NevalSrc(&noizDens[omiBSIM4IDNOIZ],
                                               &lnNdens[omiBSIM4IDNOIZ], ckt,
                                               THERMNOISE, here->omiBSIM4dNodePrime,
                                               here->omiBSIM4sNodePrime,
                                               (T0 / T1) * model->omiBSIM4ntnoi * m);
                                      break;
                                 case 1:
                                      T0 = here->omiBSIM4gm + here->omiBSIM4gmbs + here->omiBSIM4gds;
                                      T0 *= T0;
                                      igsquare = npart_theta * npart_theta * T0 / here->omiBSIM4IdovVds;
                                      T1 = npart_beta * (here->omiBSIM4gm
                                         + here->omiBSIM4gmbs) + here->omiBSIM4gds;
                                      T2 = T1 * T1 / here->omiBSIM4IdovVds;
                                      NevalSrc(&noizDens[omiBSIM4IDNOIZ],
                                               &lnNdens[omiBSIM4IDNOIZ], ckt,
                                               THERMNOISE, here->omiBSIM4dNodePrime,
                                               here->omiBSIM4sNodePrime, (T2 - igsquare) * m);
                                      break;
                                  case 2:
                                      T2 = GammaGd0;
                                      T3 = ctnoi * ctnoi;
                                      T4 = 1.0 - T3;
                                      NevalSrc(&noizDens[omiBSIM4IDNOIZ],
                                               &lnNdens[omiBSIM4IDNOIZ], ckt,
                                               THERMNOISE, here->omiBSIM4dNodePrime,
                                               here->omiBSIM4sNodePrime, T2 * T4 * m);

                                     /* Evaluate output noise due to two correlated noise sources */
                                     omega = 2.0 * M_PI * data->freq;
                                     T5 = omega * sigrat;
                                     T6 = T5 * T5;
                                     T7 = T6 / (1.0 + T6);

                                     if (here->omiBSIM4mode >= 0)  {
                                         NevalSrc2(&noizDens[omiBSIM4CORLNOIZ],
                                               &lnNdens[omiBSIM4CORLNOIZ], ckt,
                                               THERMNOISE, here->omiBSIM4dNodePrime,
                                               here->omiBSIM4sNodePrime, T2 * T3 * m,
                                               here->omiBSIM4gNodePrime,
                                               here->omiBSIM4sNodePrime,
                                               T2 * T7 * m, 0.5 * M_PI);
                                     }
                                     else
                                     {
                                         NevalSrc2(&noizDens[omiBSIM4CORLNOIZ],
                                               &lnNdens[omiBSIM4CORLNOIZ], ckt,
                                               THERMNOISE, here->omiBSIM4sNodePrime,
                                               here->omiBSIM4dNodePrime, T2 * T3 * m,
                                               here->omiBSIM4gNodePrime,
                                               here->omiBSIM4dNodePrime,
                                               T2 * T7 * m, 0.5 * M_PI);
                                     }
                                     break;
                              }

                              NevalSrc(&noizDens[omiBSIM4FLNOIZ], (double*) NULL,
                                       ckt, N_GAIN, here->omiBSIM4dNodePrime,
                                       here->omiBSIM4sNodePrime, (double) 0.0);

                              switch(model->omiBSIM4fnoiMod)
                              {  case 0:
                                      noizDens[omiBSIM4FLNOIZ] *= m * model->omiBSIM4kf
                                            * exp(model->omiBSIM4af
                                            * log(MAX(fabs(here->omiBSIM4cd),
                                            N_MINLOG)))
                                            / (pow(data->freq, model->omiBSIM4ef)
                                            * pParam->omiBSIM4leff
                                            * pParam->omiBSIM4leff
                                            * model->omiBSIM4coxe);
                                      break;
                                 case 1:
                                      Vds = *(ckt->CKTstates[0] + here->omiBSIM4vds);
                                      if (Vds < 0.0)
                                          Vds = -Vds;

                                      Ssi = Eval1ovFNoise(Vds, model, here,
                                          data->freq, ckt->CKTtemp);
                                      T10 = model->omiBSIM4oxideTrapDensityA
                                          * CONSTboltz * ckt->CKTtemp;
                                      T11 = pParam->omiBSIM4weff * here->omiBSIM4nf * pParam->omiBSIM4leff
                                          * pow(data->freq, model->omiBSIM4ef) * 1.0e10
                                          * here->omiBSIM4nstar * here->omiBSIM4nstar;
                                      Swi = T10 / T11 * here->omiBSIM4cd
                                          * here->omiBSIM4cd;
                                      T1 = Swi + Ssi;
                                      if (T1 > 0.0)
                                          noizDens[omiBSIM4FLNOIZ] *= m * (Ssi * Swi) / T1;
                                      else
                                          noizDens[omiBSIM4FLNOIZ] *= 0.0;
                                      break;
                              }

                              lnNdens[omiBSIM4FLNOIZ] =
                                     log(MAX(noizDens[omiBSIM4FLNOIZ], N_MINLOG));


                        if(here->omiBSIM4mode >= 0) {  /* bugfix  */
                              NevalSrc(&noizDens[omiBSIM4IGSNOIZ],
                                   &lnNdens[omiBSIM4IGSNOIZ], ckt, SHOTNOISE,
                                   here->omiBSIM4gNodePrime, here->omiBSIM4sNodePrime,
                                   m * (here->omiBSIM4Igs + here->omiBSIM4Igcs));
                              NevalSrc(&noizDens[omiBSIM4IGDNOIZ],
                                   &lnNdens[omiBSIM4IGDNOIZ], ckt, SHOTNOISE,
                                   here->omiBSIM4gNodePrime, here->omiBSIM4dNodePrime,
                                   m * (here->omiBSIM4Igd + here->omiBSIM4Igcd));
                        } else {
                              NevalSrc(&noizDens[omiBSIM4IGSNOIZ],
                                   &lnNdens[omiBSIM4IGSNOIZ], ckt, SHOTNOISE,
                                   here->omiBSIM4gNodePrime, here->omiBSIM4sNodePrime,
                                   m * (here->omiBSIM4Igs + here->omiBSIM4Igcd));
                              NevalSrc(&noizDens[omiBSIM4IGDNOIZ],
                                   &lnNdens[omiBSIM4IGDNOIZ], ckt, SHOTNOISE,
                                   here->omiBSIM4gNodePrime, here->omiBSIM4dNodePrime,
                                   m * (here->omiBSIM4Igd + here->omiBSIM4Igcs));
                        }
                              NevalSrc(&noizDens[omiBSIM4IGBNOIZ],
                                   &lnNdens[omiBSIM4IGBNOIZ], ckt, SHOTNOISE,
                                   here->omiBSIM4gNodePrime, here->omiBSIM4bNodePrime,
                                   m * here->omiBSIM4Igb);


                              noizDens[omiBSIM4TOTNOIZ] = noizDens[omiBSIM4RDNOIZ]
                                     + noizDens[omiBSIM4RSNOIZ] + noizDens[omiBSIM4RGNOIZ]
                                     + noizDens[omiBSIM4RBPSNOIZ] + noizDens[omiBSIM4RBPDNOIZ]
                                     + noizDens[omiBSIM4RBPBNOIZ]
                                     + noizDens[omiBSIM4RBSBNOIZ] + noizDens[omiBSIM4RBDBNOIZ]
                                     + noizDens[omiBSIM4IDNOIZ] + noizDens[omiBSIM4FLNOIZ]
                                     + noizDens[omiBSIM4IGSNOIZ] + noizDens[omiBSIM4IGDNOIZ]
                                     + noizDens[omiBSIM4IGBNOIZ] + noizDens[omiBSIM4CORLNOIZ];
                              lnNdens[omiBSIM4TOTNOIZ] =
                                     log(MAX(noizDens[omiBSIM4TOTNOIZ], N_MINLOG));

                              *OnDens += noizDens[omiBSIM4TOTNOIZ];

                              if (data->delFreq == 0.0)
                              {   /* if we haven't done any previous
                                     integration, we need to initialize our
                                     "history" variables.
                                    */

                                  for (i = 0; i < omiBSIM4NSRCS; i++)
                                  {    here->omiBSIM4nVar[LNLSTDENS][i] =
                                             lnNdens[i];
                                  }

                                  /* clear out our integration variables
                                     if it's the first pass
                                   */
                                  if (data->freq ==
                                      job->NstartFreq)
                                  {   for (i = 0; i < omiBSIM4NSRCS; i++)
                                      {    here->omiBSIM4nVar[OUTNOIZ][i] = 0.0;
                                           here->omiBSIM4nVar[INNOIZ][i] = 0.0;
                                      }
                                  }
                              }
                              else
                              {   /* data->delFreq != 0.0,
                                     we have to integrate.
                                   */
                                  for (i = 0; i < omiBSIM4NSRCS; i++)
                                  {    if (i != omiBSIM4TOTNOIZ)
                                       {   tempOnoise = Nintegrate(noizDens[i],
                                                lnNdens[i],
                                                here->omiBSIM4nVar[LNLSTDENS][i],
                                                data);
                                           tempInoise = Nintegrate(noizDens[i]
                                                * data->GainSqInv, lnNdens[i]
                                                + data->lnGainInv,
                                                here->omiBSIM4nVar[LNLSTDENS][i]
                                                + data->lnGainInv, data);
                                           here->omiBSIM4nVar[LNLSTDENS][i] =
                                                lnNdens[i];
                                           data->outNoiz += tempOnoise;
                                           data->inNoise += tempInoise;
                                           if (job->NStpsSm != 0)
                                           {   here->omiBSIM4nVar[OUTNOIZ][i]
                                                     += tempOnoise;
                                               here->omiBSIM4nVar[OUTNOIZ][omiBSIM4TOTNOIZ]
                                                     += tempOnoise;
                                               here->omiBSIM4nVar[INNOIZ][i]
                                                     += tempInoise;
                                               here->omiBSIM4nVar[INNOIZ][omiBSIM4TOTNOIZ]
                                                     += tempInoise;
                                           }
                                       }
                                  }
                              }
                              if (data->prtSummary)
                              {   for (i = 0; i < omiBSIM4NSRCS; i++)
                                  {    /* print a summary report */
                                       data->outpVector[data->outNumber++]
                                             = noizDens[i];
                                  }
                              }
                              break;
                         case INT_NOIZ:
                              /* already calculated, just output */
                              if (job->NStpsSm != 0)
                              {   for (i = 0; i < omiBSIM4NSRCS; i++)
                                  {    data->outpVector[data->outNumber++]
                                             = here->omiBSIM4nVar[OUTNOIZ][i];
                                       data->outpVector[data->outNumber++]
                                             = here->omiBSIM4nVar[INNOIZ][i];
                                  }
                              }
                              break;
                      }
                      break;
                 case N_CLOSE:
                      /* do nothing, the main calling routine will close */
                      return (OK);
                      break;   /* the plots */
              }       /* switch (operation) */
         }    /* for here */
    }    /* for model */

    return(OK);
}
