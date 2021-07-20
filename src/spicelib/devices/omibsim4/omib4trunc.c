/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4trunc.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 **********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "omibsim4def.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"


int
omiBSIM4trunc(
GENmodel *inModel,
CKTcircuit *ckt,
double *timeStep)
{
omiBSIM4model *model = (omiBSIM4model*)inModel;
omiBSIM4instance *here;

#ifdef STEPDEBUG
    double debugtemp;
#endif /* STEPDEBUG */

    for (; model != NULL; model = omiBSIM4nextModel(model))
    {    for (here = omiBSIM4instances(model); here != NULL;
	      here = omiBSIM4nextInstance(here))
	      {
#ifdef STEPDEBUG
            debugtemp = *timeStep;
#endif /* STEPDEBUG */
            CKTterr(here->omiBSIM4qb,ckt,timeStep);
            CKTterr(here->omiBSIM4qg,ckt,timeStep);
            CKTterr(here->omiBSIM4qd,ckt,timeStep);
            if (here->omiBSIM4trnqsMod)
                CKTterr(here->omiBSIM4qcdump,ckt,timeStep);
            if (here->omiBSIM4rbodyMod)
            {   CKTterr(here->omiBSIM4qbs,ckt,timeStep);
                CKTterr(here->omiBSIM4qbd,ckt,timeStep);
	          }
	          if (here->omiBSIM4rgateMod == 3)
		        CKTterr(here->omiBSIM4qgmid,ckt,timeStep);
#ifdef STEPDEBUG
            if(debugtemp != *timeStep)
	          {  printf("device %s reduces step from %g to %g\n",
                       here->omiBSIM4name,debugtemp,*timeStep);
            }
#endif /* STEPDEBUG */
        }
    }
    return(OK);
}
