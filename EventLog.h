#ifndef EVENTLOG_H
#define EVENTLOG_H
#include "Event.h"

class EventLog {
private:
    Event* events;
    int capacity;
    int count;
    void resize();
public:
    EventLog(int initialCap = 10);
    ~EventLog();
    void append(const Event& e);
    int size() const { return count; }
    Event get(int index) const;
    void set(int index, const Event& e);
    void findAndPrint(int sensorId) const;
};

// Detta är vår "Strategy" typ (funktionspekare)
typedef void (*SortStrategyFn)(EventLog& log);
#endif