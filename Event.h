#ifndef EVENT_H
#define EVENT_H

enum EventType { TEMP, BUTTON, MOTION };

struct Event {
    int timestamp;
    int sensorId;
    EventType type;
    int value;
};

#endif