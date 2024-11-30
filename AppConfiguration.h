#ifndef APPCONFIGURATION_H
#define APPCONFIGURATION_H

#include "EventManager.h"
#include "Publisher.h"
#include "Subscriber.h"

class AppConfiguration {
public:
  AppConfiguration();

  void initialise();

  EventManager *getEventManager();

  Publisher *getPublisher();

  Subscriber *getSubscriber();

private:
  EventManager *_eventManager;
  Publisher *_publisher;
  Subscriber *_subscriber;
  Subscriber *_secondSubscriber;

  void _registerSubscribers();
};

#endif