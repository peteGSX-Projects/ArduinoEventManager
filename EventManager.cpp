#include "EventManager.h"

EventManager::EventManager() { _firstEventSubscriber = nullptr; }

void EventManager::subscribe(EventListener *eventListener, EventType eventType) {
  EventSubscriber *newSubscriber = new EventSubscriber(eventListener, eventType);
  if (_firstEventSubscriber == nullptr) {
    _firstEventSubscriber = newSubscriber;
  } else {
    EventSubscriber *currentEventSubscriber = _firstEventSubscriber;
    while (currentEventSubscriber->next != nullptr) {
      currentEventSubscriber = currentEventSubscriber->next;
    }
    currentEventSubscriber->next = newSubscriber;
  }
}

void EventManager::publish(Event &event) {
  for (EventSubscriber *eventSubscriber = _firstEventSubscriber; eventSubscriber;
       eventSubscriber = eventSubscriber->next) {
    if (eventSubscriber->eventType == event.eventType) {
      eventSubscriber->eventListener->onEvent(event);
    }
  }
}
