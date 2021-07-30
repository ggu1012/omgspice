/*
 ****************************************************************************
 *  Copyright 2016 Silicon Integration Initiative, Inc. All Rights reserved.
 ****************************************************************************
 *  File        : omiIft.h 
 *  Date        : 2016-11-22
 *  Description : OMI IFT and related structures
 */

#include "omi/omiDef.h"

#ifndef  OMIIFT_H
#define  OMIIFT_H


#define OMI_DEFAULT -1

/* This macro gets workData offset of a dfield */
#define OMI_WORK_DATA_OFFSET(_type_, _field_) \
(&((_type_ *) 0)->_field_ - (double *) 0)

#define OMI_BSIM4_STD_NODE_SIZE_MAX 12/* maximum BSIM4 standard node size */


/* This enumerates all of BSIM4 standard nodes */
typedef enum omiBSIM4StdNode
{
  omiBSIM4id,           /* 0, internal drain */
  omiBSIM4xg,           /* 1, external gate */
  omiBSIM4is,           /* 2, internal source */
  omiBSIM4xb,           /* 3, external body */
  omiBSIM4xd,           /* 4, external drain */
  omiBSIM4xs,           /* 5, external source */
  omiBSIM4ig,           /* 6, internal gate, when rgatemod > 0 */
  omiBSIM4mg,           /* 7, middle gate, when rgatemod > 1 */
  omiBSIM4ib,           /* 8, internal body, when rbodymod > 0 */
  omiBSIM4db,           /* 9, internal drain side body, when rbodymod > 0 */
  omiBSIM4sb,           /* 10, internal source side body, when rbodymod > 0 */
  omiBSIM4nqs           /* 11, non-quasi-static node, when nqsmod > 0 */
} omiBSIM4StdNode;

#define OMI_BSIMCMG_STD_NODE_SIZE_MAX 19/* maximum BSIMCMG standard node size */


/* This enumerates all of BSIMCMG standard nodes */


/* This code proposed by YCLiangb of TSMC on 2014-07-30 */
typedef enum omiBSIMCMGStdNode
{
  omiBSIMCMGid,           /* 0, internal drain, when rdsmod > 0 */
  omiBSIMCMGxg,           /* 1, external gate */
  omiBSIMCMGis,           /* 2, internal source, when rdsmod > 0 */
  omiBSIMCMGxe,           /* 3, external body */
  omiBSIMCMGxd,           /* 4, external drain */
  omiBSIMCMGxs,           /* 5, external source */
  omiBSIMCMGge,           /* 6, internal gate, when rgatemod > 0 */
  omiBSIMCMGtnode,        /* 7, self-heating node, when shmod >0 and rth0 > 0 */
  omiBSIMCMGgi,           /* 8, non-quasi-static node, when nqsmod = 1 */
  omiBSIMCMGq,            /* 9, non-quasi-static node, when nqsmod = 2 */
  omiBSIMCMGq1,           /* 10, non-quasi-static node, when nqsmod = 3, nseg >= 4 */
  omiBSIMCMGq2,           /* 11, non-quasi-static node, when nqsmod = 3, nseg >= 4 */
  omiBSIMCMGq3,           /* 12, non-quasi-static node, when nqsmod = 3, nseg >= 4 */
  omiBSIMCMGq4,           /* 13, non-quasi-static node, when nqsmod = 3, nseg >= 5 */
  omiBSIMCMGq5,           /* 14, non-quasi-static node, when nqsmod = 3, nseg >= 6 */
  omiBSIMCMGq6,           /* 15, non-quasi-static node, when nqsmod = 3, nseg >= 7 */
  omiBSIMCMGq7,           /* 16, non-quasi-static node, when nqsmod = 3, nseg >= 8 */
  omiBSIMCMGq8,           /* 17, non-quasi-static node, when nqsmod = 3, nseg >= 9 */
  omiBSIMCMGq9,           /* 18, non-quasi-static node, when nqsmod = 3, nseg >= 10 */
} omiBSIMCMGStdNode;

/* begin: for HiSIM2 (Renesas, 2015/6) */
#define OMI_HiSIM2_STD_NODE_SIZE_MAX 12/* maximum HiSIM2 standard node size */


/* This enumerates all of HiSIM2 standard nodes */
typedef enum omiHiSIM2StdNode
{
  omiHiSIM2xd,           /* 0, external drain */
  omiHiSIM2xg,           /* 1, external gate */
  omiHiSIM2xs,           /* 2, external source */
  omiHiSIM2xb,           /* 3, external body */
  omiHiSIM2id,           /* 4, internal drain, when corsrd < 0 */
  omiHiSIM2ig,           /* 5, internal gate, when coreg == 1 */
  omiHiSIM2is,           /* 6, internal source, when corsrd < 0 */
  omiHiSIM2ib,           /* 7, internal body, when corbnet == 1 */
  omiHiSIM2db,           /* 8, internal drain side body, when corbnet == 1 */
  omiHiSIM2sb,           /* 9, internal source side body, when corbnet == 1 */
} omiHiSIM2StdNode;
/* end:   for HiSIM2 (Renesas, 2015/6) */

/* begin: for BSIMSOI (TSMC, 2015/3) */
#define OMI_BSIMSOI_STD_NODE_SIZE_MAX 13/* maximum BSIMSOI standard node size */

/* This enumerates all of BSIMSOI standard nodes */
typedef enum omiBSIMSOIStdNode
{
  omiBSIMSOId,           /* 0, external drain */
  omiBSIMSOIg,           /* 1, external gate */
  omiBSIMSOIs,           /* 2, external source */
  omiBSIMSOIe,           /* 3, external substrate */
  omiBSIMSOIp,           /* 4, external body contact */
  omiBSIMSOIdi,          /* 5, internal drain */
  omiBSIMSOIsi,          /* 6, internal source */
  omiBSIMSOIgi,          /* 7, internal gate */
  omiBSIMSOIgm,          /* 8, middle gate */
  omiBSIMSOIb,           /* 9, internal body */
  omiBSIMSOIsb,          /* 10, internal source side body */
  omiBSIMSOIdb,          /* 11, internal drain side body */
  omiBSIMSOIt            /* 12, self-heating node */
} omiBSIMSOIStdNode;
/* end: for BSIMSOI (TSMC, 2015/3) */


/* This is used to indicate what type of physical value is represented by a node */
typedef enum omiNodeType
{
  omiNodeTypePotential, /* such things as voltage, position, temperature */
  omiNodeTypeFlow       /* such things as current, velocity, power flow */
}
omiNodeType;


/* This is used by the simulator when initializing the omiEvalData structure
 * in order to instruct the models as to how much evaluation/calculation
 * is needed during subsequent calls to the evaluation functions.
 */
typedef enum omiEvalLevel
{
  omiEvalNothing,       /* nothing */
  omiEvalRhs,           /* for future use only.  Not defined for v2.0.x */ 
  omiEvalDeriv,         /* for future use only.  Not defined for v2.0.x */ 
  omiEvalAll,           /* all */
  omiEvalTopo           /* topology */
}
omiEvalLevel;

/* This enumerates all of stamp type */
typedef enum omiStampType
{
  omiStampAll/* placeholder */
  /* may add more types */
}
omiStampType;


/* This structure defines BSIM4 core model intermediate variables can be accessed by OMI */
typedef struct omiBSIM4CoreData
{
  double vth;           /* turn-on voltage; same as BSIM4_VON */
  double vdsat;         /* saturation voltage; same as BSIM4_VDSAT */
  double ids;           /* drain dc current; same as BSIM4_CD */
  double gds;           /* output conductance (dIds/dVds); same as BSIM4_GDS */
  double gm;            /* trans-conductance (dIds/dVgs); same as BSIM4_GM */
  double gmbs;          /* substrate trans-conductance (dIds/dVbs); same as BSIM4_GMBS */
  double beta;          /* reserved */
  double gamma;         /* reserved */

  double ibs;           /* substrate source-junction leakage current; same as BSIM4_CBS */
  double ibd;           /* substrate drain-junction leakage current; same as BSIM4_CBD */
  double isub;          /* substrate current; same as BSIM4_CSUB */
  double igso;          /* gate-to-source tunneling current through G-S overlap; same as BSIM4_IGS */
  double igdo;          /* gate-to-drain tunneling current through G-D overlap; same as BSIM4_IGD */
  double igb;           /* gate-to-bulk tunneling current; same as BSIM4_IGB */
  double igcs;          /* gate-to-source tunneling current through channel; same as BSIM4_IGCS */ 
  double igcd;          /* gate-to-drain tunneling current through channel; same as BSIM4_IGCD */
  double igidl;         /* GIDL current; same as BSIM4_IGIDL */
  double igisl;         /* GISL current; same as BSIM4_IGISL */
} omiBSIM4CoreData;

/* This code proposed by YCLiangb of TSMC on 2014-07-17 */
typedef struct omiBSIMCMGCoreData
{
  double ids;
  double igidl;
  double igisl;
  double igs;
  double igd;
  double igcs;
  double igcd;
  double igbs;
  double igbd;
  double iii;
  double qg;
  double qd;
  double qs;
  double qb;
  double rsgeo;
  double rdgeo;
  double cfgeo;
  double gm;
  double gds;
} omiBSIMCMGCoreData;

/* begin: for HiSIM2 (Renesas, 2015/6) */
typedef struct omiHiSIM2CoreData
{
  double ids;   /* Drain-Source current; same as HSM2_CD */
  double isub;	/* Substrate current; same as HSM2_ISUB */
  double igidl;	/* Gate-Induced Drain Leakage current; same as HSM2_IGIDL */
  double igisl;	/* Gate-Induced Source Leakage current; same as HSM2_IGISL */
  double igd;   /* Gate-Drain current; same as HSM2_IGD */
  double igs;   /* Gate-Source current; same as HSM2_IGS */
  double igb;   /* Gate-Substrate current; same as HSM2_IGB */
  double gm;	/* Transconductance; same as HSM2_GM */
  double gds;	/* Channel conductance; same as HSM2_GDS */
  double gmbs;	/* Body effect (Back gate) tran sconductance; same as HSM2_GMBS */
  double von;	/* Threshold voltage; same as HSM2_VON */
  double vdsat;	/* Saturation voltage; same as HSM2_VDSAT */
  double qb;	/* Bulk charge; same as HSM2_QB */
  double qg;	/* Gate charge; same as HSM2_QG */
  double qd;	/* Drain charge; same as HSM2_QD */
  double cgg;	/* MOSFET capacitance; same as HSM2_CGG */
  double cgd;	/* MOSFET capacitance; same as HSM2_CGD */
  double cgs;	/* MOSFET capacitance; same as HSM2_CGS */
  double cbg;	/* MOSFET capacitance; same as HSM2_CBG */
  double cbs;	/* MOSFET capacitance; same as HSM2_CBSB */
  double cbd;	/* MOSFET capacitance; same as HSM2_CBDB */
  double cdg;	/* MOSFET capacitance; same as HSM2_CDG */
  double cdd;	/* MOSFET capacitance; same as HSM2_CDD */
  double cds;	/* MOSFET capacitance; same as HSM2_CDS */
  double cgdo;	/* MOSFET overlap capacitance; same as HSM2_CGDO */
  double cgso;	/* MOSFET overlap capacitance; same as HSM2_CGSO */
  double cgbo;	/* MOSFET overlap capacitance; same as HSM2_CGBO */
  double ibd;	/* Diode current; same as HSM2_CBD */
  double ibs;	/* Diode current; same as HSM2_CBS */
  double gbd;	/* Diode conductance; same as HSM2_GBD */
  double gbs;	/* Diode conductance; same as HSM2_GBS */
  double capbd;	/* Diode capacitance; same as HSM2_CAPBD */
  double capbs;	/* Diode capacitance; same as HSM2_CAPBS */
} omiHiSIM2CoreData;
/* end:   for HiSIM2 (Renesas, 2015/6) */

/* begin: for BSIMSOI (TSMC, 2015/3) */
typedef struct omiBSIMSOICoreData
{
  double ids;       /* drain dc current; */
  double igidl;     /* GIDL current; */
  double igisl;     /* GISL current; */
  double igs;       /* gate-to-source tunneling current; */
  double igd;       /* gate-to-drain tunneling current; */
  double igcs;      /* gate-to-source tunneling current through channel; */
  double igcd;      /* gate-to-drain tunneling current through channel; */
  double igb;       /* gate-to-body tunneling current; */
  double ibs;       /* body source-junction leakage current; */
  double ibd;       /* body drain-junction leakage current; */
  double ic;        /* BJT collector current; */
  double vdsat;     /* saturation voltage; */
  double vth;       /* turn-on voltage; */
  double gm;        /* trans-conductance (dIds/dVgs); */
  double gmbs;      /* body trans-conductance (dIds/dVbs); */
  double gds;       /* output conductance (dIds/dVds); */
} omiBSIMSOICoreData;
/* end: for BSIMSOI (TSMC, 2015/3) */

/* This structure defines variable type for probe */
typedef struct omiProbeData
{
  char   *name;         /* name */
  double value;         /* value */
} omiProbeData;

/* This structure defines variable type for nosie */
typedef struct omiNoiseData
{
  char   *name;         /* name */
  double value;         /* value */
  int    term1;         /* terminal1 */
  int    term2;         /* terminal2 */
} omiNoiseData;

/* This structure is used to control evaluation of the model */
typedef struct omiEvalData
{
  omiEvalLevel evalI;        /* I/G evaluation for omiEvaluate( ) */
  omiEvalLevel evalQ;        /* Q/C evaluation for omiEvaluate( ) */
  omiStampType type;         /* stamp type, reserved */
  double       time;         /* time during transient analysis for aging models */
  double       step;         /* time step during transient analysis for aging models */
  double       freq;         /* frequency during AC or noise analysis */
  double       gmin;         /* gmin */
  unsigned     limiting:1;   /* limiting flag, reserved; it should not be used in OMI2.0.x releases */
  double       *workData;    /* V/I/G/Q/C information that may be changed each time omiEvaluate is called */
  void         *specData;    /* instance specific data that could be reused by all steps */
  void         *coreData;    /* core model data */
  omiProbeData *probeData;   /* probe data */
  omiNoiseData *noiseData;   /* noise data */
} omiEvalData;

/* OMI virtual function table */
typedef struct omiIft
{
  /* memory size  for simulator to allocate memory for omiEvalData->workData structure. 
     omiEvalData->workData is designed to pass general data such as V/I/G/Q/C 
     between OMI model and simulator each evaluation.  */
  int    workDataSize; 
  
  /* memory size of omiEvalData->specData for instance specific data */
  int    specDataSize;
  
  /* number of probe variable (omiEvalData->probeData) */
  int    probeDataSize;
  
  /* number of noise variable (omiEvalData->noiseData) */
  int    noiseDataSize;
  
  /* model evaluation function */
  int    (*omiEvaluate) (void *pModelData, void *pInstData, omiEvalData *pEvalData);
  
  /* noise evaluation function */
  int    (*omiNoise) (void *pModelData, void *pInstData, omiEvalData *pEvalData);
  
  /* This function performs node mapping operation when new internal node is added into standard core device topology. */
  int    (*omiSetTopology) (omiEvalData *pEvalData, int *stdNode, int *newNode);
  
  /* This function returns number of new node introduced by OMI2 device */
  int    (*omiTermCount) (omiEvalData *pEvalData);
  
  /* This function returns node physical value type. */
  omiNodeType (*omiTerminalType)(omiEvalData *pEvalData, int term_index);
  
  /* This function returns number of constant conductance */
  int    (*omiConstCondCount) (omiEvalData *pEvalData);
  
  /* This function returns matrix row location of each constant conductance given by dindex */
  int    (*omiConstCondRow) (omiEvalData *pEvalData, int dindex, int in_out); 
  
  /* This function returns matrix column location of each constant conductance given by dindex */
  int    (*omiConstCondColumn) (omiEvalData *pEvalData, int dindex, int plus_minus);
   
  /* This function returns the value of each constant conductance given by dindex */
  double (*omiConstCondValue) (omiEvalData *pEvalData, int dindex);
  
  /* This function returns number of branch currents */
  int    (*omiISize) (omiEvalData *pEvalData);
  
  /* This function returns matrix row location of each branch current given by rhs_index */
  int    (*omiITermRow) (omiEvalData *pEvalData, int rhs_index, int in_out);
  
  /* This function returns offset of current, given by rhs_index, in omiWorkData structure */
  int    (*omiIWorkDataOffset) (omiEvalData *pEvalData, int rhs_index);
  
  /* This function returns # of derivatives for each branch current given by rhs_index */
  int    (*omiIderivSize) (omiEvalData *pEvalData, int rhs_index);
  
  /* This function returns offset of branch current's derivatives in omiWorkData structure */
  int    (*omiIderivWorkDataOffset) (omiEvalData *pEvalData, int rhs_index, int deriv_index);
  
  /* This function returns matrix column location of "rhs_index" current's "derive_index" derivative */
  int    (*omiIderivTermCol) (omiEvalData *pEvalData, int rhs_index, int deriv_index, int plus_minus);
  
  /* This function returns number of all charges introduced by OMI2 */
  int    (*omiQSize) (omiEvalData *pEvalData);
  
  /* This function returns matrix row location of each charge given by rhs_index */
  int    (*omiQTermRow) (omiEvalData *pEvalData, int rhs_index, int in_out);
  
  /* This function returns offset of charge, given by rhs_index, in omiWorkdata structure */
  int    (*omiQWorkDataOffset) (omiEvalData *pEvalData, int rhs_index);
  
  /* This function returns # of derivatives for each charge */
  int    (*omiQderivSize) (omiEvalData *pEvalData, int rhs_index);
  
  /* This function returns offset of charge derivatives in omiWorkData structure */
  int    (*omiQderivWorkDataOffset) (omiEvalData *pEvalData, int rhs_index, int deriv_index);
  
  /* This function returns matrix column location of each charge derivative given by "rhs_index" and "derive_index" */
  int    (*omiQderivTermCol) (omiEvalData *pEvalData, int rhs_index, int deriv_index, int plus_minus);
  
  /* This function integrates dAge (initialize dAge when time = 0) */
  int    (*omiIntegrate)(void *pModelData, void *pInstData, omiEvalData *pEvalData);
} omiIft;


typedef struct omiModuleIft
{

   /* Model Name ID for the type of module (e.g. 5000 for Verilog-A),
      assigned by OMI code to match value passed to
      omiInitializeModule. */
   int modelID;

   /* Module ID number, assigned by OMI code to match value passed to
      omiInitializeModule by the simulator. */
   int moduleID;

   /* Module name string, statically allocated and assigned by OMI
      code to match value passed to omiInitializeModule by the
      simulator. */
   char *moduleName;

   /* Number of parameters in the modParamName, modParamDirection,
      modParamIndexIn, and modParamIndexOut arrays */
   int numModParam;

   /* Array of strings statically allocated and assigned by OMI code,
      indicating Verilog-A parameters to be included in the param and
      value fields of the omiModel struct passed to omiUpdate.  Each
      string should match the parameter name as it appears in the
      source code. */
   String * modParamName;

   /* Array of integers statically allocated and assigned by OMI code,
      indicating the direction of each Verilog-A Parameter listed in
      the modParamName array.
         0 – input (appears in param and value fields of omiModel
             struct passed to omiUpdate)
         1 – output (appears in param_o and value_o fields of omiModel
             struct passed to omiUpdate)
         2 – input and output (appears in both locations)  */
   int *modParamDirection;

   /* Array of integers statically allocated by OMI code.  For each
      Verilog-A parameter listed in the modParamName array, gives the
      index into the param and value fields of the omiModel struct, or
      a negative number on error.  This array will be assigned by the
      simulator before the first call to omiUpdate. */
   int *modParamIndexIn;

   /* Array of integers statically allocated by OMI code.  For each
      Verilog-A parameter listed in the modParamName array, gives the
      index into the param_o and value_o fields of the omiModel
      struct, or a negative number on error.  This array will be
      assigned by the simulator before the first call to omiUpdate. */
   int *modParamIndexOut;

   /* Number of parameters in the instParamName, instParamDirection,
      instParamIndexIn, and instParamIndexOut arrays */
   int numInstParam;

   /* Array of strings statically allocated and assigned by OMI code,
      indicating Verilog-A parameters to be included in the param and
      value fields of the omiInstance struct passed to omiUpdate.  It
      is expected that these parameters will have a type attribute
      annotated in the Verilog-A code, and that type attribute will be
      set to “instance”.  */
   String * instParamName;

   /* Array of integers statically allocated and assigned by OMI code,
      indicating the direction of each Verilog-A Parameter listed in the
      instParamName array.
         0 – input (appears in param and value fields of omiInstance
             struct passed to omiUpdate)
         1 – output (appears in param_o and value_o fields of
             omiInstance struct passed to omiUpdate)
         2 – input and output (appears in both locations)  */
   int *instParamDirection;

   /* Array of integers statically allocated by OMI code.  For each
      Verilog-A parameter listed in the instParamName array, gives the
      index into the param and value fields of the omiInstance struct,
      or a negative number on error.  This array will be assigned by
      the simulator before the first call to omiUpdate. */
   int *instParamIndexIn;

   /* Array of integers statically allocated by OMI code.  For each
      Verilog-A parameter listed in the instParamName array, gives the
      index into the param_o and value_o fields of the omiInstance
      struct, or a negative number on error.  This array will be
      assigned by the simulator before the first call to omiUpdate. */
   int *instParamIndexOut;

   /* Number of variables in the coreDataVarName and coreDataVarIndex
      arrays */
   int numCoreDataVar;

   /* Array of strings statically allocated and assigned by OMI code,
      indicating Verilog-A variables to be included in the coreData
      field of the omiEvalData struct passed to the omiIntegrate
      function (as specified in the omiIft struct returned by
      omiCreate).  Each string should match the parameter name as it
      appears in the source code. */
   String *coreDataVarName;

   /* Array of integers statically allocated by OMI code.  For each
      Verilog-A parameter listed in the coreDataVarName array, gives
      the index into the coreData field of the omiEvalData struct, or
      a negative number on error.  This array will be assigned by the
      simulator before the first call to the omiIntegrate function (as
      specified in the omiIft struct returned by omiCreate).  */
   int *coreDataVarIndex;

} omiModuleIft;



/* declare function */
extern char *omiCreate (int spiceType, int id, int level, void *pModelData);
extern int omiPrintAge (omiCKT *pCKT);
extern int omiFreeAge ();

#endif /* OMIIFT_H */


/* end of $RCSfile: omiIft.h,v $ */
