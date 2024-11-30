# Arduino Event Manager

This is an example object-oriented Arduino sketch utilising an event manager to call methods from specific class instances without needing to use static methods.

I struggled to come up with a scalable event manager that was able to cope with an object-oriented Arduino sketch that works across all Arduino platforms and therefore doesn't rely on any C++ constructs that aren't available across all platforms.

With some AI help I came up with this approach which seems to work well and is relatively simple to extend and scale as an application grows.

## How it works

A single EventManager instance is created to manage all event subscriptions and publishing.

Event subscribers extend the EventListener class and implement the ``onEvent()`` method to receive event notifications when an event matching their subscription is published.

When a subscriber registers to an EventType, it is added to a linked list of subscribers that have an ``onEvent()`` method called when a matching EventType is published.

There are plenty of comments in the code to help understand the details of how it works.

### Classes

- EventManager - manages all subscribtions and publishing of events
- EventListener - each class needing to subscribe to events must extend this and implement the ``onEvent()`` method

### EventType

An enum ``EventType`` defines the valid event types to publish and subscribe to, with each event having an associated EventData struct containing the relevant data.

See `EventStructure.h` for the various enums and structs in use.
