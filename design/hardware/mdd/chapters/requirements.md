
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

|Index|Prioriteit|Requirement|Voldaan|
|:---:|:---:|:---:|:---:|
|**FR-00**|<p class=must>Must</p>|Het model moet 3D geprint worden met uitzondering van bouten, moeren, lagers en frame onderdelen.|:heavy_check_mark:|
|**FR-01**|<p class=must>Must</p>|Het model moet een lineaire as hebben.|:heavy_check_mark:|
|**FR-02**|<p class=must>Must</p>|Het model moet minimaal drie axiale assen hebben.|:heavy_check_mark:|
|**FR-03**|<p class=must>Must</p>|Het model moet zo ontworpen worden dat de verschillende assen niet met elkaar kunnen botsen.|:heavy_check_mark:|
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
|**FR-17**|<p class=must>Must</p>|De lineaire as van het model moet een snelheid kunnen weerstaan van minimaal 100 millimeter per seconden.|:heavy_check_mark:|
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



