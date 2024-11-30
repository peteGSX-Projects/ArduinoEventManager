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

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "EventListener.h"

/// @brief An example subscriber class that extends the EventListener class and responds to events
class Subscriber : public EventListener {
public:
  /// @brief Constructor for the subscriber
  Subscriber();

  /// @brief Implementation of the EventListener onEvent method to respond to events
  /// @param event Valid Event to respond to
  void onEvent(Event &event) override;

  /// @brief Get the instance ID
  /// @return Instance ID
  uint8_t getInstanceID();

private:
  static uint8_t _instanceCount;
  uint8_t _instanceID; // Incrementing instance ID to identify different instances responding to events
};

#endif
