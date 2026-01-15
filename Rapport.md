Rapport1. Datastrukturer och ADTJag har valt att separera logiken i tydliga ADT:er 
(Abstract Data Types) för att hålla koden modulär:EventQueue (Ringbuffer): Använder en cirkulär array med en fast storlek. Detta är optimalt 
för inbyggda system då det garanterar konstant tidsåtgång $O(1)$ för både enqueue och dequeue utan att flytta data i minnet.EventLog (Dynamisk lista): En array som växer dynamiskt genom
att dubbla sin kapacitet vid behov. Detta ger en amorterad tidskomplexitet på $O(1)$ för tillägg.2. Algoritmer och KomplexitetSortering
(Insertion Sort): Jag har valt Insertion Sort. Den har en tidskomplexitet på $O(n^2)$ i värsta fall, men i en event-logg där data ofta kommer in nästan sorterad
(tidsföljd), presterar den nära $O(n)$.Sökning (Linjär sökning): För att hitta specifika sensor-ID:n används linjär sökning med komplexitet $O(n)$, då loggen inte är sorterad på sensor-ID.3. 
Designmönster: StrategyFör sorteringen har jag tillämpat en "Strategy-light"-modell. Genom att använda en funktionspekare
(SortStrategyFn) kan main-logiken anropa en sorteringsalgoritm utan att veta exakt vilken som körs. 
Detta gör det enkelt att i framtiden byta ut Insertion Sort mot t.ex. QuickSort utan att ändra i meny-systemet.4. MinneshanteringProgrammet
hanterar minne manuellt genom:Dynamisk allokering med new i klassernas konstruktorer.Garanterad frigöring med delete[] i destruktorer för att undvika 
minnesläckor.Resizing av EventLog som flyttar data och städar upp gamla arrayer korrekt.5. Valfri Modul: AlarmSet (Modul A)Jag har implementerat AlarmSet som en extra modul. 
Den övervakar händelserna när de flyttas från kön till loggen och sparar ID för sensorer som överskrider ett visst tröskelvärde (45).