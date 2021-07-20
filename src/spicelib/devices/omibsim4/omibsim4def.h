/**** omiBSIM4.6.2 Released by Wenwei Yang 07/31/2008 ****/

/**********
Copyright 2006 Regents of the University of California.  All rights reserved.
File: omibsim4def.h
Author: 2000 Weidong Liu.
Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
Authors: 2008- Wenwei Yang, Ali Niknejad, Chenming Hu
Modified by Xuemei Xi, 11/15/2002.
Modified by Xuemei Xi, 05/09/2003.
Modified by Xuemei Xi, 03/04/2004.
Modified by Xuemei Xi, Mohan Dunga, 09/24/2004.
Modified by Xuemei Xi, 07/29/2005.
Modified by Mohan Dunga, 12/13/2006
Modified by Mohan Dunga, Wenwei Yang, 05/18/2007.
Modified by Wenwei Yang, 07/31/2008.
 * Modified by Tanvir Morshed, Darsen Lu 03/27/2011
**********/

#ifndef omiBSIM4
#define omiBSIM4

#include "ngspice/ifsim.h"
#include "ngspice/gendefs.h"
#include "ngspice/cktdefs.h"
#include "ngspice/complex.h"
#include "ngspice/noisedef.h"

typedef struct somiBSIM4instance
{

    struct GENinstance gen;

#define omiBSIM4modPtr(inst) ((struct somiBSIM4model *)((inst)->gen.GENmodPtr))
#define omiBSIM4nextInstance(inst) ((struct somiBSIM4instance *)((inst)->gen.GENnextInstance))
#define omiBSIM4name gen.GENname
#define omiBSIM4states gen.GENstate

    const int omiBSIM4dNode;
    const int omiBSIM4gNodeExt;
    const int omiBSIM4sNode;
    const int omiBSIM4bNode;
    int omiBSIM4dNodePrime;
    int omiBSIM4gNodePrime;
    int omiBSIM4gNodeMid;
    int omiBSIM4sNodePrime;
    int omiBSIM4bNodePrime;
    int omiBSIM4dbNode;
    int omiBSIM4sbNode;
    int omiBSIM4qNode;

    double omiBSIM4ueff;
    double omiBSIM4thetavth;
    double omiBSIM4von;
    double omiBSIM4vdsat;
    double omiBSIM4cgdo;
    double omiBSIM4qgdo;
    double omiBSIM4cgso;
    double omiBSIM4qgso;
    double omiBSIM4grbsb;
    double omiBSIM4grbdb;
    double omiBSIM4grbpb;
    double omiBSIM4grbps;
    double omiBSIM4grbpd;

    double omiBSIM4vjsmFwd;
    double omiBSIM4vjsmRev;
    double omiBSIM4vjdmFwd;
    double omiBSIM4vjdmRev;
    double omiBSIM4XExpBVS;
    double omiBSIM4XExpBVD;
    double omiBSIM4SslpFwd;
    double omiBSIM4SslpRev;
    double omiBSIM4DslpFwd;
    double omiBSIM4DslpRev;
    double omiBSIM4IVjsmFwd;
    double omiBSIM4IVjsmRev;
    double omiBSIM4IVjdmFwd;
    double omiBSIM4IVjdmRev;

    double omiBSIM4grgeltd;
    double omiBSIM4Pseff;
    double omiBSIM4Pdeff;
    double omiBSIM4Aseff;
    double omiBSIM4Adeff;

    double omiBSIM4l;
    double omiBSIM4w;
    double omiBSIM4drainArea;
    double omiBSIM4sourceArea;
    double omiBSIM4drainSquares;
    double omiBSIM4sourceSquares;
    double omiBSIM4drainPerimeter;
    double omiBSIM4sourcePerimeter;
    double omiBSIM4sourceConductance;
    double omiBSIM4drainConductance;
     /* stress effect instance param */
    double omiBSIM4sa;
    double omiBSIM4sb;
    double omiBSIM4sd;
    double omiBSIM4sca;
    double omiBSIM4scb;
    double omiBSIM4scc;
    double omiBSIM4sc;

    double omiBSIM4rbdb;
    double omiBSIM4rbsb;
    double omiBSIM4rbpb;
    double omiBSIM4rbps;
    double omiBSIM4rbpd;

    double omiBSIM4delvto;
    double omiBSIM4mulu0;
    int omiBSIM4wnflag;
    double omiBSIM4xgw;
    double omiBSIM4ngcon;

     /* added here to account stress effect instance dependence */
    double omiBSIM4u0temp;
    double omiBSIM4vsattemp;
    double omiBSIM4vth0;
    double omiBSIM4vfb;
    double omiBSIM4vfbzb;
    double omiBSIM4vtfbphi1;
    double omiBSIM4vtfbphi2;
    double omiBSIM4k2;
    double omiBSIM4vbsc;
    double omiBSIM4k2ox;
    double omiBSIM4eta0;

    double omiBSIM4icVDS;
    double omiBSIM4icVGS;
    double omiBSIM4icVBS;
    double omiBSIM4m;
    double omiBSIM4nf;
    int omiBSIM4off;
    int omiBSIM4mode;
    int omiBSIM4trnqsMod;
    int omiBSIM4acnqsMod;
    int omiBSIM4rbodyMod;
    int omiBSIM4rgateMod;
    int omiBSIM4geoMod;
    int omiBSIM4rgeoMod;
    int omiBSIM4min;


    /* OP point */
    double omiBSIM4Vgsteff;
    double omiBSIM4vgs_eff;
    double omiBSIM4vgd_eff;
    double omiBSIM4dvgs_eff_dvg;
    double omiBSIM4dvgd_eff_dvg;
    double omiBSIM4Vdseff;
    double omiBSIM4nstar;
    double omiBSIM4Abulk;
    double omiBSIM4EsatL;
    double omiBSIM4AbovVgst2Vtm;
    double omiBSIM4qinv;
    double omiBSIM4cd;
    double omiBSIM4cbs;
    double omiBSIM4cbd;
    double omiBSIM4csub;
    double omiBSIM4Igidl;
    double omiBSIM4Igisl;
    double omiBSIM4gm;
    double omiBSIM4gds;
    double omiBSIM4gmbs;
    double omiBSIM4gbd;
    double omiBSIM4gbs;
    double omiBSIM4noiGd0;   /* tnoiMod=2 (v4.7) */
    double omiBSIM4Coxeff;

    double omiBSIM4gbbs;
    double omiBSIM4gbgs;
    double omiBSIM4gbds;
    double omiBSIM4ggidld;
    double omiBSIM4ggidlg;
    double omiBSIM4ggidls;
    double omiBSIM4ggidlb;
    double omiBSIM4ggisld;
    double omiBSIM4ggislg;
    double omiBSIM4ggisls;
    double omiBSIM4ggislb;

    double omiBSIM4Igcs;
    double omiBSIM4gIgcsg;
    double omiBSIM4gIgcsd;
    double omiBSIM4gIgcss;
    double omiBSIM4gIgcsb;
    double omiBSIM4Igcd;
    double omiBSIM4gIgcdg;
    double omiBSIM4gIgcdd;
    double omiBSIM4gIgcds;
    double omiBSIM4gIgcdb;

    double omiBSIM4Igs;
    double omiBSIM4gIgsg;
    double omiBSIM4gIgss;
    double omiBSIM4Igd;
    double omiBSIM4gIgdg;
    double omiBSIM4gIgdd;

    double omiBSIM4Igb;
    double omiBSIM4gIgbg;
    double omiBSIM4gIgbd;
    double omiBSIM4gIgbs;
    double omiBSIM4gIgbb;

    double omiBSIM4grdsw;
    double omiBSIM4IdovVds;
    double omiBSIM4gcrg;
    double omiBSIM4gcrgd;
    double omiBSIM4gcrgg;
    double omiBSIM4gcrgs;
    double omiBSIM4gcrgb;

    double omiBSIM4gstot;
    double omiBSIM4gstotd;
    double omiBSIM4gstotg;
    double omiBSIM4gstots;
    double omiBSIM4gstotb;

    double omiBSIM4gdtot;
    double omiBSIM4gdtotd;
    double omiBSIM4gdtotg;
    double omiBSIM4gdtots;
    double omiBSIM4gdtotb;

    double omiBSIM4cggb;
    double omiBSIM4cgdb;
    double omiBSIM4cgsb;
    double omiBSIM4cbgb;
    double omiBSIM4cbdb;
    double omiBSIM4cbsb;
    double omiBSIM4cdgb;
    double omiBSIM4cddb;
    double omiBSIM4cdsb;
    double omiBSIM4csgb;
    double omiBSIM4csdb;
    double omiBSIM4cssb;
    double omiBSIM4cgbb;
    double omiBSIM4cdbb;
    double omiBSIM4csbb;
    double omiBSIM4cbbb;
    double omiBSIM4capbd;
    double omiBSIM4capbs;

    double omiBSIM4cqgb;
    double omiBSIM4cqdb;
    double omiBSIM4cqsb;
    double omiBSIM4cqbb;

    double omiBSIM4qgate;
    double omiBSIM4qbulk;
    double omiBSIM4qdrn;
    double omiBSIM4qsrc;
    double omiBSIM4qdef;

    double omiBSIM4qchqs;
    double omiBSIM4taunet;
    double omiBSIM4gtau;
    double omiBSIM4gtg;
    double omiBSIM4gtd;
    double omiBSIM4gts;
    double omiBSIM4gtb;
    double omiBSIM4SjctTempRevSatCur;
    double omiBSIM4DjctTempRevSatCur;
    double omiBSIM4SswTempRevSatCur;
    double omiBSIM4DswTempRevSatCur;
    double omiBSIM4SswgTempRevSatCur;
    double omiBSIM4DswgTempRevSatCur;

    struct bsim4SizeDependParam  *pParam;

    unsigned omiBSIM4lGiven :1;
    unsigned omiBSIM4wGiven :1;
    unsigned omiBSIM4mGiven :1;
    unsigned omiBSIM4nfGiven :1;
    unsigned omiBSIM4minGiven :1;
    unsigned omiBSIM4drainAreaGiven :1;
    unsigned omiBSIM4sourceAreaGiven    :1;
    unsigned omiBSIM4drainSquaresGiven  :1;
    unsigned omiBSIM4sourceSquaresGiven :1;
    unsigned omiBSIM4drainPerimeterGiven    :1;
    unsigned omiBSIM4sourcePerimeterGiven   :1;
    unsigned omiBSIM4saGiven :1;
    unsigned omiBSIM4sbGiven :1;
    unsigned omiBSIM4sdGiven :1;
    unsigned omiBSIM4scaGiven :1;
    unsigned omiBSIM4scbGiven :1;
    unsigned omiBSIM4sccGiven :1;
    unsigned omiBSIM4scGiven :1;
    unsigned omiBSIM4rbdbGiven   :1;
    unsigned omiBSIM4rbsbGiven   :1;
    unsigned omiBSIM4rbpbGiven   :1;
    unsigned omiBSIM4rbpdGiven   :1;
    unsigned omiBSIM4rbpsGiven   :1;
    unsigned omiBSIM4delvtoGiven   :1;
    unsigned omiBSIM4mulu0Given   :1;
    unsigned omiBSIM4wnflagGiven   :1;
    unsigned omiBSIM4xgwGiven   :1;
    unsigned omiBSIM4ngconGiven   :1;
    unsigned omiBSIM4icVDSGiven :1;
    unsigned omiBSIM4icVGSGiven :1;
    unsigned omiBSIM4icVBSGiven :1;
    unsigned omiBSIM4trnqsModGiven :1;
    unsigned omiBSIM4acnqsModGiven :1;
    unsigned omiBSIM4rbodyModGiven :1;
    unsigned omiBSIM4rgateModGiven :1;
    unsigned omiBSIM4geoModGiven :1;
    unsigned omiBSIM4rgeoModGiven :1;


    double *omiBSIM4DPdPtr;
    double *omiBSIM4DPdpPtr;
    double *omiBSIM4DPgpPtr;
    double *omiBSIM4DPgmPtr;
    double *omiBSIM4DPspPtr;
    double *omiBSIM4DPbpPtr;
    double *omiBSIM4DPdbPtr;

    double *omiBSIM4DdPtr;
    double *omiBSIM4DdpPtr;

    double *omiBSIM4GPdpPtr;
    double *omiBSIM4GPgpPtr;
    double *omiBSIM4GPgmPtr;
    double *omiBSIM4GPgePtr;
    double *omiBSIM4GPspPtr;
    double *omiBSIM4GPbpPtr;

    double *omiBSIM4GMdpPtr;
    double *omiBSIM4GMgpPtr;
    double *omiBSIM4GMgmPtr;
    double *omiBSIM4GMgePtr;
    double *omiBSIM4GMspPtr;
    double *omiBSIM4GMbpPtr;

    double *omiBSIM4GEdpPtr;
    double *omiBSIM4GEgpPtr;
    double *omiBSIM4GEgmPtr;
    double *omiBSIM4GEgePtr;
    double *omiBSIM4GEspPtr;
    double *omiBSIM4GEbpPtr;

    double *omiBSIM4SPdpPtr;
    double *omiBSIM4SPgpPtr;
    double *omiBSIM4SPgmPtr;
    double *omiBSIM4SPsPtr;
    double *omiBSIM4SPspPtr;
    double *omiBSIM4SPbpPtr;
    double *omiBSIM4SPsbPtr;

    double *omiBSIM4SspPtr;
    double *omiBSIM4SsPtr;

    double *omiBSIM4BPdpPtr;
    double *omiBSIM4BPgpPtr;
    double *omiBSIM4BPgmPtr;
    double *omiBSIM4BPspPtr;
    double *omiBSIM4BPdbPtr;
    double *omiBSIM4BPbPtr;
    double *omiBSIM4BPsbPtr;
    double *omiBSIM4BPbpPtr;

    double *omiBSIM4DBdpPtr;
    double *omiBSIM4DBdbPtr;
    double *omiBSIM4DBbpPtr;
    double *omiBSIM4DBbPtr;

    double *omiBSIM4SBspPtr;
    double *omiBSIM4SBbpPtr;
    double *omiBSIM4SBbPtr;
    double *omiBSIM4SBsbPtr;

    double *omiBSIM4BdbPtr;
    double *omiBSIM4BbpPtr;
    double *omiBSIM4BsbPtr;
    double *omiBSIM4BbPtr;

    double *omiBSIM4DgpPtr;
    double *omiBSIM4DspPtr;
    double *omiBSIM4DbpPtr;
    double *omiBSIM4SdpPtr;
    double *omiBSIM4SgpPtr;
    double *omiBSIM4SbpPtr;

    double *omiBSIM4QdpPtr;
    double *omiBSIM4QgpPtr;
    double *omiBSIM4QspPtr;
    double *omiBSIM4QbpPtr;
    double *omiBSIM4QqPtr;
    double *omiBSIM4DPqPtr;
    double *omiBSIM4GPqPtr;
    double *omiBSIM4SPqPtr;

#ifdef USE_OMP
    /* per instance storage of results, to update matrix at a later stge */
    double omiBSIM4rhsdPrime;
    double omiBSIM4rhsgPrime;
    double omiBSIM4rhsgExt;
    double omiBSIM4grhsMid;
    double omiBSIM4rhsbPrime;
    double omiBSIM4rhssPrime;
    double omiBSIM4rhsdb;
    double omiBSIM4rhssb;
    double omiBSIM4rhsd;
    double omiBSIM4rhss;
    double omiBSIM4rhsq;

    double omiBSIM4_1;
    double omiBSIM4_2;
    double omiBSIM4_3;
    double omiBSIM4_4;
    double omiBSIM4_5;
    double omiBSIM4_6;
    double omiBSIM4_7;
    double omiBSIM4_8;
    double omiBSIM4_9;
    double omiBSIM4_10;
    double omiBSIM4_11;
    double omiBSIM4_12;
    double omiBSIM4_13;
    double omiBSIM4_14;
    double omiBSIM4_15;
    double omiBSIM4_16;
    double omiBSIM4_17;
    double omiBSIM4_18;
    double omiBSIM4_19;
    double omiBSIM4_20;
    double omiBSIM4_21;
    double omiBSIM4_22;
    double omiBSIM4_23;
    double omiBSIM4_24;
    double omiBSIM4_25;
    double omiBSIM4_26;
    double omiBSIM4_27;
    double omiBSIM4_28;
    double omiBSIM4_29;
    double omiBSIM4_30;
    double omiBSIM4_31;
    double omiBSIM4_32;
    double omiBSIM4_33;
    double omiBSIM4_34;
    double omiBSIM4_35;
    double omiBSIM4_36;
    double omiBSIM4_37;
    double omiBSIM4_38;
    double omiBSIM4_39;
    double omiBSIM4_40;
    double omiBSIM4_41;
    double omiBSIM4_42;
    double omiBSIM4_43;
    double omiBSIM4_44;
    double omiBSIM4_45;
    double omiBSIM4_46;
    double omiBSIM4_47;
    double omiBSIM4_48;
    double omiBSIM4_49;
    double omiBSIM4_50;
    double omiBSIM4_51;
    double omiBSIM4_52;
    double omiBSIM4_53;
    double omiBSIM4_54;
    double omiBSIM4_55;
    double omiBSIM4_56;
    double omiBSIM4_57;
    double omiBSIM4_58;
    double omiBSIM4_59;
    double omiBSIM4_60;
    double omiBSIM4_61;
    double omiBSIM4_62;
    double omiBSIM4_63;
    double omiBSIM4_64;
    double omiBSIM4_65;
    double omiBSIM4_66;
    double omiBSIM4_67;
    double omiBSIM4_68;
    double omiBSIM4_69;
    double omiBSIM4_70;
    double omiBSIM4_71;
    double omiBSIM4_72;
    double omiBSIM4_73;
    double omiBSIM4_74;
    double omiBSIM4_75;
    double omiBSIM4_76;
    double omiBSIM4_77;
    double omiBSIM4_78;
    double omiBSIM4_79;
    double omiBSIM4_80;
    double omiBSIM4_81;
    double omiBSIM4_82;
    double omiBSIM4_83;
    double omiBSIM4_84;
    double omiBSIM4_85;
    double omiBSIM4_86;
    double omiBSIM4_87;
    double omiBSIM4_88;
    double omiBSIM4_89;
    double omiBSIM4_90;
    double omiBSIM4_91;
    double omiBSIM4_92;
    double omiBSIM4_93;
    double omiBSIM4_94;
    double omiBSIM4_95;
    double omiBSIM4_96;
    double omiBSIM4_97;
    double omiBSIM4_98;
    double omiBSIM4_99;
    double omiBSIM4_100;
    double omiBSIM4_101;
    double omiBSIM4_102;
    double omiBSIM4_103;
#endif

#define omiBSIM4vbd omiBSIM4states+ 0
#define omiBSIM4vbs omiBSIM4states+ 1
#define omiBSIM4vgs omiBSIM4states+ 2
#define omiBSIM4vds omiBSIM4states+ 3
#define omiBSIM4vdbs omiBSIM4states+ 4
#define omiBSIM4vdbd omiBSIM4states+ 5
#define omiBSIM4vsbs omiBSIM4states+ 6
#define omiBSIM4vges omiBSIM4states+ 7
#define omiBSIM4vgms omiBSIM4states+ 8
#define omiBSIM4vses omiBSIM4states+ 9
#define omiBSIM4vdes omiBSIM4states+ 10

#define omiBSIM4qb omiBSIM4states+ 11
#define omiBSIM4cqb omiBSIM4states+ 12
#define omiBSIM4qg omiBSIM4states+ 13
#define omiBSIM4cqg omiBSIM4states+ 14
#define omiBSIM4qd omiBSIM4states+ 15
#define omiBSIM4cqd omiBSIM4states+ 16
#define omiBSIM4qgmid omiBSIM4states+ 17
#define omiBSIM4cqgmid omiBSIM4states+ 18

#define omiBSIM4qbs  omiBSIM4states+ 19
#define omiBSIM4cqbs  omiBSIM4states+ 20
#define omiBSIM4qbd  omiBSIM4states+ 21
#define omiBSIM4cqbd  omiBSIM4states+ 22

#define omiBSIM4qcheq omiBSIM4states+ 23
#define omiBSIM4cqcheq omiBSIM4states+ 24
#define omiBSIM4qcdump omiBSIM4states+ 25
#define omiBSIM4cqcdump omiBSIM4states+ 26
#define omiBSIM4qdef omiBSIM4states+ 27
#define omiBSIM4qs omiBSIM4states+ 28

#define omiBSIM4numStates 29


/* indices to the array of omiBSIM4 NOISE SOURCES */

#define omiBSIM4RDNOIZ       0
#define omiBSIM4RSNOIZ       1
#define omiBSIM4RGNOIZ       2
#define omiBSIM4RBPSNOIZ     3
#define omiBSIM4RBPDNOIZ     4
#define omiBSIM4RBPBNOIZ     5
#define omiBSIM4RBSBNOIZ     6
#define omiBSIM4RBDBNOIZ     7
#define omiBSIM4IDNOIZ       8
#define omiBSIM4FLNOIZ       9
#define omiBSIM4IGSNOIZ      10
#define omiBSIM4IGDNOIZ      11
#define omiBSIM4IGBNOIZ      12
#define omiBSIM4CORLNOIZ     13
#define omiBSIM4TOTNOIZ      14

#define omiBSIM4NSRCS        15  /* Number of omiBSIM4 noise sources */

#ifndef NONOISE
    double omiBSIM4nVar[NSTATVARS][omiBSIM4NSRCS];
#else /* NONOISE */
        double **omiBSIM4nVar;
#endif /* NONOISE */

} omiBSIM4instance ;

struct bsim4SizeDependParam
{
    double Width;
    double Length;
    double NFinger;

    double omiBSIM4cdsc;
    double omiBSIM4cdscb;
    double omiBSIM4cdscd;
    double omiBSIM4cit;
    double omiBSIM4nfactor;
    double omiBSIM4xj;
    double omiBSIM4vsat;
    double omiBSIM4at;
    double omiBSIM4a0;
    double omiBSIM4ags;
    double omiBSIM4a1;
    double omiBSIM4a2;
    double omiBSIM4keta;
    double omiBSIM4nsub;
    double omiBSIM4ndep;
    double omiBSIM4nsd;
    double omiBSIM4phin;
    double omiBSIM4ngate;
    double omiBSIM4gamma1;
    double omiBSIM4gamma2;
    double omiBSIM4vbx;
    double omiBSIM4vbi;
    double omiBSIM4vbm;
    double omiBSIM4xt;
    double omiBSIM4phi;
    double omiBSIM4litl;
    double omiBSIM4k1;
    double omiBSIM4kt1;
    double omiBSIM4kt1l;
    double omiBSIM4kt2;
    double omiBSIM4k2;
    double omiBSIM4k3;
    double omiBSIM4k3b;
    double omiBSIM4w0;
    double omiBSIM4dvtp0;
    double omiBSIM4dvtp1;
    double omiBSIM4dvtp2;	/* New DIBL/Rout */
    double omiBSIM4dvtp3;
    double omiBSIM4dvtp4;
    double omiBSIM4dvtp5;
    double omiBSIM4lpe0;
    double omiBSIM4lpeb;
    double omiBSIM4dvt0;
    double omiBSIM4dvt1;
    double omiBSIM4dvt2;
    double omiBSIM4dvt0w;
    double omiBSIM4dvt1w;
    double omiBSIM4dvt2w;
    double omiBSIM4drout;
    double omiBSIM4dsub;
    double omiBSIM4vth0;
    double omiBSIM4ua;
    double omiBSIM4ua1;
    double omiBSIM4ub;
    double omiBSIM4ub1;
    double omiBSIM4uc;
    double omiBSIM4uc1;
    double omiBSIM4ud;
    double omiBSIM4ud1;
    double omiBSIM4up;
    double omiBSIM4lp;
    double omiBSIM4u0;
    double omiBSIM4eu;
  	double omiBSIM4ucs;
    double omiBSIM4ute;
	  double omiBSIM4ucste;
    double omiBSIM4voff;
    double omiBSIM4tvoff;
    double omiBSIM4tnfactor; 	/* v4.7 Temp dep of leakage current */
    double omiBSIM4teta0;   	/* v4.7 temp dep of leakage current */
    double omiBSIM4tvoffcv;	/* v4.7 temp dep of leakage current */
    double omiBSIM4minv;
    double omiBSIM4minvcv;
    double omiBSIM4vfb;
    double omiBSIM4delta;
    double omiBSIM4rdsw;
    double omiBSIM4rds0;
    double omiBSIM4rs0;
    double omiBSIM4rd0;
    double omiBSIM4rsw;
    double omiBSIM4rdw;
    double omiBSIM4prwg;
    double omiBSIM4prwb;
    double omiBSIM4prt;
    double omiBSIM4eta0;
    double omiBSIM4etab;
    double omiBSIM4pclm;
    double omiBSIM4pdibl1;
    double omiBSIM4pdibl2;
    double omiBSIM4pdiblb;
    double omiBSIM4fprout;
    double omiBSIM4pdits;
    double omiBSIM4pditsd;
    double omiBSIM4pscbe1;
    double omiBSIM4pscbe2;
    double omiBSIM4pvag;
    double omiBSIM4wr;
    double omiBSIM4dwg;
    double omiBSIM4dwb;
    double omiBSIM4b0;
    double omiBSIM4b1;
    double omiBSIM4alpha0;
    double omiBSIM4alpha1;
    double omiBSIM4beta0;
    double omiBSIM4agidl;
    double omiBSIM4bgidl;
    double omiBSIM4cgidl;
    double omiBSIM4egidl;
    double omiBSIM4fgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4kgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4rgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4agisl;
    double omiBSIM4bgisl;
    double omiBSIM4cgisl;
    double omiBSIM4egisl;
    double omiBSIM4fgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4kgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4rgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4aigc;
    double omiBSIM4bigc;
    double omiBSIM4cigc;
    double omiBSIM4aigs;
    double omiBSIM4bigs;
    double omiBSIM4cigs;
    double omiBSIM4aigd;
    double omiBSIM4bigd;
    double omiBSIM4cigd;
    double omiBSIM4aigbacc;
    double omiBSIM4bigbacc;
    double omiBSIM4cigbacc;
    double omiBSIM4aigbinv;
    double omiBSIM4bigbinv;
    double omiBSIM4cigbinv;
    double omiBSIM4nigc;
    double omiBSIM4nigbacc;
    double omiBSIM4nigbinv;
    double omiBSIM4ntox;
    double omiBSIM4eigbinv;
    double omiBSIM4pigcd;
    double omiBSIM4poxedge;
    double omiBSIM4xrcrg1;
    double omiBSIM4xrcrg2;
    double omiBSIM4lambda; /* overshoot */
    double omiBSIM4vtl; /* thermal velocity limit */
    double omiBSIM4xn; /* back scattering parameter */
    double omiBSIM4lc; /* back scattering parameter */
    double omiBSIM4tfactor;  /* ballistic transportation factor  */
    double omiBSIM4vfbsdoff;  /* S/D flatband offset voltage  */
    double omiBSIM4tvfbsdoff;

/* added for stress effect */
    double omiBSIM4ku0;
    double omiBSIM4kvth0;
    double omiBSIM4ku0temp;
    double omiBSIM4rho_ref;
    double omiBSIM4inv_od_ref;
/* added for well proximity effect */
    double omiBSIM4kvth0we;
    double omiBSIM4k2we;
    double omiBSIM4ku0we;

    /* CV model */
    double omiBSIM4cgsl;
    double omiBSIM4cgdl;
    double omiBSIM4ckappas;
    double omiBSIM4ckappad;
    double omiBSIM4cf;
    double omiBSIM4clc;
    double omiBSIM4cle;
    double omiBSIM4vfbcv;
    double omiBSIM4noff;
    double omiBSIM4voffcv;
    double omiBSIM4acde;
    double omiBSIM4moin;

/* Pre-calculated constants */

    double omiBSIM4dw;
    double omiBSIM4dl;
    double omiBSIM4leff;
    double omiBSIM4weff;

    double omiBSIM4dwc;
    double omiBSIM4dlc;
    double omiBSIM4dwj;
    double omiBSIM4leffCV;
    double omiBSIM4weffCV;
    double omiBSIM4weffCJ;
    double omiBSIM4abulkCVfactor;
    double omiBSIM4cgso;
    double omiBSIM4cgdo;
    double omiBSIM4cgbo;

    double omiBSIM4u0temp;
    double omiBSIM4vsattemp;
    double omiBSIM4sqrtPhi;
    double omiBSIM4phis3;
    double omiBSIM4Xdep0;
    double omiBSIM4sqrtXdep0;
    double omiBSIM4theta0vb0;
    double omiBSIM4thetaRout;
    double omiBSIM4mstar;
	  double omiBSIM4VgsteffVth;
    double omiBSIM4mstarcv;
    double omiBSIM4voffcbn;
    double omiBSIM4voffcbncv;
    double omiBSIM4rdswmin;
    double omiBSIM4rdwmin;
    double omiBSIM4rswmin;
    double omiBSIM4vfbsd;

    double omiBSIM4cof1;
    double omiBSIM4cof2;
    double omiBSIM4cof3;
    double omiBSIM4cof4;
    double omiBSIM4cdep0;
    double omiBSIM4ToxRatio;
    double omiBSIM4Aechvb;
    double omiBSIM4Bechvb;
    double omiBSIM4ToxRatioEdge;
    double omiBSIM4AechvbEdgeS;
    double omiBSIM4AechvbEdgeD;
    double omiBSIM4BechvbEdge;
    double omiBSIM4ldeb;
    double omiBSIM4k1ox;
    double omiBSIM4k2ox;
    double omiBSIM4vfbzbfactor;
    double omiBSIM4dvtp2factor; /* v4.7 */
    struct bsim4SizeDependParam  *pNext;
};


typedef struct somiBSIM4model
{

    struct GENmodel gen;

#define omiBSIM4modType gen.GENmodType
#define omiBSIM4nextModel(inst) ((struct somiBSIM4model *)((inst)->gen.GENnextModel))
#define omiBSIM4instances(inst) ((omiBSIM4instance *)((inst)->gen.GENinstances))
#define omiBSIM4modName gen.GENmodName

    int omiBSIM4type;

    int    omiBSIM4mobMod;
    int    omiBSIM4cvchargeMod;
    int    omiBSIM4capMod;
    int    omiBSIM4dioMod;
    int    omiBSIM4trnqsMod;
    int    omiBSIM4acnqsMod;
    int    omiBSIM4fnoiMod;
    int    omiBSIM4tnoiMod;
    int    omiBSIM4rdsMod;
    int    omiBSIM4rbodyMod;
    int    omiBSIM4rgateMod;
    int    omiBSIM4perMod;
    int    omiBSIM4geoMod;
    int    omiBSIM4rgeoMod;
    int    omiBSIM4mtrlMod;
    int    omiBSIM4mtrlCompatMod; /* v4.7 */
    int    omiBSIM4gidlMod; /* v4.7 New GIDL/GISL */
    int    omiBSIM4igcMod;
    int    omiBSIM4igbMod;
    int    omiBSIM4tempMod;
    int    omiBSIM4binUnit;
    int    omiBSIM4paramChk;
    char   *omiBSIM4version;
    double omiBSIM4eot;
    double omiBSIM4vddeot;
  	double omiBSIM4tempeot;
  	double omiBSIM4leffeot;
  	double omiBSIM4weffeot;
    double omiBSIM4ados;
    double omiBSIM4bdos;
    double omiBSIM4toxe;
    double omiBSIM4toxp;
    double omiBSIM4toxm;
    double omiBSIM4dtox;
    double omiBSIM4epsrox;
    double omiBSIM4cdsc;
    double omiBSIM4cdscb;
    double omiBSIM4cdscd;
    double omiBSIM4cit;
    double omiBSIM4nfactor;
    double omiBSIM4xj;
    double omiBSIM4vsat;
    double omiBSIM4at;
    double omiBSIM4a0;
    double omiBSIM4ags;
    double omiBSIM4a1;
    double omiBSIM4a2;
    double omiBSIM4keta;
    double omiBSIM4nsub;
    double omiBSIM4phig;
    double omiBSIM4epsrgate;
    double omiBSIM4easub;
    double omiBSIM4epsrsub;
    double omiBSIM4ni0sub;
    double omiBSIM4bg0sub;
    double omiBSIM4tbgasub;
    double omiBSIM4tbgbsub;
    double omiBSIM4ndep;
    double omiBSIM4nsd;
    double omiBSIM4phin;
    double omiBSIM4ngate;
    double omiBSIM4gamma1;
    double omiBSIM4gamma2;
    double omiBSIM4vbx;
    double omiBSIM4vbm;
    double omiBSIM4xt;
    double omiBSIM4k1;
    double omiBSIM4kt1;
    double omiBSIM4kt1l;
    double omiBSIM4kt2;
    double omiBSIM4k2;
    double omiBSIM4k3;
    double omiBSIM4k3b;
    double omiBSIM4w0;
    double omiBSIM4dvtp0;
    double omiBSIM4dvtp1;
    double omiBSIM4dvtp2;	/* New DIBL/Rout */
    double omiBSIM4dvtp3;
    double omiBSIM4dvtp4;
    double omiBSIM4dvtp5;
    double omiBSIM4lpe0;
    double omiBSIM4lpeb;
    double omiBSIM4dvt0;
    double omiBSIM4dvt1;
    double omiBSIM4dvt2;
    double omiBSIM4dvt0w;
    double omiBSIM4dvt1w;
    double omiBSIM4dvt2w;
    double omiBSIM4drout;
    double omiBSIM4dsub;
    double omiBSIM4vth0;
    double omiBSIM4eu;
  	double omiBSIM4ucs;
    double omiBSIM4ua;
    double omiBSIM4ua1;
    double omiBSIM4ub;
    double omiBSIM4ub1;
    double omiBSIM4uc;
    double omiBSIM4uc1;
    double omiBSIM4ud;
    double omiBSIM4ud1;
    double omiBSIM4up;
    double omiBSIM4lp;
    double omiBSIM4u0;
    double omiBSIM4ute;
  	double omiBSIM4ucste;
    double omiBSIM4voff;
    double omiBSIM4tvoff;
    double omiBSIM4tnfactor; 	/* v4.7 Temp dep of leakage current */
    double omiBSIM4teta0;   	/* v4.7 temp dep of leakage current */
    double omiBSIM4tvoffcv;	/* v4.7 temp dep of leakage current */
    double omiBSIM4minv;
    double omiBSIM4minvcv;
    double omiBSIM4voffl;
    double omiBSIM4voffcvl;
    double omiBSIM4delta;
    double omiBSIM4rdsw;
    double omiBSIM4rdswmin;
    double omiBSIM4rdwmin;
    double omiBSIM4rswmin;
    double omiBSIM4rsw;
    double omiBSIM4rdw;
    double omiBSIM4prwg;
    double omiBSIM4prwb;
    double omiBSIM4prt;
    double omiBSIM4eta0;
    double omiBSIM4etab;
    double omiBSIM4pclm;
    double omiBSIM4pdibl1;
    double omiBSIM4pdibl2;
    double omiBSIM4pdiblb;
    double omiBSIM4fprout;
    double omiBSIM4pdits;
    double omiBSIM4pditsd;
    double omiBSIM4pditsl;
    double omiBSIM4pscbe1;
    double omiBSIM4pscbe2;
    double omiBSIM4pvag;
    double omiBSIM4wr;
    double omiBSIM4dwg;
    double omiBSIM4dwb;
    double omiBSIM4b0;
    double omiBSIM4b1;
    double omiBSIM4alpha0;
    double omiBSIM4alpha1;
    double omiBSIM4beta0;
    double omiBSIM4agidl;
    double omiBSIM4bgidl;
    double omiBSIM4cgidl;
    double omiBSIM4egidl;
    double omiBSIM4fgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4kgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4rgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4agisl;
    double omiBSIM4bgisl;
    double omiBSIM4cgisl;
    double omiBSIM4egisl;
    double omiBSIM4fgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4kgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4rgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4aigc;
    double omiBSIM4bigc;
    double omiBSIM4cigc;
    double omiBSIM4aigsd;
    double omiBSIM4bigsd;
    double omiBSIM4cigsd;
    double omiBSIM4aigs;
    double omiBSIM4bigs;
    double omiBSIM4cigs;
    double omiBSIM4aigd;
    double omiBSIM4bigd;
    double omiBSIM4cigd;
    double omiBSIM4aigbacc;
    double omiBSIM4bigbacc;
    double omiBSIM4cigbacc;
    double omiBSIM4aigbinv;
    double omiBSIM4bigbinv;
    double omiBSIM4cigbinv;
    double omiBSIM4nigc;
    double omiBSIM4nigbacc;
    double omiBSIM4nigbinv;
    double omiBSIM4ntox;
    double omiBSIM4eigbinv;
    double omiBSIM4pigcd;
    double omiBSIM4poxedge;
    double omiBSIM4toxref;
    double omiBSIM4ijthdfwd;
    double omiBSIM4ijthsfwd;
    double omiBSIM4ijthdrev;
    double omiBSIM4ijthsrev;
    double omiBSIM4xjbvd;
    double omiBSIM4xjbvs;
    double omiBSIM4bvd;
    double omiBSIM4bvs;

    double omiBSIM4jtss;
    double omiBSIM4jtsd;
    double omiBSIM4jtssws;
    double omiBSIM4jtsswd;
    double omiBSIM4jtsswgs;
    double omiBSIM4jtsswgd;
    double omiBSIM4jtweff;
    double omiBSIM4njts;
    double omiBSIM4njtssw;
    double omiBSIM4njtsswg;
    double omiBSIM4njtsd;
    double omiBSIM4njtsswd;
    double omiBSIM4njtsswgd;
    double omiBSIM4xtss;
    double omiBSIM4xtsd;
    double omiBSIM4xtssws;
    double omiBSIM4xtsswd;
    double omiBSIM4xtsswgs;
    double omiBSIM4xtsswgd;
    double omiBSIM4tnjts;
    double omiBSIM4tnjtssw;
    double omiBSIM4tnjtsswg;
    double omiBSIM4tnjtsd;
    double omiBSIM4tnjtsswd;
    double omiBSIM4tnjtsswgd;
    double omiBSIM4vtss;
    double omiBSIM4vtsd;
    double omiBSIM4vtssws;
    double omiBSIM4vtsswd;
    double omiBSIM4vtsswgs;
    double omiBSIM4vtsswgd;

    double omiBSIM4xrcrg1;
    double omiBSIM4xrcrg2;
    double omiBSIM4lambda;
    double omiBSIM4vtl;
    double omiBSIM4lc;
    double omiBSIM4xn;
    double omiBSIM4vfbsdoff;  /* S/D flatband offset voltage  */
    double omiBSIM4lintnoi;  /* lint offset for noise calculation  */
    double omiBSIM4tvfbsdoff;

    double omiBSIM4vfb;
    double omiBSIM4gbmin;
    double omiBSIM4rbdb;
    double omiBSIM4rbsb;
    double omiBSIM4rbpb;
    double omiBSIM4rbps;
    double omiBSIM4rbpd;

    double omiBSIM4rbps0;
    double omiBSIM4rbpsl;
    double omiBSIM4rbpsw;
    double omiBSIM4rbpsnf;

    double omiBSIM4rbpd0;
    double omiBSIM4rbpdl;
    double omiBSIM4rbpdw;
    double omiBSIM4rbpdnf;

    double omiBSIM4rbpbx0;
    double omiBSIM4rbpbxl;
    double omiBSIM4rbpbxw;
    double omiBSIM4rbpbxnf;
    double omiBSIM4rbpby0;
    double omiBSIM4rbpbyl;
    double omiBSIM4rbpbyw;
    double omiBSIM4rbpbynf;

    double omiBSIM4rbsbx0;
    double omiBSIM4rbsby0;
    double omiBSIM4rbdbx0;
    double omiBSIM4rbdby0;

    double omiBSIM4rbsdbxl;
    double omiBSIM4rbsdbxw;
    double omiBSIM4rbsdbxnf;
    double omiBSIM4rbsdbyl;
    double omiBSIM4rbsdbyw;
    double omiBSIM4rbsdbynf;

    double omiBSIM4tnoia;
    double omiBSIM4tnoib;
    double omiBSIM4tnoic;
    double omiBSIM4rnoia;
    double omiBSIM4rnoib;
    double omiBSIM4rnoic;
    double omiBSIM4ntnoi;

    /* CV model and Parasitics */
    double omiBSIM4cgsl;
    double omiBSIM4cgdl;
    double omiBSIM4ckappas;
    double omiBSIM4ckappad;
    double omiBSIM4cf;
    double omiBSIM4vfbcv;
    double omiBSIM4clc;
    double omiBSIM4cle;
    double omiBSIM4dwc;
    double omiBSIM4dlc;
    double omiBSIM4xw;
    double omiBSIM4xl;
    double omiBSIM4dlcig;
    double omiBSIM4dlcigd;
    double omiBSIM4dwj;
    double omiBSIM4noff;
    double omiBSIM4voffcv;
    double omiBSIM4acde;
    double omiBSIM4moin;
    double omiBSIM4tcj;
    double omiBSIM4tcjsw;
    double omiBSIM4tcjswg;
    double omiBSIM4tpb;
    double omiBSIM4tpbsw;
    double omiBSIM4tpbswg;
    double omiBSIM4dmcg;
    double omiBSIM4dmci;
    double omiBSIM4dmdg;
    double omiBSIM4dmcgt;
    double omiBSIM4xgw;
    double omiBSIM4xgl;
    double omiBSIM4rshg;
    double omiBSIM4ngcon;

    /* Length Dependence */
    double omiBSIM4lcdsc;
    double omiBSIM4lcdscb;
    double omiBSIM4lcdscd;
    double omiBSIM4lcit;
    double omiBSIM4lnfactor;
    double omiBSIM4lxj;
    double omiBSIM4lvsat;
    double omiBSIM4lat;
    double omiBSIM4la0;
    double omiBSIM4lags;
    double omiBSIM4la1;
    double omiBSIM4la2;
    double omiBSIM4lketa;
    double omiBSIM4lnsub;
    double omiBSIM4lndep;
    double omiBSIM4lnsd;
    double omiBSIM4lphin;
    double omiBSIM4lngate;
    double omiBSIM4lgamma1;
    double omiBSIM4lgamma2;
    double omiBSIM4lvbx;
    double omiBSIM4lvbm;
    double omiBSIM4lxt;
    double omiBSIM4lk1;
    double omiBSIM4lkt1;
    double omiBSIM4lkt1l;
    double omiBSIM4lkt2;
    double omiBSIM4lk2;
    double omiBSIM4lk3;
    double omiBSIM4lk3b;
    double omiBSIM4lw0;
    double omiBSIM4ldvtp0;
    double omiBSIM4ldvtp1;
    double omiBSIM4ldvtp2;        /* New DIBL/Rout */
    double omiBSIM4ldvtp3;
    double omiBSIM4ldvtp4;
    double omiBSIM4ldvtp5;
    double omiBSIM4llpe0;
    double omiBSIM4llpeb;
    double omiBSIM4ldvt0;
    double omiBSIM4ldvt1;
    double omiBSIM4ldvt2;
    double omiBSIM4ldvt0w;
    double omiBSIM4ldvt1w;
    double omiBSIM4ldvt2w;
    double omiBSIM4ldrout;
    double omiBSIM4ldsub;
    double omiBSIM4lvth0;
    double omiBSIM4lua;
    double omiBSIM4lua1;
    double omiBSIM4lub;
    double omiBSIM4lub1;
    double omiBSIM4luc;
    double omiBSIM4luc1;
    double omiBSIM4lud;
    double omiBSIM4lud1;
    double omiBSIM4lup;
    double omiBSIM4llp;
    double omiBSIM4lu0;
    double omiBSIM4leu;
    double omiBSIM4lucs;
    double omiBSIM4lute;
    double omiBSIM4lucste;
    double omiBSIM4lvoff;
    double omiBSIM4ltvoff;
    double omiBSIM4ltnfactor;         /* v4.7 Temp dep of leakage current */
    double omiBSIM4lteta0;           /* v4.7 temp dep of leakage current */
    double omiBSIM4ltvoffcv;        /* v4.7 temp dep of leakage current */
    double omiBSIM4lminv;
    double omiBSIM4lminvcv;
    double omiBSIM4ldelta;
    double omiBSIM4lrdsw;
    double omiBSIM4lrsw;
    double omiBSIM4lrdw;
    double omiBSIM4lprwg;
    double omiBSIM4lprwb;
    double omiBSIM4lprt;
    double omiBSIM4leta0;
    double omiBSIM4letab;
    double omiBSIM4lpclm;
    double omiBSIM4lpdibl1;
    double omiBSIM4lpdibl2;
    double omiBSIM4lpdiblb;
    double omiBSIM4lfprout;
    double omiBSIM4lpdits;
    double omiBSIM4lpditsd;
    double omiBSIM4lpscbe1;
    double omiBSIM4lpscbe2;
    double omiBSIM4lpvag;
    double omiBSIM4lwr;
    double omiBSIM4ldwg;
    double omiBSIM4ldwb;
    double omiBSIM4lb0;
    double omiBSIM4lb1;
    double omiBSIM4lalpha0;
    double omiBSIM4lalpha1;
    double omiBSIM4lbeta0;
    double omiBSIM4lvfb;
    double omiBSIM4lagidl;
    double omiBSIM4lbgidl;
    double omiBSIM4lcgidl;
    double omiBSIM4legidl;
    double omiBSIM4lfgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4lkgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4lrgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4lagisl;
    double omiBSIM4lbgisl;
    double omiBSIM4lcgisl;
    double omiBSIM4legisl;
    double omiBSIM4lfgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4lkgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4lrgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4laigc;
    double omiBSIM4lbigc;
    double omiBSIM4lcigc;
    double omiBSIM4laigsd;
    double omiBSIM4lbigsd;
    double omiBSIM4lcigsd;
    double omiBSIM4laigs;
    double omiBSIM4lbigs;
    double omiBSIM4lcigs;
    double omiBSIM4laigd;
    double omiBSIM4lbigd;
    double omiBSIM4lcigd;
    double omiBSIM4laigbacc;
    double omiBSIM4lbigbacc;
    double omiBSIM4lcigbacc;
    double omiBSIM4laigbinv;
    double omiBSIM4lbigbinv;
    double omiBSIM4lcigbinv;
    double omiBSIM4lnigc;
    double omiBSIM4lnigbacc;
    double omiBSIM4lnigbinv;
    double omiBSIM4lntox;
    double omiBSIM4leigbinv;
    double omiBSIM4lpigcd;
    double omiBSIM4lpoxedge;
    double omiBSIM4lxrcrg1;
    double omiBSIM4lxrcrg2;
    double omiBSIM4llambda;
    double omiBSIM4lvtl;
    double omiBSIM4lxn;
    double omiBSIM4lvfbsdoff;
    double omiBSIM4ltvfbsdoff;

    /* CV model */
    double omiBSIM4lcgsl;
    double omiBSIM4lcgdl;
    double omiBSIM4lckappas;
    double omiBSIM4lckappad;
    double omiBSIM4lcf;
    double omiBSIM4lclc;
    double omiBSIM4lcle;
    double omiBSIM4lvfbcv;
    double omiBSIM4lnoff;
    double omiBSIM4lvoffcv;
    double omiBSIM4lacde;
    double omiBSIM4lmoin;

    /* Width Dependence */
    double omiBSIM4wcdsc;
    double omiBSIM4wcdscb;
    double omiBSIM4wcdscd;
    double omiBSIM4wcit;
    double omiBSIM4wnfactor;
    double omiBSIM4wxj;
    double omiBSIM4wvsat;
    double omiBSIM4wat;
    double omiBSIM4wa0;
    double omiBSIM4wags;
    double omiBSIM4wa1;
    double omiBSIM4wa2;
    double omiBSIM4wketa;
    double omiBSIM4wnsub;
    double omiBSIM4wndep;
    double omiBSIM4wnsd;
    double omiBSIM4wphin;
    double omiBSIM4wngate;
    double omiBSIM4wgamma1;
    double omiBSIM4wgamma2;
    double omiBSIM4wvbx;
    double omiBSIM4wvbm;
    double omiBSIM4wxt;
    double omiBSIM4wk1;
    double omiBSIM4wkt1;
    double omiBSIM4wkt1l;
    double omiBSIM4wkt2;
    double omiBSIM4wk2;
    double omiBSIM4wk3;
    double omiBSIM4wk3b;
    double omiBSIM4ww0;
    double omiBSIM4wdvtp0;
    double omiBSIM4wdvtp1;
    double omiBSIM4wdvtp2;        /* New DIBL/Rout */
    double omiBSIM4wdvtp3;
    double omiBSIM4wdvtp4;
    double omiBSIM4wdvtp5;
    double omiBSIM4wlpe0;
    double omiBSIM4wlpeb;
    double omiBSIM4wdvt0;
    double omiBSIM4wdvt1;
    double omiBSIM4wdvt2;
    double omiBSIM4wdvt0w;
    double omiBSIM4wdvt1w;
    double omiBSIM4wdvt2w;
    double omiBSIM4wdrout;
    double omiBSIM4wdsub;
    double omiBSIM4wvth0;
    double omiBSIM4wua;
    double omiBSIM4wua1;
    double omiBSIM4wub;
    double omiBSIM4wub1;
    double omiBSIM4wuc;
    double omiBSIM4wuc1;
    double omiBSIM4wud;
    double omiBSIM4wud1;
    double omiBSIM4wup;
    double omiBSIM4wlp;
    double omiBSIM4wu0;
    double omiBSIM4weu;
    double omiBSIM4wucs;
    double omiBSIM4wute;
    double omiBSIM4wucste;
    double omiBSIM4wvoff;
    double omiBSIM4wtvoff;
    double omiBSIM4wtnfactor;         /* v4.7 Temp dep of leakage current */
    double omiBSIM4wteta0;           /* v4.7 temp dep of leakage current */
    double omiBSIM4wtvoffcv;        /* v4.7 temp dep of leakage current */
    double omiBSIM4wminv;
    double omiBSIM4wminvcv;
    double omiBSIM4wdelta;
    double omiBSIM4wrdsw;
    double omiBSIM4wrsw;
    double omiBSIM4wrdw;
    double omiBSIM4wprwg;
    double omiBSIM4wprwb;
    double omiBSIM4wprt;
    double omiBSIM4weta0;
    double omiBSIM4wetab;
    double omiBSIM4wpclm;
    double omiBSIM4wpdibl1;
    double omiBSIM4wpdibl2;
    double omiBSIM4wpdiblb;
    double omiBSIM4wfprout;
    double omiBSIM4wpdits;
    double omiBSIM4wpditsd;
    double omiBSIM4wpscbe1;
    double omiBSIM4wpscbe2;
    double omiBSIM4wpvag;
    double omiBSIM4wwr;
    double omiBSIM4wdwg;
    double omiBSIM4wdwb;
    double omiBSIM4wb0;
    double omiBSIM4wb1;
    double omiBSIM4walpha0;
    double omiBSIM4walpha1;
    double omiBSIM4wbeta0;
    double omiBSIM4wvfb;
    double omiBSIM4wagidl;
    double omiBSIM4wbgidl;
    double omiBSIM4wcgidl;
    double omiBSIM4wegidl;
    double omiBSIM4wfgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4wkgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4wrgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4wagisl;
    double omiBSIM4wbgisl;
    double omiBSIM4wcgisl;
    double omiBSIM4wegisl;
    double omiBSIM4wfgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4wkgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4wrgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4waigc;
    double omiBSIM4wbigc;
    double omiBSIM4wcigc;
    double omiBSIM4waigsd;
    double omiBSIM4wbigsd;
    double omiBSIM4wcigsd;
    double omiBSIM4waigs;
    double omiBSIM4wbigs;
    double omiBSIM4wcigs;
    double omiBSIM4waigd;
    double omiBSIM4wbigd;
    double omiBSIM4wcigd;
    double omiBSIM4waigbacc;
    double omiBSIM4wbigbacc;
    double omiBSIM4wcigbacc;
    double omiBSIM4waigbinv;
    double omiBSIM4wbigbinv;
    double omiBSIM4wcigbinv;
    double omiBSIM4wnigc;
    double omiBSIM4wnigbacc;
    double omiBSIM4wnigbinv;
    double omiBSIM4wntox;
    double omiBSIM4weigbinv;
    double omiBSIM4wpigcd;
    double omiBSIM4wpoxedge;
    double omiBSIM4wxrcrg1;
    double omiBSIM4wxrcrg2;
    double omiBSIM4wlambda;
    double omiBSIM4wvtl;
    double omiBSIM4wxn;
    double omiBSIM4wvfbsdoff;
    double omiBSIM4wtvfbsdoff;

    /* CV model */
    double omiBSIM4wcgsl;
    double omiBSIM4wcgdl;
    double omiBSIM4wckappas;
    double omiBSIM4wckappad;
    double omiBSIM4wcf;
    double omiBSIM4wclc;
    double omiBSIM4wcle;
    double omiBSIM4wvfbcv;
    double omiBSIM4wnoff;
    double omiBSIM4wvoffcv;
    double omiBSIM4wacde;
    double omiBSIM4wmoin;

    /* Cross-term Dependence */
    double omiBSIM4pcdsc;
    double omiBSIM4pcdscb;
    double omiBSIM4pcdscd;
    double omiBSIM4pcit;
    double omiBSIM4pnfactor;
    double omiBSIM4pxj;
    double omiBSIM4pvsat;
    double omiBSIM4pat;
    double omiBSIM4pa0;
    double omiBSIM4pags;
    double omiBSIM4pa1;
    double omiBSIM4pa2;
    double omiBSIM4pketa;
    double omiBSIM4pnsub;
    double omiBSIM4pndep;
    double omiBSIM4pnsd;
    double omiBSIM4pphin;
    double omiBSIM4pngate;
    double omiBSIM4pgamma1;
    double omiBSIM4pgamma2;
    double omiBSIM4pvbx;
    double omiBSIM4pvbm;
    double omiBSIM4pxt;
    double omiBSIM4pk1;
    double omiBSIM4pkt1;
    double omiBSIM4pkt1l;
    double omiBSIM4pkt2;
    double omiBSIM4pk2;
    double omiBSIM4pk3;
    double omiBSIM4pk3b;
    double omiBSIM4pw0;
    double omiBSIM4pdvtp0;
    double omiBSIM4pdvtp1;
    double omiBSIM4pdvtp2;        /* New DIBL/Rout */
    double omiBSIM4pdvtp3;
    double omiBSIM4pdvtp4;
    double omiBSIM4pdvtp5;
    double omiBSIM4plpe0;
    double omiBSIM4plpeb;
    double omiBSIM4pdvt0;
    double omiBSIM4pdvt1;
    double omiBSIM4pdvt2;
    double omiBSIM4pdvt0w;
    double omiBSIM4pdvt1w;
    double omiBSIM4pdvt2w;
    double omiBSIM4pdrout;
    double omiBSIM4pdsub;
    double omiBSIM4pvth0;
    double omiBSIM4pua;
    double omiBSIM4pua1;
    double omiBSIM4pub;
    double omiBSIM4pub1;
    double omiBSIM4puc;
    double omiBSIM4puc1;
    double omiBSIM4pud;
    double omiBSIM4pud1;
    double omiBSIM4pup;
    double omiBSIM4plp;
    double omiBSIM4pu0;
    double omiBSIM4peu;
    double omiBSIM4pucs;
    double omiBSIM4pute;
    double omiBSIM4pucste;
    double omiBSIM4pvoff;
    double omiBSIM4ptvoff;
    double omiBSIM4ptnfactor;         /* v4.7 Temp dep of leakage current */
    double omiBSIM4pteta0;           /* v4.7 temp dep of leakage current */
    double omiBSIM4ptvoffcv;        /* v4.7 temp dep of leakage current */
    double omiBSIM4pminv;
    double omiBSIM4pminvcv;
    double omiBSIM4pdelta;
    double omiBSIM4prdsw;
    double omiBSIM4prsw;
    double omiBSIM4prdw;
    double omiBSIM4pprwg;
    double omiBSIM4pprwb;
    double omiBSIM4pprt;
    double omiBSIM4peta0;
    double omiBSIM4petab;
    double omiBSIM4ppclm;
    double omiBSIM4ppdibl1;
    double omiBSIM4ppdibl2;
    double omiBSIM4ppdiblb;
    double omiBSIM4pfprout;
    double omiBSIM4ppdits;
    double omiBSIM4ppditsd;
    double omiBSIM4ppscbe1;
    double omiBSIM4ppscbe2;
    double omiBSIM4ppvag;
    double omiBSIM4pwr;
    double omiBSIM4pdwg;
    double omiBSIM4pdwb;
    double omiBSIM4pb0;
    double omiBSIM4pb1;
    double omiBSIM4palpha0;
    double omiBSIM4palpha1;
    double omiBSIM4pbeta0;
    double omiBSIM4pvfb;
    double omiBSIM4pagidl;
    double omiBSIM4pbgidl;
    double omiBSIM4pcgidl;
    double omiBSIM4pegidl;
    double omiBSIM4pfgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4pkgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4prgidl; /* v4.7 New GIDL/GISL */
    double omiBSIM4pagisl;
    double omiBSIM4pbgisl;
    double omiBSIM4pcgisl;
    double omiBSIM4pegisl;
    double omiBSIM4pfgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4pkgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4prgisl; /* v4.7 New GIDL/GISL */
    double omiBSIM4paigc;
    double omiBSIM4pbigc;
    double omiBSIM4pcigc;
    double omiBSIM4paigsd;
    double omiBSIM4pbigsd;
    double omiBSIM4pcigsd;
    double omiBSIM4paigs;
    double omiBSIM4pbigs;
    double omiBSIM4pcigs;
    double omiBSIM4paigd;
    double omiBSIM4pbigd;
    double omiBSIM4pcigd;
    double omiBSIM4paigbacc;
    double omiBSIM4pbigbacc;
    double omiBSIM4pcigbacc;
    double omiBSIM4paigbinv;
    double omiBSIM4pbigbinv;
    double omiBSIM4pcigbinv;
    double omiBSIM4pnigc;
    double omiBSIM4pnigbacc;
    double omiBSIM4pnigbinv;
    double omiBSIM4pntox;
    double omiBSIM4peigbinv;
    double omiBSIM4ppigcd;
    double omiBSIM4ppoxedge;
    double omiBSIM4pxrcrg1;
    double omiBSIM4pxrcrg2;
    double omiBSIM4plambda;
    double omiBSIM4pvtl;
    double omiBSIM4pxn;
    double omiBSIM4pvfbsdoff;
    double omiBSIM4ptvfbsdoff;

    /* CV model */
    double omiBSIM4pcgsl;
    double omiBSIM4pcgdl;
    double omiBSIM4pckappas;
    double omiBSIM4pckappad;
    double omiBSIM4pcf;
    double omiBSIM4pclc;
    double omiBSIM4pcle;
    double omiBSIM4pvfbcv;
    double omiBSIM4pnoff;
    double omiBSIM4pvoffcv;
    double omiBSIM4pacde;
    double omiBSIM4pmoin;

    double omiBSIM4tnom;
    double omiBSIM4cgso;
    double omiBSIM4cgdo;
    double omiBSIM4cgbo;
    double omiBSIM4xpart;
    double omiBSIM4cFringOut;
    double omiBSIM4cFringMax;

    double omiBSIM4sheetResistance;
    double omiBSIM4SjctSatCurDensity;
    double omiBSIM4DjctSatCurDensity;
    double omiBSIM4SjctSidewallSatCurDensity;
    double omiBSIM4DjctSidewallSatCurDensity;
    double omiBSIM4SjctGateSidewallSatCurDensity;
    double omiBSIM4DjctGateSidewallSatCurDensity;
    double omiBSIM4SbulkJctPotential;
    double omiBSIM4DbulkJctPotential;
    double omiBSIM4SbulkJctBotGradingCoeff;
    double omiBSIM4DbulkJctBotGradingCoeff;
    double omiBSIM4SbulkJctSideGradingCoeff;
    double omiBSIM4DbulkJctSideGradingCoeff;
    double omiBSIM4SbulkJctGateSideGradingCoeff;
    double omiBSIM4DbulkJctGateSideGradingCoeff;
    double omiBSIM4SsidewallJctPotential;
    double omiBSIM4DsidewallJctPotential;
    double omiBSIM4SGatesidewallJctPotential;
    double omiBSIM4DGatesidewallJctPotential;
    double omiBSIM4SunitAreaJctCap;
    double omiBSIM4DunitAreaJctCap;
    double omiBSIM4SunitLengthSidewallJctCap;
    double omiBSIM4DunitLengthSidewallJctCap;
    double omiBSIM4SunitLengthGateSidewallJctCap;
    double omiBSIM4DunitLengthGateSidewallJctCap;
    double omiBSIM4SjctEmissionCoeff;
    double omiBSIM4DjctEmissionCoeff;
    double omiBSIM4SjctTempExponent;
    double omiBSIM4DjctTempExponent;
    double omiBSIM4njtsstemp;
    double omiBSIM4njtsswstemp;
    double omiBSIM4njtsswgstemp;
    double omiBSIM4njtsdtemp;
    double omiBSIM4njtsswdtemp;
    double omiBSIM4njtsswgdtemp;

    double omiBSIM4Lint;
    double omiBSIM4Ll;
    double omiBSIM4Llc;
    double omiBSIM4Lln;
    double omiBSIM4Lw;
    double omiBSIM4Lwc;
    double omiBSIM4Lwn;
    double omiBSIM4Lwl;
    double omiBSIM4Lwlc;
    double omiBSIM4Lmin;
    double omiBSIM4Lmax;

    double omiBSIM4Wint;
    double omiBSIM4Wl;
    double omiBSIM4Wlc;
    double omiBSIM4Wln;
    double omiBSIM4Ww;
    double omiBSIM4Wwc;
    double omiBSIM4Wwn;
    double omiBSIM4Wwl;
    double omiBSIM4Wwlc;
    double omiBSIM4Wmin;
    double omiBSIM4Wmax;

    /* added for stress effect */
    double omiBSIM4saref;
    double omiBSIM4sbref;
    double omiBSIM4wlod;
    double omiBSIM4ku0;
    double omiBSIM4kvsat;
    double omiBSIM4kvth0;
    double omiBSIM4tku0;
    double omiBSIM4llodku0;
    double omiBSIM4wlodku0;
    double omiBSIM4llodvth;
    double omiBSIM4wlodvth;
    double omiBSIM4lku0;
    double omiBSIM4wku0;
    double omiBSIM4pku0;
    double omiBSIM4lkvth0;
    double omiBSIM4wkvth0;
    double omiBSIM4pkvth0;
    double omiBSIM4stk2;
    double omiBSIM4lodk2;
    double omiBSIM4steta0;
    double omiBSIM4lodeta0;

    double omiBSIM4web;
    double omiBSIM4wec;
    double omiBSIM4kvth0we;
    double omiBSIM4k2we;
    double omiBSIM4ku0we;
    double omiBSIM4scref;
    double omiBSIM4wpemod;
    double omiBSIM4lkvth0we;
    double omiBSIM4lk2we;
    double omiBSIM4lku0we;
    double omiBSIM4wkvth0we;
    double omiBSIM4wk2we;
    double omiBSIM4wku0we;
    double omiBSIM4pkvth0we;
    double omiBSIM4pk2we;
    double omiBSIM4pku0we;

/* Pre-calculated constants
 * move to size-dependent param */
    double omiBSIM4Eg0;
    double omiBSIM4vtm;
    double omiBSIM4vtm0;
    double omiBSIM4coxe;
    double omiBSIM4coxp;
    double omiBSIM4cof1;
    double omiBSIM4cof2;
    double omiBSIM4cof3;
    double omiBSIM4cof4;
    double omiBSIM4vcrit;
    double omiBSIM4factor1;
    double omiBSIM4PhiBS;
    double omiBSIM4PhiBSWS;
    double omiBSIM4PhiBSWGS;
    double omiBSIM4SjctTempSatCurDensity;
    double omiBSIM4SjctSidewallTempSatCurDensity;
    double omiBSIM4SjctGateSidewallTempSatCurDensity;
    double omiBSIM4PhiBD;
    double omiBSIM4PhiBSWD;
    double omiBSIM4PhiBSWGD;
    double omiBSIM4DjctTempSatCurDensity;
    double omiBSIM4DjctSidewallTempSatCurDensity;
    double omiBSIM4DjctGateSidewallTempSatCurDensity;
    double omiBSIM4SunitAreaTempJctCap;
    double omiBSIM4DunitAreaTempJctCap;
    double omiBSIM4SunitLengthSidewallTempJctCap;
    double omiBSIM4DunitLengthSidewallTempJctCap;
    double omiBSIM4SunitLengthGateSidewallTempJctCap;
    double omiBSIM4DunitLengthGateSidewallTempJctCap;

    double omiBSIM4oxideTrapDensityA;
    double omiBSIM4oxideTrapDensityB;
    double omiBSIM4oxideTrapDensityC;
    double omiBSIM4em;
    double omiBSIM4ef;
    double omiBSIM4af;
    double omiBSIM4kf;

    double omiBSIM4vgsMax;
    double omiBSIM4vgdMax;
    double omiBSIM4vgbMax;
    double omiBSIM4vdsMax;
    double omiBSIM4vbsMax;
    double omiBSIM4vbdMax;
    double omiBSIM4vgsrMax;
    double omiBSIM4vgdrMax;
    double omiBSIM4vgbrMax;
    double omiBSIM4vbsrMax;
    double omiBSIM4vbdrMax;

    struct bsim4SizeDependParam *pSizeDependParamKnot;

#ifdef USE_OMP
    int omiBSIM4InstCount;
    struct somiBSIM4instance **omiBSIM4InstanceArray;
#endif

    /* Flags */
    unsigned  omiBSIM4mobModGiven :1;
    unsigned  omiBSIM4binUnitGiven :1;
    unsigned  omiBSIM4cvchargeModGiven :1;
    unsigned  omiBSIM4capModGiven :1;
    unsigned  omiBSIM4dioModGiven :1;
    unsigned  omiBSIM4rdsModGiven :1;
    unsigned  omiBSIM4rbodyModGiven :1;
    unsigned  omiBSIM4rgateModGiven :1;
    unsigned  omiBSIM4perModGiven :1;
    unsigned  omiBSIM4geoModGiven :1;
    unsigned  omiBSIM4rgeoModGiven :1;
    unsigned  omiBSIM4paramChkGiven :1;
    unsigned  omiBSIM4trnqsModGiven :1;
    unsigned  omiBSIM4acnqsModGiven :1;
    unsigned  omiBSIM4fnoiModGiven :1;
    unsigned  omiBSIM4tnoiModGiven :1;
    unsigned  omiBSIM4mtrlModGiven :1;
    unsigned  omiBSIM4mtrlCompatModGiven :1;
    unsigned  omiBSIM4gidlModGiven :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4igcModGiven :1;
    unsigned  omiBSIM4igbModGiven :1;
    unsigned  omiBSIM4tempModGiven :1;
    unsigned  omiBSIM4typeGiven   :1;
    unsigned  omiBSIM4toxrefGiven   :1;
    unsigned  omiBSIM4eotGiven   :1;
    unsigned  omiBSIM4vddeotGiven   :1;
    unsigned  omiBSIM4tempeotGiven  :1;
    unsigned  omiBSIM4leffeotGiven  :1;
    unsigned  omiBSIM4weffeotGiven  :1;
    unsigned  omiBSIM4adosGiven   :1;
    unsigned  omiBSIM4bdosGiven   :1;
    unsigned  omiBSIM4toxeGiven   :1;
    unsigned  omiBSIM4toxpGiven   :1;
    unsigned  omiBSIM4toxmGiven   :1;
    unsigned  omiBSIM4dtoxGiven   :1;
    unsigned  omiBSIM4epsroxGiven   :1;
    unsigned  omiBSIM4versionGiven   :1;
    unsigned  omiBSIM4cdscGiven   :1;
    unsigned  omiBSIM4cdscbGiven   :1;
    unsigned  omiBSIM4cdscdGiven   :1;
    unsigned  omiBSIM4citGiven   :1;
    unsigned  omiBSIM4nfactorGiven   :1;
    unsigned  omiBSIM4xjGiven   :1;
    unsigned  omiBSIM4vsatGiven   :1;
    unsigned  omiBSIM4atGiven   :1;
    unsigned  omiBSIM4a0Given   :1;
    unsigned  omiBSIM4agsGiven   :1;
    unsigned  omiBSIM4a1Given   :1;
    unsigned  omiBSIM4a2Given   :1;
    unsigned  omiBSIM4ketaGiven   :1;
    unsigned  omiBSIM4nsubGiven   :1;
    unsigned  omiBSIM4phigGiven   :1;
    unsigned  omiBSIM4epsrgateGiven   :1;
    unsigned  omiBSIM4easubGiven   :1;
    unsigned  omiBSIM4epsrsubGiven   :1;
    unsigned  omiBSIM4ni0subGiven   :1;
    unsigned  omiBSIM4bg0subGiven   :1;
    unsigned  omiBSIM4tbgasubGiven   :1;
    unsigned  omiBSIM4tbgbsubGiven   :1;
    unsigned  omiBSIM4ndepGiven   :1;
    unsigned  omiBSIM4nsdGiven    :1;
    unsigned  omiBSIM4phinGiven   :1;
    unsigned  omiBSIM4ngateGiven   :1;
    unsigned  omiBSIM4gamma1Given   :1;
    unsigned  omiBSIM4gamma2Given   :1;
    unsigned  omiBSIM4vbxGiven   :1;
    unsigned  omiBSIM4vbmGiven   :1;
    unsigned  omiBSIM4xtGiven   :1;
    unsigned  omiBSIM4k1Given   :1;
    unsigned  omiBSIM4kt1Given   :1;
    unsigned  omiBSIM4kt1lGiven   :1;
    unsigned  omiBSIM4kt2Given   :1;
    unsigned  omiBSIM4k2Given   :1;
    unsigned  omiBSIM4k3Given   :1;
    unsigned  omiBSIM4k3bGiven   :1;
    unsigned  omiBSIM4w0Given   :1;
    unsigned  omiBSIM4dvtp0Given :1;
    unsigned  omiBSIM4dvtp1Given :1;
    unsigned  omiBSIM4dvtp2Given :1;        /* New DIBL/Rout */
    unsigned  omiBSIM4dvtp3Given :1;
    unsigned  omiBSIM4dvtp4Given :1;
    unsigned  omiBSIM4dvtp5Given :1;
    unsigned  omiBSIM4lpe0Given   :1;
    unsigned  omiBSIM4lpebGiven   :1;
    unsigned  omiBSIM4dvt0Given   :1;
    unsigned  omiBSIM4dvt1Given   :1;
    unsigned  omiBSIM4dvt2Given   :1;
    unsigned  omiBSIM4dvt0wGiven   :1;
    unsigned  omiBSIM4dvt1wGiven   :1;
    unsigned  omiBSIM4dvt2wGiven   :1;
    unsigned  omiBSIM4droutGiven   :1;
    unsigned  omiBSIM4dsubGiven   :1;
    unsigned  omiBSIM4vth0Given   :1;
    unsigned  omiBSIM4euGiven   :1;
    unsigned  omiBSIM4ucsGiven  :1;
    unsigned  omiBSIM4uaGiven   :1;
    unsigned  omiBSIM4ua1Given   :1;
    unsigned  omiBSIM4ubGiven   :1;
    unsigned  omiBSIM4ub1Given   :1;
    unsigned  omiBSIM4ucGiven   :1;
    unsigned  omiBSIM4uc1Given   :1;
    unsigned  omiBSIM4udGiven     :1;
    unsigned  omiBSIM4ud1Given     :1;
    unsigned  omiBSIM4upGiven     :1;
    unsigned  omiBSIM4lpGiven     :1;
    unsigned  omiBSIM4u0Given   :1;
    unsigned  omiBSIM4uteGiven   :1;
    unsigned  omiBSIM4ucsteGiven :1;
    unsigned  omiBSIM4voffGiven   :1;
    unsigned  omiBSIM4tvoffGiven   :1;
    unsigned  omiBSIM4tnfactorGiven  :1;         /* v4.7 Temp dep of leakage current */
    unsigned  omiBSIM4teta0Given   :1;           /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4tvoffcvGiven   :1;        /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4vofflGiven  :1;
    unsigned  omiBSIM4voffcvlGiven  :1;
    unsigned  omiBSIM4minvGiven   :1;
    unsigned  omiBSIM4minvcvGiven   :1;
    unsigned  omiBSIM4rdswGiven   :1;
    unsigned  omiBSIM4rdswminGiven :1;
    unsigned  omiBSIM4rdwminGiven :1;
    unsigned  omiBSIM4rswminGiven :1;
    unsigned  omiBSIM4rswGiven   :1;
    unsigned  omiBSIM4rdwGiven   :1;
    unsigned  omiBSIM4prwgGiven   :1;
    unsigned  omiBSIM4prwbGiven   :1;
    unsigned  omiBSIM4prtGiven   :1;
    unsigned  omiBSIM4eta0Given   :1;
    unsigned  omiBSIM4etabGiven   :1;
    unsigned  omiBSIM4pclmGiven   :1;
    unsigned  omiBSIM4pdibl1Given   :1;
    unsigned  omiBSIM4pdibl2Given   :1;
    unsigned  omiBSIM4pdiblbGiven   :1;
    unsigned  omiBSIM4fproutGiven   :1;
    unsigned  omiBSIM4pditsGiven    :1;
    unsigned  omiBSIM4pditsdGiven    :1;
    unsigned  omiBSIM4pditslGiven    :1;
    unsigned  omiBSIM4pscbe1Given   :1;
    unsigned  omiBSIM4pscbe2Given   :1;
    unsigned  omiBSIM4pvagGiven   :1;
    unsigned  omiBSIM4deltaGiven  :1;
    unsigned  omiBSIM4wrGiven   :1;
    unsigned  omiBSIM4dwgGiven   :1;
    unsigned  omiBSIM4dwbGiven   :1;
    unsigned  omiBSIM4b0Given   :1;
    unsigned  omiBSIM4b1Given   :1;
    unsigned  omiBSIM4alpha0Given   :1;
    unsigned  omiBSIM4alpha1Given   :1;
    unsigned  omiBSIM4beta0Given   :1;
    unsigned  omiBSIM4agidlGiven   :1;
    unsigned  omiBSIM4bgidlGiven   :1;
    unsigned  omiBSIM4cgidlGiven   :1;
    unsigned  omiBSIM4egidlGiven   :1;
    unsigned  omiBSIM4fgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4kgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4rgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4agislGiven   :1;
    unsigned  omiBSIM4bgislGiven   :1;
    unsigned  omiBSIM4cgislGiven   :1;
    unsigned  omiBSIM4egislGiven   :1;
    unsigned  omiBSIM4fgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4kgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4rgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4aigcGiven   :1;
    unsigned  omiBSIM4bigcGiven   :1;
    unsigned  omiBSIM4cigcGiven   :1;
    unsigned  omiBSIM4aigsdGiven   :1;
    unsigned  omiBSIM4bigsdGiven   :1;
    unsigned  omiBSIM4cigsdGiven   :1;
    unsigned  omiBSIM4aigsGiven   :1;
    unsigned  omiBSIM4bigsGiven   :1;
    unsigned  omiBSIM4cigsGiven   :1;
    unsigned  omiBSIM4aigdGiven   :1;
    unsigned  omiBSIM4bigdGiven   :1;
    unsigned  omiBSIM4cigdGiven   :1;
    unsigned  omiBSIM4aigbaccGiven   :1;
    unsigned  omiBSIM4bigbaccGiven   :1;
    unsigned  omiBSIM4cigbaccGiven   :1;
    unsigned  omiBSIM4aigbinvGiven   :1;
    unsigned  omiBSIM4bigbinvGiven   :1;
    unsigned  omiBSIM4cigbinvGiven   :1;
    unsigned  omiBSIM4nigcGiven   :1;
    unsigned  omiBSIM4nigbinvGiven   :1;
    unsigned  omiBSIM4nigbaccGiven   :1;
    unsigned  omiBSIM4ntoxGiven   :1;
    unsigned  omiBSIM4eigbinvGiven   :1;
    unsigned  omiBSIM4pigcdGiven   :1;
    unsigned  omiBSIM4poxedgeGiven   :1;
    unsigned  omiBSIM4ijthdfwdGiven  :1;
    unsigned  omiBSIM4ijthsfwdGiven  :1;
    unsigned  omiBSIM4ijthdrevGiven  :1;
    unsigned  omiBSIM4ijthsrevGiven  :1;
    unsigned  omiBSIM4xjbvdGiven   :1;
    unsigned  omiBSIM4xjbvsGiven   :1;
    unsigned  omiBSIM4bvdGiven   :1;
    unsigned  omiBSIM4bvsGiven   :1;

    unsigned  omiBSIM4jtssGiven   :1;
    unsigned  omiBSIM4jtsdGiven   :1;
    unsigned  omiBSIM4jtsswsGiven   :1;
    unsigned  omiBSIM4jtsswdGiven   :1;
    unsigned  omiBSIM4jtsswgsGiven   :1;
    unsigned  omiBSIM4jtsswgdGiven   :1;
        unsigned  omiBSIM4jtweffGiven    :1;
    unsigned  omiBSIM4njtsGiven   :1;
    unsigned  omiBSIM4njtsswGiven   :1;
    unsigned  omiBSIM4njtsswgGiven   :1;
    unsigned  omiBSIM4njtsdGiven   :1;
    unsigned  omiBSIM4njtsswdGiven   :1;
    unsigned  omiBSIM4njtsswgdGiven   :1;
    unsigned  omiBSIM4xtssGiven   :1;
    unsigned  omiBSIM4xtsdGiven   :1;
    unsigned  omiBSIM4xtsswsGiven   :1;
    unsigned  omiBSIM4xtsswdGiven   :1;
    unsigned  omiBSIM4xtsswgsGiven   :1;
    unsigned  omiBSIM4xtsswgdGiven   :1;
    unsigned  omiBSIM4tnjtsGiven   :1;
    unsigned  omiBSIM4tnjtsswGiven   :1;
    unsigned  omiBSIM4tnjtsswgGiven   :1;
    unsigned  omiBSIM4tnjtsdGiven   :1;
    unsigned  omiBSIM4tnjtsswdGiven   :1;
    unsigned  omiBSIM4tnjtsswgdGiven   :1;
    unsigned  omiBSIM4vtssGiven   :1;
    unsigned  omiBSIM4vtsdGiven   :1;
    unsigned  omiBSIM4vtsswsGiven   :1;
    unsigned  omiBSIM4vtsswdGiven   :1;
    unsigned  omiBSIM4vtsswgsGiven   :1;
    unsigned  omiBSIM4vtsswgdGiven   :1;

    unsigned  omiBSIM4vfbGiven   :1;
    unsigned  omiBSIM4gbminGiven :1;
    unsigned  omiBSIM4rbdbGiven :1;
    unsigned  omiBSIM4rbsbGiven :1;
    unsigned  omiBSIM4rbpsGiven :1;
    unsigned  omiBSIM4rbpdGiven :1;
    unsigned  omiBSIM4rbpbGiven :1;

    unsigned omiBSIM4rbps0Given :1;
    unsigned omiBSIM4rbpslGiven :1;
    unsigned omiBSIM4rbpswGiven :1;
    unsigned omiBSIM4rbpsnfGiven :1;

    unsigned omiBSIM4rbpd0Given :1;
    unsigned omiBSIM4rbpdlGiven :1;
    unsigned omiBSIM4rbpdwGiven :1;
    unsigned omiBSIM4rbpdnfGiven :1;

    unsigned omiBSIM4rbpbx0Given :1;
    unsigned omiBSIM4rbpbxlGiven :1;
    unsigned omiBSIM4rbpbxwGiven :1;
    unsigned omiBSIM4rbpbxnfGiven :1;
    unsigned omiBSIM4rbpby0Given :1;
    unsigned omiBSIM4rbpbylGiven :1;
    unsigned omiBSIM4rbpbywGiven :1;
    unsigned omiBSIM4rbpbynfGiven :1;

    unsigned omiBSIM4rbsbx0Given :1;
    unsigned omiBSIM4rbsby0Given :1;
    unsigned omiBSIM4rbdbx0Given :1;
    unsigned omiBSIM4rbdby0Given :1;

    unsigned omiBSIM4rbsdbxlGiven :1;
    unsigned omiBSIM4rbsdbxwGiven :1;
    unsigned omiBSIM4rbsdbxnfGiven :1;
    unsigned omiBSIM4rbsdbylGiven :1;
    unsigned omiBSIM4rbsdbywGiven :1;
    unsigned omiBSIM4rbsdbynfGiven :1;

    unsigned  omiBSIM4xrcrg1Given   :1;
    unsigned  omiBSIM4xrcrg2Given   :1;
    unsigned  omiBSIM4tnoiaGiven    :1;
    unsigned  omiBSIM4tnoibGiven    :1;
    unsigned  omiBSIM4tnoicGiven    :1;
    unsigned  omiBSIM4rnoiaGiven    :1;
    unsigned  omiBSIM4rnoibGiven    :1;
    unsigned  omiBSIM4rnoicGiven    :1;
    unsigned  omiBSIM4ntnoiGiven    :1;

    unsigned  omiBSIM4lambdaGiven    :1;
    unsigned  omiBSIM4vtlGiven    :1;
    unsigned  omiBSIM4lcGiven    :1;
    unsigned  omiBSIM4xnGiven    :1;
    unsigned  omiBSIM4vfbsdoffGiven    :1;
    unsigned  omiBSIM4lintnoiGiven    :1;
    unsigned  omiBSIM4tvfbsdoffGiven    :1;

    /* CV model and parasitics */
    unsigned  omiBSIM4cgslGiven   :1;
    unsigned  omiBSIM4cgdlGiven   :1;
    unsigned  omiBSIM4ckappasGiven   :1;
    unsigned  omiBSIM4ckappadGiven   :1;
    unsigned  omiBSIM4cfGiven   :1;
    unsigned  omiBSIM4vfbcvGiven   :1;
    unsigned  omiBSIM4clcGiven   :1;
    unsigned  omiBSIM4cleGiven   :1;
    unsigned  omiBSIM4dwcGiven   :1;
    unsigned  omiBSIM4dlcGiven   :1;
    unsigned  omiBSIM4xwGiven    :1;
    unsigned  omiBSIM4xlGiven    :1;
    unsigned  omiBSIM4dlcigGiven   :1;
    unsigned  omiBSIM4dlcigdGiven   :1;
    unsigned  omiBSIM4dwjGiven   :1;
    unsigned  omiBSIM4noffGiven  :1;
    unsigned  omiBSIM4voffcvGiven :1;
    unsigned  omiBSIM4acdeGiven  :1;
    unsigned  omiBSIM4moinGiven  :1;
    unsigned  omiBSIM4tcjGiven   :1;
    unsigned  omiBSIM4tcjswGiven :1;
    unsigned  omiBSIM4tcjswgGiven :1;
    unsigned  omiBSIM4tpbGiven    :1;
    unsigned  omiBSIM4tpbswGiven  :1;
    unsigned  omiBSIM4tpbswgGiven :1;
    unsigned  omiBSIM4dmcgGiven :1;
    unsigned  omiBSIM4dmciGiven :1;
    unsigned  omiBSIM4dmdgGiven :1;
    unsigned  omiBSIM4dmcgtGiven :1;
    unsigned  omiBSIM4xgwGiven :1;
    unsigned  omiBSIM4xglGiven :1;
    unsigned  omiBSIM4rshgGiven :1;
    unsigned  omiBSIM4ngconGiven :1;


    /* Length dependence */
    unsigned  omiBSIM4lcdscGiven   :1;
    unsigned  omiBSIM4lcdscbGiven   :1;
    unsigned  omiBSIM4lcdscdGiven   :1;
    unsigned  omiBSIM4lcitGiven   :1;
    unsigned  omiBSIM4lnfactorGiven   :1;
    unsigned  omiBSIM4lxjGiven   :1;
    unsigned  omiBSIM4lvsatGiven   :1;
    unsigned  omiBSIM4latGiven   :1;
    unsigned  omiBSIM4la0Given   :1;
    unsigned  omiBSIM4lagsGiven   :1;
    unsigned  omiBSIM4la1Given   :1;
    unsigned  omiBSIM4la2Given   :1;
    unsigned  omiBSIM4lketaGiven   :1;
    unsigned  omiBSIM4lnsubGiven   :1;
    unsigned  omiBSIM4lndepGiven   :1;
    unsigned  omiBSIM4lnsdGiven    :1;
    unsigned  omiBSIM4lphinGiven   :1;
    unsigned  omiBSIM4lngateGiven   :1;
    unsigned  omiBSIM4lgamma1Given   :1;
    unsigned  omiBSIM4lgamma2Given   :1;
    unsigned  omiBSIM4lvbxGiven   :1;
    unsigned  omiBSIM4lvbmGiven   :1;
    unsigned  omiBSIM4lxtGiven   :1;
    unsigned  omiBSIM4lk1Given   :1;
    unsigned  omiBSIM4lkt1Given   :1;
    unsigned  omiBSIM4lkt1lGiven   :1;
    unsigned  omiBSIM4lkt2Given   :1;
    unsigned  omiBSIM4lk2Given   :1;
    unsigned  omiBSIM4lk3Given   :1;
    unsigned  omiBSIM4lk3bGiven   :1;
    unsigned  omiBSIM4lw0Given   :1;
    unsigned  omiBSIM4ldvtp0Given :1;
    unsigned  omiBSIM4ldvtp1Given :1;
    unsigned  omiBSIM4ldvtp2Given :1;        /* New DIBL/Rout */
    unsigned  omiBSIM4ldvtp3Given :1;
    unsigned  omiBSIM4ldvtp4Given :1;
    unsigned  omiBSIM4ldvtp5Given :1;
    unsigned  omiBSIM4llpe0Given   :1;
    unsigned  omiBSIM4llpebGiven   :1;
    unsigned  omiBSIM4ldvt0Given   :1;
    unsigned  omiBSIM4ldvt1Given   :1;
    unsigned  omiBSIM4ldvt2Given   :1;
    unsigned  omiBSIM4ldvt0wGiven   :1;
    unsigned  omiBSIM4ldvt1wGiven   :1;
    unsigned  omiBSIM4ldvt2wGiven   :1;
    unsigned  omiBSIM4ldroutGiven   :1;
    unsigned  omiBSIM4ldsubGiven   :1;
    unsigned  omiBSIM4lvth0Given   :1;
    unsigned  omiBSIM4luaGiven   :1;
    unsigned  omiBSIM4lua1Given   :1;
    unsigned  omiBSIM4lubGiven   :1;
    unsigned  omiBSIM4lub1Given   :1;
    unsigned  omiBSIM4lucGiven   :1;
    unsigned  omiBSIM4luc1Given   :1;
    unsigned  omiBSIM4ludGiven     :1;
    unsigned  omiBSIM4lud1Given     :1;
    unsigned  omiBSIM4lupGiven     :1;
    unsigned  omiBSIM4llpGiven     :1;
    unsigned  omiBSIM4lu0Given   :1;
    unsigned  omiBSIM4leuGiven   :1;
        unsigned  omiBSIM4lucsGiven   :1;
    unsigned  omiBSIM4luteGiven   :1;
        unsigned  omiBSIM4lucsteGiven  :1;
    unsigned  omiBSIM4lvoffGiven   :1;
    unsigned  omiBSIM4ltvoffGiven   :1;
    unsigned  omiBSIM4ltnfactorGiven  :1;         /* v4.7 Temp dep of leakage current */
    unsigned  omiBSIM4lteta0Given   :1;           /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4ltvoffcvGiven   :1;        /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4lminvGiven   :1;
    unsigned  omiBSIM4lminvcvGiven   :1;
    unsigned  omiBSIM4lrdswGiven   :1;
    unsigned  omiBSIM4lrswGiven   :1;
    unsigned  omiBSIM4lrdwGiven   :1;
    unsigned  omiBSIM4lprwgGiven   :1;
    unsigned  omiBSIM4lprwbGiven   :1;
    unsigned  omiBSIM4lprtGiven   :1;
    unsigned  omiBSIM4leta0Given   :1;
    unsigned  omiBSIM4letabGiven   :1;
    unsigned  omiBSIM4lpclmGiven   :1;
    unsigned  omiBSIM4lpdibl1Given   :1;
    unsigned  omiBSIM4lpdibl2Given   :1;
    unsigned  omiBSIM4lpdiblbGiven   :1;
    unsigned  omiBSIM4lfproutGiven   :1;
    unsigned  omiBSIM4lpditsGiven    :1;
    unsigned  omiBSIM4lpditsdGiven    :1;
    unsigned  omiBSIM4lpscbe1Given   :1;
    unsigned  omiBSIM4lpscbe2Given   :1;
    unsigned  omiBSIM4lpvagGiven   :1;
    unsigned  omiBSIM4ldeltaGiven  :1;
    unsigned  omiBSIM4lwrGiven   :1;
    unsigned  omiBSIM4ldwgGiven   :1;
    unsigned  omiBSIM4ldwbGiven   :1;
    unsigned  omiBSIM4lb0Given   :1;
    unsigned  omiBSIM4lb1Given   :1;
    unsigned  omiBSIM4lalpha0Given   :1;
    unsigned  omiBSIM4lalpha1Given   :1;
    unsigned  omiBSIM4lbeta0Given   :1;
    unsigned  omiBSIM4lvfbGiven   :1;
    unsigned  omiBSIM4lagidlGiven   :1;
    unsigned  omiBSIM4lbgidlGiven   :1;
    unsigned  omiBSIM4lcgidlGiven   :1;
    unsigned  omiBSIM4legidlGiven   :1;
    unsigned  omiBSIM4lfgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4lkgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4lrgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4lagislGiven   :1;
    unsigned  omiBSIM4lbgislGiven   :1;
    unsigned  omiBSIM4lcgislGiven   :1;
    unsigned  omiBSIM4legislGiven   :1;
    unsigned  omiBSIM4lfgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4lkgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4lrgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4laigcGiven   :1;
    unsigned  omiBSIM4lbigcGiven   :1;
    unsigned  omiBSIM4lcigcGiven   :1;
    unsigned  omiBSIM4laigsdGiven   :1;
    unsigned  omiBSIM4lbigsdGiven   :1;
    unsigned  omiBSIM4lcigsdGiven   :1;
    unsigned  omiBSIM4laigsGiven   :1;
    unsigned  omiBSIM4lbigsGiven   :1;
    unsigned  omiBSIM4lcigsGiven   :1;
    unsigned  omiBSIM4laigdGiven   :1;
    unsigned  omiBSIM4lbigdGiven   :1;
    unsigned  omiBSIM4lcigdGiven   :1;
    unsigned  omiBSIM4laigbaccGiven   :1;
    unsigned  omiBSIM4lbigbaccGiven   :1;
    unsigned  omiBSIM4lcigbaccGiven   :1;
    unsigned  omiBSIM4laigbinvGiven   :1;
    unsigned  omiBSIM4lbigbinvGiven   :1;
    unsigned  omiBSIM4lcigbinvGiven   :1;
    unsigned  omiBSIM4lnigcGiven   :1;
    unsigned  omiBSIM4lnigbinvGiven   :1;
    unsigned  omiBSIM4lnigbaccGiven   :1;
    unsigned  omiBSIM4lntoxGiven   :1;
    unsigned  omiBSIM4leigbinvGiven   :1;
    unsigned  omiBSIM4lpigcdGiven   :1;
    unsigned  omiBSIM4lpoxedgeGiven   :1;
    unsigned  omiBSIM4lxrcrg1Given   :1;
    unsigned  omiBSIM4lxrcrg2Given   :1;
    unsigned  omiBSIM4llambdaGiven    :1;
    unsigned  omiBSIM4lvtlGiven    :1;
    unsigned  omiBSIM4lxnGiven    :1;
    unsigned  omiBSIM4lvfbsdoffGiven    :1;
    unsigned  omiBSIM4ltvfbsdoffGiven    :1;

    /* CV model */
    unsigned  omiBSIM4lcgslGiven   :1;
    unsigned  omiBSIM4lcgdlGiven   :1;
    unsigned  omiBSIM4lckappasGiven   :1;
    unsigned  omiBSIM4lckappadGiven   :1;
    unsigned  omiBSIM4lcfGiven   :1;
    unsigned  omiBSIM4lclcGiven   :1;
    unsigned  omiBSIM4lcleGiven   :1;
    unsigned  omiBSIM4lvfbcvGiven   :1;
    unsigned  omiBSIM4lnoffGiven   :1;
    unsigned  omiBSIM4lvoffcvGiven :1;
    unsigned  omiBSIM4lacdeGiven   :1;
    unsigned  omiBSIM4lmoinGiven   :1;

    /* Width dependence */
    unsigned  omiBSIM4wcdscGiven   :1;
    unsigned  omiBSIM4wcdscbGiven   :1;
    unsigned  omiBSIM4wcdscdGiven   :1;
    unsigned  omiBSIM4wcitGiven   :1;
    unsigned  omiBSIM4wnfactorGiven   :1;
    unsigned  omiBSIM4wxjGiven   :1;
    unsigned  omiBSIM4wvsatGiven   :1;
    unsigned  omiBSIM4watGiven   :1;
    unsigned  omiBSIM4wa0Given   :1;
    unsigned  omiBSIM4wagsGiven   :1;
    unsigned  omiBSIM4wa1Given   :1;
    unsigned  omiBSIM4wa2Given   :1;
    unsigned  omiBSIM4wketaGiven   :1;
    unsigned  omiBSIM4wnsubGiven   :1;
    unsigned  omiBSIM4wndepGiven   :1;
    unsigned  omiBSIM4wnsdGiven    :1;
    unsigned  omiBSIM4wphinGiven   :1;
    unsigned  omiBSIM4wngateGiven   :1;
    unsigned  omiBSIM4wgamma1Given   :1;
    unsigned  omiBSIM4wgamma2Given   :1;
    unsigned  omiBSIM4wvbxGiven   :1;
    unsigned  omiBSIM4wvbmGiven   :1;
    unsigned  omiBSIM4wxtGiven   :1;
    unsigned  omiBSIM4wk1Given   :1;
    unsigned  omiBSIM4wkt1Given   :1;
    unsigned  omiBSIM4wkt1lGiven   :1;
    unsigned  omiBSIM4wkt2Given   :1;
    unsigned  omiBSIM4wk2Given   :1;
    unsigned  omiBSIM4wk3Given   :1;
    unsigned  omiBSIM4wk3bGiven   :1;
    unsigned  omiBSIM4ww0Given   :1;
    unsigned  omiBSIM4wdvtp0Given :1;
    unsigned  omiBSIM4wdvtp1Given :1;
    unsigned  omiBSIM4wdvtp2Given :1;        /* New DIBL/Rout */
    unsigned  omiBSIM4wdvtp3Given :1;
    unsigned  omiBSIM4wdvtp4Given :1;
    unsigned  omiBSIM4wdvtp5Given :1;
    unsigned  omiBSIM4wlpe0Given   :1;
    unsigned  omiBSIM4wlpebGiven   :1;
    unsigned  omiBSIM4wdvt0Given   :1;
    unsigned  omiBSIM4wdvt1Given   :1;
    unsigned  omiBSIM4wdvt2Given   :1;
    unsigned  omiBSIM4wdvt0wGiven   :1;
    unsigned  omiBSIM4wdvt1wGiven   :1;
    unsigned  omiBSIM4wdvt2wGiven   :1;
    unsigned  omiBSIM4wdroutGiven   :1;
    unsigned  omiBSIM4wdsubGiven   :1;
    unsigned  omiBSIM4wvth0Given   :1;
    unsigned  omiBSIM4wuaGiven   :1;
    unsigned  omiBSIM4wua1Given   :1;
    unsigned  omiBSIM4wubGiven   :1;
    unsigned  omiBSIM4wub1Given   :1;
    unsigned  omiBSIM4wucGiven   :1;
    unsigned  omiBSIM4wuc1Given   :1;
    unsigned  omiBSIM4wudGiven     :1;
    unsigned  omiBSIM4wud1Given     :1;
    unsigned  omiBSIM4wupGiven     :1;
    unsigned  omiBSIM4wlpGiven     :1;
    unsigned  omiBSIM4wu0Given   :1;
    unsigned  omiBSIM4weuGiven   :1;
        unsigned  omiBSIM4wucsGiven  :1;
    unsigned  omiBSIM4wuteGiven   :1;
        unsigned  omiBSIM4wucsteGiven  :1;
    unsigned  omiBSIM4wvoffGiven   :1;
    unsigned  omiBSIM4wtvoffGiven   :1;
    unsigned  omiBSIM4wtnfactorGiven  :1;         /* v4.7 Temp dep of leakage current */
    unsigned  omiBSIM4wteta0Given   :1;           /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4wtvoffcvGiven   :1;        /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4wminvGiven   :1;
    unsigned  omiBSIM4wminvcvGiven   :1;
    unsigned  omiBSIM4wrdswGiven   :1;
    unsigned  omiBSIM4wrswGiven   :1;
    unsigned  omiBSIM4wrdwGiven   :1;
    unsigned  omiBSIM4wprwgGiven   :1;
    unsigned  omiBSIM4wprwbGiven   :1;
    unsigned  omiBSIM4wprtGiven   :1;
    unsigned  omiBSIM4weta0Given   :1;
    unsigned  omiBSIM4wetabGiven   :1;
    unsigned  omiBSIM4wpclmGiven   :1;
    unsigned  omiBSIM4wpdibl1Given   :1;
    unsigned  omiBSIM4wpdibl2Given   :1;
    unsigned  omiBSIM4wpdiblbGiven   :1;
    unsigned  omiBSIM4wfproutGiven   :1;
    unsigned  omiBSIM4wpditsGiven    :1;
    unsigned  omiBSIM4wpditsdGiven    :1;
    unsigned  omiBSIM4wpscbe1Given   :1;
    unsigned  omiBSIM4wpscbe2Given   :1;
    unsigned  omiBSIM4wpvagGiven   :1;
    unsigned  omiBSIM4wdeltaGiven  :1;
    unsigned  omiBSIM4wwrGiven   :1;
    unsigned  omiBSIM4wdwgGiven   :1;
    unsigned  omiBSIM4wdwbGiven   :1;
    unsigned  omiBSIM4wb0Given   :1;
    unsigned  omiBSIM4wb1Given   :1;
    unsigned  omiBSIM4walpha0Given   :1;
    unsigned  omiBSIM4walpha1Given   :1;
    unsigned  omiBSIM4wbeta0Given   :1;
    unsigned  omiBSIM4wvfbGiven   :1;
    unsigned  omiBSIM4wagidlGiven   :1;
    unsigned  omiBSIM4wbgidlGiven   :1;
    unsigned  omiBSIM4wcgidlGiven   :1;
    unsigned  omiBSIM4wegidlGiven   :1;
    unsigned  omiBSIM4wfgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4wkgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4wrgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4wagislGiven   :1;
    unsigned  omiBSIM4wbgislGiven   :1;
    unsigned  omiBSIM4wcgislGiven   :1;
    unsigned  omiBSIM4wegislGiven   :1;
    unsigned  omiBSIM4wfgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4wkgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4wrgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4waigcGiven   :1;
    unsigned  omiBSIM4wbigcGiven   :1;
    unsigned  omiBSIM4wcigcGiven   :1;
    unsigned  omiBSIM4waigsdGiven   :1;
    unsigned  omiBSIM4wbigsdGiven   :1;
    unsigned  omiBSIM4wcigsdGiven   :1;
    unsigned  omiBSIM4waigsGiven   :1;
    unsigned  omiBSIM4wbigsGiven   :1;
    unsigned  omiBSIM4wcigsGiven   :1;
    unsigned  omiBSIM4waigdGiven   :1;
    unsigned  omiBSIM4wbigdGiven   :1;
    unsigned  omiBSIM4wcigdGiven   :1;
    unsigned  omiBSIM4waigbaccGiven   :1;
    unsigned  omiBSIM4wbigbaccGiven   :1;
    unsigned  omiBSIM4wcigbaccGiven   :1;
    unsigned  omiBSIM4waigbinvGiven   :1;
    unsigned  omiBSIM4wbigbinvGiven   :1;
    unsigned  omiBSIM4wcigbinvGiven   :1;
    unsigned  omiBSIM4wnigcGiven   :1;
    unsigned  omiBSIM4wnigbinvGiven   :1;
    unsigned  omiBSIM4wnigbaccGiven   :1;
    unsigned  omiBSIM4wntoxGiven   :1;
    unsigned  omiBSIM4weigbinvGiven   :1;
    unsigned  omiBSIM4wpigcdGiven   :1;
    unsigned  omiBSIM4wpoxedgeGiven   :1;
    unsigned  omiBSIM4wxrcrg1Given   :1;
    unsigned  omiBSIM4wxrcrg2Given   :1;
    unsigned  omiBSIM4wlambdaGiven    :1;
    unsigned  omiBSIM4wvtlGiven    :1;
    unsigned  omiBSIM4wxnGiven    :1;
    unsigned  omiBSIM4wvfbsdoffGiven    :1;
    unsigned  omiBSIM4wtvfbsdoffGiven    :1;

    /* CV model */
    unsigned  omiBSIM4wcgslGiven   :1;
    unsigned  omiBSIM4wcgdlGiven   :1;
    unsigned  omiBSIM4wckappasGiven   :1;
    unsigned  omiBSIM4wckappadGiven   :1;
    unsigned  omiBSIM4wcfGiven   :1;
    unsigned  omiBSIM4wclcGiven   :1;
    unsigned  omiBSIM4wcleGiven   :1;
    unsigned  omiBSIM4wvfbcvGiven   :1;
    unsigned  omiBSIM4wnoffGiven   :1;
    unsigned  omiBSIM4wvoffcvGiven :1;
    unsigned  omiBSIM4wacdeGiven   :1;
    unsigned  omiBSIM4wmoinGiven   :1;

    /* Cross-term dependence */
    unsigned  omiBSIM4pcdscGiven   :1;
    unsigned  omiBSIM4pcdscbGiven   :1;
    unsigned  omiBSIM4pcdscdGiven   :1;
    unsigned  omiBSIM4pcitGiven   :1;
    unsigned  omiBSIM4pnfactorGiven   :1;
    unsigned  omiBSIM4pxjGiven   :1;
    unsigned  omiBSIM4pvsatGiven   :1;
    unsigned  omiBSIM4patGiven   :1;
    unsigned  omiBSIM4pa0Given   :1;
    unsigned  omiBSIM4pagsGiven   :1;
    unsigned  omiBSIM4pa1Given   :1;
    unsigned  omiBSIM4pa2Given   :1;
    unsigned  omiBSIM4pketaGiven   :1;
    unsigned  omiBSIM4pnsubGiven   :1;
    unsigned  omiBSIM4pndepGiven   :1;
    unsigned  omiBSIM4pnsdGiven    :1;
    unsigned  omiBSIM4pphinGiven   :1;
    unsigned  omiBSIM4pngateGiven   :1;
    unsigned  omiBSIM4pgamma1Given   :1;
    unsigned  omiBSIM4pgamma2Given   :1;
    unsigned  omiBSIM4pvbxGiven   :1;
    unsigned  omiBSIM4pvbmGiven   :1;
    unsigned  omiBSIM4pxtGiven   :1;
    unsigned  omiBSIM4pk1Given   :1;
    unsigned  omiBSIM4pkt1Given   :1;
    unsigned  omiBSIM4pkt1lGiven   :1;
    unsigned  omiBSIM4pkt2Given   :1;
    unsigned  omiBSIM4pk2Given   :1;
    unsigned  omiBSIM4pk3Given   :1;
    unsigned  omiBSIM4pk3bGiven   :1;
    unsigned  omiBSIM4pw0Given   :1;
    unsigned  omiBSIM4pdvtp0Given :1;
    unsigned  omiBSIM4pdvtp1Given :1;
    unsigned  omiBSIM4pdvtp2Given :1;        /* New DIBL/Rout */
    unsigned  omiBSIM4pdvtp3Given :1;
    unsigned  omiBSIM4pdvtp4Given :1;
    unsigned  omiBSIM4pdvtp5Given :1;
    unsigned  omiBSIM4plpe0Given   :1;
    unsigned  omiBSIM4plpebGiven   :1;
    unsigned  omiBSIM4pdvt0Given   :1;
    unsigned  omiBSIM4pdvt1Given   :1;
    unsigned  omiBSIM4pdvt2Given   :1;
    unsigned  omiBSIM4pdvt0wGiven   :1;
    unsigned  omiBSIM4pdvt1wGiven   :1;
    unsigned  omiBSIM4pdvt2wGiven   :1;
    unsigned  omiBSIM4pdroutGiven   :1;
    unsigned  omiBSIM4pdsubGiven   :1;
    unsigned  omiBSIM4pvth0Given   :1;
    unsigned  omiBSIM4puaGiven   :1;
    unsigned  omiBSIM4pua1Given   :1;
    unsigned  omiBSIM4pubGiven   :1;
    unsigned  omiBSIM4pub1Given   :1;
    unsigned  omiBSIM4pucGiven   :1;
    unsigned  omiBSIM4puc1Given   :1;
    unsigned  omiBSIM4pudGiven     :1;
    unsigned  omiBSIM4pud1Given     :1;
    unsigned  omiBSIM4pupGiven     :1;
    unsigned  omiBSIM4plpGiven     :1;
    unsigned  omiBSIM4pu0Given   :1;
    unsigned  omiBSIM4peuGiven   :1;
        unsigned  omiBSIM4pucsGiven   :1;
    unsigned  omiBSIM4puteGiven   :1;
        unsigned  omiBSIM4pucsteGiven  :1;
    unsigned  omiBSIM4pvoffGiven   :1;
    unsigned  omiBSIM4ptvoffGiven   :1;
    unsigned  omiBSIM4ptnfactorGiven  :1;         /* v4.7 Temp dep of leakage current */
    unsigned  omiBSIM4pteta0Given   :1;           /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4ptvoffcvGiven   :1;        /* v4.7 temp dep of leakage current */
    unsigned  omiBSIM4pminvGiven   :1;
    unsigned  omiBSIM4pminvcvGiven   :1;
    unsigned  omiBSIM4prdswGiven   :1;
    unsigned  omiBSIM4prswGiven   :1;
    unsigned  omiBSIM4prdwGiven   :1;
    unsigned  omiBSIM4pprwgGiven   :1;
    unsigned  omiBSIM4pprwbGiven   :1;
    unsigned  omiBSIM4pprtGiven   :1;
    unsigned  omiBSIM4peta0Given   :1;
    unsigned  omiBSIM4petabGiven   :1;
    unsigned  omiBSIM4ppclmGiven   :1;
    unsigned  omiBSIM4ppdibl1Given   :1;
    unsigned  omiBSIM4ppdibl2Given   :1;
    unsigned  omiBSIM4ppdiblbGiven   :1;
    unsigned  omiBSIM4pfproutGiven   :1;
    unsigned  omiBSIM4ppditsGiven    :1;
    unsigned  omiBSIM4ppditsdGiven    :1;
    unsigned  omiBSIM4ppscbe1Given   :1;
    unsigned  omiBSIM4ppscbe2Given   :1;
    unsigned  omiBSIM4ppvagGiven   :1;
    unsigned  omiBSIM4pdeltaGiven  :1;
    unsigned  omiBSIM4pwrGiven   :1;
    unsigned  omiBSIM4pdwgGiven   :1;
    unsigned  omiBSIM4pdwbGiven   :1;
    unsigned  omiBSIM4pb0Given   :1;
    unsigned  omiBSIM4pb1Given   :1;
    unsigned  omiBSIM4palpha0Given   :1;
    unsigned  omiBSIM4palpha1Given   :1;
    unsigned  omiBSIM4pbeta0Given   :1;
    unsigned  omiBSIM4pvfbGiven   :1;
    unsigned  omiBSIM4pagidlGiven   :1;
    unsigned  omiBSIM4pbgidlGiven   :1;
    unsigned  omiBSIM4pcgidlGiven   :1;
    unsigned  omiBSIM4pegidlGiven   :1;
    unsigned  omiBSIM4pfgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4pkgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4prgidlGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4pagislGiven   :1;
    unsigned  omiBSIM4pbgislGiven   :1;
    unsigned  omiBSIM4pcgislGiven   :1;
    unsigned  omiBSIM4pegislGiven   :1;
    unsigned  omiBSIM4pfgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4pkgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4prgislGiven   :1;    /* v4.7 New GIDL/GISL */
    unsigned  omiBSIM4paigcGiven   :1;
    unsigned  omiBSIM4pbigcGiven   :1;
    unsigned  omiBSIM4pcigcGiven   :1;
    unsigned  omiBSIM4paigsdGiven   :1;
    unsigned  omiBSIM4pbigsdGiven   :1;
    unsigned  omiBSIM4pcigsdGiven   :1;
    unsigned  omiBSIM4paigsGiven   :1;
    unsigned  omiBSIM4pbigsGiven   :1;
    unsigned  omiBSIM4pcigsGiven   :1;
    unsigned  omiBSIM4paigdGiven   :1;
    unsigned  omiBSIM4pbigdGiven   :1;
    unsigned  omiBSIM4pcigdGiven   :1;
    unsigned  omiBSIM4paigbaccGiven   :1;
    unsigned  omiBSIM4pbigbaccGiven   :1;
    unsigned  omiBSIM4pcigbaccGiven   :1;
    unsigned  omiBSIM4paigbinvGiven   :1;
    unsigned  omiBSIM4pbigbinvGiven   :1;
    unsigned  omiBSIM4pcigbinvGiven   :1;
    unsigned  omiBSIM4pnigcGiven   :1;
    unsigned  omiBSIM4pnigbinvGiven   :1;
    unsigned  omiBSIM4pnigbaccGiven   :1;
    unsigned  omiBSIM4pntoxGiven   :1;
    unsigned  omiBSIM4peigbinvGiven   :1;
    unsigned  omiBSIM4ppigcdGiven   :1;
    unsigned  omiBSIM4ppoxedgeGiven   :1;
    unsigned  omiBSIM4pxrcrg1Given   :1;
    unsigned  omiBSIM4pxrcrg2Given   :1;
    unsigned  omiBSIM4plambdaGiven    :1;
    unsigned  omiBSIM4pvtlGiven    :1;
    unsigned  omiBSIM4pxnGiven    :1;
    unsigned  omiBSIM4pvfbsdoffGiven    :1;
    unsigned  omiBSIM4ptvfbsdoffGiven    :1;

    /* CV model */
    unsigned  omiBSIM4pcgslGiven   :1;
    unsigned  omiBSIM4pcgdlGiven   :1;
    unsigned  omiBSIM4pckappasGiven   :1;
    unsigned  omiBSIM4pckappadGiven   :1;
    unsigned  omiBSIM4pcfGiven   :1;
    unsigned  omiBSIM4pclcGiven   :1;
    unsigned  omiBSIM4pcleGiven   :1;
    unsigned  omiBSIM4pvfbcvGiven   :1;
    unsigned  omiBSIM4pnoffGiven   :1;
    unsigned  omiBSIM4pvoffcvGiven :1;
    unsigned  omiBSIM4pacdeGiven   :1;
    unsigned  omiBSIM4pmoinGiven   :1;

    unsigned  omiBSIM4useFringeGiven   :1;

    unsigned  omiBSIM4tnomGiven   :1;
    unsigned  omiBSIM4cgsoGiven   :1;
    unsigned  omiBSIM4cgdoGiven   :1;
    unsigned  omiBSIM4cgboGiven   :1;
    unsigned  omiBSIM4xpartGiven   :1;
    unsigned  omiBSIM4sheetResistanceGiven   :1;

    unsigned  omiBSIM4SjctSatCurDensityGiven   :1;
    unsigned  omiBSIM4SjctSidewallSatCurDensityGiven   :1;
    unsigned  omiBSIM4SjctGateSidewallSatCurDensityGiven   :1;
    unsigned  omiBSIM4SbulkJctPotentialGiven   :1;
    unsigned  omiBSIM4SbulkJctBotGradingCoeffGiven   :1;
    unsigned  omiBSIM4SsidewallJctPotentialGiven   :1;
    unsigned  omiBSIM4SGatesidewallJctPotentialGiven   :1;
    unsigned  omiBSIM4SbulkJctSideGradingCoeffGiven   :1;
    unsigned  omiBSIM4SunitAreaJctCapGiven   :1;
    unsigned  omiBSIM4SunitLengthSidewallJctCapGiven   :1;
    unsigned  omiBSIM4SbulkJctGateSideGradingCoeffGiven   :1;
    unsigned  omiBSIM4SunitLengthGateSidewallJctCapGiven   :1;
    unsigned  omiBSIM4SjctEmissionCoeffGiven :1;
    unsigned  omiBSIM4SjctTempExponentGiven        :1;

    unsigned  omiBSIM4DjctSatCurDensityGiven   :1;
    unsigned  omiBSIM4DjctSidewallSatCurDensityGiven   :1;
    unsigned  omiBSIM4DjctGateSidewallSatCurDensityGiven   :1;
    unsigned  omiBSIM4DbulkJctPotentialGiven   :1;
    unsigned  omiBSIM4DbulkJctBotGradingCoeffGiven   :1;
    unsigned  omiBSIM4DsidewallJctPotentialGiven   :1;
    unsigned  omiBSIM4DGatesidewallJctPotentialGiven   :1;
    unsigned  omiBSIM4DbulkJctSideGradingCoeffGiven   :1;
    unsigned  omiBSIM4DunitAreaJctCapGiven   :1;
    unsigned  omiBSIM4DunitLengthSidewallJctCapGiven   :1;
    unsigned  omiBSIM4DbulkJctGateSideGradingCoeffGiven   :1;
    unsigned  omiBSIM4DunitLengthGateSidewallJctCapGiven   :1;
    unsigned  omiBSIM4DjctEmissionCoeffGiven :1;
    unsigned  omiBSIM4DjctTempExponentGiven :1;

    unsigned  omiBSIM4oxideTrapDensityAGiven  :1;
    unsigned  omiBSIM4oxideTrapDensityBGiven  :1;
    unsigned  omiBSIM4oxideTrapDensityCGiven  :1;
    unsigned  omiBSIM4emGiven  :1;
    unsigned  omiBSIM4efGiven  :1;
    unsigned  omiBSIM4afGiven  :1;
    unsigned  omiBSIM4kfGiven  :1;

    unsigned  omiBSIM4vgsMaxGiven  :1;
    unsigned  omiBSIM4vgdMaxGiven  :1;
    unsigned  omiBSIM4vgbMaxGiven  :1;
    unsigned  omiBSIM4vdsMaxGiven  :1;
    unsigned  omiBSIM4vbsMaxGiven  :1;
    unsigned  omiBSIM4vbdMaxGiven  :1;
    unsigned  omiBSIM4vgsrMaxGiven  :1;
    unsigned  omiBSIM4vgdrMaxGiven  :1;
    unsigned  omiBSIM4vgbrMaxGiven  :1;
    unsigned  omiBSIM4vbsrMaxGiven  :1;
    unsigned  omiBSIM4vbdrMaxGiven  :1;

    unsigned  omiBSIM4LintGiven   :1;
    unsigned  omiBSIM4LlGiven   :1;
    unsigned  omiBSIM4LlcGiven   :1;
    unsigned  omiBSIM4LlnGiven   :1;
    unsigned  omiBSIM4LwGiven   :1;
    unsigned  omiBSIM4LwcGiven   :1;
    unsigned  omiBSIM4LwnGiven   :1;
    unsigned  omiBSIM4LwlGiven   :1;
    unsigned  omiBSIM4LwlcGiven   :1;
    unsigned  omiBSIM4LminGiven   :1;
    unsigned  omiBSIM4LmaxGiven   :1;

    unsigned  omiBSIM4WintGiven   :1;
    unsigned  omiBSIM4WlGiven   :1;
    unsigned  omiBSIM4WlcGiven   :1;
    unsigned  omiBSIM4WlnGiven   :1;
    unsigned  omiBSIM4WwGiven   :1;
    unsigned  omiBSIM4WwcGiven   :1;
    unsigned  omiBSIM4WwnGiven   :1;
    unsigned  omiBSIM4WwlGiven   :1;
    unsigned  omiBSIM4WwlcGiven   :1;
    unsigned  omiBSIM4WminGiven   :1;
    unsigned  omiBSIM4WmaxGiven   :1;

    /* added for stress effect */
    unsigned  omiBSIM4sarefGiven   :1;
    unsigned  omiBSIM4sbrefGiven   :1;
    unsigned  omiBSIM4wlodGiven  :1;
    unsigned  omiBSIM4ku0Given   :1;
    unsigned  omiBSIM4kvsatGiven  :1;
    unsigned  omiBSIM4kvth0Given  :1;
    unsigned  omiBSIM4tku0Given   :1;
    unsigned  omiBSIM4llodku0Given   :1;
    unsigned  omiBSIM4wlodku0Given   :1;
    unsigned  omiBSIM4llodvthGiven   :1;
    unsigned  omiBSIM4wlodvthGiven   :1;
    unsigned  omiBSIM4lku0Given   :1;
    unsigned  omiBSIM4wku0Given   :1;
    unsigned  omiBSIM4pku0Given   :1;
    unsigned  omiBSIM4lkvth0Given   :1;
    unsigned  omiBSIM4wkvth0Given   :1;
    unsigned  omiBSIM4pkvth0Given   :1;
    unsigned  omiBSIM4stk2Given   :1;
    unsigned  omiBSIM4lodk2Given  :1;
    unsigned  omiBSIM4steta0Given :1;
    unsigned  omiBSIM4lodeta0Given :1;

    unsigned  omiBSIM4webGiven   :1;
    unsigned  omiBSIM4wecGiven   :1;
    unsigned  omiBSIM4kvth0weGiven   :1;
    unsigned  omiBSIM4k2weGiven   :1;
    unsigned  omiBSIM4ku0weGiven   :1;
    unsigned  omiBSIM4screfGiven   :1;
    unsigned  omiBSIM4wpemodGiven   :1;
    unsigned  omiBSIM4lkvth0weGiven   :1;
    unsigned  omiBSIM4lk2weGiven   :1;
    unsigned  omiBSIM4lku0weGiven   :1;
    unsigned  omiBSIM4wkvth0weGiven   :1;
    unsigned  omiBSIM4wk2weGiven   :1;
    unsigned  omiBSIM4wku0weGiven   :1;
    unsigned  omiBSIM4pkvth0weGiven   :1;
    unsigned  omiBSIM4pk2weGiven   :1;
    unsigned  omiBSIM4pku0weGiven   :1;


} omiBSIM4model;


#ifndef NMOS
#define NMOS 1
#define PMOS -1
#endif /*NMOS*/


/* Instance parameters */
#define omiBSIM4_W                   1
#define omiBSIM4_L                   2
#define omiBSIM4_AS                  3
#define omiBSIM4_AD                  4
#define omiBSIM4_PS                  5
#define omiBSIM4_PD                  6
#define omiBSIM4_NRS                 7
#define omiBSIM4_NRD                 8
#define omiBSIM4_OFF                 9
#define omiBSIM4_IC                  10
#define omiBSIM4_IC_VDS              11
#define omiBSIM4_IC_VGS              12
#define omiBSIM4_IC_VBS              13
#define omiBSIM4_TRNQSMOD            14
#define omiBSIM4_RBODYMOD            15
#define omiBSIM4_RGATEMOD            16
#define omiBSIM4_GEOMOD              17
#define omiBSIM4_RGEOMOD             18
#define omiBSIM4_NF                  19
#define omiBSIM4_MIN                 20
#define omiBSIM4_ACNQSMOD            22
#define omiBSIM4_RBDB                23
#define omiBSIM4_RBSB                24
#define omiBSIM4_RBPB                25
#define omiBSIM4_RBPS                26
#define omiBSIM4_RBPD                27
#define omiBSIM4_SA                  28
#define omiBSIM4_SB                  29
#define omiBSIM4_SD                  30
#define omiBSIM4_DELVTO              31
#define omiBSIM4_XGW                 32
#define omiBSIM4_NGCON               33
#define omiBSIM4_SCA                 34
#define omiBSIM4_SCB                 35
#define omiBSIM4_SCC                 36
#define omiBSIM4_SC                  37
#define omiBSIM4_M                   38
#define omiBSIM4_MULU0               39
#define omiBSIM4_WNFLAG              40

/* Global parameters */
#define omiBSIM4_MOD_TEMPEOT         65
#define omiBSIM4_MOD_LEFFEOT         66
#define omiBSIM4_MOD_WEFFEOT         67
#define omiBSIM4_MOD_UCSTE           68
#define omiBSIM4_MOD_LUCSTE          69
#define omiBSIM4_MOD_WUCSTE          70
#define omiBSIM4_MOD_PUCSTE          71
#define omiBSIM4_MOD_UCS             72
#define omiBSIM4_MOD_LUCS            73
#define omiBSIM4_MOD_WUCS            74
#define omiBSIM4_MOD_PUCS            75
#define omiBSIM4_MOD_CVCHARGEMOD     76
#define omiBSIM4_MOD_ADOS            77
#define omiBSIM4_MOD_BDOS            78
#define omiBSIM4_MOD_TEMPMOD         79
#define omiBSIM4_MOD_MTRLMOD         80
#define omiBSIM4_MOD_IGCMOD          81
#define omiBSIM4_MOD_IGBMOD          82
#define omiBSIM4_MOD_ACNQSMOD        83
#define omiBSIM4_MOD_FNOIMOD         84
#define omiBSIM4_MOD_RDSMOD          85
#define omiBSIM4_MOD_DIOMOD          86
#define omiBSIM4_MOD_PERMOD          87
#define omiBSIM4_MOD_GEOMOD          88
#define omiBSIM4_MOD_RGEOMOD         89
#define omiBSIM4_MOD_RGATEMOD        90
#define omiBSIM4_MOD_RBODYMOD        91
#define omiBSIM4_MOD_CAPMOD          92
#define omiBSIM4_MOD_TRNQSMOD        93
#define omiBSIM4_MOD_MOBMOD          94
#define omiBSIM4_MOD_TNOIMOD         95
#define omiBSIM4_MOD_EOT             96
#define omiBSIM4_MOD_VDDEOT          97
#define omiBSIM4_MOD_TOXE            98
#define omiBSIM4_MOD_CDSC            99
#define omiBSIM4_MOD_CDSCB           100
#define omiBSIM4_MOD_CIT             101
#define omiBSIM4_MOD_NFACTOR         102
#define omiBSIM4_MOD_XJ              103
#define omiBSIM4_MOD_VSAT            104
#define omiBSIM4_MOD_AT              105
#define omiBSIM4_MOD_A0              106
#define omiBSIM4_MOD_A1              107
#define omiBSIM4_MOD_A2              108
#define omiBSIM4_MOD_KETA            109
#define omiBSIM4_MOD_NSUB            110
#define omiBSIM4_MOD_PHIG            111
#define omiBSIM4_MOD_EPSRGATE        112
#define omiBSIM4_MOD_EASUB           113
#define omiBSIM4_MOD_EPSRSUB         114
#define omiBSIM4_MOD_NI0SUB          115
#define omiBSIM4_MOD_BG0SUB          116
#define omiBSIM4_MOD_TBGASUB         117
#define omiBSIM4_MOD_TBGBSUB         118
#define omiBSIM4_MOD_NDEP            119
#define omiBSIM4_MOD_NGATE           120
#define omiBSIM4_MOD_GAMMA1          121
#define omiBSIM4_MOD_GAMMA2          122
#define omiBSIM4_MOD_VBX             123
#define omiBSIM4_MOD_BINUNIT         124
#define omiBSIM4_MOD_VBM             125
#define omiBSIM4_MOD_XT              126
#define omiBSIM4_MOD_K1              129
#define omiBSIM4_MOD_KT1             130
#define omiBSIM4_MOD_KT1L            131
#define omiBSIM4_MOD_K2              132
#define omiBSIM4_MOD_KT2             133
#define omiBSIM4_MOD_K3              134
#define omiBSIM4_MOD_K3B             135
#define omiBSIM4_MOD_W0              136
#define omiBSIM4_MOD_LPE0            137
#define omiBSIM4_MOD_DVT0            138
#define omiBSIM4_MOD_DVT1            139
#define omiBSIM4_MOD_DVT2            140
#define omiBSIM4_MOD_DVT0W           141
#define omiBSIM4_MOD_DVT1W           142
#define omiBSIM4_MOD_DVT2W           143
#define omiBSIM4_MOD_DROUT           144
#define omiBSIM4_MOD_DSUB            145
#define omiBSIM4_MOD_VTH0            146
#define omiBSIM4_MOD_UA              147
#define omiBSIM4_MOD_UA1             148
#define omiBSIM4_MOD_UB              149
#define omiBSIM4_MOD_UB1             150
#define omiBSIM4_MOD_UC              151
#define omiBSIM4_MOD_UC1             152
#define omiBSIM4_MOD_U0              153
#define omiBSIM4_MOD_UTE             154
#define omiBSIM4_MOD_VOFF            155
#define omiBSIM4_MOD_DELTA           156
#define omiBSIM4_MOD_RDSW            157
#define omiBSIM4_MOD_PRT             158
#define omiBSIM4_MOD_LDD             159
#define omiBSIM4_MOD_ETA             160
#define omiBSIM4_MOD_ETA0            161
#define omiBSIM4_MOD_ETAB            162
#define omiBSIM4_MOD_PCLM            163
#define omiBSIM4_MOD_PDIBL1          164
#define omiBSIM4_MOD_PDIBL2          165
#define omiBSIM4_MOD_PSCBE1          166
#define omiBSIM4_MOD_PSCBE2          167
#define omiBSIM4_MOD_PVAG            168
#define omiBSIM4_MOD_WR              169
#define omiBSIM4_MOD_DWG             170
#define omiBSIM4_MOD_DWB             171
#define omiBSIM4_MOD_B0              172
#define omiBSIM4_MOD_B1              173
#define omiBSIM4_MOD_ALPHA0          174
#define omiBSIM4_MOD_BETA0           175
#define omiBSIM4_MOD_PDIBLB          178
#define omiBSIM4_MOD_PRWG            179
#define omiBSIM4_MOD_PRWB            180
#define omiBSIM4_MOD_CDSCD           181
#define omiBSIM4_MOD_AGS             182
#define omiBSIM4_MOD_FRINGE          184
#define omiBSIM4_MOD_CGSL            186
#define omiBSIM4_MOD_CGDL            187
#define omiBSIM4_MOD_CKAPPAS         188
#define omiBSIM4_MOD_CF              189
#define omiBSIM4_MOD_CLC             190
#define omiBSIM4_MOD_CLE             191
#define omiBSIM4_MOD_PARAMCHK        192
#define omiBSIM4_MOD_VERSION         193
#define omiBSIM4_MOD_VFBCV           194
#define omiBSIM4_MOD_ACDE            195
#define omiBSIM4_MOD_MOIN            196
#define omiBSIM4_MOD_NOFF            197
#define omiBSIM4_MOD_IJTHDFWD        198
#define omiBSIM4_MOD_ALPHA1          199
#define omiBSIM4_MOD_VFB             200
#define omiBSIM4_MOD_TOXM            201
#define omiBSIM4_MOD_TCJ             202
#define omiBSIM4_MOD_TCJSW           203
#define omiBSIM4_MOD_TCJSWG          204
#define omiBSIM4_MOD_TPB             205
#define omiBSIM4_MOD_TPBSW           206
#define omiBSIM4_MOD_TPBSWG          207
#define omiBSIM4_MOD_VOFFCV          208
#define omiBSIM4_MOD_GBMIN           209
#define omiBSIM4_MOD_RBDB            210
#define omiBSIM4_MOD_RBSB            211
#define omiBSIM4_MOD_RBPB            212
#define omiBSIM4_MOD_RBPS            213
#define omiBSIM4_MOD_RBPD            214
#define omiBSIM4_MOD_DMCG            215
#define omiBSIM4_MOD_DMCI            216
#define omiBSIM4_MOD_DMDG            217
#define omiBSIM4_MOD_XGW             218
#define omiBSIM4_MOD_XGL             219
#define omiBSIM4_MOD_RSHG            220
#define omiBSIM4_MOD_NGCON           221
#define omiBSIM4_MOD_AGIDL           222
#define omiBSIM4_MOD_BGIDL           223
#define omiBSIM4_MOD_EGIDL           224
#define omiBSIM4_MOD_IJTHSFWD        225
#define omiBSIM4_MOD_XJBVD           226
#define omiBSIM4_MOD_XJBVS           227
#define omiBSIM4_MOD_BVD             228
#define omiBSIM4_MOD_BVS             229
#define omiBSIM4_MOD_TOXP            230
#define omiBSIM4_MOD_DTOX            231
#define omiBSIM4_MOD_XRCRG1          232
#define omiBSIM4_MOD_XRCRG2          233
#define omiBSIM4_MOD_EU              234
#define omiBSIM4_MOD_IJTHSREV        235
#define omiBSIM4_MOD_IJTHDREV        236
#define omiBSIM4_MOD_MINV            237
#define omiBSIM4_MOD_VOFFL           238
#define omiBSIM4_MOD_PDITS           239
#define omiBSIM4_MOD_PDITSD          240
#define omiBSIM4_MOD_PDITSL          241
#define omiBSIM4_MOD_TNOIA           242
#define omiBSIM4_MOD_TNOIB           243
#define omiBSIM4_MOD_NTNOI           244
#define omiBSIM4_MOD_FPROUT          245
#define omiBSIM4_MOD_LPEB            246
#define omiBSIM4_MOD_DVTP0           247
#define omiBSIM4_MOD_DVTP1           248
#define omiBSIM4_MOD_CGIDL           249
#define omiBSIM4_MOD_PHIN            250
#define omiBSIM4_MOD_RDSWMIN         251
#define omiBSIM4_MOD_RSW             252
#define omiBSIM4_MOD_RDW             253
#define omiBSIM4_MOD_RDWMIN          254
#define omiBSIM4_MOD_RSWMIN          255
#define omiBSIM4_MOD_NSD             256
#define omiBSIM4_MOD_CKAPPAD         257
#define omiBSIM4_MOD_DMCGT           258
#define omiBSIM4_MOD_AIGC            259
#define omiBSIM4_MOD_BIGC            260
#define omiBSIM4_MOD_CIGC            261
#define omiBSIM4_MOD_AIGBACC         262
#define omiBSIM4_MOD_BIGBACC         263
#define omiBSIM4_MOD_CIGBACC         264
#define omiBSIM4_MOD_AIGBINV         265
#define omiBSIM4_MOD_BIGBINV         266
#define omiBSIM4_MOD_CIGBINV         267
#define omiBSIM4_MOD_NIGC            268
#define omiBSIM4_MOD_NIGBACC         269
#define omiBSIM4_MOD_NIGBINV         270
#define omiBSIM4_MOD_NTOX            271
#define omiBSIM4_MOD_TOXREF          272
#define omiBSIM4_MOD_EIGBINV         273
#define omiBSIM4_MOD_PIGCD           274
#define omiBSIM4_MOD_POXEDGE         275
#define omiBSIM4_MOD_EPSROX          276
#define omiBSIM4_MOD_AIGSD           277
#define omiBSIM4_MOD_BIGSD           278
#define omiBSIM4_MOD_CIGSD           279
#define omiBSIM4_MOD_JSWGS           280
#define omiBSIM4_MOD_JSWGD           281
#define omiBSIM4_MOD_LAMBDA          282
#define omiBSIM4_MOD_VTL             283
#define omiBSIM4_MOD_LC              284
#define omiBSIM4_MOD_XN              285
#define omiBSIM4_MOD_RNOIA           286
#define omiBSIM4_MOD_RNOIB           287
#define omiBSIM4_MOD_VFBSDOFF        288
#define omiBSIM4_MOD_LINTNOI         289
#define omiBSIM4_MOD_UD              290
#define omiBSIM4_MOD_UD1             291
#define omiBSIM4_MOD_UP              292
#define omiBSIM4_MOD_LP              293
#define omiBSIM4_MOD_TVOFF           294
#define omiBSIM4_MOD_TVFBSDOFF       295
#define omiBSIM4_MOD_MINVCV          296
#define omiBSIM4_MOD_VOFFCVL         297
#define omiBSIM4_MOD_MTRLCOMPATMOD   380

/* Length dependence */
#define omiBSIM4_MOD_LCDSC            301
#define omiBSIM4_MOD_LCDSCB           302
#define omiBSIM4_MOD_LCIT             303
#define omiBSIM4_MOD_LNFACTOR         304
#define omiBSIM4_MOD_LXJ              305
#define omiBSIM4_MOD_LVSAT            306
#define omiBSIM4_MOD_LAT              307
#define omiBSIM4_MOD_LA0              308
#define omiBSIM4_MOD_LA1              309
#define omiBSIM4_MOD_LA2              310
#define omiBSIM4_MOD_LKETA            311
#define omiBSIM4_MOD_LNSUB            312
#define omiBSIM4_MOD_LNDEP            313
#define omiBSIM4_MOD_LNGATE           315
#define omiBSIM4_MOD_LGAMMA1          316
#define omiBSIM4_MOD_LGAMMA2          317
#define omiBSIM4_MOD_LVBX             318
#define omiBSIM4_MOD_LVBM             320
#define omiBSIM4_MOD_LXT              322
#define omiBSIM4_MOD_LK1              325
#define omiBSIM4_MOD_LKT1             326
#define omiBSIM4_MOD_LKT1L            327
#define omiBSIM4_MOD_LK2              328
#define omiBSIM4_MOD_LKT2             329
#define omiBSIM4_MOD_LK3              330
#define omiBSIM4_MOD_LK3B             331
#define omiBSIM4_MOD_LW0              332
#define omiBSIM4_MOD_LLPE0            333
#define omiBSIM4_MOD_LDVT0            334
#define omiBSIM4_MOD_LDVT1            335
#define omiBSIM4_MOD_LDVT2            336
#define omiBSIM4_MOD_LDVT0W           337
#define omiBSIM4_MOD_LDVT1W           338
#define omiBSIM4_MOD_LDVT2W           339
#define omiBSIM4_MOD_LDROUT           340
#define omiBSIM4_MOD_LDSUB            341
#define omiBSIM4_MOD_LVTH0            342
#define omiBSIM4_MOD_LUA              343
#define omiBSIM4_MOD_LUA1             344
#define omiBSIM4_MOD_LUB              345
#define omiBSIM4_MOD_LUB1             346
#define omiBSIM4_MOD_LUC              347
#define omiBSIM4_MOD_LUC1             348
#define omiBSIM4_MOD_LU0              349
#define omiBSIM4_MOD_LUTE             350
#define omiBSIM4_MOD_LVOFF            351
#define omiBSIM4_MOD_LDELTA           352
#define omiBSIM4_MOD_LRDSW            353
#define omiBSIM4_MOD_LPRT             354
#define omiBSIM4_MOD_LLDD             355
#define omiBSIM4_MOD_LETA             356
#define omiBSIM4_MOD_LETA0            357
#define omiBSIM4_MOD_LETAB            358
#define omiBSIM4_MOD_LPCLM            359
#define omiBSIM4_MOD_LPDIBL1          360
#define omiBSIM4_MOD_LPDIBL2          361
#define omiBSIM4_MOD_LPSCBE1          362
#define omiBSIM4_MOD_LPSCBE2          363
#define omiBSIM4_MOD_LPVAG            364
#define omiBSIM4_MOD_LWR              365
#define omiBSIM4_MOD_LDWG             366
#define omiBSIM4_MOD_LDWB             367
#define omiBSIM4_MOD_LB0              368
#define omiBSIM4_MOD_LB1              369
#define omiBSIM4_MOD_LALPHA0          370
#define omiBSIM4_MOD_LBETA0           371
#define omiBSIM4_MOD_LPDIBLB          374
#define omiBSIM4_MOD_LPRWG            375
#define omiBSIM4_MOD_LPRWB            376
#define omiBSIM4_MOD_LCDSCD           377
#define omiBSIM4_MOD_LAGS             378

#define omiBSIM4_MOD_LFRINGE          381
#define omiBSIM4_MOD_LCGSL            383
#define omiBSIM4_MOD_LCGDL            384
#define omiBSIM4_MOD_LCKAPPAS         385
#define omiBSIM4_MOD_LCF              386
#define omiBSIM4_MOD_LCLC             387
#define omiBSIM4_MOD_LCLE             388
#define omiBSIM4_MOD_LVFBCV           389
#define omiBSIM4_MOD_LACDE            390
#define omiBSIM4_MOD_LMOIN            391
#define omiBSIM4_MOD_LNOFF            392
#define omiBSIM4_MOD_LALPHA1          394
#define omiBSIM4_MOD_LVFB             395
#define omiBSIM4_MOD_LVOFFCV          396
#define omiBSIM4_MOD_LAGIDL           397
#define omiBSIM4_MOD_LBGIDL           398
#define omiBSIM4_MOD_LEGIDL           399
#define omiBSIM4_MOD_LXRCRG1          400
#define omiBSIM4_MOD_LXRCRG2          401
#define omiBSIM4_MOD_LEU              402
#define omiBSIM4_MOD_LMINV            403
#define omiBSIM4_MOD_LPDITS           404
#define omiBSIM4_MOD_LPDITSD          405
#define omiBSIM4_MOD_LFPROUT          406
#define omiBSIM4_MOD_LLPEB            407
#define omiBSIM4_MOD_LDVTP0           408
#define omiBSIM4_MOD_LDVTP1           409
#define omiBSIM4_MOD_LCGIDL           410
#define omiBSIM4_MOD_LPHIN            411
#define omiBSIM4_MOD_LRSW             412
#define omiBSIM4_MOD_LRDW             413
#define omiBSIM4_MOD_LNSD             414
#define omiBSIM4_MOD_LCKAPPAD         415
#define omiBSIM4_MOD_LAIGC            416
#define omiBSIM4_MOD_LBIGC            417
#define omiBSIM4_MOD_LCIGC            418
#define omiBSIM4_MOD_LAIGBACC         419
#define omiBSIM4_MOD_LBIGBACC         420
#define omiBSIM4_MOD_LCIGBACC         421
#define omiBSIM4_MOD_LAIGBINV         422
#define omiBSIM4_MOD_LBIGBINV         423
#define omiBSIM4_MOD_LCIGBINV         424
#define omiBSIM4_MOD_LNIGC            425
#define omiBSIM4_MOD_LNIGBACC         426
#define omiBSIM4_MOD_LNIGBINV         427
#define omiBSIM4_MOD_LNTOX            428
#define omiBSIM4_MOD_LEIGBINV         429
#define omiBSIM4_MOD_LPIGCD           430
#define omiBSIM4_MOD_LPOXEDGE         431
#define omiBSIM4_MOD_LAIGSD           432
#define omiBSIM4_MOD_LBIGSD           433
#define omiBSIM4_MOD_LCIGSD           434

#define omiBSIM4_MOD_LLAMBDA          435
#define omiBSIM4_MOD_LVTL             436
#define omiBSIM4_MOD_LXN              437
#define omiBSIM4_MOD_LVFBSDOFF        438
#define omiBSIM4_MOD_LUD              439
#define omiBSIM4_MOD_LUD1             440
#define omiBSIM4_MOD_LUP              441
#define omiBSIM4_MOD_LLP              442
#define omiBSIM4_MOD_LMINVCV          443

#define omiBSIM4_MOD_FGIDL            444                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_KGIDL            445                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_RGIDL            446                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_FGISL            447                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_KGISL            448                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_RGISL            449                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_LFGIDL           450                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_LKGIDL           451                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_LRGIDL           452                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_LFGISL           453                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_LKGISL           454                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_LRGISL           455                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_WFGIDL           456                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_WKGIDL           457                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_WRGIDL           458                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_WFGISL           459                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_WKGISL           460                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_WRGISL           461                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_PFGIDL           462                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_PKGIDL           463                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_PRGIDL           464                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_PFGISL           465                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_PKGISL           466                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_PRGISL           467                  /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_GIDLMOD          379                        /* v4.7 New GIDL/GISL*/
#define omiBSIM4_MOD_DVTP2           468                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_DVTP3           469                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_DVTP4           470                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_DVTP5           471                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_LDVTP2          472                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_LDVTP3          473                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_LDVTP4          474                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_LDVTP5          475                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_WDVTP2          476                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_WDVTP3          477                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_WDVTP4          478                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_WDVTP5          479                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_PDVTP2          480                        /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_PDVTP3          298                         /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_PDVTP4          299                         /* v4.7 NEW DIBL/Rout*/
#define omiBSIM4_MOD_PDVTP5          300                         /* v4.7 NEW DIBL/Rout*/

/* Width dependence */
#define omiBSIM4_MOD_WCDSC            481
#define omiBSIM4_MOD_WCDSCB           482
#define omiBSIM4_MOD_WCIT             483
#define omiBSIM4_MOD_WNFACTOR         484
#define omiBSIM4_MOD_WXJ              485
#define omiBSIM4_MOD_WVSAT            486
#define omiBSIM4_MOD_WAT              487
#define omiBSIM4_MOD_WA0              488
#define omiBSIM4_MOD_WA1              489
#define omiBSIM4_MOD_WA2              490
#define omiBSIM4_MOD_WKETA            491
#define omiBSIM4_MOD_WNSUB            492
#define omiBSIM4_MOD_WNDEP            493
#define omiBSIM4_MOD_WNGATE           495
#define omiBSIM4_MOD_WGAMMA1          496
#define omiBSIM4_MOD_WGAMMA2          497
#define omiBSIM4_MOD_WVBX             498
#define omiBSIM4_MOD_WVBM             500
#define omiBSIM4_MOD_WXT              502
#define omiBSIM4_MOD_WK1              505
#define omiBSIM4_MOD_WKT1             506
#define omiBSIM4_MOD_WKT1L            507
#define omiBSIM4_MOD_WK2              508
#define omiBSIM4_MOD_WKT2             509
#define omiBSIM4_MOD_WK3              510
#define omiBSIM4_MOD_WK3B             511
#define omiBSIM4_MOD_WW0              512
#define omiBSIM4_MOD_WLPE0            513
#define omiBSIM4_MOD_WDVT0            514
#define omiBSIM4_MOD_WDVT1            515
#define omiBSIM4_MOD_WDVT2            516
#define omiBSIM4_MOD_WDVT0W           517
#define omiBSIM4_MOD_WDVT1W           518
#define omiBSIM4_MOD_WDVT2W           519
#define omiBSIM4_MOD_WDROUT           520
#define omiBSIM4_MOD_WDSUB            521
#define omiBSIM4_MOD_WVTH0            522
#define omiBSIM4_MOD_WUA              523
#define omiBSIM4_MOD_WUA1             524
#define omiBSIM4_MOD_WUB              525
#define omiBSIM4_MOD_WUB1             526
#define omiBSIM4_MOD_WUC              527
#define omiBSIM4_MOD_WUC1             528
#define omiBSIM4_MOD_WU0              529
#define omiBSIM4_MOD_WUTE             530
#define omiBSIM4_MOD_WVOFF            531
#define omiBSIM4_MOD_WDELTA           532
#define omiBSIM4_MOD_WRDSW            533
#define omiBSIM4_MOD_WPRT             534
#define omiBSIM4_MOD_WLDD             535
#define omiBSIM4_MOD_WETA             536
#define omiBSIM4_MOD_WETA0            537
#define omiBSIM4_MOD_WETAB            538
#define omiBSIM4_MOD_WPCLM            539
#define omiBSIM4_MOD_WPDIBL1          540
#define omiBSIM4_MOD_WPDIBL2          541
#define omiBSIM4_MOD_WPSCBE1          542
#define omiBSIM4_MOD_WPSCBE2          543
#define omiBSIM4_MOD_WPVAG            544
#define omiBSIM4_MOD_WWR              545
#define omiBSIM4_MOD_WDWG             546
#define omiBSIM4_MOD_WDWB             547
#define omiBSIM4_MOD_WB0              548
#define omiBSIM4_MOD_WB1              549
#define omiBSIM4_MOD_WALPHA0          550
#define omiBSIM4_MOD_WBETA0           551
#define omiBSIM4_MOD_WPDIBLB          554
#define omiBSIM4_MOD_WPRWG            555
#define omiBSIM4_MOD_WPRWB            556
#define omiBSIM4_MOD_WCDSCD           557
#define omiBSIM4_MOD_WAGS             558

#define omiBSIM4_MOD_WFRINGE          561
#define omiBSIM4_MOD_WCGSL            563
#define omiBSIM4_MOD_WCGDL            564
#define omiBSIM4_MOD_WCKAPPAS         565
#define omiBSIM4_MOD_WCF              566
#define omiBSIM4_MOD_WCLC             567
#define omiBSIM4_MOD_WCLE             568
#define omiBSIM4_MOD_WVFBCV           569
#define omiBSIM4_MOD_WACDE            570
#define omiBSIM4_MOD_WMOIN            571
#define omiBSIM4_MOD_WNOFF            572
#define omiBSIM4_MOD_WALPHA1          574
#define omiBSIM4_MOD_WVFB             575
#define omiBSIM4_MOD_WVOFFCV          576
#define omiBSIM4_MOD_WAGIDL           577
#define omiBSIM4_MOD_WBGIDL           578
#define omiBSIM4_MOD_WEGIDL           579
#define omiBSIM4_MOD_WXRCRG1          580
#define omiBSIM4_MOD_WXRCRG2          581
#define omiBSIM4_MOD_WEU              582
#define omiBSIM4_MOD_WMINV            583
#define omiBSIM4_MOD_WPDITS           584
#define omiBSIM4_MOD_WPDITSD          585
#define omiBSIM4_MOD_WFPROUT          586
#define omiBSIM4_MOD_WLPEB            587
#define omiBSIM4_MOD_WDVTP0           588
#define omiBSIM4_MOD_WDVTP1           589
#define omiBSIM4_MOD_WCGIDL           590
#define omiBSIM4_MOD_WPHIN            591
#define omiBSIM4_MOD_WRSW             592
#define omiBSIM4_MOD_WRDW             593
#define omiBSIM4_MOD_WNSD             594
#define omiBSIM4_MOD_WCKAPPAD         595
#define omiBSIM4_MOD_WAIGC            596
#define omiBSIM4_MOD_WBIGC            597
#define omiBSIM4_MOD_WCIGC            598
#define omiBSIM4_MOD_WAIGBACC         599
#define omiBSIM4_MOD_WBIGBACC         600
#define omiBSIM4_MOD_WCIGBACC         601
#define omiBSIM4_MOD_WAIGBINV         602
#define omiBSIM4_MOD_WBIGBINV         603
#define omiBSIM4_MOD_WCIGBINV         604
#define omiBSIM4_MOD_WNIGC            605
#define omiBSIM4_MOD_WNIGBACC         606
#define omiBSIM4_MOD_WNIGBINV         607
#define omiBSIM4_MOD_WNTOX            608
#define omiBSIM4_MOD_WEIGBINV         609
#define omiBSIM4_MOD_WPIGCD           610
#define omiBSIM4_MOD_WPOXEDGE         611
#define omiBSIM4_MOD_WAIGSD           612
#define omiBSIM4_MOD_WBIGSD           613
#define omiBSIM4_MOD_WCIGSD           614
#define omiBSIM4_MOD_WLAMBDA          615
#define omiBSIM4_MOD_WVTL             616
#define omiBSIM4_MOD_WXN              617
#define omiBSIM4_MOD_WVFBSDOFF        618
#define omiBSIM4_MOD_WUD              619
#define omiBSIM4_MOD_WUD1             620
#define omiBSIM4_MOD_WUP              621
#define omiBSIM4_MOD_WLP              622
#define omiBSIM4_MOD_WMINVCV          623

/* Cross-term dependence */
#define omiBSIM4_MOD_PCDSC            661
#define omiBSIM4_MOD_PCDSCB           662
#define omiBSIM4_MOD_PCIT             663
#define omiBSIM4_MOD_PNFACTOR         664
#define omiBSIM4_MOD_PXJ              665
#define omiBSIM4_MOD_PVSAT            666
#define omiBSIM4_MOD_PAT              667
#define omiBSIM4_MOD_PA0              668
#define omiBSIM4_MOD_PA1              669
#define omiBSIM4_MOD_PA2              670
#define omiBSIM4_MOD_PKETA            671
#define omiBSIM4_MOD_PNSUB            672
#define omiBSIM4_MOD_PNDEP            673
#define omiBSIM4_MOD_PNGATE           675
#define omiBSIM4_MOD_PGAMMA1          676
#define omiBSIM4_MOD_PGAMMA2          677
#define omiBSIM4_MOD_PVBX             678

#define omiBSIM4_MOD_PVBM             680

#define omiBSIM4_MOD_PXT              682
#define omiBSIM4_MOD_PK1              685
#define omiBSIM4_MOD_PKT1             686
#define omiBSIM4_MOD_PKT1L            687
#define omiBSIM4_MOD_PK2              688
#define omiBSIM4_MOD_PKT2             689
#define omiBSIM4_MOD_PK3              690
#define omiBSIM4_MOD_PK3B             691
#define omiBSIM4_MOD_PW0              692
#define omiBSIM4_MOD_PLPE0            693

#define omiBSIM4_MOD_PDVT0            694
#define omiBSIM4_MOD_PDVT1            695
#define omiBSIM4_MOD_PDVT2            696

#define omiBSIM4_MOD_PDVT0W           697
#define omiBSIM4_MOD_PDVT1W           698
#define omiBSIM4_MOD_PDVT2W           699

#define omiBSIM4_MOD_PDROUT           700
#define omiBSIM4_MOD_PDSUB            701
#define omiBSIM4_MOD_PVTH0            702
#define omiBSIM4_MOD_PUA              703
#define omiBSIM4_MOD_PUA1             704
#define omiBSIM4_MOD_PUB              705
#define omiBSIM4_MOD_PUB1             706
#define omiBSIM4_MOD_PUC              707
#define omiBSIM4_MOD_PUC1             708
#define omiBSIM4_MOD_PU0              709
#define omiBSIM4_MOD_PUTE             710
#define omiBSIM4_MOD_PVOFF            711
#define omiBSIM4_MOD_PDELTA           712
#define omiBSIM4_MOD_PRDSW            713
#define omiBSIM4_MOD_PPRT             714
#define omiBSIM4_MOD_PLDD             715
#define omiBSIM4_MOD_PETA             716
#define omiBSIM4_MOD_PETA0            717
#define omiBSIM4_MOD_PETAB            718
#define omiBSIM4_MOD_PPCLM            719
#define omiBSIM4_MOD_PPDIBL1          720
#define omiBSIM4_MOD_PPDIBL2          721
#define omiBSIM4_MOD_PPSCBE1          722
#define omiBSIM4_MOD_PPSCBE2          723
#define omiBSIM4_MOD_PPVAG            724
#define omiBSIM4_MOD_PWR              725
#define omiBSIM4_MOD_PDWG             726
#define omiBSIM4_MOD_PDWB             727
#define omiBSIM4_MOD_PB0              728
#define omiBSIM4_MOD_PB1              729
#define omiBSIM4_MOD_PALPHA0          730
#define omiBSIM4_MOD_PBETA0           731
#define omiBSIM4_MOD_PPDIBLB          734

#define omiBSIM4_MOD_PPRWG            735
#define omiBSIM4_MOD_PPRWB            736

#define omiBSIM4_MOD_PCDSCD           737
#define omiBSIM4_MOD_PAGS             738

#define omiBSIM4_MOD_PFRINGE          741
#define omiBSIM4_MOD_PCGSL            743
#define omiBSIM4_MOD_PCGDL            744
#define omiBSIM4_MOD_PCKAPPAS         745
#define omiBSIM4_MOD_PCF              746
#define omiBSIM4_MOD_PCLC             747
#define omiBSIM4_MOD_PCLE             748
#define omiBSIM4_MOD_PVFBCV           749
#define omiBSIM4_MOD_PACDE            750
#define omiBSIM4_MOD_PMOIN            751
#define omiBSIM4_MOD_PNOFF            752
#define omiBSIM4_MOD_PALPHA1          754
#define omiBSIM4_MOD_PVFB             755
#define omiBSIM4_MOD_PVOFFCV          756
#define omiBSIM4_MOD_PAGIDL           757
#define omiBSIM4_MOD_PBGIDL           758
#define omiBSIM4_MOD_PEGIDL           759
#define omiBSIM4_MOD_PXRCRG1          760
#define omiBSIM4_MOD_PXRCRG2          761
#define omiBSIM4_MOD_PEU              762
#define omiBSIM4_MOD_PMINV            763
#define omiBSIM4_MOD_PPDITS           764
#define omiBSIM4_MOD_PPDITSD          765
#define omiBSIM4_MOD_PFPROUT          766
#define omiBSIM4_MOD_PLPEB            767
#define omiBSIM4_MOD_PDVTP0           768
#define omiBSIM4_MOD_PDVTP1           769
#define omiBSIM4_MOD_PCGIDL           770
#define omiBSIM4_MOD_PPHIN            771
#define omiBSIM4_MOD_PRSW             772
#define omiBSIM4_MOD_PRDW             773
#define omiBSIM4_MOD_PNSD             774
#define omiBSIM4_MOD_PCKAPPAD         775
#define omiBSIM4_MOD_PAIGC            776
#define omiBSIM4_MOD_PBIGC            777
#define omiBSIM4_MOD_PCIGC            778
#define omiBSIM4_MOD_PAIGBACC         779
#define omiBSIM4_MOD_PBIGBACC         780
#define omiBSIM4_MOD_PCIGBACC         781
#define omiBSIM4_MOD_PAIGBINV         782
#define omiBSIM4_MOD_PBIGBINV         783
#define omiBSIM4_MOD_PCIGBINV         784
#define omiBSIM4_MOD_PNIGC            785
#define omiBSIM4_MOD_PNIGBACC         786
#define omiBSIM4_MOD_PNIGBINV         787
#define omiBSIM4_MOD_PNTOX            788
#define omiBSIM4_MOD_PEIGBINV         789
#define omiBSIM4_MOD_PPIGCD           790
#define omiBSIM4_MOD_PPOXEDGE         791
#define omiBSIM4_MOD_PAIGSD           792
#define omiBSIM4_MOD_PBIGSD           793
#define omiBSIM4_MOD_PCIGSD           794

#define omiBSIM4_MOD_SAREF            795
#define omiBSIM4_MOD_SBREF            796
#define omiBSIM4_MOD_KU0              797
#define omiBSIM4_MOD_KVSAT            798
#define omiBSIM4_MOD_TKU0             799
#define omiBSIM4_MOD_LLODKU0          800
#define omiBSIM4_MOD_WLODKU0          801
#define omiBSIM4_MOD_LLODVTH          802
#define omiBSIM4_MOD_WLODVTH          803
#define omiBSIM4_MOD_LKU0             804
#define omiBSIM4_MOD_WKU0             805
#define omiBSIM4_MOD_PKU0             806
#define omiBSIM4_MOD_KVTH0            807
#define omiBSIM4_MOD_LKVTH0           808
#define omiBSIM4_MOD_WKVTH0           809
#define omiBSIM4_MOD_PKVTH0           810
#define omiBSIM4_MOD_WLOD                   811
#define omiBSIM4_MOD_STK2                   812
#define omiBSIM4_MOD_LODK2                   813
#define omiBSIM4_MOD_STETA0           814
#define omiBSIM4_MOD_LODETA0           815

#define omiBSIM4_MOD_WEB              816
#define omiBSIM4_MOD_WEC              817
#define omiBSIM4_MOD_KVTH0WE          818
#define omiBSIM4_MOD_K2WE             819
#define omiBSIM4_MOD_KU0WE            820
#define omiBSIM4_MOD_SCREF            821
#define omiBSIM4_MOD_WPEMOD           822
#define omiBSIM4_MOD_PMINVCV          823

#define omiBSIM4_MOD_PLAMBDA          825
#define omiBSIM4_MOD_PVTL             826
#define omiBSIM4_MOD_PXN              827
#define omiBSIM4_MOD_PVFBSDOFF        828

#define omiBSIM4_MOD_TNOM             831
#define omiBSIM4_MOD_CGSO             832
#define omiBSIM4_MOD_CGDO             833
#define omiBSIM4_MOD_CGBO             834
#define omiBSIM4_MOD_XPART            835
#define omiBSIM4_MOD_RSH              836
#define omiBSIM4_MOD_JSS              837
#define omiBSIM4_MOD_PBS              838
#define omiBSIM4_MOD_MJS              839
#define omiBSIM4_MOD_PBSWS            840
#define omiBSIM4_MOD_MJSWS            841
#define omiBSIM4_MOD_CJS              842
#define omiBSIM4_MOD_CJSWS            843
#define omiBSIM4_MOD_NMOS             844
#define omiBSIM4_MOD_PMOS             845
#define omiBSIM4_MOD_NOIA             846
#define omiBSIM4_MOD_NOIB             847
#define omiBSIM4_MOD_NOIC             848
#define omiBSIM4_MOD_LINT             849
#define omiBSIM4_MOD_LL               850
#define omiBSIM4_MOD_LLN              851
#define omiBSIM4_MOD_LW               852
#define omiBSIM4_MOD_LWN              853
#define omiBSIM4_MOD_LWL              854
#define omiBSIM4_MOD_LMIN             855
#define omiBSIM4_MOD_LMAX             856
#define omiBSIM4_MOD_WINT             857
#define omiBSIM4_MOD_WL               858
#define omiBSIM4_MOD_WLN              859
#define omiBSIM4_MOD_WW               860
#define omiBSIM4_MOD_WWN              861
#define omiBSIM4_MOD_WWL              862
#define omiBSIM4_MOD_WMIN             863
#define omiBSIM4_MOD_WMAX             864
#define omiBSIM4_MOD_DWC              865
#define omiBSIM4_MOD_DLC              866
#define omiBSIM4_MOD_XL               867
#define omiBSIM4_MOD_XW               868
#define omiBSIM4_MOD_EM               869
#define omiBSIM4_MOD_EF               870
#define omiBSIM4_MOD_AF               871
#define omiBSIM4_MOD_KF               872
#define omiBSIM4_MOD_NJS              873
#define omiBSIM4_MOD_XTIS             874
#define omiBSIM4_MOD_PBSWGS           875
#define omiBSIM4_MOD_MJSWGS           876
#define omiBSIM4_MOD_CJSWGS           877
#define omiBSIM4_MOD_JSWS             878
#define omiBSIM4_MOD_LLC              879
#define omiBSIM4_MOD_LWC              880
#define omiBSIM4_MOD_LWLC             881
#define omiBSIM4_MOD_WLC              882
#define omiBSIM4_MOD_WWC              883
#define omiBSIM4_MOD_WWLC             884
#define omiBSIM4_MOD_DWJ              885
#define omiBSIM4_MOD_JSD              886
#define omiBSIM4_MOD_PBD              887
#define omiBSIM4_MOD_MJD              888
#define omiBSIM4_MOD_PBSWD            889
#define omiBSIM4_MOD_MJSWD            890
#define omiBSIM4_MOD_CJD              891
#define omiBSIM4_MOD_CJSWD            892
#define omiBSIM4_MOD_NJD              893
#define omiBSIM4_MOD_XTID             894
#define omiBSIM4_MOD_PBSWGD           895
#define omiBSIM4_MOD_MJSWGD           896
#define omiBSIM4_MOD_CJSWGD           897
#define omiBSIM4_MOD_JSWD             898
#define omiBSIM4_MOD_DLCIG            899

/* trap-assisted tunneling */

#define omiBSIM4_MOD_JTSS             900
#define omiBSIM4_MOD_JTSD                   901
#define omiBSIM4_MOD_JTSSWS           902
#define omiBSIM4_MOD_JTSSWD           903
#define omiBSIM4_MOD_JTSSWGS           904
#define omiBSIM4_MOD_JTSSWGD           905
#define omiBSIM4_MOD_NJTS                    906
#define omiBSIM4_MOD_NJTSSW           907
#define omiBSIM4_MOD_NJTSSWG           908
#define omiBSIM4_MOD_XTSS                   909
#define omiBSIM4_MOD_XTSD                   910
#define omiBSIM4_MOD_XTSSWS           911
#define omiBSIM4_MOD_XTSSWD           912
#define omiBSIM4_MOD_XTSSWGS           913
#define omiBSIM4_MOD_XTSSWGD           914
#define omiBSIM4_MOD_TNJTS                   915
#define omiBSIM4_MOD_TNJTSSW           916
#define omiBSIM4_MOD_TNJTSSWG           917
#define omiBSIM4_MOD_VTSS             918
#define omiBSIM4_MOD_VTSD                   919
#define omiBSIM4_MOD_VTSSWS           920
#define omiBSIM4_MOD_VTSSWD           921
#define omiBSIM4_MOD_VTSSWGS           922
#define omiBSIM4_MOD_VTSSWGD           923
#define omiBSIM4_MOD_PUD              924
#define omiBSIM4_MOD_PUD1             925
#define omiBSIM4_MOD_PUP              926
#define omiBSIM4_MOD_PLP              927
#define omiBSIM4_MOD_JTWEFF           928

/* device questions */
#define omiBSIM4_DNODE                945
#define omiBSIM4_GNODEEXT             946
#define omiBSIM4_SNODE                947
#define omiBSIM4_BNODE                948
#define omiBSIM4_DNODEPRIME           949
#define omiBSIM4_GNODEPRIME           950
#define omiBSIM4_GNODEMIDE            951
#define omiBSIM4_GNODEMID             952
#define omiBSIM4_SNODEPRIME           953
#define omiBSIM4_BNODEPRIME           954
#define omiBSIM4_DBNODE               955
#define omiBSIM4_SBNODE               956
#define omiBSIM4_VBD                  957
#define omiBSIM4_VBS                  958
#define omiBSIM4_VGS                  959
#define omiBSIM4_VDS                  960
#define omiBSIM4_CD                   961
#define omiBSIM4_CBS                  962
#define omiBSIM4_CBD                  963
#define omiBSIM4_GM                   964
#define omiBSIM4_GDS                  965
#define omiBSIM4_GMBS                 966
#define omiBSIM4_GBD                  967
#define omiBSIM4_GBS                  968
#define omiBSIM4_QB                   969
#define omiBSIM4_CQB                  970
#define omiBSIM4_QG                   971
#define omiBSIM4_CQG                  972
#define omiBSIM4_QD                   973
#define omiBSIM4_CQD                  974
#define omiBSIM4_CGGB                 975
#define omiBSIM4_CGDB                 976
#define omiBSIM4_CGSB                 977
#define omiBSIM4_CBGB                 978
#define omiBSIM4_CAPBD                979
#define omiBSIM4_CQBD                 980
#define omiBSIM4_CAPBS                981
#define omiBSIM4_CQBS                 982
#define omiBSIM4_CDGB                 983
#define omiBSIM4_CDDB                 984
#define omiBSIM4_CDSB                 985
#define omiBSIM4_VON                  986
#define omiBSIM4_VDSAT                987
#define omiBSIM4_QBS                  988
#define omiBSIM4_QBD                  989
#define omiBSIM4_SOURCECONDUCT        990
#define omiBSIM4_DRAINCONDUCT         991
#define omiBSIM4_CBDB                 992
#define omiBSIM4_CBSB                 993
#define omiBSIM4_CSUB                   994
#define omiBSIM4_QINV                   995
#define omiBSIM4_IGIDL                   996
#define omiBSIM4_CSGB                 997
#define omiBSIM4_CSDB                 998
#define omiBSIM4_CSSB                 999
#define omiBSIM4_CGBB                 1000
#define omiBSIM4_CDBB                 1001
#define omiBSIM4_CSBB                 1002
#define omiBSIM4_CBBB                 1003
#define omiBSIM4_QS                   1004
#define omiBSIM4_IGISL                   1005
#define omiBSIM4_IGS                   1006
#define omiBSIM4_IGD                   1007
#define omiBSIM4_IGB                   1008
#define omiBSIM4_IGCS                   1009
#define omiBSIM4_IGCD                   1010
#define omiBSIM4_QDEF                   1011
#define omiBSIM4_DELVT0                   1012
#define omiBSIM4_GCRG                 1013
#define omiBSIM4_GTAU                 1014

#define omiBSIM4_MOD_LTVOFF           1051
#define omiBSIM4_MOD_LTVFBSDOFF       1052
#define omiBSIM4_MOD_WTVOFF           1053
#define omiBSIM4_MOD_WTVFBSDOFF       1054
#define omiBSIM4_MOD_PTVOFF           1055
#define omiBSIM4_MOD_PTVFBSDOFF       1056

#define omiBSIM4_MOD_LKVTH0WE          1061
#define omiBSIM4_MOD_LK2WE             1062
#define omiBSIM4_MOD_LKU0WE                1063
#define omiBSIM4_MOD_WKVTH0WE          1064
#define omiBSIM4_MOD_WK2WE             1065
#define omiBSIM4_MOD_WKU0WE                1066
#define omiBSIM4_MOD_PKVTH0WE          1067
#define omiBSIM4_MOD_PK2WE             1068
#define omiBSIM4_MOD_PKU0WE                1069

#define omiBSIM4_MOD_RBPS0               1101
#define omiBSIM4_MOD_RBPSL               1102
#define omiBSIM4_MOD_RBPSW               1103
#define omiBSIM4_MOD_RBPSNF              1104
#define omiBSIM4_MOD_RBPD0               1105
#define omiBSIM4_MOD_RBPDL               1106
#define omiBSIM4_MOD_RBPDW               1107
#define omiBSIM4_MOD_RBPDNF              1108

#define omiBSIM4_MOD_RBPBX0              1109
#define omiBSIM4_MOD_RBPBXL              1110
#define omiBSIM4_MOD_RBPBXW              1111
#define omiBSIM4_MOD_RBPBXNF             1112
#define omiBSIM4_MOD_RBPBY0              1113
#define omiBSIM4_MOD_RBPBYL              1114
#define omiBSIM4_MOD_RBPBYW              1115
#define omiBSIM4_MOD_RBPBYNF             1116

#define omiBSIM4_MOD_RBSBX0              1117
#define omiBSIM4_MOD_RBSBY0              1118
#define omiBSIM4_MOD_RBDBX0              1119
#define omiBSIM4_MOD_RBDBY0              1120

#define omiBSIM4_MOD_RBSDBXL             1121
#define omiBSIM4_MOD_RBSDBXW             1122
#define omiBSIM4_MOD_RBSDBXNF            1123
#define omiBSIM4_MOD_RBSDBYL             1124
#define omiBSIM4_MOD_RBSDBYW             1125
#define omiBSIM4_MOD_RBSDBYNF            1126

#define omiBSIM4_MOD_AGISL               1200
#define omiBSIM4_MOD_BGISL               1201
#define omiBSIM4_MOD_EGISL               1202
#define omiBSIM4_MOD_CGISL               1203
#define omiBSIM4_MOD_LAGISL              1204
#define omiBSIM4_MOD_LBGISL              1205
#define omiBSIM4_MOD_LEGISL              1206
#define omiBSIM4_MOD_LCGISL              1207
#define omiBSIM4_MOD_WAGISL              1208
#define omiBSIM4_MOD_WBGISL              1209
#define omiBSIM4_MOD_WEGISL              1210
#define omiBSIM4_MOD_WCGISL              1211
#define omiBSIM4_MOD_PAGISL              1212
#define omiBSIM4_MOD_PBGISL              1213
#define omiBSIM4_MOD_PEGISL              1214
#define omiBSIM4_MOD_PCGISL              1215

#define omiBSIM4_MOD_AIGS                1220
#define omiBSIM4_MOD_BIGS                1221
#define omiBSIM4_MOD_CIGS                1222
#define omiBSIM4_MOD_LAIGS               1223
#define omiBSIM4_MOD_LBIGS               1224
#define omiBSIM4_MOD_LCIGS               1225
#define omiBSIM4_MOD_WAIGS               1226
#define omiBSIM4_MOD_WBIGS               1227
#define omiBSIM4_MOD_WCIGS               1228
#define omiBSIM4_MOD_PAIGS               1229
#define omiBSIM4_MOD_PBIGS               1230
#define omiBSIM4_MOD_PCIGS               1231
#define omiBSIM4_MOD_AIGD                1232
#define omiBSIM4_MOD_BIGD                1233
#define omiBSIM4_MOD_CIGD                1234
#define omiBSIM4_MOD_LAIGD               1235
#define omiBSIM4_MOD_LBIGD               1236
#define omiBSIM4_MOD_LCIGD               1237
#define omiBSIM4_MOD_WAIGD               1238
#define omiBSIM4_MOD_WBIGD               1239
#define omiBSIM4_MOD_WCIGD               1240
#define omiBSIM4_MOD_PAIGD               1241
#define omiBSIM4_MOD_PBIGD               1242
#define omiBSIM4_MOD_PCIGD               1243
#define omiBSIM4_MOD_DLCIGD              1244

#define omiBSIM4_MOD_NJTSD               1250
#define omiBSIM4_MOD_NJTSSWD             1251
#define omiBSIM4_MOD_NJTSSWGD            1252
#define omiBSIM4_MOD_TNJTSD              1253
#define omiBSIM4_MOD_TNJTSSWD            1254
#define omiBSIM4_MOD_TNJTSSWGD           1255

/* v4.7 temp dep of leakage current  */

#define omiBSIM4_MOD_TNFACTOR          1256
#define omiBSIM4_MOD_TETA0                    1257
#define omiBSIM4_MOD_TVOFFCV           1258
#define omiBSIM4_MOD_LTNFACTOR         1260
#define omiBSIM4_MOD_LTETA0            1261
#define omiBSIM4_MOD_LTVOFFCV          1262
#define omiBSIM4_MOD_WTNFACTOR         1264
#define omiBSIM4_MOD_WTETA0            1265
#define omiBSIM4_MOD_WTVOFFCV          1266
#define omiBSIM4_MOD_PTNFACTOR         1268
#define omiBSIM4_MOD_PTETA0            1269
#define omiBSIM4_MOD_PTVOFFCV          1270

/* tnoiMod=2 (v4.7) */
#define omiBSIM4_MOD_TNOIC             1272
#define omiBSIM4_MOD_RNOIC             1273

#define omiBSIM4_MOD_VGS_MAX           1301
#define omiBSIM4_MOD_VGD_MAX           1302
#define omiBSIM4_MOD_VGB_MAX           1303
#define omiBSIM4_MOD_VDS_MAX           1304
#define omiBSIM4_MOD_VBS_MAX           1305
#define omiBSIM4_MOD_VBD_MAX           1306
#define omiBSIM4_MOD_VGSR_MAX          1307
#define omiBSIM4_MOD_VGDR_MAX          1308
#define omiBSIM4_MOD_VGBR_MAX          1309
#define omiBSIM4_MOD_VBSR_MAX          1310
#define omiBSIM4_MOD_VBDR_MAX          1311

#include "omibsim4ext.h"

extern void omiBSIM4evaluate(double,double,double,omiBSIM4instance*,omiBSIM4model*,
        double*,double*,double*, double*, double*, double*, double*,
        double*, double*, double*, double*, double*, double*, double*,
        double*, double*, double*, double*, CKTcircuit*);
extern int omiBSIM4debug(omiBSIM4model*, omiBSIM4instance*, CKTcircuit*, int);
extern int omiBSIM4checkModel(omiBSIM4model*, omiBSIM4instance*, CKTcircuit*);
extern int omiBSIM4PAeffGeo(double, int, int, double, double, double, double, double *, double *, double *, double *);
extern int omiBSIM4RdseffGeo(double, int, int, int, double, double, double, double, double, int, double *);
extern int omiBSIM4RdsEndIso(double, double, double, double, double, double, int, int, double *);
extern int omiBSIM4RdsEndSha(double, double, double, double, double, double, int, int, double *);

#endif /*omiBSIM4*/
