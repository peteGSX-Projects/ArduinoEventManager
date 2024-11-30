# Arduino Event Manager

This is an example object-oriented Arduino sketch utilising an event manager to call methods from specific class instances without needing to use static methods.

## How it works

A single EventManager instance is created to manage all event subscriptions and publishing.

When a subscriber registers to an EventType, it is added to a linked list of subscribers that have an ``onEvent()`` method called when a matching EventType is published.

### Classes

- EventManager - manages all subscribtions and publishing of events
- EventListener - each class needing to subscribe to events must extend this and implement the ``onEvent()`` method
