#ifndef ALARMSET_H
#define ALARMSET_H
#include <vector>
#include <iostream>

class AlarmSet {
private:
    std::vector<int> activeAlarms;
    int threshold;
public:
    AlarmSet(int t) : threshold(t) {}
    void checkEvent(int id, int val) {
        if (val > threshold) {
            activeAlarms.push_back(id);
            std::cout << "!!! LARM: Sensor " << id << " över tröskelvärde (" << val << ")\n";
        }
    }
    void printAlarms() {
        std::cout << "Aktiva larm IDs: ";
        for (int id : activeAlarms) std::cout << id << " ";
        std::cout << "\n";
    }
};
#endif