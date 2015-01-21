#include <FreqCounter.h>
long int frq;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
void loop() {
  FreqCounter::f_comp= 8;             // Set compensation to 12
  FreqCounter::start(100);            // Start counting with gatetime of 100ms
  while (FreqCounter::f_ready == 0)         // wait until counter ready

    frq=FreqCounter::f_freq;            // read result  
  //calculation for relative humidity
  double humidity = ((7790-(frq*10))*393/4096)+16;
  Serial.println (humidity);
}

