#include "PTNFILTER.h"

/*
   RETIRADO DE:https://github.com/emuflight/EmuFlight/blob/master/src/main/common/filter.c
*/

#define THIS_LOOP_RATE 1000 //1000uS = 1KHz
#define FILTER_CUTOFF_FREQUENCY 10 //Hz

ptnFilter_t smoothingData;

void setup() {
  Serial.begin(115200);

  ptnFilterInit(&smoothingData, TYPE_PT2, FILTER_CUTOFF_FREQUENCY, PTN_SET_FREQUENCY(THIS_LOOP_RATE));
}

void loop() {
  int getAnalogRead = analogRead(0);

  Serial.print(getAnalogRead);
  Serial.print("  ");
  Serial.println((int)ptnFilterApply(&smoothingData, getAnalogRead));

  delayMicroseconds(THIS_LOOP_RATE);
}
