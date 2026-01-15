Inlämningsuppgift: Embedded Event Logger
Detta projekt simulerar ett inbyggt system som tar emot sensorhändelser, köar dem i en ringbuffer och sparar dem i en dynamisk logg för analys (sortering och sökning).

Hur man bygger och kör
Kompilering: Använd g++ (eller valfri C++-kompilator). Alla moduler måste länkas samman:

Bash

g++ main.cpp EventQueue.cpp EventLog.cpp Sort.cpp -o logger
Körning:

Bash

./logger

Testinstruktioner (Exempelkörning)
För att verifiera att systemet fungerar, kör följande kommandon i menyn:

tick 5 - Skapar 5 händelser (notera att larm kan triggas om värdet > 45).

print - Se den osorterade loggen.

sort - Sorterar loggen baserat på tidsstämpel.

print - Kontrollera att tidsstämplarna nu är i stigande ordning.

find 1 - Sök efter alla händelser från sensor med ID 1.

alarms - Se vilka sensorer som har triggat larmmodulen.