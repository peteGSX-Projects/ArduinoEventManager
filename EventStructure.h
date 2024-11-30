#ifndef EVENTSTRUCTURE_H
#define EVENTSTRUCTURE_H

#include <Arduino.h>
#include <DCCEXProtocol.h>

enum EventType { ByteEvent, IntEvent, LocoEvent, NoneEvent };

/// @brief Struct to cater for events with different data types
struct EventData {
  enum class DataType { Byte, Integer, Loco, None };
  DataType dataType;

  union {
    uint8_t byteValue;
    int intValue;
    Loco *locoValue;
  };

  /// @brief Constructor for events with a uint8_t parameter
  /// @param value 8 bit integer
  EventData(uint8_t value) : dataType(DataType::Byte), byteValue(value) {}

  /// @brief Constructor for events with an int parameter
  /// @param value Signed integer
  EventData(int value) : dataType(DataType::Integer), intValue(value) {}

  /// @brief Constructor for events with a Loco pointer
  /// @param value Pointer to a loco object
  EventData(Loco *value) : dataType(DataType::Loco), locoValue(value) {}

  /// @brief Constructor for events with no data or parameters
  EventData() : dataType(DataType::None) {}
};

struct Event {
  EventType eventType;
  EventData eventData;

  Event(EventType eventType, EventData eventData) : eventType(eventType), eventData(eventData) {}
};

#endif // EVENTSTRUCTURE_H
