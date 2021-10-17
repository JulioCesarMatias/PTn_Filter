#include "PTNFILTER.h"

void ptnFilterInit(ptnFilter_t *filter, uint8_t order, uint16_t f_cut, float dT) {

  // AdjCutHz = CutHz /(sqrtf(powf(2, 1/Order) -1))
  const float ScaleF[] = { 1.0f,         //NONE COEFF
                           1.553773974f, //COEFF PT2
                           1.961459177f, //COEFF PT3
                           2.298959223f  //COEFF PT4
                         };
  float Adj_f_cut;

  filter->order = (order > 4) ? 4 : order;
  for (int n = 1; n <= filter->order; n++) {
    filter->state[n] = 0.0f;
  }

  Adj_f_cut = (float)f_cut * ScaleF[filter->order - 1];

  filter->k = dT / ((1.0f / (2.0f * 3.14159265358979323846f * Adj_f_cut)) + dT);
}

float ptnFilterApply(ptnFilter_t *filter, float input) {
  filter->state[0] = input;

  for (int n = 1; n <= filter->order; n++) {
    filter->state[n] += (filter->state[n - 1] - filter->state[n]) * filter->k;
  }

  return filter->state[filter->order];
}
