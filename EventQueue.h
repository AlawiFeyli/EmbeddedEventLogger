#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include "Event.h"

class EventQueue {
private:
    Event* buffer;
    int capacity;
    int head;
    int tail;
    int count;
public:
    EventQueue(int cap);
    ~EventQueue();
    bool enqueue(const Event& e);
    bool dequeue(Event* out);
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
};
#endif