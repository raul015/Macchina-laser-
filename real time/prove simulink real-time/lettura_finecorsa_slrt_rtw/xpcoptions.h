#ifndef __lettura_finecorsa_XPCOPTIONS_H___
#define __lettura_finecorsa_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "lettura_finecorsa.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                1
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_lettura_finecorsa_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            2048
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0
#define SLRTFTZOFFFLAG                 0

/* Change all stepsize using the newBaseRateStepSize */
void lettura_finecorsa_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_lettura_finecorsa_T *const lettura_finecorsa_M)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  lettura_finecorsa_M->Timing.stepSize0 = lettura_finecorsa_M->Timing.stepSize0 *
    ratio;
  lettura_finecorsa_M->Timing.stepSize = lettura_finecorsa_M->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  lettura_finecorsa_ChangeStepSize(stepSize, lettura_finecorsa_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(lettura_finecorsa_M, errMsg);
}

#endif                                 /* __lettura_finecorsa_XPCOPTIONS_H___ */
