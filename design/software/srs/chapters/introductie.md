
Dit is het software requirements specification document voor het UI-onderdeel van het ROBOX project. De *applicatie* zal draaien op de computer van de gebruiker. De applicatie is fungeert als een vertaalslag tussen wat de gebruiker van de *robot* wil en wat de robot begrijpt, kortom een *user interface*. Deze applicatie zal de verschillende functionaliteiten van de *firmware* applicatie implementeren en op een overzichtelijke manier weergegeven aan de gebruiker. De applicatie zal verder nog mogelijkheden bieden om te verschillende manieren van besturing te gebruiken, denk bijvoorbeeld aan een bluetooth controller of met de pijltjes toetsen op een toetsenbord. Ook de configuratie van de firmware zal aanpasbaar worden gemaakt in deze applicatie.

## Gebruikers, klasse en karakteristieken

Deze applicatie zal ontwikkeld worden voor een enkele actor, de gebruiker. Een gebruiker is iemand die deze software heeft geïnstalleerd en beschikt over een (soortgelijke) robot.

## Ontwikkelomgeving

De applicatie zal ontwikkeld worden voor Windows 10, MacOS 12 (Monterey) & Ubuntu Focal Fossa (20.04). De applicatie zal enkel getest worden voor Ubuntu Focal Fossa 20.04. Verdere systeem eisen zijn niet van toepassing.

## Ontwerp en implementatie beperkingen

De gehele applicatie zal geschreven worden in C++. Er zal geen gebruik gemaakt worden van externe library's met uitzondering van [Boost](https://www.boost.org/), voor de communicatie met de robot, en [wxWidgets](https://www.wxwidgets.org/), voor het weergeven van de *GUI*.


!url Boost. (z.d.). Boost C++ Libraries. Geraadpleegd op 28 mei 2022, van [https://www.boost.org/](https://www.boost.org/)
!url wxWidgets. (2022, 4 april). wxWidgets: Cross-Platform GUI Library. Geraadpleegd op 28 mei 2022, van [https://www.wxwidgets.org/](https://www.wxwidgets.org/)