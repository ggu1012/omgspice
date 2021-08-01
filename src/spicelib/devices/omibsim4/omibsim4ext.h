/**********
Copyright 2004 Regents of the University of California.  All rights reserved.
Author: 2000 Weidong Liu
Author: 2001- Xuemei Xi
File: omibsim4ext.h
**********/

extern int omiBSIM4acLoad(GENmodel *,CKTcircuit*);
extern int omiBSIM4ask(CKTcircuit *,GENinstance*,int,IFvalue*,IFvalue*);
extern int omiBSIM4convTest(GENmodel *,CKTcircuit*);
extern int omiBSIM4getic(GENmodel*,CKTcircuit*);
extern int omiBSIM4load(GENmodel*,CKTcircuit*);
extern int omiBSIM4mAsk(CKTcircuit*,GENmodel *,int, IFvalue*);
extern int omiBSIM4mDelete(GENmodel*);
extern int omiBSIM4mParam(int,IFvalue*,GENmodel*);
extern void omiBSIM4mosCap(CKTcircuit*, double, double, double, double,
        double, double, double, double, double, double, double,
        double, double, double, double, double, double, double*,
        double*, double*, double*, double*, double*, double*, double*,
        double*, double*, double*, double*, double*, double*, double*, 
        double*);
extern int omiBSIM4param(int,IFvalue*,GENinstance*,IFvalue*);
extern int omiBSIM4pzLoad(GENmodel*,CKTcircuit*,SPcomplex*);
extern int omiBSIM4setup(SMPmatrix*,GENmodel*,CKTcircuit*,int*);
extern int omiBSIM4temp(GENmodel*,CKTcircuit*);
extern int omiBSIM4trunc(GENmodel*,CKTcircuit*,double*);
extern int omiBSIM4noise(int,int,GENmodel*,CKTcircuit*,Ndata*,double*);
extern int omiBSIM4unsetup(GENmodel*,CKTcircuit*);
extern int omiBSIM4soaCheck(CKTcircuit *, GENmodel *);

/* OMI */
extern int omiBSIM4delete(GENinstance *);
extern double omiBSIM4GetmParam(GENmodel * , int);
extern double omiBSIM4GetParam(GENinstance *, int);
