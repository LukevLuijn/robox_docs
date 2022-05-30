
In dit onderdeel zullen enkele essentiële usecases in fully-dressed formaat uitgewerkt worden. De uitgewerkte usecases zijn gekozen op basis van systeem complexiteit en prioriteit.


## Robot starten

|||
|:---|:---|
|**Primary actor**|Gebruiker|
|**Brief description**|De gebruiker wil de robot starten.|
|**Pre conditions**|De robot is gedeactiveerd.|
|**Post conditions**|De robot is geactiveerd.|

||Actor action||System resposibility|
|:---:|:---|:---:|:---|
|1.|De gebruiker drukt op de 'Connect'-toggleknop.|2.|Het systeem veranderd de tekst van de 'Connect'-knop naar 'Disconnect'.|
|||3.|Het systeem kijkt of de robot beschikbaar is voor een seriële connectie.|
|||4.|Het systeem maakt een seriële connectie met de robot.|
|||5.|Het systeem start de data uitwisseling met de robot.|
|||6.|Het systeem activeert de 'Activate'-toggleknop.|
|7.|De gebruiker drukt op de 'Activate'-toggleknop.|8.|Het systeem stuurt een 'start'-bericht naar de robot.|
|||9.|Het systeem veranderd de tekst op de 'Activate'-toggleknop naar 'Deactivate'.|
|||10.|Het systeem activeert de 'Stop'-knop.|
|||11.|Het systeem activeert de 'E-Stop'-knop.|
|||10.|Zodra het systeem een 'homing-complete'-bericht ontvangt van de robot activeert het systeem het controle paneel.|
||**Alternative flow 01:**|3.|*De robot is niet beschikbaar voor een seriële connectie.*|
|||4a.|Het systeem zal een error-log bericht naar de gebruiker versturen waarin vermeld wordt dat de robot niet beschikbaar is.|
|||5a.|Het systeem veranderd de tekst van de 'Connect'-knop terug naar 'Connect'.|

**!usecase** - *Fully dressed usecase description - Robot starten*

## Robot stoppen

|||
|:---|:---|
|**Primary actor**|Gebruiker|
|**Brief description**|De gebruiker wil de robot stoppen.|
|**Pre conditions**|UC0_0 is succesvol uitgevoerd, de robot is gestart.|
|**Post conditions**|De robot is gedeactiveerd.|

||Actor action||System responsibility|
|:---:|:---|:---:|:---|
|1.|De gebruiker drukt op de 'Stop'-knop.|2.|Het systeem stuurt een 'Stop'-bericht naar de robot.|
|||3.|Het systeem deactiveert het controle paneel.|
|||4.|Het systeem deactiveert de 'Stop'-knop.|
|||5.|Het systeem deactiveert de 'E-Stop'-knop.|
|||6.|Het systeem deactiveert de 'Activate'-knop.|
|||7.|Het systeem veranderd de tekst van de 'Activate'-knop naar 'Activate'.|
||**Alternative flow 01:**|1.|*De gebruiker drukt op de 'Deactivate'-knop*|
||||Het systeem gaat verder bij stap 2.|
||**Alternative flow 02:**|1.|*De gebruiker drukt op de 'Disconnect'-knop*|
|||2a.|Het systeem zet de waarde van de 'Disconnect'-knop op ```false```.|
|||3a.|Het systeem veranderd de tekst van de 'Disconnect'-knop naar 'Connect'.|
|||4a.|Het systeem stopt de seriële connectie met de robot.|
||||Het systeem gaat verder bij stap 2.|
||**Alternative flow 03:**|1.|*De gebruiker drukt op de 'E-Stop'-knop*|
|||2b.|Het systeem stuurt een 'E-Stop'-bericht naar de robot.|
||||Het systeem gaat verder bij stap 3.|
||**Alternative flow 04:**|1.|*De gebruiker sluit de applicatie af.*|
|||2c.|Het systeem stuurt een 'E-Stop'-bericht naar de robot.|
|||3c.|Het systeem stopt de seriële connectie met de robot.|
|||4c.|Het systeem opent een pop-up met daarin de tekst 'Bye'.|
|5c.|De gebruiker drukt op de 'Ok'-knop|6c.|Het systeem sluit de applicatie af.|

**!usecase** - *Fully dressed usecase description - Robot stoppen*

## Aansturen met cartesiaanse coördinaten

|||
|:---|:---|
|**Primary actor**|Gebruiker|
|**Brief description**|De gebruiker wil de robot bewegen aan de hand van cartesiaanse coördinaten.|
|**Pre conditions**|UC0_0 is successvol uitgevoerd, de robot is gestart.|
|**Post conditions**|De gripper van de robot bevindt zich op de door de gebruiker opgegeven locatie.|

||Actor action||System responsibility|
|:---:|:---|:---:|:---|
|1.|De gebruiker geeft aan de robot aan te willen sturen door middel van de muis.|2.|Het systeem geeft het scherm weer waar de gebruiker de robot kan besturen met de muis.|
|3.|De gebruiker selecteert de gripper in de simulatie.|4.|Het systeem geeft aan dat de gripper geselecteerd is.|
|5.|De gebruiker verplaatst de gripper naar de gewenste locatie|6.|Het systeem geeft de huidige locatie weer.|
|7.|De gebruiker laat de linker muisknop los.|8.|Het systeem geeft aan dat de gripper niet meer geselecteerd is.|
|||9.|Het systeem berekend de de hoeken die resulteren in de opgegeven locatie.|
|||10.|Het systeem veranderd de waardes weergegeven in de text velden naar de berekende waardes.|
|||11.|Het systeem veranderd de waardes weergegeven op de sliders naar de berekende waardes.|
|12.|De gebruiker drukt op de 'Run'-knop|13.|Het systeem maakt een bericht aan voor de robot met de nieuwe waardes.|
|||14.|Het systeem verstuurd het nieuwe bericht naar de robot.|

**!usecase** - *Fully dressed usecase description - Aansturen met cartesiaanse coördinaten*

## Aansturen met hoeken via sliders

|||
|:---|:---|
|**Primary actor**|Gebruiker|
|**Brief description**|De gebruiker wil de robot bewegen aan de hand van verschillende hoeken, gekozen met sliders.|
|**Pre conditions**|UC0_0 is succesvol uitgevoerd, de robot is gestart.|
|**Post conditions**|De gripper van de robot bevindt zich op de door de gebruiker opgegeven locatie.|

||Actor action||System responsibility|
|:---:|:---|:---:|:---|
|1.|De gebruiker geeft aan de robot aan te willen sturen door middel van de muis.|2.|Het systeem geeft het scherm weer waar de gebruiker de robot kan besturen met de muis.|
|2.|De gebruiker selecteert de slider met de titel 'A1'.|||
|3.|De gebruiker beweegt de geselecteerde slider naar de gewenste positie.|4.|Het systeem update het bijhorende text veld naar de gekozen positie.|
|||5.|Het systeem update de simulatie zodat de gesimuleerde robot dezelfde hoek representeert als de gekozen waarde.|
|6.|De gebruiker laat de linker muisknop los.|7.|Het systeem slaat de positie op.|
|8.|De gebruiker selecteert de slider Met de titel 'A2'|||
|9.|De gebruiker beweegt de geselecteerde slider naar de gewenste positie.|10.|Het systeem update het bijhorende text veld naar de gekozen positie.|
|||11.|Hey systeem update de simulatie zodat de gesimuleerde robot dezelfde hoek representeert als de gekozen waarde.|
|12.|De gebruiker laat de linker muisknop los.|13.|Hey systeem slaat de positie op.|
|14.|De gebruiker drukt op de 'Run'-knop.|15.|Het systeem maakt een bericht aan voor de robot met de nieuwe waardes.|
|||16.|Het systeem verstuurd het nieuwe bericht naar de robot.|

**!usecase** - *Fully dressed usecase description - Aansturen met hoeken via sliders*

## Aansturen met hoeken via tekst velden

|||
|:---|:---|
|**Primary actor**|Gebruiker|
|**Brief description**|De gebruiker wil de robot bewegen aan de hand van verschillende hoeken, gekozen met tekst velden.|
|**Pre conditions**|UC0_0 is succesvol uitgevoerd, de robot is gestart.|
|**Post conditions**|De gripper van de robot bevindt zich op de door de gebruiker opgegeven locatie.|

||Actor action||System responsibility|
|:---:|:---|:---:|:---|
|1.|De gebruiker geeft aan de robot te willen besturen door middel van de muis.|2.|Het systeem geeft het scherm weer waar de gebruiker de robot kan besturen door middel van de muis.|
|3.|De gebruiker selecteert het tekst veld met de titel 'A1'.|||
|4.|De gebruiker typt een getal.|||
|5.|De gebruiker drukt op de 'enter'-toets.|6.|Het systeem controleert de opgegeven waarde.|
|||7.|Het systeem update de bijhorende slider naar de gekozen waarde.|
|||8.|Het systeem update de simulatie zodat de gesimuleerde robot dezelfde hoek representeert als de gekozen waarde.|
|9.|De gebruiker selecteert het text veld met de titel 'A2'.|||
|10.|De gebruiker typt een getal.|||
|11.|De gebruiker drukt op de 'enter'-toets.|12.|Het systeem controleert de opgegeven waarde.|
|||13.|Het systeem update de bijhorende slider naar de gekozen waarde.|
|||14.|Het systeem update de simulatie zodat de gesimuleerde robot dezelfde hoek representeert als de gekozen waarde.|
|15.|De gebruiker drukt op de 'Run'-knop|16.|Het systeem maakt een bericht aan voor de robot met de nieuwe waardes.|
|||17.|Het systeem verstuurd het nieuwe bericht naar de robot.|
||**Alternative flow 01:**|4.|*De gebruiker probeert meer dan 7 karakters te typen.*|
|||5a.|Het systeem verstuurd een warning-log bericht met daarin de vermelding dat een waarde niet langer mag zijn dan 7 karakters.|
||||Het systeem gaat verder bij stap 3.|
||**Alternative flow 02:**|6.|*De opgegeven waarde is geen getal.*|
|||7a.|Het systeem kleurt de ingevoerde waarde in het tekst veld rood.|
||||Het systeem gaat verder bij stap 3.|
||**Alternative flow 03:**|6.|*De opgegeven waarde is hoger dan het maximum.*|
|||7a.|Het systeem veranderd de opgegeven waarde in het maximum.|
||||Het systeem gaat verder bij stap 7.|
||**Alternative flow 04:**|6.|*De opgegeven waarde is lager dan het minimum.*|
|||7a.|Het systeem veranderd de opgegeven waarde in het minimum.|
||||Het systeem gaat verder bij stap 7.|

**!usecase** - *Fully dressed usecase description - Aansturen met hoeken via tekst velden*

## Instellen snelheid met een slider

|||
|:---|:---|
|**Primary actor**|Gebruiker|
|**Brief description**|De gebruiker wil de bewegingssnelheid van de robot aanpassen, gekozen met een slider.|
|**Pre conditions**|UC0_0 is succesvol uitgevoerd, de robot is gestart.|
|**Post conditions**|De snelheid van de robot is aangepast naar de gewenste snelheid.|

||Actor action||System responsibility|
|:---:|:---|:---:|:---|
|1.|De gebruiker geeft aan de robot aan te willen sturen door middel van de muis.|2.|Het systeem geeft het scherm weer waar de gebruiker de robot kan besturen met de muis.|
|3.|De gebruiker selecteert de slider met de titel 'Speed'|||
|4.|De gebruiker beweegt de geselecteerde slider naar de gewenste positie.|5.|Het systeem update het bijhorende text veld naar de gekozen waarde.|
|6.|De gebruiker laat e linker muisknop los.|7.|Het systeem slaat de nieuwe waarde op.|
|7.|De gebruiker drukt op de 'Run'-knop.|8.|Het systeem maakt een nieuw bericht aan voor de robot met de nieuwe waardes.|
|||9.|Het systeem verstuurd het nieuwe bericht naar de robot.|


**!usecase** - *Fully dressed usecase description - Instellen snelheid met een slider*

## Instellen snelheid met een tekst veld

|||
|:---|:---|
|**Primary actor**|Gebruiker|
|**Brief description**|De gebruiker wil de bewegingssnelheid van de robot aanpassen, gekozen met een tekst veld.|
|**Pre conditions**|UC0_0 is succesvol uitgevoerd, de robot is gestart.|
|**Post conditions**|De snelheid van de robot is aangepast naar de gewenste snelheid.|

||Actor action||System responsibility|
|:---:|:---|:---:|:---|
|1.|De gebruiker geeft aan de robot te willen besturen door middel van de muis.|2.|Het systeem geeft het scherm weer waar de gebruiker de robot kan besturen door middel van de muis.|
|3.|De gebruiker selecteert het tekst veld met de titel 'Speed'|||
|4.|De gebruiker typt een getal.|||
|5.|De gebruiker drukt op de 'Enter'-toets.|6.|Het systeem controleert de opgegeven waarde.|
|||7.|Het systeem update de bijhorende slider naar de gekozen waarde.|
|8.|De gebruiker drukt op de 'Run'-knop.|9.|Het systeem maakt een nieuw bericht aan voor de robot met daarin de nieuwe waardes.|
|||10.|Het systeem stuurt het nieuwe bericht naar de robot.|
||**Alternative flow 01:**|4.|*De gebruiker probeert meer dan 6 karakters te typen.*|
|||5a.|Het systeem verstuurd een warning-log bericht met daarin de vermelding dat een waarde niet langer mag zijn dan 7 karakters.|
||||Het systeem gaat verder bij stap 3.|
||**Alternative flow 02:**|6.|*De opgegeven waarde is geen getal.*|
|||7b.|Het systeem kleurt de ingevoerde waarde in het tekst veld rood.|
||||Het systeem gaat verder bij stap 3.|
||**Alternative flow 03:**|6.|*De opgegeven waarde is hoger dan het maximum.*|
|||7c.|Het systeem veranderd de opgegeven waarde in het maximum.|
||||Het systeem gaat verder bij stap 7.|
||**Alternative flow 04:**|6.|*De opgegeven waarde is lager dan het minimum.*|
|||7d.|Het systeem veranderd de opgegeven waarde in het minimum.|
||||Het systeem gaat verder bij stap 7.|

**!usecase** - *Fully dressed usecase description - Instellen snelheid met een tekst veld*
