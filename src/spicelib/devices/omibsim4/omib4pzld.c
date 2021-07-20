/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4pzld.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 10/05/2001.
 **********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "ngspice/complex.h"
#include "ngspice/sperror.h"
#include "omibsim4def.h"
#include "ngspice/suffix.h"

int
omiBSIM4pzLoad(
GENmodel *inModel,
CKTcircuit *ckt,
SPcomplex *s)
{
omiBSIM4model *model = (omiBSIM4model*)inModel;
omiBSIM4instance *here;

double gjbd, gjbs, geltd, gcrg, gcrgg, gcrgd, gcrgs, gcrgb;
double xcggb, xcgdb, xcgsb, xcgbb, xcbgb, xcbdb, xcbsb, xcbbb;
double xcdgb, xcddb, xcdsb, xcdbb, xcsgb, xcsdb, xcssb, xcsbb;
double gds, capbd, capbs, FwdSum, RevSum, Gm, Gmbs;
double gstot, gstotd, gstotg, gstots, gstotb, gspr;
double gdtot, gdtotd, gdtotg, gdtots, gdtotb, gdpr;
double gIstotg, gIstotd, gIstots, gIstotb;
double gIdtotg, gIdtotd, gIdtots, gIdtotb;
double gIbtotg, gIbtotd, gIbtots, gIbtotb;
double gIgtotg, gIgtotd, gIgtots, gIgtotb;
double cgso, cgdo, cgbo;
double xcdbdb=0.0, xcsbsb=0.0, xcgmgmb=0.0, xcgmdb=0.0, xcgmsb=0.0, xcdgmb=0.0, xcsgmb=0.0;
double xcgmbb=0.0, xcbgmb=0.0;
double dxpart, sxpart, xgtg, xgtd, xgts, xgtb, xcqgb=0.0, xcqdb=0.0, xcqsb=0.0, xcqbb=0.0;
double gbspsp, gbbdp, gbbsp, gbspg, gbspb;
double gbspdp, gbdpdp, gbdpg, gbdpb, gbdpsp;
double ddxpart_dVd, ddxpart_dVg, ddxpart_dVb, ddxpart_dVs;
double dsxpart_dVd, dsxpart_dVg, dsxpart_dVb, dsxpart_dVs;
double T0=0.0, T1, CoxWL, qcheq, Cdg, Cdd, Cds, Csg, Csd, Css;
double ScalingFactor = 1.0e-9;
struct bsim4SizeDependParam *pParam;
double ggidld, ggidlg, ggidlb, ggislg, ggislb, ggisls;

double m;

    for (; model != NULL; model = omiBSIM4nextModel(model))
    {    for (here = omiBSIM4instances(model); here!= NULL;
              here = omiBSIM4nextInstance(here))
         {
              pParam = here->pParam;
              capbd = here->omiBSIM4capbd;
              capbs = here->omiBSIM4capbs;
              cgso = here->omiBSIM4cgso;
              cgdo = here->omiBSIM4cgdo;
              cgbo = pParam->omiBSIM4cgbo;

              if (here->omiBSIM4mode >= 0)
              {   Gm = here->omiBSIM4gm;
                  Gmbs = here->omiBSIM4gmbs;
                  FwdSum = Gm + Gmbs;
                  RevSum = 0.0;

                  gbbdp = -(here->omiBSIM4gbds);
                  gbbsp = here->omiBSIM4gbds + here->omiBSIM4gbgs + here->omiBSIM4gbbs;
                  gbdpg = here->omiBSIM4gbgs;
                  gbdpdp = here->omiBSIM4gbds;
                  gbdpb = here->omiBSIM4gbbs;
                  gbdpsp = -(gbdpg + gbdpdp + gbdpb);

                  gbspdp = 0.0;
                  gbspg = 0.0;
                  gbspb = 0.0;
                  gbspsp = 0.0;

                  if (model->omiBSIM4igcMod)
                  {   gIstotg = here->omiBSIM4gIgsg + here->omiBSIM4gIgcsg;
                      gIstotd = here->omiBSIM4gIgcsd;
                      gIstots = here->omiBSIM4gIgss + here->omiBSIM4gIgcss;
                      gIstotb = here->omiBSIM4gIgcsb;

                      gIdtotg = here->omiBSIM4gIgdg + here->omiBSIM4gIgcdg;
                      gIdtotd = here->omiBSIM4gIgdd + here->omiBSIM4gIgcdd;
                      gIdtots = here->omiBSIM4gIgcds;
                      gIdtotb = here->omiBSIM4gIgcdb;
                  }
                  else
                  {   gIstotg = gIstotd = gIstots = gIstotb = 0.0;
                      gIdtotg = gIdtotd = gIdtots = gIdtotb = 0.0;
                  }

                  if (model->omiBSIM4igbMod)
                  {   gIbtotg = here->omiBSIM4gIgbg;
                      gIbtotd = here->omiBSIM4gIgbd;
                      gIbtots = here->omiBSIM4gIgbs;
                      gIbtotb = here->omiBSIM4gIgbb;
                  }
                  else
                      gIbtotg = gIbtotd = gIbtots = gIbtotb = 0.0;

                  if ((model->omiBSIM4igcMod != 0) || (model->omiBSIM4igbMod != 0))
                  {   gIgtotg = gIstotg + gIdtotg + gIbtotg;
                      gIgtotd = gIstotd + gIdtotd + gIbtotd ;
                      gIgtots = gIstots + gIdtots + gIbtots;
                      gIgtotb = gIstotb + gIdtotb + gIbtotb;
                  }
                  else
                      gIgtotg = gIgtotd = gIgtots = gIgtotb = 0.0;

                  if (here->omiBSIM4rgateMod == 2)
                      T0 = *(ckt->CKTstates[0] + here->omiBSIM4vges)
                         - *(ckt->CKTstates[0] + here->omiBSIM4vgs);
                  else if (here->omiBSIM4rgateMod == 3)
                      T0 = *(ckt->CKTstates[0] + here->omiBSIM4vgms)
                         - *(ckt->CKTstates[0] + here->omiBSIM4vgs);
                  if (here->omiBSIM4rgateMod > 1)
                  {   gcrgd = here->omiBSIM4gcrgd * T0;
                      gcrgg = here->omiBSIM4gcrgg * T0;
                      gcrgs = here->omiBSIM4gcrgs * T0;
                      gcrgb = here->omiBSIM4gcrgb * T0;
                      gcrgg -= here->omiBSIM4gcrg;
                      gcrg = here->omiBSIM4gcrg;
                  }
                  else
                      gcrg = gcrgd = gcrgg = gcrgs = gcrgb = 0.0;

                  if (here->omiBSIM4acnqsMod == 0)
                  {   if (here->omiBSIM4rgateMod == 3)
                      {   xcgmgmb = cgdo + cgso + pParam->omiBSIM4cgbo;
                          xcgmdb = -cgdo;
                          xcgmsb = -cgso;
                          xcgmbb = -pParam->omiBSIM4cgbo;

                          xcdgmb = xcgmdb;
                          xcsgmb = xcgmsb;
                          xcbgmb = xcgmbb;

                          xcggb = here->omiBSIM4cggb;
                          xcgdb = here->omiBSIM4cgdb;
                          xcgsb = here->omiBSIM4cgsb;
                          xcgbb = -(xcggb + xcgdb + xcgsb);

                          xcdgb = here->omiBSIM4cdgb;
                          xcsgb = -(here->omiBSIM4cggb + here->omiBSIM4cbgb
                                + here->omiBSIM4cdgb);
                          xcbgb = here->omiBSIM4cbgb;
                      }
                      else
                      {   xcggb = here->omiBSIM4cggb + cgdo + cgso
                                + pParam->omiBSIM4cgbo;
                          xcgdb = here->omiBSIM4cgdb - cgdo;
                          xcgsb = here->omiBSIM4cgsb - cgso;
                          xcgbb = -(xcggb + xcgdb + xcgsb);

                          xcdgb = here->omiBSIM4cdgb - cgdo;
                          xcsgb = -(here->omiBSIM4cggb + here->omiBSIM4cbgb
                                + here->omiBSIM4cdgb + cgso);
                          xcbgb = here->omiBSIM4cbgb - pParam->omiBSIM4cgbo;

                          xcdgmb = xcsgmb = xcbgmb = 0.0;
                      }
                      xcddb = here->omiBSIM4cddb + here->omiBSIM4capbd + cgdo;
                      xcdsb = here->omiBSIM4cdsb;

                      xcsdb = -(here->omiBSIM4cgdb + here->omiBSIM4cbdb
                            + here->omiBSIM4cddb);
                      xcssb = here->omiBSIM4capbs + cgso - (here->omiBSIM4cgsb
                            + here->omiBSIM4cbsb + here->omiBSIM4cdsb);

                      if (!here->omiBSIM4rbodyMod)
                      {   xcdbb = -(xcdgb + xcddb + xcdsb + xcdgmb);
                          xcsbb = -(xcsgb + xcsdb + xcssb + xcsgmb);
                          xcbdb = here->omiBSIM4cbdb - here->omiBSIM4capbd;
                          xcbsb = here->omiBSIM4cbsb - here->omiBSIM4capbs;
                          xcdbdb = 0.0;
                      }
                      else
                      {   xcdbb  = -(here->omiBSIM4cddb + here->omiBSIM4cdgb
                                 + here->omiBSIM4cdsb);
                          xcsbb = -(xcsgb + xcsdb + xcssb + xcsgmb)
                                + here->omiBSIM4capbs;
                          xcbdb = here->omiBSIM4cbdb;
                          xcbsb = here->omiBSIM4cbsb;

                          xcdbdb = -here->omiBSIM4capbd;
                          xcsbsb = -here->omiBSIM4capbs;
                      }
                      xcbbb = -(xcbdb + xcbgb + xcbsb + xcbgmb);

                      xgtg = xgtd = xgts = xgtb = 0.0;
                      sxpart = 0.6;
                      dxpart = 0.4;
                      ddxpart_dVd = ddxpart_dVg = ddxpart_dVb
                                  = ddxpart_dVs = 0.0;
                      dsxpart_dVd = dsxpart_dVg = dsxpart_dVb
                                  = dsxpart_dVs = 0.0;
                  }
                  else
                  {   xcggb = xcgdb = xcgsb = xcgbb = 0.0;
                      xcbgb = xcbdb = xcbsb = xcbbb = 0.0;
                      xcdgb = xcddb = xcdsb = xcdbb = 0.0;
                      xcsgb = xcsdb = xcssb = xcsbb = 0.0;

                      xgtg = here->omiBSIM4gtg;
                      xgtd = here->omiBSIM4gtd;
                      xgts = here->omiBSIM4gts;
                      xgtb = here->omiBSIM4gtb;

                      xcqgb = here->omiBSIM4cqgb;
                      xcqdb = here->omiBSIM4cqdb;
                      xcqsb = here->omiBSIM4cqsb;
                      xcqbb = here->omiBSIM4cqbb;

                      CoxWL = model->omiBSIM4coxe * here->pParam->omiBSIM4weffCV
                            * here->omiBSIM4nf * here->pParam->omiBSIM4leffCV;
                      qcheq = -(here->omiBSIM4qgate + here->omiBSIM4qbulk);
                      if (fabs(qcheq) <= 1.0e-5 * CoxWL)
                      {   if (model->omiBSIM4xpart < 0.5)
                          {   dxpart = 0.4;
                          }
                          else if (model->omiBSIM4xpart > 0.5)
                          {   dxpart = 0.0;
                          }
                          else
                          {   dxpart = 0.5;
                          }
                          ddxpart_dVd = ddxpart_dVg = ddxpart_dVb
                                      = ddxpart_dVs = 0.0;
                      }
                      else
                      {   dxpart = here->omiBSIM4qdrn / qcheq;
                          Cdd = here->omiBSIM4cddb;
                          Csd = -(here->omiBSIM4cgdb + here->omiBSIM4cddb
                              + here->omiBSIM4cbdb);
                          ddxpart_dVd = (Cdd - dxpart * (Cdd + Csd)) / qcheq;
                          Cdg = here->omiBSIM4cdgb;
                          Csg = -(here->omiBSIM4cggb + here->omiBSIM4cdgb
                              + here->omiBSIM4cbgb);
                          ddxpart_dVg = (Cdg - dxpart * (Cdg + Csg)) / qcheq;

                          Cds = here->omiBSIM4cdsb;
                          Css = -(here->omiBSIM4cgsb + here->omiBSIM4cdsb
                              + here->omiBSIM4cbsb);
                          ddxpart_dVs = (Cds - dxpart * (Cds + Css)) / qcheq;

                          ddxpart_dVb = -(ddxpart_dVd + ddxpart_dVg
                                      + ddxpart_dVs);
                      }
                      sxpart = 1.0 - dxpart;
                      dsxpart_dVd = -ddxpart_dVd;
                      dsxpart_dVg = -ddxpart_dVg;
                      dsxpart_dVs = -ddxpart_dVs;
                      dsxpart_dVb = -(dsxpart_dVd + dsxpart_dVg + dsxpart_dVs);
                  }
              }
              else
              {   Gm = -here->omiBSIM4gm;
                  Gmbs = -here->omiBSIM4gmbs;
                  FwdSum = 0.0;
                  RevSum = -(Gm + Gmbs);

                  gbbsp = -(here->omiBSIM4gbds);
                  gbbdp = here->omiBSIM4gbds + here->omiBSIM4gbgs + here->omiBSIM4gbbs;

                  gbdpg = 0.0;
                  gbdpsp = 0.0;
                  gbdpb = 0.0;
                  gbdpdp = 0.0;

                  gbspg = here->omiBSIM4gbgs;
                  gbspsp = here->omiBSIM4gbds;
                  gbspb = here->omiBSIM4gbbs;
                  gbspdp = -(gbspg + gbspsp + gbspb);

                  if (model->omiBSIM4igcMod)
                  {   gIstotg = here->omiBSIM4gIgsg + here->omiBSIM4gIgcdg;
                      gIstotd = here->omiBSIM4gIgcds;
                      gIstots = here->omiBSIM4gIgss + here->omiBSIM4gIgcdd;
                      gIstotb = here->omiBSIM4gIgcdb;

                      gIdtotg = here->omiBSIM4gIgdg + here->omiBSIM4gIgcsg;
                      gIdtotd = here->omiBSIM4gIgdd + here->omiBSIM4gIgcss;
                      gIdtots = here->omiBSIM4gIgcsd;
                      gIdtotb = here->omiBSIM4gIgcsb;
                  }
                  else
                  {   gIstotg = gIstotd = gIstots = gIstotb = 0.0;
                      gIdtotg = gIdtotd = gIdtots = gIdtotb  = 0.0;
                  }

                  if (model->omiBSIM4igbMod)
                  {   gIbtotg = here->omiBSIM4gIgbg;
                      gIbtotd = here->omiBSIM4gIgbs;
                      gIbtots = here->omiBSIM4gIgbd;
                      gIbtotb = here->omiBSIM4gIgbb;
                  }
                  else
                      gIbtotg = gIbtotd = gIbtots = gIbtotb = 0.0;

                  if ((model->omiBSIM4igcMod != 0) || (model->omiBSIM4igbMod != 0))
                  {   gIgtotg = gIstotg + gIdtotg + gIbtotg;
                      gIgtotd = gIstotd + gIdtotd + gIbtotd ;
                      gIgtots = gIstots + gIdtots + gIbtots;
                      gIgtotb = gIstotb + gIdtotb + gIbtotb;
                  }
                  else
                      gIgtotg = gIgtotd = gIgtots = gIgtotb = 0.0;

                  if (here->omiBSIM4rgateMod == 2)
                      T0 = *(ckt->CKTstates[0] + here->omiBSIM4vges)
                         - *(ckt->CKTstates[0] + here->omiBSIM4vgs);
                  else if (here->omiBSIM4rgateMod == 3)
                      T0 = *(ckt->CKTstates[0] + here->omiBSIM4vgms)
                         - *(ckt->CKTstates[0] + here->omiBSIM4vgs);
                  if (here->omiBSIM4rgateMod > 1)
                  {   gcrgd = here->omiBSIM4gcrgs * T0;
                      gcrgg = here->omiBSIM4gcrgg * T0;
                      gcrgs = here->omiBSIM4gcrgd * T0;
                      gcrgb = here->omiBSIM4gcrgb * T0;
                      gcrgg -= here->omiBSIM4gcrg;
                      gcrg = here->omiBSIM4gcrg;
                  }
                  else
                      gcrg = gcrgd = gcrgg = gcrgs = gcrgb = 0.0;

                  if (here->omiBSIM4acnqsMod == 0)
                  {   if (here->omiBSIM4rgateMod == 3)
                      {   xcgmgmb = cgdo + cgso + pParam->omiBSIM4cgbo;
                          xcgmdb = -cgdo;
                          xcgmsb = -cgso;
                          xcgmbb = -pParam->omiBSIM4cgbo;

                          xcdgmb = xcgmdb;
                          xcsgmb = xcgmsb;
                          xcbgmb = xcgmbb;

                          xcggb = here->omiBSIM4cggb;
                          xcgdb = here->omiBSIM4cgsb;
                          xcgsb = here->omiBSIM4cgdb;
                          xcgbb = -(xcggb + xcgdb + xcgsb);

                          xcdgb = -(here->omiBSIM4cggb + here->omiBSIM4cbgb
                                + here->omiBSIM4cdgb);
                          xcsgb = here->omiBSIM4cdgb;
                          xcbgb = here->omiBSIM4cbgb;
                      }
                      else
                      {   xcggb = here->omiBSIM4cggb + cgdo + cgso
                                + pParam->omiBSIM4cgbo;
                          xcgdb = here->omiBSIM4cgsb - cgdo;
                          xcgsb = here->omiBSIM4cgdb - cgso;
                          xcgbb = -(xcggb + xcgdb + xcgsb);

                          xcdgb = -(here->omiBSIM4cggb + here->omiBSIM4cbgb
                                + here->omiBSIM4cdgb + cgdo);
                          xcsgb = here->omiBSIM4cdgb - cgso;
                          xcbgb = here->omiBSIM4cbgb - pParam->omiBSIM4cgbo;

                          xcdgmb = xcsgmb = xcbgmb = 0.0;
                      }
                      xcddb = here->omiBSIM4capbd + cgdo - (here->omiBSIM4cgsb
                            + here->omiBSIM4cbsb + here->omiBSIM4cdsb);
                      xcdsb = -(here->omiBSIM4cgdb + here->omiBSIM4cbdb
                            + here->omiBSIM4cddb);

                      xcsdb = here->omiBSIM4cdsb;
                      xcssb = here->omiBSIM4cddb + here->omiBSIM4capbs + cgso;

                      if (!here->omiBSIM4rbodyMod)
                      {   xcdbb = -(xcdgb + xcddb + xcdsb + xcdgmb);
                          xcsbb = -(xcsgb + xcsdb + xcssb + xcsgmb);
                          xcbdb = here->omiBSIM4cbsb - here->omiBSIM4capbd;
                          xcbsb = here->omiBSIM4cbdb - here->omiBSIM4capbs;
                          xcdbdb = 0.0;
                      }
                      else
                      {   xcdbb = -(xcdgb + xcddb + xcdsb + xcdgmb)
                                + here->omiBSIM4capbd;
                          xcsbb = -(here->omiBSIM4cddb + here->omiBSIM4cdgb
                                + here->omiBSIM4cdsb);
                          xcbdb = here->omiBSIM4cbsb;
                          xcbsb = here->omiBSIM4cbdb;
                          xcdbdb = -here->omiBSIM4capbd;
                          xcsbsb = -here->omiBSIM4capbs;
                      }
                      xcbbb = -(xcbgb + xcbdb + xcbsb + xcbgmb);

                      xgtg = xgtd = xgts = xgtb = 0.0;
                      sxpart = 0.4;
                      dxpart = 0.6;
                      ddxpart_dVd = ddxpart_dVg = ddxpart_dVb
                                  = ddxpart_dVs = 0.0;
                      dsxpart_dVd = dsxpart_dVg = dsxpart_dVb
                                  = dsxpart_dVs = 0.0;
                  }
                  else
                  {   xcggb = xcgdb = xcgsb = xcgbb = 0.0;
                      xcbgb = xcbdb = xcbsb = xcbbb = 0.0;
                      xcdgb = xcddb = xcdsb = xcdbb = 0.0;
                      xcsgb = xcsdb = xcssb = xcsbb = 0.0;

                      xgtg = here->omiBSIM4gtg;
                      xgtd = here->omiBSIM4gts;
                      xgts = here->omiBSIM4gtd;
                      xgtb = here->omiBSIM4gtb;

                      xcqgb = here->omiBSIM4cqgb;
                      xcqdb = here->omiBSIM4cqsb;
                      xcqsb = here->omiBSIM4cqdb;
                      xcqbb = here->omiBSIM4cqbb;

                      CoxWL = model->omiBSIM4coxe * here->pParam->omiBSIM4weffCV
                            * here->omiBSIM4nf * here->pParam->omiBSIM4leffCV;
                      qcheq = -(here->omiBSIM4qgate + here->omiBSIM4qbulk);
                      if (fabs(qcheq) <= 1.0e-5 * CoxWL)
                      {   if (model->omiBSIM4xpart < 0.5)
                          {   sxpart = 0.4;
                          }
                          else if (model->omiBSIM4xpart > 0.5)
                          {   sxpart = 0.0;
                          }
                          else
                          {   sxpart = 0.5;
                          }
                          dsxpart_dVd = dsxpart_dVg = dsxpart_dVb
                                      = dsxpart_dVs = 0.0;
                      }
                      else
                      {   sxpart = here->omiBSIM4qdrn / qcheq;
                          Css = here->omiBSIM4cddb;
                          Cds = -(here->omiBSIM4cgdb + here->omiBSIM4cddb
                              + here->omiBSIM4cbdb);
                          dsxpart_dVs = (Css - sxpart * (Css + Cds)) / qcheq;
                          Csg = here->omiBSIM4cdgb;
                          Cdg = -(here->omiBSIM4cggb + here->omiBSIM4cdgb
                              + here->omiBSIM4cbgb);
                          dsxpart_dVg = (Csg - sxpart * (Csg + Cdg)) / qcheq;

                          Csd = here->omiBSIM4cdsb;
                          Cdd = -(here->omiBSIM4cgsb + here->omiBSIM4cdsb
                              + here->omiBSIM4cbsb);
                          dsxpart_dVd = (Csd - sxpart * (Csd + Cdd)) / qcheq;

                          dsxpart_dVb = -(dsxpart_dVd + dsxpart_dVg
                                      + dsxpart_dVs);
                      }
                      dxpart = 1.0 - sxpart;
                      ddxpart_dVd = -dsxpart_dVd;
                      ddxpart_dVg = -dsxpart_dVg;
                      ddxpart_dVs = -dsxpart_dVs;
                      ddxpart_dVb = -(ddxpart_dVd + ddxpart_dVg + ddxpart_dVs);
                  }
              }

              if (model->omiBSIM4rdsMod == 1)
              {   gstot = here->omiBSIM4gstot;
                  gstotd = here->omiBSIM4gstotd;
                  gstotg = here->omiBSIM4gstotg;
                  gstots = here->omiBSIM4gstots - gstot;
                  gstotb = here->omiBSIM4gstotb;

                  gdtot = here->omiBSIM4gdtot;
                  gdtotd = here->omiBSIM4gdtotd - gdtot;
                  gdtotg = here->omiBSIM4gdtotg;
                  gdtots = here->omiBSIM4gdtots;
                  gdtotb = here->omiBSIM4gdtotb;
              }
              else
              {   gstot = gstotd = gstotg = gstots = gstotb = 0.0;
                  gdtot = gdtotd = gdtotg = gdtots = gdtotb = 0.0;
              }


              T1 = *(ckt->CKTstate0 + here->omiBSIM4qdef) * here->omiBSIM4gtau;
              gds = here->omiBSIM4gds;

              /*
               * Loading PZ matrix
               */
              m = here->omiBSIM4m;

              if (!model->omiBSIM4rdsMod)
              {   gdpr = here->omiBSIM4drainConductance;
                  gspr = here->omiBSIM4sourceConductance;
              }
              else
                  gdpr = gspr = 0.0;

              if (!here->omiBSIM4rbodyMod)
              {   gjbd = here->omiBSIM4gbd;
                  gjbs = here->omiBSIM4gbs;
              }
              else
                  gjbd = gjbs = 0.0;

              geltd = here->omiBSIM4grgeltd;

              if (here->omiBSIM4rgateMod == 1)
              {   *(here->omiBSIM4GEgePtr) += m * geltd;
                  *(here->omiBSIM4GPgePtr) -= m * geltd;
                  *(here->omiBSIM4GEgpPtr) -= m * geltd;

                  *(here->omiBSIM4GPgpPtr ) += m * xcggb * s->real;
                  *(here->omiBSIM4GPgpPtr +1) += m * xcggb * s->imag;
                  *(here->omiBSIM4GPgpPtr) += m * (geltd - xgtg + gIgtotg);
                  *(here->omiBSIM4GPdpPtr ) += m * xcgdb * s->real;
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdb * s->imag;
                  *(here->omiBSIM4GPdpPtr) -= m * (xgtd - gIgtotd);
                  *(here->omiBSIM4GPspPtr ) += m * xcgsb * s->real;
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsb * s->imag;
                  *(here->omiBSIM4GPspPtr) -= m * (xgts - gIgtots);
                  *(here->omiBSIM4GPbpPtr ) += m * xcgbb * s->real;
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbb * s->imag;
                  *(here->omiBSIM4GPbpPtr) -= m * (xgtb - gIgtotb);
              }
              else if (here->omiBSIM4rgateMod == 2)
              {   *(here->omiBSIM4GEgePtr) += m * gcrg;
                  *(here->omiBSIM4GEgpPtr) += m * gcrgg;
                  *(here->omiBSIM4GEdpPtr) += m * gcrgd;
                  *(here->omiBSIM4GEspPtr) += m * gcrgs;
                  *(here->omiBSIM4GEbpPtr) += m * gcrgb;

                  *(here->omiBSIM4GPgePtr) -= m * gcrg;
                  *(here->omiBSIM4GPgpPtr ) += m * xcggb * s->real;
                  *(here->omiBSIM4GPgpPtr +1) += m * xcggb * s->imag;
                  *(here->omiBSIM4GPgpPtr) -= m * (gcrgg + xgtg - gIgtotg);
                  *(here->omiBSIM4GPdpPtr ) += m * xcgdb * s->real;
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdb * s->imag;
                  *(here->omiBSIM4GPdpPtr) -= m * (gcrgd + xgtd - gIgtotd);
                  *(here->omiBSIM4GPspPtr ) += m * xcgsb * s->real;
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsb * s->imag;
                  *(here->omiBSIM4GPspPtr) -= m * (gcrgs + xgts - gIgtots);
                  *(here->omiBSIM4GPbpPtr ) += m * xcgbb * s->real;
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbb * s->imag;
                  *(here->omiBSIM4GPbpPtr) -= m * (gcrgb + xgtb - gIgtotb);
              }
              else if (here->omiBSIM4rgateMod == 3)
              {   *(here->omiBSIM4GEgePtr) += m * geltd;
                  *(here->omiBSIM4GEgmPtr) -= m * geltd;
                  *(here->omiBSIM4GMgePtr) -= m * geltd;
                  *(here->omiBSIM4GMgmPtr) += m * (geltd + gcrg);
                  *(here->omiBSIM4GMgmPtr ) += m * xcgmgmb * s->real;
                  *(here->omiBSIM4GMgmPtr +1) += m * xcgmgmb * s->imag;
  
                  *(here->omiBSIM4GMdpPtr) += m * gcrgd;
                  *(here->omiBSIM4GMdpPtr ) += m * xcgmdb * s->real;
                  *(here->omiBSIM4GMdpPtr +1) += m * xcgmdb * s->imag;
                  *(here->omiBSIM4GMgpPtr) += m * gcrgg;
                  *(here->omiBSIM4GMspPtr) += m * gcrgs;
                  *(here->omiBSIM4GMspPtr ) += m * xcgmsb * s->real;
                  *(here->omiBSIM4GMspPtr +1) += m * xcgmsb * s->imag;
                  *(here->omiBSIM4GMbpPtr) += m * gcrgb;
                  *(here->omiBSIM4GMbpPtr ) += m * xcgmbb * s->real;
                  *(here->omiBSIM4GMbpPtr +1) += m * xcgmbb * s->imag;
  
                  *(here->omiBSIM4DPgmPtr ) += m * xcdgmb * s->real;
                  *(here->omiBSIM4DPgmPtr +1) += m * xcdgmb * s->imag;
                  *(here->omiBSIM4GPgmPtr) -= m * gcrg;
                  *(here->omiBSIM4SPgmPtr ) += m * xcsgmb * s->real;
                  *(here->omiBSIM4SPgmPtr +1) += m * xcsgmb * s->imag;
                  *(here->omiBSIM4BPgmPtr ) += m * xcbgmb * s->real;
                  *(here->omiBSIM4BPgmPtr +1) += m * xcbgmb * s->imag;
  
                  *(here->omiBSIM4GPgpPtr) -= m * (gcrgg + xgtg - gIgtotg);
                  *(here->omiBSIM4GPgpPtr ) += m * xcggb * s->real;
                  *(here->omiBSIM4GPgpPtr +1) += m * xcggb * s->imag;
                  *(here->omiBSIM4GPdpPtr) -= m * (gcrgd + xgtd - gIgtotd);
                  *(here->omiBSIM4GPdpPtr ) += m * xcgdb * s->real;
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdb * s->imag;
                  *(here->omiBSIM4GPspPtr) -= m * (gcrgs + xgts - gIgtots);
                  *(here->omiBSIM4GPspPtr ) += m * xcgsb * s->real;
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsb * s->imag;
                  *(here->omiBSIM4GPbpPtr) -= m * (gcrgb + xgtb - gIgtotb);
                  *(here->omiBSIM4GPbpPtr ) += m * xcgbb * s->real;
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbb * s->imag;
              }
              else
              {   *(here->omiBSIM4GPdpPtr ) += m * xcgdb * s->real;
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdb * s->imag;
                  *(here->omiBSIM4GPdpPtr) -= m * (xgtd - gIgtotd);
                  *(here->omiBSIM4GPgpPtr ) += m * xcggb * s->real;
                  *(here->omiBSIM4GPgpPtr +1) += m * xcggb * s->imag;
                  *(here->omiBSIM4GPgpPtr) -= m * (xgtg - gIgtotg);
                  *(here->omiBSIM4GPspPtr ) += m * xcgsb * s->real;
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsb * s->imag;
                  *(here->omiBSIM4GPspPtr) -= m * (xgts - gIgtots);
                  *(here->omiBSIM4GPbpPtr ) += m * xcgbb * s->real;
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbb * s->imag;
                  *(here->omiBSIM4GPbpPtr) -= m * (xgtb - gIgtotb);
              }

              if (model->omiBSIM4rdsMod)
              {   (*(here->omiBSIM4DgpPtr) += m * gdtotg);
                  (*(here->omiBSIM4DspPtr) += m * gdtots);
                  (*(here->omiBSIM4DbpPtr) += m * gdtotb);
                  (*(here->omiBSIM4SdpPtr) += m * gstotd);
                  (*(here->omiBSIM4SgpPtr) += m * gstotg);
                  (*(here->omiBSIM4SbpPtr) += m * gstotb);
              }

              *(here->omiBSIM4DPdpPtr ) += m * xcddb * s->real;
              *(here->omiBSIM4DPdpPtr +1) += m * xcddb * s->imag;
              *(here->omiBSIM4DPdpPtr) += m * (gdpr + gds + here->omiBSIM4gbd
                                     - gdtotd + RevSum + gbdpdp - gIdtotd
                                     + dxpart * xgtd + T1 * ddxpart_dVd);
              *(here->omiBSIM4DPdPtr) -= m * (gdpr + gdtot);
              *(here->omiBSIM4DPgpPtr ) += m * xcdgb * s->real;
              *(here->omiBSIM4DPgpPtr +1) += m * xcdgb * s->imag;
              *(here->omiBSIM4DPgpPtr) += m * (Gm - gdtotg + gbdpg - gIdtotg
                                     + T1 * ddxpart_dVg + dxpart * xgtg);
              *(here->omiBSIM4DPspPtr ) += m * xcdsb * s->real;
              *(here->omiBSIM4DPspPtr +1) += m * xcdsb * s->imag;
              *(here->omiBSIM4DPspPtr) -= m * (gds + FwdSum + gdtots - gbdpsp + gIdtots
                                     - T1 * ddxpart_dVs - dxpart * xgts);
              *(here->omiBSIM4DPbpPtr ) += m * xcdbb * s->real;
              *(here->omiBSIM4DPbpPtr +1) += m * xcdbb * s->imag;
              *(here->omiBSIM4DPbpPtr) -= m * (gjbd + gdtotb - Gmbs - gbdpb + gIdtotb
                                     - T1 * ddxpart_dVb - dxpart * xgtb);

              *(here->omiBSIM4DdpPtr) -= m * (gdpr - gdtotd);
              *(here->omiBSIM4DdPtr) += m * (gdpr + gdtot);

              *(here->omiBSIM4SPdpPtr ) += m * xcsdb * s->real;
              *(here->omiBSIM4SPdpPtr +1) += m * xcsdb * s->imag;
              *(here->omiBSIM4SPdpPtr) -= m * (gds + gstotd + RevSum - gbspdp + gIstotd
                                     - T1 * dsxpart_dVd - sxpart * xgtd);
              *(here->omiBSIM4SPgpPtr ) += m * xcsgb * s->real;
              *(here->omiBSIM4SPgpPtr +1) += m * xcsgb * s->imag;
              *(here->omiBSIM4SPgpPtr) -= m * (Gm + gstotg - gbspg + gIstotg
                                     - T1 * dsxpart_dVg - sxpart * xgtg);
              *(here->omiBSIM4SPspPtr ) += m * xcssb * s->real;
              *(here->omiBSIM4SPspPtr +1) += m * xcssb * s->imag;
              *(here->omiBSIM4SPspPtr) += m * (gspr + gds + here->omiBSIM4gbs - gIstots
                                     - gstots + FwdSum + gbspsp
                                     + sxpart * xgts + T1 * dsxpart_dVs);
              *(here->omiBSIM4SPsPtr) -= m * (gspr + gstot);
              *(here->omiBSIM4SPbpPtr ) += m * xcsbb * s->real;
              *(here->omiBSIM4SPbpPtr +1) += m * xcsbb * s->imag;
              *(here->omiBSIM4SPbpPtr) -= m * (gjbs + gstotb + Gmbs - gbspb + gIstotb
                                     - T1 * dsxpart_dVb - sxpart * xgtb);

              *(here->omiBSIM4SspPtr) -= m * (gspr - gstots);
              *(here->omiBSIM4SsPtr) += m * (gspr + gstot);

              *(here->omiBSIM4BPdpPtr ) += m * xcbdb * s->real;
              *(here->omiBSIM4BPdpPtr +1) += m * xcbdb * s->imag;
              *(here->omiBSIM4BPdpPtr) -= m * (gjbd - gbbdp + gIbtotd);
              *(here->omiBSIM4BPgpPtr ) += m * xcbgb * s->real;
              *(here->omiBSIM4BPgpPtr +1) += m * xcbgb * s->imag;
              *(here->omiBSIM4BPgpPtr) -= m * (here->omiBSIM4gbgs + gIbtotg);
              *(here->omiBSIM4BPspPtr ) += m * xcbsb * s->real;
              *(here->omiBSIM4BPspPtr +1) += m * xcbsb * s->imag;
              *(here->omiBSIM4BPspPtr) -= m * (gjbs - gbbsp + gIbtots);
              *(here->omiBSIM4BPbpPtr ) += m * xcbbb * s->real;
              *(here->omiBSIM4BPbpPtr +1) += m * xcbbb * s->imag;
              *(here->omiBSIM4BPbpPtr) += m * (gjbd + gjbs - here->omiBSIM4gbbs
                                     - gIbtotb);
              ggidld = here->omiBSIM4ggidld;
              ggidlg = here->omiBSIM4ggidlg;
              ggidlb = here->omiBSIM4ggidlb;
              ggislg = here->omiBSIM4ggislg;
              ggisls = here->omiBSIM4ggisls;
              ggislb = here->omiBSIM4ggislb;

              /* stamp gidl */
              (*(here->omiBSIM4DPdpPtr) += m * ggidld);
              (*(here->omiBSIM4DPgpPtr) += m * ggidlg);
              (*(here->omiBSIM4DPspPtr) -= m * ((ggidlg + ggidld) + ggidlb));
              (*(here->omiBSIM4DPbpPtr) += m * ggidlb);
              (*(here->omiBSIM4BPdpPtr) -= m * ggidld);
              (*(here->omiBSIM4BPgpPtr) -= m * ggidlg);
              (*(here->omiBSIM4BPspPtr) += m * ((ggidlg + ggidld) + ggidlb));
              (*(here->omiBSIM4BPbpPtr) -= m * ggidlb);
               /* stamp gisl */
              (*(here->omiBSIM4SPdpPtr) -= m * ((ggisls + ggislg) + ggislb));
              (*(here->omiBSIM4SPgpPtr) += m * ggislg);
              (*(here->omiBSIM4SPspPtr) += m * ggisls);
              (*(here->omiBSIM4SPbpPtr) += m * ggislb);
              (*(here->omiBSIM4BPdpPtr) += m * ((ggislg + ggisls) + ggislb));
              (*(here->omiBSIM4BPgpPtr) -= m * ggislg);
              (*(here->omiBSIM4BPspPtr) -= m * ggisls);
              (*(here->omiBSIM4BPbpPtr) -= m * ggislb);

              if (here->omiBSIM4rbodyMod)
              {   (*(here->omiBSIM4DPdbPtr ) += m * xcdbdb * s->real);
                  (*(here->omiBSIM4DPdbPtr +1) += m * xcdbdb * s->imag);
                  (*(here->omiBSIM4DPdbPtr) -= m * here->omiBSIM4gbd);
                  (*(here->omiBSIM4SPsbPtr ) += m * xcsbsb * s->real);
                  (*(here->omiBSIM4SPsbPtr +1) += m * xcsbsb * s->imag);
                  (*(here->omiBSIM4SPsbPtr) -= m * here->omiBSIM4gbs);

                  (*(here->omiBSIM4DBdpPtr ) += m * xcdbdb * s->real);
                  (*(here->omiBSIM4DBdpPtr +1) += m * xcdbdb * s->imag);
                  (*(here->omiBSIM4DBdpPtr) -= m * here->omiBSIM4gbd);
                  (*(here->omiBSIM4DBdbPtr ) -= m * xcdbdb * s->real);
                  (*(here->omiBSIM4DBdbPtr +1) -= m * xcdbdb * s->imag);
                  (*(here->omiBSIM4DBdbPtr) += m * (here->omiBSIM4gbd + here->omiBSIM4grbpd
                                          + here->omiBSIM4grbdb));
                  (*(here->omiBSIM4DBbpPtr) -= m * here->omiBSIM4grbpd);
                  (*(here->omiBSIM4DBbPtr) -= m * here->omiBSIM4grbdb);

                  (*(here->omiBSIM4BPdbPtr) -= m * here->omiBSIM4grbpd);
                  (*(here->omiBSIM4BPbPtr) -= m * here->omiBSIM4grbpb);
                  (*(here->omiBSIM4BPsbPtr) -= m * here->omiBSIM4grbps);
                  (*(here->omiBSIM4BPbpPtr) += m * (here->omiBSIM4grbpd + here->omiBSIM4grbps
                                          + here->omiBSIM4grbpb));
                  /* WDL: (-here->omiBSIM4gbbs) already added to BPbpPtr */

                  (*(here->omiBSIM4SBspPtr ) += m * xcsbsb * s->real);
                  (*(here->omiBSIM4SBspPtr +1) += m * xcsbsb * s->imag);
                  (*(here->omiBSIM4SBspPtr) -= m * here->omiBSIM4gbs);
                  (*(here->omiBSIM4SBbpPtr) -= m * here->omiBSIM4grbps);
                  (*(here->omiBSIM4SBbPtr) -= m * here->omiBSIM4grbsb);
                  (*(here->omiBSIM4SBsbPtr ) -= m * xcsbsb * s->real);
                  (*(here->omiBSIM4SBsbPtr +1) -= m * xcsbsb * s->imag);
                  (*(here->omiBSIM4SBsbPtr) += m * (here->omiBSIM4gbs
                                          + here->omiBSIM4grbps + here->omiBSIM4grbsb));

                  (*(here->omiBSIM4BdbPtr) -= m * here->omiBSIM4grbdb);
                  (*(here->omiBSIM4BbpPtr) -= m * here->omiBSIM4grbpb);
                  (*(here->omiBSIM4BsbPtr) -= m * here->omiBSIM4grbsb);
                  (*(here->omiBSIM4BbPtr) += m * (here->omiBSIM4grbsb + here->omiBSIM4grbdb
                                        + here->omiBSIM4grbpb));
              }

              if (here->omiBSIM4acnqsMod)
              {   *(here->omiBSIM4QqPtr ) += m * s->real * ScalingFactor;
                  *(here->omiBSIM4QqPtr +1) += m * s->imag * ScalingFactor;
                  *(here->omiBSIM4QgpPtr ) -= m * xcqgb * s->real;
                  *(here->omiBSIM4QgpPtr +1) -= m * xcqgb * s->imag;
                  *(here->omiBSIM4QdpPtr ) -= m * xcqdb * s->real;
                  *(here->omiBSIM4QdpPtr +1) -= m * xcqdb * s->imag;
                  *(here->omiBSIM4QbpPtr ) -= m * xcqbb * s->real;
                  *(here->omiBSIM4QbpPtr +1) -= m * xcqbb * s->imag;
                  *(here->omiBSIM4QspPtr ) -= m * xcqsb * s->real;
                  *(here->omiBSIM4QspPtr +1) -= m * xcqsb * s->imag;

                  *(here->omiBSIM4GPqPtr) -= m * here->omiBSIM4gtau;
                  *(here->omiBSIM4DPqPtr) += m * dxpart * here->omiBSIM4gtau;
                  *(here->omiBSIM4SPqPtr) += m * sxpart * here->omiBSIM4gtau;

                  *(here->omiBSIM4QqPtr) += m * here->omiBSIM4gtau;
                  *(here->omiBSIM4QgpPtr) += m * xgtg;
                  *(here->omiBSIM4QdpPtr) += m * xgtd;
                  *(here->omiBSIM4QbpPtr) += m * xgtb;
                  *(here->omiBSIM4QspPtr) += m * xgts;
              }
         }
    }
    return(OK);
}
