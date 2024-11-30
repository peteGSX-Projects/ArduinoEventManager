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

#include "Subscriber.h"

uint8_t Subscriber::_instanceCount = 0;

Subscriber::Subscriber() : _instanceID(_instanceCount++) {}

void Subscriber::onEvent(Event &event) {
  switch (event.eventType) {
  case EventType::ByteEvent:
    Serial.print("SubscriberInstance|ByteEvent: ");
    Serial.print(_instanceID);
    Serial.print("|");
    Serial.println(event.eventData.byteValue);
    break;
  case EventType::IntEvent:
    Serial.print("SubscriberInstance|IntEvent: ");
    Serial.print(_instanceID);
    Serial.print("|");
    Serial.println(event.eventData.intValue);
    break;
  case EventType::LocoEvent:
    Serial.print("SubscriberInstance|LocoEvent: ");
    Serial.print(_instanceID);
    Serial.print("|");
    Serial.println(event.eventData.locoValue->getAddress());
    break;
  default:
    Serial.print("Unknown event received by SubscriberInstance ");
    Serial.println(_instanceID);
    break;
  }
}

uint8_t Subscriber::getInstanceID() { return _instanceID; }
