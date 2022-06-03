Aan het begin van dit document word de hoofdvraag van dit project opgesteld;

> **- Hoe maak je een robotarm die door iedereen (binnen de doelgroep) te bouwen is, goed presteert, en niet teveel kost?**

In het verloop van het ROBOX project is er geprobeerd deze hoofdvraag verder te definiëren aan de hand van experimenten en andere onderzoeken. Er zijn vervolgens verschillende deelvragen opgesteld;

> **1. Wat voor robotarm zal er gebouwd worden?**

> **2. Welke functionaliteiten verwacht de doelgroep?**

> **3. Wat is te duur en wat niet?**

> **4. Wat voor apparatuur kun je verwachten bij een gemiddelde hobbyist?**

> **5. Wat definieert een goede prestatie?**

De eerste deelvraag is beantwoord aan de hand van een literatuuronderzoek. Het type robot dat tijdens dit project gebouwd zou worden was een *SCARA robot*. Dit type robot zou beide de gewenste uitdaging op gebied van ontwerp en software met zich meebrengen. Het type voldeed aan de bewegingssnelheids-eis en scoorde sterk op de persoonlijke interesse schaal.

Vervolgens is er gekeken naar de verschillende functionaliteiten die noodzakelijk zijn voor de robot zodat de doelgroep eerder geneigd is om zelf een ROBOX te bouwen. De verschillende functionaliteiten zijn onderverdeeld in drie documenten, het [MDD](bijlage/04_design_documents/03_mdd_hardware.pdf) (bijlage 18 - mdd_hardware.pdf), [SRS (firmware)](bijlage/04_design_documents/01_srs_firmware.pdf) (bijlage 16 - srs_firmware.pdf) & [SRS (software)](bijlage/04_design_documents/02_srs_software.pdf) (bijlage 17 - srs_software.pdf). Deze functionaliteiten zijn het antwoord op de tweede deelvraag.

De derde deelvraag is puur gebaseerd op de persoonlijke instelling van de doelgroep. De totale prijs van ROBOX is terug te vinden in de bill of materials ([BOM](bijlage/04_design_documents/06_bill_of_materials.pdf) (bijlage 21 - bill_of_materials.pdf)) en komt neer op een bedrag van € 553,42 euro. Dit is erg veel geld voor een hobby project.

Gezien ikzelf val binnen de doelgroep zal deze deelvraag beantwoord worden op basis van persoonlijke mening; Als ik op zoek ben naar een robot arm project zou ik persoonlijk zeggen dat meer dan 500 euro onacceptabel is, tenzij het product voorzien is van alle gebruiksgemakken zoals bijvoorbeeld: Een handleiding, actief onderhouden firm- en software en een actieve gemeenschap om het product heen zodat troubleshooten van het product mogelijk is.

Voor de vierde deelvraag is uitgegaan van enkel een 3D-printer. Studenten, zoals ikzelf, wonen misschien op kamers. Hier is weinig ruimte voor apparatuur. Tijdens de ontwikkeling van ROBOX is er exclusief gebruik gemaakt van 'off-the-shelf'-onderdelen (met de uitzondering van de 3D geprinte onderdelen) zodat een eindgebruiker naast een 3D-printer en wat schroevendraaiers niks nodig heeft om het project te voltooien. 

Het beantwoorden van de vijfde deelvraag is gedaan in het [tweede experiment](bijlage/03_experiment_02/experiment_02.pdf) (bijlage 03 - experiment_02). In dit experiment wordt er gekeken naar de repeatability (herhaalbaarheid) van de robot in de staat van toen. Het resultaat van dat experiment was een repeatability van < 0.1 millimeter. Het huidige eindproduct is op een soortgelijke manier getest (zie bijlage X - clips/repeatability/*.) en de resultaten zijn vervolgens verwerkt in het document: [Resultaten](bijlage/06_repeatability.pdf) (bijlage 06- repeatability.pdf). De uiteindelijke repeatability van ROBOX voldoet aan de gestelde eisen in het tweede experiment (0.079 mm).

Nu alle deelvragen beantwoord zijn kan de hoofdvraag beantwoord worden, dit antwoord is gegeven in de vorm van dit document, het ontwerp proces. In dit document worden in detail beschreven hoe een dergelijke robot ontwikkeld kan worden. 

## Verbeterpunten

Het uiteindelijke resultaat bevat op verschillende aspecten nog verbeterpunten, deze punten zijn in dit onderdeel vermeld.

- Het model bevat een verticale 'wiebel' deze is afkomstig uit de segmentverbinding tussen de schouder en de elleboog. Deze wiebel is ontstaan door het niet helemaal kunnen vastmaken van de bouten (Hoofdstuk *De verwezenlijking*).
- De controller is momenteel een handmatig gesoldeerd printplaatje, dit kan in toekomstige iteraties vervangen worden door een 'purpose-build'-PCB. Dit zal het toegankelijker maken voor eindgebruikers en zal schelen in ruimte.
- De printplaat voor de gripper is momenteel verwerkt in de hoofdcontroller zelf. Het is de bedoeling dat de gripper uitgewisseld kan worden zonder de robot uit elkaar te halen. In toekomstige iteraties moet de printplaat voor de gripper dan ook losgekoppeld worden van de controller.
- De maximale snelheden vermeld in het hoofdstuk *Resultaten* is gebaseerd op de maximale snelheid wanneer een enkele motor tegelijk beweegt. Wanneer meerdere motoren tegelijkertijd bewegen zijn deze snelheden niet meer haalbaar (de firmware slaat stappen over). Dit is het resultaat van een library die geschreven is voor relatief trage microcontrollers (Arduino 16 MHz). ROBOX maakt gebruik van een Teensy 4.0 met een snelheid van 600 MHz. Door gebruik te maken van een meer geoptimaliseerde library bijvoorbeeld [TeensyStep](https://github.com/luni64/TeensyStep) kan er waarschijnlijk een hogere algemene snelheid bereikt worden.
- In de software zijn een aantal elementen geschrapt in verband met de beschikbare tijd (Hoofdstuk *De software* & bijlage X - srs_software.pdf). Onderdelen als het sequence paneel en bijvoorbeeld Keyboard control. Deze onderdelen kunnen in een latere iteratie uitgewerkt worden, hierdoor zal de functionaliteit van de GUI sterk verhoogd worden.

!url Berkel, L. (z.d.). GRAND LITTLE PIANO. Grand Litte Piano. Geraadpleegd op 1 juni 2022, van [https://lottevanberkel10.wixsite.com/website-3/kopie-van-pre-master-tueCartesian](https://lottevanberkel10.wixsite.com/website-3/kopie-van-pre-master-tueCartesian)

!url Robots: Guide to The Most Scalable Robot Technology. (z.d.). #HowToRobot. Geraadpleegd op 3 juni 2022, van [https://www.howtorobot.com/expert-insight/cartesian-robots](https://www.howtorobot.com/expert-insight/cartesian-robots)

!url CUI. (z.d.). AMT10 Series Modular Incremental Rotary Encoders. CUI Devices. Geraadpleegd op 3 juni 2022, van [https://www.cuidevices.com/product/motion/rotary-encoders/incremental/modular/amt10-series](https://www.cuidevices.com/product/motion/rotary-encoders/incremental/modular/amt10-series)

!url Fairchild, M. (2021, 31 augustus). Types of Industrial Robots and Their Different Uses. HowToRobot. Geraadpleegd op 1 juni 2022, van [https://www.howtorobot.com/expert-insight/industrial-robot-types-and-their-different-uses](https://www.howtorobot.com/expert-insight/industrial-robot-types-and-their-different-uses)

!url ICA. (z.d.-a). Available product analysis - ICT research methods. ICA Research Methods. Geraadpleegd op 1 juni 2022, van [https://ictresearchmethods.nl/Available_product_analysis](https://ictresearchmethods.nl/Available_product_analysis)

!url ICA. (z.d.-b). Community research - ICT research methods. ICA Research Methods. Geraadpleegd op 2 juni 2022, van [https://ictresearchmethods.nl/Community_research](https://ictresearchmethods.nl/Community_research)

!url ICA. (z.d.-c). Component test - ICT research methods. ICA Research Methods. Geraadpleegd op 2 juni 2022, van [https://ictresearchmethods.nl/Component_test](https://ictresearchmethods.nl/Component_test)

!url ICA. (z.d.-d). Literature study - ICT research methods. ICA Research Methods. Geraadpleegd op 1 juni 2022, van [https://ictresearchmethods.nl/Literature_study](https://ictresearchmethods.nl/Literature_study)

!url ICA. (z.d.-e). Model validation (ML) - ICT research methods. ICA Research Methods. Geraadpleegd op 1 juni 2022, van [https://ictresearchmethods.nl/Model_validation_(ML)](https://ictresearchmethods.nl/Model_validation_(ML))

!url ICA. (z.d.-f). Multi-criteria decision making - ICT research methods. ICA Research Methods. Geraadpleegd op 1 juni 2022, van [https://ictresearchmethods.nl/Multi-criteria_decision_making](https://ictresearchmethods.nl/Multi-criteria_decision_making)

!url ICA. (z.d.-g). Requirements prioritization - ICT research methods. ICA Reasearch Methods. Geraadpleegd op 1 juni 2022, van [https://ictresearchmethods.nl/Requirements_prioritization](https://ictresearchmethods.nl/Requirements_prioritization)

!url Wikipedia contributors. (2022, 17 februari). Faraday cage. Wikipedia. Geraadpleegd op 1 juni 2022, van [https://en.wikipedia.org/wiki/Faraday_cage](https://en.wikipedia.org/wiki/Faraday_cage)
