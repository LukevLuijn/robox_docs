
<style>
p.must           {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.should         {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.could          {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.wont           {margin-left:auto; margin-right:auto; text-align:center; width:60px;} 
p.must           {border:3px; border-style:solid; border-color:#00FF00; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
p.should         {border:3px; border-style:solid; border-color:#FFA500; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
p.could          {border:3px; border-style:solid; border-color:#0000FF; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
p.wont           {border:3px; border-style:solid; border-color:#DDDDDD; border-radius:10px; background-color:#000000; font-weight:bold; color:#FFFFFF;}
</style>


In dit hoofdstuk zullen de verschillende requirements voor het model beschreven worden. De argumenten zijn afkomstig uit gesprekken met de product owner. In het onderdeel 'Requirements' zullen de verschillende requirements gesorteerd volgens de *MoSCoW*-methode weergegeven worden, per requirement staat tevens weergegeven of deze behaald is in het uiteindelijke product. In het onderdeel 'Argumentatie' worden deze requirements onderbouwd.

## Requirements

|Index|Prioriteit|Requirement|Voldaan|
|:---:|:---:|:---:|:---:|
|**FR-00**|<p class=must>Must</p>|Het model moet 3D geprint worden met uitzondering van bouten, moeren, lagers en frame onderdelen.|:heavy_check_mark:|
|**FR-01**|<p class=must>Must</p>|Het model moet een lineaire as hebben.|:heavy_check_mark:|
|**FR-02**|<p class=must>Must</p>|Het model moet minimaal drie axiale assen hebben.|:heavy_check_mark:|
|**FR-03**|<p class=must>Must</p>|Het model moet zo ontworpen worden dat de verschillende segmenten niet met elkaar kunnen botsen.|:heavy_check_mark:|
|**FR-04**|<p class=must>Must</p>|Het model moet gebruik maken van holle assen voor de bekabeling.|:heavy_check_mark:|
|**FR-05**|<p class=must>Must</p>|Het model moet gebruik maken van stappen motoren.|:heavy_check_mark:|
|**FR-06**|<p class=must>Must</p>|Het model mag geen externe onderdelen bevatten voor bijvoorbeeld electronica.|:heavy_check_mark:|
|**FR-07**|<p class=must>Must</p>|Het model moet voor axiale actuatoren gebruik maken van tandriem reductie.|:heavy_check_mark:|
|**FR-08**|<p class=must>Must</p>|Het model moet per reductie systeem voorzien zijn van instelbare *tensioners*.|:heavy_check_mark:|
|**FR-09**|<p class=must>Must</p>|Het model moet gebruik maken van bouten en moeren die off-the-shelf beschikbaar zijn.|:heavy_check_mark:|
|**FR-10**|<p class=must>Must</p>|Het model moet gebruik maken van onderdelen die off-the-shelf beschikbaar zijn.|:heavy_check_mark:|
|**FR-11**|<p class=must>Must</p>|Het model moet met maximaal twee verschillende kleuren PLA te printen zijn.|:heavy_multiplication_x:|
|**FR-12**|<p class=must>Must</p>|Het model moet passen op een print oppervlak van 210x210x250 (Ender 3).|:heavy_multiplication_x:|
|**FR-13**|<p class=must>Must</p>|Het model moet minder dan 400 watt aan stroom gebruiken.|:heavy_check_mark:|
|**FR-14**|<p class=must>Must</p>|Het model moet alle motoren buiten het model verwerken zodat deze toegang hebben tot 'firsse lucht'.|:heavy_check_mark:|
|**FR-15**|<p class=must>Must</p>|Het model moet alle motoren altijd monteren op een medium dat geen geprint PLA plastic is.|:heavy_check_mark:|
|**FR-16**|<p class=must>Must</p>|De hoofdcontroller van het model moet bestaan uit componenten die handmatig te solderen zijn, geen *SMD* componenten.|:heavy_check_mark:|
|**FR-17**|<p class=must>Must</p>|De lineaire as van het model moet een snelheid kunnen weerstaan van minimaal 50 millimeter per seconden.|:heavy_check_mark:|
|**FR-18**|<p class=must>Must</p>|De axiale assen van het model moeten een snelheid kunnen weerstaan van minimaal 90 graden per seconden.|:heavy_check_mark:|
|**FR-19**|<p class=should>Should</p>|Het model moet het mogelijk maken dat de laatste twee assen onder de eerste axiale as door kunnen.|:heavy_check_mark:|
|**FR-20**|<p class=should>Should</p>|Het model moet het gebruik van externe bekabeling minimaliseren.|:heavy_check_mark:|
|**FR-21**|<p class=should>Should</p>|Het model moet voor axiale actuatoren een reductie implementeren in plaats van directe aansturing.|:heavy_check_mark:|
|**FR-22**|<p class=should>Should</p>|Het model moet voor de lineaire as gebruik maken van een *leadscrew* reductie.|:heavy_check_mark:|
|**FR-23**|<p class=should>Should</p>|Het model moet alle componenten waar stroom op staat verbergen voor de eindgebruiker.|:heavy_multiplication_x:|
|**FR-24**|<p class=should>Should</p>|Het model moet ondersteuning bieden voor encoders op de motoren.|:heavy_multiplication_x:|
|**FR-25**|<p class=should>Should</p>|Het model moet per actuator een losse controller hebben.|:heavy_multiplication_x:|
|**FR-26**|<p class=should>Should</p>|Het model moet elke controller voorzien van een *CAN-interface* waardoor enkel twee stroom en twee can-bus kabels per segment nodig zijn.|:heavy_multiplication_x:|
|**FR-27**|<p class=should>Should</p>|Het model moet een reikwijdte van 500 millimeter hebben.|:heavy_multiplication_x:|
|**FR-28**|<p class=should>Should</p>|Het model moet een verticale bewegingsruimte hebben van 500 millimeter.|:heavy_multiplication_x:|
|**FR-29**|<p class=should>Should</p>|Het model zal nooit een reductie toepassen van meer dan tien. |:heavy_check_mark:|
|**FR-30**|<p class=should>Should</p>|Het model moet zo ontworpen zijn dat het de warmte van motoren (60 graden) voor 30 minuten kan weerstaan.|:heavy_check_mark:|
|**FR-31**|<p class=could>Could</p>|Het model moet het gewicht in latere segmenten minimaliseren.|:heavy_check_mark:|
|**FR-32**|<p class=could>Could</p>|Het model moet een zo laag mogelijk zwaarte punt realiseren.|:heavy_check_mark:|
|**FR-33**|<p class=could>Could</p>|Het model moet waar mogelijk gebruik maken van *GX-style* connectors voor het verbinden van bekabeling.|:heavy_check_mark:|
|**FR-34**|<p class=could>Could</p>|Het model moet alle tandriemen binnen het model verwerken.|:heavy_multiplication_x:|

**!tabel** - *Requirements*

## Argumentatie

|Requirement|Argument(en)|
|:---:|:---|
|**FR-00**|Door alle onderdelen 3D te printen blijven de kosten laag en is het model toegankelijker voor gebruikers.|
|**FR-01**|Gezien de robot ontwikkeld zal worden als een *SCARA* variant moet er een lineaire as verwerkt worden in het model voor de Z-as.|
|**FR-02**|Het doel van ROBOX is om een vier dimensionale (*4-DOF*) robot te maken. Er moet een lineaire in zitten, dus minimaal drie axiale assen.|
|**FR-03**|Als de verschillende segmenten fysiek niet in contact kunnen komen met elkaar maakt dat de software ontwikkeling vele malen makkelijker.|
|**FR-04**|Als het model meer assen bevat die meer dan 360 graden kunnen draaien zijn holle assen noodzakelijk omdat de bekabeling anders in de weg zit.|
|**FR-05**|Tijdens de experimenten is er gekozen voor het gebruik van stappen motoren, de beredenering is daar terug te vinden (zie [Experiment 01](https://github.com/LukevLuijn/robox_docs/blob/06efc12c7d1f006f6b29dcf17404ff0cd0511f50/experiment/experiment_01/experiment_01.pdf)).|
|**FR-06**|ROBOX moet een strakke module zijn die astatisch er mooi uit ziet. Een extra externe doos voor de electronica valt niet binnen dit plaatje.|
|**FR-07**|Reductie systemen gemaakt van tandwielen zijn op drie punten minder geschikt dan tandriem reductie: De tandwielen kunnen door de gebrekkige tolerantie van een 3D printer voor veel *backlash* zorgen. 3D geprinte tandwielen zijn imperfect, deze imperfectie zorgt voor veel slijtage wanneer twee imperfectie tandwielen langs elkaar heen wrijven. Doordat het twee plastic componenten zijn die tegen elkaar wrijven ontstaat er veel warmte, plastic en warmte gaan niet goed samen en kunnen zorgen voor verzachting van het materiaal. Tandriem reductie heeft deze gebreken niet.|
|**FR-08**|Tandriemen kunnen over een langere periode 'uitrekken' waardoor ze hun tensie verliezen, door van buiten af bereikbare tensioners te gebruiken kan deze slack verholpen worden.|
|**FR-09/10**|ROBOX moet beschikbaar zijn voor iedereen die er interesse in heeft. Als er onderdelen gebruikt worden die iemand zelf of door een bedrijf moet laten maken verhoogd dat de drempel waarde om een ROBOX te maken.|
|**FR-11**|Door het kleur gebruik te maximaliseren op twee scheelt dat in de PLA kosten die een gebruiker hoeft te maken.|
|**FR-12**|Door alle onderdelen printbaar te maken op de een van de meest populaire budget printers (Cass, 2022) verzeker je het project van een grotere compatibiliteit.|
|**FR-13**|Power supplies tot en met 400 watt zijn meestal zonder active koeling te koop. Een luide ventilator is niet gewenst.|
|**FR-14**|Stepper motoren kunnen en worden vrij warm tijdens gebruik, Hiervoor zijn ze ontwikkeld. Door alle motoren buiten het plastic frame te plaatsen wordt er voor gezorgd dat ze ook weer snel afkoelen.|
|**FR-15**|Zoals verteld worden stepper motoren vrij warm. tijdens gebruik kunnen ze makkelijk boven de 60 graden komen. PLA plastic heeft een softening temperature van ongeveer 50 graden (Rogers, z.d.) en zal dan ook zijn vorm verliezen. Door een medium van bijvoorbeeld staal of aluminium te gebruiken kan veel warmte opgevangen worden.|
|**FR-16**|Omdat de controller handmatig in elkaar gezet moet worden voor iedere gebruiker van ROBOX is het niet handig als er allerlei miniscule SMD componenten verwerkt zijn op de *PCB*.|
|**FR-17**|Bij een vertical bewegingsruimte van 500 millimeter zou een snelheid van 50 millimeter per seconden betekenen dat de gehele robot binnen twintig seconden op en neer kan.|
|**FR-18**|Bij een horizontale bewegingshoek van 180 graden zou een snelheid van 90 graden per seconden betekenen dat dat segment binnen vier seconden heen en weer kan.|
|**FR-19**|Dit is een extensie op FR-03, door de segmenten onder elkaar door te laten gaan geeft dit meer mogelijkheden in de software.|
|**FR-20**|Externe bekabeling is niet altijd even mooi en ziet er niet professioneel uit. Door de bekabeling te verwerken in de arm zelf kan dit verholpen worden.|
|**FR-21**|Directe aansturing van de assen zou kunnen als de motoren genoeg torque zouden hebben, echter voor een robot als deze zou dit betekenen dat er grotere motoren gebruikt moeten worden. Grotere motoren betekend meer gewicht en meer gewicht betekend meer *sag*|
|**FR-22**|Gezien er erg veel gewicht aan de verticale as hangt is het gebruik van een randriem transmissie niet mogelijk. Zoals vermeld rekken randriemen uit over tijd op de verticale as zou dit voor grote problemen kunnen zorgen. Tandriemen hebben ook een veer effect dat versterkt wordt hoe langer de tandriem is bij vertical beweging kan dit voor een wiebelende robot zorgen. Het gebruik van een leadscrew heeft deze problemen niet.|
|**FR-23**|Een eindgebruiker mag geen mogelijkheid hebben om met zijn of haar vingers aan connecties zoals netstroom te zitten.|
|**FR-24**|Het gebruik van encoders levert veel mogelijkheden in de software. Door middel van een encoder kan de arm bijvoorbeeld handmatig getraind worden en kan de software voorzien worden van fout detectie.|
|**FR-25**|Door elk segment te voorzien van een eigen (slave) controller kan de bekabeling door de robot heen sterk verminderd worden. Verder levert het de mogelijkheid om meer functionaliteiten per segment te implementeren. Er zou bijvoorbeeld een temperatuur sensor geïmplementeerd kunnen worden.|
|**FR-26**|CAN is ontwikkeld voor de auto industrie en is bestand tegen veel *noise*, ideaal voor de robot. |
|**FR-27**|De robot moet een degelijke omvang hebben maar niet te groot worden.|
|**FR-28**|De robot moet een degelijke omvang hebben maar niet te groot worden.|
|**FR-29**|Een hoge reductie kan zorgen voor meer weerstand in de actuatoren. Een quasi-direct drive (minder dan tien) levert de mogelijkheid tot het *backdriven* van de robot.|
|**FR-30**|Dit is een minimale eis.|
|**FR-31**|Door het gewicht verder in de robot te minimaliseren blijft de structuur sterk en is het mogelijk om snellere bewegingen te maken.|
|**FR-32**|ROBOX is van zichzelf een vrij instabiel ontwerp. Door zware componenten laag in het systeem te verwerken kan deze stabiliteit gemaximaliseerd worden.|
|**FR-33**|GX-style connectors zien er mooi en professioneel uit.|
|**FR-34**|Tandriemen kunnen dingen als haren of vingers grijpen, de robot heeft hier geen idee van en zal dan ook gewoon lekker door draaien. Door de tandriemen binnen het model te verwerken wordt dit scenario geminimaliseerd|

**!tabel** - *Argumentatie*


!url Cass, J. (2022, 25 mei). Best Budget 3D Printers for Creatives in 2022. JUSTTM Creative. Geraadpleegd op 31 mei 2022, van [https://justcreative.com/best-budget-3d-printers/](https://justcreative.com/best-budget-3d-printers/)
!url Rogers, T. (z.d.). Everything You Need To Know About Polylactic Acid (PLA). PLA. Geraadpleegd op 31 mei 2022, van [https://www.creativemechanisms.com/blog/learn-about-polylactic-acid-pla-prototypes](https://www.creativemechanisms.com/blog/learn-about-polylactic-acid-pla-prototypes)