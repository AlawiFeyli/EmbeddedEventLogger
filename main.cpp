#include <iostream>
#include <string>
#include <cstdlib>   // För rand() och srand()
#include <ctime>     // För time() så vi får olika slumpmässiga värden varje gång
#include "EventQueue.h"
#include "EventLog.h"
#include "AlarmSet.h"
#include "Sort.h"    // Inkluderar vår nya sorteringsmodul

int main() {
    // Initialisera slumpgeneratorn med nuvarande tid
    srand(static_cast<unsigned int>(time(0)));

    // Skapa våra objekt (Kärnan i uppgiften)
    EventQueue q(10);           // Ringbuffer med plats för 10
    EventLog log(20);            // Dynamisk logg som börjar på 20
    AlarmSet alarms(45);         // Modul A: Larmar om värdet är över 45

    // Design Pattern: Strategy-light
    // Vi använder en funktionspekare för att välja sorteringsalgoritm
    SortStrategyFn currentSort = insertionSort;

    int globalTime = 0;
    std::string cmd;

    std::cout << "========================================" << std::endl;
    std::cout << "   Embedded Event Logger Simulator G" << std::endl;
    std::cout << "========================================" << std::endl;

    while (true) {
        std::cout << "\nMENY: tick <n>, print, sort, find <id>, alarms, exit\n> ";
        if (!(std::cin >> cmd)) break; // Avbryt om input dör

        if (cmd == "tick") {
            int n;
            if (std::cin >> n) {
                for (int i = 0; i < n; i++) {
                    // 1. PRODUCER: Skapa ett slumpmässigt event
                    int sId = rand() % 5; // Sensor ID 0-4
                    int val = rand() % 100; // Värde 0-99
                    q.enqueue({ ++globalTime, sId, TEMP, val });

                    // 2. CONSUMER: Hämta från kön och lägg i loggen
                    Event e;
                    if (q.dequeue(&e)) {
                        log.append(e);
                        // Uppdatera extra-modulen (AlarmSet)
                        alarms.checkEvent(e.sensorId, e.value);
                    }
                }
                std::cout << "Körde " << n << " ticks. Loggen har nu " << log.size() << " rader." << std::endl;
            }
        }
        else if (cmd == "print") {
            std::cout << "\n--- EVENT LOG ---" << std::endl;
            for (int i = 0; i < log.size(); i++) {
                Event e = log.get(i);
                std::cout << "Tid: " << e.timestamp << "\t| Sensor: " << e.sensorId
                    << "\t| Värde: " << e.value << std::endl;
            }
        }
        else if (cmd == "sort") {
            // Här använder vi vår Strategy-pekare
            currentSort(log);
            std::cout << "Loggen har sorterats efter tid (Tidskomplexitet: O(n^2))." << std::endl;
        }
        else if (cmd == "find") {
            int id;
            if (std::cin >> id) {
                log.findAndPrint(id); // Linjär sökning (Krav för G)
            }
        }
        else if (cmd == "alarms") {
            alarms.printAlarms(); // Visa larmhistorik från Modul A
        }
        else if (cmd == "exit") {
            std::cout << "Avslutar programmet..." << std::endl;
            break;
        }
        else {
            std::cout << "Okänt kommando." << std::endl;
            // Rensa input om användaren skrev något konstigt
            std::cin.clear();
            std::string discard;
            std::getline(std::cin, discard);
        }
    }

    return 0;
}