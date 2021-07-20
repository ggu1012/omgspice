/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4set.c of BSIM4.7.0.
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
#include "ngspice/jobdefs.h"
#include "ngspice/ftedefs.h"
#include "ngspice/smpdefs.h"
#include "ngspice/cktdefs.h"
#include "omibsim4def.h"
#include "ngspice/const.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"

#ifdef USE_OMP
#include "ngspice/cpextern.h"
#endif

#define MAX_EXP 5.834617425e14
#define MIN_EXP 1.713908431e-15
#define EXP_THRESHOLD 34.0
#define EPS0 8.85418e-12
#define EPSSI 1.03594e-10
#define PI 3.141592654
#define Charge_q 1.60219e-19

int
omiBSIM4setup(
SMPmatrix *matrix,
GENmodel *inModel,
CKTcircuit *ckt,
int *states)
{
omiBSIM4model *model = (omiBSIM4model*)inModel;
omiBSIM4instance *here;
int error;
CKTnode *tmp;
int    noiseAnalGiven = 0, createNode;  /* Criteria for new node creation */
double Rtot, DMCGeff, DMCIeff, DMDGeff;
JOB   *job;

#ifdef USE_OMP
int idx, InstCount;
omiBSIM4instance **InstArray;
#endif

    /* Search for a noise analysis request */
    for (job = ((TSKtask *)ft_curckt->ci_curTask)->jobs;job;job = job->JOBnextJob) {
        if(strcmp(job->JOBname,"Noise Analysis")==0) {
            noiseAnalGiven = 1;
            break;
        }
    }

    /*  loop through all the omiBSIM4 device models */
    for( ; model != NULL; model = omiBSIM4nextModel(model))
    {   /* process defaults of model parameters */
        if (!model->omiBSIM4typeGiven)
            model->omiBSIM4type = NMOS;     

        if (!model->omiBSIM4mobModGiven) 
            model->omiBSIM4mobMod = 0;
        else if ((model->omiBSIM4mobMod != 0) && (model->omiBSIM4mobMod != 1)
                 && (model->omiBSIM4mobMod != 2)&& (model->omiBSIM4mobMod != 3))
        {   model->omiBSIM4mobMod = 0;
            printf("Warning: mobMod has been set to its default value: 0.\n");
        }

        if (!model->omiBSIM4binUnitGiven) 
            model->omiBSIM4binUnit = 1;
        if (!model->omiBSIM4paramChkGiven) 
            model->omiBSIM4paramChk = 1;

        if (!model->omiBSIM4dioModGiven)
            model->omiBSIM4dioMod = 1;
        else if ((model->omiBSIM4dioMod != 0) && (model->omiBSIM4dioMod != 1)
            && (model->omiBSIM4dioMod != 2))
        {   model->omiBSIM4dioMod = 1;
            printf("Warning: dioMod has been set to its default value: 1.\n");
        }

        if (!model->omiBSIM4cvchargeModGiven) 
            model->omiBSIM4cvchargeMod = 0;
        if (!model->omiBSIM4capModGiven) 
            model->omiBSIM4capMod = 2;
        else if ((model->omiBSIM4capMod != 0) && (model->omiBSIM4capMod != 1)
            && (model->omiBSIM4capMod != 2))
        {   model->omiBSIM4capMod = 2;
            printf("Warning: capMod has been set to its default value: 2.\n");
        }

        if (!model->omiBSIM4rdsModGiven)
            model->omiBSIM4rdsMod = 0;
        else if ((model->omiBSIM4rdsMod != 0) && (model->omiBSIM4rdsMod != 1))
        {   model->omiBSIM4rdsMod = 0;
            printf("Warning: rdsMod has been set to its default value: 0.\n");
        }
        if (!model->omiBSIM4rbodyModGiven)
            model->omiBSIM4rbodyMod = 0;
        else if ((model->omiBSIM4rbodyMod != 0) && (model->omiBSIM4rbodyMod != 1) && (model->omiBSIM4rbodyMod != 2))
        {   model->omiBSIM4rbodyMod = 0;
            printf("Warning: rbodyMod has been set to its default value: 0.\n");
        }

        if (!model->omiBSIM4rgateModGiven)
            model->omiBSIM4rgateMod = 0;
        else if ((model->omiBSIM4rgateMod != 0) && (model->omiBSIM4rgateMod != 1)
            && (model->omiBSIM4rgateMod != 2) && (model->omiBSIM4rgateMod != 3))
        {   model->omiBSIM4rgateMod = 0;
            printf("Warning: rgateMod has been set to its default value: 0.\n");
        }

        if (!model->omiBSIM4perModGiven)
            model->omiBSIM4perMod = 1;
        else if ((model->omiBSIM4perMod != 0) && (model->omiBSIM4perMod != 1))
        {   model->omiBSIM4perMod = 1;
            printf("Warning: perMod has been set to its default value: 1.\n");
        }

        if (!model->omiBSIM4geoModGiven)
            model->omiBSIM4geoMod = 0;

        if (!model->omiBSIM4rgeoModGiven)
            model->omiBSIM4rgeoMod = 0;
        else if ((model->omiBSIM4rgeoMod != 0) && (model->omiBSIM4rgeoMod != 1))
        {   model->omiBSIM4rgeoMod = 1;
            printf("Warning: rgeoMod has been set to its default value: 1.\n");
        }
        if (!model->omiBSIM4fnoiModGiven) 
            model->omiBSIM4fnoiMod = 1;
        else if ((model->omiBSIM4fnoiMod != 0) && (model->omiBSIM4fnoiMod != 1))
        {   model->omiBSIM4fnoiMod = 1;
            printf("Warning: fnoiMod has been set to its default value: 1.\n");
        }
        if (!model->omiBSIM4tnoiModGiven)
            model->omiBSIM4tnoiMod = 0; /* WDLiu: tnoiMod=1 needs to set internal S/D nodes */
        else if ((model->omiBSIM4tnoiMod != 0) && (model->omiBSIM4tnoiMod != 1) && (model->omiBSIM4tnoiMod != 2))  /* v4.7 */
        {   model->omiBSIM4tnoiMod = 0;
            printf("Warning: tnoiMod has been set to its default value: 0.\n");
        }

        if (!model->omiBSIM4trnqsModGiven)
            model->omiBSIM4trnqsMod = 0; 
        else if ((model->omiBSIM4trnqsMod != 0) && (model->omiBSIM4trnqsMod != 1))
        {   model->omiBSIM4trnqsMod = 0;
            printf("Warning: trnqsMod has been set to its default value: 0.\n");
        }
        if (!model->omiBSIM4acnqsModGiven)
            model->omiBSIM4acnqsMod = 0;
        else if ((model->omiBSIM4acnqsMod != 0) && (model->omiBSIM4acnqsMod != 1))
        {   model->omiBSIM4acnqsMod = 0;
            printf("Warning: acnqsMod has been set to its default value: 0.\n");
        }

        if (!model->omiBSIM4mtrlModGiven)   
            model->omiBSIM4mtrlMod = 0;
        else if((model->omiBSIM4mtrlMod != 0) && (model->omiBSIM4mtrlMod != 1))
        {
            model->omiBSIM4mtrlMod = 0;
            printf("Warning: mtrlMod has been set to its default value: 0.\n");
        }
        if (!model->omiBSIM4mtrlCompatModGiven)   
            model->omiBSIM4mtrlCompatMod = 0;
        else if((model->omiBSIM4mtrlCompatMod != 0) && (model->omiBSIM4mtrlCompatMod != 1))
        {
            model->omiBSIM4mtrlCompatMod = 0;
            printf("Warning: mtrlCompatMod has been set to its default value: 0.\n");
        }

        if (!model->omiBSIM4igcModGiven)
            model->omiBSIM4igcMod = 0;
        else if ((model->omiBSIM4igcMod != 0) && (model->omiBSIM4igcMod != 1)
                  && (model->omiBSIM4igcMod != 2))
        {   model->omiBSIM4igcMod = 0;
            printf("Warning: igcMod has been set to its default value: 0.\n");
        }
        if (!model->omiBSIM4igbModGiven)
            model->omiBSIM4igbMod = 0;
        else if ((model->omiBSIM4igbMod != 0) && (model->omiBSIM4igbMod != 1))
        {   model->omiBSIM4igbMod = 0;
            printf("Warning: igbMod has been set to its default value: 0.\n");
        }
        if (!model->omiBSIM4tempModGiven)
            model->omiBSIM4tempMod = 0;
        else if ((model->omiBSIM4tempMod != 0) && (model->omiBSIM4tempMod != 1) 
                  && (model->omiBSIM4tempMod != 2) && (model->omiBSIM4tempMod != 3))
        {   model->omiBSIM4tempMod = 0;
            printf("Warning: tempMod has been set to its default value: 0.\n");
        }

        if (!model->omiBSIM4versionGiven) 
            model->omiBSIM4version = copy("4.7.0");
        if (!model->omiBSIM4toxrefGiven)
            model->omiBSIM4toxref = 30.0e-10;
        if (!model->omiBSIM4eotGiven)
            model->omiBSIM4eot = 15.0e-10;
        if (!model->omiBSIM4vddeotGiven)
            model->omiBSIM4vddeot = (model->omiBSIM4type == NMOS) ? 1.5 : -1.5;
        if (!model->omiBSIM4tempeotGiven)
            model->omiBSIM4tempeot = 300.15;
        if (!model->omiBSIM4leffeotGiven)
            model->omiBSIM4leffeot = 1;
        if (!model->omiBSIM4weffeotGiven)
            model->omiBSIM4weffeot = 10;        
        if (!model->omiBSIM4adosGiven)
            model->omiBSIM4ados = 1.0;
        if (!model->omiBSIM4bdosGiven)
            model->omiBSIM4bdos = 1.0;
        if (!model->omiBSIM4toxeGiven)
            model->omiBSIM4toxe = 30.0e-10;
        if (!model->omiBSIM4toxpGiven)
            model->omiBSIM4toxp = model->omiBSIM4toxe;
        if (!model->omiBSIM4toxmGiven)
            model->omiBSIM4toxm = model->omiBSIM4toxe;
        if (!model->omiBSIM4dtoxGiven)
            model->omiBSIM4dtox = 0.0;
        if (!model->omiBSIM4epsroxGiven)
            model->omiBSIM4epsrox = 3.9;

        if (!model->omiBSIM4cdscGiven)
            model->omiBSIM4cdsc = 2.4e-4;   /* unit Q/V/m^2  */
        if (!model->omiBSIM4cdscbGiven)
            model->omiBSIM4cdscb = 0.0;   /* unit Q/V/m^2  */    
        if (!model->omiBSIM4cdscdGiven)
            model->omiBSIM4cdscd = 0.0;   /* unit Q/V/m^2  */
        if (!model->omiBSIM4citGiven)
            model->omiBSIM4cit = 0.0;   /* unit Q/V/m^2  */
        if (!model->omiBSIM4nfactorGiven)
            model->omiBSIM4nfactor = 1.0;
        if (!model->omiBSIM4xjGiven)
            model->omiBSIM4xj = .15e-6;
        if (!model->omiBSIM4vsatGiven)
            model->omiBSIM4vsat = 8.0e4;    /* unit m/s */ 
        if (!model->omiBSIM4atGiven)
            model->omiBSIM4at = 3.3e4;    /* unit m/s */ 
        if (!model->omiBSIM4a0Given)
            model->omiBSIM4a0 = 1.0;  
        if (!model->omiBSIM4agsGiven)
            model->omiBSIM4ags = 0.0;
        if (!model->omiBSIM4a1Given)
            model->omiBSIM4a1 = 0.0;
        if (!model->omiBSIM4a2Given)
            model->omiBSIM4a2 = 1.0;
        if (!model->omiBSIM4ketaGiven)
            model->omiBSIM4keta = -0.047;    /* unit  / V */
        if (!model->omiBSIM4nsubGiven)
            model->omiBSIM4nsub = 6.0e16;   /* unit 1/cm3 */
        if (!model->omiBSIM4phigGiven)
            model->omiBSIM4phig = 4.05;  
        if (!model->omiBSIM4epsrgateGiven)
            model->omiBSIM4epsrgate = 11.7;  
        if (!model->omiBSIM4easubGiven)
            model->omiBSIM4easub = 4.05;  
        if (!model->omiBSIM4epsrsubGiven)
            model->omiBSIM4epsrsub = 11.7; 
        if (!model->omiBSIM4ni0subGiven)
            model->omiBSIM4ni0sub = 1.45e10;   /* unit 1/cm3 */
        if (!model->omiBSIM4bg0subGiven)
            model->omiBSIM4bg0sub =  1.16;     /* unit eV */
        if (!model->omiBSIM4tbgasubGiven)
            model->omiBSIM4tbgasub = 7.02e-4;  
        if (!model->omiBSIM4tbgbsubGiven)
            model->omiBSIM4tbgbsub = 1108.0;  
        if (!model->omiBSIM4ndepGiven)
            model->omiBSIM4ndep = 1.7e17;   /* unit 1/cm3 */
        if (!model->omiBSIM4nsdGiven)
            model->omiBSIM4nsd = 1.0e20;   /* unit 1/cm3 */
        if (!model->omiBSIM4phinGiven)
            model->omiBSIM4phin = 0.0; /* unit V */
        if (!model->omiBSIM4ngateGiven)
            model->omiBSIM4ngate = 0;   /* unit 1/cm3 */
        if (!model->omiBSIM4vbmGiven)
            model->omiBSIM4vbm = -3.0;
        if (!model->omiBSIM4xtGiven)
            model->omiBSIM4xt = 1.55e-7;
        if (!model->omiBSIM4kt1Given)
            model->omiBSIM4kt1 = -0.11;      /* unit V */
        if (!model->omiBSIM4kt1lGiven)
            model->omiBSIM4kt1l = 0.0;      /* unit V*m */
        if (!model->omiBSIM4kt2Given)
            model->omiBSIM4kt2 = 0.022;      /* No unit */
        if (!model->omiBSIM4k3Given)
            model->omiBSIM4k3 = 80.0;      
        if (!model->omiBSIM4k3bGiven)
            model->omiBSIM4k3b = 0.0;      
        if (!model->omiBSIM4w0Given)
            model->omiBSIM4w0 = 2.5e-6;    
        if (!model->omiBSIM4lpe0Given)
            model->omiBSIM4lpe0 = 1.74e-7;     
        if (!model->omiBSIM4lpebGiven)
            model->omiBSIM4lpeb = 0.0;
        if (!model->omiBSIM4dvtp0Given)
            model->omiBSIM4dvtp0 = 0.0;
        if (!model->omiBSIM4dvtp1Given)
            model->omiBSIM4dvtp1 = 0.0;
        if (!model->omiBSIM4dvtp2Given)        /* New DIBL/Rout */
            model->omiBSIM4dvtp2 = 0.0;
        if (!model->omiBSIM4dvtp3Given)
            model->omiBSIM4dvtp3 = 0.0;
        if (!model->omiBSIM4dvtp4Given)
            model->omiBSIM4dvtp4 = 0.0;
        if (!model->omiBSIM4dvtp5Given)
            model->omiBSIM4dvtp5 = 0.0;
        if (!model->omiBSIM4dvt0Given)
            model->omiBSIM4dvt0 = 2.2;    
        if (!model->omiBSIM4dvt1Given)
            model->omiBSIM4dvt1 = 0.53;      
        if (!model->omiBSIM4dvt2Given)
            model->omiBSIM4dvt2 = -0.032;   /* unit 1 / V */     

        if (!model->omiBSIM4dvt0wGiven)
            model->omiBSIM4dvt0w = 0.0;    
        if (!model->omiBSIM4dvt1wGiven)
            model->omiBSIM4dvt1w = 5.3e6;    
        if (!model->omiBSIM4dvt2wGiven)
            model->omiBSIM4dvt2w = -0.032;   

        if (!model->omiBSIM4droutGiven)
            model->omiBSIM4drout = 0.56;     
        if (!model->omiBSIM4dsubGiven)
            model->omiBSIM4dsub = model->omiBSIM4drout;     
        if (!model->omiBSIM4vth0Given)
            model->omiBSIM4vth0 = (model->omiBSIM4type == NMOS) ? 0.7 : -0.7;
        if (!model->omiBSIM4vfbGiven)
            model->omiBSIM4vfb = -1.0;
        if (!model->omiBSIM4euGiven)
            model->omiBSIM4eu = (model->omiBSIM4type == NMOS) ? 1.67 : 1.0;
        if (!model->omiBSIM4ucsGiven)
            model->omiBSIM4ucs = (model->omiBSIM4type == NMOS) ? 1.67 : 1.0;
        if (!model->omiBSIM4uaGiven)
            model->omiBSIM4ua = ((model->omiBSIM4mobMod == 2)) ? 1.0e-15 : 1.0e-9; /* unit m/V */
        if (!model->omiBSIM4ua1Given)
            model->omiBSIM4ua1 = 1.0e-9;      /* unit m/V */
        if (!model->omiBSIM4ubGiven)
            model->omiBSIM4ub = 1.0e-19;     /* unit (m/V)**2 */
        if (!model->omiBSIM4ub1Given)
            model->omiBSIM4ub1 = -1.0e-18;     /* unit (m/V)**2 */
        if (!model->omiBSIM4ucGiven)
            model->omiBSIM4uc = (model->omiBSIM4mobMod == 1) ? -0.0465 : -0.0465e-9;   
        if (!model->omiBSIM4uc1Given)
            model->omiBSIM4uc1 = (model->omiBSIM4mobMod == 1) ? -0.056 : -0.056e-9;   
        if (!model->omiBSIM4udGiven)
            model->omiBSIM4ud = 0.0;     /* unit m**(-2) */
        if (!model->omiBSIM4ud1Given)
            model->omiBSIM4ud1 = 0.0;     
        if (!model->omiBSIM4upGiven)
            model->omiBSIM4up = 0.0;     
        if (!model->omiBSIM4lpGiven)
            model->omiBSIM4lp = 1.0e-8;     
        if (!model->omiBSIM4u0Given)
            model->omiBSIM4u0 = (model->omiBSIM4type == NMOS) ? 0.067 : 0.025;
        if (!model->omiBSIM4uteGiven)
            model->omiBSIM4ute = -1.5; 
        if (!model->omiBSIM4ucsteGiven)
            model->omiBSIM4ucste = -4.775e-3;
        if (!model->omiBSIM4voffGiven)
            model->omiBSIM4voff = -0.08;
        if (!model->omiBSIM4vofflGiven)
            model->omiBSIM4voffl = 0.0;
        if (!model->omiBSIM4voffcvlGiven)
            model->omiBSIM4voffcvl = 0.0;
        if (!model->omiBSIM4minvGiven)
            model->omiBSIM4minv = 0.0;
        if (!model->omiBSIM4minvcvGiven)
            model->omiBSIM4minvcv = 0.0;
        if (!model->omiBSIM4fproutGiven)
            model->omiBSIM4fprout = 0.0;
        if (!model->omiBSIM4pditsGiven)
            model->omiBSIM4pdits = 0.0;
        if (!model->omiBSIM4pditsdGiven)
            model->omiBSIM4pditsd = 0.0;
        if (!model->omiBSIM4pditslGiven)
            model->omiBSIM4pditsl = 0.0;
        if (!model->omiBSIM4deltaGiven)  
           model->omiBSIM4delta = 0.01;
        if (!model->omiBSIM4rdswminGiven)
            model->omiBSIM4rdswmin = 0.0;
        if (!model->omiBSIM4rdwminGiven)
            model->omiBSIM4rdwmin = 0.0;
        if (!model->omiBSIM4rswminGiven)
            model->omiBSIM4rswmin = 0.0;
        if (!model->omiBSIM4rdswGiven)
            model->omiBSIM4rdsw = 200.0; /* in ohm*um */     
        if (!model->omiBSIM4rdwGiven)
            model->omiBSIM4rdw = 100.0;
        if (!model->omiBSIM4rswGiven)
            model->omiBSIM4rsw = 100.0;
        if (!model->omiBSIM4prwgGiven)
            model->omiBSIM4prwg = 1.0; /* in 1/V */
        if (!model->omiBSIM4prwbGiven)
            model->omiBSIM4prwb = 0.0;      
        if (!model->omiBSIM4prtGiven)
            model->omiBSIM4prt = 0.0;      
        if (!model->omiBSIM4eta0Given)
            model->omiBSIM4eta0 = 0.08;      /* no unit  */ 
        if (!model->omiBSIM4etabGiven)
            model->omiBSIM4etab = -0.07;      /* unit  1/V */ 
        if (!model->omiBSIM4pclmGiven)
            model->omiBSIM4pclm = 1.3;      /* no unit  */ 
        if (!model->omiBSIM4pdibl1Given)
            model->omiBSIM4pdibl1 = 0.39;    /* no unit  */
        if (!model->omiBSIM4pdibl2Given)
            model->omiBSIM4pdibl2 = 0.0086;    /* no unit  */ 
        if (!model->omiBSIM4pdiblbGiven)
            model->omiBSIM4pdiblb = 0.0;    /* 1/V  */ 
        if (!model->omiBSIM4pscbe1Given)
            model->omiBSIM4pscbe1 = 4.24e8;     
        if (!model->omiBSIM4pscbe2Given)
            model->omiBSIM4pscbe2 = 1.0e-5;    
        if (!model->omiBSIM4pvagGiven)
            model->omiBSIM4pvag = 0.0;     
        if (!model->omiBSIM4wrGiven)  
            model->omiBSIM4wr = 1.0;
        if (!model->omiBSIM4dwgGiven)  
            model->omiBSIM4dwg = 0.0;
        if (!model->omiBSIM4dwbGiven)  
            model->omiBSIM4dwb = 0.0;
        if (!model->omiBSIM4b0Given)
            model->omiBSIM4b0 = 0.0;
        if (!model->omiBSIM4b1Given)  
            model->omiBSIM4b1 = 0.0;
        if (!model->omiBSIM4alpha0Given)  
            model->omiBSIM4alpha0 = 0.0;
        if (!model->omiBSIM4alpha1Given)
            model->omiBSIM4alpha1 = 0.0;
        if (!model->omiBSIM4beta0Given)  
            model->omiBSIM4beta0 = 0.0;
        if (!model->omiBSIM4gidlModGiven)
            model->omiBSIM4gidlMod = 0;         /* v4.7 New GIDL/GISL */
        if (!model->omiBSIM4agidlGiven)
            model->omiBSIM4agidl = 0.0;
        if (!model->omiBSIM4bgidlGiven)
            model->omiBSIM4bgidl = 2.3e9; /* V/m */
        if (!model->omiBSIM4cgidlGiven)
            model->omiBSIM4cgidl = 0.5; /* V^3 */
        if (!model->omiBSIM4egidlGiven)
            model->omiBSIM4egidl = 0.8; /* V */
        if (!model->omiBSIM4rgidlGiven)          /* v4.7 New GIDL/GISL */
            model->omiBSIM4rgidl = 1.0;
        if (!model->omiBSIM4kgidlGiven)          /* v4.7 New GIDL/GISL */
            model->omiBSIM4kgidl = 0.0;
        if (!model->omiBSIM4fgidlGiven)          /* v4.7 New GIDL/GISL */
            model->omiBSIM4fgidl = 0.0;
        if (!model->omiBSIM4agislGiven)
        {
            if (model->omiBSIM4agidlGiven)
                model->omiBSIM4agisl = model->omiBSIM4agidl;
            else
                model->omiBSIM4agisl = 0.0;
        }
        if (!model->omiBSIM4bgislGiven)
        {
            if (model->omiBSIM4bgidlGiven)
                model->omiBSIM4bgisl = model->omiBSIM4bgidl;
            else
                model->omiBSIM4bgisl = 2.3e9; /* V/m */
        }
        if (!model->omiBSIM4cgislGiven)
        {
            if (model->omiBSIM4cgidlGiven)
                model->omiBSIM4cgisl = model->omiBSIM4cgidl;
            else
                model->omiBSIM4cgisl = 0.5; /* V^3 */
        }
        if (!model->omiBSIM4egislGiven)
        {
            if (model->omiBSIM4egidlGiven)
                model->omiBSIM4egisl = model->omiBSIM4egidl;
            else
                model->omiBSIM4egisl = 0.8; /* V */
        }
        if (!model->omiBSIM4rgislGiven)          /* v4.7 New GIDL/GISL */
            model->omiBSIM4rgisl = model->omiBSIM4rgidl;
        if (!model->omiBSIM4kgislGiven)          /* v4.7 New GIDL/GISL */
            model->omiBSIM4kgisl = model->omiBSIM4kgidl;
        if (!model->omiBSIM4fgislGiven)          /* v4.7 New GIDL/GISL */
            model->omiBSIM4fgisl = model->omiBSIM4fgidl;
        if (!model->omiBSIM4aigcGiven)
            model->omiBSIM4aigc = (model->omiBSIM4type == NMOS) ? 1.36e-2 : 9.80e-3;
        if (!model->omiBSIM4bigcGiven)
            model->omiBSIM4bigc = (model->omiBSIM4type == NMOS) ? 1.71e-3 : 7.59e-4;
        if (!model->omiBSIM4cigcGiven)
            model->omiBSIM4cigc = (model->omiBSIM4type == NMOS) ? 0.075 : 0.03;
        if (model->omiBSIM4aigsdGiven)
        {
            model->omiBSIM4aigs = model->omiBSIM4aigd = model->omiBSIM4aigsd;
        }
        else
        {
            model->omiBSIM4aigsd = (model->omiBSIM4type == NMOS) ? 1.36e-2 : 9.80e-3;
            if (!model->omiBSIM4aigsGiven)
                model->omiBSIM4aigs = (model->omiBSIM4type == NMOS) ? 1.36e-2 : 9.80e-3;
            if (!model->omiBSIM4aigdGiven)
                model->omiBSIM4aigd = (model->omiBSIM4type == NMOS) ? 1.36e-2 : 9.80e-3;
        }
        if (model->omiBSIM4bigsdGiven)
        {
            model->omiBSIM4bigs = model->omiBSIM4bigd = model->omiBSIM4bigsd;
        }
        else
        {
            model->omiBSIM4bigsd = (model->omiBSIM4type == NMOS) ? 1.71e-3 : 7.59e-4;
            if (!model->omiBSIM4bigsGiven)
                model->omiBSIM4bigs = (model->omiBSIM4type == NMOS) ? 1.71e-3 : 7.59e-4;
            if (!model->omiBSIM4bigdGiven)
                model->omiBSIM4bigd = (model->omiBSIM4type == NMOS) ? 1.71e-3 : 7.59e-4;
        }
        if (model->omiBSIM4cigsdGiven)
        {
            model->omiBSIM4cigs = model->omiBSIM4cigd = model->omiBSIM4cigsd;
        }
        else
        {
             model->omiBSIM4cigsd = (model->omiBSIM4type == NMOS) ? 0.075 : 0.03;
           if (!model->omiBSIM4cigsGiven)
                model->omiBSIM4cigs = (model->omiBSIM4type == NMOS) ? 0.075 : 0.03;
            if (!model->omiBSIM4cigdGiven)
                model->omiBSIM4cigd = (model->omiBSIM4type == NMOS) ? 0.075 : 0.03;
        }
        if (!model->omiBSIM4aigbaccGiven)
            model->omiBSIM4aigbacc = 1.36e-2;
        if (!model->omiBSIM4bigbaccGiven)
            model->omiBSIM4bigbacc = 1.71e-3;
        if (!model->omiBSIM4cigbaccGiven)
            model->omiBSIM4cigbacc = 0.075;
        if (!model->omiBSIM4aigbinvGiven)
            model->omiBSIM4aigbinv = 1.11e-2;
        if (!model->omiBSIM4bigbinvGiven)
            model->omiBSIM4bigbinv = 9.49e-4;
        if (!model->omiBSIM4cigbinvGiven)
            model->omiBSIM4cigbinv = 0.006;
        if (!model->omiBSIM4nigcGiven)
            model->omiBSIM4nigc = 1.0;
        if (!model->omiBSIM4nigbinvGiven)
            model->omiBSIM4nigbinv = 3.0;
        if (!model->omiBSIM4nigbaccGiven)
            model->omiBSIM4nigbacc = 1.0;
        if (!model->omiBSIM4ntoxGiven)
            model->omiBSIM4ntox = 1.0;
        if (!model->omiBSIM4eigbinvGiven)
            model->omiBSIM4eigbinv = 1.1;
        if (!model->omiBSIM4pigcdGiven)
            model->omiBSIM4pigcd = 1.0;
        if (!model->omiBSIM4poxedgeGiven)
            model->omiBSIM4poxedge = 1.0;
        if (!model->omiBSIM4xrcrg1Given)
            model->omiBSIM4xrcrg1 = 12.0;
        if (!model->omiBSIM4xrcrg2Given)
            model->omiBSIM4xrcrg2 = 1.0;
        if (!model->omiBSIM4ijthsfwdGiven)
            model->omiBSIM4ijthsfwd = 0.1; /* unit A */
        if (!model->omiBSIM4ijthdfwdGiven)
            model->omiBSIM4ijthdfwd = model->omiBSIM4ijthsfwd;
        if (!model->omiBSIM4ijthsrevGiven)
            model->omiBSIM4ijthsrev = 0.1; /* unit A */
        if (!model->omiBSIM4ijthdrevGiven)
            model->omiBSIM4ijthdrev = model->omiBSIM4ijthsrev;
        if (!model->omiBSIM4tnoiaGiven)
            model->omiBSIM4tnoia = 1.5;
        if (!model->omiBSIM4tnoibGiven)
            model->omiBSIM4tnoib = 3.5;
        if (!model->omiBSIM4tnoicGiven)
            model->omiBSIM4tnoic = 0.0;
        if (!model->omiBSIM4rnoiaGiven)
            model->omiBSIM4rnoia = 0.577;
        if (!model->omiBSIM4rnoibGiven)
            model->omiBSIM4rnoib = 0.5164;
        if (!model->omiBSIM4rnoicGiven)
            model->omiBSIM4rnoic = 0.395;
        if (!model->omiBSIM4ntnoiGiven)
            model->omiBSIM4ntnoi = 1.0;
        if (!model->omiBSIM4lambdaGiven)
            model->omiBSIM4lambda = 0.0;
        if (!model->omiBSIM4vtlGiven)
            model->omiBSIM4vtl = 2.0e5;    /* unit m/s */ 
        if (!model->omiBSIM4xnGiven)
            model->omiBSIM4xn = 3.0;   
        if (!model->omiBSIM4lcGiven)
            model->omiBSIM4lc = 5.0e-9;   
        if (!model->omiBSIM4vfbsdoffGiven)  
            model->omiBSIM4vfbsdoff = 0.0;  /* unit v */  
        if (!model->omiBSIM4tvfbsdoffGiven)
            model->omiBSIM4tvfbsdoff = 0.0;  
        if (!model->omiBSIM4tvoffGiven)
            model->omiBSIM4tvoff = 0.0;  
        if (!model->omiBSIM4tnfactorGiven)         /* v4.7 temp dep of leakage current  */
            model->omiBSIM4tnfactor = 0.0;  
        if (!model->omiBSIM4teta0Given)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4teta0 = 0.0;  
        if (!model->omiBSIM4tvoffcvGiven)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4tvoffcv = 0.0;  
 
        if (!model->omiBSIM4lintnoiGiven)
            model->omiBSIM4lintnoi = 0.0;  /* unit m */  

        if (!model->omiBSIM4xjbvsGiven)
            model->omiBSIM4xjbvs = 1.0; /* no unit */
        if (!model->omiBSIM4xjbvdGiven)
            model->omiBSIM4xjbvd = model->omiBSIM4xjbvs;
        if (!model->omiBSIM4bvsGiven)
            model->omiBSIM4bvs = 10.0; /* V */
        if (!model->omiBSIM4bvdGiven)
            model->omiBSIM4bvd = model->omiBSIM4bvs;

        if (!model->omiBSIM4gbminGiven)
            model->omiBSIM4gbmin = 1.0e-12; /* in mho */
        if (!model->omiBSIM4rbdbGiven)
            model->omiBSIM4rbdb = 50.0; /* in ohm */
        if (!model->omiBSIM4rbpbGiven)
            model->omiBSIM4rbpb = 50.0;
        if (!model->omiBSIM4rbsbGiven)
            model->omiBSIM4rbsb = 50.0;
        if (!model->omiBSIM4rbpsGiven)
            model->omiBSIM4rbps = 50.0;
        if (!model->omiBSIM4rbpdGiven)
            model->omiBSIM4rbpd = 50.0;

        if (!model->omiBSIM4rbps0Given)
            model->omiBSIM4rbps0 = 50.0;
        if (!model->omiBSIM4rbpslGiven)
            model->omiBSIM4rbpsl = 0.0;
        if (!model->omiBSIM4rbpswGiven)
            model->omiBSIM4rbpsw = 0.0;
        if (!model->omiBSIM4rbpsnfGiven)
            model->omiBSIM4rbpsnf = 0.0;

        if (!model->omiBSIM4rbpd0Given)
            model->omiBSIM4rbpd0 = 50.0;
        if (!model->omiBSIM4rbpdlGiven)
            model->omiBSIM4rbpdl = 0.0;
        if (!model->omiBSIM4rbpdwGiven)
            model->omiBSIM4rbpdw = 0.0;
        if (!model->omiBSIM4rbpdnfGiven)
            model->omiBSIM4rbpdnf = 0.0;

        if (!model->omiBSIM4rbpbx0Given)
            model->omiBSIM4rbpbx0 = 100.0;
        if (!model->omiBSIM4rbpbxlGiven)
            model->omiBSIM4rbpbxl = 0.0;
        if (!model->omiBSIM4rbpbxwGiven)
            model->omiBSIM4rbpbxw = 0.0;
        if (!model->omiBSIM4rbpbxnfGiven)
            model->omiBSIM4rbpbxnf = 0.0;
        if (!model->omiBSIM4rbpby0Given)
            model->omiBSIM4rbpby0 = 100.0;
        if (!model->omiBSIM4rbpbylGiven)
            model->omiBSIM4rbpbyl = 0.0;
        if (!model->omiBSIM4rbpbywGiven)
            model->omiBSIM4rbpbyw = 0.0;
        if (!model->omiBSIM4rbpbynfGiven)
            model->omiBSIM4rbpbynf = 0.0;


        if (!model->omiBSIM4rbsbx0Given)
            model->omiBSIM4rbsbx0 = 100.0;
        if (!model->omiBSIM4rbsby0Given)
            model->omiBSIM4rbsby0 = 100.0;
        if (!model->omiBSIM4rbdbx0Given)
            model->omiBSIM4rbdbx0 = 100.0;
        if (!model->omiBSIM4rbdby0Given)
            model->omiBSIM4rbdby0 = 100.0;


        if (!model->omiBSIM4rbsdbxlGiven)
            model->omiBSIM4rbsdbxl = 0.0;
        if (!model->omiBSIM4rbsdbxwGiven)
            model->omiBSIM4rbsdbxw = 0.0;
        if (!model->omiBSIM4rbsdbxnfGiven)
            model->omiBSIM4rbsdbxnf = 0.0;
        if (!model->omiBSIM4rbsdbylGiven)
            model->omiBSIM4rbsdbyl = 0.0;
        if (!model->omiBSIM4rbsdbywGiven)
            model->omiBSIM4rbsdbyw = 0.0;
        if (!model->omiBSIM4rbsdbynfGiven)
            model->omiBSIM4rbsdbynf = 0.0;

        if (!model->omiBSIM4cgslGiven)  
            model->omiBSIM4cgsl = 0.0;
        if (!model->omiBSIM4cgdlGiven)  
            model->omiBSIM4cgdl = 0.0;
        if (!model->omiBSIM4ckappasGiven)  
            model->omiBSIM4ckappas = 0.6;
        if (!model->omiBSIM4ckappadGiven)
            model->omiBSIM4ckappad = model->omiBSIM4ckappas;
        if (!model->omiBSIM4clcGiven)  
            model->omiBSIM4clc = 0.1e-6;
        if (!model->omiBSIM4cleGiven)  
            model->omiBSIM4cle = 0.6;
        if (!model->omiBSIM4vfbcvGiven)  
            model->omiBSIM4vfbcv = -1.0;
        if (!model->omiBSIM4acdeGiven)
            model->omiBSIM4acde = 1.0;
        if (!model->omiBSIM4moinGiven)
            model->omiBSIM4moin = 15.0;
        if (!model->omiBSIM4noffGiven)
            model->omiBSIM4noff = 1.0;
        if (!model->omiBSIM4voffcvGiven)
            model->omiBSIM4voffcv = 0.0;
        if (!model->omiBSIM4dmcgGiven)
            model->omiBSIM4dmcg = 0.0;
        if (!model->omiBSIM4dmciGiven)
            model->omiBSIM4dmci = model->omiBSIM4dmcg;
        if (!model->omiBSIM4dmdgGiven)
            model->omiBSIM4dmdg = 0.0;
        if (!model->omiBSIM4dmcgtGiven)
            model->omiBSIM4dmcgt = 0.0;
        if (!model->omiBSIM4xgwGiven)
            model->omiBSIM4xgw = 0.0;
        if (!model->omiBSIM4xglGiven)
            model->omiBSIM4xgl = 0.0;
        if (!model->omiBSIM4rshgGiven)
            model->omiBSIM4rshg = 0.1;
        if (!model->omiBSIM4ngconGiven)
            model->omiBSIM4ngcon = 1.0;
        if (!model->omiBSIM4tcjGiven)
            model->omiBSIM4tcj = 0.0;
        if (!model->omiBSIM4tpbGiven)
            model->omiBSIM4tpb = 0.0;
        if (!model->omiBSIM4tcjswGiven)
            model->omiBSIM4tcjsw = 0.0;
        if (!model->omiBSIM4tpbswGiven)
            model->omiBSIM4tpbsw = 0.0;
        if (!model->omiBSIM4tcjswgGiven)
            model->omiBSIM4tcjswg = 0.0;
        if (!model->omiBSIM4tpbswgGiven)
            model->omiBSIM4tpbswg = 0.0;

        /* Length dependence */
        if (!model->omiBSIM4lcdscGiven)
            model->omiBSIM4lcdsc = 0.0;
        if (!model->omiBSIM4lcdscbGiven)
            model->omiBSIM4lcdscb = 0.0;
        if (!model->omiBSIM4lcdscdGiven)
            model->omiBSIM4lcdscd = 0.0;
        if (!model->omiBSIM4lcitGiven)
            model->omiBSIM4lcit = 0.0;
        if (!model->omiBSIM4lnfactorGiven)
            model->omiBSIM4lnfactor = 0.0;
        if (!model->omiBSIM4lxjGiven)
            model->omiBSIM4lxj = 0.0;
        if (!model->omiBSIM4lvsatGiven)
            model->omiBSIM4lvsat = 0.0;
        if (!model->omiBSIM4latGiven)
            model->omiBSIM4lat = 0.0;
        if (!model->omiBSIM4la0Given)
            model->omiBSIM4la0 = 0.0; 
        if (!model->omiBSIM4lagsGiven)
            model->omiBSIM4lags = 0.0;
        if (!model->omiBSIM4la1Given)
            model->omiBSIM4la1 = 0.0;
        if (!model->omiBSIM4la2Given)
            model->omiBSIM4la2 = 0.0;
        if (!model->omiBSIM4lketaGiven)
            model->omiBSIM4lketa = 0.0;
        if (!model->omiBSIM4lnsubGiven)
            model->omiBSIM4lnsub = 0.0;
        if (!model->omiBSIM4lndepGiven)
            model->omiBSIM4lndep = 0.0;
        if (!model->omiBSIM4lnsdGiven)
            model->omiBSIM4lnsd = 0.0;
        if (!model->omiBSIM4lphinGiven)
            model->omiBSIM4lphin = 0.0;
        if (!model->omiBSIM4lngateGiven)
            model->omiBSIM4lngate = 0.0;
        if (!model->omiBSIM4lvbmGiven)
            model->omiBSIM4lvbm = 0.0;
        if (!model->omiBSIM4lxtGiven)
            model->omiBSIM4lxt = 0.0;
        if (!model->omiBSIM4lkt1Given)
            model->omiBSIM4lkt1 = 0.0; 
        if (!model->omiBSIM4lkt1lGiven)
            model->omiBSIM4lkt1l = 0.0;
        if (!model->omiBSIM4lkt2Given)
            model->omiBSIM4lkt2 = 0.0;
        if (!model->omiBSIM4lk3Given)
            model->omiBSIM4lk3 = 0.0;      
        if (!model->omiBSIM4lk3bGiven)
            model->omiBSIM4lk3b = 0.0;      
        if (!model->omiBSIM4lw0Given)
            model->omiBSIM4lw0 = 0.0;    
        if (!model->omiBSIM4llpe0Given)
            model->omiBSIM4llpe0 = 0.0;
        if (!model->omiBSIM4llpebGiven)
            model->omiBSIM4llpeb = 0.0; 
        if (!model->omiBSIM4ldvtp0Given)
            model->omiBSIM4ldvtp0 = 0.0;
        if (!model->omiBSIM4ldvtp1Given)
            model->omiBSIM4ldvtp1 = 0.0;
        if (!model->omiBSIM4ldvtp2Given)        /* New DIBL/Rout */
            model->omiBSIM4ldvtp2 = 0.0;
        if (!model->omiBSIM4ldvtp3Given)
            model->omiBSIM4ldvtp3 = 0.0;
        if (!model->omiBSIM4ldvtp4Given)
            model->omiBSIM4ldvtp4 = 0.0;
        if (!model->omiBSIM4ldvtp5Given)
            model->omiBSIM4ldvtp5 = 0.0;
        if (!model->omiBSIM4ldvt0Given)
            model->omiBSIM4ldvt0 = 0.0;    
        if (!model->omiBSIM4ldvt1Given)
            model->omiBSIM4ldvt1 = 0.0;      
        if (!model->omiBSIM4ldvt2Given)
            model->omiBSIM4ldvt2 = 0.0;
        if (!model->omiBSIM4ldvt0wGiven)
            model->omiBSIM4ldvt0w = 0.0;    
        if (!model->omiBSIM4ldvt1wGiven)
            model->omiBSIM4ldvt1w = 0.0;      
        if (!model->omiBSIM4ldvt2wGiven)
            model->omiBSIM4ldvt2w = 0.0;
        if (!model->omiBSIM4ldroutGiven)
            model->omiBSIM4ldrout = 0.0;     
        if (!model->omiBSIM4ldsubGiven)
            model->omiBSIM4ldsub = 0.0;
        if (!model->omiBSIM4lvth0Given)
           model->omiBSIM4lvth0 = 0.0;
        if (!model->omiBSIM4luaGiven)
            model->omiBSIM4lua = 0.0;
        if (!model->omiBSIM4lua1Given)
            model->omiBSIM4lua1 = 0.0;
        if (!model->omiBSIM4lubGiven)
            model->omiBSIM4lub = 0.0;
        if (!model->omiBSIM4lub1Given)
            model->omiBSIM4lub1 = 0.0;
        if (!model->omiBSIM4lucGiven)
            model->omiBSIM4luc = 0.0;
        if (!model->omiBSIM4luc1Given)
            model->omiBSIM4luc1 = 0.0;
        if (!model->omiBSIM4ludGiven)
            model->omiBSIM4lud = 0.0;
        if (!model->omiBSIM4lud1Given)
            model->omiBSIM4lud1 = 0.0;
        if (!model->omiBSIM4lupGiven)
            model->omiBSIM4lup = 0.0;
        if (!model->omiBSIM4llpGiven)
            model->omiBSIM4llp = 0.0;
        if (!model->omiBSIM4lu0Given)
            model->omiBSIM4lu0 = 0.0;
        if (!model->omiBSIM4luteGiven)
            model->omiBSIM4lute = 0.0;  
          if (!model->omiBSIM4lucsteGiven)
            model->omiBSIM4lucste = 0.0;                 
        if (!model->omiBSIM4lvoffGiven)
            model->omiBSIM4lvoff = 0.0;
        if (!model->omiBSIM4lminvGiven)
            model->omiBSIM4lminv = 0.0;
        if (!model->omiBSIM4lminvcvGiven)
            model->omiBSIM4lminvcv = 0.0;
        if (!model->omiBSIM4lfproutGiven)
            model->omiBSIM4lfprout = 0.0;
        if (!model->omiBSIM4lpditsGiven)
            model->omiBSIM4lpdits = 0.0;
        if (!model->omiBSIM4lpditsdGiven)
            model->omiBSIM4lpditsd = 0.0;
        if (!model->omiBSIM4ldeltaGiven)  
            model->omiBSIM4ldelta = 0.0;
        if (!model->omiBSIM4lrdswGiven)
            model->omiBSIM4lrdsw = 0.0;
        if (!model->omiBSIM4lrdwGiven)
            model->omiBSIM4lrdw = 0.0;
        if (!model->omiBSIM4lrswGiven)
            model->omiBSIM4lrsw = 0.0;
        if (!model->omiBSIM4lprwbGiven)
            model->omiBSIM4lprwb = 0.0;
        if (!model->omiBSIM4lprwgGiven)
            model->omiBSIM4lprwg = 0.0;
        if (!model->omiBSIM4lprtGiven)
            model->omiBSIM4lprt = 0.0;
        if (!model->omiBSIM4leta0Given)
            model->omiBSIM4leta0 = 0.0;
        if (!model->omiBSIM4letabGiven)
            model->omiBSIM4letab = -0.0;
        if (!model->omiBSIM4lpclmGiven)
            model->omiBSIM4lpclm = 0.0; 
        if (!model->omiBSIM4lpdibl1Given)
            model->omiBSIM4lpdibl1 = 0.0;
        if (!model->omiBSIM4lpdibl2Given)
            model->omiBSIM4lpdibl2 = 0.0;
        if (!model->omiBSIM4lpdiblbGiven)
            model->omiBSIM4lpdiblb = 0.0;
        if (!model->omiBSIM4lpscbe1Given)
            model->omiBSIM4lpscbe1 = 0.0;
        if (!model->omiBSIM4lpscbe2Given)
            model->omiBSIM4lpscbe2 = 0.0;
        if (!model->omiBSIM4lpvagGiven)
            model->omiBSIM4lpvag = 0.0;     
        if (!model->omiBSIM4lwrGiven)  
            model->omiBSIM4lwr = 0.0;
        if (!model->omiBSIM4ldwgGiven)  
            model->omiBSIM4ldwg = 0.0;
        if (!model->omiBSIM4ldwbGiven)  
            model->omiBSIM4ldwb = 0.0;
        if (!model->omiBSIM4lb0Given)
            model->omiBSIM4lb0 = 0.0;
        if (!model->omiBSIM4lb1Given)  
            model->omiBSIM4lb1 = 0.0;
        if (!model->omiBSIM4lalpha0Given)  
            model->omiBSIM4lalpha0 = 0.0;
        if (!model->omiBSIM4lalpha1Given)
            model->omiBSIM4lalpha1 = 0.0;
        if (!model->omiBSIM4lbeta0Given)  
            model->omiBSIM4lbeta0 = 0.0;
        if (!model->omiBSIM4lagidlGiven)
            model->omiBSIM4lagidl = 0.0;
        if (!model->omiBSIM4lbgidlGiven)
            model->omiBSIM4lbgidl = 0.0;
        if (!model->omiBSIM4lcgidlGiven)
            model->omiBSIM4lcgidl = 0.0;
        if (!model->omiBSIM4legidlGiven)
            model->omiBSIM4legidl = 0.0;
        if (!model->omiBSIM4lrgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4lrgidl = 0.0;
        if (!model->omiBSIM4lkgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4lkgidl = 0.0;
        if (!model->omiBSIM4lfgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4lfgidl = 0.0;

        if (!model->omiBSIM4lagislGiven)
        {
            if (model->omiBSIM4lagidlGiven)
                model->omiBSIM4lagisl = model->omiBSIM4lagidl;
            else
                model->omiBSIM4lagisl = 0.0;
        }
        if (!model->omiBSIM4lbgislGiven)
        {
            if (model->omiBSIM4lbgidlGiven)
                model->omiBSIM4lbgisl = model->omiBSIM4lbgidl;
            else
                model->omiBSIM4lbgisl = 0.0;
        }
        if (!model->omiBSIM4lcgislGiven)
        {
            if (model->omiBSIM4lcgidlGiven)
                model->omiBSIM4lcgisl = model->omiBSIM4lcgidl;
            else
                model->omiBSIM4lcgisl = 0.0;
        }
        if (!model->omiBSIM4legislGiven)
        {
            if (model->omiBSIM4legidlGiven)
                model->omiBSIM4legisl = model->omiBSIM4legidl;
            else
                model->omiBSIM4legisl = 0.0; 
        }
        if (!model->omiBSIM4lrgislGiven)         /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4lrgidlGiven)
                model->omiBSIM4lrgisl = model->omiBSIM4lrgidl;
        }
        if (!model->omiBSIM4lkgislGiven)        /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4lkgidlGiven)
                model->omiBSIM4lkgisl = model->omiBSIM4lkgidl;
        }
        if (!model->omiBSIM4lfgislGiven)        /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4lfgidlGiven)
                model->omiBSIM4lfgisl = model->omiBSIM4lfgidl;
        }
        if (!model->omiBSIM4laigcGiven)
            model->omiBSIM4laigc = 0.0;
        if (!model->omiBSIM4lbigcGiven)
            model->omiBSIM4lbigc = 0.0;
        if (!model->omiBSIM4lcigcGiven)
            model->omiBSIM4lcigc = 0.0;
        if (!model->omiBSIM4aigsdGiven && (model->omiBSIM4aigsGiven || model->omiBSIM4aigdGiven))
        {
            if (!model->omiBSIM4laigsGiven)
                model->omiBSIM4laigs = 0.0;
            if (!model->omiBSIM4laigdGiven)
                model->omiBSIM4laigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4laigsdGiven)
               model->omiBSIM4laigsd = 0.0;
           model->omiBSIM4laigs = model->omiBSIM4laigd = model->omiBSIM4laigsd;
        }
        if (!model->omiBSIM4bigsdGiven && (model->omiBSIM4bigsGiven || model->omiBSIM4bigdGiven))
        {
            if (!model->omiBSIM4lbigsGiven)
                model->omiBSIM4lbigs = 0.0;
            if (!model->omiBSIM4lbigdGiven)
                model->omiBSIM4lbigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4lbigsdGiven)
               model->omiBSIM4lbigsd = 0.0;
           model->omiBSIM4lbigs = model->omiBSIM4lbigd = model->omiBSIM4lbigsd;
        }
        if (!model->omiBSIM4cigsdGiven && (model->omiBSIM4cigsGiven || model->omiBSIM4cigdGiven))
        {
            if (!model->omiBSIM4lcigsGiven)
                model->omiBSIM4lcigs = 0.0;
            if (!model->omiBSIM4lcigdGiven)
                model->omiBSIM4lcigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4lcigsdGiven)
               model->omiBSIM4lcigsd = 0.0;
           model->omiBSIM4lcigs = model->omiBSIM4lcigd = model->omiBSIM4lcigsd;
        }
        if (!model->omiBSIM4laigbaccGiven)
            model->omiBSIM4laigbacc = 0.0;
        if (!model->omiBSIM4lbigbaccGiven)
            model->omiBSIM4lbigbacc = 0.0;
        if (!model->omiBSIM4lcigbaccGiven)
            model->omiBSIM4lcigbacc = 0.0;
        if (!model->omiBSIM4laigbinvGiven)
            model->omiBSIM4laigbinv = 0.0;
        if (!model->omiBSIM4lbigbinvGiven)
            model->omiBSIM4lbigbinv = 0.0;
        if (!model->omiBSIM4lcigbinvGiven)
            model->omiBSIM4lcigbinv = 0.0;
        if (!model->omiBSIM4lnigcGiven)
            model->omiBSIM4lnigc = 0.0;
        if (!model->omiBSIM4lnigbinvGiven)
            model->omiBSIM4lnigbinv = 0.0;
        if (!model->omiBSIM4lnigbaccGiven)
            model->omiBSIM4lnigbacc = 0.0;
        if (!model->omiBSIM4lntoxGiven)
            model->omiBSIM4lntox = 0.0;
        if (!model->omiBSIM4leigbinvGiven)
            model->omiBSIM4leigbinv = 0.0;
        if (!model->omiBSIM4lpigcdGiven)
            model->omiBSIM4lpigcd = 0.0;
        if (!model->omiBSIM4lpoxedgeGiven)
            model->omiBSIM4lpoxedge = 0.0;
        if (!model->omiBSIM4lxrcrg1Given)
            model->omiBSIM4lxrcrg1 = 0.0;
        if (!model->omiBSIM4lxrcrg2Given)
            model->omiBSIM4lxrcrg2 = 0.0;
        if (!model->omiBSIM4leuGiven)
            model->omiBSIM4leu = 0.0;
                if (!model->omiBSIM4lucsGiven)
            model->omiBSIM4lucs = 0.0;
        if (!model->omiBSIM4lvfbGiven)
            model->omiBSIM4lvfb = 0.0;
        if (!model->omiBSIM4llambdaGiven)
            model->omiBSIM4llambda = 0.0;
        if (!model->omiBSIM4lvtlGiven)
            model->omiBSIM4lvtl = 0.0;  
        if (!model->omiBSIM4lxnGiven)
            model->omiBSIM4lxn = 0.0;  
        if (!model->omiBSIM4lvfbsdoffGiven)
            model->omiBSIM4lvfbsdoff = 0.0;   
        if (!model->omiBSIM4ltvfbsdoffGiven)
            model->omiBSIM4ltvfbsdoff = 0.0;  
        if (!model->omiBSIM4ltvoffGiven)
            model->omiBSIM4ltvoff = 0.0;  
        if (!model->omiBSIM4ltnfactorGiven)         /* v4.7 temp dep of leakage current  */
            model->omiBSIM4ltnfactor = 0.0;  
        if (!model->omiBSIM4lteta0Given)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4lteta0 = 0.0;  
        if (!model->omiBSIM4ltvoffcvGiven)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4ltvoffcv = 0.0;  


        if (!model->omiBSIM4lcgslGiven)  
            model->omiBSIM4lcgsl = 0.0;
        if (!model->omiBSIM4lcgdlGiven)  
            model->omiBSIM4lcgdl = 0.0;
        if (!model->omiBSIM4lckappasGiven)  
            model->omiBSIM4lckappas = 0.0;
        if (!model->omiBSIM4lckappadGiven)
            model->omiBSIM4lckappad = 0.0;
        if (!model->omiBSIM4lclcGiven)  
            model->omiBSIM4lclc = 0.0;
        if (!model->omiBSIM4lcleGiven)  
            model->omiBSIM4lcle = 0.0;
        if (!model->omiBSIM4lcfGiven)  
            model->omiBSIM4lcf = 0.0;
        if (!model->omiBSIM4lvfbcvGiven)  
            model->omiBSIM4lvfbcv = 0.0;
        if (!model->omiBSIM4lacdeGiven)
            model->omiBSIM4lacde = 0.0;
        if (!model->omiBSIM4lmoinGiven)
            model->omiBSIM4lmoin = 0.0;
        if (!model->omiBSIM4lnoffGiven)
            model->omiBSIM4lnoff = 0.0;
        if (!model->omiBSIM4lvoffcvGiven)
            model->omiBSIM4lvoffcv = 0.0;

        /* Width dependence */
        if (!model->omiBSIM4wcdscGiven)
            model->omiBSIM4wcdsc = 0.0;
        if (!model->omiBSIM4wcdscbGiven)
            model->omiBSIM4wcdscb = 0.0;  
        if (!model->omiBSIM4wcdscdGiven)
            model->omiBSIM4wcdscd = 0.0;
        if (!model->omiBSIM4wcitGiven)
            model->omiBSIM4wcit = 0.0;
        if (!model->omiBSIM4wnfactorGiven)
            model->omiBSIM4wnfactor = 0.0;
        if (!model->omiBSIM4wxjGiven)
            model->omiBSIM4wxj = 0.0;
        if (!model->omiBSIM4wvsatGiven)
            model->omiBSIM4wvsat = 0.0;
        if (!model->omiBSIM4watGiven)
            model->omiBSIM4wat = 0.0;
        if (!model->omiBSIM4wa0Given)
            model->omiBSIM4wa0 = 0.0; 
        if (!model->omiBSIM4wagsGiven)
            model->omiBSIM4wags = 0.0;
        if (!model->omiBSIM4wa1Given)
            model->omiBSIM4wa1 = 0.0;
        if (!model->omiBSIM4wa2Given)
            model->omiBSIM4wa2 = 0.0;
        if (!model->omiBSIM4wketaGiven)
            model->omiBSIM4wketa = 0.0;
        if (!model->omiBSIM4wnsubGiven)
            model->omiBSIM4wnsub = 0.0;
        if (!model->omiBSIM4wndepGiven)
            model->omiBSIM4wndep = 0.0;
        if (!model->omiBSIM4wnsdGiven)
            model->omiBSIM4wnsd = 0.0;
        if (!model->omiBSIM4wphinGiven)
            model->omiBSIM4wphin = 0.0;
        if (!model->omiBSIM4wngateGiven)
            model->omiBSIM4wngate = 0.0;
        if (!model->omiBSIM4wvbmGiven)
            model->omiBSIM4wvbm = 0.0;
        if (!model->omiBSIM4wxtGiven)
            model->omiBSIM4wxt = 0.0;
        if (!model->omiBSIM4wkt1Given)
            model->omiBSIM4wkt1 = 0.0; 
        if (!model->omiBSIM4wkt1lGiven)
            model->omiBSIM4wkt1l = 0.0;
        if (!model->omiBSIM4wkt2Given)
            model->omiBSIM4wkt2 = 0.0;
        if (!model->omiBSIM4wk3Given)
            model->omiBSIM4wk3 = 0.0;      
        if (!model->omiBSIM4wk3bGiven)
            model->omiBSIM4wk3b = 0.0;      
        if (!model->omiBSIM4ww0Given)
            model->omiBSIM4ww0 = 0.0;    
        if (!model->omiBSIM4wlpe0Given)
            model->omiBSIM4wlpe0 = 0.0;
        if (!model->omiBSIM4wlpebGiven)
            model->omiBSIM4wlpeb = 0.0; 
        if (!model->omiBSIM4wdvtp0Given)
            model->omiBSIM4wdvtp0 = 0.0;
        if (!model->omiBSIM4wdvtp1Given)
            model->omiBSIM4wdvtp1 = 0.0;
        if (!model->omiBSIM4wdvtp2Given)        /* New DIBL/Rout */
            model->omiBSIM4wdvtp2 = 0.0;
        if (!model->omiBSIM4wdvtp3Given)
            model->omiBSIM4wdvtp3 = 0.0;
        if (!model->omiBSIM4wdvtp4Given)
            model->omiBSIM4wdvtp4 = 0.0;
        if (!model->omiBSIM4wdvtp5Given)
            model->omiBSIM4wdvtp5 = 0.0;
        if (!model->omiBSIM4wdvt0Given)
            model->omiBSIM4wdvt0 = 0.0;    
        if (!model->omiBSIM4wdvt1Given)
            model->omiBSIM4wdvt1 = 0.0;      
        if (!model->omiBSIM4wdvt2Given)
            model->omiBSIM4wdvt2 = 0.0;
        if (!model->omiBSIM4wdvt0wGiven)
            model->omiBSIM4wdvt0w = 0.0;    
        if (!model->omiBSIM4wdvt1wGiven)
            model->omiBSIM4wdvt1w = 0.0;      
        if (!model->omiBSIM4wdvt2wGiven)
            model->omiBSIM4wdvt2w = 0.0;
        if (!model->omiBSIM4wdroutGiven)
            model->omiBSIM4wdrout = 0.0;     
        if (!model->omiBSIM4wdsubGiven)
            model->omiBSIM4wdsub = 0.0;
        if (!model->omiBSIM4wvth0Given)
           model->omiBSIM4wvth0 = 0.0;
        if (!model->omiBSIM4wuaGiven)
            model->omiBSIM4wua = 0.0;
        if (!model->omiBSIM4wua1Given)
            model->omiBSIM4wua1 = 0.0;
        if (!model->omiBSIM4wubGiven)
            model->omiBSIM4wub = 0.0;
        if (!model->omiBSIM4wub1Given)
            model->omiBSIM4wub1 = 0.0;
        if (!model->omiBSIM4wucGiven)
            model->omiBSIM4wuc = 0.0;
        if (!model->omiBSIM4wuc1Given)
            model->omiBSIM4wuc1 = 0.0;
        if (!model->omiBSIM4wudGiven)
            model->omiBSIM4wud = 0.0;
        if (!model->omiBSIM4wud1Given)
            model->omiBSIM4wud1 = 0.0;
        if (!model->omiBSIM4wupGiven)
            model->omiBSIM4wup = 0.0;
        if (!model->omiBSIM4wlpGiven)
            model->omiBSIM4wlp = 0.0;
        if (!model->omiBSIM4wu0Given)
            model->omiBSIM4wu0 = 0.0;
        if (!model->omiBSIM4wuteGiven)
                model->omiBSIM4wute = 0.0; 
        if (!model->omiBSIM4wucsteGiven)
                model->omiBSIM4wucste = 0.0;                 
        if (!model->omiBSIM4wvoffGiven)
                model->omiBSIM4wvoff = 0.0;
        if (!model->omiBSIM4wminvGiven)
            model->omiBSIM4wminv = 0.0;
        if (!model->omiBSIM4wminvcvGiven)
            model->omiBSIM4wminvcv = 0.0;
        if (!model->omiBSIM4wfproutGiven)
            model->omiBSIM4wfprout = 0.0;
        if (!model->omiBSIM4wpditsGiven)
            model->omiBSIM4wpdits = 0.0;
        if (!model->omiBSIM4wpditsdGiven)
            model->omiBSIM4wpditsd = 0.0;
        if (!model->omiBSIM4wdeltaGiven)  
            model->omiBSIM4wdelta = 0.0;
        if (!model->omiBSIM4wrdswGiven)
            model->omiBSIM4wrdsw = 0.0;
        if (!model->omiBSIM4wrdwGiven)
            model->omiBSIM4wrdw = 0.0;
        if (!model->omiBSIM4wrswGiven)
            model->omiBSIM4wrsw = 0.0;
        if (!model->omiBSIM4wprwbGiven)
            model->omiBSIM4wprwb = 0.0;
        if (!model->omiBSIM4wprwgGiven)
            model->omiBSIM4wprwg = 0.0;
        if (!model->omiBSIM4wprtGiven)
            model->omiBSIM4wprt = 0.0;
        if (!model->omiBSIM4weta0Given)
            model->omiBSIM4weta0 = 0.0;
        if (!model->omiBSIM4wetabGiven)
            model->omiBSIM4wetab = 0.0;
        if (!model->omiBSIM4wpclmGiven)
            model->omiBSIM4wpclm = 0.0; 
        if (!model->omiBSIM4wpdibl1Given)
            model->omiBSIM4wpdibl1 = 0.0;
        if (!model->omiBSIM4wpdibl2Given)
            model->omiBSIM4wpdibl2 = 0.0;
        if (!model->omiBSIM4wpdiblbGiven)
            model->omiBSIM4wpdiblb = 0.0;
        if (!model->omiBSIM4wpscbe1Given)
            model->omiBSIM4wpscbe1 = 0.0;
        if (!model->omiBSIM4wpscbe2Given)
            model->omiBSIM4wpscbe2 = 0.0;
        if (!model->omiBSIM4wpvagGiven)
            model->omiBSIM4wpvag = 0.0;     
        if (!model->omiBSIM4wwrGiven)  
            model->omiBSIM4wwr = 0.0;
        if (!model->omiBSIM4wdwgGiven)  
            model->omiBSIM4wdwg = 0.0;
        if (!model->omiBSIM4wdwbGiven)  
            model->omiBSIM4wdwb = 0.0;
        if (!model->omiBSIM4wb0Given)
            model->omiBSIM4wb0 = 0.0;
        if (!model->omiBSIM4wb1Given)  
            model->omiBSIM4wb1 = 0.0;
        if (!model->omiBSIM4walpha0Given)  
            model->omiBSIM4walpha0 = 0.0;
        if (!model->omiBSIM4walpha1Given)
            model->omiBSIM4walpha1 = 0.0;
        if (!model->omiBSIM4wbeta0Given)  
            model->omiBSIM4wbeta0 = 0.0;
        if (!model->omiBSIM4wagidlGiven)
            model->omiBSIM4wagidl = 0.0;
        if (!model->omiBSIM4wbgidlGiven)
            model->omiBSIM4wbgidl = 0.0;
        if (!model->omiBSIM4wcgidlGiven)
            model->omiBSIM4wcgidl = 0.0;
        if (!model->omiBSIM4wegidlGiven)
            model->omiBSIM4wegidl = 0.0;
        if (!model->omiBSIM4wrgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4wrgidl = 0.0;
        if (!model->omiBSIM4wkgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4wkgidl = 0.0;
        if (!model->omiBSIM4wfgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4wfgidl = 0.0;

        if (!model->omiBSIM4wagislGiven)
        {
            if (model->omiBSIM4wagidlGiven)
                model->omiBSIM4wagisl = model->omiBSIM4wagidl;
            else
                model->omiBSIM4wagisl = 0.0;
        }
        if (!model->omiBSIM4wbgislGiven)
        {
            if (model->omiBSIM4wbgidlGiven)
                model->omiBSIM4wbgisl = model->omiBSIM4wbgidl;
            else
                model->omiBSIM4wbgisl = 0.0;
        }
        if (!model->omiBSIM4wcgislGiven)
        {
            if (model->omiBSIM4wcgidlGiven)
                model->omiBSIM4wcgisl = model->omiBSIM4wcgidl;
            else
                model->omiBSIM4wcgisl = 0.0;
        }
        if (!model->omiBSIM4wegislGiven)
        {
            if (model->omiBSIM4wegidlGiven)
                model->omiBSIM4wegisl = model->omiBSIM4wegidl;
            else
                model->omiBSIM4wegisl = 0.0; 
        }
        if (!model->omiBSIM4wrgislGiven)         /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4wrgidlGiven)
                model->omiBSIM4wrgisl = model->omiBSIM4wrgidl;
        }
        if (!model->omiBSIM4wkgislGiven)        /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4wkgidlGiven)
                model->omiBSIM4wkgisl = model->omiBSIM4wkgidl;
        }
        if (!model->omiBSIM4wfgislGiven)        /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4wfgidlGiven)
                model->omiBSIM4wfgisl = model->omiBSIM4wfgidl;
        }
        if (!model->omiBSIM4waigcGiven)
            model->omiBSIM4waigc = 0.0;
        if (!model->omiBSIM4wbigcGiven)
            model->omiBSIM4wbigc = 0.0;
        if (!model->omiBSIM4wcigcGiven)
            model->omiBSIM4wcigc = 0.0;
        if (!model->omiBSIM4aigsdGiven && (model->omiBSIM4aigsGiven || model->omiBSIM4aigdGiven))
        {
            if (!model->omiBSIM4waigsGiven)
                model->omiBSIM4waigs = 0.0;
            if (!model->omiBSIM4waigdGiven)
                model->omiBSIM4waigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4waigsdGiven)
               model->omiBSIM4waigsd = 0.0;
           model->omiBSIM4waigs = model->omiBSIM4waigd = model->omiBSIM4waigsd;
        }
        if (!model->omiBSIM4bigsdGiven && (model->omiBSIM4bigsGiven || model->omiBSIM4bigdGiven))
        {
            if (!model->omiBSIM4wbigsGiven)
                model->omiBSIM4wbigs = 0.0;
            if (!model->omiBSIM4wbigdGiven)
                model->omiBSIM4wbigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4wbigsdGiven)
               model->omiBSIM4wbigsd = 0.0;
           model->omiBSIM4wbigs = model->omiBSIM4wbigd = model->omiBSIM4wbigsd;
        }
        if (!model->omiBSIM4cigsdGiven && (model->omiBSIM4cigsGiven || model->omiBSIM4cigdGiven))
        {
            if (!model->omiBSIM4wcigsGiven)
                model->omiBSIM4wcigs = 0.0;
            if (!model->omiBSIM4wcigdGiven)
                model->omiBSIM4wcigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4wcigsdGiven)
               model->omiBSIM4wcigsd = 0.0;
           model->omiBSIM4wcigs = model->omiBSIM4wcigd = model->omiBSIM4wcigsd;
        }
        if (!model->omiBSIM4waigbaccGiven)
            model->omiBSIM4waigbacc = 0.0;
        if (!model->omiBSIM4wbigbaccGiven)
            model->omiBSIM4wbigbacc = 0.0;
        if (!model->omiBSIM4wcigbaccGiven)
            model->omiBSIM4wcigbacc = 0.0;
        if (!model->omiBSIM4waigbinvGiven)
            model->omiBSIM4waigbinv = 0.0;
        if (!model->omiBSIM4wbigbinvGiven)
            model->omiBSIM4wbigbinv = 0.0;
        if (!model->omiBSIM4wcigbinvGiven)
            model->omiBSIM4wcigbinv = 0.0;
        if (!model->omiBSIM4wnigcGiven)
            model->omiBSIM4wnigc = 0.0;
        if (!model->omiBSIM4wnigbinvGiven)
            model->omiBSIM4wnigbinv = 0.0;
        if (!model->omiBSIM4wnigbaccGiven)
            model->omiBSIM4wnigbacc = 0.0;
        if (!model->omiBSIM4wntoxGiven)
            model->omiBSIM4wntox = 0.0;
        if (!model->omiBSIM4weigbinvGiven)
            model->omiBSIM4weigbinv = 0.0;
        if (!model->omiBSIM4wpigcdGiven)
            model->omiBSIM4wpigcd = 0.0;
        if (!model->omiBSIM4wpoxedgeGiven)
            model->omiBSIM4wpoxedge = 0.0;
        if (!model->omiBSIM4wxrcrg1Given)
            model->omiBSIM4wxrcrg1 = 0.0;
        if (!model->omiBSIM4wxrcrg2Given)
            model->omiBSIM4wxrcrg2 = 0.0;
        if (!model->omiBSIM4weuGiven)
            model->omiBSIM4weu = 0.0;
        if (!model->omiBSIM4wucsGiven)
            model->omiBSIM4wucs = 0.0;
        if (!model->omiBSIM4wvfbGiven)
            model->omiBSIM4wvfb = 0.0;
        if (!model->omiBSIM4wlambdaGiven)
            model->omiBSIM4wlambda = 0.0;
        if (!model->omiBSIM4wvtlGiven)
            model->omiBSIM4wvtl = 0.0;  
        if (!model->omiBSIM4wxnGiven)
            model->omiBSIM4wxn = 0.0;  
        if (!model->omiBSIM4wvfbsdoffGiven)
            model->omiBSIM4wvfbsdoff = 0.0;   
        if (!model->omiBSIM4wtvfbsdoffGiven)
            model->omiBSIM4wtvfbsdoff = 0.0;  
        if (!model->omiBSIM4wtvoffGiven)
            model->omiBSIM4wtvoff = 0.0;  
        if (!model->omiBSIM4wtnfactorGiven)         /* v4.7 temp dep of leakage current  */
            model->omiBSIM4wtnfactor = 0.0;  
        if (!model->omiBSIM4wteta0Given)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4wteta0 = 0.0;  
        if (!model->omiBSIM4wtvoffcvGiven)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4wtvoffcv = 0.0;  

        if (!model->omiBSIM4wcgslGiven)  
            model->omiBSIM4wcgsl = 0.0;
        if (!model->omiBSIM4wcgdlGiven)  
            model->omiBSIM4wcgdl = 0.0;
        if (!model->omiBSIM4wckappasGiven)  
            model->omiBSIM4wckappas = 0.0;
        if (!model->omiBSIM4wckappadGiven)
            model->omiBSIM4wckappad = 0.0;
        if (!model->omiBSIM4wcfGiven)  
            model->omiBSIM4wcf = 0.0;
        if (!model->omiBSIM4wclcGiven)  
            model->omiBSIM4wclc = 0.0;
        if (!model->omiBSIM4wcleGiven)  
            model->omiBSIM4wcle = 0.0;
        if (!model->omiBSIM4wvfbcvGiven)  
            model->omiBSIM4wvfbcv = 0.0;
        if (!model->omiBSIM4wacdeGiven)
            model->omiBSIM4wacde = 0.0;
        if (!model->omiBSIM4wmoinGiven)
            model->omiBSIM4wmoin = 0.0;
        if (!model->omiBSIM4wnoffGiven)
            model->omiBSIM4wnoff = 0.0;
        if (!model->omiBSIM4wvoffcvGiven)
            model->omiBSIM4wvoffcv = 0.0;

        /* Cross-term dependence */
        if (!model->omiBSIM4pcdscGiven)
            model->omiBSIM4pcdsc = 0.0;
        if (!model->omiBSIM4pcdscbGiven)
            model->omiBSIM4pcdscb = 0.0;   
        if (!model->omiBSIM4pcdscdGiven)
            model->omiBSIM4pcdscd = 0.0;
        if (!model->omiBSIM4pcitGiven)
            model->omiBSIM4pcit = 0.0;
        if (!model->omiBSIM4pnfactorGiven)
            model->omiBSIM4pnfactor = 0.0;
        if (!model->omiBSIM4pxjGiven)
            model->omiBSIM4pxj = 0.0;
        if (!model->omiBSIM4pvsatGiven)
            model->omiBSIM4pvsat = 0.0;
        if (!model->omiBSIM4patGiven)
            model->omiBSIM4pat = 0.0;
        if (!model->omiBSIM4pa0Given)
            model->omiBSIM4pa0 = 0.0; 
            
        if (!model->omiBSIM4pagsGiven)
            model->omiBSIM4pags = 0.0;
        if (!model->omiBSIM4pa1Given)
            model->omiBSIM4pa1 = 0.0;
        if (!model->omiBSIM4pa2Given)
            model->omiBSIM4pa2 = 0.0;
        if (!model->omiBSIM4pketaGiven)
            model->omiBSIM4pketa = 0.0;
        if (!model->omiBSIM4pnsubGiven)
            model->omiBSIM4pnsub = 0.0;
        if (!model->omiBSIM4pndepGiven)
            model->omiBSIM4pndep = 0.0;
        if (!model->omiBSIM4pnsdGiven)
            model->omiBSIM4pnsd = 0.0;
        if (!model->omiBSIM4pphinGiven)
            model->omiBSIM4pphin = 0.0;
        if (!model->omiBSIM4pngateGiven)
            model->omiBSIM4pngate = 0.0;
        if (!model->omiBSIM4pvbmGiven)
            model->omiBSIM4pvbm = 0.0;
        if (!model->omiBSIM4pxtGiven)
            model->omiBSIM4pxt = 0.0;
        if (!model->omiBSIM4pkt1Given)
            model->omiBSIM4pkt1 = 0.0; 
        if (!model->omiBSIM4pkt1lGiven)
            model->omiBSIM4pkt1l = 0.0;
        if (!model->omiBSIM4pkt2Given)
            model->omiBSIM4pkt2 = 0.0;
        if (!model->omiBSIM4pk3Given)
            model->omiBSIM4pk3 = 0.0;      
        if (!model->omiBSIM4pk3bGiven)
            model->omiBSIM4pk3b = 0.0;      
        if (!model->omiBSIM4pw0Given)
            model->omiBSIM4pw0 = 0.0;    
        if (!model->omiBSIM4plpe0Given)
            model->omiBSIM4plpe0 = 0.0;
        if (!model->omiBSIM4plpebGiven)
            model->omiBSIM4plpeb = 0.0;
        if (!model->omiBSIM4pdvtp0Given)
            model->omiBSIM4pdvtp0 = 0.0;
        if (!model->omiBSIM4pdvtp1Given)
            model->omiBSIM4pdvtp1 = 0.0;
        if (!model->omiBSIM4pdvtp2Given)        /* New DIBL/Rout */
            model->omiBSIM4pdvtp2 = 0.0;
        if (!model->omiBSIM4pdvtp3Given)
            model->omiBSIM4pdvtp3 = 0.0;
        if (!model->omiBSIM4pdvtp4Given)
            model->omiBSIM4pdvtp4 = 0.0;
        if (!model->omiBSIM4pdvtp5Given)
            model->omiBSIM4pdvtp5 = 0.0;
        if (!model->omiBSIM4pdvt0Given)
            model->omiBSIM4pdvt0 = 0.0;    
        if (!model->omiBSIM4pdvt1Given)
            model->omiBSIM4pdvt1 = 0.0;      
        if (!model->omiBSIM4pdvt2Given)
            model->omiBSIM4pdvt2 = 0.0;
        if (!model->omiBSIM4pdvt0wGiven)
            model->omiBSIM4pdvt0w = 0.0;    
        if (!model->omiBSIM4pdvt1wGiven)
            model->omiBSIM4pdvt1w = 0.0;      
        if (!model->omiBSIM4pdvt2wGiven)
            model->omiBSIM4pdvt2w = 0.0;
        if (!model->omiBSIM4pdroutGiven)
            model->omiBSIM4pdrout = 0.0;     
        if (!model->omiBSIM4pdsubGiven)
            model->omiBSIM4pdsub = 0.0;
        if (!model->omiBSIM4pvth0Given)
           model->omiBSIM4pvth0 = 0.0;
        if (!model->omiBSIM4puaGiven)
            model->omiBSIM4pua = 0.0;
        if (!model->omiBSIM4pua1Given)
            model->omiBSIM4pua1 = 0.0;
        if (!model->omiBSIM4pubGiven)
            model->omiBSIM4pub = 0.0;
        if (!model->omiBSIM4pub1Given)
            model->omiBSIM4pub1 = 0.0;
        if (!model->omiBSIM4pucGiven)
            model->omiBSIM4puc = 0.0;
        if (!model->omiBSIM4puc1Given)
            model->omiBSIM4puc1 = 0.0;
        if (!model->omiBSIM4pudGiven)
            model->omiBSIM4pud = 0.0;
        if (!model->omiBSIM4pud1Given)
            model->omiBSIM4pud1 = 0.0;
        if (!model->omiBSIM4pupGiven)
            model->omiBSIM4pup = 0.0;
        if (!model->omiBSIM4plpGiven)
            model->omiBSIM4plp = 0.0;
        if (!model->omiBSIM4pu0Given)
            model->omiBSIM4pu0 = 0.0;
        if (!model->omiBSIM4puteGiven)
            model->omiBSIM4pute = 0.0;  
     if (!model->omiBSIM4pucsteGiven)
            model->omiBSIM4pucste = 0.0;                 
        if (!model->omiBSIM4pvoffGiven)
            model->omiBSIM4pvoff = 0.0;
        if (!model->omiBSIM4pminvGiven)
            model->omiBSIM4pminv = 0.0;
        if (!model->omiBSIM4pminvcvGiven)
            model->omiBSIM4pminvcv = 0.0;
        if (!model->omiBSIM4pfproutGiven)
            model->omiBSIM4pfprout = 0.0;
        if (!model->omiBSIM4ppditsGiven)
            model->omiBSIM4ppdits = 0.0;
        if (!model->omiBSIM4ppditsdGiven)
            model->omiBSIM4ppditsd = 0.0;
        if (!model->omiBSIM4pdeltaGiven)  
            model->omiBSIM4pdelta = 0.0;
        if (!model->omiBSIM4prdswGiven)
            model->omiBSIM4prdsw = 0.0;
        if (!model->omiBSIM4prdwGiven)
            model->omiBSIM4prdw = 0.0;
        if (!model->omiBSIM4prswGiven)
            model->omiBSIM4prsw = 0.0;
        if (!model->omiBSIM4pprwbGiven)
            model->omiBSIM4pprwb = 0.0;
        if (!model->omiBSIM4pprwgGiven)
            model->omiBSIM4pprwg = 0.0;
        if (!model->omiBSIM4pprtGiven)
            model->omiBSIM4pprt = 0.0;
        if (!model->omiBSIM4peta0Given)
            model->omiBSIM4peta0 = 0.0;
        if (!model->omiBSIM4petabGiven)
            model->omiBSIM4petab = 0.0;
        if (!model->omiBSIM4ppclmGiven)
            model->omiBSIM4ppclm = 0.0; 
        if (!model->omiBSIM4ppdibl1Given)
            model->omiBSIM4ppdibl1 = 0.0;
        if (!model->omiBSIM4ppdibl2Given)
            model->omiBSIM4ppdibl2 = 0.0;
        if (!model->omiBSIM4ppdiblbGiven)
            model->omiBSIM4ppdiblb = 0.0;
        if (!model->omiBSIM4ppscbe1Given)
            model->omiBSIM4ppscbe1 = 0.0;
        if (!model->omiBSIM4ppscbe2Given)
            model->omiBSIM4ppscbe2 = 0.0;
        if (!model->omiBSIM4ppvagGiven)
            model->omiBSIM4ppvag = 0.0;     
        if (!model->omiBSIM4pwrGiven)  
            model->omiBSIM4pwr = 0.0;
        if (!model->omiBSIM4pdwgGiven)  
            model->omiBSIM4pdwg = 0.0;
        if (!model->omiBSIM4pdwbGiven)  
            model->omiBSIM4pdwb = 0.0;
        if (!model->omiBSIM4pb0Given)
            model->omiBSIM4pb0 = 0.0;
        if (!model->omiBSIM4pb1Given)  
            model->omiBSIM4pb1 = 0.0;
        if (!model->omiBSIM4palpha0Given)  
            model->omiBSIM4palpha0 = 0.0;
        if (!model->omiBSIM4palpha1Given)
            model->omiBSIM4palpha1 = 0.0;
        if (!model->omiBSIM4pbeta0Given)  
            model->omiBSIM4pbeta0 = 0.0;
        if (!model->omiBSIM4pagidlGiven)
            model->omiBSIM4pagidl = 0.0;
        if (!model->omiBSIM4pbgidlGiven)
            model->omiBSIM4pbgidl = 0.0;
        if (!model->omiBSIM4pcgidlGiven)
            model->omiBSIM4pcgidl = 0.0;
        if (!model->omiBSIM4pegidlGiven)
            model->omiBSIM4pegidl = 0.0;
        if (!model->omiBSIM4prgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4prgidl = 0.0;
        if (!model->omiBSIM4pkgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4pkgidl = 0.0;
        if (!model->omiBSIM4pfgidlGiven)        /* v4.7 New GIDL/GISL */
            model->omiBSIM4pfgidl = 0.0;

        if (!model->omiBSIM4pagislGiven)
        {
            if (model->omiBSIM4pagidlGiven)
                model->omiBSIM4pagisl = model->omiBSIM4pagidl;
            else
                model->omiBSIM4pagisl = 0.0;
        }
        if (!model->omiBSIM4pbgislGiven)
        {
            if (model->omiBSIM4pbgidlGiven)
                model->omiBSIM4pbgisl = model->omiBSIM4pbgidl;
            else
                model->omiBSIM4pbgisl = 0.0;
        }
        if (!model->omiBSIM4pcgislGiven)
        {
            if (model->omiBSIM4pcgidlGiven)
                model->omiBSIM4pcgisl = model->omiBSIM4pcgidl;
            else
                model->omiBSIM4pcgisl = 0.0;
        }
        if (!model->omiBSIM4pegislGiven)
        {
            if (model->omiBSIM4pegidlGiven)
                model->omiBSIM4pegisl = model->omiBSIM4pegidl;
            else
                model->omiBSIM4pegisl = 0.0; 
        }
        if (!model->omiBSIM4prgislGiven)         /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4prgidlGiven)
                model->omiBSIM4prgisl = model->omiBSIM4prgidl;
        }
        if (!model->omiBSIM4pkgislGiven)        /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4pkgidlGiven)
                model->omiBSIM4pkgisl = model->omiBSIM4pkgidl;
        }
        if (!model->omiBSIM4pfgislGiven)        /* v4.7 New GIDL/GISL */
        {
            if (model->omiBSIM4pfgidlGiven)
                model->omiBSIM4pfgisl = model->omiBSIM4pfgidl;
        }
        if (!model->omiBSIM4paigcGiven)
            model->omiBSIM4paigc = 0.0;
        if (!model->omiBSIM4pbigcGiven)
            model->omiBSIM4pbigc = 0.0;
        if (!model->omiBSIM4pcigcGiven)
            model->omiBSIM4pcigc = 0.0;
        if (!model->omiBSIM4aigsdGiven && (model->omiBSIM4aigsGiven || model->omiBSIM4aigdGiven))
        {
            if (!model->omiBSIM4paigsGiven)
                model->omiBSIM4paigs = 0.0;
            if (!model->omiBSIM4paigdGiven)
                model->omiBSIM4paigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4paigsdGiven)
               model->omiBSIM4paigsd = 0.0;
           model->omiBSIM4paigs = model->omiBSIM4paigd = model->omiBSIM4paigsd;
        }
        if (!model->omiBSIM4bigsdGiven && (model->omiBSIM4bigsGiven || model->omiBSIM4bigdGiven))
        {
            if (!model->omiBSIM4pbigsGiven)
                model->omiBSIM4pbigs = 0.0;
            if (!model->omiBSIM4pbigdGiven)
                model->omiBSIM4pbigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4pbigsdGiven)
               model->omiBSIM4pbigsd = 0.0;
           model->omiBSIM4pbigs = model->omiBSIM4pbigd = model->omiBSIM4pbigsd;
        }
        if (!model->omiBSIM4cigsdGiven && (model->omiBSIM4cigsGiven || model->omiBSIM4cigdGiven))
        {
            if (!model->omiBSIM4pcigsGiven)
                model->omiBSIM4pcigs = 0.0;
            if (!model->omiBSIM4pcigdGiven)
                model->omiBSIM4pcigd = 0.0;
        }
        else
        {
           if (!model->omiBSIM4pcigsdGiven)
               model->omiBSIM4pcigsd = 0.0;
           model->omiBSIM4pcigs = model->omiBSIM4pcigd = model->omiBSIM4pcigsd;
        }
        if (!model->omiBSIM4paigbaccGiven)
            model->omiBSIM4paigbacc = 0.0;
        if (!model->omiBSIM4pbigbaccGiven)
            model->omiBSIM4pbigbacc = 0.0;
        if (!model->omiBSIM4pcigbaccGiven)
            model->omiBSIM4pcigbacc = 0.0;
        if (!model->omiBSIM4paigbinvGiven)
            model->omiBSIM4paigbinv = 0.0;
        if (!model->omiBSIM4pbigbinvGiven)
            model->omiBSIM4pbigbinv = 0.0;
        if (!model->omiBSIM4pcigbinvGiven)
            model->omiBSIM4pcigbinv = 0.0;
        if (!model->omiBSIM4pnigcGiven)
            model->omiBSIM4pnigc = 0.0;
        if (!model->omiBSIM4pnigbinvGiven)
            model->omiBSIM4pnigbinv = 0.0;
        if (!model->omiBSIM4pnigbaccGiven)
            model->omiBSIM4pnigbacc = 0.0;
        if (!model->omiBSIM4pntoxGiven)
            model->omiBSIM4pntox = 0.0;
        if (!model->omiBSIM4peigbinvGiven)
            model->omiBSIM4peigbinv = 0.0;
        if (!model->omiBSIM4ppigcdGiven)
            model->omiBSIM4ppigcd = 0.0;
        if (!model->omiBSIM4ppoxedgeGiven)
            model->omiBSIM4ppoxedge = 0.0;
        if (!model->omiBSIM4pxrcrg1Given)
            model->omiBSIM4pxrcrg1 = 0.0;
        if (!model->omiBSIM4pxrcrg2Given)
            model->omiBSIM4pxrcrg2 = 0.0;
        if (!model->omiBSIM4peuGiven)
            model->omiBSIM4peu = 0.0;
                if (!model->omiBSIM4pucsGiven)
            model->omiBSIM4pucs = 0.0;
        if (!model->omiBSIM4pvfbGiven)
            model->omiBSIM4pvfb = 0.0;
        if (!model->omiBSIM4plambdaGiven)
            model->omiBSIM4plambda = 0.0;
        if (!model->omiBSIM4pvtlGiven)
            model->omiBSIM4pvtl = 0.0;  
        if (!model->omiBSIM4pxnGiven)
            model->omiBSIM4pxn = 0.0;  
        if (!model->omiBSIM4pvfbsdoffGiven)
            model->omiBSIM4pvfbsdoff = 0.0;   
        if (!model->omiBSIM4ptvfbsdoffGiven)
            model->omiBSIM4ptvfbsdoff = 0.0;  
        if (!model->omiBSIM4ptvoffGiven)
            model->omiBSIM4ptvoff = 0.0;  
        if (!model->omiBSIM4ptnfactorGiven)         /* v4.7 temp dep of leakage current  */
            model->omiBSIM4ptnfactor = 0.0;  
        if (!model->omiBSIM4pteta0Given)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4pteta0 = 0.0;  
        if (!model->omiBSIM4ptvoffcvGiven)                /* v4.7 temp dep of leakage current  */
            model->omiBSIM4ptvoffcv = 0.0;  

        if (!model->omiBSIM4pcgslGiven)  
            model->omiBSIM4pcgsl = 0.0;
        if (!model->omiBSIM4pcgdlGiven)  
            model->omiBSIM4pcgdl = 0.0;
        if (!model->omiBSIM4pckappasGiven)  
            model->omiBSIM4pckappas = 0.0;
        if (!model->omiBSIM4pckappadGiven)
            model->omiBSIM4pckappad = 0.0;
        if (!model->omiBSIM4pcfGiven)  
            model->omiBSIM4pcf = 0.0;
        if (!model->omiBSIM4pclcGiven)  
            model->omiBSIM4pclc = 0.0;
        if (!model->omiBSIM4pcleGiven)  
            model->omiBSIM4pcle = 0.0;
        if (!model->omiBSIM4pvfbcvGiven)  
            model->omiBSIM4pvfbcv = 0.0;
        if (!model->omiBSIM4pacdeGiven)
            model->omiBSIM4pacde = 0.0;
        if (!model->omiBSIM4pmoinGiven)
            model->omiBSIM4pmoin = 0.0;
        if (!model->omiBSIM4pnoffGiven)
            model->omiBSIM4pnoff = 0.0;
        if (!model->omiBSIM4pvoffcvGiven)
            model->omiBSIM4pvoffcv = 0.0;

        if (!model->omiBSIM4gamma1Given)
            model->omiBSIM4gamma1 = 0.0;
        if (!model->omiBSIM4lgamma1Given)
            model->omiBSIM4lgamma1 = 0.0;
        if (!model->omiBSIM4wgamma1Given)
            model->omiBSIM4wgamma1 = 0.0;
        if (!model->omiBSIM4pgamma1Given)
            model->omiBSIM4pgamma1 = 0.0;
        if (!model->omiBSIM4gamma2Given)
            model->omiBSIM4gamma2 = 0.0;
        if (!model->omiBSIM4lgamma2Given)
            model->omiBSIM4lgamma2 = 0.0;
        if (!model->omiBSIM4wgamma2Given)
            model->omiBSIM4wgamma2 = 0.0;
        if (!model->omiBSIM4pgamma2Given)
            model->omiBSIM4pgamma2 = 0.0;
        if (!model->omiBSIM4vbxGiven)
            model->omiBSIM4vbx = 0.0;
        if (!model->omiBSIM4lvbxGiven)
            model->omiBSIM4lvbx = 0.0;
        if (!model->omiBSIM4wvbxGiven)
            model->omiBSIM4wvbx = 0.0;
        if (!model->omiBSIM4pvbxGiven)
            model->omiBSIM4pvbx = 0.0;

        /* unit degree celcius */
        if (!model->omiBSIM4tnomGiven)  
            model->omiBSIM4tnom = ckt->CKTnomTemp; 
        if (!model->omiBSIM4LintGiven)  
           model->omiBSIM4Lint = 0.0;
        if (!model->omiBSIM4LlGiven)  
           model->omiBSIM4Ll = 0.0;
        if (!model->omiBSIM4LlcGiven)
           model->omiBSIM4Llc = model->omiBSIM4Ll;
        if (!model->omiBSIM4LlnGiven)  
           model->omiBSIM4Lln = 1.0;
        if (!model->omiBSIM4LwGiven)  
           model->omiBSIM4Lw = 0.0;
        if (!model->omiBSIM4LwcGiven)
           model->omiBSIM4Lwc = model->omiBSIM4Lw;
        if (!model->omiBSIM4LwnGiven)  
           model->omiBSIM4Lwn = 1.0;
        if (!model->omiBSIM4LwlGiven)  
           model->omiBSIM4Lwl = 0.0;
        if (!model->omiBSIM4LwlcGiven)
           model->omiBSIM4Lwlc = model->omiBSIM4Lwl;
        if (!model->omiBSIM4LminGiven)  
           model->omiBSIM4Lmin = 0.0;
        if (!model->omiBSIM4LmaxGiven)  
           model->omiBSIM4Lmax = 1.0;
        if (!model->omiBSIM4WintGiven)  
           model->omiBSIM4Wint = 0.0;
        if (!model->omiBSIM4WlGiven)  
           model->omiBSIM4Wl = 0.0;
        if (!model->omiBSIM4WlcGiven)
           model->omiBSIM4Wlc = model->omiBSIM4Wl;
        if (!model->omiBSIM4WlnGiven)  
           model->omiBSIM4Wln = 1.0;
        if (!model->omiBSIM4WwGiven)  
           model->omiBSIM4Ww = 0.0;
        if (!model->omiBSIM4WwcGiven)
           model->omiBSIM4Wwc = model->omiBSIM4Ww;
        if (!model->omiBSIM4WwnGiven)  
           model->omiBSIM4Wwn = 1.0;
        if (!model->omiBSIM4WwlGiven)  
           model->omiBSIM4Wwl = 0.0;
        if (!model->omiBSIM4WwlcGiven)
           model->omiBSIM4Wwlc = model->omiBSIM4Wwl;
        if (!model->omiBSIM4WminGiven)  
           model->omiBSIM4Wmin = 0.0;
        if (!model->omiBSIM4WmaxGiven)  
           model->omiBSIM4Wmax = 1.0;
        if (!model->omiBSIM4dwcGiven)  
           model->omiBSIM4dwc = model->omiBSIM4Wint;
        if (!model->omiBSIM4dlcGiven)  
           model->omiBSIM4dlc = model->omiBSIM4Lint;
        if (!model->omiBSIM4xlGiven)  
           model->omiBSIM4xl = 0.0;
        if (!model->omiBSIM4xwGiven)  
           model->omiBSIM4xw = 0.0;
        if (!model->omiBSIM4dlcigGiven)
           model->omiBSIM4dlcig = model->omiBSIM4Lint;
        if (!model->omiBSIM4dlcigdGiven)
        {
           if (model->omiBSIM4dlcigGiven) 
               model->omiBSIM4dlcigd = model->omiBSIM4dlcig;
           else             
               model->omiBSIM4dlcigd = model->omiBSIM4Lint;
        }
        if (!model->omiBSIM4dwjGiven)
           model->omiBSIM4dwj = model->omiBSIM4dwc;
        if (!model->omiBSIM4cfGiven)
           model->omiBSIM4cf = 2.0 * model->omiBSIM4epsrox * EPS0 / PI
                          * log(1.0 + 0.4e-6 / model->omiBSIM4toxe);

        if (!model->omiBSIM4xpartGiven)
            model->omiBSIM4xpart = 0.0;
        if (!model->omiBSIM4sheetResistanceGiven)
            model->omiBSIM4sheetResistance = 0.0;

        if (!model->omiBSIM4SunitAreaJctCapGiven)
            model->omiBSIM4SunitAreaJctCap = 5.0E-4;
        if (!model->omiBSIM4DunitAreaJctCapGiven)
            model->omiBSIM4DunitAreaJctCap = model->omiBSIM4SunitAreaJctCap;
        if (!model->omiBSIM4SunitLengthSidewallJctCapGiven)
            model->omiBSIM4SunitLengthSidewallJctCap = 5.0E-10;
        if (!model->omiBSIM4DunitLengthSidewallJctCapGiven)
            model->omiBSIM4DunitLengthSidewallJctCap = model->omiBSIM4SunitLengthSidewallJctCap;
        if (!model->omiBSIM4SunitLengthGateSidewallJctCapGiven)
            model->omiBSIM4SunitLengthGateSidewallJctCap = model->omiBSIM4SunitLengthSidewallJctCap ;
        if (!model->omiBSIM4DunitLengthGateSidewallJctCapGiven)
            model->omiBSIM4DunitLengthGateSidewallJctCap = model->omiBSIM4SunitLengthGateSidewallJctCap;
        if (!model->omiBSIM4SjctSatCurDensityGiven)
            model->omiBSIM4SjctSatCurDensity = 1.0E-4;
        if (!model->omiBSIM4DjctSatCurDensityGiven)
            model->omiBSIM4DjctSatCurDensity = model->omiBSIM4SjctSatCurDensity;
        if (!model->omiBSIM4SjctSidewallSatCurDensityGiven)
            model->omiBSIM4SjctSidewallSatCurDensity = 0.0;
        if (!model->omiBSIM4DjctSidewallSatCurDensityGiven)
            model->omiBSIM4DjctSidewallSatCurDensity = model->omiBSIM4SjctSidewallSatCurDensity;
        if (!model->omiBSIM4SjctGateSidewallSatCurDensityGiven)
            model->omiBSIM4SjctGateSidewallSatCurDensity = 0.0;
        if (!model->omiBSIM4DjctGateSidewallSatCurDensityGiven)
            model->omiBSIM4DjctGateSidewallSatCurDensity = model->omiBSIM4SjctGateSidewallSatCurDensity;
        if (!model->omiBSIM4SbulkJctPotentialGiven)
            model->omiBSIM4SbulkJctPotential = 1.0;
        if (!model->omiBSIM4DbulkJctPotentialGiven)
            model->omiBSIM4DbulkJctPotential = model->omiBSIM4SbulkJctPotential;
        if (!model->omiBSIM4SsidewallJctPotentialGiven)
            model->omiBSIM4SsidewallJctPotential = 1.0;
        if (!model->omiBSIM4DsidewallJctPotentialGiven)
            model->omiBSIM4DsidewallJctPotential = model->omiBSIM4SsidewallJctPotential;
        if (!model->omiBSIM4SGatesidewallJctPotentialGiven)
            model->omiBSIM4SGatesidewallJctPotential = model->omiBSIM4SsidewallJctPotential;
        if (!model->omiBSIM4DGatesidewallJctPotentialGiven)
            model->omiBSIM4DGatesidewallJctPotential = model->omiBSIM4SGatesidewallJctPotential;
        if (!model->omiBSIM4SbulkJctBotGradingCoeffGiven)
            model->omiBSIM4SbulkJctBotGradingCoeff = 0.5;
        if (!model->omiBSIM4DbulkJctBotGradingCoeffGiven)
            model->omiBSIM4DbulkJctBotGradingCoeff = model->omiBSIM4SbulkJctBotGradingCoeff;
        if (!model->omiBSIM4SbulkJctSideGradingCoeffGiven)
            model->omiBSIM4SbulkJctSideGradingCoeff = 0.33;
        if (!model->omiBSIM4DbulkJctSideGradingCoeffGiven)
            model->omiBSIM4DbulkJctSideGradingCoeff = model->omiBSIM4SbulkJctSideGradingCoeff;
        if (!model->omiBSIM4SbulkJctGateSideGradingCoeffGiven)
            model->omiBSIM4SbulkJctGateSideGradingCoeff = model->omiBSIM4SbulkJctSideGradingCoeff;
        if (!model->omiBSIM4DbulkJctGateSideGradingCoeffGiven)
            model->omiBSIM4DbulkJctGateSideGradingCoeff = model->omiBSIM4SbulkJctGateSideGradingCoeff;
        if (!model->omiBSIM4SjctEmissionCoeffGiven)
            model->omiBSIM4SjctEmissionCoeff = 1.0;
        if (!model->omiBSIM4DjctEmissionCoeffGiven)
            model->omiBSIM4DjctEmissionCoeff = model->omiBSIM4SjctEmissionCoeff;
        if (!model->omiBSIM4SjctTempExponentGiven)
            model->omiBSIM4SjctTempExponent = 3.0;
        if (!model->omiBSIM4DjctTempExponentGiven)
            model->omiBSIM4DjctTempExponent = model->omiBSIM4SjctTempExponent;

        if (!model->omiBSIM4jtssGiven)
            model->omiBSIM4jtss = 0.0;
        if (!model->omiBSIM4jtsdGiven)
            model->omiBSIM4jtsd = model->omiBSIM4jtss;
        if (!model->omiBSIM4jtsswsGiven)
            model->omiBSIM4jtssws = 0.0;
        if (!model->omiBSIM4jtsswdGiven)
            model->omiBSIM4jtsswd = model->omiBSIM4jtssws;
        if (!model->omiBSIM4jtsswgsGiven)
            model->omiBSIM4jtsswgs = 0.0;
        if (!model->omiBSIM4jtsswgdGiven)
            model->omiBSIM4jtsswgd = model->omiBSIM4jtsswgs;
                if (!model->omiBSIM4jtweffGiven)
                    model->omiBSIM4jtweff = 0.0;
        if (!model->omiBSIM4njtsGiven)
            model->omiBSIM4njts = 20.0;
        if (!model->omiBSIM4njtsswGiven)
            model->omiBSIM4njtssw = 20.0;
        if (!model->omiBSIM4njtsswgGiven)
            model->omiBSIM4njtsswg = 20.0;
        if (!model->omiBSIM4njtsdGiven)
        {
            if (model->omiBSIM4njtsGiven)
                model->omiBSIM4njtsd =  model->omiBSIM4njts;
            else
              model->omiBSIM4njtsd = 20.0;
        }
        if (!model->omiBSIM4njtsswdGiven)
        {
            if (model->omiBSIM4njtsswGiven)
                model->omiBSIM4njtsswd =  model->omiBSIM4njtssw;
            else
              model->omiBSIM4njtsswd = 20.0;
        }
        if (!model->omiBSIM4njtsswgdGiven)
        {
            if (model->omiBSIM4njtsswgGiven)
                model->omiBSIM4njtsswgd =  model->omiBSIM4njtsswg;
            else
              model->omiBSIM4njtsswgd = 20.0;
        }
        if (!model->omiBSIM4xtssGiven)
            model->omiBSIM4xtss = 0.02;
        if (!model->omiBSIM4xtsdGiven)
            model->omiBSIM4xtsd = model->omiBSIM4xtss;
        if (!model->omiBSIM4xtsswsGiven)
            model->omiBSIM4xtssws = 0.02;
        if (!model->omiBSIM4xtsswdGiven)
            model->omiBSIM4xtsswd = model->omiBSIM4xtssws;
        if (!model->omiBSIM4xtsswgsGiven)
            model->omiBSIM4xtsswgs = 0.02;
        if (!model->omiBSIM4xtsswgdGiven)
            model->omiBSIM4xtsswgd = model->omiBSIM4xtsswgs;
        if (!model->omiBSIM4tnjtsGiven)
            model->omiBSIM4tnjts = 0.0;
        if (!model->omiBSIM4tnjtsswGiven)
            model->omiBSIM4tnjtssw = 0.0;
        if (!model->omiBSIM4tnjtsswgGiven)
            model->omiBSIM4tnjtsswg = 0.0;
        if (!model->omiBSIM4tnjtsdGiven)
        {
            if (model->omiBSIM4tnjtsGiven)
                model->omiBSIM4tnjtsd =  model->omiBSIM4tnjts;
            else
              model->omiBSIM4tnjtsd = 0.0;
        }
        if (!model->omiBSIM4tnjtsswdGiven)
        {
            if (model->omiBSIM4tnjtsswGiven)
                model->omiBSIM4tnjtsswd =  model->omiBSIM4tnjtssw;
            else
              model->omiBSIM4tnjtsswd = 0.0;
        }
        if (!model->omiBSIM4tnjtsswgdGiven)
        {
            if (model->omiBSIM4tnjtsswgGiven)
                model->omiBSIM4tnjtsswgd =  model->omiBSIM4tnjtsswg;
            else
              model->omiBSIM4tnjtsswgd = 0.0;
        }
        if (!model->omiBSIM4vtssGiven)
            model->omiBSIM4vtss = 10.0;
        if (!model->omiBSIM4vtsdGiven)
            model->omiBSIM4vtsd = model->omiBSIM4vtss;
        if (!model->omiBSIM4vtsswsGiven)
            model->omiBSIM4vtssws = 10.0;
        if (!model->omiBSIM4vtsswdGiven)
            model->omiBSIM4vtsswd = model->omiBSIM4vtssws;
        if (!model->omiBSIM4vtsswgsGiven)
            model->omiBSIM4vtsswgs = 10.0;
        if (!model->omiBSIM4vtsswgdGiven)
            model->omiBSIM4vtsswgd = model->omiBSIM4vtsswgs;

        if (!model->omiBSIM4oxideTrapDensityAGiven)
        {   if (model->omiBSIM4type == NMOS)
                model->omiBSIM4oxideTrapDensityA = 6.25e41;
            else
                model->omiBSIM4oxideTrapDensityA= 6.188e40;
        }
        if (!model->omiBSIM4oxideTrapDensityBGiven)
        {   if (model->omiBSIM4type == NMOS)
                model->omiBSIM4oxideTrapDensityB = 3.125e26;
            else
                model->omiBSIM4oxideTrapDensityB = 1.5e25;
        }
        if (!model->omiBSIM4oxideTrapDensityCGiven)
            model->omiBSIM4oxideTrapDensityC = 8.75e9;
        if (!model->omiBSIM4emGiven)
            model->omiBSIM4em = 4.1e7; /* V/m */
        if (!model->omiBSIM4efGiven)
            model->omiBSIM4ef = 1.0;
        if (!model->omiBSIM4afGiven)
            model->omiBSIM4af = 1.0;
        if (!model->omiBSIM4kfGiven)
            model->omiBSIM4kf = 0.0;

        if (!model->omiBSIM4vgsMaxGiven)
            model->omiBSIM4vgsMax = 1e99;
        if (!model->omiBSIM4vgdMaxGiven)
            model->omiBSIM4vgdMax = 1e99;
        if (!model->omiBSIM4vgbMaxGiven)
            model->omiBSIM4vgbMax = 1e99;
        if (!model->omiBSIM4vdsMaxGiven)
            model->omiBSIM4vdsMax = 1e99;
        if (!model->omiBSIM4vbsMaxGiven)
            model->omiBSIM4vbsMax = 1e99;
        if (!model->omiBSIM4vbdMaxGiven)
            model->omiBSIM4vbdMax = 1e99;
        if (!model->omiBSIM4vgsrMaxGiven)
            model->omiBSIM4vgsrMax = 1e99;
        if (!model->omiBSIM4vgdrMaxGiven)
            model->omiBSIM4vgdrMax = 1e99;
        if (!model->omiBSIM4vgbrMaxGiven)
            model->omiBSIM4vgbrMax = 1e99;
        if (!model->omiBSIM4vbsrMaxGiven)
            model->omiBSIM4vbsrMax = 1e99;
        if (!model->omiBSIM4vbdrMaxGiven)
            model->omiBSIM4vbdrMax = 1e99;

        /* stress effect */
        if (!model->omiBSIM4sarefGiven)
            model->omiBSIM4saref = 1e-6; /* m */
        if (!model->omiBSIM4sbrefGiven)
            model->omiBSIM4sbref = 1e-6;  /* m */
        if (!model->omiBSIM4wlodGiven)
            model->omiBSIM4wlod = 0;  /* m */
        if (!model->omiBSIM4ku0Given)
            model->omiBSIM4ku0 = 0; /* 1/m */
        if (!model->omiBSIM4kvsatGiven)
            model->omiBSIM4kvsat = 0;
        if (!model->omiBSIM4kvth0Given) /* m */
            model->omiBSIM4kvth0 = 0;
        if (!model->omiBSIM4tku0Given)
            model->omiBSIM4tku0 = 0;
        if (!model->omiBSIM4llodku0Given)
            model->omiBSIM4llodku0 = 0;
        if (!model->omiBSIM4wlodku0Given)
            model->omiBSIM4wlodku0 = 0;
        if (!model->omiBSIM4llodvthGiven)
            model->omiBSIM4llodvth = 0;
        if (!model->omiBSIM4wlodvthGiven)
            model->omiBSIM4wlodvth = 0;
        if (!model->omiBSIM4lku0Given)
            model->omiBSIM4lku0 = 0;
        if (!model->omiBSIM4wku0Given)
            model->omiBSIM4wku0 = 0;
        if (!model->omiBSIM4pku0Given)
            model->omiBSIM4pku0 = 0;
        if (!model->omiBSIM4lkvth0Given)
            model->omiBSIM4lkvth0 = 0;
        if (!model->omiBSIM4wkvth0Given)
            model->omiBSIM4wkvth0 = 0;
        if (!model->omiBSIM4pkvth0Given)
            model->omiBSIM4pkvth0 = 0;
        if (!model->omiBSIM4stk2Given)
            model->omiBSIM4stk2 = 0;
        if (!model->omiBSIM4lodk2Given)
            model->omiBSIM4lodk2 = 1.0;
        if (!model->omiBSIM4steta0Given)
            model->omiBSIM4steta0 = 0;
        if (!model->omiBSIM4lodeta0Given)
            model->omiBSIM4lodeta0 = 1.0;

        /* Well Proximity Effect  */
        if (!model->omiBSIM4webGiven)
            model->omiBSIM4web = 0.0; 
        if (!model->omiBSIM4wecGiven)
            model->omiBSIM4wec = 0.0;
        if (!model->omiBSIM4kvth0weGiven)
            model->omiBSIM4kvth0we = 0.0; 
        if (!model->omiBSIM4k2weGiven)
            model->omiBSIM4k2we = 0.0; 
        if (!model->omiBSIM4ku0weGiven)
            model->omiBSIM4ku0we = 0.0; 
        if (!model->omiBSIM4screfGiven)
            model->omiBSIM4scref = 1.0E-6; /* m */
        if (!model->omiBSIM4wpemodGiven)
            model->omiBSIM4wpemod = 0; 
        else if ((model->omiBSIM4wpemod != 0) && (model->omiBSIM4wpemod != 1))
        {   model->omiBSIM4wpemod = 0;
            printf("Warning: wpemod has been set to its default value: 0.\n");
        }
        if (!model->omiBSIM4lkvth0weGiven)
            model->omiBSIM4lkvth0we = 0; 
        if (!model->omiBSIM4lk2weGiven)
            model->omiBSIM4lk2we = 0;
        if (!model->omiBSIM4lku0weGiven)
            model->omiBSIM4lku0we = 0;
        if (!model->omiBSIM4wkvth0weGiven)
            model->omiBSIM4wkvth0we = 0; 
        if (!model->omiBSIM4wk2weGiven)
            model->omiBSIM4wk2we = 0;
        if (!model->omiBSIM4wku0weGiven)
            model->omiBSIM4wku0we = 0;
        if (!model->omiBSIM4pkvth0weGiven)
            model->omiBSIM4pkvth0we = 0; 
        if (!model->omiBSIM4pk2weGiven)
            model->omiBSIM4pk2we = 0;
        if (!model->omiBSIM4pku0weGiven)
            model->omiBSIM4pku0we = 0;

        DMCGeff = model->omiBSIM4dmcg - model->omiBSIM4dmcgt;
        DMCIeff = model->omiBSIM4dmci;
        DMDGeff = model->omiBSIM4dmdg - model->omiBSIM4dmcgt;

        /*
         * End processing models and begin to loop
         * through all the instances of the model
         */

        for (here = omiBSIM4instances(model); here != NULL ;
             here=omiBSIM4nextInstance(here)) 
        {
            /* allocate a chunk of the state vector */
            here->omiBSIM4states = *states;
            *states += omiBSIM4numStates;

            /* perform the parameter defaulting */
            if (!here->omiBSIM4lGiven)
                here->omiBSIM4l = 5.0e-6;
            if (!here->omiBSIM4wGiven)
                here->omiBSIM4w = 5.0e-6;
            if (!here->omiBSIM4mGiven)
                here->omiBSIM4m = 1.0;
            if (!here->omiBSIM4nfGiven)
                here->omiBSIM4nf = 1.0;
            if (!here->omiBSIM4minGiven)
                here->omiBSIM4min = 0; /* integer */
            if (!here->omiBSIM4icVDSGiven)
                here->omiBSIM4icVDS = 0.0;
            if (!here->omiBSIM4icVGSGiven)
                here->omiBSIM4icVGS = 0.0;
            if (!here->omiBSIM4icVBSGiven)
                here->omiBSIM4icVBS = 0.0;
            if (!here->omiBSIM4drainAreaGiven)
                here->omiBSIM4drainArea = 0.0;
            if (!here->omiBSIM4drainPerimeterGiven)
                here->omiBSIM4drainPerimeter = 0.0;
            if (!here->omiBSIM4drainSquaresGiven)
                here->omiBSIM4drainSquares = 1.0;
            if (!here->omiBSIM4sourceAreaGiven)
                here->omiBSIM4sourceArea = 0.0;
            if (!here->omiBSIM4sourcePerimeterGiven)
                here->omiBSIM4sourcePerimeter = 0.0;
            if (!here->omiBSIM4sourceSquaresGiven)
                here->omiBSIM4sourceSquares = 1.0;

            if (!here->omiBSIM4rbdbGiven)
                here->omiBSIM4rbdb = model->omiBSIM4rbdb; /* in ohm */
            if (!here->omiBSIM4rbsbGiven)
                here->omiBSIM4rbsb = model->omiBSIM4rbsb;
            if (!here->omiBSIM4rbpbGiven)
                here->omiBSIM4rbpb = model->omiBSIM4rbpb;
            if (!here->omiBSIM4rbpsGiven)
                here->omiBSIM4rbps = model->omiBSIM4rbps;
            if (!here->omiBSIM4rbpdGiven)
                here->omiBSIM4rbpd = model->omiBSIM4rbpd;
            if (!here->omiBSIM4delvtoGiven)
                here->omiBSIM4delvto = 0.0;
            if (!here->omiBSIM4mulu0Given)
                here->omiBSIM4mulu0 = 1.0;
            if (!here->omiBSIM4xgwGiven)
                here->omiBSIM4xgw = model->omiBSIM4xgw;
            if (!here->omiBSIM4ngconGiven)
                here->omiBSIM4ngcon = model->omiBSIM4ngcon;

                    
            /* Process instance model selectors, some
             * may override their global counterparts
             */
            if (!here->omiBSIM4rbodyModGiven)
                here->omiBSIM4rbodyMod = model->omiBSIM4rbodyMod;
            else if ((here->omiBSIM4rbodyMod != 0) && (here->omiBSIM4rbodyMod != 1) && (here->omiBSIM4rbodyMod != 2))
            {   here->omiBSIM4rbodyMod = model->omiBSIM4rbodyMod;
                printf("Warning: rbodyMod has been set to its global value %d.\n",
                model->omiBSIM4rbodyMod);
            }

            if (!here->omiBSIM4rgateModGiven)
                here->omiBSIM4rgateMod = model->omiBSIM4rgateMod;
            else if ((here->omiBSIM4rgateMod != 0) && (here->omiBSIM4rgateMod != 1)
                && (here->omiBSIM4rgateMod != 2) && (here->omiBSIM4rgateMod != 3))
            {   here->omiBSIM4rgateMod = model->omiBSIM4rgateMod;
                printf("Warning: rgateMod has been set to its global value %d.\n",
                model->omiBSIM4rgateMod);
            }

            if (!here->omiBSIM4geoModGiven)
                here->omiBSIM4geoMod = model->omiBSIM4geoMod;

            if (!here->omiBSIM4rgeoModGiven)
                here->omiBSIM4rgeoMod = model->omiBSIM4rgeoMod;
            else if ((here->omiBSIM4rgeoMod != 0) && (here->omiBSIM4rgeoMod != 1))
            {   here->omiBSIM4rgeoMod = model->omiBSIM4rgeoMod;
                printf("Warning: rgeoMod has been set to its global value %d.\n",
                model->omiBSIM4rgeoMod);
            }

            if (!here->omiBSIM4trnqsModGiven)
                here->omiBSIM4trnqsMod = model->omiBSIM4trnqsMod;
            else if ((here->omiBSIM4trnqsMod != 0) && (here->omiBSIM4trnqsMod != 1))
            {   here->omiBSIM4trnqsMod = model->omiBSIM4trnqsMod;
                printf("Warning: trnqsMod has been set to its global value %d.\n",
                model->omiBSIM4trnqsMod);
            }

            if (!here->omiBSIM4acnqsModGiven)
                here->omiBSIM4acnqsMod = model->omiBSIM4acnqsMod;
            else if ((here->omiBSIM4acnqsMod != 0) && (here->omiBSIM4acnqsMod != 1))
            {   here->omiBSIM4acnqsMod = model->omiBSIM4acnqsMod;
                printf("Warning: acnqsMod has been set to its global value %d.\n",
                model->omiBSIM4acnqsMod);
            }

            /* stress effect */
            if (!here->omiBSIM4saGiven)
                here->omiBSIM4sa = 0.0;
            if (!here->omiBSIM4sbGiven)
                here->omiBSIM4sb = 0.0;
            if (!here->omiBSIM4sdGiven)
                here->omiBSIM4sd = 2 * model->omiBSIM4dmcg;
            /* Well Proximity Effect  */
            if (!here->omiBSIM4scaGiven)
                here->omiBSIM4sca = 0.0;
            if (!here->omiBSIM4scbGiven)
                here->omiBSIM4scb = 0.0;
            if (!here->omiBSIM4sccGiven)
                here->omiBSIM4scc = 0.0;
            if (!here->omiBSIM4scGiven)
                here->omiBSIM4sc = 0.0; /* m */

            /* process drain series resistance */
            createNode = 0;
            if ( (model->omiBSIM4rdsMod != 0)
                            || (model->omiBSIM4tnoiMod == 1 && noiseAnalGiven))
            {
               createNode = 1;
            } else if (model->omiBSIM4sheetResistance > 0)
            {
                     if (here->omiBSIM4drainSquaresGiven
                                       && here->omiBSIM4drainSquares > 0)
                     {
                          createNode = 1;
                     } else if (!here->omiBSIM4drainSquaresGiven
                                       && (here->omiBSIM4rgeoMod != 0))
                     {
                          omiBSIM4RdseffGeo(here->omiBSIM4nf*here->omiBSIM4m, here->omiBSIM4geoMod,
                                  here->omiBSIM4rgeoMod, here->omiBSIM4min,
                                  here->omiBSIM4w, model->omiBSIM4sheetResistance,
                                  DMCGeff, DMCIeff, DMDGeff, 0, &Rtot);
                          if(Rtot > 0)
                             createNode = 1;
                     }
            }
            if ( createNode != 0 )
            {   if ( here->omiBSIM4dNodePrime == 0 )
            {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"drain");
                if(error) return(error);
                here->omiBSIM4dNodePrime = tmp->number;
                if (ckt->CKTcopyNodesets) {
                  CKTnode *tmpNode;
                  IFuid tmpName;    
                  if (CKTinst2Node(ckt,here,1,&tmpNode,&tmpName)==OK) {
                     if (tmpNode->nsGiven) {
                       tmp->nodeset=tmpNode->nodeset; 
                       tmp->nsGiven=tmpNode->nsGiven; 
                     }
                  }
                }
            }
            }
            else
            {   here->omiBSIM4dNodePrime = here->omiBSIM4dNode;
            }
            
            /* process source series resistance */
            createNode = 0;
            if ( (model->omiBSIM4rdsMod != 0)
                            || (model->omiBSIM4tnoiMod == 1 && noiseAnalGiven))
            {
               createNode = 1;
            } else if (model->omiBSIM4sheetResistance > 0)
            {
                     if (here->omiBSIM4sourceSquaresGiven
                                        && here->omiBSIM4sourceSquares > 0)
                     {
                          createNode = 1;
                     } else if (!here->omiBSIM4sourceSquaresGiven
                                        && (here->omiBSIM4rgeoMod != 0))
                     {
                          omiBSIM4RdseffGeo(here->omiBSIM4nf*here->omiBSIM4m, here->omiBSIM4geoMod,
                                  here->omiBSIM4rgeoMod, here->omiBSIM4min,
                                  here->omiBSIM4w, model->omiBSIM4sheetResistance,
                                  DMCGeff, DMCIeff, DMDGeff, 1, &Rtot);
                          if(Rtot > 0)
                             createNode = 1;
                     }
            }
            if ( createNode != 0 )
            {   if ( here->omiBSIM4sNodePrime == 0 )
            {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"source");
                if(error) return(error);
                here->omiBSIM4sNodePrime = tmp->number;
                if (ckt->CKTcopyNodesets) {
                  CKTnode *tmpNode;
                  IFuid tmpName;
                  if (CKTinst2Node(ckt,here,3,&tmpNode,&tmpName)==OK) {
                     if (tmpNode->nsGiven) {
                       tmp->nodeset=tmpNode->nodeset; 
                       tmp->nsGiven=tmpNode->nsGiven; 
                     }
                  }
                }
            }
            }
            else
                here->omiBSIM4sNodePrime = here->omiBSIM4sNode;

            if ( here->omiBSIM4rgateMod > 0 )
            {   if ( here->omiBSIM4gNodePrime == 0 )
            {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"gate");
                if(error) return(error);
                   here->omiBSIM4gNodePrime = tmp->number;
                if (ckt->CKTcopyNodesets) {
                  CKTnode *tmpNode;
                  IFuid tmpName;
                  if (CKTinst2Node(ckt,here,2,&tmpNode,&tmpName)==OK) {
                    if (tmpNode->nsGiven) {
                      tmp->nodeset=tmpNode->nodeset; 
                      tmp->nsGiven=tmpNode->nsGiven; 
                    }
                  }
                }
            }
            }
            else
                here->omiBSIM4gNodePrime = here->omiBSIM4gNodeExt;

            if ( here->omiBSIM4rgateMod == 3 )
            {   if ( here->omiBSIM4gNodeMid == 0 )
            {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"midgate");
                if(error) return(error);
                   here->omiBSIM4gNodeMid = tmp->number;
            }
            }
            else
                here->omiBSIM4gNodeMid = here->omiBSIM4gNodeExt;
            

            /* internal body nodes for body resistance model */
            if ((here->omiBSIM4rbodyMod ==1) || (here->omiBSIM4rbodyMod ==2))
            {   if (here->omiBSIM4dbNode == 0)
                {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"dbody");
                    if(error) return(error);
                    here->omiBSIM4dbNode = tmp->number;
                }
                if (here->omiBSIM4bNodePrime == 0)
                {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"body");
                    if(error) return(error);
                    here->omiBSIM4bNodePrime = tmp->number;
                    if (ckt->CKTcopyNodesets) {
                      CKTnode *tmpNode;
                      IFuid tmpName;
                      if (CKTinst2Node(ckt,here,4,&tmpNode,&tmpName)==OK) {
                        if (tmpNode->nsGiven) {
                          tmp->nodeset=tmpNode->nodeset; 
                          tmp->nsGiven=tmpNode->nsGiven; 
                        }
                      }
                    }
                }
                if (here->omiBSIM4sbNode == 0)
                {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"sbody");
                    if(error) return(error);
                    here->omiBSIM4sbNode = tmp->number;
                }
            }
            else
                here->omiBSIM4dbNode = here->omiBSIM4bNodePrime = here->omiBSIM4sbNode
                                  = here->omiBSIM4bNode;

            /* NQS node */
            if ( here->omiBSIM4trnqsMod )
            {   if ( here->omiBSIM4qNode == 0 ) 
            {   error = CKTmkVolt(ckt,&tmp,here->omiBSIM4name,"charge");
                if(error) return(error);
                here->omiBSIM4qNode = tmp->number;
            }
            }
            else 
                here->omiBSIM4qNode = 0;
      

/* set Sparse Matrix Pointers 
 * macro to make elements with built-in out-of-memory test */
#define TSTALLOC(ptr,first,second) \
do { if((here->ptr = SMPmakeElt(matrix,here->first,here->second))==(double *)NULL){\
    return(E_NOMEM);\
} } while(0)

            TSTALLOC(omiBSIM4DPbpPtr, omiBSIM4dNodePrime, omiBSIM4bNodePrime);
            TSTALLOC(omiBSIM4GPbpPtr, omiBSIM4gNodePrime, omiBSIM4bNodePrime);
            TSTALLOC(omiBSIM4SPbpPtr, omiBSIM4sNodePrime, omiBSIM4bNodePrime);

            TSTALLOC(omiBSIM4BPdpPtr, omiBSIM4bNodePrime, omiBSIM4dNodePrime);
            TSTALLOC(omiBSIM4BPgpPtr, omiBSIM4bNodePrime, omiBSIM4gNodePrime);
            TSTALLOC(omiBSIM4BPspPtr, omiBSIM4bNodePrime, omiBSIM4sNodePrime);
            TSTALLOC(omiBSIM4BPbpPtr, omiBSIM4bNodePrime, omiBSIM4bNodePrime);

            TSTALLOC(omiBSIM4DdPtr, omiBSIM4dNode, omiBSIM4dNode);
            TSTALLOC(omiBSIM4GPgpPtr, omiBSIM4gNodePrime, omiBSIM4gNodePrime);
            TSTALLOC(omiBSIM4SsPtr, omiBSIM4sNode, omiBSIM4sNode);
            TSTALLOC(omiBSIM4DPdpPtr, omiBSIM4dNodePrime, omiBSIM4dNodePrime);
            TSTALLOC(omiBSIM4SPspPtr, omiBSIM4sNodePrime, omiBSIM4sNodePrime);
            TSTALLOC(omiBSIM4DdpPtr, omiBSIM4dNode, omiBSIM4dNodePrime);
            TSTALLOC(omiBSIM4GPdpPtr, omiBSIM4gNodePrime, omiBSIM4dNodePrime);
            TSTALLOC(omiBSIM4GPspPtr, omiBSIM4gNodePrime, omiBSIM4sNodePrime);
            TSTALLOC(omiBSIM4SspPtr, omiBSIM4sNode, omiBSIM4sNodePrime);
            TSTALLOC(omiBSIM4DPspPtr, omiBSIM4dNodePrime, omiBSIM4sNodePrime);
            TSTALLOC(omiBSIM4DPdPtr, omiBSIM4dNodePrime, omiBSIM4dNode);
            TSTALLOC(omiBSIM4DPgpPtr, omiBSIM4dNodePrime, omiBSIM4gNodePrime);
            TSTALLOC(omiBSIM4SPgpPtr, omiBSIM4sNodePrime, omiBSIM4gNodePrime);
            TSTALLOC(omiBSIM4SPsPtr, omiBSIM4sNodePrime, omiBSIM4sNode);
            TSTALLOC(omiBSIM4SPdpPtr, omiBSIM4sNodePrime, omiBSIM4dNodePrime);

            TSTALLOC(omiBSIM4QqPtr, omiBSIM4qNode, omiBSIM4qNode);
            TSTALLOC(omiBSIM4QbpPtr, omiBSIM4qNode, omiBSIM4bNodePrime) ;
            TSTALLOC(omiBSIM4QdpPtr, omiBSIM4qNode, omiBSIM4dNodePrime);
            TSTALLOC(omiBSIM4QspPtr, omiBSIM4qNode, omiBSIM4sNodePrime);
            TSTALLOC(omiBSIM4QgpPtr, omiBSIM4qNode, omiBSIM4gNodePrime);
            TSTALLOC(omiBSIM4DPqPtr, omiBSIM4dNodePrime, omiBSIM4qNode);
            TSTALLOC(omiBSIM4SPqPtr, omiBSIM4sNodePrime, omiBSIM4qNode);
            TSTALLOC(omiBSIM4GPqPtr, omiBSIM4gNodePrime, omiBSIM4qNode);

            if (here->omiBSIM4rgateMod != 0)
            {   TSTALLOC(omiBSIM4GEgePtr, omiBSIM4gNodeExt, omiBSIM4gNodeExt);
                TSTALLOC(omiBSIM4GEgpPtr, omiBSIM4gNodeExt, omiBSIM4gNodePrime);
                TSTALLOC(omiBSIM4GPgePtr, omiBSIM4gNodePrime, omiBSIM4gNodeExt);
                TSTALLOC(omiBSIM4GEdpPtr, omiBSIM4gNodeExt, omiBSIM4dNodePrime);
                TSTALLOC(omiBSIM4GEspPtr, omiBSIM4gNodeExt, omiBSIM4sNodePrime);
                TSTALLOC(omiBSIM4GEbpPtr, omiBSIM4gNodeExt, omiBSIM4bNodePrime);

                TSTALLOC(omiBSIM4GMdpPtr, omiBSIM4gNodeMid, omiBSIM4dNodePrime);
                TSTALLOC(omiBSIM4GMgpPtr, omiBSIM4gNodeMid, omiBSIM4gNodePrime);
                TSTALLOC(omiBSIM4GMgmPtr, omiBSIM4gNodeMid, omiBSIM4gNodeMid);
                TSTALLOC(omiBSIM4GMgePtr, omiBSIM4gNodeMid, omiBSIM4gNodeExt);
                TSTALLOC(omiBSIM4GMspPtr, omiBSIM4gNodeMid, omiBSIM4sNodePrime);
                TSTALLOC(omiBSIM4GMbpPtr, omiBSIM4gNodeMid, omiBSIM4bNodePrime);
                TSTALLOC(omiBSIM4DPgmPtr, omiBSIM4dNodePrime, omiBSIM4gNodeMid);
                TSTALLOC(omiBSIM4GPgmPtr, omiBSIM4gNodePrime, omiBSIM4gNodeMid);
                TSTALLOC(omiBSIM4GEgmPtr, omiBSIM4gNodeExt, omiBSIM4gNodeMid);
                TSTALLOC(omiBSIM4SPgmPtr, omiBSIM4sNodePrime, omiBSIM4gNodeMid);
                TSTALLOC(omiBSIM4BPgmPtr, omiBSIM4bNodePrime, omiBSIM4gNodeMid);
            }        

            if ((here->omiBSIM4rbodyMod ==1) || (here->omiBSIM4rbodyMod ==2))
            {   TSTALLOC(omiBSIM4DPdbPtr, omiBSIM4dNodePrime, omiBSIM4dbNode);
                TSTALLOC(omiBSIM4SPsbPtr, omiBSIM4sNodePrime, omiBSIM4sbNode);

                TSTALLOC(omiBSIM4DBdpPtr, omiBSIM4dbNode, omiBSIM4dNodePrime);
                TSTALLOC(omiBSIM4DBdbPtr, omiBSIM4dbNode, omiBSIM4dbNode);
                TSTALLOC(omiBSIM4DBbpPtr, omiBSIM4dbNode, omiBSIM4bNodePrime);
                TSTALLOC(omiBSIM4DBbPtr, omiBSIM4dbNode, omiBSIM4bNode);

                TSTALLOC(omiBSIM4BPdbPtr, omiBSIM4bNodePrime, omiBSIM4dbNode);
                TSTALLOC(omiBSIM4BPbPtr, omiBSIM4bNodePrime, omiBSIM4bNode);
                TSTALLOC(omiBSIM4BPsbPtr, omiBSIM4bNodePrime, omiBSIM4sbNode);

                TSTALLOC(omiBSIM4SBspPtr, omiBSIM4sbNode, omiBSIM4sNodePrime);
                TSTALLOC(omiBSIM4SBbpPtr, omiBSIM4sbNode, omiBSIM4bNodePrime);
                TSTALLOC(omiBSIM4SBbPtr, omiBSIM4sbNode, omiBSIM4bNode);
                TSTALLOC(omiBSIM4SBsbPtr, omiBSIM4sbNode, omiBSIM4sbNode);

                TSTALLOC(omiBSIM4BdbPtr, omiBSIM4bNode, omiBSIM4dbNode);
                TSTALLOC(omiBSIM4BbpPtr, omiBSIM4bNode, omiBSIM4bNodePrime);
                TSTALLOC(omiBSIM4BsbPtr, omiBSIM4bNode, omiBSIM4sbNode);
                TSTALLOC(omiBSIM4BbPtr, omiBSIM4bNode, omiBSIM4bNode);
            }

            if (model->omiBSIM4rdsMod)
            {   TSTALLOC(omiBSIM4DgpPtr, omiBSIM4dNode, omiBSIM4gNodePrime);
                TSTALLOC(omiBSIM4DspPtr, omiBSIM4dNode, omiBSIM4sNodePrime);
                TSTALLOC(omiBSIM4DbpPtr, omiBSIM4dNode, omiBSIM4bNodePrime);
                TSTALLOC(omiBSIM4SdpPtr, omiBSIM4sNode, omiBSIM4dNodePrime);
                TSTALLOC(omiBSIM4SgpPtr, omiBSIM4sNode, omiBSIM4gNodePrime);
                TSTALLOC(omiBSIM4SbpPtr, omiBSIM4sNode, omiBSIM4bNodePrime);
            }
        }
    }

#ifdef USE_OMP
    InstCount = 0;
    model = (omiBSIM4model*)inModel;
    /* loop through all the omiBSIM4 device models 
       to count the number of instances */
    
    for( ; model != NULL; model = omiBSIM4nextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = omiBSIM4instances(model); here != NULL ;
             here=omiBSIM4nextInstance(here)) 
        { 
            InstCount++;
        }
        model->omiBSIM4InstCount = 0;
        model->omiBSIM4InstanceArray = NULL;
    }
    InstArray = TMALLOC(omiBSIM4instance*, InstCount);
    model = (omiBSIM4model*)inModel;
    /* store this in the first model only */
    model->omiBSIM4InstCount = InstCount;
    model->omiBSIM4InstanceArray = InstArray;
    idx = 0;
    for( ; model != NULL; model = omiBSIM4nextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = omiBSIM4instances(model); here != NULL ;
             here=omiBSIM4nextInstance(here)) 
        { 
            InstArray[idx] = here;
            idx++;
        }
    }
#endif

    return(OK);
}  

int
omiBSIM4unsetup(
GENmodel *inModel,
CKTcircuit *ckt)
{
#ifndef HAS_BATCHSIM
    omiBSIM4model *model;
    omiBSIM4instance *here;

#ifdef USE_OMP
    model = (omiBSIM4model*)inModel;
    tfree(model->omiBSIM4InstanceArray);
#endif

    for (model = (omiBSIM4model *)inModel; model != NULL;
            model = omiBSIM4nextModel(model))
    {
        for (here = omiBSIM4instances(model); here != NULL;
                here=omiBSIM4nextInstance(here))
        {
            if (here->omiBSIM4qNode > 0)
                CKTdltNNum(ckt, here->omiBSIM4qNode);
            here->omiBSIM4qNode = 0;

            if (here->omiBSIM4sbNode > 0 &&
                here->omiBSIM4sbNode != here->omiBSIM4bNode)
                CKTdltNNum(ckt, here->omiBSIM4sbNode);
            here->omiBSIM4sbNode = 0;

            if (here->omiBSIM4bNodePrime > 0 &&
                here->omiBSIM4bNodePrime != here->omiBSIM4bNode)
                CKTdltNNum(ckt, here->omiBSIM4bNodePrime);
            here->omiBSIM4bNodePrime = 0;

            if (here->omiBSIM4dbNode > 0 &&
                here->omiBSIM4dbNode != here->omiBSIM4bNode)
                CKTdltNNum(ckt, here->omiBSIM4dbNode);
            here->omiBSIM4dbNode = 0;

            if (here->omiBSIM4gNodeMid > 0 &&
                here->omiBSIM4gNodeMid != here->omiBSIM4gNodeExt)
                CKTdltNNum(ckt, here->omiBSIM4gNodeMid);
            here->omiBSIM4gNodeMid = 0;

            if (here->omiBSIM4gNodePrime > 0 &&
                here->omiBSIM4gNodePrime != here->omiBSIM4gNodeExt)
                CKTdltNNum(ckt, here->omiBSIM4gNodePrime);
            here->omiBSIM4gNodePrime = 0;

            if (here->omiBSIM4sNodePrime > 0
                    && here->omiBSIM4sNodePrime != here->omiBSIM4sNode)
                CKTdltNNum(ckt, here->omiBSIM4sNodePrime);
            here->omiBSIM4sNodePrime = 0;

            if (here->omiBSIM4dNodePrime > 0
                    && here->omiBSIM4dNodePrime != here->omiBSIM4dNode)
                CKTdltNNum(ckt, here->omiBSIM4dNodePrime);
            here->omiBSIM4dNodePrime = 0;

        }
    }
#endif
    return OK;
}
