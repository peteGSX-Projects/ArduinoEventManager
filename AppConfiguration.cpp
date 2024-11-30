#include "AppConfiguration.h"

AppConfiguration::AppConfiguration() {
  _eventManager = new EventManager();
  _publisher = new Publisher(_eventManager);
  _subscriber = new Subscriber();
  _secondSubscriber = new Subscriber();
}

void AppConfiguration::initialise() {
  _publisher->begin();
  _registerSubscribers();
}

EventManager *AppConfiguration::getEventManager() { return _eventManager; }

Publisher *AppConfiguration::getPublisher() { return _publisher; }

Subscriber *AppConfiguration::getSubscriber() { return _subscriber; }

void AppConfiguration::_registerSubscribers() {
  _eventManager->subscribe(_subscriber, EventType::ByteEvent);
  _eventManager->subscribe(_secondSubscriber, EventType::IntEvent);
  _eventManager->subscribe(_subscriber, EventType::LocoEvent);
}
