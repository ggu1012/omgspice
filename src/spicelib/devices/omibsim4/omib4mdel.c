/**** BSIM4.7.0 Released by Darsen Lu 04/08/2011 ****/

/**********
 * Copyright 2006 Regents of the University of California. All rights reserved.
 * File: b4mdel.c of BSIM4.7.0.
 * Author: 2000 Weidong Liu
 * Authors: 2001- Xuemei Xi, Mohan Dunga, Ali Niknejad, Chenming Hu.
 * Authors: 2006- Mohan Dunga, Ali Niknejad, Chenming Hu
 * Authors: 2007- Mohan Dunga, Wenwei Yang, Ali Niknejad, Chenming Hu
 * Project Director: Prof. Chenming Hu.
 **********/

#include "ngspice/ngspice.h"
#include "omibsim4def.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"


int
omiBSIM4mDelete(GENmodel *gen_model)
{
    omiBSIM4model *model = (omiBSIM4model *) gen_model;    

#ifdef USE_OMP
    FREE(model->omiBSIM4InstanceArray);
#endif

    /* OMI */
    omiModel* mypModel = &model->mypModel;
    FREE(mypModel->param);
    FREE(mypModel->value);

    struct bsim4SizeDependParam *p = model->pSizeDependParamKnot;
    while (p) {
        struct bsim4SizeDependParam *next_p = p->pNext;
        FREE(p);
        p = next_p;
    }

    /* model->omiBSIM4modName to be freed in INPtabEnd() */
    FREE(model->omiBSIM4version);

    return OK;
}
