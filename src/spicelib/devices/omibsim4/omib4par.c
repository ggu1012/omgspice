/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4par.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 04/06/2001.
 * Modified by Xuemei Xi, 11/15/2002.
 * Modified by Xuemei Xi, 05/09/2003.
 * Modified by Xuemei Xi, Mohan Dunga, 07/29/2005.
**********/

#include "ngspice/ngspice.h"
#include "ngspice/ifsim.h"
#include "omibsim4def.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"
#include "ngspice/fteext.h"

int
omiBSIM4param(
int param,
IFvalue *value,
GENinstance *inst,
IFvalue *select)
{
    double scale;

    omiBSIM4instance *here = (omiBSIM4instance*)inst;

    NG_IGNORE(select);

    if (!cp_getvar("scale", CP_REAL, &scale, 0))
        scale = 1;

    switch (param) {
        case omiBSIM4_W:
            here->omiBSIM4w = value->rValue * scale;
            here->omiBSIM4wGiven = TRUE;
            break;
        case omiBSIM4_L:
            here->omiBSIM4l = value->rValue * scale;
            here->omiBSIM4lGiven = TRUE;
            break;
        case omiBSIM4_M:
            here->omiBSIM4m = value->rValue;
            here->omiBSIM4mGiven = TRUE;
            break;
        case omiBSIM4_NF:
            here->omiBSIM4nf = value->rValue;
            here->omiBSIM4nfGiven = TRUE;
            break;
        case omiBSIM4_MIN:
            here->omiBSIM4min = value->iValue;
            here->omiBSIM4minGiven = TRUE;
            break;
        case omiBSIM4_AS:
            here->omiBSIM4sourceArea = value->rValue * scale * scale;
            here->omiBSIM4sourceAreaGiven = TRUE;
            break;
        case omiBSIM4_AD:
            here->omiBSIM4drainArea = value->rValue * scale * scale;
            here->omiBSIM4drainAreaGiven = TRUE;
            break;
        case omiBSIM4_PS:
            here->omiBSIM4sourcePerimeter = value->rValue * scale;
            here->omiBSIM4sourcePerimeterGiven = TRUE;
            break;
        case omiBSIM4_PD:
            here->omiBSIM4drainPerimeter = value->rValue * scale;
            here->omiBSIM4drainPerimeterGiven = TRUE;
            break;
        case omiBSIM4_NRS:
            here->omiBSIM4sourceSquares = value->rValue;
            here->omiBSIM4sourceSquaresGiven = TRUE;
            break;
        case omiBSIM4_NRD:
            here->omiBSIM4drainSquares = value->rValue;
            here->omiBSIM4drainSquaresGiven = TRUE;
            break;
        case omiBSIM4_OFF:
            here->omiBSIM4off = value->iValue;
            break;
        case omiBSIM4_SA:
            here->omiBSIM4sa = value->rValue;
            here->omiBSIM4saGiven = TRUE;
            break;
        case omiBSIM4_SB:
            here->omiBSIM4sb = value->rValue;
            here->omiBSIM4sbGiven = TRUE;
            break;
        case omiBSIM4_SD:
            here->omiBSIM4sd = value->rValue;
            here->omiBSIM4sdGiven = TRUE;
            break;
        case omiBSIM4_SCA:
            here->omiBSIM4sca = value->rValue;
            here->omiBSIM4scaGiven = TRUE;
            break;
        case omiBSIM4_SCB:
            here->omiBSIM4scb = value->rValue;
            here->omiBSIM4scbGiven = TRUE;
            break;
        case omiBSIM4_SCC:
            here->omiBSIM4scc = value->rValue;
            here->omiBSIM4sccGiven = TRUE;
            break;
        case omiBSIM4_SC:
            here->omiBSIM4sc = value->rValue;
            here->omiBSIM4scGiven = TRUE;
            break;
        case omiBSIM4_RBSB:
            here->omiBSIM4rbsb = value->rValue;
            here->omiBSIM4rbsbGiven = TRUE;
            break;
        case omiBSIM4_RBDB:
            here->omiBSIM4rbdb = value->rValue;
            here->omiBSIM4rbdbGiven = TRUE;
            break;
        case omiBSIM4_RBPB:
            here->omiBSIM4rbpb = value->rValue;
            here->omiBSIM4rbpbGiven = TRUE;
            break;
        case omiBSIM4_RBPS:
            here->omiBSIM4rbps = value->rValue;
            here->omiBSIM4rbpsGiven = TRUE;
            break;
        case omiBSIM4_RBPD:
            here->omiBSIM4rbpd = value->rValue;
            here->omiBSIM4rbpdGiven = TRUE;
            break;
        case omiBSIM4_DELVTO:
            here->omiBSIM4delvto = value->rValue;
            here->omiBSIM4delvtoGiven = TRUE;
            break;
        case omiBSIM4_MULU0:
            here->omiBSIM4mulu0 = value->rValue;
            here->omiBSIM4mulu0Given = TRUE;
            break;
        case omiBSIM4_WNFLAG:
            here->omiBSIM4wnflag = value->iValue;
            here->omiBSIM4wnflagGiven = TRUE;
            break;
        case omiBSIM4_XGW:
            here->omiBSIM4xgw = value->rValue;
            here->omiBSIM4xgwGiven = TRUE;
            break;
        case omiBSIM4_NGCON:
            here->omiBSIM4ngcon = value->rValue;
            here->omiBSIM4ngconGiven = TRUE;
            break;
        case omiBSIM4_TRNQSMOD:
            here->omiBSIM4trnqsMod = value->iValue;
            here->omiBSIM4trnqsModGiven = TRUE;
            break;
        case omiBSIM4_ACNQSMOD:
            here->omiBSIM4acnqsMod = value->iValue;
            here->omiBSIM4acnqsModGiven = TRUE;
            break;
        case omiBSIM4_RBODYMOD:
            here->omiBSIM4rbodyMod = value->iValue;
            here->omiBSIM4rbodyModGiven = TRUE;
            break;
        case omiBSIM4_RGATEMOD:
            here->omiBSIM4rgateMod = value->iValue;
            here->omiBSIM4rgateModGiven = TRUE;
            break;
        case omiBSIM4_GEOMOD:
            here->omiBSIM4geoMod = value->iValue;
            here->omiBSIM4geoModGiven = TRUE;
            break;
        case omiBSIM4_RGEOMOD:
            here->omiBSIM4rgeoMod = value->iValue;
            here->omiBSIM4rgeoModGiven = TRUE;
            break;
        case omiBSIM4_IC_VDS:
            here->omiBSIM4icVDS = value->rValue;
            here->omiBSIM4icVDSGiven = TRUE;
            break;
        case omiBSIM4_IC_VGS:
            here->omiBSIM4icVGS = value->rValue;
            here->omiBSIM4icVGSGiven = TRUE;
            break;
        case omiBSIM4_IC_VBS:
            here->omiBSIM4icVBS = value->rValue;
            here->omiBSIM4icVBSGiven = TRUE;
            break;
        case omiBSIM4_IC:
            /* FALLTHROUGH added to suppress GCC warning due to
             * -Wimplicit-fallthrough flag */
            switch (value->v.numValue) {
                case 3:
                    here->omiBSIM4icVBS = *(value->v.vec.rVec+2);
                    here->omiBSIM4icVBSGiven = TRUE;
                    /* FALLTHROUGH */
                case 2:
                    here->omiBSIM4icVGS = *(value->v.vec.rVec+1);
                    here->omiBSIM4icVGSGiven = TRUE;
                    /* FALLTHROUGH */
                case 1:
                    here->omiBSIM4icVDS = *(value->v.vec.rVec);
                    here->omiBSIM4icVDSGiven = TRUE;
                    break;
                default:
                    return(E_BADPARM);
            }
            break;
        default:
            return(E_BADPARM);
    }
    return(OK);
}
