
# Firmware prototype - Serial

In dit prototype wordt getest of de communicatie over de seriële bus snel genoeg is voor de applicatie. Tijdens deze tests is ook gelijk gekeken over er verlies van data ontstaat bij hogere communicatie snelheden.

Het prototype bestaat uit twee onderdelen. Het eerste onderdeel draait op de PC van de gebruiker. Dit onderdeel verstuurt seriële berichten met een steeds korter wordend interval met een maximale snelheid van 1 milliseconden.

Het tweede onderdeel is de ontvangende partij, draaiend op de microcontroller. Het binnenkomende bericht, wat is opgesteld volgens het resultaat van het prototype: [**Message**](https://github.com/LukevLuijn/robox_docs/tree/main/prototypes/firmware/message_test), wordt ge-parsed en over de seriële bus geprint.

In [dit](https://github.com/LukevLuijn/robox_docs/blob/main/prototypes/firmware/serial_test/assets/serial_speed_test_00.mp4?raw=true) filmpje is het resultaat van deze communicatie te zien. In het linker terminal is de driver te zien die de berichten verstuurd. In het rechter terminal is het verwerkte resultaat te zien van de microcontroller.