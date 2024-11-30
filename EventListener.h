#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "EventStructure.h"

class EventListener {
public:
  virtual void onEvent(Event &event) = 0;
};

#endif // EVENTLISTENER_H
