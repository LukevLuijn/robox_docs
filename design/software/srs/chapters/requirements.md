<style>
span.error       {color:#FF0000; background-color:#000000; border-radius:3px}
span.warning     {color:#FFFF00; background-color:#000000; border-radius:3px}
span.info        {color:#00FF00; background-color:#000000; border-radius:3px}
span.debug       {color:#FF00FF; background-color:#000000; border-radius:3px}
p.must           {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.should         {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.could          {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.wont           {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.must           {border:3px; border-style:solid; border-color:#00FF00; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
p.should         {border:3px; border-style:solid; border-color:#FFA500; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
p.could          {border:3px; border-style:solid; border-color:#0000FF; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
p.wont           {border:3px; border-style:solid; border-color:#DDDDDD; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
</style>

## Functionele requirements

|Index|Prioriteit|Requirement|Voldaan|
|:---:|:---:|:---|:---:|
|**FR-00**|<p class=must>Must</p>|De gebruiker moet de huidige methodiek van aansturing kunnen selecteren.|:heavy_check_mark:|
|**FR-01**|<p class=must>Must</p>|De gebruiker moet een individuele as kunnen aansturen door middel van het invoeren van een bepaalde hoek.|:heavy_check_mark:|
|**FR-02**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de snelheid van de robot door middel van een slider.|:heavy_check_mark:|
|**FR-03**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de snelheid van de robot door middel van een text veld.|:heavy_check_mark:|
|**FR-04**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de acceleratie van de robot door middel van een slider.|:heavy_check_mark:|
|**FR-05**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de acceleratie van de robot door middel van een text veld.|:heavy_check_mark:|
|**FR-06**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de positie van een segment door middel van een slider.|:heavy_check_mark:|
|**FR-07**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de positie van een segment door middel van een text veld.|:heavy_check_mark:|
|**FR-08**|<p class=must>Must</p>|Het systeem moet de minimale waarde van de sliders gelijkstellen op basis van de waardes verkregen van de robot.|:heavy_check_mark:|
|**FR-09**|<p class=must>Must</p>|Het systeem moet de maximale waarde van de sliders gelijkstellen op basis van de waardes verkregen van de robot.|:heavy_check_mark:|
|**FR-10**|<p class=must>Must</p>|Het systeem moet de minimale waarde van de text velden gelijkstellen op basis van de waardes verkregen van de robot.|:heavy_check_mark:|
|**FR-11**|<p class=must>Must</p>|Het systeem moet de maximale waarde van de text velden gelijkstellen op basis van de waardes verkregen van de robot.|:heavy_check_mark:|
|**FR-12**|<p class=must>Must</p>|Het systeem moet de simulatie updaten met de huidige posities verkregen van de robot.|:heavy_check_mark:|
|**FR-13**|<p class=must>Must</p>|De simulatie moet de huidige positie in cartesiaanse coördinaten weergeven.|:heavy_check_mark:|
|**FR-14**|<p class=must>Must</p>|De gebruiker moet de huidige positie van de gripper kunnen aanpassen aan de hand van cartesiaanse coördinaten.|:heavy_check_mark:|
|**FR-15**|<p class=must>Must</p>|De gebruiker moet de bewegingssnelheid kunnen aanpassen.|:heavy_check_mark:|
|**FR-16**|<p class=must>Must</p>|De gebruiker moet de acceleratie kunnen aanpassen.|:heavy_check_mark:|
|**FR-17**|<p class=must>Must</p>|De applicatie moet een tekst veld valideren op basis van invoer lengte.|:heavy_check_mark:|
|**FR-18**|<p class=must>Must</p>|De applicatie moet een melding geven wanneer een ingevoerde string in een tekst veld te lang is.|:heavy_check_mark:|
|**FR-19**|<p class=must>Must</p>|De applicatie moet een tekst veld valideren op basis van karakter keuze.|:heavy_check_mark:|
|**FR-20**|<p class=must>Must</p>|De applicatie moet een melding geven wanneer een ingevoerd karakter niet toegestaan is.|:heavy_check_mark:|
|**FR-21**|<p class=must>Must</p>|De applicatie moet een gevalideerde waarde in een tekst veld checken op basis van minimum waarde.|:heavy_check_mark:|
|**FR-22**|<p class=must>Must</p>|De applicatie moet een gevalideerde waarde in een tekst veld checken op basis van maximum waarde.|:heavy_check_mark:|
|**FR-23**|<p class=must>Must</p>|De applicatie moet alle onderdelen die dezelfde variable weergegeven tegelijkertijd updaten.|:heavy_check_mark:|
|**FR-24**|<p class=must>Must</p>|De applicatie moet de mogelijkheid bieden tot het filteren van een bepaalde log gradatie.|:heavy_check_mark:|
|**FR-25**|<p class=must>Must</p>|De applicatie moet de log berichten kunnen onderverdelen in vier verschillende gradaties; <span class=error>ERROR</span>, <span class=warning>WARNING</span>, <span class=info>INFO</span>, <span class=debug>DEBUG</span>.|:heavy_check_mark:|
|**FR-26**|<p class=must>Must</p>|De applicatie moet ondersteuning bieden voor het loggen naar de console.|:heavy_check_mark:|
|**FR-27**|<p class=must>Must</p>|Er moet een simulatie zijn die de huidige oriëntatie van de robot weergeeft.|:heavy_check_mark:|
|**FR-28**|<p class=must>Must</p>|Er moet een simulatie zijn die de een voorbeeld geeft van de nieuwe positie van de robot.|:heavy_check_mark:|
|**FR-29**|<p class=must>Must</p>|Er moet een simulatie zijn waarbij als de gripper verplaatst word deze positie wordt opgeslagen en afgespeeld kan worden.|:heavy_check_mark:|
|**FR-30**|<p class=must>Must</p>|De applicatie moet de mogelijkheid bieden tot het instellen van de PWM waarde voor de gripper.|:heavy_check_mark:|
|**FR-31**|<p class=must>Must</p>|De applicatie moet de mogelijkheid bieden tot het automatisch afspelen van een ingevoerde positie.|:heavy_check_mark:|
|**FR-32**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het stoppen van de robot door middel van een knop.|:heavy_check_mark:|
|**FR-33**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het uitvoeren van een noodstop door middel van een knop.|:heavy_check_mark:|
|**FR-34**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het starten van een seriële verbinding met de robot.|:heavy_check_mark:|
|**FR-35**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het stoppen van een seriële verbinding met de robot.|:heavy_check_mark:|
|**FR-36**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het 'activeren' van de robot.|:heavy_check_mark:|
|**FR-37**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het 'deactiveren' van de robot.|:heavy_check_mark:|
|**FR-38**|<p class=should>Should</p>|De gebruiker moet de robot kunnen aansturen door middel van de pijltjes toetsen.|:heavy_multiplication_x:|
|**FR-39**|<p class=should>Should</p>|De gebruiker moet de robot kunnen aansturen door middel van de WASD-toetsen.|:heavy_multiplication_x:|
|**FR-40**|<p class=should>Should</p>|De gebruiker moet de snelheid van de robot kunnen aanpassen door middel van de toetsen [```+```/```-```].|:heavy_multiplication_x:|
|**FR-41**|<p class=should>Should</p>|De gebruiker moet de stapgrootte van de robot kunnen aanpassen door middel van de toetsen [```page-up```/```page-down```]|:heavy_multiplication_x:|
|**FR-42**|<p class=should>Should</p>|De gebruiker moet de hoogte van de robot kunnen aanpassen door middel van het ```scroll-wheel```.|:heavy_multiplication_x:|
|**FR-43**|<p class=should>Should</p>|De applicatie moet voorzien zijn van een log-venster waar de verschillende log berichten te zien zijn.|:heavy_check_mark:|
|**FR-44**|<p class=should>Should</p>|De applicatie moet ondersteuning bieden voor het weergeven van interne logs.|:heavy_check_mark:|
|**FR-45**|<p class=should>Should</p>|De applicatie moet de mogelijkheid bieden tot het filteren van interne log berichten.|:heavy_check_mark:|
|**FR-46**|<p class=should>Should</p>|De applicatie moet de mogelijkheid bieden tot het filteren van externe log berichten.|:heavy_check_mark:|
|**FR-47**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de **frame height* waarde van de robot.|:heavy_multiplication_x:|
|**FR-48**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de **gripper height* waarde van de robot.|:heavy_multiplication_x:|
|**FR-49**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de **idle positions* van de robot.|:heavy_multiplication_x:|
|**FR-50**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de status van <span class=error>ERROR</span> berichten van de robot.|:heavy_multiplication_x:|
|**FR-51**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de status van <span class=warning>WARNING</span> berichten van de robot.|:heavy_multiplication_x:|
|**FR-52**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de status van <span class=info>INFO</span> berichten van de robot.|:heavy_multiplication_x:|
|**FR-53**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het aanpassen van de status van <span class=debug>DEBUG</span> berichten van de robot.|:heavy_multiplication_x:|
|**FR-54**|<p class=could>Could</p>|De gebruiker moet een bepaalde positie kunnen opslaan.|:heavy_multiplication_x:|
|**FR-55**|<p class=could>Could</p>|De gebruiker moet een opgeslagen positie kunnen aanpassen.|:heavy_multiplication_x:|
|**FR-56**|<p class=could>Could</p>|De gebruiker moet een opgeslagen positie kunnen verwijderen.|:heavy_multiplication_x:|
|**FR-57**|<p class=could>Could</p>|De gebruiker moet een opgeslagen positie kunnen opslaan in een sequence.|:heavy_multiplication_x:|
|**FR-58**|<p class=could>Could</p>|De gebruiker moet een sequence kunnen aanpassen.|:heavy_multiplication_x:|
|**FR-59**|<p class=could>Could</p>|De gebruiker moet een sequence kunnen verwijderen.|:heavy_multiplication_x:|
|**FR-60**|<p class=could>Could</p>|De gebruiker moet een nieuwe sequence kunnen aanmaken.|:heavy_multiplication_x:|
|**FR-61**|<p class=could>Could</p>|De gebruiker moet een sequence kunnen afspelen.|:heavy_multiplication_x:|
|**FR-62**|<p class=could>Could</p>|De gebruiker moet een sequence herhaaldelijk kunnen afspelen.|:heavy_multiplication_x:|
|**FR-63**|<p class=could>Could</p>|De gebruiker moet de bewegingsvolgorde van een sequence kunnen aanpassen.|:heavy_multiplication_x:|
|**FR-64**|<p class=could>Could</p>|De gebruiker moet de robot kunnen aansturen door middel van de joysticks op een BLT controller.|:heavy_multiplication_x:|
|**FR-65**|<p class=could>Could</p>|De gebruiker moet de robot kunnen aansturen door middel van de pijltjestoetsen op een BLT controller.|:heavy_multiplication_x:|
|**FR-66**|<p class=could>Could</p>|De gebruiker moet de snelheid van de robot kunnen aanpassen door middel van de 'driehoek' & 'kruis' knoppen op een BLT controller.|:heavy_multiplication_x:|
|**FR-67**|<p class=could>Could</p>|De gebruiker moet de stapgrootte van de robot kunnen aanpassen door middel van de 'vierkant' & 'cirkel' knoppen op een BLT controller.|:heavy_multiplication_x:|
|**FR-68**|<p class=could>Could</p>|De gebruiker moet de hoogte van de robot kunnen aanpassen door middel van de 'R1' & 'R2' knoppen op een BLT controller.|:heavy_multiplication_x:|
|**FR-69**|<p class=could>Could</p>|De applicatie moet ondersteuning bieden voor het weergeven van externe logs (vanaf de robot).|:heavy_check_mark:|
|**FR-70**|<p class=could>Could</p>|De applicatie moet ondersteuning bieden voor het loggen naar het venster.|:heavy_check_mark:|
|**FR-71**|<p class=could>Could</p>|De applicatie moet ondersteuning bieden voor het loggen naar een document.|:heavy_multiplication_x:|
|**FR-72**|<p class=could>Could</p>|De applicatie moet de mogelijkheid bieden om de huidige logs te verwijderen.|:heavy_check_mark:|
|**FR-73**|<p class=could>Could</p>|Het systeem moet de maximale positie per segment kunnen weergeven.|:heavy_check_mark:|
|**FR-74**|<p class=could>Could</p>|Het systeem moet de minimale positie per segment kunnen weergeven.|:heavy_check_mark:|
|**FR-75**|<p class=could>Could</p>|Het systeem moet de maximale snelheid van een segment kunnen weergeven.|:heavy_multiplication_x:|
|**FR-77**|<p class=could>Could</p>|Het systeem moet de huidige pin configuratie van de robot kunnen weergeven.|:heavy_multiplication_x:|
|**FR-78**|<p class=could>Could</p>|Het systeem moet de huidige microstepping configuratie per segment kunnen weergeven.|:heavy_multiplication_x:|
|**FR-79**|<p class=could>Could</p>|Het systeem moet de huidige **steps per millimeter* waarde kunnen weergeven voor segment 0.|:heavy_multiplication_x:|
|**FR-80**|<p class=could>Could</p>|Het systeem moet de huidige **steps per degree* waarde kunnen weergeven voor segment 1,2 & 3.|:heavy_multiplication_x:|
|**FR-81**|<p class=could>Could</p>|Het systeem moet de huidige snelheid per segment kunnen weergeven.|:heavy_multiplication_x:|
|**FR-82**|<p class=could>Could</p>|Het systeem moet de huidige acceleratie per segment kunnen weergeven.|:heavy_multiplication_x:|
|**FR-83**|<p class=could>Could</p>|Het systeem moet de huidige status van <span class=error>ERROR</span> berichten kunnen weergeven, beide voor de robot en de applicatie.|:heavy_multiplication_x:|
|**FR-84**|<p class=could>Could</p>|Het systeem moet de huidige status van <span class=warning>WARNING</span> berichten kunnen weergeven, beide voor de robot en de applicatie.|:heavy_multiplication_x:|
|**FR-85**|<p class=could>Could</p>|Het systeem moet de huidige status van <span class=info>INFO</span> berichten kunnen weergeven, beide voor de robot en de applicatie.|:heavy_multiplication_x:|
|**FR-86**|<p class=could>Could</p>|Het systeem moet de huidige status van <span class=debug>DEBUG</span> berichten kunnen weergeven, beide voor de robot en de applicatie.|:heavy_check_mark:|

**!tabel** - *Functionele requirements* 

## Niet functionele requirements

In dit onderdeel worden de niet functionele requirements verder toegelicht. De niet functionele
requirements zijn onderverdeeld op basis van quality of service (QoS). De verschillende QoS elementen;
usability, reliability, performance en supportability, zijn in de onderstaande tabel uitgewerkt.

### QoS - Usability

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-00**|<p class=must>Must</p>|*Safety*|Het systeem moet de interne log berichten met een prioriteit ERROR naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-01**|<p class=must>Must</p>|*Safety*|Het systeem moet de interne log berichten met een prioriteit WARNING naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-02**|<p class=must>Must</p>|*Safety*|Het systeem moet de interne log berichten met een prioriteit INFO naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-03**|<p class=must>Must</p>|*Safety*|Het systeem moet de interne log berichten met een prioriteit DEBUG naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-04**|<p class=must>Must</p>|*Safety*|Het systeem moet de externe log berichten met een prioriteit ERROR naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-05**|<p class=must>Must</p>|*Safety*|Het systeem moet de externe log berichten met een prioriteit WARNING naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-06**|<p class=must>Must</p>|*Safety*|Het systeem moet de externe log berichten met een prioriteit INFO naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-07**|<p class=must>Must</p>|*Safety*|Het systeem moet de externe log berichten met een prioriteit DEBUG naar de gebruiker sturen indien deze niet specifiek zijn uitgeschakeld.|:heavy_check_mark:|
|**NFR-08**|<p class=must>Must</p>|*Quality*|Alle publieke methodes in het systeem zullen voorzien zijn van beschrijvend [Doxygen](https://www.doxygen.nl/manual/docblocks.html) commentaar.|:heavy_check_mark:|
|**NFR-09**|<p class=must>Must</p>|*Quality*|Alle bestanden met betrekking tot de code zullen voorzien van een header met daarin de datum van aanmaak en de naam van de schrijver.|:heavy_check_mark:|
|**NFR-10**|<p class=must>Must</p>|*Quality*|Al het commentaar verwerkt in de code zal geschreven worden met de voertaal; Engels.|:heavy_check_mark:|
|**NFR-11**|<p class=must>Must</p>|*Quality*|De verschillende onderdelen in het systeem die een gelijksoortig doel nastreven zullen worden gegroepeerd in een namespace.|:heavy_check_mark:|
|**NFR-12**|<p class=must>Must</p>|*Quality*|De verschillende header bestanden (*.h) zullen worden onderverdeeld in mappen op basis van namespace.|:heavy_check_mark:|
|**NFR-13**|<p class=should>Should</p>|*Quality*|De applicatie zal worden voorzien van een installatie handleiding.|:heavy_multiplication_x:|
|**NFR-14**|<p class=should>Should</p>|*Quality*|De installatie handleiding zal geschreven worden in de voertaal; Engels|:heavy_multiplication_x:|
|**NFR-15**|<p class=should>Should</p>|*Quality*|De applicatie zal worden voorzien van een gebruikershandleiding.|:heavy_multiplication_x:|
|**NFR-16**|<p class=should>Should</p>|*Quality*|De gebruikershandleiding zal geschreven worden in de voertaal; Engels.|:heavy_multiplication_x:|

### QoS - Reliability

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-17**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat een gebruiker geen commando's direct naar de robot kan sturen.|:heavy_check_mark:|
|**NFR-18**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat wanneer de robot niet ge-'homed' is er geen bewegingscommando's verstuurd worden.|:heavy_check_mark:|
|**NFR-19**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat er geen snelheid waardes hoger dan het maximum verstuurd zullen worden.|:heavy_check_mark:|
|**NFR-20**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat er geen acceleratie waardes hoger dan het maximum verstuurd zullen worden.|:heavy_check_mark:|
|**NFR-21**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat er geen posities verstuurd worden die hoger dan het maximum voor dat segment zijn.|:heavy_check_mark:|
|**NFR-22**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat er geen posities verstuurd worden die lager dan het minimum voor dat segment zijn.|:heavy_check_mark:|
|**NFR-23**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat de 'E-Stop'-knop altijd zichtbaar is in de applicatie.|:heavy_check_mark:|
|**NFR-24**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat wanneer de robot aan het bewegen is de E-Stop knop actief is.|:heavy_check_mark:|
|**NFR-25**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat een 'E-Stop'-knop trigger altijd direct naar de robot verstuurd wordt.|:heavy_check_mark:|
|**NFR-26**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat wanneer de applicatie wordt afgesloten de robot gedeactiveerd word.|:heavy_check_mark:|
|**NFR-27**|<p class=must>Must</p>|*Safety*|Het systeem zal ervoor zorgen dat wanneer de applicatie wordt afgesloten de seriële connectie afgesloten wordt.|:heavy_check_mark:|
|**NFR-28**|<p class=should>Should</p>|*Reliability*|Het systeem zal na 5 minuten inactiviteit de robot automatisch deactiveren.|:heavy_multiplication_x:|
|**NFR-29**|<p class=should>Should</p>|*Reliability*|Het systeem zal na 5 minuten inactiviteit de seriële connectie automatisch afsluiten.|:heavy_multiplication_x:|

### QoS - Performance

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-30**|<p class=must>Must</p>|*Timeliness*|Het systeem zal losse 'update'-threads vertragen tot maximaal 1000x per seconden.|:heavy_check_mark:|
|**NFR-31**|<p class=must>Must</p>|*Timeliness*|Het systeem zal binnen 100 milliseconden een bewegingscommando versturen naar de robot.|:heavy_check_mark:|
|**NFR-32**|<p class=must>Must</p>|*Timeliness*|Het systeem zal binnen 20 milliseconden na het ontvangen van een data response dit response hebben verwerkt in de applicatie.|:heavy_check_mark:|

## QoS - Supportability

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-33**|<p class=must>Must</p>|*Quality*|Het product zal ontwikkeld worden in Jetbrains - CLion.|:heavy_check_mark:|
|**NFR-34**|<p class=must>Must</p>|*Quality*|Het product zal voorzien worden van omschrijvende documentatie.|:heavy_check_mark:|
|**NFR-35**|<p class=should>Should</p>|*Quality*|Het product zal voorzien worden van een document waarin beschreven staat welke eventuele bugs of fouten er aanwezig zijn.|:heavy_multiplication_x:|
|**NFR-36**|<p class=should>Should</p>|*Quality*|Het product zal voorzien worden van een document waarin beschreven staat welke toekomstige verbeterpunten er zijn.|:heavy_multiplication_x:|



!url https://www.doxygen.nl/manual/docblocks.html