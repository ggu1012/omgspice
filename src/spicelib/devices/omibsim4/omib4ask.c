/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4ask.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 04/06/2001.
 * Modified by Xuemei Xi, 10/05/2001.
 * Modified by Xuemei Xi, 05/09/2003.
 * Modified by Xuemei Xi, Mohan Dunga, 07/29/2005.
 **********/

#include "ngspice/ngspice.h"
#include "ngspice/ifsim.h"
#include "ngspice/cktdefs.h"
#include "ngspice/devdefs.h"
#include "omibsim4def.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"

int
omiBSIM4ask(
CKTcircuit *ckt,
GENinstance *inst,
int which,
IFvalue *value,
IFvalue *select)
{
omiBSIM4instance *here = (omiBSIM4instance*)inst;

    NG_IGNORE(select);

    switch(which) 
    {   case omiBSIM4_L:
            value->rValue = here->omiBSIM4l;
            return(OK);
        case omiBSIM4_W:
            value->rValue = here->omiBSIM4w;
            return(OK);
        case omiBSIM4_M:
            value->rValue = here->omiBSIM4m;
            return(OK);
        case omiBSIM4_NF:
            value->rValue = here->omiBSIM4nf;
            return(OK);
        case omiBSIM4_MIN:
            value->iValue = here->omiBSIM4min;
            return(OK);
        case omiBSIM4_AS:
            value->rValue = here->omiBSIM4sourceArea;
            return(OK);
        case omiBSIM4_AD:
            value->rValue = here->omiBSIM4drainArea;
            return(OK);
        case omiBSIM4_PS:
            value->rValue = here->omiBSIM4sourcePerimeter;
            return(OK);
        case omiBSIM4_PD:
            value->rValue = here->omiBSIM4drainPerimeter;
            return(OK);
        case omiBSIM4_NRS:
            value->rValue = here->omiBSIM4sourceSquares;
            return(OK);
        case omiBSIM4_NRD:
            value->rValue = here->omiBSIM4drainSquares;
            return(OK);
        case omiBSIM4_OFF:
            value->rValue = here->omiBSIM4off;
            return(OK);
        case omiBSIM4_SA:
            value->rValue = here->omiBSIM4sa ;
            return(OK);
        case omiBSIM4_SB:
            value->rValue = here->omiBSIM4sb ;
            return(OK);
        case omiBSIM4_SD:
            value->rValue = here->omiBSIM4sd ;
            return(OK);
        case omiBSIM4_SCA:
            value->rValue = here->omiBSIM4sca ;
            return(OK);
        case omiBSIM4_SCB:
            value->rValue = here->omiBSIM4scb ;
            return(OK);
        case omiBSIM4_SCC:
            value->rValue = here->omiBSIM4scc ;
            return(OK);
        case omiBSIM4_SC:
            value->rValue = here->omiBSIM4sc ;
            return(OK);

        case omiBSIM4_RBSB:
            value->rValue = here->omiBSIM4rbsb;
            return(OK);
        case omiBSIM4_RBDB:
            value->rValue = here->omiBSIM4rbdb;
            return(OK);
        case omiBSIM4_RBPB:
            value->rValue = here->omiBSIM4rbpb;
            return(OK);
        case omiBSIM4_RBPS:
            value->rValue = here->omiBSIM4rbps;
            return(OK);
        case omiBSIM4_RBPD:
            value->rValue = here->omiBSIM4rbpd;
            return(OK);
        case omiBSIM4_DELVTO:
            value->rValue = here->omiBSIM4delvto;
            return(OK);
        case omiBSIM4_MULU0:
            value->rValue = here->omiBSIM4mulu0;
            return(OK);
        case omiBSIM4_WNFLAG:
            value->iValue = here->omiBSIM4wnflag;
            return(OK);
        case omiBSIM4_XGW:
            value->rValue = here->omiBSIM4xgw;
            return(OK);
        case omiBSIM4_NGCON:
            value->rValue = here->omiBSIM4ngcon;
            return(OK);
        case omiBSIM4_TRNQSMOD:
            value->iValue = here->omiBSIM4trnqsMod;
            return(OK);
        case omiBSIM4_ACNQSMOD:
            value->iValue = here->omiBSIM4acnqsMod;
            return(OK);
        case omiBSIM4_RBODYMOD:
            value->iValue = here->omiBSIM4rbodyMod;
            return(OK);
        case omiBSIM4_RGATEMOD:
            value->iValue = here->omiBSIM4rgateMod;
            return(OK);
        case omiBSIM4_GEOMOD:
            value->iValue = here->omiBSIM4geoMod;
            return(OK);
        case omiBSIM4_RGEOMOD:
            value->iValue = here->omiBSIM4rgeoMod;
            return(OK);
        case omiBSIM4_IC_VDS:
            value->rValue = here->omiBSIM4icVDS;
            return(OK);
        case omiBSIM4_IC_VGS:
            value->rValue = here->omiBSIM4icVGS;
            return(OK);
        case omiBSIM4_IC_VBS:
            value->rValue = here->omiBSIM4icVBS;
            return(OK);
        case omiBSIM4_DNODE:
            value->iValue = here->omiBSIM4dNode;
            return(OK);
        case omiBSIM4_GNODEEXT:
            value->iValue = here->omiBSIM4gNodeExt;
            return(OK);
        case omiBSIM4_SNODE:
            value->iValue = here->omiBSIM4sNode;
            return(OK);
        case omiBSIM4_BNODE:
            value->iValue = here->omiBSIM4bNode;
            return(OK);
        case omiBSIM4_DNODEPRIME:
            value->iValue = here->omiBSIM4dNodePrime;
            return(OK);
        case omiBSIM4_GNODEPRIME:
            value->iValue = here->omiBSIM4gNodePrime;
            return(OK);
        case omiBSIM4_GNODEMID:
            value->iValue = here->omiBSIM4gNodeMid;
            return(OK);
        case omiBSIM4_SNODEPRIME:
            value->iValue = here->omiBSIM4sNodePrime;
            return(OK);
        case omiBSIM4_DBNODE:
            value->iValue = here->omiBSIM4dbNode;
            return(OK);
        case omiBSIM4_BNODEPRIME:
            value->iValue = here->omiBSIM4bNodePrime;
            return(OK);
        case omiBSIM4_SBNODE:
            value->iValue = here->omiBSIM4sbNode;
            return(OK);
        case omiBSIM4_SOURCECONDUCT:
            value->rValue = here->omiBSIM4sourceConductance;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_DRAINCONDUCT:
            value->rValue = here->omiBSIM4drainConductance;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_VBD:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4vbd);
            return(OK);
        case omiBSIM4_VBS:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4vbs);
            return(OK);
        case omiBSIM4_VGS:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4vgs);
            return(OK);
        case omiBSIM4_VDS:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4vds);
            return(OK);
        case omiBSIM4_CD:
            value->rValue = here->omiBSIM4cd; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CBS:
            value->rValue = here->omiBSIM4cbs; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CBD:
            value->rValue = here->omiBSIM4cbd; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CSUB:
            value->rValue = here->omiBSIM4csub; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_QINV:
            value->rValue = here-> omiBSIM4qinv; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_IGIDL:
            value->rValue = here->omiBSIM4Igidl; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_IGISL:
            value->rValue = here->omiBSIM4Igisl; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_IGS:
            value->rValue = here->omiBSIM4Igs; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_IGD:
            value->rValue = here->omiBSIM4Igd; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_IGB:
            value->rValue = here->omiBSIM4Igb; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_IGCS:
            value->rValue = here->omiBSIM4Igcs; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_IGCD:
            value->rValue = here->omiBSIM4Igcd; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_GM:
            value->rValue = here->omiBSIM4gm; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_GDS:
            value->rValue = here->omiBSIM4gds; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_GMBS:
            value->rValue = here->omiBSIM4gmbs; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_GBD:
            value->rValue = here->omiBSIM4gbd; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_GBS:
            value->rValue = here->omiBSIM4gbs; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
/*        case omiBSIM4_QB:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4qb); 
            return(OK); */
        case omiBSIM4_CQB:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4cqb); 
            return(OK);
/*        case omiBSIM4_QG:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4qg); 
            return(OK); */
        case omiBSIM4_CQG:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4cqg); 
            return(OK);
/*        case omiBSIM4_QD:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4qd); 
            return(OK); */
        case omiBSIM4_CQD:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4cqd); 
            return(OK);
/*        case omiBSIM4_QS:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4qs); 
            return(OK); */
        case omiBSIM4_QB:
            value->rValue = here->omiBSIM4qbulk; 
            value->rValue *= here->omiBSIM4m;
            return(OK); 
        case omiBSIM4_QG:
            value->rValue = here->omiBSIM4qgate; 
            value->rValue *= here->omiBSIM4m;
            return(OK); 
        case omiBSIM4_QS:
            value->rValue = here->omiBSIM4qsrc; 
            value->rValue *= here->omiBSIM4m;
            return(OK); 
        case omiBSIM4_QD:
            value->rValue = here->omiBSIM4qdrn; 
            value->rValue *= here->omiBSIM4m;
            return(OK); 
        case omiBSIM4_QDEF:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4qdef); 
            return(OK); 
        case omiBSIM4_GCRG:
            value->rValue = here->omiBSIM4gcrg;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_GTAU:
            value->rValue = here->omiBSIM4gtau;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CGGB:
            value->rValue = here->omiBSIM4cggb; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CGDB:
            value->rValue = here->omiBSIM4cgdb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CGSB:
            value->rValue = here->omiBSIM4cgsb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CDGB:
            value->rValue = here->omiBSIM4cdgb; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CDDB:
            value->rValue = here->omiBSIM4cddb; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CDSB:
            value->rValue = here->omiBSIM4cdsb; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CBGB:
            value->rValue = here->omiBSIM4cbgb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CBDB:
            value->rValue = here->omiBSIM4cbdb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CBSB:
            value->rValue = here->omiBSIM4cbsb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CSGB:
            value->rValue = here->omiBSIM4csgb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CSDB:
            value->rValue = here->omiBSIM4csdb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CSSB:
            value->rValue = here->omiBSIM4cssb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CGBB:
            value->rValue = here->omiBSIM4cgbb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CDBB:
            value->rValue = here->omiBSIM4cdbb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CSBB:
            value->rValue = here->omiBSIM4csbb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CBBB:
            value->rValue = here->omiBSIM4cbbb;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CAPBD:
            value->rValue = here->omiBSIM4capbd; 
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_CAPBS:
            value->rValue = here->omiBSIM4capbs;
            value->rValue *= here->omiBSIM4m;
            return(OK);
        case omiBSIM4_VON:
            value->rValue = here->omiBSIM4von; 
            return(OK);
        case omiBSIM4_VDSAT:
            value->rValue = here->omiBSIM4vdsat; 
            return(OK);
        case omiBSIM4_QBS:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4qbs); 
            return(OK);
        case omiBSIM4_QBD:
            value->rValue = *(ckt->CKTstate0 + here->omiBSIM4qbd); 
            return(OK);
        default:
            return(E_BADPARM);
    }
    /* NOTREACHED */
}

