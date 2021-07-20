/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4mask.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 * Modified by Xuemei Xi, 04/06/2001.
 * Modified by Xuemei Xi, 10/05/2001.
 * Modified by Xuemei Xi, 11/15/2002.
 * Modified by Xuemei Xi, 05/09/2003.
 * Modified by Xuemei Xi, Mohan Dunga, 07/29/2005.
 * Modified by Mohan Dunga, 12/13/2006
 * Modified by Mohan Dunga, Wenwei Yang, 07/31/2008.
 * Modified by Tanvir Morshed, Darsen Lu 03/27/2011
 **********/


#include "ngspice/ngspice.h"
#include "ngspice/ifsim.h"
#include "ngspice/cktdefs.h"
#include "ngspice/devdefs.h"
#include "omibsim4def.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"

int
omiBSIM4mAsk(
CKTcircuit *ckt,
GENmodel *inst,
int which,
IFvalue *value)
{
    omiBSIM4model *model = (omiBSIM4model *)inst;

    NG_IGNORE(ckt);

    switch(which) 
    {   case omiBSIM4_MOD_MOBMOD :
            value->iValue = model->omiBSIM4mobMod; 
            return(OK);
        case omiBSIM4_MOD_PARAMCHK :
            value->iValue = model->omiBSIM4paramChk; 
            return(OK);
        case omiBSIM4_MOD_BINUNIT :
            value->iValue = model->omiBSIM4binUnit; 
            return(OK);
        case omiBSIM4_MOD_CVCHARGEMOD :
            value->iValue = model->omiBSIM4cvchargeMod; 
            return(OK);
        case omiBSIM4_MOD_CAPMOD :
            value->iValue = model->omiBSIM4capMod; 
            return(OK);
        case omiBSIM4_MOD_DIOMOD :
            value->iValue = model->omiBSIM4dioMod;
            return(OK);
        case omiBSIM4_MOD_TRNQSMOD :
            value->iValue = model->omiBSIM4trnqsMod;
            return(OK);
        case omiBSIM4_MOD_ACNQSMOD :
            value->iValue = model->omiBSIM4acnqsMod;
            return(OK);
        case omiBSIM4_MOD_FNOIMOD :
            value->iValue = model->omiBSIM4fnoiMod; 
            return(OK);
        case omiBSIM4_MOD_TNOIMOD :
            value->iValue = model->omiBSIM4tnoiMod;
            return(OK);
        case omiBSIM4_MOD_RDSMOD :
            value->iValue = model->omiBSIM4rdsMod;
            return(OK);
        case omiBSIM4_MOD_RBODYMOD :
            value->iValue = model->omiBSIM4rbodyMod;
            return(OK);
        case omiBSIM4_MOD_RGATEMOD :
            value->iValue = model->omiBSIM4rgateMod;
            return(OK);
        case omiBSIM4_MOD_PERMOD :
            value->iValue = model->omiBSIM4perMod;
            return(OK);
        case omiBSIM4_MOD_GEOMOD :
            value->iValue = model->omiBSIM4geoMod;
            return(OK);
        case omiBSIM4_MOD_RGEOMOD :
            value->iValue = model->omiBSIM4rgeoMod;
            return(OK);
        case omiBSIM4_MOD_MTRLMOD :
            value->iValue = model->omiBSIM4mtrlMod;
            return(OK);
	case omiBSIM4_MOD_GIDLMOD :		/* v4.7 New GIDL/GISL*/
            value->iValue = model->omiBSIM4gidlMod;
            return(OK);
        case omiBSIM4_MOD_MTRLCOMPATMOD :
	    value->iValue = model->omiBSIM4mtrlCompatMod;
	    return(OK);
        case omiBSIM4_MOD_IGCMOD :
            value->iValue = model->omiBSIM4igcMod;
            return(OK);
        case omiBSIM4_MOD_IGBMOD :
            value->iValue = model->omiBSIM4igbMod;
            return(OK);
        case  omiBSIM4_MOD_TEMPMOD :
            value->iValue = model->omiBSIM4tempMod;
            return(OK);

        case  omiBSIM4_MOD_VERSION :
          value->sValue = model->omiBSIM4version;
            return(OK);
        case  omiBSIM4_MOD_TOXREF :
          value->rValue = model->omiBSIM4toxref;
          return(OK);
        case  omiBSIM4_MOD_EOT :
          value->rValue = model->omiBSIM4eot;
            return(OK);
        case  omiBSIM4_MOD_VDDEOT :
          value->rValue = model->omiBSIM4vddeot;
            return(OK);
		case  omiBSIM4_MOD_TEMPEOT :
          value->rValue = model->omiBSIM4tempeot;
            return(OK);
		case  omiBSIM4_MOD_LEFFEOT :
          value->rValue = model->omiBSIM4leffeot;
            return(OK);
		case  omiBSIM4_MOD_WEFFEOT :
          value->rValue = model->omiBSIM4weffeot;
            return(OK);
        case  omiBSIM4_MOD_ADOS :
          value->rValue = model->omiBSIM4ados;
            return(OK);
        case  omiBSIM4_MOD_BDOS :
          value->rValue = model->omiBSIM4bdos;
            return(OK);
        case  omiBSIM4_MOD_TOXE :
          value->rValue = model->omiBSIM4toxe;
            return(OK);
        case  omiBSIM4_MOD_TOXP :
          value->rValue = model->omiBSIM4toxp;
            return(OK);
        case  omiBSIM4_MOD_TOXM :
          value->rValue = model->omiBSIM4toxm;
            return(OK);
        case  omiBSIM4_MOD_DTOX :
          value->rValue = model->omiBSIM4dtox;
            return(OK);
        case  omiBSIM4_MOD_EPSROX :
          value->rValue = model->omiBSIM4epsrox;
            return(OK);
        case  omiBSIM4_MOD_CDSC :
          value->rValue = model->omiBSIM4cdsc;
            return(OK);
        case  omiBSIM4_MOD_CDSCB :
          value->rValue = model->omiBSIM4cdscb;
            return(OK);

        case  omiBSIM4_MOD_CDSCD :
          value->rValue = model->omiBSIM4cdscd;
            return(OK);

        case  omiBSIM4_MOD_CIT :
          value->rValue = model->omiBSIM4cit;
            return(OK);
        case  omiBSIM4_MOD_NFACTOR :
          value->rValue = model->omiBSIM4nfactor;
            return(OK);
        case omiBSIM4_MOD_XJ:
            value->rValue = model->omiBSIM4xj;
            return(OK);
        case omiBSIM4_MOD_VSAT:
            value->rValue = model->omiBSIM4vsat;
            return(OK);
        case omiBSIM4_MOD_VTL:
            value->rValue = model->omiBSIM4vtl;
            return(OK);
        case omiBSIM4_MOD_XN:
            value->rValue = model->omiBSIM4xn;
            return(OK);
        case omiBSIM4_MOD_LC:
            value->rValue = model->omiBSIM4lc;
            return(OK);
        case omiBSIM4_MOD_LAMBDA:
            value->rValue = model->omiBSIM4lambda;
            return(OK);
        case omiBSIM4_MOD_AT:
            value->rValue = model->omiBSIM4at;
            return(OK);
        case omiBSIM4_MOD_A0:
            value->rValue = model->omiBSIM4a0;
            return(OK);

        case omiBSIM4_MOD_AGS:
            value->rValue = model->omiBSIM4ags;
            return(OK);

        case omiBSIM4_MOD_A1:
            value->rValue = model->omiBSIM4a1;
            return(OK);
        case omiBSIM4_MOD_A2:
            value->rValue = model->omiBSIM4a2;
            return(OK);
        case omiBSIM4_MOD_KETA:
            value->rValue = model->omiBSIM4keta;
            return(OK);   
        case omiBSIM4_MOD_NSUB:
            value->rValue = model->omiBSIM4nsub;
            return(OK);
        case omiBSIM4_MOD_PHIG:
	    value->rValue = model->omiBSIM4phig;
	    return(OK);
        case omiBSIM4_MOD_EPSRGATE:
	    value->rValue = model->omiBSIM4epsrgate;
	    return(OK);
        case omiBSIM4_MOD_EASUB:
            value->rValue = model->omiBSIM4easub;
            return(OK);
        case omiBSIM4_MOD_EPSRSUB:
            value->rValue = model->omiBSIM4epsrsub;
            return(OK);
        case omiBSIM4_MOD_NI0SUB:
            value->rValue = model->omiBSIM4ni0sub;
            return(OK);
        case omiBSIM4_MOD_BG0SUB:
            value->rValue = model->omiBSIM4bg0sub;
            return(OK);
        case omiBSIM4_MOD_TBGASUB:
            value->rValue = model->omiBSIM4tbgasub;
            return(OK);
        case omiBSIM4_MOD_TBGBSUB:
            value->rValue = model->omiBSIM4tbgbsub;
            return(OK);
        case omiBSIM4_MOD_NDEP:
            value->rValue = model->omiBSIM4ndep;
            return(OK);
        case omiBSIM4_MOD_NSD:
            value->rValue = model->omiBSIM4nsd;
            return(OK);
        case omiBSIM4_MOD_NGATE:
            value->rValue = model->omiBSIM4ngate;
            return(OK);
        case omiBSIM4_MOD_GAMMA1:
            value->rValue = model->omiBSIM4gamma1;
            return(OK);
        case omiBSIM4_MOD_GAMMA2:
            value->rValue = model->omiBSIM4gamma2;
            return(OK);
        case omiBSIM4_MOD_VBX:
            value->rValue = model->omiBSIM4vbx;
            return(OK);
        case omiBSIM4_MOD_VBM:
            value->rValue = model->omiBSIM4vbm;
            return(OK);
        case omiBSIM4_MOD_XT:
            value->rValue = model->omiBSIM4xt;
            return(OK);
        case  omiBSIM4_MOD_K1:
          value->rValue = model->omiBSIM4k1;
            return(OK);
        case  omiBSIM4_MOD_KT1:
          value->rValue = model->omiBSIM4kt1;
            return(OK);
        case  omiBSIM4_MOD_KT1L:
          value->rValue = model->omiBSIM4kt1l;
            return(OK);
        case  omiBSIM4_MOD_KT2 :
          value->rValue = model->omiBSIM4kt2;
            return(OK);
        case  omiBSIM4_MOD_K2 :
          value->rValue = model->omiBSIM4k2;
            return(OK);
        case  omiBSIM4_MOD_K3:
          value->rValue = model->omiBSIM4k3;
            return(OK);
        case  omiBSIM4_MOD_K3B:
          value->rValue = model->omiBSIM4k3b;
            return(OK);
        case  omiBSIM4_MOD_W0:
          value->rValue = model->omiBSIM4w0;
            return(OK);
        case  omiBSIM4_MOD_LPE0:
          value->rValue = model->omiBSIM4lpe0;
            return(OK);
        case  omiBSIM4_MOD_LPEB:
          value->rValue = model->omiBSIM4lpeb;
            return(OK);
        case  omiBSIM4_MOD_DVTP0:
          value->rValue = model->omiBSIM4dvtp0;
            return(OK);
        case  omiBSIM4_MOD_DVTP1:
          value->rValue = model->omiBSIM4dvtp1;
            return(OK);
        case  omiBSIM4_MOD_DVTP2:
          value->rValue = model->omiBSIM4dvtp2;  /* New DIBL/Rout */
            return(OK);
        case  omiBSIM4_MOD_DVTP3:
          value->rValue = model->omiBSIM4dvtp3;
            return(OK);
        case  omiBSIM4_MOD_DVTP4:
          value->rValue = model->omiBSIM4dvtp4;
            return(OK);
        case  omiBSIM4_MOD_DVTP5:
          value->rValue = model->omiBSIM4dvtp5;
            return(OK);
        case  omiBSIM4_MOD_DVT0 :                
          value->rValue = model->omiBSIM4dvt0;
            return(OK);
        case  omiBSIM4_MOD_DVT1 :             
          value->rValue = model->omiBSIM4dvt1;
            return(OK);
        case  omiBSIM4_MOD_DVT2 :             
          value->rValue = model->omiBSIM4dvt2;
            return(OK);
        case  omiBSIM4_MOD_DVT0W :                
          value->rValue = model->omiBSIM4dvt0w;
            return(OK);
        case  omiBSIM4_MOD_DVT1W :             
          value->rValue = model->omiBSIM4dvt1w;
            return(OK);
        case  omiBSIM4_MOD_DVT2W :             
          value->rValue = model->omiBSIM4dvt2w;
            return(OK);
        case  omiBSIM4_MOD_DROUT :           
          value->rValue = model->omiBSIM4drout;
            return(OK);
        case  omiBSIM4_MOD_DSUB :           
          value->rValue = model->omiBSIM4dsub;
            return(OK);
        case omiBSIM4_MOD_VTH0:
            value->rValue = model->omiBSIM4vth0; 
            return(OK);
        case omiBSIM4_MOD_EU:
            value->rValue = model->omiBSIM4eu;
            return(OK);
		 case omiBSIM4_MOD_UCS:
            value->rValue = model->omiBSIM4ucs;
            return(OK);
        case omiBSIM4_MOD_UA:
            value->rValue = model->omiBSIM4ua; 
            return(OK);
        case omiBSIM4_MOD_UA1:
            value->rValue = model->omiBSIM4ua1; 
            return(OK);
        case omiBSIM4_MOD_UB:
            value->rValue = model->omiBSIM4ub;  
            return(OK);
        case omiBSIM4_MOD_UB1:
            value->rValue = model->omiBSIM4ub1;  
            return(OK);
        case omiBSIM4_MOD_UC:
            value->rValue = model->omiBSIM4uc; 
            return(OK);
        case omiBSIM4_MOD_UC1:
            value->rValue = model->omiBSIM4uc1; 
            return(OK);
        case omiBSIM4_MOD_UD:
            value->rValue = model->omiBSIM4ud; 
            return(OK);
        case omiBSIM4_MOD_UD1:
            value->rValue = model->omiBSIM4ud1; 
            return(OK);
        case omiBSIM4_MOD_UP:
            value->rValue = model->omiBSIM4up; 
            return(OK);
        case omiBSIM4_MOD_LP:
            value->rValue = model->omiBSIM4lp; 
            return(OK);
        case omiBSIM4_MOD_U0:
            value->rValue = model->omiBSIM4u0;
            return(OK);
        case omiBSIM4_MOD_UTE:
            value->rValue = model->omiBSIM4ute;
            return(OK);
		 case omiBSIM4_MOD_UCSTE:
            value->rValue = model->omiBSIM4ucste;
            return(OK);
        case omiBSIM4_MOD_VOFF:
            value->rValue = model->omiBSIM4voff;
            return(OK);
        case omiBSIM4_MOD_TVOFF:
            value->rValue = model->omiBSIM4tvoff;
            return(OK);
        case omiBSIM4_MOD_TNFACTOR:	/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4tnfactor;
            return(OK);
        case omiBSIM4_MOD_TETA0:		/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4teta0;
            return(OK);
        case omiBSIM4_MOD_TVOFFCV:		/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4tvoffcv;
            return(OK);
        case omiBSIM4_MOD_VFBSDOFF:
            value->rValue = model->omiBSIM4vfbsdoff;
            return(OK);
        case omiBSIM4_MOD_TVFBSDOFF:
            value->rValue = model->omiBSIM4tvfbsdoff;
            return(OK);
        case omiBSIM4_MOD_VOFFL:
            value->rValue = model->omiBSIM4voffl;
            return(OK);
        case omiBSIM4_MOD_VOFFCVL:
            value->rValue = model->omiBSIM4voffcvl;
            return(OK);
        case omiBSIM4_MOD_MINV:
            value->rValue = model->omiBSIM4minv;
            return(OK);
        case omiBSIM4_MOD_MINVCV:
            value->rValue = model->omiBSIM4minvcv;
            return(OK);
        case omiBSIM4_MOD_FPROUT:
            value->rValue = model->omiBSIM4fprout;
            return(OK);
        case omiBSIM4_MOD_PDITS:
            value->rValue = model->omiBSIM4pdits;
            return(OK);
        case omiBSIM4_MOD_PDITSD:
            value->rValue = model->omiBSIM4pditsd;
            return(OK);
        case omiBSIM4_MOD_PDITSL:
            value->rValue = model->omiBSIM4pditsl;
            return(OK);
        case omiBSIM4_MOD_DELTA:
            value->rValue = model->omiBSIM4delta;
            return(OK);
        case omiBSIM4_MOD_RDSW:
            value->rValue = model->omiBSIM4rdsw; 
            return(OK);
        case omiBSIM4_MOD_RDSWMIN:
            value->rValue = model->omiBSIM4rdswmin;
            return(OK);
        case omiBSIM4_MOD_RDWMIN:
            value->rValue = model->omiBSIM4rdwmin;
            return(OK);
        case omiBSIM4_MOD_RSWMIN:
            value->rValue = model->omiBSIM4rswmin;
            return(OK);
        case omiBSIM4_MOD_RDW:
            value->rValue = model->omiBSIM4rdw;
            return(OK);
        case omiBSIM4_MOD_RSW:
            value->rValue = model->omiBSIM4rsw;
            return(OK);
        case omiBSIM4_MOD_PRWG:
            value->rValue = model->omiBSIM4prwg; 
            return(OK);             
        case omiBSIM4_MOD_PRWB:
            value->rValue = model->omiBSIM4prwb; 
            return(OK);             
        case omiBSIM4_MOD_PRT:
            value->rValue = model->omiBSIM4prt; 
            return(OK);              
        case omiBSIM4_MOD_ETA0:
            value->rValue = model->omiBSIM4eta0; 
            return(OK);               
        case omiBSIM4_MOD_ETAB:
            value->rValue = model->omiBSIM4etab; 
            return(OK);               
        case omiBSIM4_MOD_PCLM:
            value->rValue = model->omiBSIM4pclm; 
            return(OK);               
        case omiBSIM4_MOD_PDIBL1:
            value->rValue = model->omiBSIM4pdibl1; 
            return(OK);               
        case omiBSIM4_MOD_PDIBL2:
            value->rValue = model->omiBSIM4pdibl2; 
            return(OK);               
        case omiBSIM4_MOD_PDIBLB:
            value->rValue = model->omiBSIM4pdiblb; 
            return(OK);               
        case omiBSIM4_MOD_PSCBE1:
            value->rValue = model->omiBSIM4pscbe1; 
            return(OK);               
        case omiBSIM4_MOD_PSCBE2:
            value->rValue = model->omiBSIM4pscbe2; 
            return(OK);               
        case omiBSIM4_MOD_PVAG:
            value->rValue = model->omiBSIM4pvag; 
            return(OK);               
        case omiBSIM4_MOD_WR:
            value->rValue = model->omiBSIM4wr;
            return(OK);
        case omiBSIM4_MOD_DWG:
            value->rValue = model->omiBSIM4dwg;
            return(OK);
        case omiBSIM4_MOD_DWB:
            value->rValue = model->omiBSIM4dwb;
            return(OK);
        case omiBSIM4_MOD_B0:
            value->rValue = model->omiBSIM4b0;
            return(OK);
        case omiBSIM4_MOD_B1:
            value->rValue = model->omiBSIM4b1;
            return(OK);
        case omiBSIM4_MOD_ALPHA0:
            value->rValue = model->omiBSIM4alpha0;
            return(OK);
        case omiBSIM4_MOD_ALPHA1:
            value->rValue = model->omiBSIM4alpha1;
            return(OK);
        case omiBSIM4_MOD_BETA0:
            value->rValue = model->omiBSIM4beta0;
            return(OK);
        case omiBSIM4_MOD_AGIDL:
            value->rValue = model->omiBSIM4agidl;
            return(OK);
        case omiBSIM4_MOD_BGIDL:
            value->rValue = model->omiBSIM4bgidl;
            return(OK);
        case omiBSIM4_MOD_CGIDL:
            value->rValue = model->omiBSIM4cgidl;
            return(OK);
        case omiBSIM4_MOD_EGIDL:
            value->rValue = model->omiBSIM4egidl;
            return(OK);
 	case omiBSIM4_MOD_FGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4fgidl;
            return(OK);
 	case omiBSIM4_MOD_KGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4kgidl;
            return(OK);
 	case omiBSIM4_MOD_RGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4rgidl;
            return(OK);
        case omiBSIM4_MOD_AGISL:
            value->rValue = model->omiBSIM4agisl;
            return(OK);
        case omiBSIM4_MOD_BGISL:
            value->rValue = model->omiBSIM4bgisl;
            return(OK);
        case omiBSIM4_MOD_CGISL:
            value->rValue = model->omiBSIM4cgisl;
            return(OK);
        case omiBSIM4_MOD_EGISL:
            value->rValue = model->omiBSIM4egisl;
            return(OK);
 	case omiBSIM4_MOD_FGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4fgisl;
            return(OK);
 	case omiBSIM4_MOD_KGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4kgisl;
            return(OK);
 	case omiBSIM4_MOD_RGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4rgisl;
            return(OK);
        case omiBSIM4_MOD_AIGC:
            value->rValue = model->omiBSIM4aigc;
            return(OK);
        case omiBSIM4_MOD_BIGC:
            value->rValue = model->omiBSIM4bigc;
            return(OK);
        case omiBSIM4_MOD_CIGC:
            value->rValue = model->omiBSIM4cigc;
            return(OK);
        case omiBSIM4_MOD_AIGSD:
            value->rValue = model->omiBSIM4aigsd;
            return(OK);
        case omiBSIM4_MOD_BIGSD:
            value->rValue = model->omiBSIM4bigsd;
            return(OK);
        case omiBSIM4_MOD_CIGSD:
            value->rValue = model->omiBSIM4cigsd;
            return(OK);
        case omiBSIM4_MOD_AIGS:
            value->rValue = model->omiBSIM4aigs;
            return(OK);
        case omiBSIM4_MOD_BIGS:
            value->rValue = model->omiBSIM4bigs;
            return(OK);
        case omiBSIM4_MOD_CIGS:
            value->rValue = model->omiBSIM4cigs;
            return(OK);
        case omiBSIM4_MOD_AIGD:
            value->rValue = model->omiBSIM4aigd;
            return(OK);
        case omiBSIM4_MOD_BIGD:
            value->rValue = model->omiBSIM4bigd;
            return(OK);
        case omiBSIM4_MOD_CIGD:
            value->rValue = model->omiBSIM4cigd;
            return(OK);
        case omiBSIM4_MOD_AIGBACC:
            value->rValue = model->omiBSIM4aigbacc;
            return(OK);
        case omiBSIM4_MOD_BIGBACC:
            value->rValue = model->omiBSIM4bigbacc;
            return(OK);
        case omiBSIM4_MOD_CIGBACC:
            value->rValue = model->omiBSIM4cigbacc;
            return(OK);
        case omiBSIM4_MOD_AIGBINV:
            value->rValue = model->omiBSIM4aigbinv;
            return(OK);
        case omiBSIM4_MOD_BIGBINV:
            value->rValue = model->omiBSIM4bigbinv;
            return(OK);
        case omiBSIM4_MOD_CIGBINV:
            value->rValue = model->omiBSIM4cigbinv;
            return(OK);
        case omiBSIM4_MOD_NIGC:
            value->rValue = model->omiBSIM4nigc;
            return(OK);
        case omiBSIM4_MOD_NIGBACC:
            value->rValue = model->omiBSIM4nigbacc;
            return(OK);
        case omiBSIM4_MOD_NIGBINV:
            value->rValue = model->omiBSIM4nigbinv;
            return(OK);
        case omiBSIM4_MOD_NTOX:
            value->rValue = model->omiBSIM4ntox;
            return(OK);
        case omiBSIM4_MOD_EIGBINV:
            value->rValue = model->omiBSIM4eigbinv;
            return(OK);
        case omiBSIM4_MOD_PIGCD:
            value->rValue = model->omiBSIM4pigcd;
            return(OK);
        case omiBSIM4_MOD_POXEDGE:
            value->rValue = model->omiBSIM4poxedge;
            return(OK);
        case omiBSIM4_MOD_PHIN:
            value->rValue = model->omiBSIM4phin;
            return(OK);
        case omiBSIM4_MOD_XRCRG1:
            value->rValue = model->omiBSIM4xrcrg1;
            return(OK);
        case omiBSIM4_MOD_XRCRG2:
            value->rValue = model->omiBSIM4xrcrg2;
            return(OK);
        case omiBSIM4_MOD_TNOIA:
            value->rValue = model->omiBSIM4tnoia;
            return(OK);
        case omiBSIM4_MOD_TNOIB:
            value->rValue = model->omiBSIM4tnoib;
            return(OK);
        case omiBSIM4_MOD_TNOIC:
            value->rValue = model->omiBSIM4tnoic;
            return(OK);
        case omiBSIM4_MOD_RNOIA:
            value->rValue = model->omiBSIM4rnoia;
            return(OK);
        case omiBSIM4_MOD_RNOIB:
            value->rValue = model->omiBSIM4rnoib;
            return(OK);
        case omiBSIM4_MOD_RNOIC:
            value->rValue = model->omiBSIM4rnoic;
            return(OK);
        case omiBSIM4_MOD_NTNOI:
            value->rValue = model->omiBSIM4ntnoi;
            return(OK);
        case omiBSIM4_MOD_IJTHDFWD:
            value->rValue = model->omiBSIM4ijthdfwd;
            return(OK);
        case omiBSIM4_MOD_IJTHSFWD:
            value->rValue = model->omiBSIM4ijthsfwd;
            return(OK);
        case omiBSIM4_MOD_IJTHDREV:
            value->rValue = model->omiBSIM4ijthdrev;
            return(OK);
        case omiBSIM4_MOD_IJTHSREV:
            value->rValue = model->omiBSIM4ijthsrev;
            return(OK);
        case omiBSIM4_MOD_XJBVD:
            value->rValue = model->omiBSIM4xjbvd;
            return(OK);
        case omiBSIM4_MOD_XJBVS:
            value->rValue = model->omiBSIM4xjbvs;
            return(OK);
        case omiBSIM4_MOD_BVD:
            value->rValue = model->omiBSIM4bvd;
            return(OK);
        case omiBSIM4_MOD_BVS:
            value->rValue = model->omiBSIM4bvs;
            return(OK);
        case omiBSIM4_MOD_VFB:
            value->rValue = model->omiBSIM4vfb;
            return(OK);

        case omiBSIM4_MOD_JTSS:
            value->rValue = model->omiBSIM4jtss;
            return(OK);
        case omiBSIM4_MOD_JTSD:
            value->rValue = model->omiBSIM4jtsd;
            return(OK);
        case omiBSIM4_MOD_JTSSWS:
            value->rValue = model->omiBSIM4jtssws;
            return(OK);
        case omiBSIM4_MOD_JTSSWD:
            value->rValue = model->omiBSIM4jtsswd;
            return(OK);
        case omiBSIM4_MOD_JTSSWGS:
            value->rValue = model->omiBSIM4jtsswgs;
            return(OK);
        case omiBSIM4_MOD_JTSSWGD:
            value->rValue = model->omiBSIM4jtsswgd;
            return(OK);
		case omiBSIM4_MOD_JTWEFF:
		    value->rValue = model->omiBSIM4jtweff;
			return(OK);
        case omiBSIM4_MOD_NJTS:
            value->rValue = model->omiBSIM4njts;
            return(OK);
        case omiBSIM4_MOD_NJTSSW:
            value->rValue = model->omiBSIM4njtssw;
            return(OK);
        case omiBSIM4_MOD_NJTSSWG:
            value->rValue = model->omiBSIM4njtsswg;
            return(OK);
        case omiBSIM4_MOD_NJTSD:
            value->rValue = model->omiBSIM4njtsd;
            return(OK);
        case omiBSIM4_MOD_NJTSSWD:
            value->rValue = model->omiBSIM4njtsswd;
            return(OK);
        case omiBSIM4_MOD_NJTSSWGD:
            value->rValue = model->omiBSIM4njtsswgd;
            return(OK);
        case omiBSIM4_MOD_XTSS:
            value->rValue = model->omiBSIM4xtss;
            return(OK);
        case omiBSIM4_MOD_XTSD:
            value->rValue = model->omiBSIM4xtsd;
            return(OK);
        case omiBSIM4_MOD_XTSSWS:
            value->rValue = model->omiBSIM4xtssws;
            return(OK);
        case omiBSIM4_MOD_XTSSWD:
            value->rValue = model->omiBSIM4xtsswd;
            return(OK);
        case omiBSIM4_MOD_XTSSWGS:
            value->rValue = model->omiBSIM4xtsswgs;
            return(OK);
        case omiBSIM4_MOD_XTSSWGD:
            value->rValue = model->omiBSIM4xtsswgd;
            return(OK);
        case omiBSIM4_MOD_TNJTS:
            value->rValue = model->omiBSIM4tnjts;
            return(OK);
        case omiBSIM4_MOD_TNJTSSW:
            value->rValue = model->omiBSIM4tnjtssw;
            return(OK);
        case omiBSIM4_MOD_TNJTSSWG:
            value->rValue = model->omiBSIM4tnjtsswg;
            return(OK);
        case omiBSIM4_MOD_TNJTSD:
            value->rValue = model->omiBSIM4tnjtsd;
            return(OK);
        case omiBSIM4_MOD_TNJTSSWD:
            value->rValue = model->omiBSIM4tnjtsswd;
            return(OK);
        case omiBSIM4_MOD_TNJTSSWGD:
            value->rValue = model->omiBSIM4tnjtsswgd;
            return(OK);
        case omiBSIM4_MOD_VTSS:
            value->rValue = model->omiBSIM4vtss;
            return(OK);
        case omiBSIM4_MOD_VTSD:
            value->rValue = model->omiBSIM4vtsd;
            return(OK);
        case omiBSIM4_MOD_VTSSWS:
            value->rValue = model->omiBSIM4vtssws;
            return(OK);
        case omiBSIM4_MOD_VTSSWD:
            value->rValue = model->omiBSIM4vtsswd;
            return(OK);
        case omiBSIM4_MOD_VTSSWGS:
            value->rValue = model->omiBSIM4vtsswgs;
            return(OK);
        case omiBSIM4_MOD_VTSSWGD:
            value->rValue = model->omiBSIM4vtsswgd;
            return(OK);

        case omiBSIM4_MOD_GBMIN:
            value->rValue = model->omiBSIM4gbmin;
            return(OK);
        case omiBSIM4_MOD_RBDB:
            value->rValue = model->omiBSIM4rbdb;
            return(OK);
        case omiBSIM4_MOD_RBPB:
            value->rValue = model->omiBSIM4rbpb;
            return(OK);
        case omiBSIM4_MOD_RBSB:
            value->rValue = model->omiBSIM4rbsb;
            return(OK);
        case omiBSIM4_MOD_RBPS:
            value->rValue = model->omiBSIM4rbps;
            return(OK);
        case omiBSIM4_MOD_RBPD:
            value->rValue = model->omiBSIM4rbpd;
            return(OK);

        case omiBSIM4_MOD_RBPS0:
            value->rValue = model->omiBSIM4rbps0;
            return(OK);
        case omiBSIM4_MOD_RBPSL:
            value->rValue = model->omiBSIM4rbpsl;
            return(OK);
        case omiBSIM4_MOD_RBPSW:
            value->rValue = model->omiBSIM4rbpsw;
            return(OK);
        case omiBSIM4_MOD_RBPSNF:
            value->rValue = model->omiBSIM4rbpsnf;
            return(OK);
        case omiBSIM4_MOD_RBPD0:
            value->rValue = model->omiBSIM4rbpd0;
            return(OK);
        case omiBSIM4_MOD_RBPDL:
            value->rValue = model->omiBSIM4rbpdl;
            return(OK);
        case omiBSIM4_MOD_RBPDW:
            value->rValue = model->omiBSIM4rbpdw;
            return(OK);
        case omiBSIM4_MOD_RBPDNF:
            value->rValue = model->omiBSIM4rbpdnf;
            return(OK);
        case omiBSIM4_MOD_RBPBX0:
            value->rValue = model->omiBSIM4rbpbx0;
            return(OK);
        case omiBSIM4_MOD_RBPBXL:
            value->rValue = model->omiBSIM4rbpbxl;
            return(OK);
        case omiBSIM4_MOD_RBPBXW:
            value->rValue = model->omiBSIM4rbpbxw;
            return(OK);
        case omiBSIM4_MOD_RBPBXNF:
            value->rValue = model->omiBSIM4rbpbxnf;
            return(OK);
        case omiBSIM4_MOD_RBPBY0:
            value->rValue = model->omiBSIM4rbpby0;
            return(OK);
        case omiBSIM4_MOD_RBPBYL:
            value->rValue = model->omiBSIM4rbpbyl;
            return(OK);
        case omiBSIM4_MOD_RBPBYW:
            value->rValue = model->omiBSIM4rbpbyw;
            return(OK);
        case omiBSIM4_MOD_RBPBYNF:
            value->rValue = model->omiBSIM4rbpbynf;
            return(OK);

        case omiBSIM4_MOD_RBSBX0:
            value->rValue = model->omiBSIM4rbsbx0;
            return(OK);
        case omiBSIM4_MOD_RBSBY0:
            value->rValue = model->omiBSIM4rbsby0;
            return(OK);
        case omiBSIM4_MOD_RBDBX0:
            value->rValue = model->omiBSIM4rbdbx0;
            return(OK);
        case omiBSIM4_MOD_RBDBY0:
            value->rValue = model->omiBSIM4rbdby0;
            return(OK);
        case omiBSIM4_MOD_RBSDBXL:
            value->rValue = model->omiBSIM4rbsdbxl;
            return(OK);
        case omiBSIM4_MOD_RBSDBXW:
            value->rValue = model->omiBSIM4rbsdbxw;
            return(OK);
        case omiBSIM4_MOD_RBSDBXNF:
            value->rValue = model->omiBSIM4rbsdbxnf;
            return(OK);
        case omiBSIM4_MOD_RBSDBYL:
            value->rValue = model->omiBSIM4rbsdbyl;
            return(OK);
        case omiBSIM4_MOD_RBSDBYW:
            value->rValue = model->omiBSIM4rbsdbyw;
            return(OK);
        case omiBSIM4_MOD_RBSDBYNF:
            value->rValue = model->omiBSIM4rbsdbynf;
            return(OK);


        case omiBSIM4_MOD_CGSL:
            value->rValue = model->omiBSIM4cgsl;
            return(OK);
        case omiBSIM4_MOD_CGDL:
            value->rValue = model->omiBSIM4cgdl;
            return(OK);
        case omiBSIM4_MOD_CKAPPAS:
            value->rValue = model->omiBSIM4ckappas;
            return(OK);
        case omiBSIM4_MOD_CKAPPAD:
            value->rValue = model->omiBSIM4ckappad;
            return(OK);
        case omiBSIM4_MOD_CF:
            value->rValue = model->omiBSIM4cf;
            return(OK);
        case omiBSIM4_MOD_CLC:
            value->rValue = model->omiBSIM4clc;
            return(OK);
        case omiBSIM4_MOD_CLE:
            value->rValue = model->omiBSIM4cle;
            return(OK);
        case omiBSIM4_MOD_DWC:
            value->rValue = model->omiBSIM4dwc;
            return(OK);
        case omiBSIM4_MOD_DLC:
            value->rValue = model->omiBSIM4dlc;
            return(OK);
        case omiBSIM4_MOD_XW:
            value->rValue = model->omiBSIM4xw;
            return(OK);
        case omiBSIM4_MOD_XL:
            value->rValue = model->omiBSIM4xl;
            return(OK);
        case omiBSIM4_MOD_DLCIG:
            value->rValue = model->omiBSIM4dlcig;
            return(OK);
        case omiBSIM4_MOD_DLCIGD:
            value->rValue = model->omiBSIM4dlcigd;
            return(OK);
        case omiBSIM4_MOD_DWJ:
            value->rValue = model->omiBSIM4dwj;
            return(OK);
        case omiBSIM4_MOD_VFBCV:
            value->rValue = model->omiBSIM4vfbcv; 
            return(OK);
        case omiBSIM4_MOD_ACDE:
            value->rValue = model->omiBSIM4acde;
            return(OK);
        case omiBSIM4_MOD_MOIN:
            value->rValue = model->omiBSIM4moin;
            return(OK);
        case omiBSIM4_MOD_NOFF:
            value->rValue = model->omiBSIM4noff;
            return(OK);
        case omiBSIM4_MOD_VOFFCV:
            value->rValue = model->omiBSIM4voffcv;
            return(OK);
        case omiBSIM4_MOD_DMCG:
            value->rValue = model->omiBSIM4dmcg;
            return(OK);
        case omiBSIM4_MOD_DMCI:
            value->rValue = model->omiBSIM4dmci;
            return(OK);
        case omiBSIM4_MOD_DMDG:
            value->rValue = model->omiBSIM4dmdg;
            return(OK);
        case omiBSIM4_MOD_DMCGT:
            value->rValue = model->omiBSIM4dmcgt;
            return(OK);
        case omiBSIM4_MOD_XGW:
            value->rValue = model->omiBSIM4xgw;
            return(OK);
        case omiBSIM4_MOD_XGL:
            value->rValue = model->omiBSIM4xgl;
            return(OK);
        case omiBSIM4_MOD_RSHG:
            value->rValue = model->omiBSIM4rshg;
            return(OK);
        case omiBSIM4_MOD_NGCON:
            value->rValue = model->omiBSIM4ngcon; 
            return(OK);
        case omiBSIM4_MOD_TCJ:
            value->rValue = model->omiBSIM4tcj;
            return(OK);
        case omiBSIM4_MOD_TPB:
            value->rValue = model->omiBSIM4tpb;
            return(OK);
        case omiBSIM4_MOD_TCJSW:
            value->rValue = model->omiBSIM4tcjsw;
            return(OK);
        case omiBSIM4_MOD_TPBSW:
            value->rValue = model->omiBSIM4tpbsw;
            return(OK);
        case omiBSIM4_MOD_TCJSWG:
            value->rValue = model->omiBSIM4tcjswg;
            return(OK);
        case omiBSIM4_MOD_TPBSWG:
            value->rValue = model->omiBSIM4tpbswg;
            return(OK);

	/* Length dependence */
        case  omiBSIM4_MOD_LCDSC :
          value->rValue = model->omiBSIM4lcdsc;
            return(OK);
        case  omiBSIM4_MOD_LCDSCB :
          value->rValue = model->omiBSIM4lcdscb;
            return(OK);
        case  omiBSIM4_MOD_LCDSCD :
          value->rValue = model->omiBSIM4lcdscd;
            return(OK);
        case  omiBSIM4_MOD_LCIT :
          value->rValue = model->omiBSIM4lcit;
            return(OK);
        case  omiBSIM4_MOD_LNFACTOR :
          value->rValue = model->omiBSIM4lnfactor;
            return(OK);
        case omiBSIM4_MOD_LXJ:
            value->rValue = model->omiBSIM4lxj;
            return(OK);
        case omiBSIM4_MOD_LVSAT:
            value->rValue = model->omiBSIM4lvsat;
            return(OK);
        case omiBSIM4_MOD_LAT:
            value->rValue = model->omiBSIM4lat;
            return(OK);
        case omiBSIM4_MOD_LA0:
            value->rValue = model->omiBSIM4la0;
            return(OK);
        case omiBSIM4_MOD_LAGS:
            value->rValue = model->omiBSIM4lags;
            return(OK);
        case omiBSIM4_MOD_LA1:
            value->rValue = model->omiBSIM4la1;
            return(OK);
        case omiBSIM4_MOD_LA2:
            value->rValue = model->omiBSIM4la2;
            return(OK);
        case omiBSIM4_MOD_LKETA:
            value->rValue = model->omiBSIM4lketa;
            return(OK);   
        case omiBSIM4_MOD_LNSUB:
            value->rValue = model->omiBSIM4lnsub;
            return(OK);
        case omiBSIM4_MOD_LNDEP:
            value->rValue = model->omiBSIM4lndep;
            return(OK);
        case omiBSIM4_MOD_LNSD:
            value->rValue = model->omiBSIM4lnsd;
            return(OK);
        case omiBSIM4_MOD_LNGATE:
            value->rValue = model->omiBSIM4lngate;
            return(OK);
        case omiBSIM4_MOD_LGAMMA1:
            value->rValue = model->omiBSIM4lgamma1;
            return(OK);
        case omiBSIM4_MOD_LGAMMA2:
            value->rValue = model->omiBSIM4lgamma2;
            return(OK);
        case omiBSIM4_MOD_LVBX:
            value->rValue = model->omiBSIM4lvbx;
            return(OK);
        case omiBSIM4_MOD_LVBM:
            value->rValue = model->omiBSIM4lvbm;
            return(OK);
        case omiBSIM4_MOD_LXT:
            value->rValue = model->omiBSIM4lxt;
            return(OK);
        case  omiBSIM4_MOD_LK1:
          value->rValue = model->omiBSIM4lk1;
            return(OK);
        case  omiBSIM4_MOD_LKT1:
          value->rValue = model->omiBSIM4lkt1;
            return(OK);
        case  omiBSIM4_MOD_LKT1L:
          value->rValue = model->omiBSIM4lkt1l;
            return(OK);
        case  omiBSIM4_MOD_LKT2 :
          value->rValue = model->omiBSIM4lkt2;
            return(OK);
        case  omiBSIM4_MOD_LK2 :
          value->rValue = model->omiBSIM4lk2;
            return(OK);
        case  omiBSIM4_MOD_LK3:
          value->rValue = model->omiBSIM4lk3;
            return(OK);
        case  omiBSIM4_MOD_LK3B:
          value->rValue = model->omiBSIM4lk3b;
            return(OK);
        case  omiBSIM4_MOD_LW0:
          value->rValue = model->omiBSIM4lw0;
            return(OK);
        case  omiBSIM4_MOD_LLPE0:
          value->rValue = model->omiBSIM4llpe0;
            return(OK);
        case  omiBSIM4_MOD_LLPEB:
          value->rValue = model->omiBSIM4llpeb;
            return(OK);
        case  omiBSIM4_MOD_LDVTP0:
          value->rValue = model->omiBSIM4ldvtp0;
            return(OK);
        case  omiBSIM4_MOD_LDVTP1:
          value->rValue = model->omiBSIM4ldvtp1;
            return(OK);
	case  omiBSIM4_MOD_LDVTP2:
          value->rValue = model->omiBSIM4ldvtp2;  /* New DIBL/Rout */
            return(OK);
        case  omiBSIM4_MOD_LDVTP3:
          value->rValue = model->omiBSIM4ldvtp3;
            return(OK);
        case  omiBSIM4_MOD_LDVTP4:
          value->rValue = model->omiBSIM4ldvtp4;
            return(OK);
        case  omiBSIM4_MOD_LDVTP5:
          value->rValue = model->omiBSIM4ldvtp5;
            return(OK);
        case  omiBSIM4_MOD_LDVT0:                
          value->rValue = model->omiBSIM4ldvt0;
            return(OK);
        case  omiBSIM4_MOD_LDVT1 :             
          value->rValue = model->omiBSIM4ldvt1;
            return(OK);
        case  omiBSIM4_MOD_LDVT2 :             
          value->rValue = model->omiBSIM4ldvt2;
            return(OK);
        case  omiBSIM4_MOD_LDVT0W :                
          value->rValue = model->omiBSIM4ldvt0w;
            return(OK);
        case  omiBSIM4_MOD_LDVT1W :             
          value->rValue = model->omiBSIM4ldvt1w;
            return(OK);
        case  omiBSIM4_MOD_LDVT2W :             
          value->rValue = model->omiBSIM4ldvt2w;
            return(OK);
        case  omiBSIM4_MOD_LDROUT :           
          value->rValue = model->omiBSIM4ldrout;
            return(OK);
        case  omiBSIM4_MOD_LDSUB :           
          value->rValue = model->omiBSIM4ldsub;
            return(OK);
        case omiBSIM4_MOD_LVTH0:
            value->rValue = model->omiBSIM4lvth0; 
            return(OK);
        case omiBSIM4_MOD_LUA:
            value->rValue = model->omiBSIM4lua; 
            return(OK);
        case omiBSIM4_MOD_LUA1:
            value->rValue = model->omiBSIM4lua1; 
            return(OK);
        case omiBSIM4_MOD_LUB:
            value->rValue = model->omiBSIM4lub;  
            return(OK);
        case omiBSIM4_MOD_LUB1:
            value->rValue = model->omiBSIM4lub1;  
            return(OK);
        case omiBSIM4_MOD_LUC:
            value->rValue = model->omiBSIM4luc; 
            return(OK);
        case omiBSIM4_MOD_LUC1:
            value->rValue = model->omiBSIM4luc1; 
            return(OK);
        case omiBSIM4_MOD_LUD:
            value->rValue = model->omiBSIM4lud; 
            return(OK);
        case omiBSIM4_MOD_LUD1:
            value->rValue = model->omiBSIM4lud1; 
            return(OK);
        case omiBSIM4_MOD_LUP:
            value->rValue = model->omiBSIM4lup; 
            return(OK);
        case omiBSIM4_MOD_LLP:
            value->rValue = model->omiBSIM4llp; 
            return(OK);
        case omiBSIM4_MOD_LU0:
            value->rValue = model->omiBSIM4lu0;
            return(OK);
        case omiBSIM4_MOD_LUTE:
            value->rValue = model->omiBSIM4lute;
            return(OK);
		case omiBSIM4_MOD_LUCSTE:
            value->rValue = model->omiBSIM4lucste;
            return(OK);
        case omiBSIM4_MOD_LVOFF:
            value->rValue = model->omiBSIM4lvoff;
            return(OK);
        case omiBSIM4_MOD_LTVOFF:
            value->rValue = model->omiBSIM4ltvoff;
            return(OK);
        case omiBSIM4_MOD_LTNFACTOR:	/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4ltnfactor;
            return(OK);
        case omiBSIM4_MOD_LTETA0:		/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4lteta0;
            return(OK);
        case omiBSIM4_MOD_LTVOFFCV:	/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4ltvoffcv;
            return(OK);
        case omiBSIM4_MOD_LMINV:
            value->rValue = model->omiBSIM4lminv;
            return(OK);
        case omiBSIM4_MOD_LMINVCV:
            value->rValue = model->omiBSIM4lminvcv;
            return(OK);
        case omiBSIM4_MOD_LFPROUT:
            value->rValue = model->omiBSIM4lfprout;
            return(OK);
        case omiBSIM4_MOD_LPDITS:
            value->rValue = model->omiBSIM4lpdits;
            return(OK);
        case omiBSIM4_MOD_LPDITSD:
            value->rValue = model->omiBSIM4lpditsd;
            return(OK);
        case omiBSIM4_MOD_LDELTA:
            value->rValue = model->omiBSIM4ldelta;
            return(OK);
        case omiBSIM4_MOD_LRDSW:
            value->rValue = model->omiBSIM4lrdsw; 
            return(OK);             
        case omiBSIM4_MOD_LRDW:
            value->rValue = model->omiBSIM4lrdw;
            return(OK);
        case omiBSIM4_MOD_LRSW:
            value->rValue = model->omiBSIM4lrsw;
            return(OK);
        case omiBSIM4_MOD_LPRWB:
            value->rValue = model->omiBSIM4lprwb; 
            return(OK);             
        case omiBSIM4_MOD_LPRWG:
            value->rValue = model->omiBSIM4lprwg; 
            return(OK);             
        case omiBSIM4_MOD_LPRT:
            value->rValue = model->omiBSIM4lprt; 
            return(OK);              
        case omiBSIM4_MOD_LETA0:
            value->rValue = model->omiBSIM4leta0; 
            return(OK);               
        case omiBSIM4_MOD_LETAB:
            value->rValue = model->omiBSIM4letab; 
            return(OK);               
        case omiBSIM4_MOD_LPCLM:
            value->rValue = model->omiBSIM4lpclm; 
            return(OK);               
        case omiBSIM4_MOD_LPDIBL1:
            value->rValue = model->omiBSIM4lpdibl1; 
            return(OK);               
        case omiBSIM4_MOD_LPDIBL2:
            value->rValue = model->omiBSIM4lpdibl2; 
            return(OK);               
        case omiBSIM4_MOD_LPDIBLB:
            value->rValue = model->omiBSIM4lpdiblb; 
            return(OK);               
        case omiBSIM4_MOD_LPSCBE1:
            value->rValue = model->omiBSIM4lpscbe1; 
            return(OK);               
        case omiBSIM4_MOD_LPSCBE2:
            value->rValue = model->omiBSIM4lpscbe2; 
            return(OK);               
        case omiBSIM4_MOD_LPVAG:
            value->rValue = model->omiBSIM4lpvag; 
            return(OK);               
        case omiBSIM4_MOD_LWR:
            value->rValue = model->omiBSIM4lwr;
            return(OK);
        case omiBSIM4_MOD_LDWG:
            value->rValue = model->omiBSIM4ldwg;
            return(OK);
        case omiBSIM4_MOD_LDWB:
            value->rValue = model->omiBSIM4ldwb;
            return(OK);
        case omiBSIM4_MOD_LB0:
            value->rValue = model->omiBSIM4lb0;
            return(OK);
        case omiBSIM4_MOD_LB1:
            value->rValue = model->omiBSIM4lb1;
            return(OK);
        case omiBSIM4_MOD_LALPHA0:
            value->rValue = model->omiBSIM4lalpha0;
            return(OK);
        case omiBSIM4_MOD_LALPHA1:
            value->rValue = model->omiBSIM4lalpha1;
            return(OK);
        case omiBSIM4_MOD_LBETA0:
            value->rValue = model->omiBSIM4lbeta0;
            return(OK);
        case omiBSIM4_MOD_LAGIDL:
            value->rValue = model->omiBSIM4lagidl;
            return(OK);
        case omiBSIM4_MOD_LBGIDL:
            value->rValue = model->omiBSIM4lbgidl;
            return(OK);
        case omiBSIM4_MOD_LCGIDL:
            value->rValue = model->omiBSIM4lcgidl;
            return(OK);
	case omiBSIM4_MOD_LEGIDL:
            value->rValue = model->omiBSIM4legidl;
            return(OK);
        case omiBSIM4_MOD_LFGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4lfgidl;
            return(OK);
 	case omiBSIM4_MOD_LKGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4lkgidl;
            return(OK);
 	case omiBSIM4_MOD_LRGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4lrgidl;
            return(OK);
        case omiBSIM4_MOD_LAGISL:
            value->rValue = model->omiBSIM4lagisl;
            return(OK);
        case omiBSIM4_MOD_LBGISL:
            value->rValue = model->omiBSIM4lbgisl;
            return(OK);
        case omiBSIM4_MOD_LCGISL:
            value->rValue = model->omiBSIM4lcgisl;
            return(OK);
        case omiBSIM4_MOD_LEGISL:
            value->rValue = model->omiBSIM4legisl;
            return(OK);
        case omiBSIM4_MOD_LFGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4lfgisl;
            return(OK);
 	case omiBSIM4_MOD_LKGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4lkgisl;
            return(OK);
 	case omiBSIM4_MOD_LRGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4lrgisl;
            return(OK);
        case omiBSIM4_MOD_LAIGC:
            value->rValue = model->omiBSIM4laigc;
            return(OK);
        case omiBSIM4_MOD_LBIGC:
            value->rValue = model->omiBSIM4lbigc;
            return(OK);
        case omiBSIM4_MOD_LCIGC:
            value->rValue = model->omiBSIM4lcigc;
            return(OK);
        case omiBSIM4_MOD_LAIGSD:
            value->rValue = model->omiBSIM4laigsd;
            return(OK);
        case omiBSIM4_MOD_LBIGSD:
            value->rValue = model->omiBSIM4lbigsd;
            return(OK);
        case omiBSIM4_MOD_LCIGSD:
            value->rValue = model->omiBSIM4lcigsd;
            return(OK);
        case omiBSIM4_MOD_LAIGS:
            value->rValue = model->omiBSIM4laigs;
            return(OK);
        case omiBSIM4_MOD_LBIGS:
            value->rValue = model->omiBSIM4lbigs;
            return(OK);
        case omiBSIM4_MOD_LCIGS:
            value->rValue = model->omiBSIM4lcigs;
            return(OK);
        case omiBSIM4_MOD_LAIGD:
            value->rValue = model->omiBSIM4laigd;
            return(OK);
        case omiBSIM4_MOD_LBIGD:
            value->rValue = model->omiBSIM4lbigd;
            return(OK);
        case omiBSIM4_MOD_LCIGD:
            value->rValue = model->omiBSIM4lcigd;
            return(OK);
        case omiBSIM4_MOD_LAIGBACC:
            value->rValue = model->omiBSIM4laigbacc;
            return(OK);
        case omiBSIM4_MOD_LBIGBACC:
            value->rValue = model->omiBSIM4lbigbacc;
            return(OK);
        case omiBSIM4_MOD_LCIGBACC:
            value->rValue = model->omiBSIM4lcigbacc;
            return(OK);
        case omiBSIM4_MOD_LAIGBINV:
            value->rValue = model->omiBSIM4laigbinv;
            return(OK);
        case omiBSIM4_MOD_LBIGBINV:
            value->rValue = model->omiBSIM4lbigbinv;
            return(OK);
        case omiBSIM4_MOD_LCIGBINV:
            value->rValue = model->omiBSIM4lcigbinv;
            return(OK);
        case omiBSIM4_MOD_LNIGC:
            value->rValue = model->omiBSIM4lnigc;
            return(OK);
        case omiBSIM4_MOD_LNIGBACC:
            value->rValue = model->omiBSIM4lnigbacc;
            return(OK);
        case omiBSIM4_MOD_LNIGBINV:
            value->rValue = model->omiBSIM4lnigbinv;
            return(OK);
        case omiBSIM4_MOD_LNTOX:
            value->rValue = model->omiBSIM4lntox;
            return(OK);
        case omiBSIM4_MOD_LEIGBINV:
            value->rValue = model->omiBSIM4leigbinv;
            return(OK);
        case omiBSIM4_MOD_LPIGCD:
            value->rValue = model->omiBSIM4lpigcd;
            return(OK);
        case omiBSIM4_MOD_LPOXEDGE:
            value->rValue = model->omiBSIM4lpoxedge;
            return(OK);
        case omiBSIM4_MOD_LPHIN:
            value->rValue = model->omiBSIM4lphin;
            return(OK);
        case omiBSIM4_MOD_LXRCRG1:
            value->rValue = model->omiBSIM4lxrcrg1;
            return(OK);
        case omiBSIM4_MOD_LXRCRG2:
            value->rValue = model->omiBSIM4lxrcrg2;
            return(OK);
        case omiBSIM4_MOD_LEU:
            value->rValue = model->omiBSIM4leu;
            return(OK);
		case omiBSIM4_MOD_LUCS:
            value->rValue = model->omiBSIM4lucs;
            return(OK);
        case omiBSIM4_MOD_LVFB:
            value->rValue = model->omiBSIM4lvfb;
            return(OK);

        case omiBSIM4_MOD_LCGSL:
            value->rValue = model->omiBSIM4lcgsl;
            return(OK);
        case omiBSIM4_MOD_LCGDL:
            value->rValue = model->omiBSIM4lcgdl;
            return(OK);
        case omiBSIM4_MOD_LCKAPPAS:
            value->rValue = model->omiBSIM4lckappas;
            return(OK);
        case omiBSIM4_MOD_LCKAPPAD:
            value->rValue = model->omiBSIM4lckappad;
            return(OK);
        case omiBSIM4_MOD_LCF:
            value->rValue = model->omiBSIM4lcf;
            return(OK);
        case omiBSIM4_MOD_LCLC:
            value->rValue = model->omiBSIM4lclc;
            return(OK);
        case omiBSIM4_MOD_LCLE:
            value->rValue = model->omiBSIM4lcle;
            return(OK);
        case omiBSIM4_MOD_LVFBCV:
            value->rValue = model->omiBSIM4lvfbcv;
            return(OK);
        case omiBSIM4_MOD_LACDE:
            value->rValue = model->omiBSIM4lacde;
            return(OK);
        case omiBSIM4_MOD_LMOIN:
            value->rValue = model->omiBSIM4lmoin;
            return(OK);
        case omiBSIM4_MOD_LNOFF:
            value->rValue = model->omiBSIM4lnoff;
            return(OK);
        case omiBSIM4_MOD_LVOFFCV:
            value->rValue = model->omiBSIM4lvoffcv;
            return(OK);
        case omiBSIM4_MOD_LVFBSDOFF:
            value->rValue = model->omiBSIM4lvfbsdoff;
            return(OK);
        case omiBSIM4_MOD_LTVFBSDOFF:
            value->rValue = model->omiBSIM4ltvfbsdoff;
            return(OK);

        case omiBSIM4_MOD_LLAMBDA:
            value->rValue = model->omiBSIM4llambda;
            return(OK);
        case omiBSIM4_MOD_LVTL:
            value->rValue = model->omiBSIM4lvtl;
            return(OK);
        case omiBSIM4_MOD_LXN:
            value->rValue = model->omiBSIM4lxn;
            return(OK);

	/* Width dependence */
        case  omiBSIM4_MOD_WCDSC :
          value->rValue = model->omiBSIM4wcdsc;
            return(OK);
        case  omiBSIM4_MOD_WCDSCB :
          value->rValue = model->omiBSIM4wcdscb;
            return(OK);
        case  omiBSIM4_MOD_WCDSCD :
          value->rValue = model->omiBSIM4wcdscd;
            return(OK);
        case  omiBSIM4_MOD_WCIT :
          value->rValue = model->omiBSIM4wcit;
            return(OK);
        case  omiBSIM4_MOD_WNFACTOR :
          value->rValue = model->omiBSIM4wnfactor;
            return(OK);
        case omiBSIM4_MOD_WXJ:
            value->rValue = model->omiBSIM4wxj;
            return(OK);
        case omiBSIM4_MOD_WVSAT:
            value->rValue = model->omiBSIM4wvsat;
            return(OK);
        case omiBSIM4_MOD_WAT:
            value->rValue = model->omiBSIM4wat;
            return(OK);
        case omiBSIM4_MOD_WA0:
            value->rValue = model->omiBSIM4wa0;
            return(OK);
        case omiBSIM4_MOD_WAGS:
            value->rValue = model->omiBSIM4wags;
            return(OK);
        case omiBSIM4_MOD_WA1:
            value->rValue = model->omiBSIM4wa1;
            return(OK);
        case omiBSIM4_MOD_WA2:
            value->rValue = model->omiBSIM4wa2;
            return(OK);
        case omiBSIM4_MOD_WKETA:
            value->rValue = model->omiBSIM4wketa;
            return(OK);   
        case omiBSIM4_MOD_WNSUB:
            value->rValue = model->omiBSIM4wnsub;
            return(OK);
        case omiBSIM4_MOD_WNDEP:
            value->rValue = model->omiBSIM4wndep;
            return(OK);
        case omiBSIM4_MOD_WNSD:
            value->rValue = model->omiBSIM4wnsd;
            return(OK);
        case omiBSIM4_MOD_WNGATE:
            value->rValue = model->omiBSIM4wngate;
            return(OK);
        case omiBSIM4_MOD_WGAMMA1:
            value->rValue = model->omiBSIM4wgamma1;
            return(OK);
        case omiBSIM4_MOD_WGAMMA2:
            value->rValue = model->omiBSIM4wgamma2;
            return(OK);
        case omiBSIM4_MOD_WVBX:
            value->rValue = model->omiBSIM4wvbx;
            return(OK);
        case omiBSIM4_MOD_WVBM:
            value->rValue = model->omiBSIM4wvbm;
            return(OK);
        case omiBSIM4_MOD_WXT:
            value->rValue = model->omiBSIM4wxt;
            return(OK);
        case  omiBSIM4_MOD_WK1:
          value->rValue = model->omiBSIM4wk1;
            return(OK);
        case  omiBSIM4_MOD_WKT1:
          value->rValue = model->omiBSIM4wkt1;
            return(OK);
        case  omiBSIM4_MOD_WKT1L:
          value->rValue = model->omiBSIM4wkt1l;
            return(OK);
        case  omiBSIM4_MOD_WKT2 :
          value->rValue = model->omiBSIM4wkt2;
            return(OK);
        case  omiBSIM4_MOD_WK2 :
          value->rValue = model->omiBSIM4wk2;
            return(OK);
        case  omiBSIM4_MOD_WK3:
          value->rValue = model->omiBSIM4wk3;
            return(OK);
        case  omiBSIM4_MOD_WK3B:
          value->rValue = model->omiBSIM4wk3b;
            return(OK);
        case  omiBSIM4_MOD_WW0:
          value->rValue = model->omiBSIM4ww0;
            return(OK);
        case  omiBSIM4_MOD_WLPE0:
          value->rValue = model->omiBSIM4wlpe0;
            return(OK);
        case  omiBSIM4_MOD_WDVTP0:
          value->rValue = model->omiBSIM4wdvtp0;
            return(OK);
        case  omiBSIM4_MOD_WDVTP1:
          value->rValue = model->omiBSIM4wdvtp1;
            return(OK);
        case  omiBSIM4_MOD_WDVTP2:
          value->rValue = model->omiBSIM4wdvtp2;  /* New DIBL/Rout */
            return(OK);
        case  omiBSIM4_MOD_WDVTP3:
          value->rValue = model->omiBSIM4wdvtp3;
            return(OK);
        case  omiBSIM4_MOD_WDVTP4:
          value->rValue = model->omiBSIM4wdvtp4;
            return(OK);
        case  omiBSIM4_MOD_WDVTP5:
          value->rValue = model->omiBSIM4wdvtp5;
            return(OK);
        case  omiBSIM4_MOD_WLPEB:
          value->rValue = model->omiBSIM4wlpeb;
            return(OK);
        case  omiBSIM4_MOD_WDVT0:                
          value->rValue = model->omiBSIM4wdvt0;
            return(OK);
        case  omiBSIM4_MOD_WDVT1 :             
          value->rValue = model->omiBSIM4wdvt1;
            return(OK);
        case  omiBSIM4_MOD_WDVT2 :             
          value->rValue = model->omiBSIM4wdvt2;
            return(OK);
        case  omiBSIM4_MOD_WDVT0W :                
          value->rValue = model->omiBSIM4wdvt0w;
            return(OK);
        case  omiBSIM4_MOD_WDVT1W :             
          value->rValue = model->omiBSIM4wdvt1w;
            return(OK);
        case  omiBSIM4_MOD_WDVT2W :             
          value->rValue = model->omiBSIM4wdvt2w;
            return(OK);
        case  omiBSIM4_MOD_WDROUT :           
          value->rValue = model->omiBSIM4wdrout;
            return(OK);
        case  omiBSIM4_MOD_WDSUB :           
          value->rValue = model->omiBSIM4wdsub;
            return(OK);
        case omiBSIM4_MOD_WVTH0:
            value->rValue = model->omiBSIM4wvth0; 
            return(OK);
        case omiBSIM4_MOD_WUA:
            value->rValue = model->omiBSIM4wua; 
            return(OK);
        case omiBSIM4_MOD_WUA1:
            value->rValue = model->omiBSIM4wua1; 
            return(OK);
        case omiBSIM4_MOD_WUB:
            value->rValue = model->omiBSIM4wub;  
            return(OK);
        case omiBSIM4_MOD_WUB1:
            value->rValue = model->omiBSIM4wub1;  
            return(OK);
        case omiBSIM4_MOD_WUC:
            value->rValue = model->omiBSIM4wuc; 
            return(OK);
        case omiBSIM4_MOD_WUC1:
            value->rValue = model->omiBSIM4wuc1; 
            return(OK);
        case omiBSIM4_MOD_WUD:
            value->rValue = model->omiBSIM4wud; 
            return(OK);
        case omiBSIM4_MOD_WUD1:
            value->rValue = model->omiBSIM4wud1; 
            return(OK);
        case omiBSIM4_MOD_WUP:
            value->rValue = model->omiBSIM4wup; 
            return(OK);
        case omiBSIM4_MOD_WLP:
            value->rValue = model->omiBSIM4wlp; 
            return(OK);
        case omiBSIM4_MOD_WU0:
            value->rValue = model->omiBSIM4wu0;
            return(OK);
        case omiBSIM4_MOD_WUTE:
            value->rValue = model->omiBSIM4wute;
            return(OK);
        case omiBSIM4_MOD_WUCSTE:
            value->rValue = model->omiBSIM4wucste;
            return(OK);
        case omiBSIM4_MOD_WVOFF:
            value->rValue = model->omiBSIM4wvoff;
            return(OK);
        case omiBSIM4_MOD_WTVOFF:
            value->rValue = model->omiBSIM4wtvoff;
            return(OK);
        case omiBSIM4_MOD_WTNFACTOR:	/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4wtnfactor;
            return(OK);
        case omiBSIM4_MOD_WTETA0:		/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4wteta0;
            return(OK);
        case omiBSIM4_MOD_WTVOFFCV:	/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4wtvoffcv;
            return(OK);
        case omiBSIM4_MOD_WMINV:
            value->rValue = model->omiBSIM4wminv;
            return(OK);
        case omiBSIM4_MOD_WMINVCV:
            value->rValue = model->omiBSIM4wminvcv;
            return(OK);
        case omiBSIM4_MOD_WFPROUT:
            value->rValue = model->omiBSIM4wfprout;
            return(OK);
        case omiBSIM4_MOD_WPDITS:
            value->rValue = model->omiBSIM4wpdits;
            return(OK);
        case omiBSIM4_MOD_WPDITSD:
            value->rValue = model->omiBSIM4wpditsd;
            return(OK);
        case omiBSIM4_MOD_WDELTA:
            value->rValue = model->omiBSIM4wdelta;
            return(OK);
        case omiBSIM4_MOD_WRDSW:
            value->rValue = model->omiBSIM4wrdsw; 
            return(OK);             
        case omiBSIM4_MOD_WRDW:
            value->rValue = model->omiBSIM4wrdw;
            return(OK);
        case omiBSIM4_MOD_WRSW:
            value->rValue = model->omiBSIM4wrsw;
            return(OK);
        case omiBSIM4_MOD_WPRWB:
            value->rValue = model->omiBSIM4wprwb; 
            return(OK);             
        case omiBSIM4_MOD_WPRWG:
            value->rValue = model->omiBSIM4wprwg; 
            return(OK);             
        case omiBSIM4_MOD_WPRT:
            value->rValue = model->omiBSIM4wprt; 
            return(OK);              
        case omiBSIM4_MOD_WETA0:
            value->rValue = model->omiBSIM4weta0; 
            return(OK);               
        case omiBSIM4_MOD_WETAB:
            value->rValue = model->omiBSIM4wetab; 
            return(OK);               
        case omiBSIM4_MOD_WPCLM:
            value->rValue = model->omiBSIM4wpclm; 
            return(OK);               
        case omiBSIM4_MOD_WPDIBL1:
            value->rValue = model->omiBSIM4wpdibl1; 
            return(OK);               
        case omiBSIM4_MOD_WPDIBL2:
            value->rValue = model->omiBSIM4wpdibl2; 
            return(OK);               
        case omiBSIM4_MOD_WPDIBLB:
            value->rValue = model->omiBSIM4wpdiblb; 
            return(OK);               
        case omiBSIM4_MOD_WPSCBE1:
            value->rValue = model->omiBSIM4wpscbe1; 
            return(OK);               
        case omiBSIM4_MOD_WPSCBE2:
            value->rValue = model->omiBSIM4wpscbe2; 
            return(OK);               
        case omiBSIM4_MOD_WPVAG:
            value->rValue = model->omiBSIM4wpvag; 
            return(OK);               
        case omiBSIM4_MOD_WWR:
            value->rValue = model->omiBSIM4wwr;
            return(OK);
        case omiBSIM4_MOD_WDWG:
            value->rValue = model->omiBSIM4wdwg;
            return(OK);
        case omiBSIM4_MOD_WDWB:
            value->rValue = model->omiBSIM4wdwb;
            return(OK);
        case omiBSIM4_MOD_WB0:
            value->rValue = model->omiBSIM4wb0;
            return(OK);
        case omiBSIM4_MOD_WB1:
            value->rValue = model->omiBSIM4wb1;
            return(OK);
        case omiBSIM4_MOD_WALPHA0:
            value->rValue = model->omiBSIM4walpha0;
            return(OK);
        case omiBSIM4_MOD_WALPHA1:
            value->rValue = model->omiBSIM4walpha1;
            return(OK);
        case omiBSIM4_MOD_WBETA0:
            value->rValue = model->omiBSIM4wbeta0;
            return(OK);
        case omiBSIM4_MOD_WAGIDL:
            value->rValue = model->omiBSIM4wagidl;
            return(OK);
        case omiBSIM4_MOD_WBGIDL:
            value->rValue = model->omiBSIM4wbgidl;
            return(OK);
        case omiBSIM4_MOD_WCGIDL:
            value->rValue = model->omiBSIM4wcgidl;
            return(OK);
        case omiBSIM4_MOD_WEGIDL:
            value->rValue = model->omiBSIM4wegidl;
            return(OK);
        case omiBSIM4_MOD_WFGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4wfgidl;
            return(OK);
        case omiBSIM4_MOD_WKGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4wkgidl;
            return(OK);
        case omiBSIM4_MOD_WRGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4wrgidl;
            return(OK);
        case omiBSIM4_MOD_WAGISL:
            value->rValue = model->omiBSIM4wagisl;
            return(OK);
        case omiBSIM4_MOD_WBGISL:
            value->rValue = model->omiBSIM4wbgisl;
            return(OK);
        case omiBSIM4_MOD_WCGISL:
            value->rValue = model->omiBSIM4wcgisl;
            return(OK);
        case omiBSIM4_MOD_WEGISL:
            value->rValue = model->omiBSIM4wegisl;
            return(OK);
        case omiBSIM4_MOD_WFGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4wfgisl;
            return(OK);
        case omiBSIM4_MOD_WKGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4wkgisl;
            return(OK);
        case omiBSIM4_MOD_WRGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4wrgisl;
            return(OK);
        case omiBSIM4_MOD_WAIGC:
            value->rValue = model->omiBSIM4waigc;
            return(OK);
        case omiBSIM4_MOD_WBIGC:
            value->rValue = model->omiBSIM4wbigc;
            return(OK);
        case omiBSIM4_MOD_WCIGC:
            value->rValue = model->omiBSIM4wcigc;
            return(OK);
        case omiBSIM4_MOD_WAIGSD:
            value->rValue = model->omiBSIM4waigsd;
            return(OK);
        case omiBSIM4_MOD_WBIGSD:
            value->rValue = model->omiBSIM4wbigsd;
            return(OK);
        case omiBSIM4_MOD_WCIGSD:
            value->rValue = model->omiBSIM4wcigsd;
            return(OK);
        case omiBSIM4_MOD_WAIGS:
            value->rValue = model->omiBSIM4waigs;
            return(OK);
        case omiBSIM4_MOD_WBIGS:
            value->rValue = model->omiBSIM4wbigs;
            return(OK);
        case omiBSIM4_MOD_WCIGS:
            value->rValue = model->omiBSIM4wcigs;
            return(OK);
        case omiBSIM4_MOD_WAIGD:
            value->rValue = model->omiBSIM4waigd;
            return(OK);
        case omiBSIM4_MOD_WBIGD:
            value->rValue = model->omiBSIM4wbigd;
            return(OK);
        case omiBSIM4_MOD_WCIGD:
            value->rValue = model->omiBSIM4wcigd;
            return(OK);
        case omiBSIM4_MOD_WAIGBACC:
            value->rValue = model->omiBSIM4waigbacc;
            return(OK);
        case omiBSIM4_MOD_WBIGBACC:
            value->rValue = model->omiBSIM4wbigbacc;
            return(OK);
        case omiBSIM4_MOD_WCIGBACC:
            value->rValue = model->omiBSIM4wcigbacc;
            return(OK);
        case omiBSIM4_MOD_WAIGBINV:
            value->rValue = model->omiBSIM4waigbinv;
            return(OK);
        case omiBSIM4_MOD_WBIGBINV:
            value->rValue = model->omiBSIM4wbigbinv;
            return(OK);
        case omiBSIM4_MOD_WCIGBINV:
            value->rValue = model->omiBSIM4wcigbinv;
            return(OK);
        case omiBSIM4_MOD_WNIGC:
            value->rValue = model->omiBSIM4wnigc;
            return(OK);
        case omiBSIM4_MOD_WNIGBACC:
            value->rValue = model->omiBSIM4wnigbacc;
            return(OK);
        case omiBSIM4_MOD_WNIGBINV:
            value->rValue = model->omiBSIM4wnigbinv;
            return(OK);
        case omiBSIM4_MOD_WNTOX:
            value->rValue = model->omiBSIM4wntox;
            return(OK);
        case omiBSIM4_MOD_WEIGBINV:
            value->rValue = model->omiBSIM4weigbinv;
            return(OK);
        case omiBSIM4_MOD_WPIGCD:
            value->rValue = model->omiBSIM4wpigcd;
            return(OK);
        case omiBSIM4_MOD_WPOXEDGE:
            value->rValue = model->omiBSIM4wpoxedge;
            return(OK);
        case omiBSIM4_MOD_WPHIN:
            value->rValue = model->omiBSIM4wphin;
            return(OK);
        case omiBSIM4_MOD_WXRCRG1:
            value->rValue = model->omiBSIM4wxrcrg1;
            return(OK);
        case omiBSIM4_MOD_WXRCRG2:
            value->rValue = model->omiBSIM4wxrcrg2;
            return(OK);
        case omiBSIM4_MOD_WEU:
            value->rValue = model->omiBSIM4weu;
            return(OK);
        case omiBSIM4_MOD_WUCS:
            value->rValue = model->omiBSIM4wucs;
            return(OK);
        case omiBSIM4_MOD_WVFB:
            value->rValue = model->omiBSIM4wvfb;
            return(OK);

        case omiBSIM4_MOD_WCGSL:
            value->rValue = model->omiBSIM4wcgsl;
            return(OK);
        case omiBSIM4_MOD_WCGDL:
            value->rValue = model->omiBSIM4wcgdl;
            return(OK);
        case omiBSIM4_MOD_WCKAPPAS:
            value->rValue = model->omiBSIM4wckappas;
            return(OK);
        case omiBSIM4_MOD_WCKAPPAD:
            value->rValue = model->omiBSIM4wckappad;
            return(OK);
        case omiBSIM4_MOD_WCF:
            value->rValue = model->omiBSIM4wcf;
            return(OK);
        case omiBSIM4_MOD_WCLC:
            value->rValue = model->omiBSIM4wclc;
            return(OK);
        case omiBSIM4_MOD_WCLE:
            value->rValue = model->omiBSIM4wcle;
            return(OK);
        case omiBSIM4_MOD_WVFBCV:
            value->rValue = model->omiBSIM4wvfbcv;
            return(OK);
        case omiBSIM4_MOD_WACDE:
            value->rValue = model->omiBSIM4wacde;
            return(OK);
        case omiBSIM4_MOD_WMOIN:
            value->rValue = model->omiBSIM4wmoin;
            return(OK);
        case omiBSIM4_MOD_WNOFF:
            value->rValue = model->omiBSIM4wnoff;
            return(OK);
        case omiBSIM4_MOD_WVOFFCV:
            value->rValue = model->omiBSIM4wvoffcv;
            return(OK);
        case omiBSIM4_MOD_WVFBSDOFF:
            value->rValue = model->omiBSIM4wvfbsdoff;
            return(OK);
        case omiBSIM4_MOD_WTVFBSDOFF:
            value->rValue = model->omiBSIM4wtvfbsdoff;
            return(OK);

        case omiBSIM4_MOD_WLAMBDA:
            value->rValue = model->omiBSIM4wlambda;
            return(OK);
        case omiBSIM4_MOD_WVTL:
            value->rValue = model->omiBSIM4wvtl;
            return(OK);
        case omiBSIM4_MOD_WXN:
            value->rValue = model->omiBSIM4wxn;
            return(OK);

	/* Cross-term dependence */
        case  omiBSIM4_MOD_PCDSC :
          value->rValue = model->omiBSIM4pcdsc;
            return(OK);
        case  omiBSIM4_MOD_PCDSCB :
          value->rValue = model->omiBSIM4pcdscb;
            return(OK);
        case  omiBSIM4_MOD_PCDSCD :
          value->rValue = model->omiBSIM4pcdscd;
            return(OK);
         case  omiBSIM4_MOD_PCIT :
          value->rValue = model->omiBSIM4pcit;
            return(OK);
        case  omiBSIM4_MOD_PNFACTOR :
          value->rValue = model->omiBSIM4pnfactor;
            return(OK);
        case omiBSIM4_MOD_PXJ:
            value->rValue = model->omiBSIM4pxj;
            return(OK);
        case omiBSIM4_MOD_PVSAT:
            value->rValue = model->omiBSIM4pvsat;
            return(OK);
        case omiBSIM4_MOD_PAT:
            value->rValue = model->omiBSIM4pat;
            return(OK);
        case omiBSIM4_MOD_PA0:
            value->rValue = model->omiBSIM4pa0;
            return(OK);
        case omiBSIM4_MOD_PAGS:
            value->rValue = model->omiBSIM4pags;
            return(OK);
        case omiBSIM4_MOD_PA1:
            value->rValue = model->omiBSIM4pa1;
            return(OK);
        case omiBSIM4_MOD_PA2:
            value->rValue = model->omiBSIM4pa2;
            return(OK);
        case omiBSIM4_MOD_PKETA:
            value->rValue = model->omiBSIM4pketa;
            return(OK);   
        case omiBSIM4_MOD_PNSUB:
            value->rValue = model->omiBSIM4pnsub;
            return(OK);
        case omiBSIM4_MOD_PNDEP:
            value->rValue = model->omiBSIM4pndep;
            return(OK);
        case omiBSIM4_MOD_PNSD:
            value->rValue = model->omiBSIM4pnsd;
            return(OK);
        case omiBSIM4_MOD_PNGATE:
            value->rValue = model->omiBSIM4pngate;
            return(OK);
        case omiBSIM4_MOD_PGAMMA1:
            value->rValue = model->omiBSIM4pgamma1;
            return(OK);
        case omiBSIM4_MOD_PGAMMA2:
            value->rValue = model->omiBSIM4pgamma2;
            return(OK);
        case omiBSIM4_MOD_PVBX:
            value->rValue = model->omiBSIM4pvbx;
            return(OK);
        case omiBSIM4_MOD_PVBM:
            value->rValue = model->omiBSIM4pvbm;
            return(OK);
        case omiBSIM4_MOD_PXT:
            value->rValue = model->omiBSIM4pxt;
            return(OK);
        case  omiBSIM4_MOD_PK1:
          value->rValue = model->omiBSIM4pk1;
            return(OK);
        case  omiBSIM4_MOD_PKT1:
          value->rValue = model->omiBSIM4pkt1;
            return(OK);
        case  omiBSIM4_MOD_PKT1L:
          value->rValue = model->omiBSIM4pkt1l;
            return(OK);
        case  omiBSIM4_MOD_PKT2 :
          value->rValue = model->omiBSIM4pkt2;
            return(OK);
        case  omiBSIM4_MOD_PK2 :
          value->rValue = model->omiBSIM4pk2;
            return(OK);
        case  omiBSIM4_MOD_PK3:
          value->rValue = model->omiBSIM4pk3;
            return(OK);
        case  omiBSIM4_MOD_PK3B:
          value->rValue = model->omiBSIM4pk3b;
            return(OK);
        case  omiBSIM4_MOD_PW0:
          value->rValue = model->omiBSIM4pw0;
            return(OK);
        case  omiBSIM4_MOD_PLPE0:
          value->rValue = model->omiBSIM4plpe0;
            return(OK);
        case  omiBSIM4_MOD_PLPEB:
          value->rValue = model->omiBSIM4plpeb;
            return(OK);
        case  omiBSIM4_MOD_PDVTP0:
          value->rValue = model->omiBSIM4pdvtp0;
            return(OK);
        case  omiBSIM4_MOD_PDVTP1:
          value->rValue = model->omiBSIM4pdvtp1;
            return(OK);
        case  omiBSIM4_MOD_PDVTP2:
          value->rValue = model->omiBSIM4pdvtp2;  /* New DIBL/Rout */
            return(OK);
        case  omiBSIM4_MOD_PDVTP3:
          value->rValue = model->omiBSIM4pdvtp3;
            return(OK);
        case  omiBSIM4_MOD_PDVTP4:
          value->rValue = model->omiBSIM4pdvtp4;
            return(OK);
        case  omiBSIM4_MOD_PDVTP5:
          value->rValue = model->omiBSIM4pdvtp5;
            return(OK);
        case  omiBSIM4_MOD_PDVT0 :                
          value->rValue = model->omiBSIM4pdvt0;
            return(OK);
        case  omiBSIM4_MOD_PDVT1 :             
          value->rValue = model->omiBSIM4pdvt1;
            return(OK);
        case  omiBSIM4_MOD_PDVT2 :             
          value->rValue = model->omiBSIM4pdvt2;
            return(OK);
        case  omiBSIM4_MOD_PDVT0W :                
          value->rValue = model->omiBSIM4pdvt0w;
            return(OK);
        case  omiBSIM4_MOD_PDVT1W :             
          value->rValue = model->omiBSIM4pdvt1w;
            return(OK);
        case  omiBSIM4_MOD_PDVT2W :             
          value->rValue = model->omiBSIM4pdvt2w;
            return(OK);
        case  omiBSIM4_MOD_PDROUT :           
          value->rValue = model->omiBSIM4pdrout;
            return(OK);
        case  omiBSIM4_MOD_PDSUB :           
          value->rValue = model->omiBSIM4pdsub;
            return(OK);
        case omiBSIM4_MOD_PVTH0:
            value->rValue = model->omiBSIM4pvth0; 
            return(OK);
        case omiBSIM4_MOD_PUA:
            value->rValue = model->omiBSIM4pua; 
            return(OK);
        case omiBSIM4_MOD_PUA1:
            value->rValue = model->omiBSIM4pua1; 
            return(OK);
        case omiBSIM4_MOD_PUB:
            value->rValue = model->omiBSIM4pub;  
            return(OK);
        case omiBSIM4_MOD_PUB1:
            value->rValue = model->omiBSIM4pub1;  
            return(OK);
        case omiBSIM4_MOD_PUC:
            value->rValue = model->omiBSIM4puc; 
            return(OK);
        case omiBSIM4_MOD_PUC1:
            value->rValue = model->omiBSIM4puc1; 
            return(OK);
        case omiBSIM4_MOD_PUD:
            value->rValue = model->omiBSIM4pud; 
            return(OK);
        case omiBSIM4_MOD_PUD1:
            value->rValue = model->omiBSIM4pud1; 
            return(OK);
        case omiBSIM4_MOD_PUP:
            value->rValue = model->omiBSIM4pup; 
            return(OK);
        case omiBSIM4_MOD_PLP:
            value->rValue = model->omiBSIM4plp; 
            return(OK);
        case omiBSIM4_MOD_PU0:
            value->rValue = model->omiBSIM4pu0;
            return(OK);
        case omiBSIM4_MOD_PUTE:
            value->rValue = model->omiBSIM4pute;
            return(OK);
        case omiBSIM4_MOD_PUCSTE:
            value->rValue = model->omiBSIM4pucste;
            return(OK);
        case omiBSIM4_MOD_PVOFF:
            value->rValue = model->omiBSIM4pvoff;
            return(OK);
        case omiBSIM4_MOD_PTVOFF:
            value->rValue = model->omiBSIM4ptvoff;
            return(OK);
        case omiBSIM4_MOD_PTNFACTOR:	/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4ptnfactor;
            return(OK);
        case omiBSIM4_MOD_PTETA0:		/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4pteta0;
            return(OK);
        case omiBSIM4_MOD_PTVOFFCV:	/* v4.7 temp dep of leakage current  */
            value->rValue = model->omiBSIM4ptvoffcv;
            return(OK);
        case omiBSIM4_MOD_PMINV:
            value->rValue = model->omiBSIM4pminv;
            return(OK);
        case omiBSIM4_MOD_PMINVCV:
            value->rValue = model->omiBSIM4pminvcv;
            return(OK);
        case omiBSIM4_MOD_PFPROUT:
            value->rValue = model->omiBSIM4pfprout;
            return(OK);
        case omiBSIM4_MOD_PPDITS:
            value->rValue = model->omiBSIM4ppdits;
            return(OK);
        case omiBSIM4_MOD_PPDITSD:
            value->rValue = model->omiBSIM4ppditsd;
            return(OK);
        case omiBSIM4_MOD_PDELTA:
            value->rValue = model->omiBSIM4pdelta;
            return(OK);
        case omiBSIM4_MOD_PRDSW:
            value->rValue = model->omiBSIM4prdsw; 
            return(OK);             
        case omiBSIM4_MOD_PRDW:
            value->rValue = model->omiBSIM4prdw;
            return(OK);
        case omiBSIM4_MOD_PRSW:
            value->rValue = model->omiBSIM4prsw;
            return(OK);
        case omiBSIM4_MOD_PPRWB:
            value->rValue = model->omiBSIM4pprwb; 
            return(OK);             
        case omiBSIM4_MOD_PPRWG:
            value->rValue = model->omiBSIM4pprwg; 
            return(OK);             
        case omiBSIM4_MOD_PPRT:
            value->rValue = model->omiBSIM4pprt; 
            return(OK);              
        case omiBSIM4_MOD_PETA0:
            value->rValue = model->omiBSIM4peta0; 
            return(OK);               
        case omiBSIM4_MOD_PETAB:
            value->rValue = model->omiBSIM4petab; 
            return(OK);               
        case omiBSIM4_MOD_PPCLM:
            value->rValue = model->omiBSIM4ppclm; 
            return(OK);               
        case omiBSIM4_MOD_PPDIBL1:
            value->rValue = model->omiBSIM4ppdibl1; 
            return(OK);               
        case omiBSIM4_MOD_PPDIBL2:
            value->rValue = model->omiBSIM4ppdibl2; 
            return(OK);               
        case omiBSIM4_MOD_PPDIBLB:
            value->rValue = model->omiBSIM4ppdiblb; 
            return(OK);               
        case omiBSIM4_MOD_PPSCBE1:
            value->rValue = model->omiBSIM4ppscbe1; 
            return(OK);               
        case omiBSIM4_MOD_PPSCBE2:
            value->rValue = model->omiBSIM4ppscbe2; 
            return(OK);               
        case omiBSIM4_MOD_PPVAG:
            value->rValue = model->omiBSIM4ppvag; 
            return(OK);               
        case omiBSIM4_MOD_PWR:
            value->rValue = model->omiBSIM4pwr;
            return(OK);
        case omiBSIM4_MOD_PDWG:
            value->rValue = model->omiBSIM4pdwg;
            return(OK);
        case omiBSIM4_MOD_PDWB:
            value->rValue = model->omiBSIM4pdwb;
            return(OK);
        case omiBSIM4_MOD_PB0:
            value->rValue = model->omiBSIM4pb0;
            return(OK);
        case omiBSIM4_MOD_PB1:
            value->rValue = model->omiBSIM4pb1;
            return(OK);
        case omiBSIM4_MOD_PALPHA0:
            value->rValue = model->omiBSIM4palpha0;
            return(OK);
        case omiBSIM4_MOD_PALPHA1:
            value->rValue = model->omiBSIM4palpha1;
            return(OK);
        case omiBSIM4_MOD_PBETA0:
            value->rValue = model->omiBSIM4pbeta0;
            return(OK);
        case omiBSIM4_MOD_PAGIDL:
            value->rValue = model->omiBSIM4pagidl;
            return(OK);
        case omiBSIM4_MOD_PBGIDL:
            value->rValue = model->omiBSIM4pbgidl;
            return(OK);
        case omiBSIM4_MOD_PCGIDL:
            value->rValue = model->omiBSIM4pcgidl;
            return(OK);
        case omiBSIM4_MOD_PEGIDL:
            value->rValue = model->omiBSIM4pegidl;
            return(OK);
        case omiBSIM4_MOD_PFGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4pfgidl;
            return(OK);
        case omiBSIM4_MOD_PKGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4pkgidl;
            return(OK);
        case omiBSIM4_MOD_PRGIDL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4prgidl;
            return(OK);
        case omiBSIM4_MOD_PAGISL:
            value->rValue = model->omiBSIM4pagisl;
            return(OK);
        case omiBSIM4_MOD_PBGISL:
            value->rValue = model->omiBSIM4pbgisl;
            return(OK);
        case omiBSIM4_MOD_PCGISL:
            value->rValue = model->omiBSIM4pcgisl;
            return(OK);
        case omiBSIM4_MOD_PEGISL:
            value->rValue = model->omiBSIM4pegisl;
            return(OK);
        case omiBSIM4_MOD_PFGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4pfgisl;
            return(OK);
        case omiBSIM4_MOD_PKGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4pkgisl;
            return(OK);
        case omiBSIM4_MOD_PRGISL:			/* v4.7 New GIDL/GISL*/
            value->rValue = model->omiBSIM4prgisl;
            return(OK);
        case omiBSIM4_MOD_PAIGC:
            value->rValue = model->omiBSIM4paigc;
            return(OK);
        case omiBSIM4_MOD_PBIGC:
            value->rValue = model->omiBSIM4pbigc;
            return(OK);
        case omiBSIM4_MOD_PCIGC:
            value->rValue = model->omiBSIM4pcigc;
            return(OK);
        case omiBSIM4_MOD_PAIGSD:
            value->rValue = model->omiBSIM4paigsd;
            return(OK);
        case omiBSIM4_MOD_PBIGSD:
            value->rValue = model->omiBSIM4pbigsd;
            return(OK);
        case omiBSIM4_MOD_PCIGSD:
            value->rValue = model->omiBSIM4pcigsd;
            return(OK);
        case omiBSIM4_MOD_PAIGS:
            value->rValue = model->omiBSIM4paigs;
            return(OK);
        case omiBSIM4_MOD_PBIGS:
            value->rValue = model->omiBSIM4pbigs;
            return(OK);
        case omiBSIM4_MOD_PCIGS:
            value->rValue = model->omiBSIM4pcigs;
            return(OK);
        case omiBSIM4_MOD_PAIGD:
            value->rValue = model->omiBSIM4paigd;
            return(OK);
        case omiBSIM4_MOD_PBIGD:
            value->rValue = model->omiBSIM4pbigd;
            return(OK);
        case omiBSIM4_MOD_PCIGD:
            value->rValue = model->omiBSIM4pcigd;
            return(OK);
        case omiBSIM4_MOD_PAIGBACC:
            value->rValue = model->omiBSIM4paigbacc;
            return(OK);
        case omiBSIM4_MOD_PBIGBACC:
            value->rValue = model->omiBSIM4pbigbacc;
            return(OK);
        case omiBSIM4_MOD_PCIGBACC:
            value->rValue = model->omiBSIM4pcigbacc;
            return(OK);
        case omiBSIM4_MOD_PAIGBINV:
            value->rValue = model->omiBSIM4paigbinv;
            return(OK);
        case omiBSIM4_MOD_PBIGBINV:
            value->rValue = model->omiBSIM4pbigbinv;
            return(OK);
        case omiBSIM4_MOD_PCIGBINV:
            value->rValue = model->omiBSIM4pcigbinv;
            return(OK);
        case omiBSIM4_MOD_PNIGC:
            value->rValue = model->omiBSIM4pnigc;
            return(OK);
        case omiBSIM4_MOD_PNIGBACC:
            value->rValue = model->omiBSIM4pnigbacc;
            return(OK);
        case omiBSIM4_MOD_PNIGBINV:
            value->rValue = model->omiBSIM4pnigbinv;
            return(OK);
        case omiBSIM4_MOD_PNTOX:
            value->rValue = model->omiBSIM4pntox;
            return(OK);
        case omiBSIM4_MOD_PEIGBINV:
            value->rValue = model->omiBSIM4peigbinv;
            return(OK);
        case omiBSIM4_MOD_PPIGCD:
            value->rValue = model->omiBSIM4ppigcd;
            return(OK);
        case omiBSIM4_MOD_PPOXEDGE:
            value->rValue = model->omiBSIM4ppoxedge;
            return(OK);
        case omiBSIM4_MOD_PPHIN:
            value->rValue = model->omiBSIM4pphin;
            return(OK);
        case omiBSIM4_MOD_PXRCRG1:
            value->rValue = model->omiBSIM4pxrcrg1;
            return(OK);
        case omiBSIM4_MOD_PXRCRG2:
            value->rValue = model->omiBSIM4pxrcrg2;
            return(OK);
        case omiBSIM4_MOD_PEU:
            value->rValue = model->omiBSIM4peu;
            return(OK);
        case omiBSIM4_MOD_PUCS:
            value->rValue = model->omiBSIM4pucs;
            return(OK);
        case omiBSIM4_MOD_PVFB:
            value->rValue = model->omiBSIM4pvfb;
            return(OK);

        case omiBSIM4_MOD_PCGSL:
            value->rValue = model->omiBSIM4pcgsl;
            return(OK);
        case omiBSIM4_MOD_PCGDL:
            value->rValue = model->omiBSIM4pcgdl;
            return(OK);
        case omiBSIM4_MOD_PCKAPPAS:
            value->rValue = model->omiBSIM4pckappas;
            return(OK);
        case omiBSIM4_MOD_PCKAPPAD:
            value->rValue = model->omiBSIM4pckappad;
            return(OK);
        case omiBSIM4_MOD_PCF:
            value->rValue = model->omiBSIM4pcf;
            return(OK);
        case omiBSIM4_MOD_PCLC:
            value->rValue = model->omiBSIM4pclc;
            return(OK);
        case omiBSIM4_MOD_PCLE:
            value->rValue = model->omiBSIM4pcle;
            return(OK);
        case omiBSIM4_MOD_PVFBCV:
            value->rValue = model->omiBSIM4pvfbcv;
            return(OK);
        case omiBSIM4_MOD_PACDE:
            value->rValue = model->omiBSIM4pacde;
            return(OK);
        case omiBSIM4_MOD_PMOIN:
            value->rValue = model->omiBSIM4pmoin;
            return(OK);
        case omiBSIM4_MOD_PNOFF:
            value->rValue = model->omiBSIM4pnoff;
            return(OK);
        case omiBSIM4_MOD_PVOFFCV:
            value->rValue = model->omiBSIM4pvoffcv;
            return(OK);
        case omiBSIM4_MOD_PVFBSDOFF:
            value->rValue = model->omiBSIM4pvfbsdoff;
            return(OK);
        case omiBSIM4_MOD_PTVFBSDOFF:
            value->rValue = model->omiBSIM4ptvfbsdoff;
            return(OK);

        case omiBSIM4_MOD_PLAMBDA:
            value->rValue = model->omiBSIM4plambda;
            return(OK);
        case omiBSIM4_MOD_PVTL:
            value->rValue = model->omiBSIM4pvtl;
            return(OK);
        case omiBSIM4_MOD_PXN:
            value->rValue = model->omiBSIM4pxn;
            return(OK);

        case  omiBSIM4_MOD_TNOM :
          value->rValue = model->omiBSIM4tnom;
            return(OK);
        case omiBSIM4_MOD_CGSO:
            value->rValue = model->omiBSIM4cgso; 
            return(OK);
        case omiBSIM4_MOD_CGDO:
            value->rValue = model->omiBSIM4cgdo; 
            return(OK);
        case omiBSIM4_MOD_CGBO:
            value->rValue = model->omiBSIM4cgbo; 
            return(OK);
        case omiBSIM4_MOD_XPART:
            value->rValue = model->omiBSIM4xpart; 
            return(OK);
        case omiBSIM4_MOD_RSH:
            value->rValue = model->omiBSIM4sheetResistance; 
            return(OK);
        case omiBSIM4_MOD_JSS:
            value->rValue = model->omiBSIM4SjctSatCurDensity; 
            return(OK);
        case omiBSIM4_MOD_JSWS:
            value->rValue = model->omiBSIM4SjctSidewallSatCurDensity; 
            return(OK);
        case omiBSIM4_MOD_JSWGS:
            value->rValue = model->omiBSIM4SjctGateSidewallSatCurDensity;
            return(OK);
        case omiBSIM4_MOD_PBS:
            value->rValue = model->omiBSIM4SbulkJctPotential; 
            return(OK);
        case omiBSIM4_MOD_MJS:
            value->rValue = model->omiBSIM4SbulkJctBotGradingCoeff; 
            return(OK);
        case omiBSIM4_MOD_PBSWS:
            value->rValue = model->omiBSIM4SsidewallJctPotential; 
            return(OK);
        case omiBSIM4_MOD_MJSWS:
            value->rValue = model->omiBSIM4SbulkJctSideGradingCoeff; 
            return(OK);
        case omiBSIM4_MOD_CJS:
            value->rValue = model->omiBSIM4SunitAreaJctCap; 
            return(OK);
        case omiBSIM4_MOD_CJSWS:
            value->rValue = model->omiBSIM4SunitLengthSidewallJctCap; 
            return(OK);
        case omiBSIM4_MOD_PBSWGS:
            value->rValue = model->omiBSIM4SGatesidewallJctPotential; 
            return(OK);
        case omiBSIM4_MOD_MJSWGS:
            value->rValue = model->omiBSIM4SbulkJctGateSideGradingCoeff; 
            return(OK);
        case omiBSIM4_MOD_CJSWGS:
            value->rValue = model->omiBSIM4SunitLengthGateSidewallJctCap; 
            return(OK);
        case omiBSIM4_MOD_NJS:
            value->rValue = model->omiBSIM4SjctEmissionCoeff; 
            return(OK);
        case omiBSIM4_MOD_XTIS:
            value->rValue = model->omiBSIM4SjctTempExponent; 
            return(OK);
        case omiBSIM4_MOD_JSD:
            value->rValue = model->omiBSIM4DjctSatCurDensity;
            return(OK);
        case omiBSIM4_MOD_JSWD:
            value->rValue = model->omiBSIM4DjctSidewallSatCurDensity;
            return(OK);
        case omiBSIM4_MOD_JSWGD:
            value->rValue = model->omiBSIM4DjctGateSidewallSatCurDensity;
            return(OK);
        case omiBSIM4_MOD_PBD:
            value->rValue = model->omiBSIM4DbulkJctPotential;
            return(OK);
        case omiBSIM4_MOD_MJD:
            value->rValue = model->omiBSIM4DbulkJctBotGradingCoeff;
            return(OK);
        case omiBSIM4_MOD_PBSWD:
            value->rValue = model->omiBSIM4DsidewallJctPotential;
            return(OK);
        case omiBSIM4_MOD_MJSWD:
            value->rValue = model->omiBSIM4DbulkJctSideGradingCoeff;
            return(OK);
        case omiBSIM4_MOD_CJD:
            value->rValue = model->omiBSIM4DunitAreaJctCap;
            return(OK);
        case omiBSIM4_MOD_CJSWD:
            value->rValue = model->omiBSIM4DunitLengthSidewallJctCap;
            return(OK);
        case omiBSIM4_MOD_PBSWGD:
            value->rValue = model->omiBSIM4DGatesidewallJctPotential;
            return(OK);
        case omiBSIM4_MOD_MJSWGD:
            value->rValue = model->omiBSIM4DbulkJctGateSideGradingCoeff;
            return(OK);
        case omiBSIM4_MOD_CJSWGD:
            value->rValue = model->omiBSIM4DunitLengthGateSidewallJctCap;
            return(OK);
        case omiBSIM4_MOD_NJD:
            value->rValue = model->omiBSIM4DjctEmissionCoeff;
            return(OK);
        case omiBSIM4_MOD_XTID:
            value->rValue = model->omiBSIM4DjctTempExponent;
            return(OK);
        case omiBSIM4_MOD_LINTNOI:
            value->rValue = model->omiBSIM4lintnoi; 
            return(OK);
        case omiBSIM4_MOD_LINT:
            value->rValue = model->omiBSIM4Lint; 
            return(OK);
        case omiBSIM4_MOD_LL:
            value->rValue = model->omiBSIM4Ll;
            return(OK);
        case omiBSIM4_MOD_LLC:
            value->rValue = model->omiBSIM4Llc;
            return(OK);
        case omiBSIM4_MOD_LLN:
            value->rValue = model->omiBSIM4Lln;
            return(OK);
        case omiBSIM4_MOD_LW:
            value->rValue = model->omiBSIM4Lw;
            return(OK);
        case omiBSIM4_MOD_LWC:
            value->rValue = model->omiBSIM4Lwc;
            return(OK);
        case omiBSIM4_MOD_LWN:
            value->rValue = model->omiBSIM4Lwn;
            return(OK);
        case omiBSIM4_MOD_LWL:
            value->rValue = model->omiBSIM4Lwl;
            return(OK);
        case omiBSIM4_MOD_LWLC:
            value->rValue = model->omiBSIM4Lwlc;
            return(OK);
        case omiBSIM4_MOD_LMIN:
            value->rValue = model->omiBSIM4Lmin;
            return(OK);
        case omiBSIM4_MOD_LMAX:
            value->rValue = model->omiBSIM4Lmax;
            return(OK);
        case omiBSIM4_MOD_WINT:
            value->rValue = model->omiBSIM4Wint;
            return(OK);
        case omiBSIM4_MOD_WL:
            value->rValue = model->omiBSIM4Wl;
            return(OK);
        case omiBSIM4_MOD_WLC:
            value->rValue = model->omiBSIM4Wlc;
            return(OK);
        case omiBSIM4_MOD_WLN:
            value->rValue = model->omiBSIM4Wln;
            return(OK);
        case omiBSIM4_MOD_WW:
            value->rValue = model->omiBSIM4Ww;
            return(OK);
        case omiBSIM4_MOD_WWC:
            value->rValue = model->omiBSIM4Wwc;
            return(OK);
        case omiBSIM4_MOD_WWN:
            value->rValue = model->omiBSIM4Wwn;
            return(OK);
        case omiBSIM4_MOD_WWL:
            value->rValue = model->omiBSIM4Wwl;
            return(OK);
        case omiBSIM4_MOD_WWLC:
            value->rValue = model->omiBSIM4Wwlc;
            return(OK);
        case omiBSIM4_MOD_WMIN:
            value->rValue = model->omiBSIM4Wmin;
            return(OK);
        case omiBSIM4_MOD_WMAX:
            value->rValue = model->omiBSIM4Wmax;
            return(OK);

        /* stress effect */
        case omiBSIM4_MOD_SAREF:
            value->rValue = model->omiBSIM4saref;
            return(OK);
        case omiBSIM4_MOD_SBREF:
            value->rValue = model->omiBSIM4sbref;
            return(OK);
        case omiBSIM4_MOD_WLOD:
            value->rValue = model->omiBSIM4wlod;
            return(OK);
        case omiBSIM4_MOD_KU0:
            value->rValue = model->omiBSIM4ku0;
            return(OK);
        case omiBSIM4_MOD_KVSAT:
            value->rValue = model->omiBSIM4kvsat;
            return(OK);
        case omiBSIM4_MOD_KVTH0:
            value->rValue = model->omiBSIM4kvth0;
            return(OK);
        case omiBSIM4_MOD_TKU0:
            value->rValue = model->omiBSIM4tku0;
            return(OK);
        case omiBSIM4_MOD_LLODKU0:
            value->rValue = model->omiBSIM4llodku0;
            return(OK);
        case omiBSIM4_MOD_WLODKU0:
            value->rValue = model->omiBSIM4wlodku0;
            return(OK);
        case omiBSIM4_MOD_LLODVTH:
            value->rValue = model->omiBSIM4llodvth;
            return(OK);
        case omiBSIM4_MOD_WLODVTH:
            value->rValue = model->omiBSIM4wlodvth;
            return(OK);
        case omiBSIM4_MOD_LKU0:
            value->rValue = model->omiBSIM4lku0;
            return(OK);
        case omiBSIM4_MOD_WKU0:
            value->rValue = model->omiBSIM4wku0;
            return(OK);
        case omiBSIM4_MOD_PKU0:
            value->rValue = model->omiBSIM4pku0;
            return(OK);
        case omiBSIM4_MOD_LKVTH0:
            value->rValue = model->omiBSIM4lkvth0;
            return(OK);
        case omiBSIM4_MOD_WKVTH0:
            value->rValue = model->omiBSIM4wkvth0;
            return(OK);
        case omiBSIM4_MOD_PKVTH0:
            value->rValue = model->omiBSIM4pkvth0;
            return(OK);
        case omiBSIM4_MOD_STK2:
            value->rValue = model->omiBSIM4stk2;
            return(OK);
        case omiBSIM4_MOD_LODK2:
            value->rValue = model->omiBSIM4lodk2;
            return(OK);
        case omiBSIM4_MOD_STETA0:
            value->rValue = model->omiBSIM4steta0;
            return(OK);
        case omiBSIM4_MOD_LODETA0:
            value->rValue = model->omiBSIM4lodeta0;
            return(OK);

        /* Well Proximity Effect  */
        case omiBSIM4_MOD_WEB:
            value->rValue = model->omiBSIM4web;
            return(OK);
        case omiBSIM4_MOD_WEC:
            value->rValue = model->omiBSIM4wec;
            return(OK);
        case omiBSIM4_MOD_KVTH0WE:
            value->rValue = model->omiBSIM4kvth0we;
            return(OK);
        case omiBSIM4_MOD_K2WE:
            value->rValue = model->omiBSIM4k2we;
            return(OK);
        case omiBSIM4_MOD_KU0WE:
            value->rValue = model->omiBSIM4ku0we;
            return(OK);
        case omiBSIM4_MOD_SCREF:
            value->rValue = model->omiBSIM4scref;
            return(OK);
        case omiBSIM4_MOD_WPEMOD:
            value->rValue = model->omiBSIM4wpemod;
            return(OK);
        case omiBSIM4_MOD_LKVTH0WE:
            value->rValue = model->omiBSIM4lkvth0we;
            return(OK);
        case omiBSIM4_MOD_LK2WE:
            value->rValue = model->omiBSIM4lk2we;
            return(OK);
        case omiBSIM4_MOD_LKU0WE:
            value->rValue = model->omiBSIM4lku0we;
            return(OK);
        case omiBSIM4_MOD_WKVTH0WE:
            value->rValue = model->omiBSIM4wkvth0we;
            return(OK);
        case omiBSIM4_MOD_WK2WE:
            value->rValue = model->omiBSIM4wk2we;
            return(OK);
        case omiBSIM4_MOD_WKU0WE:
            value->rValue = model->omiBSIM4wku0we;
            return(OK);
        case omiBSIM4_MOD_PKVTH0WE:
            value->rValue = model->omiBSIM4pkvth0we;
            return(OK);
        case omiBSIM4_MOD_PK2WE:
            value->rValue = model->omiBSIM4pk2we;
            return(OK);
        case omiBSIM4_MOD_PKU0WE:
            value->rValue = model->omiBSIM4pku0we;
            return(OK);

        case omiBSIM4_MOD_NOIA:
            value->rValue = model->omiBSIM4oxideTrapDensityA;
            return(OK);
        case omiBSIM4_MOD_NOIB:
            value->rValue = model->omiBSIM4oxideTrapDensityB;
            return(OK);
        case omiBSIM4_MOD_NOIC:
            value->rValue = model->omiBSIM4oxideTrapDensityC;
            return(OK);
        case omiBSIM4_MOD_EM:
            value->rValue = model->omiBSIM4em;
            return(OK);
        case omiBSIM4_MOD_EF:
            value->rValue = model->omiBSIM4ef;
            return(OK);
        case omiBSIM4_MOD_AF:
            value->rValue = model->omiBSIM4af;
            return(OK);
        case omiBSIM4_MOD_KF:
            value->rValue = model->omiBSIM4kf;
            return(OK);

        case omiBSIM4_MOD_VGS_MAX:
            value->rValue = model->omiBSIM4vgsMax;
            return(OK);
        case omiBSIM4_MOD_VGD_MAX:
            value->rValue = model->omiBSIM4vgdMax;
            return(OK);
        case omiBSIM4_MOD_VGB_MAX:
            value->rValue = model->omiBSIM4vgbMax;
            return(OK);
        case omiBSIM4_MOD_VDS_MAX:
            value->rValue = model->omiBSIM4vdsMax;
            return(OK);
        case omiBSIM4_MOD_VBS_MAX:
            value->rValue = model->omiBSIM4vbsMax;
            return(OK);
        case omiBSIM4_MOD_VBD_MAX:
            value->rValue = model->omiBSIM4vbdMax;
            return(OK);
        case omiBSIM4_MOD_VGSR_MAX:
            value->rValue = model->omiBSIM4vgsrMax;
            return(OK);
        case omiBSIM4_MOD_VGDR_MAX:
            value->rValue = model->omiBSIM4vgdrMax;
            return(OK);
        case omiBSIM4_MOD_VGBR_MAX:
            value->rValue = model->omiBSIM4vgbrMax;
            return(OK);
        case omiBSIM4_MOD_VBSR_MAX:
            value->rValue = model->omiBSIM4vbsrMax;
            return(OK);
        case omiBSIM4_MOD_VBDR_MAX:
            value->rValue = model->omiBSIM4vbdrMax;
            return(OK);

        default:
            return(E_BADPARM);
    }
    /* NOTREACHED */
}



