#include "AppConfiguration.h"
#include "EventManager.h"
#include <Arduino.h>

AppConfiguration appConfiguration;

void setup() {
  Serial.begin(115200);
  Serial.println("Learning how to implement an event bus");
  appConfiguration.initialise();
}

uint8_t test = 0;

void loop() {
  appConfiguration.getPublisher()->process();
}
