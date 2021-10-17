#include "PTNFILTER.h"

/*
   RETIRADO DE:https://github.com/emuflight/EmuFlight/blob/master/src/main/common/filter.c
*/

#define THIS_LOOP_RATE 1000 //1000uS = 1KHz
#define FILTER_CUTOFF_FREQUENCY 10 //Hz
#define CONFIGURED_FILTER_TYPE FILTER_TYPE_PT2 //OPÇÕES:PT2,PT3 OU PT4

ptnFilter_t smoothingData;

void setup() {
  Serial.begin(115200);

  ptnFilterInit(&smoothingData, CONFIGURED_FILTER_TYPE, FILTER_CUTOFF_FREQUENCY, PTN_SET_FREQUENCY(THIS_LOOP_RATE));
}

void loop() {
  int getAnalogRead = analogRead(0);

  Serial.print(getAnalogRead);
  Serial.print("  ");
  Serial.println((int)ptnFilterApply(&smoothingData, getAnalogRead));

  delayMicroseconds(THIS_LOOP_RATE);
}
