/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4cvtest.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 04/06/2001.
 * Modified by Xuemei Xi, 10/05/2001.
 * Modified by Xuemei Xi, 05/09/2003.
 **********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "omibsim4def.h"
#include "ngspice/trandefs.h"
#include "ngspice/const.h"
#include "ngspice/devdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"


int
omiBSIM4convTest(
GENmodel *inModel,
CKTcircuit *ckt)
{
omiBSIM4model *model = (omiBSIM4model*)inModel;
omiBSIM4instance *here;
double delvbd, delvbs, delvds, delvgd, delvgs;
double delvdbd, delvsbs; 
double delvbd_jct, delvbs_jct;
double vds, vgs, vgd, vgdo, vbs, vbd;
double vdbd, vdbs, vsbs;
double cbhat, cdhat, Idtot, Ibtot;
double vses, vdes, vdedo, delvses, delvded, delvdes;
double Isestot, cseshat, Idedtot, cdedhat;
double Igstot, cgshat, Igdtot, cgdhat, Igbtot, cgbhat;
double tol0, tol1, tol2, tol3, tol4, tol5, tol6;

    for (; model != NULL; model = omiBSIM4nextModel(model))
    {    for (here = omiBSIM4instances(model); here != NULL ;
              here=omiBSIM4nextInstance(here)) 
         {
              vds = model->omiBSIM4type
                  * (*(ckt->CKTrhsOld + here->omiBSIM4dNodePrime)
                  - *(ckt->CKTrhsOld + here->omiBSIM4sNodePrime));
              vgs = model->omiBSIM4type
                  * (*(ckt->CKTrhsOld + here->omiBSIM4gNodePrime)
                  - *(ckt->CKTrhsOld + here->omiBSIM4sNodePrime));
              vbs = model->omiBSIM4type
                  * (*(ckt->CKTrhsOld + here->omiBSIM4bNodePrime)
                  - *(ckt->CKTrhsOld + here->omiBSIM4sNodePrime));
              vdbs = model->omiBSIM4type
                   * (*(ckt->CKTrhsOld + here->omiBSIM4dbNode)
                   - *(ckt->CKTrhsOld + here->omiBSIM4sNodePrime));
              vsbs = model->omiBSIM4type
                   * (*(ckt->CKTrhsOld + here->omiBSIM4sbNode)
                   - *(ckt->CKTrhsOld + here->omiBSIM4sNodePrime));              
              vses = model->omiBSIM4type
                   * (*(ckt->CKTrhsOld + here->omiBSIM4sNode)
                   - *(ckt->CKTrhsOld + here->omiBSIM4sNodePrime));
              vdes = model->omiBSIM4type
                   * (*(ckt->CKTrhsOld + here->omiBSIM4dNode)
                   - *(ckt->CKTrhsOld + here->omiBSIM4sNodePrime));
              
              vgdo = *(ckt->CKTstate0 + here->omiBSIM4vgs)
                    - *(ckt->CKTstate0 + here->omiBSIM4vds);
              vbd = vbs - vds;
              vdbd = vdbs - vds;
              vgd = vgs - vds;

              delvbd = vbd - *(ckt->CKTstate0 + here->omiBSIM4vbd);
              delvdbd = vdbd - *(ckt->CKTstate0 + here->omiBSIM4vdbd);
              delvgd = vgd - vgdo;

              delvds = vds - *(ckt->CKTstate0 + here->omiBSIM4vds);
              delvgs = vgs - *(ckt->CKTstate0 + here->omiBSIM4vgs);
              delvbs = vbs - *(ckt->CKTstate0 + here->omiBSIM4vbs);
              delvsbs = vsbs - *(ckt->CKTstate0 + here->omiBSIM4vsbs);

              delvses = vses - (*(ckt->CKTstate0 + here->omiBSIM4vses));
              vdedo = *(ckt->CKTstate0 + here->omiBSIM4vdes)
                    - *(ckt->CKTstate0 + here->omiBSIM4vds);
              delvdes = vdes - *(ckt->CKTstate0 + here->omiBSIM4vdes);
              delvded = vdes - vds - vdedo;

              delvbd_jct = (!here->omiBSIM4rbodyMod) ? delvbd : delvdbd;
              delvbs_jct = (!here->omiBSIM4rbodyMod) ? delvbs : delvsbs;

              if (here->omiBSIM4mode >= 0)
              {   Idtot = here->omiBSIM4cd + here->omiBSIM4csub - here->omiBSIM4cbd
                        + here->omiBSIM4Igidl;
                  cdhat = Idtot - here->omiBSIM4gbd * delvbd_jct
                        + (here->omiBSIM4gmbs + here->omiBSIM4gbbs + here->omiBSIM4ggidlb) * delvbs
                        + (here->omiBSIM4gm + here->omiBSIM4gbgs + here->omiBSIM4ggidlg) * delvgs
                        + (here->omiBSIM4gds + here->omiBSIM4gbds + here->omiBSIM4ggidld) * delvds;

                  Igstot = here->omiBSIM4Igs + here->omiBSIM4Igcs;
                  cgshat = Igstot + (here->omiBSIM4gIgsg + here->omiBSIM4gIgcsg) * delvgs
                         + here->omiBSIM4gIgcsd * delvds + here->omiBSIM4gIgcsb * delvbs;

                  Igdtot = here->omiBSIM4Igd + here->omiBSIM4Igcd;
                  cgdhat = Igdtot + here->omiBSIM4gIgdg * delvgd + here->omiBSIM4gIgcdg * delvgs
                         + here->omiBSIM4gIgcdd * delvds + here->omiBSIM4gIgcdb * delvbs;

                  Igbtot = here->omiBSIM4Igb;
                  cgbhat = here->omiBSIM4Igb + here->omiBSIM4gIgbg * delvgs + here->omiBSIM4gIgbd
                         * delvds + here->omiBSIM4gIgbb * delvbs;
              }
              else
               {   Idtot = here->omiBSIM4cd + here->omiBSIM4cbd - here->omiBSIM4Igidl; /* bugfix */
                   cdhat = Idtot + here->omiBSIM4gbd * delvbd_jct + here->omiBSIM4gmbs 
                         * delvbd + here->omiBSIM4gm * delvgd 
                         - (here->omiBSIM4gds + here->omiBSIM4ggidls) * delvds 
                         - here->omiBSIM4ggidlg * delvgs - here->omiBSIM4ggidlb * delvbs;

                  Igstot = here->omiBSIM4Igs + here->omiBSIM4Igcd;
                  cgshat = Igstot + here->omiBSIM4gIgsg * delvgs + here->omiBSIM4gIgcdg * delvgd
                         - here->omiBSIM4gIgcdd * delvds + here->omiBSIM4gIgcdb * delvbd;

                  Igdtot = here->omiBSIM4Igd + here->omiBSIM4Igcs;
                  cgdhat = Igdtot + (here->omiBSIM4gIgdg + here->omiBSIM4gIgcsg) * delvgd
                         - here->omiBSIM4gIgcsd * delvds + here->omiBSIM4gIgcsb * delvbd;

                  Igbtot = here->omiBSIM4Igb;
                  cgbhat = here->omiBSIM4Igb + here->omiBSIM4gIgbg * delvgd - here->omiBSIM4gIgbd
                         * delvds + here->omiBSIM4gIgbb * delvbd;
              }

              Isestot = here->omiBSIM4gstot * (*(ckt->CKTstate0 + here->omiBSIM4vses));
              cseshat = Isestot + here->omiBSIM4gstot * delvses
                      + here->omiBSIM4gstotd * delvds + here->omiBSIM4gstotg * delvgs
                      + here->omiBSIM4gstotb * delvbs;

              Idedtot = here->omiBSIM4gdtot * vdedo;
              cdedhat = Idedtot + here->omiBSIM4gdtot * delvded
                      + here->omiBSIM4gdtotd * delvds + here->omiBSIM4gdtotg * delvgs
                      + here->omiBSIM4gdtotb * delvbs;

              /*
               *  Check convergence
               */

              if ((here->omiBSIM4off == 0)  || (!(ckt->CKTmode & MODEINITFIX)))
              {   tol0 = ckt->CKTreltol * MAX(fabs(cdhat), fabs(Idtot))
                       + ckt->CKTabstol;
                  tol1 = ckt->CKTreltol * MAX(fabs(cseshat), fabs(Isestot))
                       + ckt->CKTabstol;
                  tol2 = ckt->CKTreltol * MAX(fabs(cdedhat), fabs(Idedtot))
                       + ckt->CKTabstol;
                  tol3 = ckt->CKTreltol * MAX(fabs(cgshat), fabs(Igstot))
                       + ckt->CKTabstol;
                  tol4 = ckt->CKTreltol * MAX(fabs(cgdhat), fabs(Igdtot))
                       + ckt->CKTabstol;
                  tol5 = ckt->CKTreltol * MAX(fabs(cgbhat), fabs(Igbtot))
                       + ckt->CKTabstol;

                  if ((fabs(cdhat - Idtot) >= tol0) || (fabs(cseshat - Isestot) >= tol1)
                      || (fabs(cdedhat - Idedtot) >= tol2))
                  {   ckt->CKTnoncon++;
                      return(OK);
                  } 

                  if ((fabs(cgshat - Igstot) >= tol3) || (fabs(cgdhat - Igdtot) >= tol4)
                      || (fabs(cgbhat - Igbtot) >= tol5))
                  {   ckt->CKTnoncon++;
                      return(OK);
                  }

                  Ibtot = here->omiBSIM4cbs + here->omiBSIM4cbd
                        - here->omiBSIM4Igidl - here->omiBSIM4Igisl - here->omiBSIM4csub;
                  if (here->omiBSIM4mode >= 0)
                  {   cbhat = Ibtot + here->omiBSIM4gbd * delvbd_jct
                            + here->omiBSIM4gbs * delvbs_jct - (here->omiBSIM4gbbs + here->omiBSIM4ggidlb)
                            * delvbs - (here->omiBSIM4gbgs + here->omiBSIM4ggidlg) * delvgs
                            - (here->omiBSIM4gbds + here->omiBSIM4ggidld) * delvds
                            - here->omiBSIM4ggislg * delvgd - here->omiBSIM4ggislb* delvbd + here->omiBSIM4ggisls * delvds ;
                  }
                  else
                  {   cbhat = Ibtot + here->omiBSIM4gbs * delvbs_jct + here->omiBSIM4gbd 
                         * delvbd_jct - (here->omiBSIM4gbbs + here->omiBSIM4ggislb) * delvbd
                         - (here->omiBSIM4gbgs + here->omiBSIM4ggislg) * delvgd
                         + (here->omiBSIM4gbds + here->omiBSIM4ggisld - here->omiBSIM4ggidls) * delvds
                         - here->omiBSIM4ggidlg * delvgs - here->omiBSIM4ggidlb * delvbs; 
                  }
                  tol6 = ckt->CKTreltol * MAX(fabs(cbhat), 
                        fabs(Ibtot)) + ckt->CKTabstol;
                  if (fabs(cbhat - Ibtot) > tol6) 
                  {   ckt->CKTnoncon++;
                      return(OK);
                  }
              }
         }
    }
    return(OK);
}
