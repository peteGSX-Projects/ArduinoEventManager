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

#ifndef APPCONFIGURATION_H
#define APPCONFIGURATION_H

#include "EventManager.h"
#include "Publisher.h"
#include "Subscriber.h"

/// @brief Class to centralise all application configuration
/// All instances are created here and made available via getters
/// All event subscriptions are registered here, see _registerSubscribers()
class AppConfiguration {
public:
  /// @brief Constructor for each instance
  AppConfiguration();

  /// @brief Starts any instances requiring intialisation and registers subscribers
  void initialise();

  /// @brief Retrieve the EventManager instance
  /// @return Pointer to the EventManager
  EventManager *getEventManager();

  /// @brief Retrieve the example Publisher instance
  /// @return Pointer to the example Publisher
  Publisher *getPublisher();

  /// @brief Example to demonstrate subscribing and unsubscribing to an event type
  void subscribeUnsubscribeExample();

private:
  EventManager *_eventManager;            // Pointer to the EventManager
  Publisher *_publisher;                  // Pointer to the example Publisher
  Subscriber *_subscriber;                // Pointer to an example Subscriber
  Subscriber *_secondSubscriber;          // Pointer to another example Subscriber
  Subscriber *_exampleSubscriber;         // Pointer to the example subscriber used for subscribing/unsubscribing
  unsigned long _subscriptionChangeDelay; // Delay in ms between subscribing/unsubscribing for the example
  unsigned long _lastSubscriptionChange;  // Last time the subscription was changed

  /// @brief Central method to register all subscribers to event types
  void _registerSubscribers();
};

#endif