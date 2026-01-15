#include "EventQueue.h"

EventQueue::EventQueue(int cap) : capacity(cap), head(0), tail(0), count(0) {
    buffer = new Event[capacity];
}

EventQueue::~EventQueue() {
    delete[] buffer;
}

bool EventQueue::enqueue(const Event& e) {
    if (isFull()) return false;
    buffer[tail] = e;
    tail = (tail + 1) % capacity;
    count++;
    return true;
}

bool EventQueue::dequeue(Event* out) {
    if (isEmpty()) return false;
    *out = buffer[head];
    head = (head + 1) % capacity;
    count--;
    return true;
}