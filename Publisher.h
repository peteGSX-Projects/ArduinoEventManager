#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "EventManager.h"

class Publisher {
public:
  Publisher(EventManager *eventManager);

  void begin();

  void process();

private:
  EventManager *_eventManager;
  uint8_t _testByte;
  int _testInt;
  unsigned long _byteDelay;
  unsigned long _intDelay;
  unsigned long _lastByteEvent;
  unsigned long _lastIntEvent;
  unsigned long _locoDelay;
  unsigned long _lastLocoEvent;
  Loco *_testLoco;

  void _publishEvent(EventType eventType, EventData eventData);
};

#endif
