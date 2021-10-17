#ifndef PTNFILTER_H_
#define PTNFILTER_H_

#include <inttypes.h>

#define PTN_SET_FREQUENCY(Frequecy) ((Frequecy) * 1e-6f)

enum PTn_types {
  FILTER_TYPE_PT2 = 2,
  FILTER_TYPE_PT3,
  FILTER_TYPE_PT4
};

typedef struct ptnFilter_s {
  float state[5];
  float k;
  uint8_t order;
} ptnFilter_t;

void ptnFilterInit(ptnFilter_t *filter, uint8_t order, uint16_t f_cut, float dT);
float ptnFilterApply(ptnFilter_t *filter, float input);

#endif
