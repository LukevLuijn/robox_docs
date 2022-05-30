
# Firmware prototype - Homing

In dit prototype is de homing sequence uitgewerkt. Er is een basis opzet gemaakt van de methodiek van besturing van de verschillende motoren in combinatie met de hall sensors.

De drie hoofd elementen van dit prototype zijn terug te vinden op de onderstaande locaties:

|#|Onderdeel|Beschrijving|
|:---:|:---|:---|
|01|[**Homing single magnet axial**](https://github.com/LukevLuijn/robox_docs/blob/745136eff8d45ba5060a808fa8a38697ca228cd8/prototypes/firmware/homing_test/code/src/AxialActuator.cpp#L35-L98)|In dit onderdeel is te homing sequence uitgewerkt voor het home'en van een axiale as met een enkele magneet, dit houdt in dat de as dus meer dan 360 graden rotatie heeft.|
|02|[**Homing double magnet axial**](https://github.com/LukevLuijn/robox_docs/blob/745136eff8d45ba5060a808fa8a38697ca228cd8/prototypes/firmware/homing_test/code/src/AxialActuator.cpp#L99-L155)|In dit onderdeel is te homing sequence uitgewerkt voor het home'en van een axiale as met twee magneten, dit houdt in dat de as dus minder dan 360 graden rotatie heeft.|
|03|[**Homing single magnet linear**](https://github.com/LukevLuijn/robox_docs/blob/745136eff8d45ba5060a808fa8a38697ca228cd8/prototypes/firmware/homing_test/code/src/LinearActuator.cpp#L24-L60)|In dit onderdeel is te homing sequence uitgewerkt voor het home'en van een lineaire as met een enkele magneet.|

Er is ook een filmpje van de werking van de homing sequence, deze is [hier](https://github.com/LukevLuijn/robox_docs/blob/main/prototypes/firmware/homing_test/assets/homing_test_clip_00.mp4?raw=true) te zien. 

