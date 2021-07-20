/**********
Copyright 2013 Dietmar Warning. All rights reserved.
Author:   2013 Dietmar Warning
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "omibsim4def.h"
#include "ngspice/trandefs.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"
#include "ngspice/cpdefs.h"


int
omiBSIM4soaCheck(CKTcircuit *ckt, GENmodel *inModel)
{
    omiBSIM4model *model = (omiBSIM4model *) inModel;
    omiBSIM4instance *here;
    double vgs, vgd, vgb, vds, vbs, vbd;    /* actual mos voltages */
    int maxwarns;
    static int warns_vgs = 0, warns_vgd = 0, warns_vgb = 0, warns_vds = 0, warns_vbs = 0, warns_vbd = 0;

    if (!ckt) {
        warns_vgs = 0;
        warns_vgd = 0;
        warns_vgb = 0;
        warns_vds = 0;
        warns_vbs = 0;
        warns_vbd = 0;
        return OK;
    }

    maxwarns = ckt->CKTsoaMaxWarns;

    for (; model; model = omiBSIM4nextModel(model)) {

        for (here = omiBSIM4instances(model); here; here = omiBSIM4nextInstance(here)) {

            vgs = ckt->CKTrhsOld [here->omiBSIM4gNodePrime] -
                  ckt->CKTrhsOld [here->omiBSIM4sNodePrime];

            vgd = ckt->CKTrhsOld [here->omiBSIM4gNodePrime] -
                  ckt->CKTrhsOld [here->omiBSIM4dNodePrime];

            vgb = ckt->CKTrhsOld [here->omiBSIM4gNodePrime] -
                  ckt->CKTrhsOld [here->omiBSIM4bNodePrime];

            vds = ckt->CKTrhsOld [here->omiBSIM4dNodePrime] -
                  ckt->CKTrhsOld [here->omiBSIM4sNodePrime];

            vbs = ckt->CKTrhsOld [here->omiBSIM4bNodePrime] -
                  ckt->CKTrhsOld [here->omiBSIM4sNodePrime];

            vbd = ckt->CKTrhsOld [here->omiBSIM4bNodePrime] -
                  ckt->CKTrhsOld [here->omiBSIM4dNodePrime];

            if (!model->omiBSIM4vgsrMaxGiven) {
                if (fabs(vgs) > model->omiBSIM4vgsMax)
                    if (warns_vgs < maxwarns) {
                        soa_printf(ckt, (GENinstance*) here,
                                   "Vgs=%g has exceeded Vgs_max=%g\n",
                                   vgs, model->omiBSIM4vgsMax);
                        warns_vgs++;
                    }
                if (!model->omiBSIM4vgbMaxGiven) {
                    if (fabs(vgb) > model->omiBSIM4vgsMax)
                        if (warns_vgb < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgb=%g has exceeded Vgs_max=%g\n",
                                       vgb, model->omiBSIM4vgsMax);
                            warns_vgb++;
                        }
                } else {
                    if (fabs(vgb) > model->omiBSIM4vgbMax)
                        if (warns_vgb < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgb=%g has exceeded Vgb_max=%g\n",
                                       vgb, model->omiBSIM4vgbMax);
                            warns_vgb++;
                        }
                }
            } else {
                if (model->omiBSIM4type > 0) {
                    if (vgs > model->omiBSIM4vgsMax)
                        if (warns_vgs < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgs=%g has exceeded Vgs_max=%g\n",
                                       vgs, model->omiBSIM4vgsMax);
                            warns_vgs++;
                        }
                    if (-1*vgs > model->omiBSIM4vgsrMax)
                        if (warns_vgs < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgs=%g has exceeded Vgsr_max=%g\n",
                                       vgs, model->omiBSIM4vgsrMax);
                            warns_vgs++;
                        }
                } else {
                    if (vgs > model->omiBSIM4vgsrMax)
                        if (warns_vgs < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgs=%g has exceeded Vgsr_max=%g\n",
                                       vgs, model->omiBSIM4vgsrMax);
                            warns_vgs++;
                        }
                    if (-1*vgs > model->omiBSIM4vgsMax)
                        if (warns_vgs < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgs=%g has exceeded Vgs_max=%g\n",
                                       vgs, model->omiBSIM4vgsMax);
                            warns_vgs++;
                        }
                }
            }

            if (!model->omiBSIM4vgdrMaxGiven) {
                if (fabs(vgd) > model->omiBSIM4vgdMax)
                    if (warns_vgd < maxwarns) {
                        soa_printf(ckt, (GENinstance*) here,
                                   "Vgd=%g has exceeded Vgd_max=%g\n",
                                   vgd, model->omiBSIM4vgdMax);
                        warns_vgd++;
                    }
            } else {
                if (model->omiBSIM4type > 0) {
                    if (vgd > model->omiBSIM4vgdMax)
                        if (warns_vgd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgd=%g has exceeded Vgd_max=%g\n",
                                       vgd, model->omiBSIM4vgdMax);
                            warns_vgd++;
                        }
                    if (-1*vgd > model->omiBSIM4vgdrMax)
                        if (warns_vgd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgd=%g has exceeded Vgdr_max=%g\n",
                                       vgd, model->omiBSIM4vgdrMax);
                            warns_vgd++;
                        }
                } else {
                    if (vgd > model->omiBSIM4vgdrMax)
                        if (warns_vgd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgd=%g has exceeded Vgdr_max=%g\n",
                                       vgd, model->omiBSIM4vgdrMax);
                            warns_vgd++;
                        }
                    if (-1*vgd > model->omiBSIM4vgdMax)
                        if (warns_vgd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgd=%g has exceeded Vgd_max=%g\n",
                                       vgd, model->omiBSIM4vgdMax);
                            warns_vgd++;
                        }
                }
            }

            if (fabs(vds) > model->omiBSIM4vdsMax)
                if (warns_vds < maxwarns) {
                    soa_printf(ckt, (GENinstance*) here,
                               "Vds=%g has exceeded Vds_max=%g\n",
                               vds, model->omiBSIM4vdsMax);
                    warns_vds++;
                }

            if (!model->omiBSIM4vgbrMaxGiven) {
                if (fabs(vgb) > model->omiBSIM4vgbMax)
                    if (warns_vgb < maxwarns) {
                        soa_printf(ckt, (GENinstance*) here,
                                   "Vgb=%g has exceeded Vgb_max=%g\n",
                                   vgb, model->omiBSIM4vgbMax);
                        warns_vgb++;
                    }
            } else {
                if (model->omiBSIM4type > 0) {
                    if (vgb > model->omiBSIM4vgbMax)
                        if (warns_vgb < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgb=%g has exceeded Vgb_max=%g\n",
                                       vgb, model->omiBSIM4vgbMax);
                            warns_vgb++;
                        }
                    if (-1*vgb > model->omiBSIM4vgbrMax)
                        if (warns_vgb < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgb=%g has exceeded Vgbr_max=%g\n",
                                       vgb, model->omiBSIM4vgbrMax);
                            warns_vgb++;
                        }
                } else {
                    if (vgb > model->omiBSIM4vgbrMax)
                        if (warns_vgb < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgb=%g has exceeded Vgbr_max=%g\n",
                                       vgb, model->omiBSIM4vgbrMax);
                            warns_vgb++;
                        }
                    if (-1*vgb > model->omiBSIM4vgbMax)
                        if (warns_vgb < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vgb=%g has exceeded Vgb_max=%g\n",
                                       vgb, model->omiBSIM4vgbMax);
                            warns_vgb++;
                        }
                }
            }

            if (!model->omiBSIM4vbsrMaxGiven) {
                if (!model->omiBSIM4vbsMaxGiven) {
                    if (fabs(vbs) > model->omiBSIM4vbdMax)
                        if (warns_vbs < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vbs=%g has exceeded Vbd_max=%g\n",
                                       vbs, model->omiBSIM4vbdMax);
                            warns_vbs++;
                        }
                } else {
                    if (fabs(vbs) > model->omiBSIM4vbsMax)
                        if (warns_vbs < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vbs=%g has exceeded Vbs_max=%g\n",
                                       vbs, model->omiBSIM4vbsMax);
                            warns_vbs++;
                        }
                }
            } else {
                if (!model->omiBSIM4vbsMaxGiven) {
                    if (model->omiBSIM4type > 0) {
                        if (vbs > model->omiBSIM4vbdMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbd_max=%g\n",
                                           vbs, model->omiBSIM4vbdMax);
                                warns_vbs++;
                            }
                        if (-1*vbs > model->omiBSIM4vbsrMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbsr_max=%g\n",
                                           vbs, model->omiBSIM4vbsrMax);
                                warns_vbs++;
                            }
                    } else {
                        if (vbs > model->omiBSIM4vbsrMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbsr_max=%g\n",
                                           vbs, model->omiBSIM4vbsrMax);
                                warns_vbs++;
                            }
                        if (-1*vbs > model->omiBSIM4vbdMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbd_max=%g\n",
                                           vbs, model->omiBSIM4vbdMax);
                                warns_vbs++;
                            }
                    }
                } else {
                    if (model->omiBSIM4type > 0) {
                        if (vbs > model->omiBSIM4vbsMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbs_max=%g\n",
                                           vbs, model->omiBSIM4vbsMax);
                                warns_vbs++;
                            }
                        if (-1*vbs > model->omiBSIM4vbsrMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbsr_max=%g\n",
                                           vbs, model->omiBSIM4vbsrMax);
                                warns_vbs++;
                            }
                    } else {
                        if (vbs > model->omiBSIM4vbsrMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbsr_max=%g\n",
                                           vbs, model->omiBSIM4vbsrMax);
                                warns_vbs++;
                            }
                        if (-1*vbs > model->omiBSIM4vbsMax)
                            if (warns_vbs < maxwarns) {
                                soa_printf(ckt, (GENinstance*) here,
                                           "Vbs=%g has exceeded Vbs_max=%g\n",
                                           vbs, model->omiBSIM4vbsMax);
                                warns_vbs++;
                            }
                    }
                }
            }

            if (!model->omiBSIM4vbdrMaxGiven) {
                if (fabs(vbd) > model->omiBSIM4vbdMax)
                    if (warns_vbd < maxwarns) {
                        soa_printf(ckt, (GENinstance*) here,
                                   "Vbd=%g has exceeded Vbd_max=%g\n",
                                   vbd, model->omiBSIM4vbdMax);
                        warns_vbd++;
                    }
            } else {
                if (model->omiBSIM4type > 0) {
                    if (vbd > model->omiBSIM4vbdMax)
                        if (warns_vbd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vbd=%g has exceeded Vbd_max=%g\n",
                                       vbd, model->omiBSIM4vbdMax);
                            warns_vbd++;
                        }
                    if (-1*vbd > model->omiBSIM4vbdrMax)
                        if (warns_vbd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vbd=%g has exceeded Vbdr_max=%g\n",
                                       vbd, model->omiBSIM4vbdrMax);
                            warns_vbd++;
                        }
                } else {
                    if (vbd > model->omiBSIM4vbdrMax)
                        if (warns_vbd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vbd=%g has exceeded Vbdr_max=%g\n",
                                       vbd, model->omiBSIM4vbdrMax);
                            warns_vbd++;
                        }
                    if (-1*vbd > model->omiBSIM4vbdMax)
                        if (warns_vbd < maxwarns) {
                            soa_printf(ckt, (GENinstance*) here,
                                       "Vbd=%g has exceeded Vbd_max=%g\n",
                                       vbd, model->omiBSIM4vbdMax);
                            warns_vbd++;
                        }
                }
            }

        }
    }

    return OK;
}
