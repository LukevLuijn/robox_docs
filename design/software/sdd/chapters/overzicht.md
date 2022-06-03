
De applicatie is onderverdeeld in verschillende *packages*, ook wel *namespaces*. De verschillende klassen zijn onderverdeeld in deze namespaces op basis van de functionaliteit die ze vertonen. De Driver namespace is bijvoorbeeld verantwoordelijk voor de communicatie met de *robot* zelf.

|                                                                        |
| :--------------------------------------------------------------------: |
| <img width="10000" src="assets/DCD_software.svg"  alt="dcd_firmware"/> |
|      **!diagram** - *Design class diagram - Software applicatie*       |

De softwareapplicatie is geschreven zodat het makkelijk uitgebreid kan worden met nieuwe functionaliteit. De GUI is opgezet zodat het uitgebreid kan worden met nieuwe *Control methods*. Momenteel bevat de applicatie een enkele control method; **ManualCtlr**, hierover meer in het hoofdstuk 'Package  - Frame'. In toekomstige iteraties kan dit bijvoorbeeld uitgebreid worden met een KeyboardCtrl of een BLTCtrl klasse.

De applicatie is ook ingericht om te communiceren met meerdere microcontrollers tegelijkertijd. Het zou bijvoorbeeld goed kunnen dat de robot gebruikt zal worden in combinatie met andere apparaten. Dit zou dus allemaal in deze applicatie verwerkt kunnen worden.