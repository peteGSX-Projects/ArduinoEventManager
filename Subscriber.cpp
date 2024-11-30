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
