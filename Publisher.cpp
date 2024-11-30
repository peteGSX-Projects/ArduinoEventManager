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

#include "Publisher.h"

Publisher::Publisher(EventManager *eventManager) : _eventManager(eventManager) {
  _testByte = 0;
  _testInt = -1000;
  _byteDelay = 1000;
  _intDelay = 1500;
  _lastByteEvent = 0;
  _lastIntEvent = 0;
  _locoDelay = 2000;
  _lastLocoEvent = 0;
  _testLoco = nullptr;
}

void Publisher::begin() {
  if (_testLoco == nullptr) {
    _testLoco = new Loco(2010, LocoSource::LocoSourceEntry);
    Serial.print("Created loco with address ");
    Serial.println(_testLoco->getAddress());
  }
}

void Publisher::process() {
  unsigned long currentMillis = millis();
  if (currentMillis - _lastByteEvent > _byteDelay) {
    _lastByteEvent = currentMillis;
    EventData eventData(_testByte++);
    _publishEvent(EventType::ByteEvent, eventData);
  }
  if (currentMillis - _lastIntEvent > _intDelay) {
    _lastIntEvent = currentMillis;
    EventData eventData(_testInt++);
    _publishEvent(EventType::IntEvent, eventData);
  }
  if (currentMillis - _lastLocoEvent > _locoDelay) {
    _lastLocoEvent = currentMillis;
    EventData eventData(_testLoco);
    _publishEvent(EventType::LocoEvent, eventData);
  }
}

void Publisher::_publishEvent(EventType eventType, EventData eventData) {
  Event testEvent(eventType, eventData);
  _eventManager->publish(testEvent);
}
