#include "ngspice/config.h"

#include "ngspice/devdefs.h"

#include "omibsim4itf.h"
#include "omibsim4ext.h"
#include "omibsim4init.h"


SPICEdev omiBSIM4info = {
    .DEVpublic = {
        .name = "omiBSIM4",
        .description = "BSIM4 with Open Model Interface",
        .terms = &omiBSIM4nSize,
        .numNames = &omiBSIM4nSize,
        .termNames = omiBSIM4names,
        .numInstanceParms = &omiBSIM4pTSize,
        .instanceParms = omiBSIM4pTable,
        .numModelParms = &omiBSIM4mPTSize,
        .modelParms = omiBSIM4mPTable,
        .flags = DEV_DEFAULT,

#ifdef XSPICE
        .cm_func = NULL,
        .num_conn = 0,
        .conn = NULL,
        .num_param = 0,
        .param = NULL,
        .num_inst_var = 0,
        .inst_var = NULL,
#endif
    },

    .DEVparam = omiBSIM4param,
    .DEVmodParam = omiBSIM4mParam,
    .DEVload = omiBSIM4load,
    .DEVsetup = omiBSIM4setup,
    .DEVunsetup = omiBSIM4unsetup,
    .DEVpzSetup = omiBSIM4setup,
    .DEVtemperature = omiBSIM4temp,
    .DEVtrunc = omiBSIM4trunc,
    .DEVfindBranch = NULL,
    .DEVacLoad = omiBSIM4acLoad,
    .DEVaccept = NULL,
    .DEVdestroy = NULL,
    .DEVmodDelete = omiBSIM4mDelete,
    .DEVdelete = NULL,
    .DEVsetic = omiBSIM4getic,
    .DEVask = omiBSIM4ask,
    .DEVmodAsk = omiBSIM4mAsk,
    .DEVpzLoad = omiBSIM4pzLoad,
    .DEVconvTest = omiBSIM4convTest,
    .DEVsenSetup = NULL,
    .DEVsenLoad = NULL,
    .DEVsenUpdate = NULL,
    .DEVsenAcLoad = NULL,
    .DEVsenPrint = NULL,
    .DEVsenTrunc = NULL,
    .DEVdisto = NULL,
    .DEVnoise = omiBSIM4noise,
    .DEVsoaCheck = omiBSIM4soaCheck,
    .DEVinstSize = &omiBSIM4iSize,
    .DEVmodSize = &omiBSIM4mSize,

#ifdef CIDER
    .DEVdump = NULL,
    .DEVacct = NULL,
#endif
};


SPICEdev *
get_omibsim4_info(void)
{
    return &omiBSIM4info;
}
