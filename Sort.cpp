#include "Sort.h"

void insertionSort(EventLog& log) {
    for (int i = 1; i < log.size(); i++) {
        Event key = log.get(i);
        int j = i - 1;
        while (j >= 0 && log.get(j).timestamp > key.timestamp) {
            log.set(j + 1, log.get(j));
            j--;
        }
        log.set(j + 1, key);
    }
}