#include "ngspice/cktdefs.h"
#include "ngspice/const.h"
#include "ngspice/ftedefs.h"
#include "ngspice/jobdefs.h"
#include "ngspice/ngspice.h"
#include "omibsim4def.h"
#include "omibsim4init.h"

double omiBSIM4GetmParam(GENmodel *inMod, int id) {
  omiBSIM4model *mod = (omiBSIM4model *)inMod;
  switch (id) {
    case omiBSIM4_MOD_MOBMOD:
      return (mod->omiBSIM4mobModGiven ? (double)mod->omiBSIM4mobMod
                                       : 1e199);
    case omiBSIM4_MOD_BINUNIT:
      return (mod->omiBSIM4binUnitGiven ? (double)mod->omiBSIM4binUnit
                                        : 1e199);
    case omiBSIM4_MOD_PARAMCHK:
      return (mod->omiBSIM4paramChkGiven ? (double)mod->omiBSIM4paramChk
                                         : 1e199);
    case omiBSIM4_MOD_CVCHARGEMOD:
      return (mod->omiBSIM4cvchargeModGiven ? (double)mod->omiBSIM4cvchargeMod
                                            : 1e199);
    case omiBSIM4_MOD_CAPMOD:
      return (mod->omiBSIM4capModGiven ? (double)mod->omiBSIM4capMod
                                       : 1e199);
    case omiBSIM4_MOD_DIOMOD:
      return (mod->omiBSIM4dioModGiven ? (double)mod->omiBSIM4dioMod
                                       : 1e199);
    case omiBSIM4_MOD_RDSMOD:
      return (mod->omiBSIM4rdsModGiven ? (double)mod->omiBSIM4rdsMod
                                       : 1e199);
    case omiBSIM4_MOD_TRNQSMOD:
      return (mod->omiBSIM4trnqsModGiven ? (double)mod->omiBSIM4trnqsMod
                                         : 1e199);
    case omiBSIM4_MOD_ACNQSMOD:
      return (mod->omiBSIM4acnqsModGiven ? (double)mod->omiBSIM4acnqsMod
                                         : 1e199);
    case omiBSIM4_MOD_RBODYMOD:
      return (mod->omiBSIM4rbodyModGiven ? (double)mod->omiBSIM4rbodyMod
                                         : 1e199);
    case omiBSIM4_MOD_RGATEMOD:
      return (mod->omiBSIM4rgateModGiven ? (double)mod->omiBSIM4rgateMod
                                         : 1e199);
    case omiBSIM4_MOD_PERMOD:
      return (mod->omiBSIM4perModGiven ? (double)mod->omiBSIM4perMod
                                       : 1e199);
    case omiBSIM4_MOD_GEOMOD:
      return (mod->omiBSIM4geoModGiven ? (double)mod->omiBSIM4geoMod
                                       : 1e199);
    case omiBSIM4_MOD_RGEOMOD:
      return (mod->omiBSIM4rgeoModGiven ? (double)mod->omiBSIM4rgeoMod
                                        : 1e199);
    case omiBSIM4_MOD_FNOIMOD:
      return (mod->omiBSIM4fnoiModGiven ? (double)mod->omiBSIM4fnoiMod
                                        : 1e199);
    case omiBSIM4_MOD_TNOIMOD:
      return (mod->omiBSIM4tnoiModGiven ? (double)mod->omiBSIM4tnoiMod
                                        : 1e199);
    case omiBSIM4_MOD_MTRLMOD:
      return (mod->omiBSIM4mtrlModGiven ? (double)mod->omiBSIM4mtrlMod
                                        : 1e199);
    case omiBSIM4_MOD_MTRLCOMPATMOD:
      return (mod->omiBSIM4mtrlCompatModGiven
                  ? (double)mod->omiBSIM4mtrlCompatMod
                  : 1e199);
    case omiBSIM4_MOD_GIDLMOD: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4gidlModGiven ? (double)mod->omiBSIM4gidlMod
                                        : 1e199);
    case omiBSIM4_MOD_IGCMOD:
      return (mod->omiBSIM4igcModGiven ? (double)mod->omiBSIM4igcMod
                                       : 1e199);
    case omiBSIM4_MOD_IGBMOD:
      return (mod->omiBSIM4igbModGiven ? (double)mod->omiBSIM4igbMod
                                       : 1e199);
    case omiBSIM4_MOD_TEMPMOD:
      return (mod->omiBSIM4tempModGiven ? (double)mod->omiBSIM4tempMod
                                        : 1e199);

    case omiBSIM4_MOD_VERSION:
      return (mod->omiBSIM4versionGiven ? 4.7 : 1e199);
    case omiBSIM4_MOD_TOXREF:
      return (mod->omiBSIM4toxrefGiven ? mod->omiBSIM4toxref : 1e199);
    case omiBSIM4_MOD_EOT:
      return (mod->omiBSIM4eotGiven ? mod->omiBSIM4eot : 1e199);
    case omiBSIM4_MOD_VDDEOT:
      return (mod->omiBSIM4vddeotGiven ? mod->omiBSIM4vddeot : 1e199);
    case omiBSIM4_MOD_TEMPEOT:
      return (mod->omiBSIM4tempeotGiven ? mod->omiBSIM4tempeot : 1e199);
    case omiBSIM4_MOD_LEFFEOT:
      return (mod->omiBSIM4leffeotGiven ? mod->omiBSIM4leffeot : 1e199);
    case omiBSIM4_MOD_WEFFEOT:
      return (mod->omiBSIM4weffeotGiven ? mod->omiBSIM4weffeot : 1e199);
    case omiBSIM4_MOD_ADOS:
      return (mod->omiBSIM4adosGiven ? mod->omiBSIM4ados : 1e199);
    case omiBSIM4_MOD_BDOS:
      return (mod->omiBSIM4bdosGiven ? mod->omiBSIM4bdos : 1e199);
    case omiBSIM4_MOD_TOXE:
      return (mod->omiBSIM4toxeGiven ? mod->omiBSIM4toxe : 1e199);
    case omiBSIM4_MOD_TOXP:
      return (mod->omiBSIM4toxpGiven ? mod->omiBSIM4toxp : 1e199);
    case omiBSIM4_MOD_TOXM:
      return (mod->omiBSIM4toxmGiven ? mod->omiBSIM4toxm : 1e199);
    case omiBSIM4_MOD_DTOX:
      return (mod->omiBSIM4dtoxGiven ? mod->omiBSIM4dtox : 1e199);
    case omiBSIM4_MOD_EPSROX:
      return (mod->omiBSIM4epsroxGiven ? mod->omiBSIM4epsrox : 1e199);

    case omiBSIM4_MOD_CDSC:
      return (mod->omiBSIM4cdscGiven ? mod->omiBSIM4cdsc : 1e199);
    case omiBSIM4_MOD_CDSCB:
      return (mod->omiBSIM4cdscbGiven ? mod->omiBSIM4cdscb : 1e199);

    case omiBSIM4_MOD_CDSCD:
      return (mod->omiBSIM4cdscdGiven ? mod->omiBSIM4cdscd : 1e199);

    case omiBSIM4_MOD_CIT:
      return (mod->omiBSIM4citGiven ? mod->omiBSIM4cit : 1e199);
    case omiBSIM4_MOD_NFACTOR:
      return (mod->omiBSIM4nfactorGiven ? mod->omiBSIM4nfactor : 1e199);
    case omiBSIM4_MOD_XJ:
      return (mod->omiBSIM4xjGiven ? mod->omiBSIM4xj : 1e199);
    case omiBSIM4_MOD_VSAT:
      return (mod->omiBSIM4vsatGiven ? mod->omiBSIM4vsat : 1e199);
    case omiBSIM4_MOD_A0:
      return (mod->omiBSIM4a0Given ? mod->omiBSIM4a0 : 1e199);

    case omiBSIM4_MOD_AGS:
      return (mod->omiBSIM4agsGiven ? mod->omiBSIM4ags : 1e199);

    case omiBSIM4_MOD_A1:
      return (mod->omiBSIM4a1Given ? mod->omiBSIM4a1 : 1e199);
    case omiBSIM4_MOD_A2:
      return (mod->omiBSIM4a2Given ? mod->omiBSIM4a2 : 1e199);
    case omiBSIM4_MOD_AT:
      return (mod->omiBSIM4atGiven ? mod->omiBSIM4at : 1e199);
    case omiBSIM4_MOD_KETA:
      return (mod->omiBSIM4ketaGiven ? mod->omiBSIM4keta : 1e199);
    case omiBSIM4_MOD_NSUB:
      return (mod->omiBSIM4nsubGiven ? mod->omiBSIM4nsub : 1e199);
    case omiBSIM4_MOD_PHIG:
      return (mod->omiBSIM4phigGiven ? mod->omiBSIM4phig : 1e199);
    case omiBSIM4_MOD_EPSRGATE:
      return (mod->omiBSIM4epsrgateGiven ? mod->omiBSIM4epsrgate : 1e199);
    case omiBSIM4_MOD_EASUB:
      return (mod->omiBSIM4easubGiven ? mod->omiBSIM4easub : 1e199);
    case omiBSIM4_MOD_EPSRSUB:
      return (mod->omiBSIM4epsrsubGiven ? mod->omiBSIM4epsrsub : 1e199);
    case omiBSIM4_MOD_NI0SUB:
      return (mod->omiBSIM4ni0subGiven ? mod->omiBSIM4ni0sub : 1e199);
    case omiBSIM4_MOD_BG0SUB:
      return (mod->omiBSIM4bg0subGiven ? mod->omiBSIM4bg0sub : 1e199);
    case omiBSIM4_MOD_TBGASUB:
      return (mod->omiBSIM4tbgasubGiven ? mod->omiBSIM4tbgasub : 1e199);
    case omiBSIM4_MOD_TBGBSUB:
      return (mod->omiBSIM4tbgbsubGiven ? mod->omiBSIM4tbgbsub : 1e199);
    case omiBSIM4_MOD_NDEP:
      return (mod->omiBSIM4ndepGiven ? mod->omiBSIM4ndep : 1e199);
    case omiBSIM4_MOD_NSD:
      return (mod->omiBSIM4nsdGiven ? mod->omiBSIM4nsd : 1e199);
    case omiBSIM4_MOD_NGATE:
      return (mod->omiBSIM4ngateGiven ? mod->omiBSIM4ngate : 1e199);
    case omiBSIM4_MOD_GAMMA1:
      return (mod->omiBSIM4gamma1Given ? mod->omiBSIM4gamma1 : 1e199);
    case omiBSIM4_MOD_GAMMA2:
      return (mod->omiBSIM4gamma2Given ? mod->omiBSIM4gamma2 : 1e199);
    case omiBSIM4_MOD_VBX:
      return (mod->omiBSIM4vbxGiven ? mod->omiBSIM4vbx : 1e199);
    case omiBSIM4_MOD_VBM:
      return (mod->omiBSIM4vbmGiven ? mod->omiBSIM4vbm : 1e199);
    case omiBSIM4_MOD_XT:
      return (mod->omiBSIM4xtGiven ? mod->omiBSIM4xt : 1e199);
    case omiBSIM4_MOD_K1:
      return (mod->omiBSIM4k1Given ? mod->omiBSIM4k1 : 1e199);
    case omiBSIM4_MOD_KT1:
      return (mod->omiBSIM4kt1Given ? mod->omiBSIM4kt1 : 1e199);
    case omiBSIM4_MOD_KT1L:
      return (mod->omiBSIM4kt1lGiven ? mod->omiBSIM4kt1l : 1e199);
    case omiBSIM4_MOD_KT2:
      return (mod->omiBSIM4kt2Given ? mod->omiBSIM4kt2 : 1e199);
    case omiBSIM4_MOD_K2:
      return (mod->omiBSIM4k2Given ? mod->omiBSIM4k2 : 1e199);
    case omiBSIM4_MOD_K3:
      return (mod->omiBSIM4k3Given ? mod->omiBSIM4k3 : 1e199);
    case omiBSIM4_MOD_K3B:
      return (mod->omiBSIM4k3bGiven ? mod->omiBSIM4k3b : 1e199);
    case omiBSIM4_MOD_LPE0:
      return (mod->omiBSIM4lpe0Given ? mod->omiBSIM4lpe0 : 1e199);
    case omiBSIM4_MOD_LPEB:
      return (mod->omiBSIM4lpebGiven ? mod->omiBSIM4lpeb : 1e199);
    case omiBSIM4_MOD_DVTP0:
      return (mod->omiBSIM4dvtp0Given ? mod->omiBSIM4dvtp0 : 1e199);
    case omiBSIM4_MOD_DVTP1:
      return (mod->omiBSIM4dvtp1Given ? mod->omiBSIM4dvtp1 : 1e199);
    case omiBSIM4_MOD_DVTP2: /* New DIBL/Rout */
      return (mod->omiBSIM4dvtp2Given ? mod->omiBSIM4dvtp2 : 1e199);
    case omiBSIM4_MOD_DVTP3:
      return (mod->omiBSIM4dvtp3Given ? mod->omiBSIM4dvtp3 : 1e199);
    case omiBSIM4_MOD_DVTP4:
      return (mod->omiBSIM4dvtp4Given ? mod->omiBSIM4dvtp4 : 1e199);
    case omiBSIM4_MOD_DVTP5:
      return (mod->omiBSIM4dvtp5Given ? mod->omiBSIM4dvtp5 : 1e199);
    case omiBSIM4_MOD_W0:
      return (mod->omiBSIM4w0Given ? mod->omiBSIM4w0 : 1e199);
    case omiBSIM4_MOD_DVT0:
      return (mod->omiBSIM4dvt0Given ? mod->omiBSIM4dvt0 : 1e199);
    case omiBSIM4_MOD_DVT1:
      return (mod->omiBSIM4dvt1Given ? mod->omiBSIM4dvt1 : 1e199);
    case omiBSIM4_MOD_DVT2:
      return (mod->omiBSIM4dvt2Given ? mod->omiBSIM4dvt2 : 1e199);
    case omiBSIM4_MOD_DVT0W:
      return (mod->omiBSIM4dvt0wGiven ? mod->omiBSIM4dvt0w : 1e199);
    case omiBSIM4_MOD_DVT1W:
      return (mod->omiBSIM4dvt1wGiven ? mod->omiBSIM4dvt1w : 1e199);
    case omiBSIM4_MOD_DVT2W:
      return (mod->omiBSIM4dvt2wGiven ? mod->omiBSIM4dvt2w : 1e199);
    case omiBSIM4_MOD_DROUT:
      return (mod->omiBSIM4droutGiven ? mod->omiBSIM4drout : 1e199);
    case omiBSIM4_MOD_DSUB:
      return (mod->omiBSIM4dsubGiven ? mod->omiBSIM4dsub : 1e199);
    case omiBSIM4_MOD_VTH0:
      return (mod->omiBSIM4vth0Given ? mod->omiBSIM4vth0 : 1e199);
    case omiBSIM4_MOD_EU:
      return (mod->omiBSIM4euGiven ? mod->omiBSIM4eu : 1e199);
    case omiBSIM4_MOD_UCS:
      return (mod->omiBSIM4ucsGiven ? mod->omiBSIM4ucs : 1e199);
    case omiBSIM4_MOD_UA:
      return (mod->omiBSIM4uaGiven ? mod->omiBSIM4ua : 1e199);
    case omiBSIM4_MOD_UA1:
      return (mod->omiBSIM4ua1Given ? mod->omiBSIM4ua1 : 1e199);
    case omiBSIM4_MOD_UB:
      return (mod->omiBSIM4ubGiven ? mod->omiBSIM4ub : 1e199);
    case omiBSIM4_MOD_UB1:
      return (mod->omiBSIM4ub1Given ? mod->omiBSIM4ub1 : 1e199);
    case omiBSIM4_MOD_UC:
      return (mod->omiBSIM4ucGiven ? mod->omiBSIM4uc : 1e199);
    case omiBSIM4_MOD_UC1:
      return (mod->omiBSIM4uc1Given ? mod->omiBSIM4uc1 : 1e199);
    case omiBSIM4_MOD_U0:
      return (mod->omiBSIM4u0Given ? mod->omiBSIM4u0 : 1e199);
    case omiBSIM4_MOD_UTE:
      return (mod->omiBSIM4uteGiven ? mod->omiBSIM4ute : 1e199);
    case omiBSIM4_MOD_UCSTE:
      return (mod->omiBSIM4ucsteGiven ? mod->omiBSIM4ucste : 1e199);
    case omiBSIM4_MOD_UD:
      return (mod->omiBSIM4udGiven ? mod->omiBSIM4ud : 1e199);
    case omiBSIM4_MOD_UD1:
      return (mod->omiBSIM4ud1Given ? mod->omiBSIM4ud1 : 1e199);
    case omiBSIM4_MOD_UP:
      return (mod->omiBSIM4upGiven ? mod->omiBSIM4up : 1e199);
    case omiBSIM4_MOD_LP:
      return (mod->omiBSIM4lpGiven ? mod->omiBSIM4lp : 1e199);
    case omiBSIM4_MOD_LUD:
      return (mod->omiBSIM4ludGiven ? mod->omiBSIM4lud : 1e199);
    case omiBSIM4_MOD_LUD1:
      return (mod->omiBSIM4lud1Given ? mod->omiBSIM4lud1 : 1e199);
    case omiBSIM4_MOD_LUP:
      return (mod->omiBSIM4lupGiven ? mod->omiBSIM4lup : 1e199);
    case omiBSIM4_MOD_LLP:
      return (mod->omiBSIM4llpGiven ? mod->omiBSIM4llp : 1e199);
    case omiBSIM4_MOD_WUD:
      return (mod->omiBSIM4wudGiven ? mod->omiBSIM4wud : 1e199);
    case omiBSIM4_MOD_WUD1:
      return (mod->omiBSIM4wud1Given ? mod->omiBSIM4wud1 : 1e199);
    case omiBSIM4_MOD_WUP:
      return (mod->omiBSIM4wupGiven ? mod->omiBSIM4wup : 1e199);
    case omiBSIM4_MOD_WLP:
      return (mod->omiBSIM4wlpGiven ? mod->omiBSIM4wlp : 1e199);
    case omiBSIM4_MOD_PUD:
      return (mod->omiBSIM4pudGiven ? mod->omiBSIM4pud : 1e199);
    case omiBSIM4_MOD_PUD1:
      return (mod->omiBSIM4pud1Given ? mod->omiBSIM4pud1 : 1e199);
    case omiBSIM4_MOD_PUP:
      return (mod->omiBSIM4pupGiven ? mod->omiBSIM4pup : 1e199);
    case omiBSIM4_MOD_PLP:
      return (mod->omiBSIM4plpGiven ? mod->omiBSIM4plp : 1e199);

    case omiBSIM4_MOD_VOFF:
      return (mod->omiBSIM4voffGiven ? mod->omiBSIM4voff : 1e199);
    case omiBSIM4_MOD_TVOFF:
      return (mod->omiBSIM4tvoffGiven ? mod->omiBSIM4tvoff : 1e199);
    case omiBSIM4_MOD_TNFACTOR: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4tnfactorGiven ? mod->omiBSIM4tnfactor : 1e199);
    case omiBSIM4_MOD_TETA0: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4teta0Given ? mod->omiBSIM4teta0 : 1e199);
    case omiBSIM4_MOD_TVOFFCV: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4tvoffcvGiven ? mod->omiBSIM4tvoffcv : 1e199);
    case omiBSIM4_MOD_VOFFL:
      return (mod->omiBSIM4vofflGiven ? mod->omiBSIM4voffl : 1e199);
    case omiBSIM4_MOD_VOFFCVL:
      return (mod->omiBSIM4voffcvlGiven ? mod->omiBSIM4voffcvl : 1e199);
    case omiBSIM4_MOD_MINV:
      return (mod->omiBSIM4minvGiven ? mod->omiBSIM4minv : 1e199);
    case omiBSIM4_MOD_MINVCV:
      return (mod->omiBSIM4minvcvGiven ? mod->omiBSIM4minvcv : 1e199);
    case omiBSIM4_MOD_FPROUT:
      return (mod->omiBSIM4fproutGiven ? mod->omiBSIM4fprout : 1e199);
    case omiBSIM4_MOD_PDITS:
      return (mod->omiBSIM4pditsGiven ? mod->omiBSIM4pdits : 1e199);
    case omiBSIM4_MOD_PDITSD:
      return (mod->omiBSIM4pditsdGiven ? mod->omiBSIM4pditsd : 1e199);
    case omiBSIM4_MOD_PDITSL:
      return (mod->omiBSIM4pditslGiven ? mod->omiBSIM4pditsl : 1e199);
    case omiBSIM4_MOD_DELTA:
      return (mod->omiBSIM4deltaGiven ? mod->omiBSIM4delta : 1e199);
    case omiBSIM4_MOD_RDSW:
      return (mod->omiBSIM4rdswGiven ? mod->omiBSIM4rdsw : 1e199);
    case omiBSIM4_MOD_RDSWMIN:
      return (mod->omiBSIM4rdswminGiven ? mod->omiBSIM4rdswmin : 1e199);
    case omiBSIM4_MOD_RDWMIN:
      return (mod->omiBSIM4rdwminGiven ? mod->omiBSIM4rdwmin : 1e199);
    case omiBSIM4_MOD_RSWMIN:
      return (mod->omiBSIM4rswminGiven ? mod->omiBSIM4rswmin : 1e199);
    case omiBSIM4_MOD_RDW:
      return (mod->omiBSIM4rdwGiven ? mod->omiBSIM4rdw : 1e199);
    case omiBSIM4_MOD_RSW:
      return (mod->omiBSIM4rswGiven ? mod->omiBSIM4rsw : 1e199);
    case omiBSIM4_MOD_PRWG:
      return (mod->omiBSIM4prwgGiven ? mod->omiBSIM4prwg : 1e199);
    case omiBSIM4_MOD_PRWB:
      return (mod->omiBSIM4prwbGiven ? mod->omiBSIM4prwb : 1e199);
    case omiBSIM4_MOD_PRT:
      return (mod->omiBSIM4prtGiven ? mod->omiBSIM4prt : 1e199);
    case omiBSIM4_MOD_ETA0:
      return (mod->omiBSIM4eta0Given ? mod->omiBSIM4eta0 : 1e199);
    case omiBSIM4_MOD_ETAB:
      return (mod->omiBSIM4etabGiven ? mod->omiBSIM4etab : 1e199);
    case omiBSIM4_MOD_PCLM:
      return (mod->omiBSIM4pclmGiven ? mod->omiBSIM4pclm : 1e199);
    case omiBSIM4_MOD_PDIBL1:
      return (mod->omiBSIM4pdibl1Given ? mod->omiBSIM4pdibl1 : 1e199);
    case omiBSIM4_MOD_PDIBL2:
      return (mod->omiBSIM4pdibl2Given ? mod->omiBSIM4pdibl2 : 1e199);
    case omiBSIM4_MOD_PDIBLB:
      return (mod->omiBSIM4pdiblbGiven ? mod->omiBSIM4pdiblb : 1e199);
    case omiBSIM4_MOD_PSCBE1:
      return (mod->omiBSIM4pscbe1Given ? mod->omiBSIM4pscbe1 : 1e199);
    case omiBSIM4_MOD_PSCBE2:
      return (mod->omiBSIM4pscbe2Given ? mod->omiBSIM4pscbe2 : 1e199);
    case omiBSIM4_MOD_PVAG:
      return (mod->omiBSIM4pvagGiven ? mod->omiBSIM4pvag : 1e199);
    case omiBSIM4_MOD_WR:
      return (mod->omiBSIM4wrGiven ? mod->omiBSIM4wr : 1e199);
    case omiBSIM4_MOD_DWG:
      return (mod->omiBSIM4dwgGiven ? mod->omiBSIM4dwg : 1e199);
    case omiBSIM4_MOD_DWB:
      return (mod->omiBSIM4dwbGiven ? mod->omiBSIM4dwb : 1e199);
    case omiBSIM4_MOD_B0:
      return (mod->omiBSIM4b0Given ? mod->omiBSIM4b0 : 1e199);
    case omiBSIM4_MOD_B1:
      return (mod->omiBSIM4b1Given ? mod->omiBSIM4b1 : 1e199);
    case omiBSIM4_MOD_ALPHA0:
      return (mod->omiBSIM4alpha0Given ? mod->omiBSIM4alpha0 : 1e199);
    case omiBSIM4_MOD_ALPHA1:
      return (mod->omiBSIM4alpha1Given ? mod->omiBSIM4alpha1 : 1e199);
    case omiBSIM4_MOD_PHIN:
      return (mod->omiBSIM4phinGiven ? mod->omiBSIM4phin : 1e199);
    case omiBSIM4_MOD_AGIDL:
      return (mod->omiBSIM4agidlGiven ? mod->omiBSIM4agidl : 1e199);
    case omiBSIM4_MOD_BGIDL:
      return (mod->omiBSIM4bgidlGiven ? mod->omiBSIM4bgidl : 1e199);
    case omiBSIM4_MOD_CGIDL:
      return (mod->omiBSIM4cgidlGiven ? mod->omiBSIM4cgidl : 1e199);
    case omiBSIM4_MOD_EGIDL:
      return (mod->omiBSIM4egidlGiven ? mod->omiBSIM4egidl : 1e199);
    case omiBSIM4_MOD_FGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4fgidlGiven ? mod->omiBSIM4fgidl : 1e199);
    case omiBSIM4_MOD_KGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4kgidlGiven ? mod->omiBSIM4kgidl : 1e199);
    case omiBSIM4_MOD_RGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4rgidlGiven ? mod->omiBSIM4rgidl : 1e199);
    case omiBSIM4_MOD_AGISL:
      return (mod->omiBSIM4agislGiven ? mod->omiBSIM4agisl : 1e199);
    case omiBSIM4_MOD_BGISL:
      return (mod->omiBSIM4bgislGiven ? mod->omiBSIM4bgisl : 1e199);
    case omiBSIM4_MOD_CGISL:
      return (mod->omiBSIM4cgislGiven ? mod->omiBSIM4cgisl : 1e199);
    case omiBSIM4_MOD_EGISL:
      return (mod->omiBSIM4egislGiven ? mod->omiBSIM4egisl : 1e199);
    case omiBSIM4_MOD_FGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4fgislGiven ? mod->omiBSIM4fgisl : 1e199);
    case omiBSIM4_MOD_KGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4kgislGiven ? mod->omiBSIM4kgisl : 1e199);
    case omiBSIM4_MOD_RGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4rgislGiven ? mod->omiBSIM4rgisl : 1e199);
    case omiBSIM4_MOD_AIGC:
      return (mod->omiBSIM4aigcGiven ? mod->omiBSIM4aigc : 1e199);
    case omiBSIM4_MOD_BIGC:
      return (mod->omiBSIM4bigcGiven ? mod->omiBSIM4bigc : 1e199);
    case omiBSIM4_MOD_CIGC:
      return (mod->omiBSIM4cigcGiven ? mod->omiBSIM4cigc : 1e199);
    case omiBSIM4_MOD_AIGSD:
      return (mod->omiBSIM4aigsdGiven ? mod->omiBSIM4aigsd : 1e199);
    case omiBSIM4_MOD_BIGSD:
      return (mod->omiBSIM4bigsdGiven ? mod->omiBSIM4bigsd : 1e199);
    case omiBSIM4_MOD_CIGSD:
      return (mod->omiBSIM4cigsdGiven ? mod->omiBSIM4cigsd : 1e199);
    case omiBSIM4_MOD_AIGS:
      return (mod->omiBSIM4aigsGiven ? mod->omiBSIM4aigs : 1e199);
    case omiBSIM4_MOD_BIGS:
      return (mod->omiBSIM4bigsGiven ? mod->omiBSIM4bigs : 1e199);
    case omiBSIM4_MOD_CIGS:
      return (mod->omiBSIM4cigsGiven ? mod->omiBSIM4cigs : 1e199);
    case omiBSIM4_MOD_AIGD:
      return (mod->omiBSIM4aigdGiven ? mod->omiBSIM4aigd : 1e199);
    case omiBSIM4_MOD_BIGD:
      return (mod->omiBSIM4bigdGiven ? mod->omiBSIM4bigd : 1e199);
    case omiBSIM4_MOD_CIGD:
      return (mod->omiBSIM4cigdGiven ? mod->omiBSIM4cigd : 1e199);
    case omiBSIM4_MOD_AIGBACC:
      return (mod->omiBSIM4aigbaccGiven ? mod->omiBSIM4aigbacc : 1e199);
    case omiBSIM4_MOD_BIGBACC:
      return (mod->omiBSIM4bigbaccGiven ? mod->omiBSIM4bigbacc : 1e199);
    case omiBSIM4_MOD_CIGBACC:
      return (mod->omiBSIM4cigbaccGiven ? mod->omiBSIM4cigbacc : 1e199);
    case omiBSIM4_MOD_AIGBINV:
      return (mod->omiBSIM4aigbinvGiven ? mod->omiBSIM4aigbinv : 1e199);
    case omiBSIM4_MOD_BIGBINV:
      return (mod->omiBSIM4bigbinvGiven ? mod->omiBSIM4bigbinv : 1e199);
    case omiBSIM4_MOD_CIGBINV:
      return (mod->omiBSIM4cigbinvGiven ? mod->omiBSIM4cigbinv : 1e199);
    case omiBSIM4_MOD_NIGC:
      return (mod->omiBSIM4nigcGiven ? mod->omiBSIM4nigc : 1e199);
    case omiBSIM4_MOD_NIGBINV:
      return (mod->omiBSIM4nigbinvGiven ? mod->omiBSIM4nigbinv : 1e199);
    case omiBSIM4_MOD_NIGBACC:
      return (mod->omiBSIM4nigbaccGiven ? mod->omiBSIM4nigbacc : 1e199);
    case omiBSIM4_MOD_NTOX:
      return (mod->omiBSIM4ntoxGiven ? mod->omiBSIM4ntox : 1e199);
    case omiBSIM4_MOD_EIGBINV:
      return (mod->omiBSIM4eigbinvGiven ? mod->omiBSIM4eigbinv : 1e199);
    case omiBSIM4_MOD_PIGCD:
      return (mod->omiBSIM4pigcdGiven ? mod->omiBSIM4pigcd : 1e199);
    case omiBSIM4_MOD_POXEDGE:
      return (mod->omiBSIM4poxedgeGiven ? mod->omiBSIM4poxedge : 1e199);
    case omiBSIM4_MOD_XRCRG1:
      return (mod->omiBSIM4xrcrg1Given ? mod->omiBSIM4xrcrg1 : 1e199);
    case omiBSIM4_MOD_XRCRG2:
      return (mod->omiBSIM4xrcrg2Given ? mod->omiBSIM4xrcrg2 : 1e199);
    case omiBSIM4_MOD_LAMBDA:
      return (mod->omiBSIM4lambdaGiven ? mod->omiBSIM4lambda : 1e199);
    case omiBSIM4_MOD_VTL:
      return (mod->omiBSIM4vtlGiven ? mod->omiBSIM4vtl : 1e199);
    case omiBSIM4_MOD_XN:
      return (mod->omiBSIM4xnGiven ? mod->omiBSIM4xn : 1e199);
    case omiBSIM4_MOD_LC:
      return (mod->omiBSIM4lcGiven ? mod->omiBSIM4lc : 1e199);
    case omiBSIM4_MOD_TNOIA:
      return (mod->omiBSIM4tnoiaGiven ? mod->omiBSIM4tnoia : 1e199);
    case omiBSIM4_MOD_TNOIB:
      return (mod->omiBSIM4tnoibGiven ? mod->omiBSIM4tnoib : 1e199);
    case omiBSIM4_MOD_TNOIC:
      return (mod->omiBSIM4tnoicGiven ? mod->omiBSIM4tnoic : 1e199);
    case omiBSIM4_MOD_RNOIA:
      return (mod->omiBSIM4rnoiaGiven ? mod->omiBSIM4rnoia : 1e199);
    case omiBSIM4_MOD_RNOIB:
      return (mod->omiBSIM4rnoibGiven ? mod->omiBSIM4rnoib : 1e199);
    case omiBSIM4_MOD_RNOIC:
      return (mod->omiBSIM4rnoicGiven ? mod->omiBSIM4rnoic : 1e199);
    case omiBSIM4_MOD_NTNOI:
      return (mod->omiBSIM4ntnoiGiven ? mod->omiBSIM4ntnoi : 1e199);
    case omiBSIM4_MOD_VFBSDOFF:
      return (mod->omiBSIM4vfbsdoffGiven ? mod->omiBSIM4vfbsdoff : 1e199);
    case omiBSIM4_MOD_TVFBSDOFF:
      return (mod->omiBSIM4tvfbsdoffGiven ? mod->omiBSIM4tvfbsdoff
                                          : 1e199);
    case omiBSIM4_MOD_LINTNOI:
      return (mod->omiBSIM4lintnoiGiven ? mod->omiBSIM4lintnoi : 1e199);

    /* stress effect */
    case omiBSIM4_MOD_SAREF:
      return (mod->omiBSIM4sarefGiven ? mod->omiBSIM4saref : 1e199);
    case omiBSIM4_MOD_SBREF:
      return (mod->omiBSIM4sbrefGiven ? mod->omiBSIM4sbref : 1e199);
    case omiBSIM4_MOD_WLOD:
      return (mod->omiBSIM4wlodGiven ? mod->omiBSIM4wlod : 1e199);
    case omiBSIM4_MOD_KU0:
      return (mod->omiBSIM4ku0Given ? mod->omiBSIM4ku0 : 1e199);
    case omiBSIM4_MOD_KVSAT:
      return (mod->omiBSIM4kvsatGiven ? mod->omiBSIM4kvsat : 1e199);
    case omiBSIM4_MOD_KVTH0:
      return (mod->omiBSIM4kvth0Given ? mod->omiBSIM4kvth0 : 1e199);
    case omiBSIM4_MOD_TKU0:
      return (mod->omiBSIM4tku0Given ? mod->omiBSIM4tku0 : 1e199);
    case omiBSIM4_MOD_LLODKU0:
      return (mod->omiBSIM4llodku0Given ? mod->omiBSIM4llodku0 : 1e199);
    case omiBSIM4_MOD_WLODKU0:
      return (mod->omiBSIM4wlodku0Given ? mod->omiBSIM4wlodku0 : 1e199);
    case omiBSIM4_MOD_LLODVTH:
      return (mod->omiBSIM4llodvthGiven ? mod->omiBSIM4llodvth : 1e199);
    case omiBSIM4_MOD_WLODVTH:
      return (mod->omiBSIM4wlodvthGiven ? mod->omiBSIM4wlodvth : 1e199);
    case omiBSIM4_MOD_LKU0:
      return (mod->omiBSIM4lku0Given ? mod->omiBSIM4lku0 : 1e199);
    case omiBSIM4_MOD_WKU0:
      return (mod->omiBSIM4wku0Given ? mod->omiBSIM4wku0 : 1e199);
    case omiBSIM4_MOD_PKU0:
      return (mod->omiBSIM4pku0Given ? mod->omiBSIM4pku0 : 1e199);
    case omiBSIM4_MOD_LKVTH0:
      return (mod->omiBSIM4lkvth0Given ? mod->omiBSIM4lkvth0 : 1e199);
    case omiBSIM4_MOD_WKVTH0:
      return (mod->omiBSIM4wkvth0Given ? mod->omiBSIM4wkvth0 : 1e199);
    case omiBSIM4_MOD_PKVTH0:
      return (mod->omiBSIM4pkvth0Given ? mod->omiBSIM4pkvth0 : 1e199);
    case omiBSIM4_MOD_STK2:
      return (mod->omiBSIM4stk2Given ? mod->omiBSIM4stk2 : 1e199);
    case omiBSIM4_MOD_LODK2:
      return (mod->omiBSIM4lodk2Given ? mod->omiBSIM4lodk2 : 1e199);
    case omiBSIM4_MOD_STETA0:
      return (mod->omiBSIM4steta0Given ? mod->omiBSIM4steta0 : 1e199);
    case omiBSIM4_MOD_LODETA0:
      return (mod->omiBSIM4lodeta0Given ? mod->omiBSIM4lodeta0 : 1e199);

    case omiBSIM4_MOD_WEB:
      return (mod->omiBSIM4webGiven ? mod->omiBSIM4web : 1e199);
    case omiBSIM4_MOD_WEC:
      return (mod->omiBSIM4wecGiven ? mod->omiBSIM4wec : 1e199);
    case omiBSIM4_MOD_KVTH0WE:
      return (mod->omiBSIM4kvth0weGiven ? mod->omiBSIM4kvth0we : 1e199);
    case omiBSIM4_MOD_K2WE:
      return (mod->omiBSIM4k2weGiven ? mod->omiBSIM4k2we : 1e199);
    case omiBSIM4_MOD_KU0WE:
      return (mod->omiBSIM4ku0weGiven ? mod->omiBSIM4ku0we : 1e199);
    case omiBSIM4_MOD_SCREF:
      return (mod->omiBSIM4screfGiven ? mod->omiBSIM4scref : 1e199);
    case omiBSIM4_MOD_WPEMOD:
      return (mod->omiBSIM4wpemodGiven ? mod->omiBSIM4wpemod : 1e199);
    case omiBSIM4_MOD_LKVTH0WE:
      return (mod->omiBSIM4lkvth0weGiven ? mod->omiBSIM4lkvth0we : 1e199);
    case omiBSIM4_MOD_LK2WE:
      return (mod->omiBSIM4lk2weGiven ? mod->omiBSIM4lk2we : 1e199);
    case omiBSIM4_MOD_LKU0WE:
      return (mod->omiBSIM4lku0weGiven ? mod->omiBSIM4lku0we : 1e199);
    case omiBSIM4_MOD_WKVTH0WE:
      return (mod->omiBSIM4wkvth0weGiven ? mod->omiBSIM4wkvth0we : 1e199);
    case omiBSIM4_MOD_WK2WE:
      return (mod->omiBSIM4wk2weGiven ? mod->omiBSIM4wk2we : 1e199);
    case omiBSIM4_MOD_WKU0WE:
      return (mod->omiBSIM4wku0weGiven ? mod->omiBSIM4wku0we : 1e199);
    case omiBSIM4_MOD_PKVTH0WE:
      return (mod->omiBSIM4pkvth0weGiven ? mod->omiBSIM4pkvth0we : 1e199);
    case omiBSIM4_MOD_PK2WE:
      return (mod->omiBSIM4pk2weGiven ? mod->omiBSIM4pk2we : 1e199);
    case omiBSIM4_MOD_PKU0WE:
      return (mod->omiBSIM4pku0weGiven ? mod->omiBSIM4pku0we : 1e199);

    case omiBSIM4_MOD_BETA0:
      return (mod->omiBSIM4beta0Given ? mod->omiBSIM4beta0 : 1e199);
    case omiBSIM4_MOD_IJTHDFWD:
      return (mod->omiBSIM4ijthdfwdGiven ? mod->omiBSIM4ijthdfwd : 1e199);
    case omiBSIM4_MOD_IJTHSFWD:
      return (mod->omiBSIM4ijthsfwdGiven ? mod->omiBSIM4ijthsfwd : 1e199);
    case omiBSIM4_MOD_IJTHDREV:
      return (mod->omiBSIM4ijthdrevGiven ? mod->omiBSIM4ijthdrev : 1e199);
    case omiBSIM4_MOD_IJTHSREV:
      return (mod->omiBSIM4ijthsrevGiven ? mod->omiBSIM4ijthsrev : 1e199);
    case omiBSIM4_MOD_XJBVD:
      return (mod->omiBSIM4xjbvdGiven ? mod->omiBSIM4xjbvd : 1e199);
    case omiBSIM4_MOD_XJBVS:
      return (mod->omiBSIM4xjbvsGiven ? mod->omiBSIM4xjbvs : 1e199);
    case omiBSIM4_MOD_BVD:
      return (mod->omiBSIM4bvdGiven ? mod->omiBSIM4bvd : 1e199);
    case omiBSIM4_MOD_BVS:
      return (mod->omiBSIM4bvsGiven ? mod->omiBSIM4bvs : 1e199);

    /* reverse diode */
    case omiBSIM4_MOD_JTSS:
      return (mod->omiBSIM4jtssGiven ? mod->omiBSIM4jtss : 1e199);
    case omiBSIM4_MOD_JTSD:
      return (mod->omiBSIM4jtsdGiven ? mod->omiBSIM4jtsd : 1e199);
    case omiBSIM4_MOD_JTSSWS:
      return (mod->omiBSIM4jtsswsGiven ? mod->omiBSIM4jtssws : 1e199);
    case omiBSIM4_MOD_JTSSWD:
      return (mod->omiBSIM4jtsswdGiven ? mod->omiBSIM4jtsswd : 1e199);
    case omiBSIM4_MOD_JTSSWGS:
      return (mod->omiBSIM4jtsswgsGiven ? mod->omiBSIM4jtsswgs : 1e199);
    case omiBSIM4_MOD_JTSSWGD:
      return (mod->omiBSIM4jtsswgdGiven ? mod->omiBSIM4jtsswgd : 1e199);
    case omiBSIM4_MOD_JTWEFF:
      return (mod->omiBSIM4jtweffGiven ? mod->omiBSIM4jtweff : 1e199);
    case omiBSIM4_MOD_NJTS:
      return (mod->omiBSIM4njtsGiven ? mod->omiBSIM4njts : 1e199);
    case omiBSIM4_MOD_NJTSSW:
      return (mod->omiBSIM4njtsswGiven ? mod->omiBSIM4njtssw : 1e199);
    case omiBSIM4_MOD_NJTSSWG:
      return (mod->omiBSIM4njtsswgGiven ? mod->omiBSIM4njtsswg : 1e199);
    case omiBSIM4_MOD_NJTSD:
      return (mod->omiBSIM4njtsdGiven ? mod->omiBSIM4njtsd : 1e199);
    case omiBSIM4_MOD_NJTSSWD:
      return (mod->omiBSIM4njtsswdGiven ? mod->omiBSIM4njtsswd : 1e199);
    case omiBSIM4_MOD_NJTSSWGD:
      return (mod->omiBSIM4njtsswgdGiven ? mod->omiBSIM4njtsswgd : 1e199);
    case omiBSIM4_MOD_XTSS:
      return (mod->omiBSIM4xtssGiven ? mod->omiBSIM4xtss : 1e199);
    case omiBSIM4_MOD_XTSD:
      return (mod->omiBSIM4xtsdGiven ? mod->omiBSIM4xtsd : 1e199);
    case omiBSIM4_MOD_XTSSWS:
      return (mod->omiBSIM4xtsswsGiven ? mod->omiBSIM4xtssws : 1e199);
    case omiBSIM4_MOD_XTSSWD:
      return (mod->omiBSIM4xtsswdGiven ? mod->omiBSIM4xtsswd : 1e199);
    case omiBSIM4_MOD_XTSSWGS:
      return (mod->omiBSIM4xtsswgsGiven ? mod->omiBSIM4xtsswgs : 1e199);
    case omiBSIM4_MOD_XTSSWGD:
      return (mod->omiBSIM4xtsswgdGiven ? mod->omiBSIM4xtsswgd : 1e199);
    case omiBSIM4_MOD_TNJTS:
      return (mod->omiBSIM4tnjtsGiven ? mod->omiBSIM4tnjts : 1e199);
    case omiBSIM4_MOD_TNJTSSW:
      return (mod->omiBSIM4tnjtsswGiven ? mod->omiBSIM4tnjtssw : 1e199);
    case omiBSIM4_MOD_TNJTSSWG:
      return (mod->omiBSIM4tnjtsswgGiven ? mod->omiBSIM4tnjtsswg : 1e199);
    case omiBSIM4_MOD_TNJTSD:
      return (mod->omiBSIM4tnjtsdGiven ? mod->omiBSIM4tnjtsd : 1e199);
    case omiBSIM4_MOD_TNJTSSWD:
      return (mod->omiBSIM4tnjtsswdGiven ? mod->omiBSIM4tnjtsswd : 1e199);
    case omiBSIM4_MOD_TNJTSSWGD:
      return (mod->omiBSIM4tnjtsswgdGiven ? mod->omiBSIM4tnjtsswgd
                                          : 1e199);
    case omiBSIM4_MOD_VTSS:
      return (mod->omiBSIM4vtssGiven ? mod->omiBSIM4vtss : 1e199);
    case omiBSIM4_MOD_VTSD:
      return (mod->omiBSIM4vtsdGiven ? mod->omiBSIM4vtsd : 1e199);
    case omiBSIM4_MOD_VTSSWS:
      return (mod->omiBSIM4vtsswsGiven ? mod->omiBSIM4vtssws : 1e199);
    case omiBSIM4_MOD_VTSSWD:
      return (mod->omiBSIM4vtsswdGiven ? mod->omiBSIM4vtsswd : 1e199);
    case omiBSIM4_MOD_VTSSWGS:
      return (mod->omiBSIM4vtsswgsGiven ? mod->omiBSIM4vtsswgs : 1e199);
    case omiBSIM4_MOD_VTSSWGD:
      return (mod->omiBSIM4vtsswgdGiven ? mod->omiBSIM4vtsswgd : 1e199);

    case omiBSIM4_MOD_VFB:
      return (mod->omiBSIM4vfbGiven ? mod->omiBSIM4vfb : 1e199);

    case omiBSIM4_MOD_GBMIN:
      return (mod->omiBSIM4gbminGiven ? mod->omiBSIM4gbmin : 1e199);
    case omiBSIM4_MOD_RBDB:
      return (mod->omiBSIM4rbdbGiven ? mod->omiBSIM4rbdb : 1e199);
    case omiBSIM4_MOD_RBPB:
      return (mod->omiBSIM4rbpbGiven ? mod->omiBSIM4rbpb : 1e199);
    case omiBSIM4_MOD_RBSB:
      return (mod->omiBSIM4rbsbGiven ? mod->omiBSIM4rbsb : 1e199);
    case omiBSIM4_MOD_RBPS:
      return (mod->omiBSIM4rbpsGiven ? mod->omiBSIM4rbps : 1e199);
    case omiBSIM4_MOD_RBPD:
      return (mod->omiBSIM4rbpdGiven ? mod->omiBSIM4rbpd : 1e199);

    case omiBSIM4_MOD_RBPS0:
      return (mod->omiBSIM4rbps0Given ? mod->omiBSIM4rbps0 : 1e199);
    case omiBSIM4_MOD_RBPSL:
      return (mod->omiBSIM4rbpslGiven ? mod->omiBSIM4rbpsl : 1e199);
    case omiBSIM4_MOD_RBPSW:
      return (mod->omiBSIM4rbpswGiven ? mod->omiBSIM4rbpsw : 1e199);
    case omiBSIM4_MOD_RBPSNF:
      return (mod->omiBSIM4rbpsnfGiven ? mod->omiBSIM4rbpsnf : 1e199);

    case omiBSIM4_MOD_RBPD0:
      return (mod->omiBSIM4rbpd0Given ? mod->omiBSIM4rbpd0 : 1e199);
    case omiBSIM4_MOD_RBPDL:
      return (mod->omiBSIM4rbpdlGiven ? mod->omiBSIM4rbpdl : 1e199);
    case omiBSIM4_MOD_RBPDW:
      return (mod->omiBSIM4rbpdwGiven ? mod->omiBSIM4rbpdw : 1e199);
    case omiBSIM4_MOD_RBPDNF:
      return (mod->omiBSIM4rbpdnfGiven ? mod->omiBSIM4rbpdnf : 1e199);

    case omiBSIM4_MOD_RBPBX0:
      return (mod->omiBSIM4rbpbx0Given ? mod->omiBSIM4rbpbx0 : 1e199);
    case omiBSIM4_MOD_RBPBXL:
      return (mod->omiBSIM4rbpbxlGiven ? mod->omiBSIM4rbpbxl : 1e199);
    case omiBSIM4_MOD_RBPBXW:
      return (mod->omiBSIM4rbpbxwGiven ? mod->omiBSIM4rbpbxw : 1e199);
    case omiBSIM4_MOD_RBPBXNF:
      return (mod->omiBSIM4rbpbxnfGiven ? mod->omiBSIM4rbpbxnf : 1e199);
    case omiBSIM4_MOD_RBPBY0:
      return (mod->omiBSIM4rbpby0Given ? mod->omiBSIM4rbpby0 : 1e199);
    case omiBSIM4_MOD_RBPBYL:
      return (mod->omiBSIM4rbpbylGiven ? mod->omiBSIM4rbpbyl : 1e199);
    case omiBSIM4_MOD_RBPBYW:
      return (mod->omiBSIM4rbpbywGiven ? mod->omiBSIM4rbpbyw : 1e199);
    case omiBSIM4_MOD_RBPBYNF:
      return (mod->omiBSIM4rbpbynfGiven ? mod->omiBSIM4rbpbynf : 1e199);
    case omiBSIM4_MOD_RBSBX0:
      return (mod->omiBSIM4rbsbx0Given ? mod->omiBSIM4rbsbx0 : 1e199);
    case omiBSIM4_MOD_RBSBY0:
      return (mod->omiBSIM4rbsby0Given ? mod->omiBSIM4rbsby0 : 1e199);
    case omiBSIM4_MOD_RBDBX0:
      return (mod->omiBSIM4rbdbx0Given ? mod->omiBSIM4rbdbx0 : 1e199);
    case omiBSIM4_MOD_RBDBY0:
      return (mod->omiBSIM4rbdby0Given ? mod->omiBSIM4rbdby0 : 1e199);

    case omiBSIM4_MOD_RBSDBXL:
      return (mod->omiBSIM4rbsdbxlGiven ? mod->omiBSIM4rbsdbxl : 1e199);
    case omiBSIM4_MOD_RBSDBXW:
      return (mod->omiBSIM4rbsdbxwGiven ? mod->omiBSIM4rbsdbxw : 1e199);
    case omiBSIM4_MOD_RBSDBXNF:
      return (mod->omiBSIM4rbsdbxnfGiven ? mod->omiBSIM4rbsdbxnf : 1e199);
    case omiBSIM4_MOD_RBSDBYL:
      return (mod->omiBSIM4rbsdbylGiven ? mod->omiBSIM4rbsdbyl : 1e199);
    case omiBSIM4_MOD_RBSDBYW:
      return (mod->omiBSIM4rbsdbywGiven ? mod->omiBSIM4rbsdbyw : 1e199);
    case omiBSIM4_MOD_RBSDBYNF:
      return (mod->omiBSIM4rbsdbynfGiven ? mod->omiBSIM4rbsdbynf : 1e199);

    case omiBSIM4_MOD_CGSL:
      return (mod->omiBSIM4cgslGiven ? mod->omiBSIM4cgsl : 1e199);
    case omiBSIM4_MOD_CGDL:
      return (mod->omiBSIM4cgdlGiven ? mod->omiBSIM4cgdl : 1e199);
    case omiBSIM4_MOD_CKAPPAS:
      return (mod->omiBSIM4ckappasGiven ? mod->omiBSIM4ckappas : 1e199);
    case omiBSIM4_MOD_CKAPPAD:
      return (mod->omiBSIM4ckappadGiven ? mod->omiBSIM4ckappad : 1e199);
    case omiBSIM4_MOD_CF:
      return (mod->omiBSIM4cfGiven ? mod->omiBSIM4cf : 1e199);
    case omiBSIM4_MOD_CLC:
      return (mod->omiBSIM4clcGiven ? mod->omiBSIM4clc : 1e199);
    case omiBSIM4_MOD_CLE:
      return (mod->omiBSIM4cleGiven ? mod->omiBSIM4cle : 1e199);
    case omiBSIM4_MOD_DWC:
      return (mod->omiBSIM4dwcGiven ? mod->omiBSIM4dwc : 1e199);
    case omiBSIM4_MOD_DLC:
      return (mod->omiBSIM4dlcGiven ? mod->omiBSIM4dlc : 1e199);
    case omiBSIM4_MOD_XW:
      return (mod->omiBSIM4xwGiven ? mod->omiBSIM4xw : 1e199);
    case omiBSIM4_MOD_XL:
      return (mod->omiBSIM4xlGiven ? mod->omiBSIM4xl : 1e199);
    case omiBSIM4_MOD_DLCIG:
      return (mod->omiBSIM4dlcigGiven ? mod->omiBSIM4dlcig : 1e199);
    case omiBSIM4_MOD_DLCIGD:
      return (mod->omiBSIM4dlcigdGiven ? mod->omiBSIM4dlcigd : 1e199);
    case omiBSIM4_MOD_DWJ:
      return (mod->omiBSIM4dwjGiven ? mod->omiBSIM4dwj : 1e199);
    case omiBSIM4_MOD_VFBCV:
      return (mod->omiBSIM4vfbcvGiven ? mod->omiBSIM4vfbcv : 1e199);
    case omiBSIM4_MOD_ACDE:
      return (mod->omiBSIM4acdeGiven ? mod->omiBSIM4acde : 1e199);
    case omiBSIM4_MOD_MOIN:
      return (mod->omiBSIM4moinGiven ? mod->omiBSIM4moin : 1e199);
    case omiBSIM4_MOD_NOFF:
      return (mod->omiBSIM4noffGiven ? mod->omiBSIM4noff : 1e199);
    case omiBSIM4_MOD_VOFFCV:
      return (mod->omiBSIM4voffcvGiven ? mod->omiBSIM4voffcv : 1e199);
    case omiBSIM4_MOD_DMCG:
      return (mod->omiBSIM4dmcgGiven ? mod->omiBSIM4dmcg : 1e199);
    case omiBSIM4_MOD_DMCI:
      return (mod->omiBSIM4dmciGiven ? mod->omiBSIM4dmci : 1e199);
    case omiBSIM4_MOD_DMDG:
      return (mod->omiBSIM4dmdgGiven ? mod->omiBSIM4dmdg : 1e199);
    case omiBSIM4_MOD_DMCGT:
      return (mod->omiBSIM4dmcgtGiven ? mod->omiBSIM4dmcgt : 1e199);
    case omiBSIM4_MOD_XGW:
      return (mod->omiBSIM4xgwGiven ? mod->omiBSIM4xgw : 1e199);
    case omiBSIM4_MOD_XGL:
      return (mod->omiBSIM4xglGiven ? mod->omiBSIM4xgl : 1e199);
    case omiBSIM4_MOD_RSHG:
      return (mod->omiBSIM4rshgGiven ? mod->omiBSIM4rshg : 1e199);
    case omiBSIM4_MOD_NGCON:
      return (mod->omiBSIM4ngconGiven ? mod->omiBSIM4ngcon : 1e199);
    case omiBSIM4_MOD_TCJ:
      return (mod->omiBSIM4tcjGiven ? mod->omiBSIM4tcj : 1e199);
    case omiBSIM4_MOD_TPB:
      return (mod->omiBSIM4tpbGiven ? mod->omiBSIM4tpb : 1e199);
    case omiBSIM4_MOD_TCJSW:
      return (mod->omiBSIM4tcjswGiven ? mod->omiBSIM4tcjsw : 1e199);
    case omiBSIM4_MOD_TPBSW:
      return (mod->omiBSIM4tpbswGiven ? mod->omiBSIM4tpbsw : 1e199);
    case omiBSIM4_MOD_TCJSWG:
      return (mod->omiBSIM4tcjswgGiven ? mod->omiBSIM4tcjswg : 1e199);
    case omiBSIM4_MOD_TPBSWG:
      return (mod->omiBSIM4tpbswgGiven ? mod->omiBSIM4tpbswg : 1e199);

    /* Length dependence */
    case omiBSIM4_MOD_LCDSC:
      return (mod->omiBSIM4lcdscGiven ? mod->omiBSIM4lcdsc : 1e199);

    case omiBSIM4_MOD_LCDSCB:
      return (mod->omiBSIM4lcdscbGiven ? mod->omiBSIM4lcdscb : 1e199);
    case omiBSIM4_MOD_LCDSCD:
      return (mod->omiBSIM4lcdscdGiven ? mod->omiBSIM4lcdscd : 1e199);
    case omiBSIM4_MOD_LCIT:
      return (mod->omiBSIM4lcitGiven ? mod->omiBSIM4lcit : 1e199);
    case omiBSIM4_MOD_LNFACTOR:
      return (mod->omiBSIM4lnfactorGiven ? mod->omiBSIM4lnfactor : 1e199);
    case omiBSIM4_MOD_LXJ:
      return (mod->omiBSIM4lxjGiven ? mod->omiBSIM4lxj : 1e199);
    case omiBSIM4_MOD_LVSAT:
      return (mod->omiBSIM4lvsatGiven ? mod->omiBSIM4lvsat : 1e199);

    case omiBSIM4_MOD_LA0:
      return (mod->omiBSIM4la0Given ? mod->omiBSIM4la0 : 1e199);
    case omiBSIM4_MOD_LAGS:
      return (mod->omiBSIM4lagsGiven ? mod->omiBSIM4lags : 1e199);
    case omiBSIM4_MOD_LA1:
      return (mod->omiBSIM4la1Given ? mod->omiBSIM4la1 : 1e199);
    case omiBSIM4_MOD_LA2:
      return (mod->omiBSIM4la2Given ? mod->omiBSIM4la2 : 1e199);
    case omiBSIM4_MOD_LAT:
      return (mod->omiBSIM4latGiven ? mod->omiBSIM4lat : 1e199);
    case omiBSIM4_MOD_LKETA:
      return (mod->omiBSIM4lketaGiven ? mod->omiBSIM4lketa : 1e199);
    case omiBSIM4_MOD_LNSUB:
      return (mod->omiBSIM4lnsubGiven ? mod->omiBSIM4lnsub : 1e199);
    case omiBSIM4_MOD_LNDEP:
      return (mod->omiBSIM4lndepGiven ? mod->omiBSIM4lndep : 1e199);
    case omiBSIM4_MOD_LNSD:
      return (mod->omiBSIM4lnsdGiven ? mod->omiBSIM4lnsd : 1e199);
    case omiBSIM4_MOD_LNGATE:
      return (mod->omiBSIM4lngateGiven ? mod->omiBSIM4lngate : 1e199);
    case omiBSIM4_MOD_LGAMMA1:
      return (mod->omiBSIM4lgamma1Given ? mod->omiBSIM4lgamma1 : 1e199);
    case omiBSIM4_MOD_LGAMMA2:
      return (mod->omiBSIM4lgamma2Given ? mod->omiBSIM4lgamma2 : 1e199);
    case omiBSIM4_MOD_LVBX:
      return (mod->omiBSIM4lvbxGiven ? mod->omiBSIM4lvbx : 1e199);
    case omiBSIM4_MOD_LVBM:
      return (mod->omiBSIM4lvbmGiven ? mod->omiBSIM4lvbm : 1e199);
    case omiBSIM4_MOD_LXT:
      return (mod->omiBSIM4lxtGiven ? mod->omiBSIM4lxt : 1e199);
    case omiBSIM4_MOD_LK1:
      return (mod->omiBSIM4lk1Given ? mod->omiBSIM4lk1 : 1e199);
    case omiBSIM4_MOD_LKT1:
      return (mod->omiBSIM4lkt1Given ? mod->omiBSIM4lkt1 : 1e199);
    case omiBSIM4_MOD_LKT1L:
      return (mod->omiBSIM4lkt1lGiven ? mod->omiBSIM4lkt1l : 1e199);
    case omiBSIM4_MOD_LKT2:
      return (mod->omiBSIM4lkt2Given ? mod->omiBSIM4lkt2 : 1e199);
    case omiBSIM4_MOD_LK2:
      return (mod->omiBSIM4lk2Given ? mod->omiBSIM4lk2 : 1e199);
    case omiBSIM4_MOD_LK3:
      return (mod->omiBSIM4lk3Given ? mod->omiBSIM4lk3 : 1e199);
    case omiBSIM4_MOD_LK3B:
      return (mod->omiBSIM4lk3bGiven ? mod->omiBSIM4lk3b : 1e199);
    case omiBSIM4_MOD_LLPE0:
      return (mod->omiBSIM4llpe0Given ? mod->omiBSIM4llpe0 : 1e199);
    case omiBSIM4_MOD_LLPEB:
      return (mod->omiBSIM4llpebGiven ? mod->omiBSIM4llpeb : 1e199);
    case omiBSIM4_MOD_LDVTP0:
      return (mod->omiBSIM4ldvtp0Given ? mod->omiBSIM4ldvtp0 : 1e199);
    case omiBSIM4_MOD_LDVTP1:
      return (mod->omiBSIM4ldvtp1Given ? mod->omiBSIM4ldvtp1 : 1e199);
    case omiBSIM4_MOD_LDVTP2: /* New DIBL/Rout */
      return (mod->omiBSIM4ldvtp2Given ? mod->omiBSIM4ldvtp2 : 1e199);
    case omiBSIM4_MOD_LDVTP3:
      return (mod->omiBSIM4ldvtp3Given ? mod->omiBSIM4ldvtp3 : 1e199);
    case omiBSIM4_MOD_LDVTP4:
      return (mod->omiBSIM4ldvtp4Given ? mod->omiBSIM4ldvtp4 : 1e199);
    case omiBSIM4_MOD_LDVTP5:
      return (mod->omiBSIM4ldvtp5Given ? mod->omiBSIM4ldvtp5 : 1e199);
    case omiBSIM4_MOD_LW0:
      return (mod->omiBSIM4lw0Given ? mod->omiBSIM4lw0 : 1e199);
    case omiBSIM4_MOD_LDVT0:
      return (mod->omiBSIM4ldvt0Given ? mod->omiBSIM4ldvt0 : 1e199);
    case omiBSIM4_MOD_LDVT1:
      return (mod->omiBSIM4ldvt1Given ? mod->omiBSIM4ldvt1 : 1e199);
    case omiBSIM4_MOD_LDVT2:
      return (mod->omiBSIM4ldvt2Given ? mod->omiBSIM4ldvt2 : 1e199);
    case omiBSIM4_MOD_LDVT0W:
      return (mod->omiBSIM4ldvt0wGiven ? mod->omiBSIM4ldvt0w : 1e199);
    case omiBSIM4_MOD_LDVT1W:
      return (mod->omiBSIM4ldvt1wGiven ? mod->omiBSIM4ldvt1w : 1e199);
    case omiBSIM4_MOD_LDVT2W:
      return (mod->omiBSIM4ldvt2wGiven ? mod->omiBSIM4ldvt2w : 1e199);
    case omiBSIM4_MOD_LDROUT:
      return (mod->omiBSIM4ldroutGiven ? mod->omiBSIM4ldrout : 1e199);
    case omiBSIM4_MOD_LDSUB:
      return (mod->omiBSIM4ldsubGiven ? mod->omiBSIM4ldsub : 1e199);
    case omiBSIM4_MOD_LVTH0:
      return (mod->omiBSIM4lvth0Given ? mod->omiBSIM4lvth0 : 1e199);
    case omiBSIM4_MOD_LUA:
      return (mod->omiBSIM4luaGiven ? mod->omiBSIM4lua : 1e199);
    case omiBSIM4_MOD_LUA1:
      return (mod->omiBSIM4lua1Given ? mod->omiBSIM4lua1 : 1e199);
    case omiBSIM4_MOD_LUB:
      return (mod->omiBSIM4lubGiven ? mod->omiBSIM4lub : 1e199);
    case omiBSIM4_MOD_LUB1:
      return (mod->omiBSIM4lub1Given ? mod->omiBSIM4lub1 : 1e199);
    case omiBSIM4_MOD_LUC:
      return (mod->omiBSIM4lucGiven ? mod->omiBSIM4luc : 1e199);
    case omiBSIM4_MOD_LUC1:
      return (mod->omiBSIM4luc1Given ? mod->omiBSIM4luc1 : 1e199);
    case omiBSIM4_MOD_LU0:
      return (mod->omiBSIM4lu0Given ? mod->omiBSIM4lu0 : 1e199);
    case omiBSIM4_MOD_LUTE:
      return (mod->omiBSIM4luteGiven ? mod->omiBSIM4lute : 1e199);
    case omiBSIM4_MOD_LUCSTE:
      return (mod->omiBSIM4lucsteGiven ? mod->omiBSIM4lucste : 1e199);
    case omiBSIM4_MOD_LVOFF:
      return (mod->omiBSIM4lvoffGiven ? mod->omiBSIM4lvoff : 1e199);
    case omiBSIM4_MOD_LTVOFF:
      return (mod->omiBSIM4ltvoffGiven ? mod->omiBSIM4ltvoff : 1e199);
    case omiBSIM4_MOD_LTNFACTOR: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4ltnfactorGiven ? mod->omiBSIM4ltnfactor
                                          : 1e199);
    case omiBSIM4_MOD_LTETA0: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4lteta0Given ? mod->omiBSIM4lteta0 : 1e199);
    case omiBSIM4_MOD_LTVOFFCV: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4ltvoffcvGiven ? mod->omiBSIM4ltvoffcv : 1e199);
    case omiBSIM4_MOD_LMINV:
      return (mod->omiBSIM4lminvGiven ? mod->omiBSIM4lminv : 1e199);
    case omiBSIM4_MOD_LMINVCV:
      return (mod->omiBSIM4lminvcvGiven ? mod->omiBSIM4lminvcv : 1e199);
    case omiBSIM4_MOD_LFPROUT:
      return (mod->omiBSIM4lfproutGiven ? mod->omiBSIM4lfprout : 1e199);
    case omiBSIM4_MOD_LPDITS:
      return (mod->omiBSIM4lpditsGiven ? mod->omiBSIM4lpdits : 1e199);
    case omiBSIM4_MOD_LPDITSD:
      return (mod->omiBSIM4lpditsdGiven ? mod->omiBSIM4lpditsd : 1e199);
    case omiBSIM4_MOD_LDELTA:
      return (mod->omiBSIM4ldeltaGiven ? mod->omiBSIM4ldelta : 1e199);
    case omiBSIM4_MOD_LRDSW:
      return (mod->omiBSIM4lrdswGiven ? mod->omiBSIM4lrdsw : 1e199);
    case omiBSIM4_MOD_LRDW:
      return (mod->omiBSIM4lrdwGiven ? mod->omiBSIM4lrdw : 1e199);
    case omiBSIM4_MOD_LRSW:
      return (mod->omiBSIM4lrswGiven ? mod->omiBSIM4lrsw : 1e199);
    case omiBSIM4_MOD_LPRWB:
      return (mod->omiBSIM4lprwbGiven ? mod->omiBSIM4lprwb : 1e199);
    case omiBSIM4_MOD_LPRWG:
      return (mod->omiBSIM4lprwgGiven ? mod->omiBSIM4lprwg : 1e199);
    case omiBSIM4_MOD_LPRT:
      return (mod->omiBSIM4lprtGiven ? mod->omiBSIM4lprt : 1e199);
    case omiBSIM4_MOD_LETA0:
      return (mod->omiBSIM4leta0Given ? mod->omiBSIM4leta0 : 1e199);
    case omiBSIM4_MOD_LETAB:
      return (mod->omiBSIM4letabGiven ? mod->omiBSIM4letab : 1e199);
    case omiBSIM4_MOD_LPCLM:
      return (mod->omiBSIM4lpclmGiven ? mod->omiBSIM4lpclm : 1e199);
    case omiBSIM4_MOD_LPDIBL1:
      return (mod->omiBSIM4lpdibl1Given ? mod->omiBSIM4lpdibl1 : 1e199);
    case omiBSIM4_MOD_LPDIBL2:
      return (mod->omiBSIM4lpdibl2Given ? mod->omiBSIM4lpdibl2 : 1e199);
    case omiBSIM4_MOD_LPDIBLB:
      return (mod->omiBSIM4lpdiblbGiven ? mod->omiBSIM4lpdiblb : 1e199);
    case omiBSIM4_MOD_LPSCBE1:
      return (mod->omiBSIM4lpscbe1Given ? mod->omiBSIM4lpscbe1 : 1e199);
    case omiBSIM4_MOD_LPSCBE2:
      return (mod->omiBSIM4lpscbe2Given ? mod->omiBSIM4lpscbe2 : 1e199);
    case omiBSIM4_MOD_LPVAG:
      return (mod->omiBSIM4lpvagGiven ? mod->omiBSIM4lpvag : 1e199);
    case omiBSIM4_MOD_LWR:
      return (mod->omiBSIM4lwrGiven ? mod->omiBSIM4lwr : 1e199);
    case omiBSIM4_MOD_LDWG:
      return (mod->omiBSIM4ldwgGiven ? mod->omiBSIM4ldwg : 1e199);
    case omiBSIM4_MOD_LDWB:
      return (mod->omiBSIM4ldwbGiven ? mod->omiBSIM4ldwb : 1e199);
    case omiBSIM4_MOD_LB0:
      return (mod->omiBSIM4lb0Given ? mod->omiBSIM4lb0 : 1e199);
    case omiBSIM4_MOD_LB1:
      return (mod->omiBSIM4lb1Given ? mod->omiBSIM4lb1 : 1e199);
    case omiBSIM4_MOD_LALPHA0:
      return (mod->omiBSIM4lalpha0Given ? mod->omiBSIM4lalpha0 : 1e199);
    case omiBSIM4_MOD_LALPHA1:
      return (mod->omiBSIM4lalpha1Given ? mod->omiBSIM4lalpha1 : 1e199);
    case omiBSIM4_MOD_LBETA0:
      return (mod->omiBSIM4lbeta0Given ? mod->omiBSIM4lbeta0 : 1e199);
    case omiBSIM4_MOD_LPHIN:
      return (mod->omiBSIM4lphinGiven ? mod->omiBSIM4lphin : 1e199);
    case omiBSIM4_MOD_LAGIDL:
      return (mod->omiBSIM4lagidlGiven ? mod->omiBSIM4lagidl : 1e199);
    case omiBSIM4_MOD_LBGIDL:
      return (mod->omiBSIM4lbgidlGiven ? mod->omiBSIM4lbgidl : 1e199);
    case omiBSIM4_MOD_LCGIDL:
      return (mod->omiBSIM4lcgidlGiven ? mod->omiBSIM4lcgidl : 1e199);
    case omiBSIM4_MOD_LEGIDL:
      return (mod->omiBSIM4legidlGiven ? mod->omiBSIM4legidl : 1e199);
    case omiBSIM4_MOD_LFGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4lfgidlGiven ? mod->omiBSIM4lfgidl : 1e199);
    case omiBSIM4_MOD_LKGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4lkgidlGiven ? mod->omiBSIM4lkgidl : 1e199);
    case omiBSIM4_MOD_LRGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4lrgidlGiven ? mod->omiBSIM4lrgidl : 1e199);
    case omiBSIM4_MOD_LAGISL:
      return (mod->omiBSIM4lagislGiven ? mod->omiBSIM4lagisl : 1e199);
    case omiBSIM4_MOD_LBGISL:
      return (mod->omiBSIM4lbgislGiven ? mod->omiBSIM4lbgisl : 1e199);
    case omiBSIM4_MOD_LCGISL:
      return (mod->omiBSIM4lcgislGiven ? mod->omiBSIM4lcgisl : 1e199);
    case omiBSIM4_MOD_LEGISL:
      return (mod->omiBSIM4legislGiven ? mod->omiBSIM4legisl : 1e199);
    case omiBSIM4_MOD_LFGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4lfgislGiven ? mod->omiBSIM4lfgisl : 1e199);
    case omiBSIM4_MOD_LKGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4lkgislGiven ? mod->omiBSIM4lkgisl : 1e199);
    case omiBSIM4_MOD_LRGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4lrgislGiven ? mod->omiBSIM4lrgisl : 1e199);
    case omiBSIM4_MOD_LAIGC:
      return (mod->omiBSIM4laigcGiven ? mod->omiBSIM4laigc : 1e199);
    case omiBSIM4_MOD_LBIGC:
      return (mod->omiBSIM4lbigcGiven ? mod->omiBSIM4lbigc : 1e199);
    case omiBSIM4_MOD_LCIGC:
      return (mod->omiBSIM4lcigcGiven ? mod->omiBSIM4lcigc : 1e199);
    case omiBSIM4_MOD_LAIGSD:
      return (mod->omiBSIM4laigsdGiven ? mod->omiBSIM4laigsd : 1e199);
    case omiBSIM4_MOD_LBIGSD:
      return (mod->omiBSIM4lbigsdGiven ? mod->omiBSIM4lbigsd : 1e199);
    case omiBSIM4_MOD_LCIGSD:
      return (mod->omiBSIM4lcigsdGiven ? mod->omiBSIM4lcigsd : 1e199);
    case omiBSIM4_MOD_LAIGS:
      return (mod->omiBSIM4laigsGiven ? mod->omiBSIM4laigs : 1e199);
    case omiBSIM4_MOD_LBIGS:
      return (mod->omiBSIM4lbigsGiven ? mod->omiBSIM4lbigs : 1e199);
    case omiBSIM4_MOD_LCIGS:
      return (mod->omiBSIM4lcigsGiven ? mod->omiBSIM4lcigs : 1e199);
    case omiBSIM4_MOD_LAIGD:
      return (mod->omiBSIM4laigdGiven ? mod->omiBSIM4laigd : 1e199);
    case omiBSIM4_MOD_LBIGD:
      return (mod->omiBSIM4lbigdGiven ? mod->omiBSIM4lbigd : 1e199);
    case omiBSIM4_MOD_LCIGD:
      return (mod->omiBSIM4lcigdGiven ? mod->omiBSIM4lcigd : 1e199);
    case omiBSIM4_MOD_LAIGBACC:
      return (mod->omiBSIM4laigbaccGiven ? mod->omiBSIM4laigbacc : 1e199);
    case omiBSIM4_MOD_LBIGBACC:
      return (mod->omiBSIM4lbigbaccGiven ? mod->omiBSIM4lbigbacc : 1e199);
    case omiBSIM4_MOD_LCIGBACC:
      return (mod->omiBSIM4lcigbaccGiven ? mod->omiBSIM4lcigbacc : 1e199);
    case omiBSIM4_MOD_LAIGBINV:
      return (mod->omiBSIM4laigbinvGiven ? mod->omiBSIM4laigbinv : 1e199);
    case omiBSIM4_MOD_LBIGBINV:
      return (mod->omiBSIM4lbigbinvGiven ? mod->omiBSIM4lbigbinv : 1e199);
    case omiBSIM4_MOD_LCIGBINV:
      return (mod->omiBSIM4lcigbinvGiven ? mod->omiBSIM4lcigbinv : 1e199);
    case omiBSIM4_MOD_LNIGC:
      return (mod->omiBSIM4lnigcGiven ? mod->omiBSIM4lnigc : 1e199);
    case omiBSIM4_MOD_LNIGBINV:
      return (mod->omiBSIM4lnigbinvGiven ? mod->omiBSIM4lnigbinv : 1e199);
    case omiBSIM4_MOD_LNIGBACC:
      return (mod->omiBSIM4lnigbaccGiven ? mod->omiBSIM4lnigbacc : 1e199);
    case omiBSIM4_MOD_LNTOX:
      return (mod->omiBSIM4lntoxGiven ? mod->omiBSIM4lntox : 1e199);
    case omiBSIM4_MOD_LEIGBINV:
      return (mod->omiBSIM4leigbinvGiven ? mod->omiBSIM4leigbinv : 1e199);
    case omiBSIM4_MOD_LPIGCD:
      return (mod->omiBSIM4lpigcdGiven ? mod->omiBSIM4lpigcd : 1e199);
    case omiBSIM4_MOD_LPOXEDGE:
      return (mod->omiBSIM4lpoxedgeGiven ? mod->omiBSIM4lpoxedge : 1e199);
    case omiBSIM4_MOD_LXRCRG1:
      return (mod->omiBSIM4lxrcrg1Given ? mod->omiBSIM4lxrcrg1 : 1e199);
    case omiBSIM4_MOD_LXRCRG2:
      return (mod->omiBSIM4lxrcrg2Given ? mod->omiBSIM4lxrcrg2 : 1e199);
    case omiBSIM4_MOD_LLAMBDA:
      return (mod->omiBSIM4llambdaGiven ? mod->omiBSIM4llambda : 1e199);
    case omiBSIM4_MOD_LVTL:
      return (mod->omiBSIM4lvtlGiven ? mod->omiBSIM4lvtl : 1e199);
    case omiBSIM4_MOD_LXN:
      return (mod->omiBSIM4lxnGiven ? mod->omiBSIM4lxn : 1e199);
    case omiBSIM4_MOD_LVFBSDOFF:
      return (mod->omiBSIM4lvfbsdoffGiven ? mod->omiBSIM4lvfbsdoff
                                          : 1e199);
    case omiBSIM4_MOD_LTVFBSDOFF:
      return (mod->omiBSIM4ltvfbsdoffGiven ? mod->omiBSIM4ltvfbsdoff
                                           : 1e199);
    case omiBSIM4_MOD_LEU:
      return (mod->omiBSIM4leuGiven ? mod->omiBSIM4leu : 1e199);
    case omiBSIM4_MOD_LUCS:
      return (mod->omiBSIM4lucsGiven ? mod->omiBSIM4lucs : 1e199);
    case omiBSIM4_MOD_LVFB:
      return (mod->omiBSIM4lvfbGiven ? mod->omiBSIM4lvfb : 1e199);
    case omiBSIM4_MOD_LCGSL:
      return (mod->omiBSIM4lcgslGiven ? mod->omiBSIM4lcgsl : 1e199);
    case omiBSIM4_MOD_LCGDL:
      return (mod->omiBSIM4lcgdlGiven ? mod->omiBSIM4lcgdl : 1e199);
    case omiBSIM4_MOD_LCKAPPAS:
      return (mod->omiBSIM4lckappasGiven ? mod->omiBSIM4lckappas : 1e199);
    case omiBSIM4_MOD_LCKAPPAD:
      return (mod->omiBSIM4lckappadGiven ? mod->omiBSIM4lckappad : 1e199);
    case omiBSIM4_MOD_LCF:
      return (mod->omiBSIM4lcfGiven ? mod->omiBSIM4lcf : 1e199);
    case omiBSIM4_MOD_LCLC:
      return (mod->omiBSIM4lclcGiven ? mod->omiBSIM4lclc : 1e199);
    case omiBSIM4_MOD_LCLE:
      return (mod->omiBSIM4lcleGiven ? mod->omiBSIM4lcle : 1e199);
    case omiBSIM4_MOD_LVFBCV:
      return (mod->omiBSIM4lvfbcvGiven ? mod->omiBSIM4lvfbcv : 1e199);
    case omiBSIM4_MOD_LACDE:
      return (mod->omiBSIM4lacdeGiven ? mod->omiBSIM4lacde : 1e199);
    case omiBSIM4_MOD_LMOIN:
      return (mod->omiBSIM4lmoinGiven ? mod->omiBSIM4lmoin : 1e199);
    case omiBSIM4_MOD_LNOFF:
      return (mod->omiBSIM4lnoffGiven ? mod->omiBSIM4lnoff : 1e199);
    case omiBSIM4_MOD_LVOFFCV:
      return (mod->omiBSIM4lvoffcvGiven ? mod->omiBSIM4lvoffcv : 1e199);

    /* Width dependence */
    case omiBSIM4_MOD_WCDSC:
      return (mod->omiBSIM4wcdscGiven ? mod->omiBSIM4wcdsc : 1e199);

    case omiBSIM4_MOD_WCDSCB:
      return (mod->omiBSIM4wcdscbGiven ? mod->omiBSIM4wcdscb : 1e199);
    case omiBSIM4_MOD_WCDSCD:
      return (mod->omiBSIM4wcdscdGiven ? mod->omiBSIM4wcdscd : 1e199);
    case omiBSIM4_MOD_WCIT:
      return (mod->omiBSIM4wcitGiven ? mod->omiBSIM4wcit : 1e199);
    case omiBSIM4_MOD_WNFACTOR:
      return (mod->omiBSIM4wnfactorGiven ? mod->omiBSIM4wnfactor : 1e199);
    case omiBSIM4_MOD_WXJ:
      return (mod->omiBSIM4wxjGiven ? mod->omiBSIM4wxj : 1e199);
    case omiBSIM4_MOD_WVSAT:
      return (mod->omiBSIM4wvsatGiven ? mod->omiBSIM4wvsat : 1e199);

    case omiBSIM4_MOD_WA0:
      return (mod->omiBSIM4wa0Given ? mod->omiBSIM4wa0 : 1e199);
    case omiBSIM4_MOD_WAGS:
      return (mod->omiBSIM4wagsGiven ? mod->omiBSIM4wags : 1e199);
    case omiBSIM4_MOD_WA1:
      return (mod->omiBSIM4wa1Given ? mod->omiBSIM4wa1 : 1e199);
    case omiBSIM4_MOD_WA2:
      return (mod->omiBSIM4wa2Given ? mod->omiBSIM4wa2 : 1e199);
    case omiBSIM4_MOD_WAT:
      return (mod->omiBSIM4watGiven ? mod->omiBSIM4wat : 1e199);
    case omiBSIM4_MOD_WKETA:
      return (mod->omiBSIM4wketaGiven ? mod->omiBSIM4wketa : 1e199);
    case omiBSIM4_MOD_WNSUB:
      return (mod->omiBSIM4wnsubGiven ? mod->omiBSIM4wnsub : 1e199);
    case omiBSIM4_MOD_WNDEP:
      return (mod->omiBSIM4wndepGiven ? mod->omiBSIM4wndep : 1e199);
    case omiBSIM4_MOD_WNSD:
      return (mod->omiBSIM4wnsdGiven ? mod->omiBSIM4wnsd : 1e199);
    case omiBSIM4_MOD_WNGATE:
      return (mod->omiBSIM4wngateGiven ? mod->omiBSIM4wngate : 1e199);
    case omiBSIM4_MOD_WGAMMA1:
      return (mod->omiBSIM4wgamma1Given ? mod->omiBSIM4wgamma1 : 1e199);
    case omiBSIM4_MOD_WGAMMA2:
      return (mod->omiBSIM4wgamma2Given ? mod->omiBSIM4wgamma2 : 1e199);
    case omiBSIM4_MOD_WVBX:
      return (mod->omiBSIM4wvbxGiven ? mod->omiBSIM4wvbx : 1e199);
    case omiBSIM4_MOD_WVBM:
      return (mod->omiBSIM4wvbmGiven ? mod->omiBSIM4wvbm : 1e199);
    case omiBSIM4_MOD_WXT:
      return (mod->omiBSIM4wxtGiven ? mod->omiBSIM4wxt : 1e199);
    case omiBSIM4_MOD_WK1:
      return (mod->omiBSIM4wk1Given ? mod->omiBSIM4wk1 : 1e199);
    case omiBSIM4_MOD_WKT1:
      return (mod->omiBSIM4wkt1Given ? mod->omiBSIM4wkt1 : 1e199);
    case omiBSIM4_MOD_WKT1L:
      return (mod->omiBSIM4wkt1lGiven ? mod->omiBSIM4wkt1l : 1e199);
    case omiBSIM4_MOD_WKT2:
      return (mod->omiBSIM4wkt2Given ? mod->omiBSIM4wkt2 : 1e199);
    case omiBSIM4_MOD_WK2:
      return (mod->omiBSIM4wk2Given ? mod->omiBSIM4wk2 : 1e199);
    case omiBSIM4_MOD_WK3:
      return (mod->omiBSIM4wk3Given ? mod->omiBSIM4wk3 : 1e199);
    case omiBSIM4_MOD_WK3B:
      return (mod->omiBSIM4wk3bGiven ? mod->omiBSIM4wk3b : 1e199);
    case omiBSIM4_MOD_WLPE0:
      return (mod->omiBSIM4wlpe0Given ? mod->omiBSIM4wlpe0 : 1e199);
    case omiBSIM4_MOD_WLPEB:
      return (mod->omiBSIM4wlpebGiven ? mod->omiBSIM4wlpeb : 1e199);
    case omiBSIM4_MOD_WDVTP0:
      return (mod->omiBSIM4wdvtp0Given ? mod->omiBSIM4wdvtp0 : 1e199);
    case omiBSIM4_MOD_WDVTP1:
      return (mod->omiBSIM4wdvtp1Given ? mod->omiBSIM4wdvtp1 : 1e199);
    case omiBSIM4_MOD_WDVTP2: /* New DIBL/Rout */
      return (mod->omiBSIM4wdvtp2Given ? mod->omiBSIM4wdvtp2 : 1e199);
    case omiBSIM4_MOD_WDVTP3:
      return (mod->omiBSIM4wdvtp3Given ? mod->omiBSIM4wdvtp3 : 1e199);
    case omiBSIM4_MOD_WDVTP4:
      return (mod->omiBSIM4wdvtp4Given ? mod->omiBSIM4wdvtp4 : 1e199);
    case omiBSIM4_MOD_WDVTP5:
      return (mod->omiBSIM4wdvtp5Given ? mod->omiBSIM4wdvtp5 : 1e199);
    case omiBSIM4_MOD_WW0:
      return (mod->omiBSIM4ww0Given ? mod->omiBSIM4ww0 : 1e199);
    case omiBSIM4_MOD_WDVT0:
      return (mod->omiBSIM4wdvt0Given ? mod->omiBSIM4wdvt0 : 1e199);
    case omiBSIM4_MOD_WDVT1:
      return (mod->omiBSIM4wdvt1Given ? mod->omiBSIM4wdvt1 : 1e199);
    case omiBSIM4_MOD_WDVT2:
      return (mod->omiBSIM4wdvt2Given ? mod->omiBSIM4wdvt2 : 1e199);
    case omiBSIM4_MOD_WDVT0W:
      return (mod->omiBSIM4wdvt0wGiven ? mod->omiBSIM4wdvt0w : 1e199);
    case omiBSIM4_MOD_WDVT1W:
      return (mod->omiBSIM4wdvt1wGiven ? mod->omiBSIM4wdvt1w : 1e199);
    case omiBSIM4_MOD_WDVT2W:
      return (mod->omiBSIM4wdvt2wGiven ? mod->omiBSIM4wdvt2w : 1e199);
    case omiBSIM4_MOD_WDROUT:
      return (mod->omiBSIM4wdroutGiven ? mod->omiBSIM4wdrout : 1e199);
    case omiBSIM4_MOD_WDSUB:
      return (mod->omiBSIM4wdsubGiven ? mod->omiBSIM4wdsub : 1e199);
    case omiBSIM4_MOD_WVTH0:
      return (mod->omiBSIM4wvth0Given ? mod->omiBSIM4wvth0 : 1e199);
    case omiBSIM4_MOD_WUA:
      return (mod->omiBSIM4wuaGiven ? mod->omiBSIM4wua : 1e199);
    case omiBSIM4_MOD_WUA1:
      return (mod->omiBSIM4wua1Given ? mod->omiBSIM4wua1 : 1e199);
    case omiBSIM4_MOD_WUB:
      return (mod->omiBSIM4wubGiven ? mod->omiBSIM4wub : 1e199);
    case omiBSIM4_MOD_WUB1:
      return (mod->omiBSIM4wub1Given ? mod->omiBSIM4wub1 : 1e199);
    case omiBSIM4_MOD_WUC:
      return (mod->omiBSIM4wucGiven ? mod->omiBSIM4wuc : 1e199);
    case omiBSIM4_MOD_WUC1:
      return (mod->omiBSIM4wuc1Given ? mod->omiBSIM4wuc1 : 1e199);
    case omiBSIM4_MOD_WU0:
      return (mod->omiBSIM4wu0Given ? mod->omiBSIM4wu0 : 1e199);
    case omiBSIM4_MOD_WUTE:
      return (mod->omiBSIM4wuteGiven ? mod->omiBSIM4wute : 1e199);
    case omiBSIM4_MOD_WUCSTE:
      return (mod->omiBSIM4wucsteGiven ? mod->omiBSIM4wucste : 1e199);
    case omiBSIM4_MOD_WVOFF:
      return (mod->omiBSIM4wvoffGiven ? mod->omiBSIM4wvoff : 1e199);
    case omiBSIM4_MOD_WTVOFF:
      return (mod->omiBSIM4wtvoffGiven ? mod->omiBSIM4wtvoff : 1e199);
    case omiBSIM4_MOD_WTNFACTOR: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4wtnfactorGiven ? mod->omiBSIM4wtnfactor
                                          : 1e199);
    case omiBSIM4_MOD_WTETA0: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4wteta0Given ? mod->omiBSIM4wteta0 : 1e199);
    case omiBSIM4_MOD_WTVOFFCV: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4wtvoffcvGiven ? mod->omiBSIM4wtvoffcv : 1e199);
    case omiBSIM4_MOD_WMINV:
      return (mod->omiBSIM4wminvGiven ? mod->omiBSIM4wminv : 1e199);
    case omiBSIM4_MOD_WMINVCV:
      return (mod->omiBSIM4wminvcvGiven ? mod->omiBSIM4wminvcv : 1e199);
    case omiBSIM4_MOD_WFPROUT:
      return (mod->omiBSIM4wfproutGiven ? mod->omiBSIM4wfprout : 1e199);
    case omiBSIM4_MOD_WPDITS:
      return (mod->omiBSIM4wpditsGiven ? mod->omiBSIM4wpdits : 1e199);
    case omiBSIM4_MOD_WPDITSD:
      return (mod->omiBSIM4wpditsdGiven ? mod->omiBSIM4wpditsd : 1e199);
    case omiBSIM4_MOD_WDELTA:
      return (mod->omiBSIM4wdeltaGiven ? mod->omiBSIM4wdelta : 1e199);
    case omiBSIM4_MOD_WRDSW:
      return (mod->omiBSIM4wrdswGiven ? mod->omiBSIM4wrdsw : 1e199);
    case omiBSIM4_MOD_WRDW:
      return (mod->omiBSIM4wrdwGiven ? mod->omiBSIM4wrdw : 1e199);
    case omiBSIM4_MOD_WRSW:
      return (mod->omiBSIM4wrswGiven ? mod->omiBSIM4wrsw : 1e199);
    case omiBSIM4_MOD_WPRWB:
      return (mod->omiBSIM4wprwbGiven ? mod->omiBSIM4wprwb : 1e199);
    case omiBSIM4_MOD_WPRWG:
      return (mod->omiBSIM4wprwgGiven ? mod->omiBSIM4wprwg : 1e199);
    case omiBSIM4_MOD_WPRT:
      return (mod->omiBSIM4wprtGiven ? mod->omiBSIM4wprt : 1e199);
    case omiBSIM4_MOD_WETA0:
      return (mod->omiBSIM4weta0Given ? mod->omiBSIM4weta0 : 1e199);
    case omiBSIM4_MOD_WETAB:
      return (mod->omiBSIM4wetabGiven ? mod->omiBSIM4wetab : 1e199);
    case omiBSIM4_MOD_WPCLM:
      return (mod->omiBSIM4wpclmGiven ? mod->omiBSIM4wpclm : 1e199);
    case omiBSIM4_MOD_WPDIBL1:
      return (mod->omiBSIM4wpdibl1Given ? mod->omiBSIM4wpdibl1 : 1e199);
    case omiBSIM4_MOD_WPDIBL2:
      return (mod->omiBSIM4wpdibl2Given ? mod->omiBSIM4wpdibl2 : 1e199);
    case omiBSIM4_MOD_WPDIBLB:
      return (mod->omiBSIM4wpdiblbGiven ? mod->omiBSIM4wpdiblb : 1e199);
    case omiBSIM4_MOD_WPSCBE1:
      return (mod->omiBSIM4wpscbe1Given ? mod->omiBSIM4wpscbe1 : 1e199);
    case omiBSIM4_MOD_WPSCBE2:
      return (mod->omiBSIM4wpscbe2Given ? mod->omiBSIM4wpscbe2 : 1e199);
    case omiBSIM4_MOD_WPVAG:
      return (mod->omiBSIM4wpvagGiven ? mod->omiBSIM4wpvag : 1e199);
    case omiBSIM4_MOD_WWR:
      return (mod->omiBSIM4wwrGiven ? mod->omiBSIM4wwr : 1e199);
    case omiBSIM4_MOD_WDWG:
      return (mod->omiBSIM4wdwgGiven ? mod->omiBSIM4wdwg : 1e199);
    case omiBSIM4_MOD_WDWB:
      return (mod->omiBSIM4wdwbGiven ? mod->omiBSIM4wdwb : 1e199);
    case omiBSIM4_MOD_WB0:
      return (mod->omiBSIM4wb0Given ? mod->omiBSIM4wb0 : 1e199);
    case omiBSIM4_MOD_WB1:
      return (mod->omiBSIM4wb1Given ? mod->omiBSIM4wb1 : 1e199);
    case omiBSIM4_MOD_WALPHA0:
      return (mod->omiBSIM4walpha0Given ? mod->omiBSIM4walpha0 : 1e199);
    case omiBSIM4_MOD_WALPHA1:
      return (mod->omiBSIM4walpha1Given ? mod->omiBSIM4walpha1 : 1e199);
    case omiBSIM4_MOD_WBETA0:
      return (mod->omiBSIM4wbeta0Given ? mod->omiBSIM4wbeta0 : 1e199);
    case omiBSIM4_MOD_WPHIN:
      return (mod->omiBSIM4wphinGiven ? mod->omiBSIM4wphin : 1e199);
    case omiBSIM4_MOD_WAGIDL:
      return (mod->omiBSIM4wagidlGiven ? mod->omiBSIM4wagidl : 1e199);
    case omiBSIM4_MOD_WBGIDL:
      return (mod->omiBSIM4wbgidlGiven ? mod->omiBSIM4wbgidl : 1e199);
    case omiBSIM4_MOD_WCGIDL:
      return (mod->omiBSIM4wcgidlGiven ? mod->omiBSIM4wcgidl : 1e199);
    case omiBSIM4_MOD_WEGIDL:
      return (mod->omiBSIM4wegidlGiven ? mod->omiBSIM4wegidl : 1e199);
    case omiBSIM4_MOD_WFGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4wfgidlGiven ? mod->omiBSIM4wfgidl : 1e199);
    case omiBSIM4_MOD_WKGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4wkgidlGiven ? mod->omiBSIM4wkgidl : 1e199);
    case omiBSIM4_MOD_WRGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4wrgidlGiven ? mod->omiBSIM4wrgidl : 1e199);
    case omiBSIM4_MOD_WAGISL:
      return (mod->omiBSIM4wagislGiven ? mod->omiBSIM4wagisl : 1e199);
    case omiBSIM4_MOD_WBGISL:
      return (mod->omiBSIM4wbgislGiven ? mod->omiBSIM4wbgisl : 1e199);
    case omiBSIM4_MOD_WCGISL:
      return (mod->omiBSIM4wcgislGiven ? mod->omiBSIM4wcgisl : 1e199);
    case omiBSIM4_MOD_WEGISL:
      return (mod->omiBSIM4wegislGiven ? mod->omiBSIM4wegisl : 1e199);
    case omiBSIM4_MOD_WFGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4wfgislGiven ? mod->omiBSIM4wfgisl : 1e199);
    case omiBSIM4_MOD_WKGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4wkgislGiven ? mod->omiBSIM4wkgisl : 1e199);
    case omiBSIM4_MOD_WRGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4wrgislGiven ? mod->omiBSIM4wrgisl : 1e199);
    case omiBSIM4_MOD_WAIGC:
      return (mod->omiBSIM4waigcGiven ? mod->omiBSIM4waigc : 1e199);
    case omiBSIM4_MOD_WBIGC:
      return (mod->omiBSIM4wbigcGiven ? mod->omiBSIM4wbigc : 1e199);
    case omiBSIM4_MOD_WCIGC:
      return (mod->omiBSIM4wcigcGiven ? mod->omiBSIM4wcigc : 1e199);
    case omiBSIM4_MOD_WAIGSD:
      return (mod->omiBSIM4waigsdGiven ? mod->omiBSIM4waigsd : 1e199);
    case omiBSIM4_MOD_WBIGSD:
      return (mod->omiBSIM4wbigsdGiven ? mod->omiBSIM4wbigsd : 1e199);
    case omiBSIM4_MOD_WCIGSD:
      return (mod->omiBSIM4wcigsdGiven ? mod->omiBSIM4wcigsd : 1e199);
    case omiBSIM4_MOD_WAIGS:
      return (mod->omiBSIM4waigsGiven ? mod->omiBSIM4waigs : 1e199);
    case omiBSIM4_MOD_WBIGS:
      return (mod->omiBSIM4wbigsGiven ? mod->omiBSIM4wbigs : 1e199);
    case omiBSIM4_MOD_WCIGS:
      return (mod->omiBSIM4wcigsGiven ? mod->omiBSIM4wcigs : 1e199);
    case omiBSIM4_MOD_WAIGD:
      return (mod->omiBSIM4waigdGiven ? mod->omiBSIM4waigd : 1e199);
    case omiBSIM4_MOD_WBIGD:
      return (mod->omiBSIM4wbigdGiven ? mod->omiBSIM4wbigd : 1e199);
    case omiBSIM4_MOD_WCIGD:
      return (mod->omiBSIM4wcigdGiven ? mod->omiBSIM4wcigd : 1e199);
    case omiBSIM4_MOD_WAIGBACC:
      return (mod->omiBSIM4waigbaccGiven ? mod->omiBSIM4waigbacc : 1e199);
    case omiBSIM4_MOD_WBIGBACC:
      return (mod->omiBSIM4wbigbaccGiven ? mod->omiBSIM4wbigbacc : 1e199);
    case omiBSIM4_MOD_WCIGBACC:
      return (mod->omiBSIM4wcigbaccGiven ? mod->omiBSIM4wcigbacc : 1e199);
    case omiBSIM4_MOD_WAIGBINV:
      return (mod->omiBSIM4waigbinvGiven ? mod->omiBSIM4waigbinv : 1e199);
    case omiBSIM4_MOD_WBIGBINV:
      return (mod->omiBSIM4wbigbinvGiven ? mod->omiBSIM4wbigbinv : 1e199);
    case omiBSIM4_MOD_WCIGBINV:
      return (mod->omiBSIM4wcigbinvGiven ? mod->omiBSIM4wcigbinv : 1e199);
    case omiBSIM4_MOD_WNIGC:
      return (mod->omiBSIM4wnigcGiven ? mod->omiBSIM4wnigc : 1e199);
    case omiBSIM4_MOD_WNIGBINV:
      return (mod->omiBSIM4wnigbinvGiven ? mod->omiBSIM4wnigbinv : 1e199);
    case omiBSIM4_MOD_WNIGBACC:
      return (mod->omiBSIM4wnigbaccGiven ? mod->omiBSIM4wnigbacc : 1e199);
    case omiBSIM4_MOD_WNTOX:
      return (mod->omiBSIM4wntoxGiven ? mod->omiBSIM4wntox : 1e199);
    case omiBSIM4_MOD_WEIGBINV:
      return (mod->omiBSIM4weigbinvGiven ? mod->omiBSIM4weigbinv : 1e199);
    case omiBSIM4_MOD_WPIGCD:
      return (mod->omiBSIM4wpigcdGiven ? mod->omiBSIM4wpigcd : 1e199);
    case omiBSIM4_MOD_WPOXEDGE:
      return (mod->omiBSIM4wpoxedgeGiven ? mod->omiBSIM4wpoxedge : 1e199);
    case omiBSIM4_MOD_WXRCRG1:
      return (mod->omiBSIM4wxrcrg1Given ? mod->omiBSIM4wxrcrg1 : 1e199);
    case omiBSIM4_MOD_WXRCRG2:
      return (mod->omiBSIM4wxrcrg2Given ? mod->omiBSIM4wxrcrg2 : 1e199);
    case omiBSIM4_MOD_WLAMBDA:
      return (mod->omiBSIM4wlambdaGiven ? mod->omiBSIM4wlambda : 1e199);
    case omiBSIM4_MOD_WVTL:
      return (mod->omiBSIM4wvtlGiven ? mod->omiBSIM4wvtl : 1e199);
    case omiBSIM4_MOD_WXN:
      return (mod->omiBSIM4wxnGiven ? mod->omiBSIM4wxn : 1e199);
    case omiBSIM4_MOD_WVFBSDOFF:
      return (mod->omiBSIM4wvfbsdoffGiven ? mod->omiBSIM4wvfbsdoff
                                          : 1e199);
    case omiBSIM4_MOD_WTVFBSDOFF:
      return (mod->omiBSIM4wtvfbsdoffGiven ? mod->omiBSIM4wtvfbsdoff
                                           : 1e199);
    case omiBSIM4_MOD_WEU:
      return (mod->omiBSIM4weuGiven ? mod->omiBSIM4weu : 1e199);
    case omiBSIM4_MOD_WUCS:
      return (mod->omiBSIM4wucsGiven ? mod->omiBSIM4wucs : 1e199);
    case omiBSIM4_MOD_WVFB:
      return (mod->omiBSIM4wvfbGiven ? mod->omiBSIM4wvfb : 1e199);
    case omiBSIM4_MOD_WCGSL:
      return (mod->omiBSIM4wcgslGiven ? mod->omiBSIM4wcgsl : 1e199);
    case omiBSIM4_MOD_WCGDL:
      return (mod->omiBSIM4wcgdlGiven ? mod->omiBSIM4wcgdl : 1e199);
    case omiBSIM4_MOD_WCKAPPAS:
      return (mod->omiBSIM4wckappasGiven ? mod->omiBSIM4wckappas : 1e199);
    case omiBSIM4_MOD_WCKAPPAD:
      return (mod->omiBSIM4wckappadGiven ? mod->omiBSIM4wckappad : 1e199);
    case omiBSIM4_MOD_WCF:
      return (mod->omiBSIM4wcfGiven ? mod->omiBSIM4wcf : 1e199);
    case omiBSIM4_MOD_WCLC:
      return (mod->omiBSIM4wclcGiven ? mod->omiBSIM4wclc : 1e199);
    case omiBSIM4_MOD_WCLE:
      return (mod->omiBSIM4wcleGiven ? mod->omiBSIM4wcle : 1e199);
    case omiBSIM4_MOD_WVFBCV:
      return (mod->omiBSIM4wvfbcvGiven ? mod->omiBSIM4wvfbcv : 1e199);
    case omiBSIM4_MOD_WACDE:
      return (mod->omiBSIM4wacdeGiven ? mod->omiBSIM4wacde : 1e199);
    case omiBSIM4_MOD_WMOIN:
      return (mod->omiBSIM4wmoinGiven ? mod->omiBSIM4wmoin : 1e199);
    case omiBSIM4_MOD_WNOFF:
      return (mod->omiBSIM4wnoffGiven ? mod->omiBSIM4wnoff : 1e199);
    case omiBSIM4_MOD_WVOFFCV:
      return (mod->omiBSIM4wvoffcvGiven ? mod->omiBSIM4wvoffcv : 1e199);

    /* Cross-term dependence */
    case omiBSIM4_MOD_PCDSC:
      return (mod->omiBSIM4pcdscGiven ? mod->omiBSIM4pcdsc : 1e199);

    case omiBSIM4_MOD_PCDSCB:
      return (mod->omiBSIM4pcdscbGiven ? mod->omiBSIM4pcdscb : 1e199);
    case omiBSIM4_MOD_PCDSCD:
      return (mod->omiBSIM4pcdscdGiven ? mod->omiBSIM4pcdscd : 1e199);
    case omiBSIM4_MOD_PCIT:
      return (mod->omiBSIM4pcitGiven ? mod->omiBSIM4pcit : 1e199);
    case omiBSIM4_MOD_PNFACTOR:
      return (mod->omiBSIM4pnfactorGiven ? mod->omiBSIM4pnfactor : 1e199);
    case omiBSIM4_MOD_PXJ:
      return (mod->omiBSIM4pxjGiven ? mod->omiBSIM4pxj : 1e199);
    case omiBSIM4_MOD_PVSAT:
      return (mod->omiBSIM4pvsatGiven ? mod->omiBSIM4pvsat : 1e199);

    case omiBSIM4_MOD_PA0:
      return (mod->omiBSIM4pa0Given ? mod->omiBSIM4pa0 : 1e199);
    case omiBSIM4_MOD_PAGS:
      return (mod->omiBSIM4pagsGiven ? mod->omiBSIM4pags : 1e199);
    case omiBSIM4_MOD_PA1:
      return (mod->omiBSIM4pa1Given ? mod->omiBSIM4pa1 : 1e199);
    case omiBSIM4_MOD_PA2:
      return (mod->omiBSIM4pa2Given ? mod->omiBSIM4pa2 : 1e199);
    case omiBSIM4_MOD_PAT:
      return (mod->omiBSIM4patGiven ? mod->omiBSIM4pat : 1e199);
    case omiBSIM4_MOD_PKETA:
      return (mod->omiBSIM4pketaGiven ? mod->omiBSIM4pketa : 1e199);
    case omiBSIM4_MOD_PNSUB:
      return (mod->omiBSIM4pnsubGiven ? mod->omiBSIM4pnsub : 1e199);
    case omiBSIM4_MOD_PNDEP:
      return (mod->omiBSIM4pndepGiven ? mod->omiBSIM4pndep : 1e199);
    case omiBSIM4_MOD_PNSD:
      return (mod->omiBSIM4pnsdGiven ? mod->omiBSIM4pnsd : 1e199);
    case omiBSIM4_MOD_PNGATE:
      return (mod->omiBSIM4pngateGiven ? mod->omiBSIM4pngate : 1e199);
    case omiBSIM4_MOD_PGAMMA1:
      return (mod->omiBSIM4pgamma1Given ? mod->omiBSIM4pgamma1 : 1e199);
    case omiBSIM4_MOD_PGAMMA2:
      return (mod->omiBSIM4pgamma2Given ? mod->omiBSIM4pgamma2 : 1e199);
    case omiBSIM4_MOD_PVBX:
      return (mod->omiBSIM4pvbxGiven ? mod->omiBSIM4pvbx : 1e199);
    case omiBSIM4_MOD_PVBM:
      return (mod->omiBSIM4pvbmGiven ? mod->omiBSIM4pvbm : 1e199);
    case omiBSIM4_MOD_PXT:
      return (mod->omiBSIM4pxtGiven ? mod->omiBSIM4pxt : 1e199);
    case omiBSIM4_MOD_PK1:
      return (mod->omiBSIM4pk1Given ? mod->omiBSIM4pk1 : 1e199);
    case omiBSIM4_MOD_PKT1:
      return (mod->omiBSIM4pkt1Given ? mod->omiBSIM4pkt1 : 1e199);
    case omiBSIM4_MOD_PKT1L:
      return (mod->omiBSIM4pkt1lGiven ? mod->omiBSIM4pkt1l : 1e199);
    case omiBSIM4_MOD_PKT2:
      return (mod->omiBSIM4pkt2Given ? mod->omiBSIM4pkt2 : 1e199);
    case omiBSIM4_MOD_PK2:
      return (mod->omiBSIM4pk2Given ? mod->omiBSIM4pk2 : 1e199);
    case omiBSIM4_MOD_PK3:
      return (mod->omiBSIM4pk3Given ? mod->omiBSIM4pk3 : 1e199);
    case omiBSIM4_MOD_PK3B:
      return (mod->omiBSIM4pk3bGiven ? mod->omiBSIM4pk3b : 1e199);
    case omiBSIM4_MOD_PLPE0:
      return (mod->omiBSIM4plpe0Given ? mod->omiBSIM4plpe0 : 1e199);
    case omiBSIM4_MOD_PLPEB:
      return (mod->omiBSIM4plpebGiven ? mod->omiBSIM4plpeb : 1e199);
    case omiBSIM4_MOD_PDVTP0:
      return (mod->omiBSIM4pdvtp0Given ? mod->omiBSIM4pdvtp0 : 1e199);
    case omiBSIM4_MOD_PDVTP1:
      return (mod->omiBSIM4pdvtp1Given ? mod->omiBSIM4pdvtp1 : 1e199);
    case omiBSIM4_MOD_PDVTP2: /* New DIBL/Rout */
      return (mod->omiBSIM4pdvtp2Given ? mod->omiBSIM4pdvtp2 : 1e199);
    case omiBSIM4_MOD_PDVTP3:
      return (mod->omiBSIM4pdvtp3Given ? mod->omiBSIM4pdvtp3 : 1e199);
    case omiBSIM4_MOD_PDVTP4:
      return (mod->omiBSIM4pdvtp4Given ? mod->omiBSIM4pdvtp4 : 1e199);
    case omiBSIM4_MOD_PDVTP5:
      return (mod->omiBSIM4pdvtp5Given ? mod->omiBSIM4pdvtp5 : 1e199);
    case omiBSIM4_MOD_PW0:
      return (mod->omiBSIM4pw0Given ? mod->omiBSIM4pw0 : 1e199);
    case omiBSIM4_MOD_PDVT0:
      return (mod->omiBSIM4pdvt0Given ? mod->omiBSIM4pdvt0 : 1e199);
    case omiBSIM4_MOD_PDVT1:
      return (mod->omiBSIM4pdvt1Given ? mod->omiBSIM4pdvt1 : 1e199);
    case omiBSIM4_MOD_PDVT2:
      return (mod->omiBSIM4pdvt2Given ? mod->omiBSIM4pdvt2 : 1e199);
    case omiBSIM4_MOD_PDVT0W:
      return (mod->omiBSIM4pdvt0wGiven ? mod->omiBSIM4pdvt0w : 1e199);
    case omiBSIM4_MOD_PDVT1W:
      return (mod->omiBSIM4pdvt1wGiven ? mod->omiBSIM4pdvt1w : 1e199);
    case omiBSIM4_MOD_PDVT2W:
      return (mod->omiBSIM4pdvt2wGiven ? mod->omiBSIM4pdvt2w : 1e199);
    case omiBSIM4_MOD_PDROUT:
      return (mod->omiBSIM4pdroutGiven ? mod->omiBSIM4pdrout : 1e199);
    case omiBSIM4_MOD_PDSUB:
      return (mod->omiBSIM4pdsubGiven ? mod->omiBSIM4pdsub : 1e199);
    case omiBSIM4_MOD_PVTH0:
      return (mod->omiBSIM4pvth0Given ? mod->omiBSIM4pvth0 : 1e199);
    case omiBSIM4_MOD_PUA:
      return (mod->omiBSIM4puaGiven ? mod->omiBSIM4pua : 1e199);
    case omiBSIM4_MOD_PUA1:
      return (mod->omiBSIM4pua1Given ? mod->omiBSIM4pua1 : 1e199);
    case omiBSIM4_MOD_PUB:
      return (mod->omiBSIM4pubGiven ? mod->omiBSIM4pub : 1e199);
    case omiBSIM4_MOD_PUB1:
      return (mod->omiBSIM4pub1Given ? mod->omiBSIM4pub1 : 1e199);
    case omiBSIM4_MOD_PUC:
      return (mod->omiBSIM4pucGiven ? mod->omiBSIM4puc : 1e199);
    case omiBSIM4_MOD_PUC1:
      return (mod->omiBSIM4puc1Given ? mod->omiBSIM4puc1 : 1e199);
    case omiBSIM4_MOD_PU0:
      return (mod->omiBSIM4pu0Given ? mod->omiBSIM4pu0 : 1e199);
    case omiBSIM4_MOD_PUTE:
      return (mod->omiBSIM4puteGiven ? mod->omiBSIM4pute : 1e199);
    case omiBSIM4_MOD_PUCSTE:
      return (mod->omiBSIM4pucsteGiven ? mod->omiBSIM4pucste : 1e199);
    case omiBSIM4_MOD_PVOFF:
      return (mod->omiBSIM4pvoffGiven ? mod->omiBSIM4pvoff : 1e199);
    case omiBSIM4_MOD_PTVOFF:
      return (mod->omiBSIM4ptvoffGiven ? mod->omiBSIM4ptvoff : 1e199);
    case omiBSIM4_MOD_PTNFACTOR: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4ptnfactorGiven ? mod->omiBSIM4ptnfactor
                                          : 1e199);
    case omiBSIM4_MOD_PTETA0: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4pteta0Given ? mod->omiBSIM4pteta0 : 1e199);
    case omiBSIM4_MOD_PTVOFFCV: /* v4.7 temp dep of leakage current  */
      return (mod->omiBSIM4ptvoffcvGiven ? mod->omiBSIM4ptvoffcv : 1e199);
    case omiBSIM4_MOD_PMINV:
      return (mod->omiBSIM4pminvGiven ? mod->omiBSIM4pminv : 1e199);
    case omiBSIM4_MOD_PMINVCV:
      return (mod->omiBSIM4pminvcvGiven ? mod->omiBSIM4pminvcv : 1e199);
    case omiBSIM4_MOD_PFPROUT:
      return (mod->omiBSIM4pfproutGiven ? mod->omiBSIM4pfprout : 1e199);
    case omiBSIM4_MOD_PPDITS:
      return (mod->omiBSIM4ppditsGiven ? mod->omiBSIM4ppdits : 1e199);
    case omiBSIM4_MOD_PPDITSD:
      return (mod->omiBSIM4ppditsdGiven ? mod->omiBSIM4ppditsd : 1e199);
    case omiBSIM4_MOD_PDELTA:
      return (mod->omiBSIM4pdeltaGiven ? mod->omiBSIM4pdelta : 1e199);
    case omiBSIM4_MOD_PRDSW:
      return (mod->omiBSIM4prdswGiven ? mod->omiBSIM4prdsw : 1e199);
    case omiBSIM4_MOD_PRDW:
      return (mod->omiBSIM4prdwGiven ? mod->omiBSIM4prdw : 1e199);
    case omiBSIM4_MOD_PRSW:
      return (mod->omiBSIM4prswGiven ? mod->omiBSIM4prsw : 1e199);
    case omiBSIM4_MOD_PPRWB:
      return (mod->omiBSIM4pprwbGiven ? mod->omiBSIM4pprwb : 1e199);
    case omiBSIM4_MOD_PPRWG:
      return (mod->omiBSIM4pprwgGiven ? mod->omiBSIM4pprwg : 1e199);
    case omiBSIM4_MOD_PPRT:
      return (mod->omiBSIM4pprtGiven ? mod->omiBSIM4pprt : 1e199);
    case omiBSIM4_MOD_PETA0:
      return (mod->omiBSIM4peta0Given ? mod->omiBSIM4peta0 : 1e199);
    case omiBSIM4_MOD_PETAB:
      return (mod->omiBSIM4petabGiven ? mod->omiBSIM4petab : 1e199);
    case omiBSIM4_MOD_PPCLM:
      return (mod->omiBSIM4ppclmGiven ? mod->omiBSIM4ppclm : 1e199);
    case omiBSIM4_MOD_PPDIBL1:
      return (mod->omiBSIM4ppdibl1Given ? mod->omiBSIM4ppdibl1 : 1e199);
    case omiBSIM4_MOD_PPDIBL2:
      return (mod->omiBSIM4ppdibl2Given ? mod->omiBSIM4ppdibl2 : 1e199);
    case omiBSIM4_MOD_PPDIBLB:
      return (mod->omiBSIM4ppdiblbGiven ? mod->omiBSIM4ppdiblb : 1e199);
    case omiBSIM4_MOD_PPSCBE1:
      return (mod->omiBSIM4ppscbe1Given ? mod->omiBSIM4ppscbe1 : 1e199);
    case omiBSIM4_MOD_PPSCBE2:
      return (mod->omiBSIM4ppscbe2Given ? mod->omiBSIM4ppscbe2 : 1e199);
    case omiBSIM4_MOD_PPVAG:
      return (mod->omiBSIM4ppvagGiven ? mod->omiBSIM4ppvag : 1e199);
    case omiBSIM4_MOD_PWR:
      return (mod->omiBSIM4pwrGiven ? mod->omiBSIM4pwr : 1e199);
    case omiBSIM4_MOD_PDWG:
      return (mod->omiBSIM4pdwgGiven ? mod->omiBSIM4pdwg : 1e199);
    case omiBSIM4_MOD_PDWB:
      return (mod->omiBSIM4pdwbGiven ? mod->omiBSIM4pdwb : 1e199);
    case omiBSIM4_MOD_PB0:
      return (mod->omiBSIM4pb0Given ? mod->omiBSIM4pb0 : 1e199);
    case omiBSIM4_MOD_PB1:
      return (mod->omiBSIM4pb1Given ? mod->omiBSIM4pb1 : 1e199);
    case omiBSIM4_MOD_PALPHA0:
      return (mod->omiBSIM4palpha0Given ? mod->omiBSIM4palpha0 : 1e199);
    case omiBSIM4_MOD_PALPHA1:
      return (mod->omiBSIM4palpha1Given ? mod->omiBSIM4palpha1 : 1e199);
    case omiBSIM4_MOD_PBETA0:
      return (mod->omiBSIM4pbeta0Given ? mod->omiBSIM4pbeta0 : 1e199);
    case omiBSIM4_MOD_PPHIN:
      return (mod->omiBSIM4pphinGiven ? mod->omiBSIM4pphin : 1e199);
    case omiBSIM4_MOD_PAGIDL:
      return (mod->omiBSIM4pagidlGiven ? mod->omiBSIM4pagidl : 1e199);
    case omiBSIM4_MOD_PBGIDL:
      return (mod->omiBSIM4pbgidlGiven ? mod->omiBSIM4pbgidl : 1e199);
    case omiBSIM4_MOD_PCGIDL:
      return (mod->omiBSIM4pcgidlGiven ? mod->omiBSIM4pcgidl : 1e199);
    case omiBSIM4_MOD_PEGIDL:
      return (mod->omiBSIM4pegidlGiven ? mod->omiBSIM4pegidl : 1e199);
    case omiBSIM4_MOD_PFGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4pfgidlGiven ? mod->omiBSIM4pfgidl : 1e199);
    case omiBSIM4_MOD_PKGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4pkgidlGiven ? mod->omiBSIM4pkgidl : 1e199);
    case omiBSIM4_MOD_PRGIDL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4prgidlGiven ? mod->omiBSIM4prgidl : 1e199);
    case omiBSIM4_MOD_PAGISL:
      return (mod->omiBSIM4pagislGiven ? mod->omiBSIM4pagisl : 1e199);
    case omiBSIM4_MOD_PBGISL:
      return (mod->omiBSIM4pbgislGiven ? mod->omiBSIM4pbgisl : 1e199);
    case omiBSIM4_MOD_PCGISL:
      return (mod->omiBSIM4pcgislGiven ? mod->omiBSIM4pcgisl : 1e199);
    case omiBSIM4_MOD_PEGISL:
      return (mod->omiBSIM4pegislGiven ? mod->omiBSIM4pegisl : 1e199);
    case omiBSIM4_MOD_PFGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4pfgislGiven ? mod->omiBSIM4pfgisl : 1e199);
    case omiBSIM4_MOD_PKGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4pkgislGiven ? mod->omiBSIM4pkgisl : 1e199);
    case omiBSIM4_MOD_PRGISL: /* v4.7 New GIDL/GISL */
      return (mod->omiBSIM4prgislGiven ? mod->omiBSIM4prgisl : 1e199);
    case omiBSIM4_MOD_PAIGC:
      return (mod->omiBSIM4paigcGiven ? mod->omiBSIM4paigc : 1e199);
    case omiBSIM4_MOD_PBIGC:
      return (mod->omiBSIM4pbigcGiven ? mod->omiBSIM4pbigc : 1e199);
    case omiBSIM4_MOD_PCIGC:
      return (mod->omiBSIM4pcigcGiven ? mod->omiBSIM4pcigc : 1e199);
    case omiBSIM4_MOD_PAIGSD:
      return (mod->omiBSIM4paigsdGiven ? mod->omiBSIM4paigsd : 1e199);
    case omiBSIM4_MOD_PBIGSD:
      return (mod->omiBSIM4pbigsdGiven ? mod->omiBSIM4pbigsd : 1e199);
    case omiBSIM4_MOD_PCIGSD:
      return (mod->omiBSIM4pcigsdGiven ? mod->omiBSIM4pcigsd : 1e199);
    case omiBSIM4_MOD_PAIGS:
      return (mod->omiBSIM4paigsGiven ? mod->omiBSIM4paigs : 1e199);
    case omiBSIM4_MOD_PBIGS:
      return (mod->omiBSIM4pbigsGiven ? mod->omiBSIM4pbigs : 1e199);
    case omiBSIM4_MOD_PCIGS:
      return (mod->omiBSIM4pcigsGiven ? mod->omiBSIM4pcigs : 1e199);
    case omiBSIM4_MOD_PAIGD:
      return (mod->omiBSIM4paigdGiven ? mod->omiBSIM4paigd : 1e199);
    case omiBSIM4_MOD_PBIGD:
      return (mod->omiBSIM4pbigdGiven ? mod->omiBSIM4pbigd : 1e199);
    case omiBSIM4_MOD_PCIGD:
      return (mod->omiBSIM4pcigdGiven ? mod->omiBSIM4pcigd : 1e199);
    case omiBSIM4_MOD_PAIGBACC:
      return (mod->omiBSIM4paigbaccGiven ? mod->omiBSIM4paigbacc : 1e199);
    case omiBSIM4_MOD_PBIGBACC:
      return (mod->omiBSIM4pbigbaccGiven ? mod->omiBSIM4pbigbacc : 1e199);
    case omiBSIM4_MOD_PCIGBACC:
      return (mod->omiBSIM4pcigbaccGiven ? mod->omiBSIM4pcigbacc : 1e199);
    case omiBSIM4_MOD_PAIGBINV:
      return (mod->omiBSIM4paigbinvGiven ? mod->omiBSIM4paigbinv : 1e199);
    case omiBSIM4_MOD_PBIGBINV:
      return (mod->omiBSIM4pbigbinvGiven ? mod->omiBSIM4pbigbinv : 1e199);
    case omiBSIM4_MOD_PCIGBINV:
      return (mod->omiBSIM4pcigbinvGiven ? mod->omiBSIM4pcigbinv : 1e199);
    case omiBSIM4_MOD_PNIGC:
      return (mod->omiBSIM4pnigcGiven ? mod->omiBSIM4pnigc : 1e199);
    case omiBSIM4_MOD_PNIGBINV:
      return (mod->omiBSIM4pnigbinvGiven ? mod->omiBSIM4pnigbinv : 1e199);
    case omiBSIM4_MOD_PNIGBACC:
      return (mod->omiBSIM4pnigbaccGiven ? mod->omiBSIM4pnigbacc : 1e199);
    case omiBSIM4_MOD_PNTOX:
      return (mod->omiBSIM4pntoxGiven ? mod->omiBSIM4pntox : 1e199);
    case omiBSIM4_MOD_PEIGBINV:
      return (mod->omiBSIM4peigbinvGiven ? mod->omiBSIM4peigbinv : 1e199);
    case omiBSIM4_MOD_PPIGCD:
      return (mod->omiBSIM4ppigcdGiven ? mod->omiBSIM4ppigcd : 1e199);
    case omiBSIM4_MOD_PPOXEDGE:
      return (mod->omiBSIM4ppoxedgeGiven ? mod->omiBSIM4ppoxedge : 1e199);
    case omiBSIM4_MOD_PXRCRG1:
      return (mod->omiBSIM4pxrcrg1Given ? mod->omiBSIM4pxrcrg1 : 1e199);
    case omiBSIM4_MOD_PXRCRG2:
      return (mod->omiBSIM4pxrcrg2Given ? mod->omiBSIM4pxrcrg2 : 1e199);
    case omiBSIM4_MOD_PLAMBDA:
      return (mod->omiBSIM4plambdaGiven ? mod->omiBSIM4plambda : 1e199);
    case omiBSIM4_MOD_PVTL:
      return (mod->omiBSIM4pvtlGiven ? mod->omiBSIM4pvtl : 1e199);
    case omiBSIM4_MOD_PXN:
      return (mod->omiBSIM4pxnGiven ? mod->omiBSIM4pxn : 1e199);
    case omiBSIM4_MOD_PVFBSDOFF:
      return (mod->omiBSIM4pvfbsdoffGiven ? mod->omiBSIM4pvfbsdoff
                                          : 1e199);
    case omiBSIM4_MOD_PTVFBSDOFF:
      return (mod->omiBSIM4ptvfbsdoffGiven ? mod->omiBSIM4ptvfbsdoff
                                           : 1e199);
    case omiBSIM4_MOD_PEU:
      return (mod->omiBSIM4peuGiven ? mod->omiBSIM4peu : 1e199);
    case omiBSIM4_MOD_PUCS:
      return (mod->omiBSIM4pucsGiven ? mod->omiBSIM4pucs : 1e199);
    case omiBSIM4_MOD_PVFB:
      return (mod->omiBSIM4pvfbGiven ? mod->omiBSIM4pvfb : 1e199);
    case omiBSIM4_MOD_PCGSL:
      return (mod->omiBSIM4pcgslGiven ? mod->omiBSIM4pcgsl : 1e199);
    case omiBSIM4_MOD_PCGDL:
      return (mod->omiBSIM4pcgdlGiven ? mod->omiBSIM4pcgdl : 1e199);
    case omiBSIM4_MOD_PCKAPPAS:
      return (mod->omiBSIM4pckappasGiven ? mod->omiBSIM4pckappas : 1e199);
    case omiBSIM4_MOD_PCKAPPAD:
      return (mod->omiBSIM4pckappadGiven ? mod->omiBSIM4pckappad : 1e199);
    case omiBSIM4_MOD_PCF:
      return (mod->omiBSIM4pcfGiven ? mod->omiBSIM4pcf : 1e199);
    case omiBSIM4_MOD_PCLC:
      return (mod->omiBSIM4pclcGiven ? mod->omiBSIM4pclc : 1e199);
    case omiBSIM4_MOD_PCLE:
      return (mod->omiBSIM4pcleGiven ? mod->omiBSIM4pcle : 1e199);
    case omiBSIM4_MOD_PVFBCV:
      return (mod->omiBSIM4pvfbcvGiven ? mod->omiBSIM4pvfbcv : 1e199);
    case omiBSIM4_MOD_PACDE:
      return (mod->omiBSIM4pacdeGiven ? mod->omiBSIM4pacde : 1e199);
    case omiBSIM4_MOD_PMOIN:
      return (mod->omiBSIM4pmoinGiven ? mod->omiBSIM4pmoin : 1e199);
    case omiBSIM4_MOD_PNOFF:
      return (mod->omiBSIM4pnoffGiven ? mod->omiBSIM4pnoff : 1e199);
    case omiBSIM4_MOD_PVOFFCV:
      return (mod->omiBSIM4pvoffcvGiven ? mod->omiBSIM4pvoffcv : 1e199);

    case omiBSIM4_MOD_TNOM:
      return (mod->omiBSIM4tnomGiven ? mod->omiBSIM4tnom : 1e199);
    case omiBSIM4_MOD_CGSO:
      return (mod->omiBSIM4cgsoGiven ? mod->omiBSIM4cgso : 1e199);
    case omiBSIM4_MOD_CGDO:
      return (mod->omiBSIM4cgdoGiven ? mod->omiBSIM4cgdo : 1e199);
    case omiBSIM4_MOD_CGBO:
      return (mod->omiBSIM4cgboGiven ? mod->omiBSIM4cgbo : 1e199);
    case omiBSIM4_MOD_XPART:
      return (mod->omiBSIM4xpartGiven ? mod->omiBSIM4xpart : 1e199);
    case omiBSIM4_MOD_RSH:
      return (mod->omiBSIM4sheetResistanceGiven ? mod->omiBSIM4sheetResistance
                                                : 1e199);
    case omiBSIM4_MOD_JSS:
      return (mod->omiBSIM4SjctSatCurDensityGiven
                  ? mod->omiBSIM4SjctSatCurDensity
                  : 1e199);
    case omiBSIM4_MOD_JSWS:
      return (mod->omiBSIM4SjctSidewallSatCurDensityGiven
                  ? mod->omiBSIM4SjctSidewallSatCurDensity
                  : 1e199);
    case omiBSIM4_MOD_JSWGS:
      return (mod->omiBSIM4SjctGateSidewallSatCurDensityGiven
                  ? mod->omiBSIM4SjctGateSidewallSatCurDensity
                  : 1e199);
    case omiBSIM4_MOD_PBS:
      return (mod->omiBSIM4SbulkJctPotentialGiven
                  ? mod->omiBSIM4SbulkJctPotential
                  : 1e199);
    case omiBSIM4_MOD_MJS:
      return (mod->omiBSIM4SbulkJctBotGradingCoeffGiven
                  ? mod->omiBSIM4SbulkJctBotGradingCoeff
                  : 1e199);
    case omiBSIM4_MOD_PBSWS:
      return (mod->omiBSIM4SsidewallJctPotentialGiven
                  ? mod->omiBSIM4SsidewallJctPotential
                  : 1e199);
    case omiBSIM4_MOD_MJSWS:
      return (mod->omiBSIM4SbulkJctSideGradingCoeffGiven
                  ? mod->omiBSIM4SbulkJctSideGradingCoeff
                  : 1e199);
    case omiBSIM4_MOD_CJS:
      return (mod->omiBSIM4SunitAreaJctCapGiven ? mod->omiBSIM4SunitAreaJctCap
                                                : 1e199);
    case omiBSIM4_MOD_CJSWS:
      return (mod->omiBSIM4SunitLengthSidewallJctCapGiven
                  ? mod->omiBSIM4SunitLengthSidewallJctCap
                  : 1e199);
    case omiBSIM4_MOD_NJS:
      return (mod->omiBSIM4SjctEmissionCoeffGiven
                  ? mod->omiBSIM4SjctEmissionCoeff
                  : 1e199);
    case omiBSIM4_MOD_PBSWGS:
      return (mod->omiBSIM4SGatesidewallJctPotentialGiven
                  ? mod->omiBSIM4SGatesidewallJctPotential
                  : 1e199);
    case omiBSIM4_MOD_MJSWGS:
      return (mod->omiBSIM4SbulkJctGateSideGradingCoeffGiven
                  ? mod->omiBSIM4SbulkJctGateSideGradingCoeff
                  : 1e199);
    case omiBSIM4_MOD_CJSWGS:
      return (mod->omiBSIM4SunitLengthGateSidewallJctCapGiven
                  ? mod->omiBSIM4SunitLengthGateSidewallJctCap
                  : 1e199);
    case omiBSIM4_MOD_XTIS:
      return (mod->omiBSIM4SjctTempExponentGiven ? mod->omiBSIM4SjctTempExponent
                                                 : 1e199);
    case omiBSIM4_MOD_JSD:
      return (mod->omiBSIM4DjctSatCurDensityGiven
                  ? mod->omiBSIM4DjctSatCurDensity
                  : 1e199);
    case omiBSIM4_MOD_JSWD:
      return (mod->omiBSIM4DjctSidewallSatCurDensityGiven
                  ? mod->omiBSIM4DjctSidewallSatCurDensity
                  : 1e199);
    case omiBSIM4_MOD_JSWGD:
      return (mod->omiBSIM4DjctGateSidewallSatCurDensityGiven
                  ? mod->omiBSIM4DjctGateSidewallSatCurDensity
                  : 1e199);
    case omiBSIM4_MOD_PBD:
      return (mod->omiBSIM4DbulkJctPotentialGiven
                  ? mod->omiBSIM4DbulkJctPotential
                  : 1e199);
    case omiBSIM4_MOD_MJD:
      return (mod->omiBSIM4DbulkJctBotGradingCoeffGiven
                  ? mod->omiBSIM4DbulkJctBotGradingCoeff
                  : 1e199);
    case omiBSIM4_MOD_PBSWD:
      return (mod->omiBSIM4DsidewallJctPotentialGiven
                  ? mod->omiBSIM4DsidewallJctPotential
                  : 1e199);
    case omiBSIM4_MOD_MJSWD:
      return (mod->omiBSIM4DbulkJctSideGradingCoeffGiven
                  ? mod->omiBSIM4DbulkJctSideGradingCoeff
                  : 1e199);
    case omiBSIM4_MOD_CJD:
      return (mod->omiBSIM4DunitAreaJctCapGiven ? mod->omiBSIM4DunitAreaJctCap
                                                : 1e199);
    case omiBSIM4_MOD_CJSWD:
      return (mod->omiBSIM4DunitLengthSidewallJctCapGiven
                  ? mod->omiBSIM4DunitLengthSidewallJctCap
                  : 1e199);
    case omiBSIM4_MOD_NJD:
      return (mod->omiBSIM4DjctEmissionCoeffGiven
                  ? mod->omiBSIM4DjctEmissionCoeff
                  : 1e199);
    case omiBSIM4_MOD_PBSWGD:
      return (mod->omiBSIM4DGatesidewallJctPotentialGiven
                  ? mod->omiBSIM4DGatesidewallJctPotential
                  : 1e199);
    case omiBSIM4_MOD_MJSWGD:
      return (mod->omiBSIM4DbulkJctGateSideGradingCoeffGiven
                  ? mod->omiBSIM4DbulkJctGateSideGradingCoeff
                  : 1e199);
    case omiBSIM4_MOD_CJSWGD:
      return (mod->omiBSIM4DunitLengthGateSidewallJctCapGiven
                  ? mod->omiBSIM4DunitLengthGateSidewallJctCap
                  : 1e199);
    case omiBSIM4_MOD_XTID:
      return (mod->omiBSIM4DjctTempExponentGiven ? mod->omiBSIM4DjctTempExponent
                                                 : 1e199);
    case omiBSIM4_MOD_LINT:
      return (mod->omiBSIM4LintGiven ? mod->omiBSIM4Lint : 1e199);
    case omiBSIM4_MOD_LL:
      return (mod->omiBSIM4LlGiven ? mod->omiBSIM4Ll : 1e199);
    case omiBSIM4_MOD_LLC:
      return (mod->omiBSIM4LlcGiven ? mod->omiBSIM4Llc : 1e199);
    case omiBSIM4_MOD_LLN:
      return (mod->omiBSIM4LlnGiven ? mod->omiBSIM4Lln : 1e199);
    case omiBSIM4_MOD_LW:
      return (mod->omiBSIM4LwGiven ? mod->omiBSIM4Lw : 1e199);
    case omiBSIM4_MOD_LWC:
      return (mod->omiBSIM4LwcGiven ? mod->omiBSIM4Lwc : 1e199);
    case omiBSIM4_MOD_LWN:
      return (mod->omiBSIM4LwnGiven ? mod->omiBSIM4Lwn : 1e199);
    case omiBSIM4_MOD_LWL:
      return (mod->omiBSIM4LwlGiven ? mod->omiBSIM4Lwl : 1e199);
    case omiBSIM4_MOD_LWLC:
      return (mod->omiBSIM4LwlcGiven ? mod->omiBSIM4Lwlc : 1e199);
    case omiBSIM4_MOD_LMIN:
      return (mod->omiBSIM4LminGiven ? mod->omiBSIM4Lmin : 1e199);
    case omiBSIM4_MOD_LMAX:
      return (mod->omiBSIM4LmaxGiven ? mod->omiBSIM4Lmax : 1e199);
    case omiBSIM4_MOD_WINT:
      return (mod->omiBSIM4WintGiven ? mod->omiBSIM4Wint : 1e199);
    case omiBSIM4_MOD_WL:
      return (mod->omiBSIM4WlGiven ? mod->omiBSIM4Wl : 1e199);
    case omiBSIM4_MOD_WLC:
      return (mod->omiBSIM4WlcGiven ? mod->omiBSIM4Wlc : 1e199);
    case omiBSIM4_MOD_WLN:
      return (mod->omiBSIM4WlnGiven ? mod->omiBSIM4Wln : 1e199);
    case omiBSIM4_MOD_WW:
      return (mod->omiBSIM4WwGiven ? mod->omiBSIM4Ww : 1e199);
    case omiBSIM4_MOD_WWC:
      return (mod->omiBSIM4WwcGiven ? mod->omiBSIM4Wwc : 1e199);
    case omiBSIM4_MOD_WWN:
      return (mod->omiBSIM4WwnGiven ? mod->omiBSIM4Wwn : 1e199);
    case omiBSIM4_MOD_WWL:
      return (mod->omiBSIM4WwlGiven ? mod->omiBSIM4Wwl : 1e199);
    case omiBSIM4_MOD_WWLC:
      return (mod->omiBSIM4WwlcGiven ? mod->omiBSIM4Wwlc : 1e199);
    case omiBSIM4_MOD_WMIN:
      return (mod->omiBSIM4WminGiven ? mod->omiBSIM4Wmin : 1e199);
    case omiBSIM4_MOD_WMAX:
      return (mod->omiBSIM4WmaxGiven ? mod->omiBSIM4Wmax : 1e199);

    case omiBSIM4_MOD_NOIA:
      return (mod->omiBSIM4oxideTrapDensityAGiven
                  ? mod->omiBSIM4oxideTrapDensityA
                  : 1e199);
    case omiBSIM4_MOD_NOIB:
      return (mod->omiBSIM4oxideTrapDensityBGiven
                  ? mod->omiBSIM4oxideTrapDensityB
                  : 1e199);
    case omiBSIM4_MOD_NOIC:
      return (mod->omiBSIM4oxideTrapDensityCGiven
                  ? mod->omiBSIM4oxideTrapDensityC
                  : 1e199);
    case omiBSIM4_MOD_EM:
      return (mod->omiBSIM4emGiven ? mod->omiBSIM4em : 1e199);
    case omiBSIM4_MOD_EF:
      return (mod->omiBSIM4efGiven ? mod->omiBSIM4ef : 1e199);
    case omiBSIM4_MOD_AF:
      return (mod->omiBSIM4afGiven ? mod->omiBSIM4af : 1e199);
    case omiBSIM4_MOD_KF:
      return (mod->omiBSIM4kfGiven ? mod->omiBSIM4kf : 1e199);

    case omiBSIM4_MOD_VGS_MAX:
      return (mod->omiBSIM4vgsMaxGiven ? mod->omiBSIM4vgsMax : 1e199);
    case omiBSIM4_MOD_VGD_MAX:
      return (mod->omiBSIM4vgdMaxGiven ? mod->omiBSIM4vgdMax : 1e199);
    case omiBSIM4_MOD_VGB_MAX:
      return (mod->omiBSIM4vgbMaxGiven ? mod->omiBSIM4vgbMax : 1e199);
    case omiBSIM4_MOD_VDS_MAX:
      return (mod->omiBSIM4vdsMaxGiven ? mod->omiBSIM4vdsMax : 1e199);
    case omiBSIM4_MOD_VBS_MAX:
      return (mod->omiBSIM4vbsMaxGiven ? mod->omiBSIM4vbsMax : 1e199);
    case omiBSIM4_MOD_VBD_MAX:
      return (mod->omiBSIM4vbdMaxGiven ? mod->omiBSIM4vbdMax : 1e199);
    case omiBSIM4_MOD_VGSR_MAX:
      return (mod->omiBSIM4vgsrMaxGiven ? mod->omiBSIM4vgsrMax : 1e199);
    case omiBSIM4_MOD_VGDR_MAX:
      return (mod->omiBSIM4vgdrMaxGiven ? mod->omiBSIM4vgdrMax : 1e199);
    case omiBSIM4_MOD_VGBR_MAX:
      return (mod->omiBSIM4vgbrMaxGiven ? mod->omiBSIM4vgbrMax : 1e199);
    case omiBSIM4_MOD_VBSR_MAX:
      return (mod->omiBSIM4vbsrMaxGiven ? mod->omiBSIM4vbsrMax : 1e199);
    case omiBSIM4_MOD_VBDR_MAX:
      return (mod->omiBSIM4vbdrMaxGiven ? mod->omiBSIM4vbdrMax : 1e199);

    case omiBSIM4_MOD_NMOS:
      return (mod->omiBSIM4typeGiven ? (double)mod->omiBSIM4type : 1e199);

    case omiBSIM4_MOD_PMOS:
      return (mod->omiBSIM4typeGiven ? (double)mod->omiBSIM4type : 1e199);

    default:
      return 1e199;
  }
}