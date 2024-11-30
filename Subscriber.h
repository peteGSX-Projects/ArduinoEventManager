#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "EventListener.h"

class Subscriber : public EventListener {
public:
  Subscriber();

  void onEvent(Event &event) override;

private:
  static uint8_t _instanceCount;
  uint8_t _instanceID;
};

#endif
