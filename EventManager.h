#ifndef EVENTBUS_H
#define EVENTBUS_H

#include "EventListener.h"
#include "EventStructure.h"

class EventManager {
public:
  EventManager();

  void subscribe(EventListener *eventLister, EventType eventType);

  void publish(Event &event);

private:
  struct EventSubscriber {
    EventListener *eventListener;
    EventType eventType;
    EventSubscriber *next;

    EventSubscriber(EventListener *eventListener, EventType eventType)
        : eventListener(eventListener), eventType(eventType), next(nullptr) {}
  };

  EventSubscriber *_firstEventSubscriber;
};

#endif // EVENTBUS_H
