/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4mpar.c of BSIM4.7.0.
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
 * Modified by Mohan Dunga, 12/13/2006
 * Modified by Mohan Dunga, Wenwei Yang, 05/18/2007.
 * Modified by Wenwei Yang, 07/31/2008.
 * Modified by Tanvir Morshed, Darsen Lu 03/27/2011
 **********/

#include "ngspice/ngspice.h"
#include "omibsim4def.h"
#include "ngspice/ifsim.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"
#include "ngspice/const.h"

int
omiBSIM4mParam(
int param,
IFvalue *value,
GENmodel *inMod)
{
    omiBSIM4model *mod = (omiBSIM4model*)inMod;
    
    switch (param) {
      case omiBSIM4_MOD_MOBMOD:
        mod->omiBSIM4mobMod = value->iValue;
        mod->omiBSIM4mobModGiven = TRUE;
        break;
      case omiBSIM4_MOD_BINUNIT:
        mod->omiBSIM4binUnit = value->iValue;
        mod->omiBSIM4binUnitGiven = TRUE;
        break;
      case omiBSIM4_MOD_PARAMCHK:
        mod->omiBSIM4paramChk = value->iValue;
        mod->omiBSIM4paramChkGiven = TRUE;
        break;
      case omiBSIM4_MOD_CVCHARGEMOD:
        mod->omiBSIM4cvchargeMod = value->iValue;
        mod->omiBSIM4cvchargeModGiven = TRUE;
        break;
      case omiBSIM4_MOD_CAPMOD:
        mod->omiBSIM4capMod = value->iValue;
        mod->omiBSIM4capModGiven = TRUE;
        break;
      case omiBSIM4_MOD_DIOMOD:
        mod->omiBSIM4dioMod = value->iValue;
        mod->omiBSIM4dioModGiven = TRUE;
        break;
      case omiBSIM4_MOD_RDSMOD:
        mod->omiBSIM4rdsMod = value->iValue;
        mod->omiBSIM4rdsModGiven = TRUE;
        break;
      case omiBSIM4_MOD_TRNQSMOD:
        mod->omiBSIM4trnqsMod = value->iValue;
        mod->omiBSIM4trnqsModGiven = TRUE;
        break;
      case omiBSIM4_MOD_ACNQSMOD:
        mod->omiBSIM4acnqsMod = value->iValue;
        mod->omiBSIM4acnqsModGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBODYMOD:
        mod->omiBSIM4rbodyMod = value->iValue;
        mod->omiBSIM4rbodyModGiven = TRUE;
        break;
      case omiBSIM4_MOD_RGATEMOD:
        mod->omiBSIM4rgateMod = value->iValue;
        mod->omiBSIM4rgateModGiven = TRUE;
        break;
      case omiBSIM4_MOD_PERMOD:
        mod->omiBSIM4perMod = value->iValue;
        mod->omiBSIM4perModGiven = TRUE;
        break;
      case omiBSIM4_MOD_GEOMOD:
        mod->omiBSIM4geoMod = value->iValue;
        mod->omiBSIM4geoModGiven = TRUE;
        break;
      case omiBSIM4_MOD_RGEOMOD:
        mod->omiBSIM4rgeoMod = value->iValue;
        mod->omiBSIM4rgeoModGiven = TRUE;
        break;
      case omiBSIM4_MOD_FNOIMOD:
        mod->omiBSIM4fnoiMod = value->iValue;
        mod->omiBSIM4fnoiModGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNOIMOD:
        mod->omiBSIM4tnoiMod = value->iValue;
        mod->omiBSIM4tnoiModGiven = TRUE;
        break;
      case omiBSIM4_MOD_MTRLMOD:
        mod->omiBSIM4mtrlMod = value->iValue;
        mod->omiBSIM4mtrlModGiven = TRUE;
        break;
      case omiBSIM4_MOD_MTRLCOMPATMOD:
        mod->omiBSIM4mtrlCompatMod = value->iValue;
        mod->omiBSIM4mtrlCompatModGiven = TRUE;
        break;
      case omiBSIM4_MOD_GIDLMOD: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4gidlMod = value->iValue;
        mod->omiBSIM4gidlModGiven = TRUE;
        break;
      case omiBSIM4_MOD_IGCMOD:
        mod->omiBSIM4igcMod = value->iValue;
        mod->omiBSIM4igcModGiven = TRUE;
        break;
      case omiBSIM4_MOD_IGBMOD:
        mod->omiBSIM4igbMod = value->iValue;
        mod->omiBSIM4igbModGiven = TRUE;
        break;
      case omiBSIM4_MOD_TEMPMOD:
        mod->omiBSIM4tempMod = value->iValue;
        mod->omiBSIM4tempModGiven = TRUE;
        break;

      case omiBSIM4_MOD_VERSION:
        mod->omiBSIM4version = value->sValue;
        mod->omiBSIM4versionGiven = TRUE;
        break;
      case omiBSIM4_MOD_TOXREF:
        mod->omiBSIM4toxref = value->rValue;
        mod->omiBSIM4toxrefGiven = TRUE;
        break;
      case omiBSIM4_MOD_EOT:
        mod->omiBSIM4eot = value->rValue;
        mod->omiBSIM4eotGiven = TRUE;
        break;
      case omiBSIM4_MOD_VDDEOT:
        mod->omiBSIM4vddeot = value->rValue;
        mod->omiBSIM4vddeotGiven = TRUE;
        break;
      case omiBSIM4_MOD_TEMPEOT:
        mod->omiBSIM4tempeot = value->rValue;
        mod->omiBSIM4tempeotGiven = TRUE;
        break;
      case omiBSIM4_MOD_LEFFEOT:
        mod->omiBSIM4leffeot = value->rValue;
        mod->omiBSIM4leffeotGiven = TRUE;
        break;
      case omiBSIM4_MOD_WEFFEOT:
        mod->omiBSIM4weffeot = value->rValue;
        mod->omiBSIM4weffeotGiven = TRUE;
        break;
      case omiBSIM4_MOD_ADOS:
        mod->omiBSIM4ados = value->rValue;
        mod->omiBSIM4adosGiven = TRUE;
        break;
      case omiBSIM4_MOD_BDOS:
        mod->omiBSIM4bdos = value->rValue;
        mod->omiBSIM4bdosGiven = TRUE;
        break;
      case omiBSIM4_MOD_TOXE:
        mod->omiBSIM4toxe = value->rValue;
        mod->omiBSIM4toxeGiven = TRUE;
        break;
      case omiBSIM4_MOD_TOXP:
        mod->omiBSIM4toxp = value->rValue;
        mod->omiBSIM4toxpGiven = TRUE;
        break;
      case omiBSIM4_MOD_TOXM:
        mod->omiBSIM4toxm = value->rValue;
        mod->omiBSIM4toxmGiven = TRUE;
        break;
      case omiBSIM4_MOD_DTOX:
        mod->omiBSIM4dtox = value->rValue;
        mod->omiBSIM4dtoxGiven = TRUE;
        break;
      case omiBSIM4_MOD_EPSROX:
        mod->omiBSIM4epsrox = value->rValue;
        mod->omiBSIM4epsroxGiven = TRUE;
        break;

      case omiBSIM4_MOD_CDSC:
        mod->omiBSIM4cdsc = value->rValue;
        mod->omiBSIM4cdscGiven = TRUE;
        break;
      case omiBSIM4_MOD_CDSCB:
        mod->omiBSIM4cdscb = value->rValue;
        mod->omiBSIM4cdscbGiven = TRUE;
        break;

      case omiBSIM4_MOD_CDSCD:
        mod->omiBSIM4cdscd = value->rValue;
        mod->omiBSIM4cdscdGiven = TRUE;
        break;

      case omiBSIM4_MOD_CIT:
        mod->omiBSIM4cit = value->rValue;
        mod->omiBSIM4citGiven = TRUE;
        break;
      case omiBSIM4_MOD_NFACTOR:
        mod->omiBSIM4nfactor = value->rValue;
        mod->omiBSIM4nfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_XJ:
        mod->omiBSIM4xj = value->rValue;
        mod->omiBSIM4xjGiven = TRUE;
        break;
      case omiBSIM4_MOD_VSAT:
        mod->omiBSIM4vsat = value->rValue;
        mod->omiBSIM4vsatGiven = TRUE;
        break;
      case omiBSIM4_MOD_A0:
        mod->omiBSIM4a0 = value->rValue;
        mod->omiBSIM4a0Given = TRUE;
        break;

      case omiBSIM4_MOD_AGS:
        mod->omiBSIM4ags = value->rValue;
        mod->omiBSIM4agsGiven = TRUE;
        break;

      case omiBSIM4_MOD_A1:
        mod->omiBSIM4a1 = value->rValue;
        mod->omiBSIM4a1Given = TRUE;
        break;
      case omiBSIM4_MOD_A2:
        mod->omiBSIM4a2 = value->rValue;
        mod->omiBSIM4a2Given = TRUE;
        break;
      case omiBSIM4_MOD_AT:
        mod->omiBSIM4at = value->rValue;
        mod->omiBSIM4atGiven = TRUE;
        break;
      case omiBSIM4_MOD_KETA:
        mod->omiBSIM4keta = value->rValue;
        mod->omiBSIM4ketaGiven = TRUE;
        break;
      case omiBSIM4_MOD_NSUB:
        mod->omiBSIM4nsub = value->rValue;
        mod->omiBSIM4nsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_PHIG:
        mod->omiBSIM4phig = value->rValue;
        mod->omiBSIM4phigGiven = TRUE;
        break;
      case omiBSIM4_MOD_EPSRGATE:
        mod->omiBSIM4epsrgate = value->rValue;
        mod->omiBSIM4epsrgateGiven = TRUE;
        break;
      case omiBSIM4_MOD_EASUB:
        mod->omiBSIM4easub = value->rValue;
        mod->omiBSIM4easubGiven = TRUE;
        break;
      case omiBSIM4_MOD_EPSRSUB:
        mod->omiBSIM4epsrsub = value->rValue;
        mod->omiBSIM4epsrsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_NI0SUB:
        mod->omiBSIM4ni0sub = value->rValue;
        mod->omiBSIM4ni0subGiven = TRUE;
        break;
      case omiBSIM4_MOD_BG0SUB:
        mod->omiBSIM4bg0sub = value->rValue;
        mod->omiBSIM4bg0subGiven = TRUE;
        break;
      case omiBSIM4_MOD_TBGASUB:
        mod->omiBSIM4tbgasub = value->rValue;
        mod->omiBSIM4tbgasubGiven = TRUE;
        break;
      case omiBSIM4_MOD_TBGBSUB:
        mod->omiBSIM4tbgbsub = value->rValue;
        mod->omiBSIM4tbgbsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_NDEP:
        mod->omiBSIM4ndep = value->rValue;
        mod->omiBSIM4ndepGiven = TRUE;
        if (mod->omiBSIM4ndep > 1.0e20) mod->omiBSIM4ndep *= 1.0e-6;
        break;
      case omiBSIM4_MOD_NSD:
        mod->omiBSIM4nsd = value->rValue;
        mod->omiBSIM4nsdGiven = TRUE;
        if (mod->omiBSIM4nsd > 1.000001e24) mod->omiBSIM4nsd *= 1.0e-6;
        break;
      case omiBSIM4_MOD_NGATE:
        mod->omiBSIM4ngate = value->rValue;
        mod->omiBSIM4ngateGiven = TRUE;
        if (mod->omiBSIM4ngate > 1.000001e24) mod->omiBSIM4ngate *= 1.0e-6;
        break;
      case omiBSIM4_MOD_GAMMA1:
        mod->omiBSIM4gamma1 = value->rValue;
        mod->omiBSIM4gamma1Given = TRUE;
        break;
      case omiBSIM4_MOD_GAMMA2:
        mod->omiBSIM4gamma2 = value->rValue;
        mod->omiBSIM4gamma2Given = TRUE;
        break;
      case omiBSIM4_MOD_VBX:
        mod->omiBSIM4vbx = value->rValue;
        mod->omiBSIM4vbxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VBM:
        mod->omiBSIM4vbm = value->rValue;
        mod->omiBSIM4vbmGiven = TRUE;
        break;
      case omiBSIM4_MOD_XT:
        mod->omiBSIM4xt = value->rValue;
        mod->omiBSIM4xtGiven = TRUE;
        break;
      case omiBSIM4_MOD_K1:
        mod->omiBSIM4k1 = value->rValue;
        mod->omiBSIM4k1Given = TRUE;
        break;
      case omiBSIM4_MOD_KT1:
        mod->omiBSIM4kt1 = value->rValue;
        mod->omiBSIM4kt1Given = TRUE;
        break;
      case omiBSIM4_MOD_KT1L:
        mod->omiBSIM4kt1l = value->rValue;
        mod->omiBSIM4kt1lGiven = TRUE;
        break;
      case omiBSIM4_MOD_KT2:
        mod->omiBSIM4kt2 = value->rValue;
        mod->omiBSIM4kt2Given = TRUE;
        break;
      case omiBSIM4_MOD_K2:
        mod->omiBSIM4k2 = value->rValue;
        mod->omiBSIM4k2Given = TRUE;
        break;
      case omiBSIM4_MOD_K3:
        mod->omiBSIM4k3 = value->rValue;
        mod->omiBSIM4k3Given = TRUE;
        break;
      case omiBSIM4_MOD_K3B:
        mod->omiBSIM4k3b = value->rValue;
        mod->omiBSIM4k3bGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPE0:
        mod->omiBSIM4lpe0 = value->rValue;
        mod->omiBSIM4lpe0Given = TRUE;
        break;
      case omiBSIM4_MOD_LPEB:
        mod->omiBSIM4lpeb = value->rValue;
        mod->omiBSIM4lpebGiven = TRUE;
        break;
      case omiBSIM4_MOD_DVTP0:
        mod->omiBSIM4dvtp0 = value->rValue;
        mod->omiBSIM4dvtp0Given = TRUE;
        break;
      case omiBSIM4_MOD_DVTP1:
        mod->omiBSIM4dvtp1 = value->rValue;
        mod->omiBSIM4dvtp1Given = TRUE;
        break;
      case omiBSIM4_MOD_DVTP2: /* New DIBL/Rout */
        mod->omiBSIM4dvtp2 = value->rValue;
        mod->omiBSIM4dvtp2Given = TRUE;
        break;
      case omiBSIM4_MOD_DVTP3:
        mod->omiBSIM4dvtp3 = value->rValue;
        mod->omiBSIM4dvtp3Given = TRUE;
        break;
      case omiBSIM4_MOD_DVTP4:
        mod->omiBSIM4dvtp4 = value->rValue;
        mod->omiBSIM4dvtp4Given = TRUE;
        break;
      case omiBSIM4_MOD_DVTP5:
        mod->omiBSIM4dvtp5 = value->rValue;
        mod->omiBSIM4dvtp5Given = TRUE;
        break;
      case omiBSIM4_MOD_W0:
        mod->omiBSIM4w0 = value->rValue;
        mod->omiBSIM4w0Given = TRUE;
        break;
      case omiBSIM4_MOD_DVT0:
        mod->omiBSIM4dvt0 = value->rValue;
        mod->omiBSIM4dvt0Given = TRUE;
        break;
      case omiBSIM4_MOD_DVT1:
        mod->omiBSIM4dvt1 = value->rValue;
        mod->omiBSIM4dvt1Given = TRUE;
        break;
      case omiBSIM4_MOD_DVT2:
        mod->omiBSIM4dvt2 = value->rValue;
        mod->omiBSIM4dvt2Given = TRUE;
        break;
      case omiBSIM4_MOD_DVT0W:
        mod->omiBSIM4dvt0w = value->rValue;
        mod->omiBSIM4dvt0wGiven = TRUE;
        break;
      case omiBSIM4_MOD_DVT1W:
        mod->omiBSIM4dvt1w = value->rValue;
        mod->omiBSIM4dvt1wGiven = TRUE;
        break;
      case omiBSIM4_MOD_DVT2W:
        mod->omiBSIM4dvt2w = value->rValue;
        mod->omiBSIM4dvt2wGiven = TRUE;
        break;
      case omiBSIM4_MOD_DROUT:
        mod->omiBSIM4drout = value->rValue;
        mod->omiBSIM4droutGiven = TRUE;
        break;
      case omiBSIM4_MOD_DSUB:
        mod->omiBSIM4dsub = value->rValue;
        mod->omiBSIM4dsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTH0:
        mod->omiBSIM4vth0 = value->rValue;
        mod->omiBSIM4vth0Given = TRUE;
        break;
      case omiBSIM4_MOD_EU:
        mod->omiBSIM4eu = value->rValue;
        mod->omiBSIM4euGiven = TRUE;
        break;
      case omiBSIM4_MOD_UCS:
        mod->omiBSIM4ucs = value->rValue;
        mod->omiBSIM4ucsGiven = TRUE;
        break;
      case omiBSIM4_MOD_UA:
        mod->omiBSIM4ua = value->rValue;
        mod->omiBSIM4uaGiven = TRUE;
        break;
      case omiBSIM4_MOD_UA1:
        mod->omiBSIM4ua1 = value->rValue;
        mod->omiBSIM4ua1Given = TRUE;
        break;
      case omiBSIM4_MOD_UB:
        mod->omiBSIM4ub = value->rValue;
        mod->omiBSIM4ubGiven = TRUE;
        break;
      case omiBSIM4_MOD_UB1:
        mod->omiBSIM4ub1 = value->rValue;
        mod->omiBSIM4ub1Given = TRUE;
        break;
      case omiBSIM4_MOD_UC:
        mod->omiBSIM4uc = value->rValue;
        mod->omiBSIM4ucGiven = TRUE;
        break;
      case omiBSIM4_MOD_UC1:
        mod->omiBSIM4uc1 = value->rValue;
        mod->omiBSIM4uc1Given = TRUE;
        break;
      case omiBSIM4_MOD_U0:
        mod->omiBSIM4u0 = value->rValue;
        mod->omiBSIM4u0Given = TRUE;
        break;
      case omiBSIM4_MOD_UTE:
        mod->omiBSIM4ute = value->rValue;
        mod->omiBSIM4uteGiven = TRUE;
        break;
      case omiBSIM4_MOD_UCSTE:
        mod->omiBSIM4ucste = value->rValue;
        mod->omiBSIM4ucsteGiven = TRUE;
        break;
      case omiBSIM4_MOD_UD:
        mod->omiBSIM4ud = value->rValue;
        mod->omiBSIM4udGiven = TRUE;
        break;
      case omiBSIM4_MOD_UD1:
        mod->omiBSIM4ud1 = value->rValue;
        mod->omiBSIM4ud1Given = TRUE;
        break;
      case omiBSIM4_MOD_UP:
        mod->omiBSIM4up = value->rValue;
        mod->omiBSIM4upGiven = TRUE;
        break;
      case omiBSIM4_MOD_LP:
        mod->omiBSIM4lp = value->rValue;
        mod->omiBSIM4lpGiven = TRUE;
        break;
      case omiBSIM4_MOD_LUD:
        mod->omiBSIM4lud = value->rValue;
        mod->omiBSIM4ludGiven = TRUE;
        break;
      case omiBSIM4_MOD_LUD1:
        mod->omiBSIM4lud1 = value->rValue;
        mod->omiBSIM4lud1Given = TRUE;
        break;
      case omiBSIM4_MOD_LUP:
        mod->omiBSIM4lup = value->rValue;
        mod->omiBSIM4lupGiven = TRUE;
        break;
      case omiBSIM4_MOD_LLP:
        mod->omiBSIM4llp = value->rValue;
        mod->omiBSIM4llpGiven = TRUE;
        break;
      case omiBSIM4_MOD_WUD:
        mod->omiBSIM4wud = value->rValue;
        mod->omiBSIM4wudGiven = TRUE;
        break;
      case omiBSIM4_MOD_WUD1:
        mod->omiBSIM4wud1 = value->rValue;
        mod->omiBSIM4wud1Given = TRUE;
        break;
      case omiBSIM4_MOD_WUP:
        mod->omiBSIM4wup = value->rValue;
        mod->omiBSIM4wupGiven = TRUE;
        break;
      case omiBSIM4_MOD_WLP:
        mod->omiBSIM4wlp = value->rValue;
        mod->omiBSIM4wlpGiven = TRUE;
        break;
      case omiBSIM4_MOD_PUD:
        mod->omiBSIM4pud = value->rValue;
        mod->omiBSIM4pudGiven = TRUE;
        break;
      case omiBSIM4_MOD_PUD1:
        mod->omiBSIM4pud1 = value->rValue;
        mod->omiBSIM4pud1Given = TRUE;
        break;
      case omiBSIM4_MOD_PUP:
        mod->omiBSIM4pup = value->rValue;
        mod->omiBSIM4pupGiven = TRUE;
        break;
      case omiBSIM4_MOD_PLP:
        mod->omiBSIM4plp = value->rValue;
        mod->omiBSIM4plpGiven = TRUE;
        break;

      case omiBSIM4_MOD_VOFF:
        mod->omiBSIM4voff = value->rValue;
        mod->omiBSIM4voffGiven = TRUE;
        break;
      case omiBSIM4_MOD_TVOFF:
        mod->omiBSIM4tvoff = value->rValue;
        mod->omiBSIM4tvoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNFACTOR: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4tnfactor = value->rValue;
        mod->omiBSIM4tnfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_TETA0: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4teta0 = value->rValue;
        mod->omiBSIM4teta0Given = TRUE;
        break;
      case omiBSIM4_MOD_TVOFFCV: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4tvoffcv = value->rValue;
        mod->omiBSIM4tvoffcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_VOFFL:
        mod->omiBSIM4voffl = value->rValue;
        mod->omiBSIM4vofflGiven = TRUE;
        break;
      case omiBSIM4_MOD_VOFFCVL:
        mod->omiBSIM4voffcvl = value->rValue;
        mod->omiBSIM4voffcvlGiven = TRUE;
        break;
      case omiBSIM4_MOD_MINV:
        mod->omiBSIM4minv = value->rValue;
        mod->omiBSIM4minvGiven = TRUE;
        break;
      case omiBSIM4_MOD_MINVCV:
        mod->omiBSIM4minvcv = value->rValue;
        mod->omiBSIM4minvcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_FPROUT:
        mod->omiBSIM4fprout = value->rValue;
        mod->omiBSIM4fproutGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDITS:
        mod->omiBSIM4pdits = value->rValue;
        mod->omiBSIM4pditsGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDITSD:
        mod->omiBSIM4pditsd = value->rValue;
        mod->omiBSIM4pditsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDITSL:
        mod->omiBSIM4pditsl = value->rValue;
        mod->omiBSIM4pditslGiven = TRUE;
        break;
      case omiBSIM4_MOD_DELTA:
        mod->omiBSIM4delta = value->rValue;
        mod->omiBSIM4deltaGiven = TRUE;
        break;
      case omiBSIM4_MOD_RDSW:
        mod->omiBSIM4rdsw = value->rValue;
        mod->omiBSIM4rdswGiven = TRUE;
        break;
      case omiBSIM4_MOD_RDSWMIN:
        mod->omiBSIM4rdswmin = value->rValue;
        mod->omiBSIM4rdswminGiven = TRUE;
        break;
      case omiBSIM4_MOD_RDWMIN:
        mod->omiBSIM4rdwmin = value->rValue;
        mod->omiBSIM4rdwminGiven = TRUE;
        break;
      case omiBSIM4_MOD_RSWMIN:
        mod->omiBSIM4rswmin = value->rValue;
        mod->omiBSIM4rswminGiven = TRUE;
        break;
      case omiBSIM4_MOD_RDW:
        mod->omiBSIM4rdw = value->rValue;
        mod->omiBSIM4rdwGiven = TRUE;
        break;
      case omiBSIM4_MOD_RSW:
        mod->omiBSIM4rsw = value->rValue;
        mod->omiBSIM4rswGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRWG:
        mod->omiBSIM4prwg = value->rValue;
        mod->omiBSIM4prwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRWB:
        mod->omiBSIM4prwb = value->rValue;
        mod->omiBSIM4prwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRT:
        mod->omiBSIM4prt = value->rValue;
        mod->omiBSIM4prtGiven = TRUE;
        break;
      case omiBSIM4_MOD_ETA0:
        mod->omiBSIM4eta0 = value->rValue;
        mod->omiBSIM4eta0Given = TRUE;
        break;
      case omiBSIM4_MOD_ETAB:
        mod->omiBSIM4etab = value->rValue;
        mod->omiBSIM4etabGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCLM:
        mod->omiBSIM4pclm = value->rValue;
        mod->omiBSIM4pclmGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDIBL1:
        mod->omiBSIM4pdibl1 = value->rValue;
        mod->omiBSIM4pdibl1Given = TRUE;
        break;
      case omiBSIM4_MOD_PDIBL2:
        mod->omiBSIM4pdibl2 = value->rValue;
        mod->omiBSIM4pdibl2Given = TRUE;
        break;
      case omiBSIM4_MOD_PDIBLB:
        mod->omiBSIM4pdiblb = value->rValue;
        mod->omiBSIM4pdiblbGiven = TRUE;
        break;
      case omiBSIM4_MOD_PSCBE1:
        mod->omiBSIM4pscbe1 = value->rValue;
        mod->omiBSIM4pscbe1Given = TRUE;
        break;
      case omiBSIM4_MOD_PSCBE2:
        mod->omiBSIM4pscbe2 = value->rValue;
        mod->omiBSIM4pscbe2Given = TRUE;
        break;
      case omiBSIM4_MOD_PVAG:
        mod->omiBSIM4pvag = value->rValue;
        mod->omiBSIM4pvagGiven = TRUE;
        break;
      case omiBSIM4_MOD_WR:
        mod->omiBSIM4wr = value->rValue;
        mod->omiBSIM4wrGiven = TRUE;
        break;
      case omiBSIM4_MOD_DWG:
        mod->omiBSIM4dwg = value->rValue;
        mod->omiBSIM4dwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_DWB:
        mod->omiBSIM4dwb = value->rValue;
        mod->omiBSIM4dwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_B0:
        mod->omiBSIM4b0 = value->rValue;
        mod->omiBSIM4b0Given = TRUE;
        break;
      case omiBSIM4_MOD_B1:
        mod->omiBSIM4b1 = value->rValue;
        mod->omiBSIM4b1Given = TRUE;
        break;
      case omiBSIM4_MOD_ALPHA0:
        mod->omiBSIM4alpha0 = value->rValue;
        mod->omiBSIM4alpha0Given = TRUE;
        break;
      case omiBSIM4_MOD_ALPHA1:
        mod->omiBSIM4alpha1 = value->rValue;
        mod->omiBSIM4alpha1Given = TRUE;
        break;
      case omiBSIM4_MOD_PHIN:
        mod->omiBSIM4phin = value->rValue;
        mod->omiBSIM4phinGiven = TRUE;
        break;
      case omiBSIM4_MOD_AGIDL:
        mod->omiBSIM4agidl = value->rValue;
        mod->omiBSIM4agidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_BGIDL:
        mod->omiBSIM4bgidl = value->rValue;
        mod->omiBSIM4bgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_CGIDL:
        mod->omiBSIM4cgidl = value->rValue;
        mod->omiBSIM4cgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_EGIDL:
        mod->omiBSIM4egidl = value->rValue;
        mod->omiBSIM4egidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_FGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4fgidl = value->rValue;
        mod->omiBSIM4fgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_KGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4kgidl = value->rValue;
        mod->omiBSIM4kgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_RGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4rgidl = value->rValue;
        mod->omiBSIM4rgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_AGISL:
        mod->omiBSIM4agisl = value->rValue;
        mod->omiBSIM4agislGiven = TRUE;
        break;
      case omiBSIM4_MOD_BGISL:
        mod->omiBSIM4bgisl = value->rValue;
        mod->omiBSIM4bgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_CGISL:
        mod->omiBSIM4cgisl = value->rValue;
        mod->omiBSIM4cgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_EGISL:
        mod->omiBSIM4egisl = value->rValue;
        mod->omiBSIM4egislGiven = TRUE;
        break;
      case omiBSIM4_MOD_FGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4fgisl = value->rValue;
        mod->omiBSIM4fgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_KGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4kgisl = value->rValue;
        mod->omiBSIM4kgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_RGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4rgisl = value->rValue;
        mod->omiBSIM4rgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_AIGC:
        mod->omiBSIM4aigc = value->rValue;
        mod->omiBSIM4aigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_BIGC:
        mod->omiBSIM4bigc = value->rValue;
        mod->omiBSIM4bigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_CIGC:
        mod->omiBSIM4cigc = value->rValue;
        mod->omiBSIM4cigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_AIGSD:
        mod->omiBSIM4aigsd = value->rValue;
        mod->omiBSIM4aigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_BIGSD:
        mod->omiBSIM4bigsd = value->rValue;
        mod->omiBSIM4bigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_CIGSD:
        mod->omiBSIM4cigsd = value->rValue;
        mod->omiBSIM4cigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_AIGS:
        mod->omiBSIM4aigs = value->rValue;
        mod->omiBSIM4aigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_BIGS:
        mod->omiBSIM4bigs = value->rValue;
        mod->omiBSIM4bigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_CIGS:
        mod->omiBSIM4cigs = value->rValue;
        mod->omiBSIM4cigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_AIGD:
        mod->omiBSIM4aigd = value->rValue;
        mod->omiBSIM4aigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_BIGD:
        mod->omiBSIM4bigd = value->rValue;
        mod->omiBSIM4bigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_CIGD:
        mod->omiBSIM4cigd = value->rValue;
        mod->omiBSIM4cigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_AIGBACC:
        mod->omiBSIM4aigbacc = value->rValue;
        mod->omiBSIM4aigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_BIGBACC:
        mod->omiBSIM4bigbacc = value->rValue;
        mod->omiBSIM4bigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_CIGBACC:
        mod->omiBSIM4cigbacc = value->rValue;
        mod->omiBSIM4cigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_AIGBINV:
        mod->omiBSIM4aigbinv = value->rValue;
        mod->omiBSIM4aigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_BIGBINV:
        mod->omiBSIM4bigbinv = value->rValue;
        mod->omiBSIM4bigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_CIGBINV:
        mod->omiBSIM4cigbinv = value->rValue;
        mod->omiBSIM4cigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_NIGC:
        mod->omiBSIM4nigc = value->rValue;
        mod->omiBSIM4nigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_NIGBINV:
        mod->omiBSIM4nigbinv = value->rValue;
        mod->omiBSIM4nigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_NIGBACC:
        mod->omiBSIM4nigbacc = value->rValue;
        mod->omiBSIM4nigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_NTOX:
        mod->omiBSIM4ntox = value->rValue;
        mod->omiBSIM4ntoxGiven = TRUE;
        break;
      case omiBSIM4_MOD_EIGBINV:
        mod->omiBSIM4eigbinv = value->rValue;
        mod->omiBSIM4eigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PIGCD:
        mod->omiBSIM4pigcd = value->rValue;
        mod->omiBSIM4pigcdGiven = TRUE;
        break;
      case omiBSIM4_MOD_POXEDGE:
        mod->omiBSIM4poxedge = value->rValue;
        mod->omiBSIM4poxedgeGiven = TRUE;
        break;
      case omiBSIM4_MOD_XRCRG1:
        mod->omiBSIM4xrcrg1 = value->rValue;
        mod->omiBSIM4xrcrg1Given = TRUE;
        break;
      case omiBSIM4_MOD_XRCRG2:
        mod->omiBSIM4xrcrg2 = value->rValue;
        mod->omiBSIM4xrcrg2Given = TRUE;
        break;
      case omiBSIM4_MOD_LAMBDA:
        mod->omiBSIM4lambda = value->rValue;
        mod->omiBSIM4lambdaGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTL:
        mod->omiBSIM4vtl = value->rValue;
        mod->omiBSIM4vtlGiven = TRUE;
        break;
      case omiBSIM4_MOD_XN:
        mod->omiBSIM4xn = value->rValue;
        mod->omiBSIM4xnGiven = TRUE;
        break;
      case omiBSIM4_MOD_LC:
        mod->omiBSIM4lc = value->rValue;
        mod->omiBSIM4lcGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNOIA:
        mod->omiBSIM4tnoia = value->rValue;
        mod->omiBSIM4tnoiaGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNOIB:
        mod->omiBSIM4tnoib = value->rValue;
        mod->omiBSIM4tnoibGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNOIC:
        mod->omiBSIM4tnoic = value->rValue;
        mod->omiBSIM4tnoicGiven = TRUE;
        break;
      case omiBSIM4_MOD_RNOIA:
        mod->omiBSIM4rnoia = value->rValue;
        mod->omiBSIM4rnoiaGiven = TRUE;
        break;
      case omiBSIM4_MOD_RNOIB:
        mod->omiBSIM4rnoib = value->rValue;
        mod->omiBSIM4rnoibGiven = TRUE;
        break;
      case omiBSIM4_MOD_RNOIC:
        mod->omiBSIM4rnoic = value->rValue;
        mod->omiBSIM4rnoicGiven = TRUE;
        break;
      case omiBSIM4_MOD_NTNOI:
        mod->omiBSIM4ntnoi = value->rValue;
        mod->omiBSIM4ntnoiGiven = TRUE;
        break;
      case omiBSIM4_MOD_VFBSDOFF:
        mod->omiBSIM4vfbsdoff = value->rValue;
        mod->omiBSIM4vfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_TVFBSDOFF:
        mod->omiBSIM4tvfbsdoff = value->rValue;
        mod->omiBSIM4tvfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_LINTNOI:
        mod->omiBSIM4lintnoi = value->rValue;
        mod->omiBSIM4lintnoiGiven = TRUE;
        break;

      /* stress effect */
      case omiBSIM4_MOD_SAREF:
        mod->omiBSIM4saref = value->rValue;
        mod->omiBSIM4sarefGiven = TRUE;
        break;
      case omiBSIM4_MOD_SBREF:
        mod->omiBSIM4sbref = value->rValue;
        mod->omiBSIM4sbrefGiven = TRUE;
        break;
      case omiBSIM4_MOD_WLOD:
        mod->omiBSIM4wlod = value->rValue;
        mod->omiBSIM4wlodGiven = TRUE;
        break;
      case omiBSIM4_MOD_KU0:
        mod->omiBSIM4ku0 = value->rValue;
        mod->omiBSIM4ku0Given = TRUE;
        break;
      case omiBSIM4_MOD_KVSAT:
        mod->omiBSIM4kvsat = value->rValue;
        mod->omiBSIM4kvsatGiven = TRUE;
        break;
      case omiBSIM4_MOD_KVTH0:
        mod->omiBSIM4kvth0 = value->rValue;
        mod->omiBSIM4kvth0Given = TRUE;
        break;
      case omiBSIM4_MOD_TKU0:
        mod->omiBSIM4tku0 = value->rValue;
        mod->omiBSIM4tku0Given = TRUE;
        break;
      case omiBSIM4_MOD_LLODKU0:
        mod->omiBSIM4llodku0 = value->rValue;
        mod->omiBSIM4llodku0Given = TRUE;
        break;
      case omiBSIM4_MOD_WLODKU0:
        mod->omiBSIM4wlodku0 = value->rValue;
        mod->omiBSIM4wlodku0Given = TRUE;
        break;
      case omiBSIM4_MOD_LLODVTH:
        mod->omiBSIM4llodvth = value->rValue;
        mod->omiBSIM4llodvthGiven = TRUE;
        break;
      case omiBSIM4_MOD_WLODVTH:
        mod->omiBSIM4wlodvth = value->rValue;
        mod->omiBSIM4wlodvthGiven = TRUE;
        break;
      case omiBSIM4_MOD_LKU0:
        mod->omiBSIM4lku0 = value->rValue;
        mod->omiBSIM4lku0Given = TRUE;
        break;
      case omiBSIM4_MOD_WKU0:
        mod->omiBSIM4wku0 = value->rValue;
        mod->omiBSIM4wku0Given = TRUE;
        break;
      case omiBSIM4_MOD_PKU0:
        mod->omiBSIM4pku0 = value->rValue;
        mod->omiBSIM4pku0Given = TRUE;
        break;
      case omiBSIM4_MOD_LKVTH0:
        mod->omiBSIM4lkvth0 = value->rValue;
        mod->omiBSIM4lkvth0Given = TRUE;
        break;
      case omiBSIM4_MOD_WKVTH0:
        mod->omiBSIM4wkvth0 = value->rValue;
        mod->omiBSIM4wkvth0Given = TRUE;
        break;
      case omiBSIM4_MOD_PKVTH0:
        mod->omiBSIM4pkvth0 = value->rValue;
        mod->omiBSIM4pkvth0Given = TRUE;
        break;
      case omiBSIM4_MOD_STK2:
        mod->omiBSIM4stk2 = value->rValue;
        mod->omiBSIM4stk2Given = TRUE;
        break;
      case omiBSIM4_MOD_LODK2:
        mod->omiBSIM4lodk2 = value->rValue;
        mod->omiBSIM4lodk2Given = TRUE;
        break;
      case omiBSIM4_MOD_STETA0:
        mod->omiBSIM4steta0 = value->rValue;
        mod->omiBSIM4steta0Given = TRUE;
        break;
      case omiBSIM4_MOD_LODETA0:
        mod->omiBSIM4lodeta0 = value->rValue;
        mod->omiBSIM4lodeta0Given = TRUE;
        break;

      case omiBSIM4_MOD_WEB:
        mod->omiBSIM4web = value->rValue;
        mod->omiBSIM4webGiven = TRUE;
        break;
      case omiBSIM4_MOD_WEC:
        mod->omiBSIM4wec = value->rValue;
        mod->omiBSIM4wecGiven = TRUE;
        break;
      case omiBSIM4_MOD_KVTH0WE:
        mod->omiBSIM4kvth0we = value->rValue;
        mod->omiBSIM4kvth0weGiven = TRUE;
        break;
      case omiBSIM4_MOD_K2WE:
        mod->omiBSIM4k2we = value->rValue;
        mod->omiBSIM4k2weGiven = TRUE;
        break;
      case omiBSIM4_MOD_KU0WE:
        mod->omiBSIM4ku0we = value->rValue;
        mod->omiBSIM4ku0weGiven = TRUE;
        break;
      case omiBSIM4_MOD_SCREF:
        mod->omiBSIM4scref = value->rValue;
        mod->omiBSIM4screfGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPEMOD:
        mod->omiBSIM4wpemod = value->rValue;
        mod->omiBSIM4wpemodGiven = TRUE;
        break;
      case omiBSIM4_MOD_LKVTH0WE:
        mod->omiBSIM4lkvth0we = value->rValue;
        mod->omiBSIM4lkvth0weGiven = TRUE;
        break;
      case omiBSIM4_MOD_LK2WE:
        mod->omiBSIM4lk2we = value->rValue;
        mod->omiBSIM4lk2weGiven = TRUE;
        break;
      case omiBSIM4_MOD_LKU0WE:
        mod->omiBSIM4lku0we = value->rValue;
        mod->omiBSIM4lku0weGiven = TRUE;
        break;
      case omiBSIM4_MOD_WKVTH0WE:
        mod->omiBSIM4wkvth0we = value->rValue;
        mod->omiBSIM4wkvth0weGiven = TRUE;
        break;
      case omiBSIM4_MOD_WK2WE:
        mod->omiBSIM4wk2we = value->rValue;
        mod->omiBSIM4wk2weGiven = TRUE;
        break;
      case omiBSIM4_MOD_WKU0WE:
        mod->omiBSIM4wku0we = value->rValue;
        mod->omiBSIM4wku0weGiven = TRUE;
        break;
      case omiBSIM4_MOD_PKVTH0WE:
        mod->omiBSIM4pkvth0we = value->rValue;
        mod->omiBSIM4pkvth0weGiven = TRUE;
        break;
      case omiBSIM4_MOD_PK2WE:
        mod->omiBSIM4pk2we = value->rValue;
        mod->omiBSIM4pk2weGiven = TRUE;
        break;
      case omiBSIM4_MOD_PKU0WE:
        mod->omiBSIM4pku0we = value->rValue;
        mod->omiBSIM4pku0weGiven = TRUE;
        break;

      case omiBSIM4_MOD_BETA0:
        mod->omiBSIM4beta0 = value->rValue;
        mod->omiBSIM4beta0Given = TRUE;
        break;
      case omiBSIM4_MOD_IJTHDFWD:
        mod->omiBSIM4ijthdfwd = value->rValue;
        mod->omiBSIM4ijthdfwdGiven = TRUE;
        break;
      case omiBSIM4_MOD_IJTHSFWD:
        mod->omiBSIM4ijthsfwd = value->rValue;
        mod->omiBSIM4ijthsfwdGiven = TRUE;
        break;
      case omiBSIM4_MOD_IJTHDREV:
        mod->omiBSIM4ijthdrev = value->rValue;
        mod->omiBSIM4ijthdrevGiven = TRUE;
        break;
      case omiBSIM4_MOD_IJTHSREV:
        mod->omiBSIM4ijthsrev = value->rValue;
        mod->omiBSIM4ijthsrevGiven = TRUE;
        break;
      case omiBSIM4_MOD_XJBVD:
        mod->omiBSIM4xjbvd = value->rValue;
        mod->omiBSIM4xjbvdGiven = TRUE;
        break;
      case omiBSIM4_MOD_XJBVS:
        mod->omiBSIM4xjbvs = value->rValue;
        mod->omiBSIM4xjbvsGiven = TRUE;
        break;
      case omiBSIM4_MOD_BVD:
        mod->omiBSIM4bvd = value->rValue;
        mod->omiBSIM4bvdGiven = TRUE;
        break;
      case omiBSIM4_MOD_BVS:
        mod->omiBSIM4bvs = value->rValue;
        mod->omiBSIM4bvsGiven = TRUE;
        break;

      /* reverse diode */
      case omiBSIM4_MOD_JTSS:
        mod->omiBSIM4jtss = value->rValue;
        mod->omiBSIM4jtssGiven = TRUE;
        break;
      case omiBSIM4_MOD_JTSD:
        mod->omiBSIM4jtsd = value->rValue;
        mod->omiBSIM4jtsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_JTSSWS:
        mod->omiBSIM4jtssws = value->rValue;
        mod->omiBSIM4jtsswsGiven = TRUE;
        break;
      case omiBSIM4_MOD_JTSSWD:
        mod->omiBSIM4jtsswd = value->rValue;
        mod->omiBSIM4jtsswdGiven = TRUE;
        break;
      case omiBSIM4_MOD_JTSSWGS:
        mod->omiBSIM4jtsswgs = value->rValue;
        mod->omiBSIM4jtsswgsGiven = TRUE;
        break;
      case omiBSIM4_MOD_JTSSWGD:
        mod->omiBSIM4jtsswgd = value->rValue;
        mod->omiBSIM4jtsswgdGiven = TRUE;
        break;
      case omiBSIM4_MOD_JTWEFF:
        mod->omiBSIM4jtweff = value->rValue;
        mod->omiBSIM4jtweffGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJTS:
        mod->omiBSIM4njts = value->rValue;
        mod->omiBSIM4njtsGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJTSSW:
        mod->omiBSIM4njtssw = value->rValue;
        mod->omiBSIM4njtsswGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJTSSWG:
        mod->omiBSIM4njtsswg = value->rValue;
        mod->omiBSIM4njtsswgGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJTSD:
        mod->omiBSIM4njtsd = value->rValue;
        mod->omiBSIM4njtsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJTSSWD:
        mod->omiBSIM4njtsswd = value->rValue;
        mod->omiBSIM4njtsswdGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJTSSWGD:
        mod->omiBSIM4njtsswgd = value->rValue;
        mod->omiBSIM4njtsswgdGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTSS:
        mod->omiBSIM4xtss = value->rValue;
        mod->omiBSIM4xtssGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTSD:
        mod->omiBSIM4xtsd = value->rValue;
        mod->omiBSIM4xtsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTSSWS:
        mod->omiBSIM4xtssws = value->rValue;
        mod->omiBSIM4xtsswsGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTSSWD:
        mod->omiBSIM4xtsswd = value->rValue;
        mod->omiBSIM4xtsswdGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTSSWGS:
        mod->omiBSIM4xtsswgs = value->rValue;
        mod->omiBSIM4xtsswgsGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTSSWGD:
        mod->omiBSIM4xtsswgd = value->rValue;
        mod->omiBSIM4xtsswgdGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNJTS:
        mod->omiBSIM4tnjts = value->rValue;
        mod->omiBSIM4tnjtsGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNJTSSW:
        mod->omiBSIM4tnjtssw = value->rValue;
        mod->omiBSIM4tnjtsswGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNJTSSWG:
        mod->omiBSIM4tnjtsswg = value->rValue;
        mod->omiBSIM4tnjtsswgGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNJTSD:
        mod->omiBSIM4tnjtsd = value->rValue;
        mod->omiBSIM4tnjtsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNJTSSWD:
        mod->omiBSIM4tnjtsswd = value->rValue;
        mod->omiBSIM4tnjtsswdGiven = TRUE;
        break;
      case omiBSIM4_MOD_TNJTSSWGD:
        mod->omiBSIM4tnjtsswgd = value->rValue;
        mod->omiBSIM4tnjtsswgdGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTSS:
        mod->omiBSIM4vtss = value->rValue;
        mod->omiBSIM4vtssGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTSD:
        mod->omiBSIM4vtsd = value->rValue;
        mod->omiBSIM4vtsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTSSWS:
        mod->omiBSIM4vtssws = value->rValue;
        mod->omiBSIM4vtsswsGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTSSWD:
        mod->omiBSIM4vtsswd = value->rValue;
        mod->omiBSIM4vtsswdGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTSSWGS:
        mod->omiBSIM4vtsswgs = value->rValue;
        mod->omiBSIM4vtsswgsGiven = TRUE;
        break;
      case omiBSIM4_MOD_VTSSWGD:
        mod->omiBSIM4vtsswgd = value->rValue;
        mod->omiBSIM4vtsswgdGiven = TRUE;
        break;

      case omiBSIM4_MOD_VFB:
        mod->omiBSIM4vfb = value->rValue;
        mod->omiBSIM4vfbGiven = TRUE;
        break;

      case omiBSIM4_MOD_GBMIN:
        mod->omiBSIM4gbmin = value->rValue;
        mod->omiBSIM4gbminGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBDB:
        mod->omiBSIM4rbdb = value->rValue;
        mod->omiBSIM4rbdbGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPB:
        mod->omiBSIM4rbpb = value->rValue;
        mod->omiBSIM4rbpbGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBSB:
        mod->omiBSIM4rbsb = value->rValue;
        mod->omiBSIM4rbsbGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPS:
        mod->omiBSIM4rbps = value->rValue;
        mod->omiBSIM4rbpsGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPD:
        mod->omiBSIM4rbpd = value->rValue;
        mod->omiBSIM4rbpdGiven = TRUE;
        break;

      case omiBSIM4_MOD_RBPS0:
        mod->omiBSIM4rbps0 = value->rValue;
        mod->omiBSIM4rbps0Given = TRUE;
        break;
      case omiBSIM4_MOD_RBPSL:
        mod->omiBSIM4rbpsl = value->rValue;
        mod->omiBSIM4rbpslGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPSW:
        mod->omiBSIM4rbpsw = value->rValue;
        mod->omiBSIM4rbpswGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPSNF:
        mod->omiBSIM4rbpsnf = value->rValue;
        mod->omiBSIM4rbpsnfGiven = TRUE;
        break;

      case omiBSIM4_MOD_RBPD0:
        mod->omiBSIM4rbpd0 = value->rValue;
        mod->omiBSIM4rbpd0Given = TRUE;
        break;
      case omiBSIM4_MOD_RBPDL:
        mod->omiBSIM4rbpdl = value->rValue;
        mod->omiBSIM4rbpdlGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPDW:
        mod->omiBSIM4rbpdw = value->rValue;
        mod->omiBSIM4rbpdwGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPDNF:
        mod->omiBSIM4rbpdnf = value->rValue;
        mod->omiBSIM4rbpdnfGiven = TRUE;
        break;

      case omiBSIM4_MOD_RBPBX0:
        mod->omiBSIM4rbpbx0 = value->rValue;
        mod->omiBSIM4rbpbx0Given = TRUE;
        break;
      case omiBSIM4_MOD_RBPBXL:
        mod->omiBSIM4rbpbxl = value->rValue;
        mod->omiBSIM4rbpbxlGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPBXW:
        mod->omiBSIM4rbpbxw = value->rValue;
        mod->omiBSIM4rbpbxwGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPBXNF:
        mod->omiBSIM4rbpbxnf = value->rValue;
        mod->omiBSIM4rbpbxnfGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPBY0:
        mod->omiBSIM4rbpby0 = value->rValue;
        mod->omiBSIM4rbpby0Given = TRUE;
        break;
      case omiBSIM4_MOD_RBPBYL:
        mod->omiBSIM4rbpbyl = value->rValue;
        mod->omiBSIM4rbpbylGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPBYW:
        mod->omiBSIM4rbpbyw = value->rValue;
        mod->omiBSIM4rbpbywGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBPBYNF:
        mod->omiBSIM4rbpbynf = value->rValue;
        mod->omiBSIM4rbpbynfGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBSBX0:
        mod->omiBSIM4rbsbx0 = value->rValue;
        mod->omiBSIM4rbsbx0Given = TRUE;
        break;
      case omiBSIM4_MOD_RBSBY0:
        mod->omiBSIM4rbsby0 = value->rValue;
        mod->omiBSIM4rbsby0Given = TRUE;
        break;
      case omiBSIM4_MOD_RBDBX0:
        mod->omiBSIM4rbdbx0 = value->rValue;
        mod->omiBSIM4rbdbx0Given = TRUE;
        break;
      case omiBSIM4_MOD_RBDBY0:
        mod->omiBSIM4rbdby0 = value->rValue;
        mod->omiBSIM4rbdby0Given = TRUE;
        break;

      case omiBSIM4_MOD_RBSDBXL:
        mod->omiBSIM4rbsdbxl = value->rValue;
        mod->omiBSIM4rbsdbxlGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBSDBXW:
        mod->omiBSIM4rbsdbxw = value->rValue;
        mod->omiBSIM4rbsdbxwGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBSDBXNF:
        mod->omiBSIM4rbsdbxnf = value->rValue;
        mod->omiBSIM4rbsdbxnfGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBSDBYL:
        mod->omiBSIM4rbsdbyl = value->rValue;
        mod->omiBSIM4rbsdbylGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBSDBYW:
        mod->omiBSIM4rbsdbyw = value->rValue;
        mod->omiBSIM4rbsdbywGiven = TRUE;
        break;
      case omiBSIM4_MOD_RBSDBYNF:
        mod->omiBSIM4rbsdbynf = value->rValue;
        mod->omiBSIM4rbsdbynfGiven = TRUE;
        break;

      case omiBSIM4_MOD_CGSL:
        mod->omiBSIM4cgsl = value->rValue;
        mod->omiBSIM4cgslGiven = TRUE;
        break;
      case omiBSIM4_MOD_CGDL:
        mod->omiBSIM4cgdl = value->rValue;
        mod->omiBSIM4cgdlGiven = TRUE;
        break;
      case omiBSIM4_MOD_CKAPPAS:
        mod->omiBSIM4ckappas = value->rValue;
        mod->omiBSIM4ckappasGiven = TRUE;
        break;
      case omiBSIM4_MOD_CKAPPAD:
        mod->omiBSIM4ckappad = value->rValue;
        mod->omiBSIM4ckappadGiven = TRUE;
        break;
      case omiBSIM4_MOD_CF:
        mod->omiBSIM4cf = value->rValue;
        mod->omiBSIM4cfGiven = TRUE;
        break;
      case omiBSIM4_MOD_CLC:
        mod->omiBSIM4clc = value->rValue;
        mod->omiBSIM4clcGiven = TRUE;
        break;
      case omiBSIM4_MOD_CLE:
        mod->omiBSIM4cle = value->rValue;
        mod->omiBSIM4cleGiven = TRUE;
        break;
      case omiBSIM4_MOD_DWC:
        mod->omiBSIM4dwc = value->rValue;
        mod->omiBSIM4dwcGiven = TRUE;
        break;
      case omiBSIM4_MOD_DLC:
        mod->omiBSIM4dlc = value->rValue;
        mod->omiBSIM4dlcGiven = TRUE;
        break;
      case omiBSIM4_MOD_XW:
        mod->omiBSIM4xw = value->rValue;
        mod->omiBSIM4xwGiven = TRUE;
        break;
      case omiBSIM4_MOD_XL:
        mod->omiBSIM4xl = value->rValue;
        mod->omiBSIM4xlGiven = TRUE;
        break;
      case omiBSIM4_MOD_DLCIG:
        mod->omiBSIM4dlcig = value->rValue;
        mod->omiBSIM4dlcigGiven = TRUE;
        break;
      case omiBSIM4_MOD_DLCIGD:
        mod->omiBSIM4dlcigd = value->rValue;
        mod->omiBSIM4dlcigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_DWJ:
        mod->omiBSIM4dwj = value->rValue;
        mod->omiBSIM4dwjGiven = TRUE;
        break;
      case omiBSIM4_MOD_VFBCV:
        mod->omiBSIM4vfbcv = value->rValue;
        mod->omiBSIM4vfbcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_ACDE:
        mod->omiBSIM4acde = value->rValue;
        mod->omiBSIM4acdeGiven = TRUE;
        break;
      case omiBSIM4_MOD_MOIN:
        mod->omiBSIM4moin = value->rValue;
        mod->omiBSIM4moinGiven = TRUE;
        break;
      case omiBSIM4_MOD_NOFF:
        mod->omiBSIM4noff = value->rValue;
        mod->omiBSIM4noffGiven = TRUE;
        break;
      case omiBSIM4_MOD_VOFFCV:
        mod->omiBSIM4voffcv = value->rValue;
        mod->omiBSIM4voffcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_DMCG:
        mod->omiBSIM4dmcg = value->rValue;
        mod->omiBSIM4dmcgGiven = TRUE;
        break;
      case omiBSIM4_MOD_DMCI:
        mod->omiBSIM4dmci = value->rValue;
        mod->omiBSIM4dmciGiven = TRUE;
        break;
      case omiBSIM4_MOD_DMDG:
        mod->omiBSIM4dmdg = value->rValue;
        mod->omiBSIM4dmdgGiven = TRUE;
        break;
      case omiBSIM4_MOD_DMCGT:
        mod->omiBSIM4dmcgt = value->rValue;
        mod->omiBSIM4dmcgtGiven = TRUE;
        break;
      case omiBSIM4_MOD_XGW:
        mod->omiBSIM4xgw = value->rValue;
        mod->omiBSIM4xgwGiven = TRUE;
        break;
      case omiBSIM4_MOD_XGL:
        mod->omiBSIM4xgl = value->rValue;
        mod->omiBSIM4xglGiven = TRUE;
        break;
      case omiBSIM4_MOD_RSHG:
        mod->omiBSIM4rshg = value->rValue;
        mod->omiBSIM4rshgGiven = TRUE;
        break;
      case omiBSIM4_MOD_NGCON:
        mod->omiBSIM4ngcon = value->rValue;
        mod->omiBSIM4ngconGiven = TRUE;
        break;
      case omiBSIM4_MOD_TCJ:
        mod->omiBSIM4tcj = value->rValue;
        mod->omiBSIM4tcjGiven = TRUE;
        break;
      case omiBSIM4_MOD_TPB:
        mod->omiBSIM4tpb = value->rValue;
        mod->omiBSIM4tpbGiven = TRUE;
        break;
      case omiBSIM4_MOD_TCJSW:
        mod->omiBSIM4tcjsw = value->rValue;
        mod->omiBSIM4tcjswGiven = TRUE;
        break;
      case omiBSIM4_MOD_TPBSW:
        mod->omiBSIM4tpbsw = value->rValue;
        mod->omiBSIM4tpbswGiven = TRUE;
        break;
      case omiBSIM4_MOD_TCJSWG:
        mod->omiBSIM4tcjswg = value->rValue;
        mod->omiBSIM4tcjswgGiven = TRUE;
        break;
      case omiBSIM4_MOD_TPBSWG:
        mod->omiBSIM4tpbswg = value->rValue;
        mod->omiBSIM4tpbswgGiven = TRUE;
        break;

      /* Length dependence */
      case omiBSIM4_MOD_LCDSC:
        mod->omiBSIM4lcdsc = value->rValue;
        mod->omiBSIM4lcdscGiven = TRUE;
        break;

      case omiBSIM4_MOD_LCDSCB:
        mod->omiBSIM4lcdscb = value->rValue;
        mod->omiBSIM4lcdscbGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCDSCD:
        mod->omiBSIM4lcdscd = value->rValue;
        mod->omiBSIM4lcdscdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCIT:
        mod->omiBSIM4lcit = value->rValue;
        mod->omiBSIM4lcitGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNFACTOR:
        mod->omiBSIM4lnfactor = value->rValue;
        mod->omiBSIM4lnfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_LXJ:
        mod->omiBSIM4lxj = value->rValue;
        mod->omiBSIM4lxjGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVSAT:
        mod->omiBSIM4lvsat = value->rValue;
        mod->omiBSIM4lvsatGiven = TRUE;
        break;

      case omiBSIM4_MOD_LA0:
        mod->omiBSIM4la0 = value->rValue;
        mod->omiBSIM4la0Given = TRUE;
        break;
      case omiBSIM4_MOD_LAGS:
        mod->omiBSIM4lags = value->rValue;
        mod->omiBSIM4lagsGiven = TRUE;
        break;
      case omiBSIM4_MOD_LA1:
        mod->omiBSIM4la1 = value->rValue;
        mod->omiBSIM4la1Given = TRUE;
        break;
      case omiBSIM4_MOD_LA2:
        mod->omiBSIM4la2 = value->rValue;
        mod->omiBSIM4la2Given = TRUE;
        break;
      case omiBSIM4_MOD_LAT:
        mod->omiBSIM4lat = value->rValue;
        mod->omiBSIM4latGiven = TRUE;
        break;
      case omiBSIM4_MOD_LKETA:
        mod->omiBSIM4lketa = value->rValue;
        mod->omiBSIM4lketaGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNSUB:
        mod->omiBSIM4lnsub = value->rValue;
        mod->omiBSIM4lnsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNDEP:
        mod->omiBSIM4lndep = value->rValue;
        mod->omiBSIM4lndepGiven = TRUE;
        if (mod->omiBSIM4lndep > 1.0e20) mod->omiBSIM4lndep *= 1.0e-6;
        break;
      case omiBSIM4_MOD_LNSD:
        mod->omiBSIM4lnsd = value->rValue;
        mod->omiBSIM4lnsdGiven = TRUE;
        if (mod->omiBSIM4lnsd > 1.0e23) mod->omiBSIM4lnsd *= 1.0e-6;
        break;
      case omiBSIM4_MOD_LNGATE:
        mod->omiBSIM4lngate = value->rValue;
        mod->omiBSIM4lngateGiven = TRUE;
        if (mod->omiBSIM4lngate > 1.0e23) mod->omiBSIM4lngate *= 1.0e-6;
        break;
      case omiBSIM4_MOD_LGAMMA1:
        mod->omiBSIM4lgamma1 = value->rValue;
        mod->omiBSIM4lgamma1Given = TRUE;
        break;
      case omiBSIM4_MOD_LGAMMA2:
        mod->omiBSIM4lgamma2 = value->rValue;
        mod->omiBSIM4lgamma2Given = TRUE;
        break;
      case omiBSIM4_MOD_LVBX:
        mod->omiBSIM4lvbx = value->rValue;
        mod->omiBSIM4lvbxGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVBM:
        mod->omiBSIM4lvbm = value->rValue;
        mod->omiBSIM4lvbmGiven = TRUE;
        break;
      case omiBSIM4_MOD_LXT:
        mod->omiBSIM4lxt = value->rValue;
        mod->omiBSIM4lxtGiven = TRUE;
        break;
      case omiBSIM4_MOD_LK1:
        mod->omiBSIM4lk1 = value->rValue;
        mod->omiBSIM4lk1Given = TRUE;
        break;
      case omiBSIM4_MOD_LKT1:
        mod->omiBSIM4lkt1 = value->rValue;
        mod->omiBSIM4lkt1Given = TRUE;
        break;
      case omiBSIM4_MOD_LKT1L:
        mod->omiBSIM4lkt1l = value->rValue;
        mod->omiBSIM4lkt1lGiven = TRUE;
        break;
      case omiBSIM4_MOD_LKT2:
        mod->omiBSIM4lkt2 = value->rValue;
        mod->omiBSIM4lkt2Given = TRUE;
        break;
      case omiBSIM4_MOD_LK2:
        mod->omiBSIM4lk2 = value->rValue;
        mod->omiBSIM4lk2Given = TRUE;
        break;
      case omiBSIM4_MOD_LK3:
        mod->omiBSIM4lk3 = value->rValue;
        mod->omiBSIM4lk3Given = TRUE;
        break;
      case omiBSIM4_MOD_LK3B:
        mod->omiBSIM4lk3b = value->rValue;
        mod->omiBSIM4lk3bGiven = TRUE;
        break;
      case omiBSIM4_MOD_LLPE0:
        mod->omiBSIM4llpe0 = value->rValue;
        mod->omiBSIM4llpe0Given = TRUE;
        break;
      case omiBSIM4_MOD_LLPEB:
        mod->omiBSIM4llpeb = value->rValue;
        mod->omiBSIM4llpebGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDVTP0:
        mod->omiBSIM4ldvtp0 = value->rValue;
        mod->omiBSIM4ldvtp0Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVTP1:
        mod->omiBSIM4ldvtp1 = value->rValue;
        mod->omiBSIM4ldvtp1Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVTP2: /* New DIBL/Rout */
        mod->omiBSIM4ldvtp2 = value->rValue;
        mod->omiBSIM4ldvtp2Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVTP3:
        mod->omiBSIM4ldvtp3 = value->rValue;
        mod->omiBSIM4ldvtp3Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVTP4:
        mod->omiBSIM4ldvtp4 = value->rValue;
        mod->omiBSIM4ldvtp4Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVTP5:
        mod->omiBSIM4ldvtp5 = value->rValue;
        mod->omiBSIM4ldvtp5Given = TRUE;
        break;
      case omiBSIM4_MOD_LW0:
        mod->omiBSIM4lw0 = value->rValue;
        mod->omiBSIM4lw0Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVT0:
        mod->omiBSIM4ldvt0 = value->rValue;
        mod->omiBSIM4ldvt0Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVT1:
        mod->omiBSIM4ldvt1 = value->rValue;
        mod->omiBSIM4ldvt1Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVT2:
        mod->omiBSIM4ldvt2 = value->rValue;
        mod->omiBSIM4ldvt2Given = TRUE;
        break;
      case omiBSIM4_MOD_LDVT0W:
        mod->omiBSIM4ldvt0w = value->rValue;
        mod->omiBSIM4ldvt0wGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDVT1W:
        mod->omiBSIM4ldvt1w = value->rValue;
        mod->omiBSIM4ldvt1wGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDVT2W:
        mod->omiBSIM4ldvt2w = value->rValue;
        mod->omiBSIM4ldvt2wGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDROUT:
        mod->omiBSIM4ldrout = value->rValue;
        mod->omiBSIM4ldroutGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDSUB:
        mod->omiBSIM4ldsub = value->rValue;
        mod->omiBSIM4ldsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVTH0:
        mod->omiBSIM4lvth0 = value->rValue;
        mod->omiBSIM4lvth0Given = TRUE;
        break;
      case omiBSIM4_MOD_LUA:
        mod->omiBSIM4lua = value->rValue;
        mod->omiBSIM4luaGiven = TRUE;
        break;
      case omiBSIM4_MOD_LUA1:
        mod->omiBSIM4lua1 = value->rValue;
        mod->omiBSIM4lua1Given = TRUE;
        break;
      case omiBSIM4_MOD_LUB:
        mod->omiBSIM4lub = value->rValue;
        mod->omiBSIM4lubGiven = TRUE;
        break;
      case omiBSIM4_MOD_LUB1:
        mod->omiBSIM4lub1 = value->rValue;
        mod->omiBSIM4lub1Given = TRUE;
        break;
      case omiBSIM4_MOD_LUC:
        mod->omiBSIM4luc = value->rValue;
        mod->omiBSIM4lucGiven = TRUE;
        break;
      case omiBSIM4_MOD_LUC1:
        mod->omiBSIM4luc1 = value->rValue;
        mod->omiBSIM4luc1Given = TRUE;
        break;
      case omiBSIM4_MOD_LU0:
        mod->omiBSIM4lu0 = value->rValue;
        mod->omiBSIM4lu0Given = TRUE;
        break;
      case omiBSIM4_MOD_LUTE:
        mod->omiBSIM4lute = value->rValue;
        mod->omiBSIM4luteGiven = TRUE;
        break;
      case omiBSIM4_MOD_LUCSTE:
        mod->omiBSIM4lucste = value->rValue;
        mod->omiBSIM4lucsteGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVOFF:
        mod->omiBSIM4lvoff = value->rValue;
        mod->omiBSIM4lvoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_LTVOFF:
        mod->omiBSIM4ltvoff = value->rValue;
        mod->omiBSIM4ltvoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_LTNFACTOR: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4ltnfactor = value->rValue;
        mod->omiBSIM4ltnfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_LTETA0: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4lteta0 = value->rValue;
        mod->omiBSIM4lteta0Given = TRUE;
        break;
      case omiBSIM4_MOD_LTVOFFCV: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4ltvoffcv = value->rValue;
        mod->omiBSIM4ltvoffcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LMINV:
        mod->omiBSIM4lminv = value->rValue;
        mod->omiBSIM4lminvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LMINVCV:
        mod->omiBSIM4lminvcv = value->rValue;
        mod->omiBSIM4lminvcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LFPROUT:
        mod->omiBSIM4lfprout = value->rValue;
        mod->omiBSIM4lfproutGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPDITS:
        mod->omiBSIM4lpdits = value->rValue;
        mod->omiBSIM4lpditsGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPDITSD:
        mod->omiBSIM4lpditsd = value->rValue;
        mod->omiBSIM4lpditsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDELTA:
        mod->omiBSIM4ldelta = value->rValue;
        mod->omiBSIM4ldeltaGiven = TRUE;
        break;
      case omiBSIM4_MOD_LRDSW:
        mod->omiBSIM4lrdsw = value->rValue;
        mod->omiBSIM4lrdswGiven = TRUE;
        break;
      case omiBSIM4_MOD_LRDW:
        mod->omiBSIM4lrdw = value->rValue;
        mod->omiBSIM4lrdwGiven = TRUE;
        break;
      case omiBSIM4_MOD_LRSW:
        mod->omiBSIM4lrsw = value->rValue;
        mod->omiBSIM4lrswGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPRWB:
        mod->omiBSIM4lprwb = value->rValue;
        mod->omiBSIM4lprwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPRWG:
        mod->omiBSIM4lprwg = value->rValue;
        mod->omiBSIM4lprwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPRT:
        mod->omiBSIM4lprt = value->rValue;
        mod->omiBSIM4lprtGiven = TRUE;
        break;
      case omiBSIM4_MOD_LETA0:
        mod->omiBSIM4leta0 = value->rValue;
        mod->omiBSIM4leta0Given = TRUE;
        break;
      case omiBSIM4_MOD_LETAB:
        mod->omiBSIM4letab = value->rValue;
        mod->omiBSIM4letabGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPCLM:
        mod->omiBSIM4lpclm = value->rValue;
        mod->omiBSIM4lpclmGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPDIBL1:
        mod->omiBSIM4lpdibl1 = value->rValue;
        mod->omiBSIM4lpdibl1Given = TRUE;
        break;
      case omiBSIM4_MOD_LPDIBL2:
        mod->omiBSIM4lpdibl2 = value->rValue;
        mod->omiBSIM4lpdibl2Given = TRUE;
        break;
      case omiBSIM4_MOD_LPDIBLB:
        mod->omiBSIM4lpdiblb = value->rValue;
        mod->omiBSIM4lpdiblbGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPSCBE1:
        mod->omiBSIM4lpscbe1 = value->rValue;
        mod->omiBSIM4lpscbe1Given = TRUE;
        break;
      case omiBSIM4_MOD_LPSCBE2:
        mod->omiBSIM4lpscbe2 = value->rValue;
        mod->omiBSIM4lpscbe2Given = TRUE;
        break;
      case omiBSIM4_MOD_LPVAG:
        mod->omiBSIM4lpvag = value->rValue;
        mod->omiBSIM4lpvagGiven = TRUE;
        break;
      case omiBSIM4_MOD_LWR:
        mod->omiBSIM4lwr = value->rValue;
        mod->omiBSIM4lwrGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDWG:
        mod->omiBSIM4ldwg = value->rValue;
        mod->omiBSIM4ldwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_LDWB:
        mod->omiBSIM4ldwb = value->rValue;
        mod->omiBSIM4ldwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_LB0:
        mod->omiBSIM4lb0 = value->rValue;
        mod->omiBSIM4lb0Given = TRUE;
        break;
      case omiBSIM4_MOD_LB1:
        mod->omiBSIM4lb1 = value->rValue;
        mod->omiBSIM4lb1Given = TRUE;
        break;
      case omiBSIM4_MOD_LALPHA0:
        mod->omiBSIM4lalpha0 = value->rValue;
        mod->omiBSIM4lalpha0Given = TRUE;
        break;
      case omiBSIM4_MOD_LALPHA1:
        mod->omiBSIM4lalpha1 = value->rValue;
        mod->omiBSIM4lalpha1Given = TRUE;
        break;
      case omiBSIM4_MOD_LBETA0:
        mod->omiBSIM4lbeta0 = value->rValue;
        mod->omiBSIM4lbeta0Given = TRUE;
        break;
      case omiBSIM4_MOD_LPHIN:
        mod->omiBSIM4lphin = value->rValue;
        mod->omiBSIM4lphinGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAGIDL:
        mod->omiBSIM4lagidl = value->rValue;
        mod->omiBSIM4lagidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBGIDL:
        mod->omiBSIM4lbgidl = value->rValue;
        mod->omiBSIM4lbgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCGIDL:
        mod->omiBSIM4lcgidl = value->rValue;
        mod->omiBSIM4lcgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LEGIDL:
        mod->omiBSIM4legidl = value->rValue;
        mod->omiBSIM4legidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LFGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4lfgidl = value->rValue;
        mod->omiBSIM4lfgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LKGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4lkgidl = value->rValue;
        mod->omiBSIM4lkgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LRGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4lrgidl = value->rValue;
        mod->omiBSIM4lrgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAGISL:
        mod->omiBSIM4lagisl = value->rValue;
        mod->omiBSIM4lagislGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBGISL:
        mod->omiBSIM4lbgisl = value->rValue;
        mod->omiBSIM4lbgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCGISL:
        mod->omiBSIM4lcgisl = value->rValue;
        mod->omiBSIM4lcgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_LEGISL:
        mod->omiBSIM4legisl = value->rValue;
        mod->omiBSIM4legislGiven = TRUE;
        break;
      case omiBSIM4_MOD_LFGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4lfgisl = value->rValue;
        mod->omiBSIM4lfgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_LKGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4lkgisl = value->rValue;
        mod->omiBSIM4lkgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_LRGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4lrgisl = value->rValue;
        mod->omiBSIM4lrgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAIGC:
        mod->omiBSIM4laigc = value->rValue;
        mod->omiBSIM4laigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBIGC:
        mod->omiBSIM4lbigc = value->rValue;
        mod->omiBSIM4lbigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCIGC:
        mod->omiBSIM4lcigc = value->rValue;
        mod->omiBSIM4lcigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAIGSD:
        mod->omiBSIM4laigsd = value->rValue;
        mod->omiBSIM4laigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBIGSD:
        mod->omiBSIM4lbigsd = value->rValue;
        mod->omiBSIM4lbigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCIGSD:
        mod->omiBSIM4lcigsd = value->rValue;
        mod->omiBSIM4lcigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAIGS:
        mod->omiBSIM4laigs = value->rValue;
        mod->omiBSIM4laigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBIGS:
        mod->omiBSIM4lbigs = value->rValue;
        mod->omiBSIM4lbigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCIGS:
        mod->omiBSIM4lcigs = value->rValue;
        mod->omiBSIM4lcigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAIGD:
        mod->omiBSIM4laigd = value->rValue;
        mod->omiBSIM4laigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBIGD:
        mod->omiBSIM4lbigd = value->rValue;
        mod->omiBSIM4lbigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCIGD:
        mod->omiBSIM4lcigd = value->rValue;
        mod->omiBSIM4lcigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAIGBACC:
        mod->omiBSIM4laigbacc = value->rValue;
        mod->omiBSIM4laigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBIGBACC:
        mod->omiBSIM4lbigbacc = value->rValue;
        mod->omiBSIM4lbigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCIGBACC:
        mod->omiBSIM4lcigbacc = value->rValue;
        mod->omiBSIM4lcigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_LAIGBINV:
        mod->omiBSIM4laigbinv = value->rValue;
        mod->omiBSIM4laigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LBIGBINV:
        mod->omiBSIM4lbigbinv = value->rValue;
        mod->omiBSIM4lbigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCIGBINV:
        mod->omiBSIM4lcigbinv = value->rValue;
        mod->omiBSIM4lcigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNIGC:
        mod->omiBSIM4lnigc = value->rValue;
        mod->omiBSIM4lnigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNIGBINV:
        mod->omiBSIM4lnigbinv = value->rValue;
        mod->omiBSIM4lnigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNIGBACC:
        mod->omiBSIM4lnigbacc = value->rValue;
        mod->omiBSIM4lnigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNTOX:
        mod->omiBSIM4lntox = value->rValue;
        mod->omiBSIM4lntoxGiven = TRUE;
        break;
      case omiBSIM4_MOD_LEIGBINV:
        mod->omiBSIM4leigbinv = value->rValue;
        mod->omiBSIM4leigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPIGCD:
        mod->omiBSIM4lpigcd = value->rValue;
        mod->omiBSIM4lpigcdGiven = TRUE;
        break;
      case omiBSIM4_MOD_LPOXEDGE:
        mod->omiBSIM4lpoxedge = value->rValue;
        mod->omiBSIM4lpoxedgeGiven = TRUE;
        break;
      case omiBSIM4_MOD_LXRCRG1:
        mod->omiBSIM4lxrcrg1 = value->rValue;
        mod->omiBSIM4lxrcrg1Given = TRUE;
        break;
      case omiBSIM4_MOD_LXRCRG2:
        mod->omiBSIM4lxrcrg2 = value->rValue;
        mod->omiBSIM4lxrcrg2Given = TRUE;
        break;
      case omiBSIM4_MOD_LLAMBDA:
        mod->omiBSIM4llambda = value->rValue;
        mod->omiBSIM4llambdaGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVTL:
        mod->omiBSIM4lvtl = value->rValue;
        mod->omiBSIM4lvtlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LXN:
        mod->omiBSIM4lxn = value->rValue;
        mod->omiBSIM4lxnGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVFBSDOFF:
        mod->omiBSIM4lvfbsdoff = value->rValue;
        mod->omiBSIM4lvfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_LTVFBSDOFF:
        mod->omiBSIM4ltvfbsdoff = value->rValue;
        mod->omiBSIM4ltvfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_LEU:
        mod->omiBSIM4leu = value->rValue;
        mod->omiBSIM4leuGiven = TRUE;
        break;
      case omiBSIM4_MOD_LUCS:
        mod->omiBSIM4lucs = value->rValue;
        mod->omiBSIM4lucsGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVFB:
        mod->omiBSIM4lvfb = value->rValue;
        mod->omiBSIM4lvfbGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCGSL:
        mod->omiBSIM4lcgsl = value->rValue;
        mod->omiBSIM4lcgslGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCGDL:
        mod->omiBSIM4lcgdl = value->rValue;
        mod->omiBSIM4lcgdlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCKAPPAS:
        mod->omiBSIM4lckappas = value->rValue;
        mod->omiBSIM4lckappasGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCKAPPAD:
        mod->omiBSIM4lckappad = value->rValue;
        mod->omiBSIM4lckappadGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCF:
        mod->omiBSIM4lcf = value->rValue;
        mod->omiBSIM4lcfGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCLC:
        mod->omiBSIM4lclc = value->rValue;
        mod->omiBSIM4lclcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LCLE:
        mod->omiBSIM4lcle = value->rValue;
        mod->omiBSIM4lcleGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVFBCV:
        mod->omiBSIM4lvfbcv = value->rValue;
        mod->omiBSIM4lvfbcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_LACDE:
        mod->omiBSIM4lacde = value->rValue;
        mod->omiBSIM4lacdeGiven = TRUE;
        break;
      case omiBSIM4_MOD_LMOIN:
        mod->omiBSIM4lmoin = value->rValue;
        mod->omiBSIM4lmoinGiven = TRUE;
        break;
      case omiBSIM4_MOD_LNOFF:
        mod->omiBSIM4lnoff = value->rValue;
        mod->omiBSIM4lnoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_LVOFFCV:
        mod->omiBSIM4lvoffcv = value->rValue;
        mod->omiBSIM4lvoffcvGiven = TRUE;
        break;

      /* Width dependence */
      case omiBSIM4_MOD_WCDSC:
        mod->omiBSIM4wcdsc = value->rValue;
        mod->omiBSIM4wcdscGiven = TRUE;
        break;

      case omiBSIM4_MOD_WCDSCB:
        mod->omiBSIM4wcdscb = value->rValue;
        mod->omiBSIM4wcdscbGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCDSCD:
        mod->omiBSIM4wcdscd = value->rValue;
        mod->omiBSIM4wcdscdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCIT:
        mod->omiBSIM4wcit = value->rValue;
        mod->omiBSIM4wcitGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNFACTOR:
        mod->omiBSIM4wnfactor = value->rValue;
        mod->omiBSIM4wnfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_WXJ:
        mod->omiBSIM4wxj = value->rValue;
        mod->omiBSIM4wxjGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVSAT:
        mod->omiBSIM4wvsat = value->rValue;
        mod->omiBSIM4wvsatGiven = TRUE;
        break;

      case omiBSIM4_MOD_WA0:
        mod->omiBSIM4wa0 = value->rValue;
        mod->omiBSIM4wa0Given = TRUE;
        break;
      case omiBSIM4_MOD_WAGS:
        mod->omiBSIM4wags = value->rValue;
        mod->omiBSIM4wagsGiven = TRUE;
        break;
      case omiBSIM4_MOD_WA1:
        mod->omiBSIM4wa1 = value->rValue;
        mod->omiBSIM4wa1Given = TRUE;
        break;
      case omiBSIM4_MOD_WA2:
        mod->omiBSIM4wa2 = value->rValue;
        mod->omiBSIM4wa2Given = TRUE;
        break;
      case omiBSIM4_MOD_WAT:
        mod->omiBSIM4wat = value->rValue;
        mod->omiBSIM4watGiven = TRUE;
        break;
      case omiBSIM4_MOD_WKETA:
        mod->omiBSIM4wketa = value->rValue;
        mod->omiBSIM4wketaGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNSUB:
        mod->omiBSIM4wnsub = value->rValue;
        mod->omiBSIM4wnsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNDEP:
        mod->omiBSIM4wndep = value->rValue;
        mod->omiBSIM4wndepGiven = TRUE;
        if (mod->omiBSIM4wndep > 1.0e20) mod->omiBSIM4wndep *= 1.0e-6;
        break;
      case omiBSIM4_MOD_WNSD:
        mod->omiBSIM4wnsd = value->rValue;
        mod->omiBSIM4wnsdGiven = TRUE;
        if (mod->omiBSIM4wnsd > 1.0e23) mod->omiBSIM4wnsd *= 1.0e-6;
        break;
      case omiBSIM4_MOD_WNGATE:
        mod->omiBSIM4wngate = value->rValue;
        mod->omiBSIM4wngateGiven = TRUE;
        if (mod->omiBSIM4wngate > 1.0e23) mod->omiBSIM4wngate *= 1.0e-6;
        break;
      case omiBSIM4_MOD_WGAMMA1:
        mod->omiBSIM4wgamma1 = value->rValue;
        mod->omiBSIM4wgamma1Given = TRUE;
        break;
      case omiBSIM4_MOD_WGAMMA2:
        mod->omiBSIM4wgamma2 = value->rValue;
        mod->omiBSIM4wgamma2Given = TRUE;
        break;
      case omiBSIM4_MOD_WVBX:
        mod->omiBSIM4wvbx = value->rValue;
        mod->omiBSIM4wvbxGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVBM:
        mod->omiBSIM4wvbm = value->rValue;
        mod->omiBSIM4wvbmGiven = TRUE;
        break;
      case omiBSIM4_MOD_WXT:
        mod->omiBSIM4wxt = value->rValue;
        mod->omiBSIM4wxtGiven = TRUE;
        break;
      case omiBSIM4_MOD_WK1:
        mod->omiBSIM4wk1 = value->rValue;
        mod->omiBSIM4wk1Given = TRUE;
        break;
      case omiBSIM4_MOD_WKT1:
        mod->omiBSIM4wkt1 = value->rValue;
        mod->omiBSIM4wkt1Given = TRUE;
        break;
      case omiBSIM4_MOD_WKT1L:
        mod->omiBSIM4wkt1l = value->rValue;
        mod->omiBSIM4wkt1lGiven = TRUE;
        break;
      case omiBSIM4_MOD_WKT2:
        mod->omiBSIM4wkt2 = value->rValue;
        mod->omiBSIM4wkt2Given = TRUE;
        break;
      case omiBSIM4_MOD_WK2:
        mod->omiBSIM4wk2 = value->rValue;
        mod->omiBSIM4wk2Given = TRUE;
        break;
      case omiBSIM4_MOD_WK3:
        mod->omiBSIM4wk3 = value->rValue;
        mod->omiBSIM4wk3Given = TRUE;
        break;
      case omiBSIM4_MOD_WK3B:
        mod->omiBSIM4wk3b = value->rValue;
        mod->omiBSIM4wk3bGiven = TRUE;
        break;
      case omiBSIM4_MOD_WLPE0:
        mod->omiBSIM4wlpe0 = value->rValue;
        mod->omiBSIM4wlpe0Given = TRUE;
        break;
      case omiBSIM4_MOD_WLPEB:
        mod->omiBSIM4wlpeb = value->rValue;
        mod->omiBSIM4wlpebGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDVTP0:
        mod->omiBSIM4wdvtp0 = value->rValue;
        mod->omiBSIM4wdvtp0Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVTP1:
        mod->omiBSIM4wdvtp1 = value->rValue;
        mod->omiBSIM4wdvtp1Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVTP2: /* New DIBL/Rout */
        mod->omiBSIM4wdvtp2 = value->rValue;
        mod->omiBSIM4wdvtp2Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVTP3:
        mod->omiBSIM4wdvtp3 = value->rValue;
        mod->omiBSIM4wdvtp3Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVTP4:
        mod->omiBSIM4wdvtp4 = value->rValue;
        mod->omiBSIM4wdvtp4Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVTP5:
        mod->omiBSIM4wdvtp5 = value->rValue;
        mod->omiBSIM4wdvtp5Given = TRUE;
        break;
      case omiBSIM4_MOD_WW0:
        mod->omiBSIM4ww0 = value->rValue;
        mod->omiBSIM4ww0Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVT0:
        mod->omiBSIM4wdvt0 = value->rValue;
        mod->omiBSIM4wdvt0Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVT1:
        mod->omiBSIM4wdvt1 = value->rValue;
        mod->omiBSIM4wdvt1Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVT2:
        mod->omiBSIM4wdvt2 = value->rValue;
        mod->omiBSIM4wdvt2Given = TRUE;
        break;
      case omiBSIM4_MOD_WDVT0W:
        mod->omiBSIM4wdvt0w = value->rValue;
        mod->omiBSIM4wdvt0wGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDVT1W:
        mod->omiBSIM4wdvt1w = value->rValue;
        mod->omiBSIM4wdvt1wGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDVT2W:
        mod->omiBSIM4wdvt2w = value->rValue;
        mod->omiBSIM4wdvt2wGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDROUT:
        mod->omiBSIM4wdrout = value->rValue;
        mod->omiBSIM4wdroutGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDSUB:
        mod->omiBSIM4wdsub = value->rValue;
        mod->omiBSIM4wdsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVTH0:
        mod->omiBSIM4wvth0 = value->rValue;
        mod->omiBSIM4wvth0Given = TRUE;
        break;
      case omiBSIM4_MOD_WUA:
        mod->omiBSIM4wua = value->rValue;
        mod->omiBSIM4wuaGiven = TRUE;
        break;
      case omiBSIM4_MOD_WUA1:
        mod->omiBSIM4wua1 = value->rValue;
        mod->omiBSIM4wua1Given = TRUE;
        break;
      case omiBSIM4_MOD_WUB:
        mod->omiBSIM4wub = value->rValue;
        mod->omiBSIM4wubGiven = TRUE;
        break;
      case omiBSIM4_MOD_WUB1:
        mod->omiBSIM4wub1 = value->rValue;
        mod->omiBSIM4wub1Given = TRUE;
        break;
      case omiBSIM4_MOD_WUC:
        mod->omiBSIM4wuc = value->rValue;
        mod->omiBSIM4wucGiven = TRUE;
        break;
      case omiBSIM4_MOD_WUC1:
        mod->omiBSIM4wuc1 = value->rValue;
        mod->omiBSIM4wuc1Given = TRUE;
        break;
      case omiBSIM4_MOD_WU0:
        mod->omiBSIM4wu0 = value->rValue;
        mod->omiBSIM4wu0Given = TRUE;
        break;
      case omiBSIM4_MOD_WUTE:
        mod->omiBSIM4wute = value->rValue;
        mod->omiBSIM4wuteGiven = TRUE;
        break;
      case omiBSIM4_MOD_WUCSTE:
        mod->omiBSIM4wucste = value->rValue;
        mod->omiBSIM4wucsteGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVOFF:
        mod->omiBSIM4wvoff = value->rValue;
        mod->omiBSIM4wvoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_WTVOFF:
        mod->omiBSIM4wtvoff = value->rValue;
        mod->omiBSIM4wtvoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_WTNFACTOR: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4wtnfactor = value->rValue;
        mod->omiBSIM4wtnfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_WTETA0: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4wteta0 = value->rValue;
        mod->omiBSIM4wteta0Given = TRUE;
        break;
      case omiBSIM4_MOD_WTVOFFCV: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4wtvoffcv = value->rValue;
        mod->omiBSIM4wtvoffcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WMINV:
        mod->omiBSIM4wminv = value->rValue;
        mod->omiBSIM4wminvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WMINVCV:
        mod->omiBSIM4wminvcv = value->rValue;
        mod->omiBSIM4wminvcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WFPROUT:
        mod->omiBSIM4wfprout = value->rValue;
        mod->omiBSIM4wfproutGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPDITS:
        mod->omiBSIM4wpdits = value->rValue;
        mod->omiBSIM4wpditsGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPDITSD:
        mod->omiBSIM4wpditsd = value->rValue;
        mod->omiBSIM4wpditsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDELTA:
        mod->omiBSIM4wdelta = value->rValue;
        mod->omiBSIM4wdeltaGiven = TRUE;
        break;
      case omiBSIM4_MOD_WRDSW:
        mod->omiBSIM4wrdsw = value->rValue;
        mod->omiBSIM4wrdswGiven = TRUE;
        break;
      case omiBSIM4_MOD_WRDW:
        mod->omiBSIM4wrdw = value->rValue;
        mod->omiBSIM4wrdwGiven = TRUE;
        break;
      case omiBSIM4_MOD_WRSW:
        mod->omiBSIM4wrsw = value->rValue;
        mod->omiBSIM4wrswGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPRWB:
        mod->omiBSIM4wprwb = value->rValue;
        mod->omiBSIM4wprwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPRWG:
        mod->omiBSIM4wprwg = value->rValue;
        mod->omiBSIM4wprwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPRT:
        mod->omiBSIM4wprt = value->rValue;
        mod->omiBSIM4wprtGiven = TRUE;
        break;
      case omiBSIM4_MOD_WETA0:
        mod->omiBSIM4weta0 = value->rValue;
        mod->omiBSIM4weta0Given = TRUE;
        break;
      case omiBSIM4_MOD_WETAB:
        mod->omiBSIM4wetab = value->rValue;
        mod->omiBSIM4wetabGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPCLM:
        mod->omiBSIM4wpclm = value->rValue;
        mod->omiBSIM4wpclmGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPDIBL1:
        mod->omiBSIM4wpdibl1 = value->rValue;
        mod->omiBSIM4wpdibl1Given = TRUE;
        break;
      case omiBSIM4_MOD_WPDIBL2:
        mod->omiBSIM4wpdibl2 = value->rValue;
        mod->omiBSIM4wpdibl2Given = TRUE;
        break;
      case omiBSIM4_MOD_WPDIBLB:
        mod->omiBSIM4wpdiblb = value->rValue;
        mod->omiBSIM4wpdiblbGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPSCBE1:
        mod->omiBSIM4wpscbe1 = value->rValue;
        mod->omiBSIM4wpscbe1Given = TRUE;
        break;
      case omiBSIM4_MOD_WPSCBE2:
        mod->omiBSIM4wpscbe2 = value->rValue;
        mod->omiBSIM4wpscbe2Given = TRUE;
        break;
      case omiBSIM4_MOD_WPVAG:
        mod->omiBSIM4wpvag = value->rValue;
        mod->omiBSIM4wpvagGiven = TRUE;
        break;
      case omiBSIM4_MOD_WWR:
        mod->omiBSIM4wwr = value->rValue;
        mod->omiBSIM4wwrGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDWG:
        mod->omiBSIM4wdwg = value->rValue;
        mod->omiBSIM4wdwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_WDWB:
        mod->omiBSIM4wdwb = value->rValue;
        mod->omiBSIM4wdwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_WB0:
        mod->omiBSIM4wb0 = value->rValue;
        mod->omiBSIM4wb0Given = TRUE;
        break;
      case omiBSIM4_MOD_WB1:
        mod->omiBSIM4wb1 = value->rValue;
        mod->omiBSIM4wb1Given = TRUE;
        break;
      case omiBSIM4_MOD_WALPHA0:
        mod->omiBSIM4walpha0 = value->rValue;
        mod->omiBSIM4walpha0Given = TRUE;
        break;
      case omiBSIM4_MOD_WALPHA1:
        mod->omiBSIM4walpha1 = value->rValue;
        mod->omiBSIM4walpha1Given = TRUE;
        break;
      case omiBSIM4_MOD_WBETA0:
        mod->omiBSIM4wbeta0 = value->rValue;
        mod->omiBSIM4wbeta0Given = TRUE;
        break;
      case omiBSIM4_MOD_WPHIN:
        mod->omiBSIM4wphin = value->rValue;
        mod->omiBSIM4wphinGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAGIDL:
        mod->omiBSIM4wagidl = value->rValue;
        mod->omiBSIM4wagidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBGIDL:
        mod->omiBSIM4wbgidl = value->rValue;
        mod->omiBSIM4wbgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCGIDL:
        mod->omiBSIM4wcgidl = value->rValue;
        mod->omiBSIM4wcgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WEGIDL:
        mod->omiBSIM4wegidl = value->rValue;
        mod->omiBSIM4wegidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WFGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4wfgidl = value->rValue;
        mod->omiBSIM4wfgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WKGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4wkgidl = value->rValue;
        mod->omiBSIM4wkgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WRGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4wrgidl = value->rValue;
        mod->omiBSIM4wrgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAGISL:
        mod->omiBSIM4wagisl = value->rValue;
        mod->omiBSIM4wagislGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBGISL:
        mod->omiBSIM4wbgisl = value->rValue;
        mod->omiBSIM4wbgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCGISL:
        mod->omiBSIM4wcgisl = value->rValue;
        mod->omiBSIM4wcgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_WEGISL:
        mod->omiBSIM4wegisl = value->rValue;
        mod->omiBSIM4wegislGiven = TRUE;
        break;
      case omiBSIM4_MOD_WFGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4wfgisl = value->rValue;
        mod->omiBSIM4wfgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_WKGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4wkgisl = value->rValue;
        mod->omiBSIM4wkgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_WRGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4wrgisl = value->rValue;
        mod->omiBSIM4wrgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAIGC:
        mod->omiBSIM4waigc = value->rValue;
        mod->omiBSIM4waigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBIGC:
        mod->omiBSIM4wbigc = value->rValue;
        mod->omiBSIM4wbigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCIGC:
        mod->omiBSIM4wcigc = value->rValue;
        mod->omiBSIM4wcigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAIGSD:
        mod->omiBSIM4waigsd = value->rValue;
        mod->omiBSIM4waigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBIGSD:
        mod->omiBSIM4wbigsd = value->rValue;
        mod->omiBSIM4wbigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCIGSD:
        mod->omiBSIM4wcigsd = value->rValue;
        mod->omiBSIM4wcigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAIGS:
        mod->omiBSIM4waigs = value->rValue;
        mod->omiBSIM4waigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBIGS:
        mod->omiBSIM4wbigs = value->rValue;
        mod->omiBSIM4wbigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCIGS:
        mod->omiBSIM4wcigs = value->rValue;
        mod->omiBSIM4wcigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAIGD:
        mod->omiBSIM4waigd = value->rValue;
        mod->omiBSIM4waigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBIGD:
        mod->omiBSIM4wbigd = value->rValue;
        mod->omiBSIM4wbigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCIGD:
        mod->omiBSIM4wcigd = value->rValue;
        mod->omiBSIM4wcigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAIGBACC:
        mod->omiBSIM4waigbacc = value->rValue;
        mod->omiBSIM4waigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBIGBACC:
        mod->omiBSIM4wbigbacc = value->rValue;
        mod->omiBSIM4wbigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCIGBACC:
        mod->omiBSIM4wcigbacc = value->rValue;
        mod->omiBSIM4wcigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_WAIGBINV:
        mod->omiBSIM4waigbinv = value->rValue;
        mod->omiBSIM4waigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WBIGBINV:
        mod->omiBSIM4wbigbinv = value->rValue;
        mod->omiBSIM4wbigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCIGBINV:
        mod->omiBSIM4wcigbinv = value->rValue;
        mod->omiBSIM4wcigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNIGC:
        mod->omiBSIM4wnigc = value->rValue;
        mod->omiBSIM4wnigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNIGBINV:
        mod->omiBSIM4wnigbinv = value->rValue;
        mod->omiBSIM4wnigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNIGBACC:
        mod->omiBSIM4wnigbacc = value->rValue;
        mod->omiBSIM4wnigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNTOX:
        mod->omiBSIM4wntox = value->rValue;
        mod->omiBSIM4wntoxGiven = TRUE;
        break;
      case omiBSIM4_MOD_WEIGBINV:
        mod->omiBSIM4weigbinv = value->rValue;
        mod->omiBSIM4weigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPIGCD:
        mod->omiBSIM4wpigcd = value->rValue;
        mod->omiBSIM4wpigcdGiven = TRUE;
        break;
      case omiBSIM4_MOD_WPOXEDGE:
        mod->omiBSIM4wpoxedge = value->rValue;
        mod->omiBSIM4wpoxedgeGiven = TRUE;
        break;
      case omiBSIM4_MOD_WXRCRG1:
        mod->omiBSIM4wxrcrg1 = value->rValue;
        mod->omiBSIM4wxrcrg1Given = TRUE;
        break;
      case omiBSIM4_MOD_WXRCRG2:
        mod->omiBSIM4wxrcrg2 = value->rValue;
        mod->omiBSIM4wxrcrg2Given = TRUE;
        break;
      case omiBSIM4_MOD_WLAMBDA:
        mod->omiBSIM4wlambda = value->rValue;
        mod->omiBSIM4wlambdaGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVTL:
        mod->omiBSIM4wvtl = value->rValue;
        mod->omiBSIM4wvtlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WXN:
        mod->omiBSIM4wxn = value->rValue;
        mod->omiBSIM4wxnGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVFBSDOFF:
        mod->omiBSIM4wvfbsdoff = value->rValue;
        mod->omiBSIM4wvfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_WTVFBSDOFF:
        mod->omiBSIM4wtvfbsdoff = value->rValue;
        mod->omiBSIM4wtvfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_WEU:
        mod->omiBSIM4weu = value->rValue;
        mod->omiBSIM4weuGiven = TRUE;
        break;
      case omiBSIM4_MOD_WUCS:
        mod->omiBSIM4wucs = value->rValue;
        mod->omiBSIM4wucsGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVFB:
        mod->omiBSIM4wvfb = value->rValue;
        mod->omiBSIM4wvfbGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCGSL:
        mod->omiBSIM4wcgsl = value->rValue;
        mod->omiBSIM4wcgslGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCGDL:
        mod->omiBSIM4wcgdl = value->rValue;
        mod->omiBSIM4wcgdlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCKAPPAS:
        mod->omiBSIM4wckappas = value->rValue;
        mod->omiBSIM4wckappasGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCKAPPAD:
        mod->omiBSIM4wckappad = value->rValue;
        mod->omiBSIM4wckappadGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCF:
        mod->omiBSIM4wcf = value->rValue;
        mod->omiBSIM4wcfGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCLC:
        mod->omiBSIM4wclc = value->rValue;
        mod->omiBSIM4wclcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WCLE:
        mod->omiBSIM4wcle = value->rValue;
        mod->omiBSIM4wcleGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVFBCV:
        mod->omiBSIM4wvfbcv = value->rValue;
        mod->omiBSIM4wvfbcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_WACDE:
        mod->omiBSIM4wacde = value->rValue;
        mod->omiBSIM4wacdeGiven = TRUE;
        break;
      case omiBSIM4_MOD_WMOIN:
        mod->omiBSIM4wmoin = value->rValue;
        mod->omiBSIM4wmoinGiven = TRUE;
        break;
      case omiBSIM4_MOD_WNOFF:
        mod->omiBSIM4wnoff = value->rValue;
        mod->omiBSIM4wnoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_WVOFFCV:
        mod->omiBSIM4wvoffcv = value->rValue;
        mod->omiBSIM4wvoffcvGiven = TRUE;
        break;

      /* Cross-term dependence */
      case omiBSIM4_MOD_PCDSC:
        mod->omiBSIM4pcdsc = value->rValue;
        mod->omiBSIM4pcdscGiven = TRUE;
        break;

      case omiBSIM4_MOD_PCDSCB:
        mod->omiBSIM4pcdscb = value->rValue;
        mod->omiBSIM4pcdscbGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCDSCD:
        mod->omiBSIM4pcdscd = value->rValue;
        mod->omiBSIM4pcdscdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCIT:
        mod->omiBSIM4pcit = value->rValue;
        mod->omiBSIM4pcitGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNFACTOR:
        mod->omiBSIM4pnfactor = value->rValue;
        mod->omiBSIM4pnfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_PXJ:
        mod->omiBSIM4pxj = value->rValue;
        mod->omiBSIM4pxjGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVSAT:
        mod->omiBSIM4pvsat = value->rValue;
        mod->omiBSIM4pvsatGiven = TRUE;
        break;

      case omiBSIM4_MOD_PA0:
        mod->omiBSIM4pa0 = value->rValue;
        mod->omiBSIM4pa0Given = TRUE;
        break;
      case omiBSIM4_MOD_PAGS:
        mod->omiBSIM4pags = value->rValue;
        mod->omiBSIM4pagsGiven = TRUE;
        break;
      case omiBSIM4_MOD_PA1:
        mod->omiBSIM4pa1 = value->rValue;
        mod->omiBSIM4pa1Given = TRUE;
        break;
      case omiBSIM4_MOD_PA2:
        mod->omiBSIM4pa2 = value->rValue;
        mod->omiBSIM4pa2Given = TRUE;
        break;
      case omiBSIM4_MOD_PAT:
        mod->omiBSIM4pat = value->rValue;
        mod->omiBSIM4patGiven = TRUE;
        break;
      case omiBSIM4_MOD_PKETA:
        mod->omiBSIM4pketa = value->rValue;
        mod->omiBSIM4pketaGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNSUB:
        mod->omiBSIM4pnsub = value->rValue;
        mod->omiBSIM4pnsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNDEP:
        mod->omiBSIM4pndep = value->rValue;
        mod->omiBSIM4pndepGiven = TRUE;
        if (mod->omiBSIM4pndep > 1.0e20) mod->omiBSIM4pndep *= 1.0e-6;
        break;
      case omiBSIM4_MOD_PNSD:
        mod->omiBSIM4pnsd = value->rValue;
        mod->omiBSIM4pnsdGiven = TRUE;
        if (mod->omiBSIM4pnsd > 1.0e23) mod->omiBSIM4pnsd *= 1.0e-6;
        break;
      case omiBSIM4_MOD_PNGATE:
        mod->omiBSIM4pngate = value->rValue;
        mod->omiBSIM4pngateGiven = TRUE;
        if (mod->omiBSIM4pngate > 1.0e23) mod->omiBSIM4pngate *= 1.0e-6;
        break;
      case omiBSIM4_MOD_PGAMMA1:
        mod->omiBSIM4pgamma1 = value->rValue;
        mod->omiBSIM4pgamma1Given = TRUE;
        break;
      case omiBSIM4_MOD_PGAMMA2:
        mod->omiBSIM4pgamma2 = value->rValue;
        mod->omiBSIM4pgamma2Given = TRUE;
        break;
      case omiBSIM4_MOD_PVBX:
        mod->omiBSIM4pvbx = value->rValue;
        mod->omiBSIM4pvbxGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVBM:
        mod->omiBSIM4pvbm = value->rValue;
        mod->omiBSIM4pvbmGiven = TRUE;
        break;
      case omiBSIM4_MOD_PXT:
        mod->omiBSIM4pxt = value->rValue;
        mod->omiBSIM4pxtGiven = TRUE;
        break;
      case omiBSIM4_MOD_PK1:
        mod->omiBSIM4pk1 = value->rValue;
        mod->omiBSIM4pk1Given = TRUE;
        break;
      case omiBSIM4_MOD_PKT1:
        mod->omiBSIM4pkt1 = value->rValue;
        mod->omiBSIM4pkt1Given = TRUE;
        break;
      case omiBSIM4_MOD_PKT1L:
        mod->omiBSIM4pkt1l = value->rValue;
        mod->omiBSIM4pkt1lGiven = TRUE;
        break;
      case omiBSIM4_MOD_PKT2:
        mod->omiBSIM4pkt2 = value->rValue;
        mod->omiBSIM4pkt2Given = TRUE;
        break;
      case omiBSIM4_MOD_PK2:
        mod->omiBSIM4pk2 = value->rValue;
        mod->omiBSIM4pk2Given = TRUE;
        break;
      case omiBSIM4_MOD_PK3:
        mod->omiBSIM4pk3 = value->rValue;
        mod->omiBSIM4pk3Given = TRUE;
        break;
      case omiBSIM4_MOD_PK3B:
        mod->omiBSIM4pk3b = value->rValue;
        mod->omiBSIM4pk3bGiven = TRUE;
        break;
      case omiBSIM4_MOD_PLPE0:
        mod->omiBSIM4plpe0 = value->rValue;
        mod->omiBSIM4plpe0Given = TRUE;
        break;
      case omiBSIM4_MOD_PLPEB:
        mod->omiBSIM4plpeb = value->rValue;
        mod->omiBSIM4plpebGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDVTP0:
        mod->omiBSIM4pdvtp0 = value->rValue;
        mod->omiBSIM4pdvtp0Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVTP1:
        mod->omiBSIM4pdvtp1 = value->rValue;
        mod->omiBSIM4pdvtp1Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVTP2: /* New DIBL/Rout */
        mod->omiBSIM4pdvtp2 = value->rValue;
        mod->omiBSIM4pdvtp2Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVTP3:
        mod->omiBSIM4pdvtp3 = value->rValue;
        mod->omiBSIM4pdvtp3Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVTP4:
        mod->omiBSIM4pdvtp4 = value->rValue;
        mod->omiBSIM4pdvtp4Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVTP5:
        mod->omiBSIM4pdvtp5 = value->rValue;
        mod->omiBSIM4pdvtp5Given = TRUE;
        break;
      case omiBSIM4_MOD_PW0:
        mod->omiBSIM4pw0 = value->rValue;
        mod->omiBSIM4pw0Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVT0:
        mod->omiBSIM4pdvt0 = value->rValue;
        mod->omiBSIM4pdvt0Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVT1:
        mod->omiBSIM4pdvt1 = value->rValue;
        mod->omiBSIM4pdvt1Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVT2:
        mod->omiBSIM4pdvt2 = value->rValue;
        mod->omiBSIM4pdvt2Given = TRUE;
        break;
      case omiBSIM4_MOD_PDVT0W:
        mod->omiBSIM4pdvt0w = value->rValue;
        mod->omiBSIM4pdvt0wGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDVT1W:
        mod->omiBSIM4pdvt1w = value->rValue;
        mod->omiBSIM4pdvt1wGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDVT2W:
        mod->omiBSIM4pdvt2w = value->rValue;
        mod->omiBSIM4pdvt2wGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDROUT:
        mod->omiBSIM4pdrout = value->rValue;
        mod->omiBSIM4pdroutGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDSUB:
        mod->omiBSIM4pdsub = value->rValue;
        mod->omiBSIM4pdsubGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVTH0:
        mod->omiBSIM4pvth0 = value->rValue;
        mod->omiBSIM4pvth0Given = TRUE;
        break;
      case omiBSIM4_MOD_PUA:
        mod->omiBSIM4pua = value->rValue;
        mod->omiBSIM4puaGiven = TRUE;
        break;
      case omiBSIM4_MOD_PUA1:
        mod->omiBSIM4pua1 = value->rValue;
        mod->omiBSIM4pua1Given = TRUE;
        break;
      case omiBSIM4_MOD_PUB:
        mod->omiBSIM4pub = value->rValue;
        mod->omiBSIM4pubGiven = TRUE;
        break;
      case omiBSIM4_MOD_PUB1:
        mod->omiBSIM4pub1 = value->rValue;
        mod->omiBSIM4pub1Given = TRUE;
        break;
      case omiBSIM4_MOD_PUC:
        mod->omiBSIM4puc = value->rValue;
        mod->omiBSIM4pucGiven = TRUE;
        break;
      case omiBSIM4_MOD_PUC1:
        mod->omiBSIM4puc1 = value->rValue;
        mod->omiBSIM4puc1Given = TRUE;
        break;
      case omiBSIM4_MOD_PU0:
        mod->omiBSIM4pu0 = value->rValue;
        mod->omiBSIM4pu0Given = TRUE;
        break;
      case omiBSIM4_MOD_PUTE:
        mod->omiBSIM4pute = value->rValue;
        mod->omiBSIM4puteGiven = TRUE;
        break;
      case omiBSIM4_MOD_PUCSTE:
        mod->omiBSIM4pucste = value->rValue;
        mod->omiBSIM4pucsteGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVOFF:
        mod->omiBSIM4pvoff = value->rValue;
        mod->omiBSIM4pvoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PTVOFF:
        mod->omiBSIM4ptvoff = value->rValue;
        mod->omiBSIM4ptvoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PTNFACTOR: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4ptnfactor = value->rValue;
        mod->omiBSIM4ptnfactorGiven = TRUE;
        break;
      case omiBSIM4_MOD_PTETA0: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4pteta0 = value->rValue;
        mod->omiBSIM4pteta0Given = TRUE;
        break;
      case omiBSIM4_MOD_PTVOFFCV: /* v4.7 temp dep of leakage current  */
        mod->omiBSIM4ptvoffcv = value->rValue;
        mod->omiBSIM4ptvoffcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PMINV:
        mod->omiBSIM4pminv = value->rValue;
        mod->omiBSIM4pminvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PMINVCV:
        mod->omiBSIM4pminvcv = value->rValue;
        mod->omiBSIM4pminvcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PFPROUT:
        mod->omiBSIM4pfprout = value->rValue;
        mod->omiBSIM4pfproutGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPDITS:
        mod->omiBSIM4ppdits = value->rValue;
        mod->omiBSIM4ppditsGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPDITSD:
        mod->omiBSIM4ppditsd = value->rValue;
        mod->omiBSIM4ppditsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDELTA:
        mod->omiBSIM4pdelta = value->rValue;
        mod->omiBSIM4pdeltaGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRDSW:
        mod->omiBSIM4prdsw = value->rValue;
        mod->omiBSIM4prdswGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRDW:
        mod->omiBSIM4prdw = value->rValue;
        mod->omiBSIM4prdwGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRSW:
        mod->omiBSIM4prsw = value->rValue;
        mod->omiBSIM4prswGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPRWB:
        mod->omiBSIM4pprwb = value->rValue;
        mod->omiBSIM4pprwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPRWG:
        mod->omiBSIM4pprwg = value->rValue;
        mod->omiBSIM4pprwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPRT:
        mod->omiBSIM4pprt = value->rValue;
        mod->omiBSIM4pprtGiven = TRUE;
        break;
      case omiBSIM4_MOD_PETA0:
        mod->omiBSIM4peta0 = value->rValue;
        mod->omiBSIM4peta0Given = TRUE;
        break;
      case omiBSIM4_MOD_PETAB:
        mod->omiBSIM4petab = value->rValue;
        mod->omiBSIM4petabGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPCLM:
        mod->omiBSIM4ppclm = value->rValue;
        mod->omiBSIM4ppclmGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPDIBL1:
        mod->omiBSIM4ppdibl1 = value->rValue;
        mod->omiBSIM4ppdibl1Given = TRUE;
        break;
      case omiBSIM4_MOD_PPDIBL2:
        mod->omiBSIM4ppdibl2 = value->rValue;
        mod->omiBSIM4ppdibl2Given = TRUE;
        break;
      case omiBSIM4_MOD_PPDIBLB:
        mod->omiBSIM4ppdiblb = value->rValue;
        mod->omiBSIM4ppdiblbGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPSCBE1:
        mod->omiBSIM4ppscbe1 = value->rValue;
        mod->omiBSIM4ppscbe1Given = TRUE;
        break;
      case omiBSIM4_MOD_PPSCBE2:
        mod->omiBSIM4ppscbe2 = value->rValue;
        mod->omiBSIM4ppscbe2Given = TRUE;
        break;
      case omiBSIM4_MOD_PPVAG:
        mod->omiBSIM4ppvag = value->rValue;
        mod->omiBSIM4ppvagGiven = TRUE;
        break;
      case omiBSIM4_MOD_PWR:
        mod->omiBSIM4pwr = value->rValue;
        mod->omiBSIM4pwrGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDWG:
        mod->omiBSIM4pdwg = value->rValue;
        mod->omiBSIM4pdwgGiven = TRUE;
        break;
      case omiBSIM4_MOD_PDWB:
        mod->omiBSIM4pdwb = value->rValue;
        mod->omiBSIM4pdwbGiven = TRUE;
        break;
      case omiBSIM4_MOD_PB0:
        mod->omiBSIM4pb0 = value->rValue;
        mod->omiBSIM4pb0Given = TRUE;
        break;
      case omiBSIM4_MOD_PB1:
        mod->omiBSIM4pb1 = value->rValue;
        mod->omiBSIM4pb1Given = TRUE;
        break;
      case omiBSIM4_MOD_PALPHA0:
        mod->omiBSIM4palpha0 = value->rValue;
        mod->omiBSIM4palpha0Given = TRUE;
        break;
      case omiBSIM4_MOD_PALPHA1:
        mod->omiBSIM4palpha1 = value->rValue;
        mod->omiBSIM4palpha1Given = TRUE;
        break;
      case omiBSIM4_MOD_PBETA0:
        mod->omiBSIM4pbeta0 = value->rValue;
        mod->omiBSIM4pbeta0Given = TRUE;
        break;
      case omiBSIM4_MOD_PPHIN:
        mod->omiBSIM4pphin = value->rValue;
        mod->omiBSIM4pphinGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAGIDL:
        mod->omiBSIM4pagidl = value->rValue;
        mod->omiBSIM4pagidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBGIDL:
        mod->omiBSIM4pbgidl = value->rValue;
        mod->omiBSIM4pbgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCGIDL:
        mod->omiBSIM4pcgidl = value->rValue;
        mod->omiBSIM4pcgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PEGIDL:
        mod->omiBSIM4pegidl = value->rValue;
        mod->omiBSIM4pegidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PFGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4pfgidl = value->rValue;
        mod->omiBSIM4pfgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PKGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4pkgidl = value->rValue;
        mod->omiBSIM4pkgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRGIDL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4prgidl = value->rValue;
        mod->omiBSIM4prgidlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAGISL:
        mod->omiBSIM4pagisl = value->rValue;
        mod->omiBSIM4pagislGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBGISL:
        mod->omiBSIM4pbgisl = value->rValue;
        mod->omiBSIM4pbgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCGISL:
        mod->omiBSIM4pcgisl = value->rValue;
        mod->omiBSIM4pcgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_PEGISL:
        mod->omiBSIM4pegisl = value->rValue;
        mod->omiBSIM4pegislGiven = TRUE;
        break;
      case omiBSIM4_MOD_PFGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4pfgisl = value->rValue;
        mod->omiBSIM4pfgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_PKGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4pkgisl = value->rValue;
        mod->omiBSIM4pkgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_PRGISL: /* v4.7 New GIDL/GISL */
        mod->omiBSIM4prgisl = value->rValue;
        mod->omiBSIM4prgislGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAIGC:
        mod->omiBSIM4paigc = value->rValue;
        mod->omiBSIM4paigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBIGC:
        mod->omiBSIM4pbigc = value->rValue;
        mod->omiBSIM4pbigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCIGC:
        mod->omiBSIM4pcigc = value->rValue;
        mod->omiBSIM4pcigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAIGSD:
        mod->omiBSIM4paigsd = value->rValue;
        mod->omiBSIM4paigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBIGSD:
        mod->omiBSIM4pbigsd = value->rValue;
        mod->omiBSIM4pbigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCIGSD:
        mod->omiBSIM4pcigsd = value->rValue;
        mod->omiBSIM4pcigsdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAIGS:
        mod->omiBSIM4paigs = value->rValue;
        mod->omiBSIM4paigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBIGS:
        mod->omiBSIM4pbigs = value->rValue;
        mod->omiBSIM4pbigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCIGS:
        mod->omiBSIM4pcigs = value->rValue;
        mod->omiBSIM4pcigsGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAIGD:
        mod->omiBSIM4paigd = value->rValue;
        mod->omiBSIM4paigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBIGD:
        mod->omiBSIM4pbigd = value->rValue;
        mod->omiBSIM4pbigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCIGD:
        mod->omiBSIM4pcigd = value->rValue;
        mod->omiBSIM4pcigdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAIGBACC:
        mod->omiBSIM4paigbacc = value->rValue;
        mod->omiBSIM4paigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBIGBACC:
        mod->omiBSIM4pbigbacc = value->rValue;
        mod->omiBSIM4pbigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCIGBACC:
        mod->omiBSIM4pcigbacc = value->rValue;
        mod->omiBSIM4pcigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_PAIGBINV:
        mod->omiBSIM4paigbinv = value->rValue;
        mod->omiBSIM4paigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBIGBINV:
        mod->omiBSIM4pbigbinv = value->rValue;
        mod->omiBSIM4pbigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCIGBINV:
        mod->omiBSIM4pcigbinv = value->rValue;
        mod->omiBSIM4pcigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNIGC:
        mod->omiBSIM4pnigc = value->rValue;
        mod->omiBSIM4pnigcGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNIGBINV:
        mod->omiBSIM4pnigbinv = value->rValue;
        mod->omiBSIM4pnigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNIGBACC:
        mod->omiBSIM4pnigbacc = value->rValue;
        mod->omiBSIM4pnigbaccGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNTOX:
        mod->omiBSIM4pntox = value->rValue;
        mod->omiBSIM4pntoxGiven = TRUE;
        break;
      case omiBSIM4_MOD_PEIGBINV:
        mod->omiBSIM4peigbinv = value->rValue;
        mod->omiBSIM4peigbinvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPIGCD:
        mod->omiBSIM4ppigcd = value->rValue;
        mod->omiBSIM4ppigcdGiven = TRUE;
        break;
      case omiBSIM4_MOD_PPOXEDGE:
        mod->omiBSIM4ppoxedge = value->rValue;
        mod->omiBSIM4ppoxedgeGiven = TRUE;
        break;
      case omiBSIM4_MOD_PXRCRG1:
        mod->omiBSIM4pxrcrg1 = value->rValue;
        mod->omiBSIM4pxrcrg1Given = TRUE;
        break;
      case omiBSIM4_MOD_PXRCRG2:
        mod->omiBSIM4pxrcrg2 = value->rValue;
        mod->omiBSIM4pxrcrg2Given = TRUE;
        break;
      case omiBSIM4_MOD_PLAMBDA:
        mod->omiBSIM4plambda = value->rValue;
        mod->omiBSIM4plambdaGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVTL:
        mod->omiBSIM4pvtl = value->rValue;
        mod->omiBSIM4pvtlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PXN:
        mod->omiBSIM4pxn = value->rValue;
        mod->omiBSIM4pxnGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVFBSDOFF:
        mod->omiBSIM4pvfbsdoff = value->rValue;
        mod->omiBSIM4pvfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PTVFBSDOFF:
        mod->omiBSIM4ptvfbsdoff = value->rValue;
        mod->omiBSIM4ptvfbsdoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PEU:
        mod->omiBSIM4peu = value->rValue;
        mod->omiBSIM4peuGiven = TRUE;
        break;
      case omiBSIM4_MOD_PUCS:
        mod->omiBSIM4pucs = value->rValue;
        mod->omiBSIM4pucsGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVFB:
        mod->omiBSIM4pvfb = value->rValue;
        mod->omiBSIM4pvfbGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCGSL:
        mod->omiBSIM4pcgsl = value->rValue;
        mod->omiBSIM4pcgslGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCGDL:
        mod->omiBSIM4pcgdl = value->rValue;
        mod->omiBSIM4pcgdlGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCKAPPAS:
        mod->omiBSIM4pckappas = value->rValue;
        mod->omiBSIM4pckappasGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCKAPPAD:
        mod->omiBSIM4pckappad = value->rValue;
        mod->omiBSIM4pckappadGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCF:
        mod->omiBSIM4pcf = value->rValue;
        mod->omiBSIM4pcfGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCLC:
        mod->omiBSIM4pclc = value->rValue;
        mod->omiBSIM4pclcGiven = TRUE;
        break;
      case omiBSIM4_MOD_PCLE:
        mod->omiBSIM4pcle = value->rValue;
        mod->omiBSIM4pcleGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVFBCV:
        mod->omiBSIM4pvfbcv = value->rValue;
        mod->omiBSIM4pvfbcvGiven = TRUE;
        break;
      case omiBSIM4_MOD_PACDE:
        mod->omiBSIM4pacde = value->rValue;
        mod->omiBSIM4pacdeGiven = TRUE;
        break;
      case omiBSIM4_MOD_PMOIN:
        mod->omiBSIM4pmoin = value->rValue;
        mod->omiBSIM4pmoinGiven = TRUE;
        break;
      case omiBSIM4_MOD_PNOFF:
        mod->omiBSIM4pnoff = value->rValue;
        mod->omiBSIM4pnoffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PVOFFCV:
        mod->omiBSIM4pvoffcv = value->rValue;
        mod->omiBSIM4pvoffcvGiven = TRUE;
        break;

      case omiBSIM4_MOD_TNOM:
        mod->omiBSIM4tnom = value->rValue + CONSTCtoK;
        mod->omiBSIM4tnomGiven = TRUE;
        break;
      case omiBSIM4_MOD_CGSO:
        mod->omiBSIM4cgso = value->rValue;
        mod->omiBSIM4cgsoGiven = TRUE;
        break;
      case omiBSIM4_MOD_CGDO:
        mod->omiBSIM4cgdo = value->rValue;
        mod->omiBSIM4cgdoGiven = TRUE;
        break;
      case omiBSIM4_MOD_CGBO:
        mod->omiBSIM4cgbo = value->rValue;
        mod->omiBSIM4cgboGiven = TRUE;
        break;
      case omiBSIM4_MOD_XPART:
        mod->omiBSIM4xpart = value->rValue;
        mod->omiBSIM4xpartGiven = TRUE;
        break;
      case omiBSIM4_MOD_RSH:
        mod->omiBSIM4sheetResistance = value->rValue;
        mod->omiBSIM4sheetResistanceGiven = TRUE;
        break;
      case omiBSIM4_MOD_JSS:
        mod->omiBSIM4SjctSatCurDensity = value->rValue;
        mod->omiBSIM4SjctSatCurDensityGiven = TRUE;
        break;
      case omiBSIM4_MOD_JSWS:
        mod->omiBSIM4SjctSidewallSatCurDensity = value->rValue;
        mod->omiBSIM4SjctSidewallSatCurDensityGiven = TRUE;
        break;
      case omiBSIM4_MOD_JSWGS:
        mod->omiBSIM4SjctGateSidewallSatCurDensity = value->rValue;
        mod->omiBSIM4SjctGateSidewallSatCurDensityGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBS:
        mod->omiBSIM4SbulkJctPotential = value->rValue;
        mod->omiBSIM4SbulkJctPotentialGiven = TRUE;
        break;
      case omiBSIM4_MOD_MJS:
        mod->omiBSIM4SbulkJctBotGradingCoeff = value->rValue;
        mod->omiBSIM4SbulkJctBotGradingCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBSWS:
        mod->omiBSIM4SsidewallJctPotential = value->rValue;
        mod->omiBSIM4SsidewallJctPotentialGiven = TRUE;
        break;
      case omiBSIM4_MOD_MJSWS:
        mod->omiBSIM4SbulkJctSideGradingCoeff = value->rValue;
        mod->omiBSIM4SbulkJctSideGradingCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_CJS:
        mod->omiBSIM4SunitAreaJctCap = value->rValue;
        mod->omiBSIM4SunitAreaJctCapGiven = TRUE;
        break;
      case omiBSIM4_MOD_CJSWS:
        mod->omiBSIM4SunitLengthSidewallJctCap = value->rValue;
        mod->omiBSIM4SunitLengthSidewallJctCapGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJS:
        mod->omiBSIM4SjctEmissionCoeff = value->rValue;
        mod->omiBSIM4SjctEmissionCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBSWGS:
        mod->omiBSIM4SGatesidewallJctPotential = value->rValue;
        mod->omiBSIM4SGatesidewallJctPotentialGiven = TRUE;
        break;
      case omiBSIM4_MOD_MJSWGS:
        mod->omiBSIM4SbulkJctGateSideGradingCoeff = value->rValue;
        mod->omiBSIM4SbulkJctGateSideGradingCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_CJSWGS:
        mod->omiBSIM4SunitLengthGateSidewallJctCap = value->rValue;
        mod->omiBSIM4SunitLengthGateSidewallJctCapGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTIS:
        mod->omiBSIM4SjctTempExponent = value->rValue;
        mod->omiBSIM4SjctTempExponentGiven = TRUE;
        break;
      case omiBSIM4_MOD_JSD:
        mod->omiBSIM4DjctSatCurDensity = value->rValue;
        mod->omiBSIM4DjctSatCurDensityGiven = TRUE;
        break;
      case omiBSIM4_MOD_JSWD:
        mod->omiBSIM4DjctSidewallSatCurDensity = value->rValue;
        mod->omiBSIM4DjctSidewallSatCurDensityGiven = TRUE;
        break;
      case omiBSIM4_MOD_JSWGD:
        mod->omiBSIM4DjctGateSidewallSatCurDensity = value->rValue;
        mod->omiBSIM4DjctGateSidewallSatCurDensityGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBD:
        mod->omiBSIM4DbulkJctPotential = value->rValue;
        mod->omiBSIM4DbulkJctPotentialGiven = TRUE;
        break;
      case omiBSIM4_MOD_MJD:
        mod->omiBSIM4DbulkJctBotGradingCoeff = value->rValue;
        mod->omiBSIM4DbulkJctBotGradingCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBSWD:
        mod->omiBSIM4DsidewallJctPotential = value->rValue;
        mod->omiBSIM4DsidewallJctPotentialGiven = TRUE;
        break;
      case omiBSIM4_MOD_MJSWD:
        mod->omiBSIM4DbulkJctSideGradingCoeff = value->rValue;
        mod->omiBSIM4DbulkJctSideGradingCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_CJD:
        mod->omiBSIM4DunitAreaJctCap = value->rValue;
        mod->omiBSIM4DunitAreaJctCapGiven = TRUE;
        break;
      case omiBSIM4_MOD_CJSWD:
        mod->omiBSIM4DunitLengthSidewallJctCap = value->rValue;
        mod->omiBSIM4DunitLengthSidewallJctCapGiven = TRUE;
        break;
      case omiBSIM4_MOD_NJD:
        mod->omiBSIM4DjctEmissionCoeff = value->rValue;
        mod->omiBSIM4DjctEmissionCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_PBSWGD:
        mod->omiBSIM4DGatesidewallJctPotential = value->rValue;
        mod->omiBSIM4DGatesidewallJctPotentialGiven = TRUE;
        break;
      case omiBSIM4_MOD_MJSWGD:
        mod->omiBSIM4DbulkJctGateSideGradingCoeff = value->rValue;
        mod->omiBSIM4DbulkJctGateSideGradingCoeffGiven = TRUE;
        break;
      case omiBSIM4_MOD_CJSWGD:
        mod->omiBSIM4DunitLengthGateSidewallJctCap = value->rValue;
        mod->omiBSIM4DunitLengthGateSidewallJctCapGiven = TRUE;
        break;
      case omiBSIM4_MOD_XTID:
        mod->omiBSIM4DjctTempExponent = value->rValue;
        mod->omiBSIM4DjctTempExponentGiven = TRUE;
        break;
      case omiBSIM4_MOD_LINT:
        mod->omiBSIM4Lint = value->rValue;
        mod->omiBSIM4LintGiven = TRUE;
        break;
      case omiBSIM4_MOD_LL:
        mod->omiBSIM4Ll = value->rValue;
        mod->omiBSIM4LlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LLC:
        mod->omiBSIM4Llc = value->rValue;
        mod->omiBSIM4LlcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LLN:
        mod->omiBSIM4Lln = value->rValue;
        mod->omiBSIM4LlnGiven = TRUE;
        break;
      case omiBSIM4_MOD_LW:
        mod->omiBSIM4Lw = value->rValue;
        mod->omiBSIM4LwGiven = TRUE;
        break;
      case omiBSIM4_MOD_LWC:
        mod->omiBSIM4Lwc = value->rValue;
        mod->omiBSIM4LwcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LWN:
        mod->omiBSIM4Lwn = value->rValue;
        mod->omiBSIM4LwnGiven = TRUE;
        break;
      case omiBSIM4_MOD_LWL:
        mod->omiBSIM4Lwl = value->rValue;
        mod->omiBSIM4LwlGiven = TRUE;
        break;
      case omiBSIM4_MOD_LWLC:
        mod->omiBSIM4Lwlc = value->rValue;
        mod->omiBSIM4LwlcGiven = TRUE;
        break;
      case omiBSIM4_MOD_LMIN:
        mod->omiBSIM4Lmin = value->rValue;
        mod->omiBSIM4LminGiven = TRUE;
        break;
      case omiBSIM4_MOD_LMAX:
        mod->omiBSIM4Lmax = value->rValue;
        mod->omiBSIM4LmaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_WINT:
        mod->omiBSIM4Wint = value->rValue;
        mod->omiBSIM4WintGiven = TRUE;
        break;
      case omiBSIM4_MOD_WL:
        mod->omiBSIM4Wl = value->rValue;
        mod->omiBSIM4WlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WLC:
        mod->omiBSIM4Wlc = value->rValue;
        mod->omiBSIM4WlcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WLN:
        mod->omiBSIM4Wln = value->rValue;
        mod->omiBSIM4WlnGiven = TRUE;
        break;
      case omiBSIM4_MOD_WW:
        mod->omiBSIM4Ww = value->rValue;
        mod->omiBSIM4WwGiven = TRUE;
        break;
      case omiBSIM4_MOD_WWC:
        mod->omiBSIM4Wwc = value->rValue;
        mod->omiBSIM4WwcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WWN:
        mod->omiBSIM4Wwn = value->rValue;
        mod->omiBSIM4WwnGiven = TRUE;
        break;
      case omiBSIM4_MOD_WWL:
        mod->omiBSIM4Wwl = value->rValue;
        mod->omiBSIM4WwlGiven = TRUE;
        break;
      case omiBSIM4_MOD_WWLC:
        mod->omiBSIM4Wwlc = value->rValue;
        mod->omiBSIM4WwlcGiven = TRUE;
        break;
      case omiBSIM4_MOD_WMIN:
        mod->omiBSIM4Wmin = value->rValue;
        mod->omiBSIM4WminGiven = TRUE;
        break;
      case omiBSIM4_MOD_WMAX:
        mod->omiBSIM4Wmax = value->rValue;
        mod->omiBSIM4WmaxGiven = TRUE;
        break;

      case omiBSIM4_MOD_NOIA:
        mod->omiBSIM4oxideTrapDensityA = value->rValue;
        mod->omiBSIM4oxideTrapDensityAGiven = TRUE;
        break;
      case omiBSIM4_MOD_NOIB:
        mod->omiBSIM4oxideTrapDensityB = value->rValue;
        mod->omiBSIM4oxideTrapDensityBGiven = TRUE;
        break;
      case omiBSIM4_MOD_NOIC:
        mod->omiBSIM4oxideTrapDensityC = value->rValue;
        mod->omiBSIM4oxideTrapDensityCGiven = TRUE;
        break;
      case omiBSIM4_MOD_EM:
        mod->omiBSIM4em = value->rValue;
        mod->omiBSIM4emGiven = TRUE;
        break;
      case omiBSIM4_MOD_EF:
        mod->omiBSIM4ef = value->rValue;
        mod->omiBSIM4efGiven = TRUE;
        break;
      case omiBSIM4_MOD_AF:
        mod->omiBSIM4af = value->rValue;
        mod->omiBSIM4afGiven = TRUE;
        break;
      case omiBSIM4_MOD_KF:
        mod->omiBSIM4kf = value->rValue;
        mod->omiBSIM4kfGiven = TRUE;
        break;

      case omiBSIM4_MOD_VGS_MAX:
        mod->omiBSIM4vgsMax = value->rValue;
        mod->omiBSIM4vgsMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VGD_MAX:
        mod->omiBSIM4vgdMax = value->rValue;
        mod->omiBSIM4vgdMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VGB_MAX:
        mod->omiBSIM4vgbMax = value->rValue;
        mod->omiBSIM4vgbMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VDS_MAX:
        mod->omiBSIM4vdsMax = value->rValue;
        mod->omiBSIM4vdsMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VBS_MAX:
        mod->omiBSIM4vbsMax = value->rValue;
        mod->omiBSIM4vbsMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VBD_MAX:
        mod->omiBSIM4vbdMax = value->rValue;
        mod->omiBSIM4vbdMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VGSR_MAX:
        mod->omiBSIM4vgsrMax = value->rValue;
        mod->omiBSIM4vgsrMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VGDR_MAX:
        mod->omiBSIM4vgdrMax = value->rValue;
        mod->omiBSIM4vgdrMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VGBR_MAX:
        mod->omiBSIM4vgbrMax = value->rValue;
        mod->omiBSIM4vgbrMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VBSR_MAX:
        mod->omiBSIM4vbsrMax = value->rValue;
        mod->omiBSIM4vbsrMaxGiven = TRUE;
        break;
      case omiBSIM4_MOD_VBDR_MAX:
        mod->omiBSIM4vbdrMax = value->rValue;
        mod->omiBSIM4vbdrMaxGiven = TRUE;
        break;

      case omiBSIM4_MOD_NMOS:
        if (value->iValue) {
          mod->omiBSIM4type = 1;
          mod->omiBSIM4typeGiven = TRUE;
        }
        break;
      case omiBSIM4_MOD_PMOS:
        if (value->iValue) {
          mod->omiBSIM4type = -1;
          mod->omiBSIM4typeGiven = TRUE;
        }
        break;
      default:
        return (E_BADPARM);
    }
    return(OK);
}


