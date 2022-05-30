
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

In dit hoofdstuk zullen de verschillende (niet-) functionele requirements beschreven worden van firmware applicatie.

## Functionele requirements

|Index|Prioriteit|Requirement|Voldaan|
|:---:|:---:|:---|:---:|
|**FR-01**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de maximale positie per motor.|:heavy_check_mark:|
|**FR-02**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de minimale positie per motor.|:heavy_check_mark:|
|**FR-03**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de huidige snelheid per motor.|:heavy_check_mark:|
|**FR-04**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de huidgie acceleratie per motor.|:heavy_check_mark:|
|**FR-05**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de huidige positie per motor.|:heavy_check_mark:|
|**FR-06**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de huidige gripper PWM waarde.|:heavy_check_mark:|
|**FR-07**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het bewegen van de robot aan de hand van verschillende hoeken.|:heavy_check_mark:|
|**FR-08**|<p class=must>Must</p>|Het systeem oet de mogelijkheid bieden tot het bewegen van de robot aan de hand van een cartesiaanse positie (x,y,z).|:heavy_check_mark:|
|**FR-09**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het instellen van de huidige gripper PWM waarde.|:heavy_check_mark:|
|**FR-10**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het stoppen van de robot.|:heavy_check_mark:|
|**FR-11**|<p class=must>Must</p>|Het systeem moet de mogelijkheid bieden tot het direct stoppen van de robot (noodstop).|:heavy_check_mark:|
|**FR-12**|<p class=must>Must</p>|Het systeem moet commando's kunnen opslaan en later uitvoeren.|:heavy_check_mark:|
|**FR-13**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het instellen van globale snelheid.|:heavy_check_mark:|
|**FR-14**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het instellen van globale acceleratie.|:heavy_check_mark:|
|**FR-15**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het instellen van de snelheid per motor.|:heavy_check_mark:|
|**FR-16**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het instellen van de accleratie per motor.|:heavy_check_mark:|
|**FR-17**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het (de)activeren van de *error* berichten.|:heavy_check_mark:|
|**FR-18**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het (de)activeren van de *warning* berichten.|:heavy_check_mark:|
|**FR-19**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het (de)activeren van de *info* berichten.|:heavy_check_mark:|
|**FR-20**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het (de)activeren van de *debug* berichten.|:heavy_check_mark:|
|**FR-21**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het instellen van de **frame height offset*.|:heavy_check_mark:|
|**FR-22**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het instellen van de **gripper height offset*.|:heavy_check_mark:|
|**FR-23**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het instellen van de **idle position* per motor.|:heavy_check_mark:|
|**FR-24**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de huidige **frame height offset*.|:heavy_check_mark:|
|**FR-25**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de huidige **gripper height offset*.|:heavy_check_mark:|
|**FR-26**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het opvragen of een motor momenteel actief is (aan het bewegen).|:heavy_check_mark:|
|**FR-27**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de huidige positie van de gripper in het cartesiaans coordinaten systeem (x,y,z).|:heavy_check_mark:|
|**FR-28**|<p class=should>Should</p>|Het systeem moet de mogelijkheid bieden tot het pauzeren van de robot voor een bepaald aantal milliseconden.|:heavy_check_mark:|
|**FR-29**|<p class=should>Should</p>|Het systeem moet de gebruiker laten weten waneer een aangevraagde positie niet bereikbaar is. Bijvoorbeeld door een log bericht.|:heavy_check_mark:|
|**FR-30**|<p class=should>Should</p>|Het systeem moet de gebruiker laten weten wanneer een aangevraagde gripper waarde niet mogelijk is, bijvoorbeeld door een log bericht.|:heavy_check_mark:|
|**FR-31**|<p class=should>Should</p>|Het systeem moet de gebruiker laten weten wanneer een aangevraagde snelheid niet mogelijk is, bijvoorbeeld door een log bericht.|:heavy_check_mark:|
|**FR-32**|<p class=should>Should</p>|Het systeem moet de gebruiker laten weten wanneer een aangevraagde acceleratie niet mogelijk is, bijvoorbeeld door een log bericht.|:heavy_check_mark:|
|**FR-33**|<p class=should>Should</p>|Het systeem moet de gebruiker laten weten wanneer een aangevraagde **idle positie* niet mogelijk is, bijvoorbeeld door een log bericht.|:heavy_check_mark:|
|**FR-34**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de verschillende pin configuraties.|:heavy_check_mark:|
|**FR-35**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de microstepping resolutie per motor.|:heavy_check_mark:|
|**FR-36**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de **steps per degree* waarde per radiale actuator.|:heavy_check_mark:|
|**FR-37**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvrgane van de **steps per millimeter* waarde per lineare actuator. |:heavy_check_mark:|
|**FR-38**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de status van *error* berichten.|:heavy_check_mark:|
|**FR-39**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de status van *warning* berichten.|:heavy_check_mark:|
|**FR-40**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de status van *info* berichten.|:heavy_check_mark:|
|**FR-41**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de status van *debug* berichten.|:heavy_check_mark:|
|**FR-42**|<p class=could>Could</p>|Het systeem moet de mogelijkheid bieden tot het opvragen van de **idle positions* per motor.|:heavy_check_mark:|

**!tabel** - *Functionele requirements*

> ```*``` *Frame height offset* staat voor het verschil tussen de laagst mogelijke positie van de robot en de daadwerkelijke ondergrond waar het apparaat zich op bevind.

> ```*``` *Gripper height offset* staat voor het verschil in hoogte tussen het laagste deel van de gripper en het hoogste (bewegende) deel van de robot.

> ```*``` *Idle positions* zijn de posities die de robot aanneemt waaneer er een stop commando is ontvangen. 

> ```*``` *Steps per degree* is het aantal stappen de motor moet maken voor het een graad is gedraaid.

> ```*``` *Steps per millimeter* is het aantal stappen de motor moet maken voor het een milimeter is veranderd in hoogte.
> 
<div style="page-break-after: always;"></div>


## Niet functionele requirements

In dit onderdeel worden de niet functionele requirements verder toegelicht. De niet functionele requirements zijn onderverdeeld op basis van quality of service (QoS). De verschillende QoS elementen; usability, reliability, performance en supportability, zijn in de onderstaande tabel uitgwerkt.

### QoS - Usability

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-01**|<p class=must>Must</p>|*Safety*|Het systeem zal logs met de prioriteit: <span class=error>ERROR</span> naar de gebruiker sturen, indien de gebruiker dit niet specifiek heeft gedeactiveerd.|:heavy_check_mark:|
|**NFR-02**|<p class=must>Must</p>|*Safety*|Het systeem zal logs met de prioriteit: <span class=warning>WARNING</span> naar de gebruiker sturen, indien de gebruiker dit niet specifiek heeft gedeactiveerd.|:heavy_check_mark:|
|**NFR-03**|<p class=must>Must</p>|*Safety*|Het systeem zal logs met de prioriteit: <span class=info>INFO</span> naar de gebruiker sturen, indien de gebruiker dit niet specifiek heeft gedeactiveerd.|:heavy_check_mark:|
|**NFR-04**|<p class=must>Must</p>|*Safety*|Het systeem zal logs met de prioriteit: <span class=debug>DEBUG</span> naar de gebruiker sturen, indien de gebruiker dit niet specifiek heeft gedeactiveerd.|:heavy_check_mark:|
|**NFR-05**|<p class=must>Must</p>|*Quality*|Alle publieke methodes in het systeem zullen voorzien worden van beschrijvend [doxygen](https://www.doxygen.nl/manual/docblocks.html) (Doxygen, n.d.) commentaar.|:heavy_check_mark:|
|**NFR-06**|<p class=must>Must</p>|*Quality*|Commentaar in code zal geschreven worden in de voertaal: engels.|:heavy_check_mark:|
|**NFR-07**|<p class=should>Should</p>|*Quality*|De verschillende onderdelen in het systeem zullen worden onderverdeeld in namespaces.|:heavy_check_mark:|
|**NFR-08**|<p class=should>Should</p>|*Quality*|De verschillende header documenten (*.h) zullen worden gegroepeerd op basis van namespace.|:heavy_check_mark:|
|**NFR-09**|<p class=could>Could</p>|*Quality*|De applicatie zal voorzien worden van een installatiehandleiding.|:heavy_multiplication_x:|
|**NFR-10**|<p class=could>Could</p>|*Quality*|De installatiehandleiding zal geschreven worden in de voertaal; engels.|:heavy_multiplication_x:|
|**NFR-11**|<p class=could>Could</p>|*Quality*|De applicatie zal voorzien worden van een gebruikershandleiding.|:heavy_multiplication_x:|
|**NFR-12**|<p class=could>Could</p>|*Quality*|De gebruikershandleiding zal geschreven worden in de voertaal; engels.|:heavy_multiplication_x:|

**!tabel** - *niet functionele requirements - QoS Usability*

### QoS - Reliability

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-13**|<p class=must>Must</p>|*Reliability*|Het systeem zal voorzien zijn van mini- en maximale positionele waardes per motor.|:heavy_check_mark:|
|**NFR-14**|<p class=must>Must</p>|*Reliability*|Het systeem zal rekening houden met de mini- en maximale positionele waardes door deze niet te overschreiden.|:heavy_check_mark:|
|**NFR-15**|<p class=must>Must</p>|*Reliability*|Het systeem zal voorzien zijn van mini- en maximale snelheids waardes per motor.|:heavy_check_mark:|
|**NFR-16**|<p class=must>Must</p>|*Reliability*|Het systeem zal rekening houden met de mini- en maximale snelheids waardes door deze niet te overschreiden. |:heavy_check_mark:|
|**NFR-17**|<p class=must>Must</p>|*Reliability*|Het systeem zal voorzien zijn van mini- en maximale acceleratie waardes per motor.|:heavy_check_mark:|
|**NFR-18**|<p class=must>Must</p>|*Reliability*|Het systeem zal rekening houden mde mini- en maximale accelerate waardes door deze niet te overschreiden.|:heavy_check_mark:|
|**NFR-19**|<p class=must>Must</p>|*Safety*|Het systeem zal binnen 100 milliseconden tot stilstand komen in het geval van een noodstop.|:heavy_check_mark:|
|**NFR-20**|<p class=could>Could</p>|*Reliability*|Het systeem zal altijd hetzelfde pad volgen vanaf een positie A naar een positie B|:heavy_check_mark:|

**!tabel** - *niet functionele requirements - QoS Reliability*

<div style="page-break-after: always;"></div>

### QoS - Performance

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-21**|<p class=must>Must</p>|*Timeliness*|Het systeem zal binnen 100 milliseconden en beweginscommando uitvoeren indien er geen andere beweginscommando's in de wachtrij staan.|:heavy_check_mark:|
|**NFR-22**|<p class=must>Must</p>|*Timeliness*|Het systeem zal binnen 20 milliseconden een response hebben verstuurd wanneer er een data request ontvangen is.|:heavy_check_mark:|

**!tabel** - *niet functionele requirements - QoS Performance*

### QoS - Supportability

|Index|Prioriteit|Onderdeel|Requirement|Voldaan|
|:---:|:---:|:---:|:---|:---:|
|**NFR-23**|<p class=must>Must</p>|*Quality*|Het product zal ontwikkeld worden in de visual studio code extensie: PlatformIO.|:heavy_check_mark:|
|**NFR-24**|<p class=should>Should</p>|*Quality*|De configureerbare aspecten van het systeem zullen een omschrijvende documentatie krijgen per onderdeel.|:heavy_multiplication_x:|
|**NFR-25**|<p class=should>Should</p>|*Quality*|Het product zal voorzien worden van een document waarin beschreven staat welke eventuele bugs of fouten er aanwezig zijn.|:heavy_multiplication_x:|
|**NFR-26**|<p class=should>Should</p>|*Quality*|Het product zal voorzien worden van een document waarin beschreven staat welke toekomstige verbeterpunten er zijn.|:heavy_multiplication_x:|
|**NFR-27**|<p class=could>Could</p>|*Quality*|Het product zal voorzien worden van omschrijvende documentatie.|:heavy_check_mark:|

**!tabel** - *niet functionele requirements - QoS Supportability*

!url Doxygen. (n.d.). Doxygen Manual: Documenting the code. Retrieved May 25, 2022, from [https://www.doxygen.nl/manual/docblocks.html](https://www.doxygen.nl/manual/docblocks.html)