#include "EventLog.h"
#include <iostream>

EventLog::EventLog(int initialCap) : capacity(initialCap), count(0) {
    events = new Event[capacity];
}

EventLog::~EventLog() {
    delete[] events;
}

void EventLog::resize() {
    int newCap = capacity * 2;
    Event* newArray = new Event[newCap];
    for (int i = 0; i < count; i++) {
        newArray[i] = events[i];
    }
    delete[] events;
    events = newArray;
    capacity = newCap;
}

void EventLog::append(const Event& e) {
    if (count == capacity) resize();
    events[count++] = e;
}

Event EventLog::get(int index) const { return events[index]; }
void EventLog::set(int index, const Event& e) { events[index] = e; }

void EventLog::findAndPrint(int sensorId) const {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (events[i].sensorId == sensorId) {
            std::cout << "[Sökning] Tid: " << events[i].timestamp << " Värde: " << events[i].value << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "Inga events hittade för sensor " << sensorId << "\n";
}