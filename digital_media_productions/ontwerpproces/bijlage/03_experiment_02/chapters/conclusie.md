
Om dit experiment kort samen te vatten. Eerst is er gekeken naar welke onderdelen van de configureerbare aspecten van de robot betrekking zouden kunnen hebben tot de uiteindelijke repeatability van de robot. Uit deze deelvraag werd duidelijk dat de snelheid, afgelegde afstand, microstepping configuratie en hoeveel segmenten tegelijkertijd bewegen van belang zijn. Vervolgens is er gekeken hoe deze aspecten betrouwbaar getest kunnen worden. Er zijn verschillende snelheden en microstepping resoluties gekozen op basis van de configuraties, die uiteindelijk in de robot gebruikt zullen worden. Verder zijn er meerdere test posities opgesteld die beide de afstand en het aantal segmenten test. Dit alles is gecombineerd in een test sequence en vervolgens via de meetopstelling getest.

Er zijn enkele opmerkelijke resultaten verkregen, zoals bijvoorbeeld de 'resonance' bij een microstepping resolutie van 400. Ook het feit dat wanneer beide segmenten worden gecombineerd de afwijking omlaag gaat. Naast de opmerkelijke situaties zijn de resultaten nagenoeg verlopen volgens verwachting en kan de hoofdvraag beantwoord worden.

Het antwoord op de hoofdvraag; *'Wat is de repeatability van de robot in zijn huidige staat?'*, is afhankelijk van de uiteindelijke microstepping resolutie. Gezien het probleem met de 'resonance' valt een microstepping resolutie van 400 af. Voor de resoluties 800,1600 en 3200 zijn de uiteindelijke repeatability statistieken in de onderstaande tabel weergegeven:

|Resolutie|Maximale afwijking|Minimale afwijking|Verschil|Repeatability|
|:---|:---:|:---:|:---:|:---:|
|MS800 |-37 μm|38 μm|75 μm|**0.075 mm**|
|MS1600|-18 μm|61 μm|79 μm|**0.079 mm**|
|MS3200|-44 μm|41 μm|85 μm|**0.085 mm**|

**!tabel** - *Resultaten - **repeatability***

Zoals in de tabel te zien is de uiteindelijke repeatability voor alle drie de microstepping resoluties **< 0.1 mm** dit is een uitstekende prestatie, maar niet geheel representatief. De uiteindelijke arm krijgt nog een extra draaiend onderdeel die natuurlijk extra spelling met zich meebrengt.