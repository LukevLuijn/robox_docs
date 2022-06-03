## Package - Communication

|                                                                                |
| :----------------------------------------------------------------------------: |
| <img width="10000" src="assets/CD_communication.svg"  alt="cd_communication"/> |
|          **!diagram** - *Class diagram - Communication package*           |

De package [**Communication**](https://github.com/LukevLuijn/robox/tree/main/robox_firmware_v0.1/include/communication) is verandtwoordelijk voor de communicatie met het *overkoepelende systeem*. Het regelt beide het schrijven en lezen over de *seriële bus*. De communicatie is gebaseerd op de klasse [**Message**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/communication/Message.h#L83), deze klasse is in essentie een buffer voor een inkomend bericht. Een message bestaat uit een [**Header**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/communication/Message.h#L18) en een [**Body**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/communication/Message.h#L48). De Header bevat het type bericht en de variant van dit type (zie [message protocol](linkje)). De body bevat eventuele parameters die het bericht bevat. De klasse [**DataManager**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/communication/DataMenagement.h) is verantwoordelijk voor het correct *parsen* en opstellen van de berichten. Deze functionaliteit is gebaseerd op het *message protocol*.

De klasse [**Reader**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/communication/Reader.h) is de klasse die daadwerkelijk de inkomende berichten leest. Omdat de seriële bus maar op een enkele locatie tegelijk aangesproken kan worden is er bij deze klasse gebruik gemaakt van een *singleton pattern*. Deze klasse kijkt continue naar de seriële bus, als er een bericht beschikbaar is zal deze gecontroleerd worden op basis van het *message protocol* en, indien goedgekeurd, gesorteerd worden in de messageQueue. Tijdens het sorteren zal er gekeken worden naar de header van de message. Als blijkt dat de header van de message een datatype is (DataType_e) zal dit bericht direct afgehandeld worden door een response te creëren. Als het een E-Stop bericht te zijn zullen de motoren direct gedeactiveerd worden en wordt de gehele messageQueue geleegd zodat de robot stopt met bewegen en ook niet meer verder gaat. Als dit beide niet het geval is zal het bericht aan de messageQueue worden toegevoegd. Wanneer de state machine gereed is om een beweging te maken zal de messageQueue worden afgehandeld.

<div style="page-break-after: always;"></div>


### Ontwerp keuzes

|||
|:---|:---|
|**Probleem**|De seriële bus mag maar door een instantie tegelijk aangesproken worden.|
|**Besluit**|Er is voor een singleton pattern gekozen.|
|**Alternatieve**|Handmatig bijhouden welke instantie wanneer de serieele bus aanspreekt.|
|**Argumenten**|Een singleton klasse heeft als eigenschap dat er altijd precies 1 instantie, dezelfde, actief is in de applicatie.|

**!tabel** - *Communication - ontwerp keuze 1*

|||
|:---|:---|
|**Probleem**|Hoe verzeker je dat de applicatie alle inkomende berichten altijd op dezelfde manier verwerkt (*parsed*)?|
|**Besluit**|Het opstellen van een **Message** klasse. De klasse kan maar op een manier aangemaakt worden en is dus naast de inhoud altijd hetzelfde.|
|**Alternatieve**|Het individueel parsen van de inkomende berichten waar nodig.|
|**Argumenten**|Door een **Message** te maken is er een gestandaardiseerde methode om berichten te maken en uit te lezen. Dit maakt het voor de huidige en toekomstige klasse makkelijk om om te gaan met de seriële communicatie.|

**!tabel** - *Communication - ontwerp keuze 2*

|||
|:---|:---|
|**Probleem**|Hoe zorg je dat de berichten verstuurd tussen de applicaties altijd op dezelfde manier opgesteld zijn?|
|**Besluit**|Het opstellen van een bestand message protocol ([**msg_protocol.h**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/config/msg_protocol.h)), en dit bestand vervolgens voor beide applicaties gebruiken.|
|**Alternatieve**|Erg goed opletten dat de berichten altijd volgens hetzelfde patroon verlopen.|
|**Argumenten**|Door een protocol op te stellen is het makkelijker om een correct geformuleerd bericht op te zetten. Het uitlezen van berichten is hierdoor ook veel minder *'error-prone'*.|

**!tabel** - *Communication - ontwerp keuze 3*

<div style="page-break-after: always;"></div>


## Package - State machine

|                                                                                |
| :----------------------------------------------------------------------------: |
| <img width="10000" src="assets/CD_statemachine.svg"  alt="cd_statemachine"/> |
|          **!diagram** - *Class diagram - State machine package*           |

De package [**State Machine**](https://github.com/LukevLuijn/robox/tree/main/robox_firmware_v0.1/include/state_machine) is verantwoordelijk voor de opzet en uitwerking van de statemachine. Deze package is een uitwerking van de *state pattern*. Door gebruik te maken van een state machine is het makkelijk om op basis van een bepaalde input (een serieel bericht) een bepaalde functionaliteit uit te voeren.

De klasse [**State**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/state_machine/State.h) is een abstracte uitwerking van een state. Het is de bedoeling dat deze in de daadwerkelijke applicatie uitgewerkt wordt (zie Package - Base). De klasse [**Event**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/state_machine/Event.h) fungeert als een trigger. Aan de hand van deze klasse kunnen verschillende transities getriggerd worden binnen de state machine. Tot slot de klasse [**Context**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/state_machine/Context.h). De Context klasse regelt de samenhang tussen state en event. Deze klasse bevat een lijst met events die een voor een afgehandeld worden. Ook heeft deze klasse een instantie van de huidige state. Context is ook verantwoordelijk voor het uitvoeren van de transities tussen states.

### Ontwerp keuzes

|||
|:---|:---|
|**Probleem**|Hoe voer je verschillende functionaliteiten uit op basis van input?|
|**Besluit**|Het opstellen van een state machine, volgens het state pattern.|
|**Alternatieve**|Een omvangrijke 'if else'-boom, switch case.|
|**Argumenten**|Een state machine is een elegante oplossing voor het probleem. Het levert de mogelijkheid om op een overzichtelijke manier de verschillende situaties (states) af te handelen.|

**!tabel** - *State machine - ontwerp keuze 1*

<div style="page-break-after: always;"></div>

## Package - Device 

|                                                                                |
| :----------------------------------------------------------------------------: |
| <img width="10000" src="assets/CD_device.svg"  alt="cd_device"/> |
|          **!diagram** - *Class diagram - Device package*           |

De package [**Device**](https://github.com/LukevLuijn/robox/tree/main/robox_firmware_v0.1/include/device) heeft als verantwoordelijkheid het direct aanspreken van de verschillende hardware componenten. De klasse [**Actuator**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/device/Actuator.h) is de overkoepelende actuator klasse die de algemene zaken regelt die voor beide onderliggende actuator classen hetzelfde zijn. [**Linear**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/device/LinearActuator.h) & [**AxialActuator**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/device/AxialActuator.h) zijn de daadwerkelijke actuators. De applicatie heeft drie axiale actuators en een lineaire actuator. De axiale actuator regelt beweging in graden en de lineaire actuator regelt beweging in millimeters. Beide deze uitwerkingen maken gebruik van een [**HallSensor**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/device/HallSensor.h) instantie voor *homing*. De enumeraties [**HomingState_e**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/device/LinearActuator.h#L19), [**HomingStateSingle_e**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/device/AxialActuator.h#L21) & [**HomingStateDouble_e**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/device/AxialActuator.h#L31) worden gebruikt voor de homing sequence van de actuatoren. 

### Ontwerp keuzes

|||
|:---|:---|
|**Probleem**|Hoe kun je een homing sequence uitvoeren voor vier verschillende motoren zonder dat deze sequence het resterende programma *blokkeert*?|
|**Besluit**|Het gebruik van verschillende enumeraties die de verschillende stadia van de sequence weergegeven zodat het voor de applicatie duidelijk is welke actie ondernomen moet worden.|
|**Alternatieve**|Een homing sequence gebruiken die wel blokkeert.|
|**Argumenten**|Gezien de lineaire actuator vrij traag is en de axiale actuatoren ook niet bijster snel ontstond er een homing sequence van ongeveer twee minuten, in blokkerende toestand. Het was dus noodzakelijk om een niet-blokkerende homing sequence op te zetten zodat in ieder geval alle actuator tegelijkertijd de sequence konden uitvoeren.|

**!tabel** - *Device - ontwerp keuze 1*


## Package - Utils

|                                                                                |
| :----------------------------------------------------------------------------: |
| <img width="10000" src="assets/CD_utils.svg"  alt="cd_utils"/> |
|          **!diagram** - *Class diagram - Utils*           |


De [**Utils**](https://github.com/LukevLuijn/robox/tree/main/robox_firmware_v0.1/include/utils) package is een verzameling van verschillende klasse die ieder een eigen functionaliteit bevatten. De klasse Time bestaat uit een enkele methode *MicroTimer*. De klasse [**CircularBuffer**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/utils/CircularBuffer.h) is een C++ implementatie van de [circulaire buffer](https://en.wikipedia.org/wiki/Circular_buffer) (Wikipedia contributors, 2022a) bedoelt voor het efficiënt opslaan en uitlezen van sensor waarde. 

De [**Logger**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/utils/Logger.h) klasse heeft iets meer substantie dan de andere twee. De logger wordt door vrijwel de gehele applicatie gebruikt. De logger geeft de mogelijkheid om berichten naar de console te schrijven in een voorbepaald format. De Logger is de enige klasse die naar de seriële bus mag schrijven en is daarom, net zoals de reader, een singleton. Dit maakt het en makkelijk om vanaf meerdere locaties in de applicatie gebruik te maken van de logger en zorgt ervoor dat er nooit van meerdere locaties naar de seriële bus geschreven wordt. De logger houdt ook de *severity* van een bericht bij. Er zijn vier verschillende severities; ERROR, WARNING, INFO en DEBUG. Ieder van deze niveaus kan worden uit- en ingeschakeld. Naast de severity wordt ook de locatie van aanroepen meegenomen in het bericht. De methode, bestandsnaam en lijnnummer moet worden bijgehouden. Omdat het meegegeven van al deze data nogal veel typ-werk is is er bij de logger ook gebruik gemaakt van verschillende *Macro's*, deze macro's zijn [hier](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/utils/Logger.h#L12-L31) terug te vinden. Door gebruik te maken van deze macro's is het opstellen van een log-bericht een stuk simpeler.

|||
|:---|:---|
|Zonder macro|```Utils::Logger::GetInstance().Error("message", __func__,__FILE__,__LINE__, "vars");```|
|Met macro|```ERROR("message", "vars");```|

Door log berichten te voorzien van deze verschillende data-elementen is het tijdens het afspelen van de applicatie vele malen makkelijker om bij te houden wat er precies gebeurt in de applicatie.

### Ontwerp keuzes

|||
|:---|:---|
|**Probleem**|Hoe kan op een efficiënte manier data opgeslagen en uitgelezen worden, verkregen van sensoren?|
|**Besluit**|Het opstellen van een circulaire buffer.|
|**Alternatieve**|Grote arrays, of dynamische opties zoals vectoren.|
|**Argumenten**|Een circulaire buffer is erg efficiënt qua opslag en geheugen. Het levert altijd een relatief betrouwbaar gemiddelde van de huidige data en is makkelijk in gebruik.|

**!tabel** - *Utils - ontwerp keuze 1*

|||
|:---|:---|
|**Probleem**|Hoe verzeker je dat er maar een instantie tegelijkertijd naar de seriële bus schrijft.|
|**Besluit**|Er is wederom gekozen voor het gebruik van het singleton pattern.|
|**Alternatieve**|Zeer precies bijhouden wanneer er geschreven wordt naar de seriële bus.|
|**Argumenten**|Zoals eerder vermeld, een singleton heeft maar een enkele instantie. Het is daarom een ideale keuze voor een probleem als deze.|

**!tabel** - *Utils - ontwerp keuze 2*

|||
|:---|:---|
|**Probleem**|Hoe kun je als gebruiker van de applicatie duidelijk zien wanneer, waar, wat gebeurt?|
|**Besluit**|Door tijd, methode, bestandsnaam en lijnnummer bij te houden van elke aanroep van een log bericht.|
|**Alternatieve**|deze data handmatig in het bericht te verwerken.|
|**Argumenten**|De bovenstaande velden zijn ingebouwde macro's van C++ en zijn opgesteld precies om de reden die hier als probleem is opgesteld. Door deze data mee te geven aan elk log bericht is het meteen duidelijk waar er gekeken moet worden bij een onverwachte situatie.|

**!tabel** - *Utils - ontwerp keuze 3*

|||
|:---|:---|
|**Probleem**|Hoe kun je op efficiënte manier log berichten opstellen met toch de adequate data onderdelen.|
|**Besluit**|Het opstellen van verschillende macro's die al deze datavelden automatisch aanroepen.|
|**Alternatieve**|Het handmatig meegegeven van deze velden.|
|**Argumenten**|Zoals verteld zijn de velden ingebouwde C++ macro's en zijn daarom ideaal om gebruikt te worden voor een situatie als deze.|

**!tabel** - *Utils - ontwerp keuze 4*


## Package - Base

|                                                                                |
| :----------------------------------------------------------------------------: |
| <img width="10000" src="assets/CD_base.svg"  alt="cd_base"/> |
|          **!diagram** - *Class diagram - Base*           |

De [**Base**](https://github.com/LukevLuijn/robox/tree/main/robox_firmware_v0.1/include/base) package is het centrale punt van de applicatie. In deze package is de samenhang tussen de package communication, StateMachine en device geregeld. De base package is opgedeeld in twee hoofd onderdelen. 

Aan de ene kan is de [**Robot**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/base/Robot.h) klasse. Deze klasse is verantwoordelijk voor alles hardware. In deze klasse worden de verschillende actuatoren aangestuurd en gevalideerd. De Robot klasse is gemaakt volgens het singleton pattern, net zoals bij de seriële bus mag er altijd, maar precies, een instantie gebruik maken van de hardware. Verder wordt in de Robot klasse nog [inverse en forward kinematica](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/src/Robot.cpp#L368-L435) toegepast voor het vertalen van hoeken naar positie en van positie naar hoeken. 

Aan de andere kant de state machine implementatie. De klasse [**Machine**](https://github.com/LukevLuijn/robox/blob/main/robox_firmware_v0.1/include/base/Machine.h) is een afgeleide van de klasse Context en draagt dezelfde verantwoordelijkheid. De klasse [**MachineState**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/include/base/States.h#L16) is een directe afgeleide van de State klasse, alle onderliggende state-klasse staan hieronder beschreven;

|Class|Beschrijving|
|:---|:---|
|[**StartState**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/src/States.cpp#L16-L44)|Start state is de staat waar de applicatie wacht op input van de gebruiker. In deze state zijn alle motoren uitgeschakeld.|
|[**HomeState**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/src/States.cpp#L45-L106)|In deze state voert de applicatie de homing sequence uit voor de vier verschillende actuatoren. Tijdens deze state is het mogelijk om een E-Stop uit te voeren. Zodra de homing sequence voltooid is zal de flag: 'activityComplete' op true gezet worden.|
|[**MoveState**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/src/States.cpp#L107-L216)|In de move state worden de motors direct aangesproken en zal de robot gaan bewegen. Zodra de beweging voltooid is zal de flag 'activityComplete' op true gezet worden. Ook tijdens deze state kan er een E-Stop uitgevoerd worden.|
|[**StopState**](https://github.com/LukevLuijn/robox/blob/98aca16f7c2ca8de0ee4921713f2d635fee8d508/robox_firmware_v0.1/src/States.cpp#L217-L320)|In de stop state wordt het stoppen en pauzeren van de robot geregeld. Bij het pauzeren van de robot wordt er een timer aangezet, zodra de timer afloopt zal de activityComplete flag op true gezet worden. Bij het stoppen van de robot wordt de robot naar de *idle positions* bewogen. Zodra de robot aangekomen is op deze posities worden de motoren uitgeschakeld en de activityComplete flag op true gezet.|

**!tabel** - State beschrijvingen

In het onderstaande state machine diagram is het verloop van de statemachine nogmaals afgebeeld.

|                                                                                |
| :----------------------------------------------------------------------------: |
| <img width="10000" src="assets/SM_firmware.svg"  alt="sm_firmware"/> |
|          **!diagram** - *Statemachine diagram*           |


### Ontwerp keuzes

|||
|:---|:---|
|**Probleem**|Hoe verzeker je dat er maar een instantie tegelijkertijd met de hardware componenten communiceert?|
|**Besluit**|Het opstellen van een singleton class.|
|**Alternatieve**|Het zeer accuraat bijhouden wie er met de componenten praat.|
|**Argumenten**|Zoals meerdere malen verteld is een singleton uitermate geschikt als een restrictie voor het vanaf verschillende locaties praten met onderdelen.|

**!tabel** - *Base - ontwerp keuze 1*

|||
|:---|:---|
|**Probleem**|Hoe kun je vanuit hoeken voor iedere joint berekenen wat de uiteindelijke positie van de gripper zal zijn?|
|**Besluit**|Het toepassen van forwards kinematica.|
|**Alternatieve**|geen.|
|**Argumenten**|Het toepassen van forwards kinematica levert de mogelijkheid om vanuit de eerder genoemde hoeken de eindpositie van de gripper te berekenen.|

**!tabel** - *Base - ontwerp keuze 2*

|||
|:---|:---|
|**Probleem**|Hoe kun je vanuit een eindpositie van de gripper bepalen wat de hoeken moeten zijn voor de rest van de robot?|
|**Besluit**|Get toepassen van inverse kinematica.|
|**Alternatieve**|geen.|
|**Argumenten**|Het toepassen van inverse kinematica levert de mogelijkheid om vanuit de eerder genoemde positie de verschillende hoeken van de robot te berekenen.|

**!tabel** - *Base - ontwerp keuze 3*



!url Wikipedia contributors. (2022a, april 26). Circular buffer. Wikipedia. Geraadpleegd op 27 mei 2022, van [ https://en.wikipedia.org/wiki/Circular_buffer]( https://en.wikipedia.org/wiki/Circular_buffer)