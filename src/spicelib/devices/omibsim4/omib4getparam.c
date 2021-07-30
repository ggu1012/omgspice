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

#include "ngspice/fteext.h"
#include "ngspice/ifsim.h"
#include "ngspice/ngspice.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"
#include "omibsim4def.h"

double omiBSIM4GetParam(GENinstance *inp, int id)
{
    omiBSIM4instance *here = (omiBSIM4instance *)inp;

    switch (id)
    {
    case omiBSIM4_W:
        return (here->omiBSIM4wGiven ? here->omiBSIM4w : 1e199);
        break;
    case omiBSIM4_L:
        return (here->omiBSIM4lGiven ? here->omiBSIM4l : 1e199);
        break;
    case omiBSIM4_M:
        return (here->omiBSIM4mGiven ? here->omiBSIM4m : 1e199);
        break;
    case omiBSIM4_NF:
        return (here->omiBSIM4nfGiven ? here->omiBSIM4nf : 1e199);
        break;
    case omiBSIM4_MIN:
        return (here->omiBSIM4minGiven ? (double)here->omiBSIM4min : 1e199);
        break;
    case omiBSIM4_AS:
        return (here->omiBSIM4sourceAreaGiven ? here->omiBSIM4sourceArea
                                              : 1e199);
        break;
    case omiBSIM4_AD:
        return (here->omiBSIM4drainAreaGiven ? here->omiBSIM4drainArea
                                             : 1e199);
        break;
    case omiBSIM4_PS:
        return (here->omiBSIM4sourcePerimeterGiven ? here->omiBSIM4sourcePerimeter
                                                   : 1e199);
        break;
    case omiBSIM4_PD:
        return (here->omiBSIM4drainPerimeterGiven ? here->omiBSIM4drainPerimeter
                                                  : 1e199);
        break;
    case omiBSIM4_NRS:
        return (here->omiBSIM4sourceSquaresGiven ? here->omiBSIM4sourceSquares
                                                 : 1e199);
        break;
    case omiBSIM4_NRD:
        return (here->omiBSIM4drainSquaresGiven ? here->omiBSIM4drainSquares
                                                : 1e199);
        break;
    case omiBSIM4_OFF:
        return (double)here->omiBSIM4off;
        break;
    case omiBSIM4_SA:
        return (here->omiBSIM4saGiven ? here->omiBSIM4sa : 1e199);
        break;
    case omiBSIM4_SB:
        return (here->omiBSIM4sbGiven ? here->omiBSIM4sb : 1e199);
        break;
    case omiBSIM4_SD:
        return (here->omiBSIM4sdGiven ? here->omiBSIM4sd : 1e199);
        break;
    case omiBSIM4_SCA:
        return (here->omiBSIM4scaGiven ? here->omiBSIM4sca : 1e199);
        break;
    case omiBSIM4_SCB:
        return (here->omiBSIM4scbGiven ? here->omiBSIM4scb : 1e199);
        break;
    case omiBSIM4_SCC:
        return (here->omiBSIM4sccGiven ? here->omiBSIM4scc : 1e199);
        break;
    case omiBSIM4_SC:
        return (here->omiBSIM4scGiven ? here->omiBSIM4sc : 1e199);
        break;
    case omiBSIM4_RBSB:
        return (here->omiBSIM4rbsbGiven ? here->omiBSIM4rbsb : 1e199);
        break;
    case omiBSIM4_RBDB:
        return (here->omiBSIM4rbdbGiven ? here->omiBSIM4rbdb : 1e199);
        break;
    case omiBSIM4_RBPB:
        return (here->omiBSIM4rbpbGiven ? here->omiBSIM4rbpb : 1e199);
        break;
    case omiBSIM4_RBPS:
        return (here->omiBSIM4rbpsGiven ? here->omiBSIM4rbps : 1e199);
        break;
    case omiBSIM4_RBPD:
        return (here->omiBSIM4rbpdGiven ? here->omiBSIM4rbpd : 1e199);
        break;
    case omiBSIM4_DELVTO:
        return (here->omiBSIM4delvtoGiven ? here->omiBSIM4delvto : 1e199);
        break;
    case omiBSIM4_MULU0:
        return (here->omiBSIM4mulu0Given ? here->omiBSIM4mulu0 : 1e199);
        break;
    case omiBSIM4_WNFLAG:
        return (here->omiBSIM4wnflagGiven ? (double)here->omiBSIM4wnflag
                                          : 1e199);
        break;
    case omiBSIM4_XGW:
        return (here->omiBSIM4xgwGiven ? here->omiBSIM4xgw : 1e199);
        break;
    case omiBSIM4_NGCON:
        return (here->omiBSIM4ngconGiven ? here->omiBSIM4ngcon : 1e199);
        break;
    case omiBSIM4_TRNQSMOD:
        return (here->omiBSIM4trnqsModGiven ? (double)here->omiBSIM4trnqsMod
                                            : 1e199);
        break;
    case omiBSIM4_ACNQSMOD:
        return (here->omiBSIM4acnqsModGiven ? (double)here->omiBSIM4acnqsMod
                                            : 1e199);
        break;
    case omiBSIM4_RBODYMOD:
        return (here->omiBSIM4rbodyModGiven ? (double)here->omiBSIM4rbodyMod
                                            : 1e199);
        break;
    case omiBSIM4_RGATEMOD:
        return (here->omiBSIM4rgateModGiven ? (double)here->omiBSIM4rgateMod
                                            : 1e199);
        break;
    case omiBSIM4_GEOMOD:
        return (here->omiBSIM4geoModGiven ? (double)here->omiBSIM4geoMod
                                          : 1e199);
        break;
    case omiBSIM4_RGEOMOD:
        return (here->omiBSIM4rgeoModGiven ? (double)here->omiBSIM4rgeoMod
                                           : 1e199);

    default:
        return 1e199;
    }
}
