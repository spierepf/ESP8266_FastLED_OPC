#include "WiFiStuff.h"
#include "OTAStuff.h"
#include "FastLEDStuff.h"
#include "OPCStuff.h"


void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  WiFiStuff_setup();
  OTAStuff_setup();
  FastLEDStuff_setup();
  OPCStuff_setup();
}

void loop() {
  OTAStuff_loop();
  FastLEDStuff_loop();
  OPCStuff_loop();
}
