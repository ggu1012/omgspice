#include "ngspice/cktdefs.h"
#include "ngspice/const.h"
#include "ngspice/ftedefs.h"
#include "ngspice/jobdefs.h"
#include "ngspice/ngspice.h"
#include "ngspice/smpdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"
#include "omi/omiDef.h"
#include "omi/omiIft.h"
#include "omibsim4def.h"
#include "omibsim4init.h"


/* OMI */

int omiBSIM4delete(GENinstance* gen_inst) {

    omiBSIM4instance *inst = (omiBSIM4instance *) gen_inst;
    omiInstance* mypInstance = &inst->mypInstance;

    FREE(mypInstance->param);
    FREE(mypInstance->value);

    return OK;
}