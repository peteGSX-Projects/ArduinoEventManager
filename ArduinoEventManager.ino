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
#include "EventManager.h"
#include <Arduino.h>

/// @brief Create the AppConfiguration instance that manages all configuration for the application
AppConfiguration appConfiguration;

/// @brief Start the example application here
void setup() {
  Serial.begin(115200);
  Serial.println("Arduino Event Manager Example");
  appConfiguration.initialise();
}

/// @brief Main loop to call the example publisher's process method to generate example events
void loop() {
  appConfiguration.getPublisher()->process();
  appConfiguration.subscribeUnsubscribeExample();
}
