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

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "EventManager.h"

/// @brief An example class that publishes events using the EventManager
class Publisher {
public:
  /// @brief Constructor for the publisher
  /// @param eventManager Pointer to the EventManager instance
  Publisher(EventManager *eventManager);

  /// @brief Create the example Loco object to publish events for
  void begin();

  /// @brief Continue to publish example events at different intervals
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

  /// @brief Publish the specified event type and data
  /// @param eventType Valid EventType
  /// @param eventData Valid EventData
  void _publishEvent(EventType eventType, EventData eventData);
};

#endif
