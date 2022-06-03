
Dit is het software requirements specification document van het firmware aspect van het ROBOX project. De firmware van dit project zal draaien op een microcontroller in de robot zelf. Deze firmware is verantwoordelijk voor het correct interpreteren van de verschillende commando's afkomstig van de overkoepelende software draaiend op een verbonden computer. Verder is de firmware verantwoordelijk voor het waarborgen van de verschillende veiligheidseisen, eisen zoals tijdig stoppen, niet voorbij mini- en maximale waardes gaan en soortgelijke situaties.

## Gebruikers, klassen en karakteristieken

Voor de firmware is er een enkele actor; Het overkoepelende systeem draaiend op een aangrenzende computer. De gebruiker van ROBOX zal geen directe interactie met de firmware hebben.

## Ontwerp- en implementatie beperkingen

Gezien microcontrollers een beperkte hoeveelheid RAM en Geheugen hebben zal er tijdens de ontwikkeling rekening gehouden worden met deze beperkingen. De firmware zal dus waar mogelijk geen gebruik maken van dynamisch geheugen en zo veel mogelijk aspecten beperken op gebied van 'run time data' en de data maximaliseren op gebied van 'compile time data'.

## Ontwikkelomgeving

De firmware zal ontwikkeld worden voor een moderne microcontroller met een degelijke clock snelheid. Een voorbeeld van een dergelijke microcontroller is bijvoorbeeld de [Teensy 4.0](https://www.pjrc.com/store/teensy40.html) (PJRC, n.d.), deze microcontroller beschikt over een 32 bits ARM IC met een clock snelheid van 600 MHz. Een voorbeeld van een niet geschikte microcontroller is bijvoorbeeld de [Arduino Uno](http://store.arduino.cc/products/arduino-uno-rev3) (Arduino, n.d.), deze microcontroller beschikt over een 8 bits ATmega IC met een clock snelheid van 16MHz.

De gebruikte microcontroller zal verder moeten beschikken over een seriële bus die aanspreekbaar is over USB. De communicatie met de overkoepelende software zal hier namelijk gebruik van maken.

## Product functionaliteiten

De firmware zal verantwoordelijk zijn voor het aansturen en uitlezen van de verschillende hardware componenten. Hierbij is het belangrijk dat de componenten op correcte wijzen aangestuurd worden en mini- en maximalen waardes niet overschreden worden. Dit is belangrijk omdat er gewerkt zal worden met een fysiek apparaat dat zal beschikken over motors die krachtig genoeg zijn om het apparaat te vernielen. 


!url PJRC. (n.d.). Teensy® 4.0. Teensy 4.0. Retrieved May 25, 2022, from [https://www.pjrc.com/store/teensy40.html](https://www.pjrc.com/store/teensy40.html)
!url Arduino. (n.d.). Arduino Uno Rev3. Arduino Official Store. Retrieved May 25, 2022, from [http://store.arduino.cc/products/arduino-uno-rev3](http://store.arduino.cc/products/arduino-uno-rev3)