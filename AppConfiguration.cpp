/*
 *  © 2024 Peter Cole
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this code.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "AppConfiguration.h"

AppConfiguration::AppConfiguration() {
  _eventManager = new EventManager();
  _publisher = new Publisher(_eventManager);
  _subscriber = new Subscriber();
  _secondSubscriber = new Subscriber();
  _exampleSubscriber = new Subscriber();
  _subscriptionChangeDelay = 5000;
  _lastSubscriptionChange = 0;
}

void AppConfiguration::initialise() {
  _publisher->begin();
  _registerSubscribers();
}

EventManager *AppConfiguration::getEventManager() { return _eventManager; }

Publisher *AppConfiguration::getPublisher() { return _publisher; }

void AppConfiguration::subscribeUnsubscribeExample() {
  unsigned long currentMillis = millis();
  if (currentMillis - _lastSubscriptionChange > _subscriptionChangeDelay) {
    _lastSubscriptionChange = currentMillis;
    if (_eventManager->isSubscribed(_exampleSubscriber, EventType::ByteEvent)) {
      Serial.print("Unsubscribing instance ");
      Serial.println(_exampleSubscriber->getInstanceID());
      _eventManager->unsubscribe(_exampleSubscriber, EventType::ByteEvent);
    } else {
      Serial.print("Subscribing instance ");
      Serial.println(_exampleSubscriber->getInstanceID());
      _eventManager->subscribe(_exampleSubscriber, EventType::ByteEvent);
    }
  }
}

void AppConfiguration::_registerSubscribers() {
  _eventManager->subscribe(_subscriber, EventType::ByteEvent);
  _eventManager->subscribe(_secondSubscriber, EventType::IntEvent);
  _eventManager->subscribe(_subscriber, EventType::LocoEvent);
}
