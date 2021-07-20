/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4acld.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 10/05/2001.
 **********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "omibsim4def.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"


int
omiBSIM4acLoad(
GENmodel *inModel,
CKTcircuit *ckt)
{
omiBSIM4model *model = (omiBSIM4model*)inModel;
omiBSIM4instance *here;

double gjbd, gjbs, geltd, gcrg, gcrgg, gcrgd, gcrgs, gcrgb;
double xcbgb, xcbdb, xcbsb, xcbbb;
double xcggbr, xcgdbr, xcgsbr, xcgbbr, xcggbi, xcgdbi, xcgsbi, xcgbbi;
double Cggr, Cgdr, Cgsr, Cgbr, Cggi, Cgdi, Cgsi, Cgbi;
double xcddbr, xcdgbr, xcdsbr, xcdbbr, xcsdbr, xcsgbr, xcssbr, xcsbbr;
double xcddbi, xcdgbi, xcdsbi, xcdbbi, xcsdbi, xcsgbi, xcssbi, xcsbbi;
double xcdbdb, xcsbsb=0.0, xcgmgmb=0.0, xcgmdb=0.0, xcgmsb=0.0, xcdgmb, xcsgmb;
double xcgmbb=0.0, xcbgmb;
double capbd, capbs, omega;
double gstot, gstotd, gstotg, gstots, gstotb, gspr;
double gdtot, gdtotd, gdtotg, gdtots, gdtotb, gdpr;
double gIstotg, gIstotd, gIstots, gIstotb;
double gIdtotg, gIdtotd, gIdtots, gIdtotb;
double gIbtotg, gIbtotd, gIbtots, gIbtotb;
double gIgtotg, gIgtotd, gIgtots, gIgtotb;
double cgso, cgdo, cgbo;
double gbspsp, gbbdp, gbbsp, gbspg, gbspb;
double gbspdp, gbdpdp, gbdpg, gbdpb, gbdpsp;
double T0=0.0, T1, T2, T3;
double Csg, Csd, Css;
double Cdgr, Cddr, Cdsr, Cdbr, Csgr, Csdr, Cssr, Csbr;
double Cdgi, Cddi, Cdsi, Cdbi, Csgi, Csdi, Cssi, Csbi;
double gmr, gmi, gmbsr, gmbsi, gdsr, gdsi;
double FwdSumr, RevSumr, Gmr, Gmbsr;
double FwdSumi, RevSumi, Gmi, Gmbsi;
struct bsim4SizeDependParam *pParam;
double ggidld, ggidlg, ggidlb, ggislg, ggislb, ggisls;

double m;

    omega = ckt->CKTomega;
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

              Csd = -(here->omiBSIM4cddb + here->omiBSIM4cgdb + here->omiBSIM4cbdb);
              Csg = -(here->omiBSIM4cdgb + here->omiBSIM4cggb + here->omiBSIM4cbgb);
              Css = -(here->omiBSIM4cdsb + here->omiBSIM4cgsb + here->omiBSIM4cbsb);

              if (here->omiBSIM4acnqsMod)
              {   T0 = omega * here->omiBSIM4taunet;
                  T1 = T0 * T0;
                  T2 = 1.0 / (1.0 + T1);
                  T3 = T0 * T2;

                  gmr = here->omiBSIM4gm * T2;
                  gmbsr = here->omiBSIM4gmbs * T2;
                  gdsr = here->omiBSIM4gds * T2;

                  gmi = -here->omiBSIM4gm * T3;
                  gmbsi = -here->omiBSIM4gmbs * T3;
                  gdsi = -here->omiBSIM4gds * T3;

                  Cddr = here->omiBSIM4cddb * T2;
                  Cdgr = here->omiBSIM4cdgb * T2;
                  Cdsr = here->omiBSIM4cdsb * T2;
                  Cdbr = -(Cddr + Cdgr + Cdsr);

                  /* WDLiu: Cxyi mulitplied by jomega below, and actually to be of conductance */
                  Cddi = here->omiBSIM4cddb * T3 * omega;
                  Cdgi = here->omiBSIM4cdgb * T3 * omega;
                  Cdsi = here->omiBSIM4cdsb * T3 * omega;
                  Cdbi = -(Cddi + Cdgi + Cdsi);

                  Csdr = Csd * T2;
                  Csgr = Csg * T2;
                  Cssr = Css * T2;
                  Csbr = -(Csdr + Csgr + Cssr);

                  Csdi = Csd * T3 * omega;
                  Csgi = Csg * T3 * omega;
                  Cssi = Css * T3 * omega;
                  Csbi = -(Csdi + Csgi + Cssi);

                  Cgdr = -(Cddr + Csdr + here->omiBSIM4cbdb);
                  Cggr = -(Cdgr + Csgr + here->omiBSIM4cbgb);
                  Cgsr = -(Cdsr + Cssr + here->omiBSIM4cbsb);
                  Cgbr = -(Cgdr + Cggr + Cgsr);

                  Cgdi = -(Cddi + Csdi);
                  Cggi = -(Cdgi + Csgi);
                  Cgsi = -(Cdsi + Cssi);
                  Cgbi = -(Cgdi + Cggi + Cgsi);
              }
              else /* QS */
              {   gmr = here->omiBSIM4gm;
                  gmbsr = here->omiBSIM4gmbs;
                  gdsr = here->omiBSIM4gds;
                  gmi = gmbsi = gdsi = 0.0;

                  Cddr = here->omiBSIM4cddb;
                  Cdgr = here->omiBSIM4cdgb;
                  Cdsr = here->omiBSIM4cdsb;
                  Cdbr = -(Cddr + Cdgr + Cdsr);
                  Cddi = Cdgi = Cdsi = Cdbi = 0.0;

                  Csdr = Csd;
                  Csgr = Csg;
                  Cssr = Css;
                  Csbr = -(Csdr + Csgr + Cssr);
                  Csdi = Csgi = Cssi = Csbi = 0.0;

                  Cgdr = here->omiBSIM4cgdb;
                  Cggr = here->omiBSIM4cggb;
                  Cgsr = here->omiBSIM4cgsb;
                  Cgbr = -(Cgdr + Cggr + Cgsr);
                  Cgdi = Cggi = Cgsi = Cgbi = 0.0;
              }


              if (here->omiBSIM4mode >= 0) 
              {   Gmr = gmr;
                  Gmbsr = gmbsr;
                  FwdSumr = Gmr + Gmbsr;
                  RevSumr = 0.0;
                  Gmi = gmi;
                  Gmbsi = gmbsi;
                  FwdSumi = Gmi + Gmbsi;
                  RevSumi = 0.0;

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

                  if (here->omiBSIM4rgateMod == 3)
                  {   xcgmgmb = (cgdo + cgso + pParam->omiBSIM4cgbo) * omega;
                      xcgmdb = -cgdo * omega;
                      xcgmsb = -cgso * omega;
                      xcgmbb = -pParam->omiBSIM4cgbo * omega;
    
                      xcdgmb = xcgmdb;
                      xcsgmb = xcgmsb;
                      xcbgmb = xcgmbb;
    
                      xcggbr = Cggr * omega;
                      xcgdbr = Cgdr * omega;
                      xcgsbr = Cgsr * omega;
                      xcgbbr = -(xcggbr + xcgdbr + xcgsbr);
    
                      xcdgbr = Cdgr * omega;
                      xcsgbr = Csgr * omega;
                      xcbgb = here->omiBSIM4cbgb * omega;
                  }
                  else
                  {   xcggbr = (Cggr + cgdo + cgso + pParam->omiBSIM4cgbo ) * omega;
                      xcgdbr = (Cgdr - cgdo) * omega;
                      xcgsbr = (Cgsr - cgso) * omega;
                      xcgbbr = -(xcggbr + xcgdbr + xcgsbr);
    
                      xcdgbr = (Cdgr - cgdo) * omega;
                      xcsgbr = (Csgr - cgso) * omega;
                      xcbgb = (here->omiBSIM4cbgb - pParam->omiBSIM4cgbo) * omega;
    
                      xcdgmb = xcsgmb = xcbgmb = 0.0;
                  }
                  xcddbr = (Cddr + here->omiBSIM4capbd + cgdo) * omega;
                  xcdsbr = Cdsr * omega;
                  xcsdbr = Csdr * omega;
                  xcssbr = (here->omiBSIM4capbs + cgso + Cssr) * omega;
    
                  if (!here->omiBSIM4rbodyMod)
                  {   xcdbbr = -(xcdgbr + xcddbr + xcdsbr + xcdgmb);
                      xcsbbr = -(xcsgbr + xcsdbr + xcssbr + xcsgmb);

                      xcbdb = (here->omiBSIM4cbdb - here->omiBSIM4capbd) * omega;
                      xcbsb = (here->omiBSIM4cbsb - here->omiBSIM4capbs) * omega;
                      xcdbdb = 0.0;
                  }
                  else
                  {   xcdbbr = Cdbr * omega;
                      xcsbbr = -(xcsgbr + xcsdbr + xcssbr + xcsgmb)
                             + here->omiBSIM4capbs * omega;

                      xcbdb = here->omiBSIM4cbdb * omega;
                      xcbsb = here->omiBSIM4cbsb * omega;
    
                      xcdbdb = -here->omiBSIM4capbd * omega;
                      xcsbsb = -here->omiBSIM4capbs * omega;
                  }
                  xcbbb = -(xcbdb + xcbgb + xcbsb + xcbgmb);

                  xcdgbi = Cdgi;
                  xcsgbi = Csgi;
                  xcddbi = Cddi;
                  xcdsbi = Cdsi;
                  xcsdbi = Csdi;
                  xcssbi = Cssi;
                  xcdbbi = Cdbi;
                  xcsbbi = Csbi;
                  xcggbi = Cggi;
                  xcgdbi = Cgdi;
                  xcgsbi = Cgsi;
                  xcgbbi = Cgbi;
              } 
              else /* Reverse mode */
              {   Gmr = -gmr;
                  Gmbsr = -gmbsr;
                  FwdSumr = 0.0;
                  RevSumr = -(Gmr + Gmbsr);
                  Gmi = -gmi;
                  Gmbsi = -gmbsi;
                  FwdSumi = 0.0;
                  RevSumi = -(Gmi + Gmbsi);

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

                  if (here->omiBSIM4rgateMod == 3)
                  {   xcgmgmb = (cgdo + cgso + pParam->omiBSIM4cgbo) * omega;
                      xcgmdb = -cgdo * omega;
                      xcgmsb = -cgso * omega;
                      xcgmbb = -pParam->omiBSIM4cgbo * omega;
    
                      xcdgmb = xcgmdb;
                      xcsgmb = xcgmsb;
                      xcbgmb = xcgmbb;
   
                      xcggbr = Cggr * omega;
                      xcgdbr = Cgsr * omega;
                      xcgsbr = Cgdr * omega;
                      xcgbbr = -(xcggbr + xcgdbr + xcgsbr);
    
                      xcdgbr = Csgr * omega;
                      xcsgbr = Cdgr * omega;
                      xcbgb = here->omiBSIM4cbgb * omega;
                  }
                  else
                  {   xcggbr = (Cggr + cgdo + cgso + pParam->omiBSIM4cgbo ) * omega;
                      xcgdbr = (Cgsr - cgdo) * omega;
                      xcgsbr = (Cgdr - cgso) * omega;
                      xcgbbr = -(xcggbr + xcgdbr + xcgsbr);
    
                      xcdgbr = (Csgr - cgdo) * omega;
                      xcsgbr = (Cdgr - cgso) * omega;
                      xcbgb = (here->omiBSIM4cbgb - pParam->omiBSIM4cgbo) * omega;
    
                      xcdgmb = xcsgmb = xcbgmb = 0.0;
                  }
                  xcddbr = (here->omiBSIM4capbd + cgdo + Cssr) * omega;
                  xcdsbr = Csdr * omega;
                  xcsdbr = Cdsr * omega;
                  xcssbr = (Cddr + here->omiBSIM4capbs + cgso) * omega;
    
                  if (!here->omiBSIM4rbodyMod)
                  {   xcdbbr = -(xcdgbr + xcddbr + xcdsbr + xcdgmb);
                      xcsbbr = -(xcsgbr + xcsdbr + xcssbr + xcsgmb);

                      xcbdb = (here->omiBSIM4cbsb - here->omiBSIM4capbd) * omega;
                      xcbsb = (here->omiBSIM4cbdb - here->omiBSIM4capbs) * omega;
                      xcdbdb = 0.0;
                  }
                  else
                  {   xcdbbr = -(xcdgbr + xcddbr + xcdsbr + xcdgmb)
                             + here->omiBSIM4capbd * omega;
                      xcsbbr = Cdbr * omega;

                      xcbdb = here->omiBSIM4cbsb * omega;
                      xcbsb = here->omiBSIM4cbdb * omega;
                      xcdbdb = -here->omiBSIM4capbd * omega;
                      xcsbsb = -here->omiBSIM4capbs * omega;
                  }
                  xcbbb = -(xcbgb + xcbdb + xcbsb + xcbgmb);

                  xcdgbi = Csgi;
                  xcsgbi = Cdgi;
                  xcddbi = Cssi;
                  xcdsbi = Csdi;
                  xcsdbi = Cdsi;
                  xcssbi = Cddi;
                  xcdbbi = Csbi;
                  xcsbbi = Cdbi;
                  xcggbi = Cggi;
                  xcgdbi = Cgsi;
                  xcgsbi = Cgdi;
                  xcgbbi = Cgbi;
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


              /*
               * Loading AC matrix
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

                  *(here->omiBSIM4GPgpPtr +1) += m * xcggbr;
                  *(here->omiBSIM4GPgpPtr) += m * (geltd + xcggbi + gIgtotg);
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdbr;
                  *(here->omiBSIM4GPdpPtr) += m * (xcgdbi + gIgtotd);
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsbr;
                  *(here->omiBSIM4GPspPtr) += m * (xcgsbi + gIgtots);
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbbr;
                  *(here->omiBSIM4GPbpPtr) += m * (xcgbbi + gIgtotb);
              } /* WDLiu: gcrg already subtracted from all gcrgg below */
              else if (here->omiBSIM4rgateMod == 2)
              {   *(here->omiBSIM4GEgePtr) += m * gcrg;
                  *(here->omiBSIM4GEgpPtr) += m * gcrgg;
                  *(here->omiBSIM4GEdpPtr) += m * gcrgd;
                  *(here->omiBSIM4GEspPtr) += m * gcrgs;
                  *(here->omiBSIM4GEbpPtr) += m * gcrgb;

                  *(here->omiBSIM4GPgePtr) -= m * gcrg;
                  *(here->omiBSIM4GPgpPtr +1) += m * xcggbr;
                  *(here->omiBSIM4GPgpPtr) -= m * (gcrgg - xcggbi - gIgtotg);
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdbr;
                  *(here->omiBSIM4GPdpPtr) -= m * (gcrgd - xcgdbi - gIgtotd);
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsbr;
                  *(here->omiBSIM4GPspPtr) -= m * (gcrgs - xcgsbi - gIgtots);
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbbr;
                  *(here->omiBSIM4GPbpPtr) -= m * (gcrgb - xcgbbi - gIgtotb);
              }
              else if (here->omiBSIM4rgateMod == 3)
              {   *(here->omiBSIM4GEgePtr) += m * geltd;
                  *(here->omiBSIM4GEgmPtr) -= m * geltd;
                  *(here->omiBSIM4GMgePtr) -= m * geltd;
                  *(here->omiBSIM4GMgmPtr) += m * (geltd + gcrg);
                  *(here->omiBSIM4GMgmPtr +1) += m * xcgmgmb;
   
                  *(here->omiBSIM4GMdpPtr) += m * gcrgd;
                  *(here->omiBSIM4GMdpPtr +1) += m * xcgmdb;
                  *(here->omiBSIM4GMgpPtr) += m * gcrgg;
                  *(here->omiBSIM4GMspPtr) += m * gcrgs;
                  *(here->omiBSIM4GMspPtr +1) += m * xcgmsb;
                  *(here->omiBSIM4GMbpPtr) += m * gcrgb;
                  *(here->omiBSIM4GMbpPtr +1) += m * xcgmbb;
   
                  *(here->omiBSIM4DPgmPtr +1) += m * xcdgmb;
                  *(here->omiBSIM4GPgmPtr) -= m * gcrg;
                  *(here->omiBSIM4SPgmPtr +1) += m * xcsgmb;
                  *(here->omiBSIM4BPgmPtr +1) += m * xcbgmb;
   
                  *(here->omiBSIM4GPgpPtr) -= m * (gcrgg - xcggbi - gIgtotg);
                  *(here->omiBSIM4GPgpPtr +1) += m * xcggbr;
                  *(here->omiBSIM4GPdpPtr) -= m * (gcrgd - xcgdbi - gIgtotd);
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdbr;
                  *(here->omiBSIM4GPspPtr) -= m * (gcrgs - xcgsbi - gIgtots);
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsbr;
                  *(here->omiBSIM4GPbpPtr) -= m * (gcrgb - xcgbbi - gIgtotb);
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbbr;
              }
              else
              {   *(here->omiBSIM4GPgpPtr +1) += m * xcggbr;
                  *(here->omiBSIM4GPgpPtr) += m * (xcggbi + gIgtotg);
                  *(here->omiBSIM4GPdpPtr +1) += m * xcgdbr;
                  *(here->omiBSIM4GPdpPtr) += m * (xcgdbi + gIgtotd);
                  *(here->omiBSIM4GPspPtr +1) += m * xcgsbr;
                  *(here->omiBSIM4GPspPtr) += m * (xcgsbi + gIgtots);
                  *(here->omiBSIM4GPbpPtr +1) += m * xcgbbr;
                  *(here->omiBSIM4GPbpPtr) += m * (xcgbbi + gIgtotb);
              }

              if (model->omiBSIM4rdsMod)
              {   (*(here->omiBSIM4DgpPtr) += m * gdtotg);
                  (*(here->omiBSIM4DspPtr) += m * gdtots);
                  (*(here->omiBSIM4DbpPtr) += m * gdtotb);
                  (*(here->omiBSIM4SdpPtr) += m * gstotd);
                  (*(here->omiBSIM4SgpPtr) += m * gstotg);
                  (*(here->omiBSIM4SbpPtr) += m * gstotb);
              }

              *(here->omiBSIM4DPdpPtr +1) += m * (xcddbr + gdsi + RevSumi);
              *(here->omiBSIM4DPdpPtr) += m * (gdpr + xcddbi + gdsr + here->omiBSIM4gbd 
                                     - gdtotd + RevSumr + gbdpdp - gIdtotd);
              *(here->omiBSIM4DPdPtr) -= m * (gdpr + gdtot);
              *(here->omiBSIM4DPgpPtr +1) += m * (xcdgbr + Gmi);
              *(here->omiBSIM4DPgpPtr) += m * (Gmr + xcdgbi - gdtotg + gbdpg - gIdtotg);
              *(here->omiBSIM4DPspPtr +1) += m * (xcdsbr - gdsi - FwdSumi);
              *(here->omiBSIM4DPspPtr) -= m * (gdsr - xcdsbi + FwdSumr + gdtots - gbdpsp + gIdtots);
              *(here->omiBSIM4DPbpPtr +1) += m * (xcdbbr + Gmbsi);
              *(here->omiBSIM4DPbpPtr) -= m * (gjbd + gdtotb - xcdbbi - Gmbsr - gbdpb + gIdtotb);

              *(here->omiBSIM4DdpPtr) -= m * (gdpr - gdtotd);
              *(here->omiBSIM4DdPtr) += m * (gdpr + gdtot);

              *(here->omiBSIM4SPdpPtr +1) += m * (xcsdbr - gdsi - RevSumi);
              *(here->omiBSIM4SPdpPtr) -= m * (gdsr - xcsdbi + gstotd + RevSumr - gbspdp + gIstotd);
              *(here->omiBSIM4SPgpPtr +1) += m * (xcsgbr - Gmi);
              *(here->omiBSIM4SPgpPtr) -= m * (Gmr - xcsgbi + gstotg - gbspg + gIstotg);
              *(here->omiBSIM4SPspPtr +1) += m * (xcssbr + gdsi + FwdSumi);
              *(here->omiBSIM4SPspPtr) += m * (gspr + xcssbi + gdsr + here->omiBSIM4gbs
                                     - gstots + FwdSumr + gbspsp - gIstots);
              *(here->omiBSIM4SPsPtr) -= m * (gspr + gstot);
              *(here->omiBSIM4SPbpPtr +1) += m * (xcsbbr - Gmbsi);
              *(here->omiBSIM4SPbpPtr) -= m * (gjbs + gstotb - xcsbbi + Gmbsr - gbspb + gIstotb);

              *(here->omiBSIM4SspPtr) -= m * (gspr - gstots);
              *(here->omiBSIM4SsPtr) += m * (gspr + gstot);

              *(here->omiBSIM4BPdpPtr +1) += m * xcbdb;
              *(here->omiBSIM4BPdpPtr) -= m * (gjbd - gbbdp + gIbtotd);
              *(here->omiBSIM4BPgpPtr +1) += m * xcbgb;
              *(here->omiBSIM4BPgpPtr) -= m * (here->omiBSIM4gbgs + gIbtotg);
              *(here->omiBSIM4BPspPtr +1) += m * xcbsb;
              *(here->omiBSIM4BPspPtr) -= m * (gjbs - gbbsp + gIbtots);
              *(here->omiBSIM4BPbpPtr +1) += m * xcbbb;
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
              {   (*(here->omiBSIM4DPdbPtr +1) += m * xcdbdb);
                  (*(here->omiBSIM4DPdbPtr) -= m * here->omiBSIM4gbd);
                  (*(here->omiBSIM4SPsbPtr +1) += m * xcsbsb);
                  (*(here->omiBSIM4SPsbPtr) -= m * here->omiBSIM4gbs);

                  (*(here->omiBSIM4DBdpPtr +1) += m * xcdbdb);
                  (*(here->omiBSIM4DBdpPtr) -= m * here->omiBSIM4gbd);
                  (*(here->omiBSIM4DBdbPtr +1) -= m * xcdbdb);
                  (*(here->omiBSIM4DBdbPtr) += m * (here->omiBSIM4gbd + here->omiBSIM4grbpd 
                                          + here->omiBSIM4grbdb));
                  (*(here->omiBSIM4DBbpPtr) -= m * here->omiBSIM4grbpd);
                  (*(here->omiBSIM4DBbPtr) -= m * here->omiBSIM4grbdb);

                  (*(here->omiBSIM4BPdbPtr) -= m * here->omiBSIM4grbpd);
                  (*(here->omiBSIM4BPbPtr) -= m * here->omiBSIM4grbpb);
                  (*(here->omiBSIM4BPsbPtr) -= m * here->omiBSIM4grbps);
                  (*(here->omiBSIM4BPbpPtr) += m * (here->omiBSIM4grbpd + here->omiBSIM4grbps 
                                          + here->omiBSIM4grbpb));
                  /* WDLiu: (-here->omiBSIM4gbbs) already added to BPbpPtr */

                  (*(here->omiBSIM4SBspPtr +1) += m * xcsbsb);
                  (*(here->omiBSIM4SBspPtr) -= m * here->omiBSIM4gbs);
                  (*(here->omiBSIM4SBbpPtr) -= m * here->omiBSIM4grbps);
                  (*(here->omiBSIM4SBbPtr) -= m * here->omiBSIM4grbsb);
                  (*(here->omiBSIM4SBsbPtr +1) -= m * xcsbsb);
                  (*(here->omiBSIM4SBsbPtr) += m * (here->omiBSIM4gbs
                                          + here->omiBSIM4grbps + here->omiBSIM4grbsb));

                  (*(here->omiBSIM4BdbPtr) -= m * here->omiBSIM4grbdb);
                  (*(here->omiBSIM4BbpPtr) -= m * here->omiBSIM4grbpb);
                  (*(here->omiBSIM4BsbPtr) -= m * here->omiBSIM4grbsb);
                  (*(here->omiBSIM4BbPtr) += m * (here->omiBSIM4grbsb + here->omiBSIM4grbdb
                                        + here->omiBSIM4grbpb));
              }


           /*
            * WDLiu: The internal charge node generated for transient NQS is not needed for
            *        AC NQS. The following is not doing a real job, but we have to keep it;
            *        otherwise a singular AC NQS matrix may occur if the transient NQS is on.
            *        The charge node is isolated from the instance.
            */
           if (here->omiBSIM4trnqsMod)
           {   (*(here->omiBSIM4QqPtr) += m * 1.0);
               (*(here->omiBSIM4QgpPtr) += 0.0);
               (*(here->omiBSIM4QdpPtr) += 0.0);
               (*(here->omiBSIM4QspPtr) += 0.0);
               (*(here->omiBSIM4QbpPtr) += 0.0);

               (*(here->omiBSIM4DPqPtr) += 0.0);
               (*(here->omiBSIM4SPqPtr) += 0.0);
               (*(here->omiBSIM4GPqPtr) += 0.0);
           }
         }
    }
    return(OK);
}
