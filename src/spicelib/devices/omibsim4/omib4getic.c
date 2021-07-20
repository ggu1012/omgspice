/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4getic.c of BSIM4.7.0.
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
omiBSIM4getic(
GENmodel *inModel,
CKTcircuit *ckt)
{
omiBSIM4model *model = (omiBSIM4model*)inModel;
omiBSIM4instance *here;

    for (; model ; model = omiBSIM4nextModel(model)) 
    {    for (here = omiBSIM4instances(model); here; here = omiBSIM4nextInstance(here))
          {
              if (!here->omiBSIM4icVDSGiven) 
              {   here->omiBSIM4icVDS = *(ckt->CKTrhs + here->omiBSIM4dNode) 
                                   - *(ckt->CKTrhs + here->omiBSIM4sNode);
              }
              if (!here->omiBSIM4icVGSGiven) 
              {   here->omiBSIM4icVGS = *(ckt->CKTrhs + here->omiBSIM4gNodeExt) 
                                   - *(ckt->CKTrhs + here->omiBSIM4sNode);
              }
              if(!here->omiBSIM4icVBSGiven)
              {  here->omiBSIM4icVBS = *(ckt->CKTrhs + here->omiBSIM4bNode)
                                  - *(ckt->CKTrhs + here->omiBSIM4sNode);
              }
         }
    }
    return(OK);
}
