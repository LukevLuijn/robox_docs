# Firmware prototype - state machine

In dit prototype wordt de uitwerking van het [state machine pattern](https://sourcemaking.com/design_patterns/state) (Sourcemaking, z.d.-d) op een microcontroller getest. Voor het prototype is een klein spel opgezet. Er zijn twee dobbelstenen ([**Dice**](https://github.com/LukevLuijn/robox_docs/blob/main/prototypes/firmware/state_machine_test/code/include/Dice.h)) deze worden 'geworpen' door de applicatie. Als het aantal ogen gelijk is aan twee verlies je, als het gelijk is aan twaalf win je en bij elk ander getal moet je opnieuw gooien, wat automatisch gebeurt. 

In dit prototype is voornamelijk de package [**StateMachine**](https://github.com/LukevLuijn/robox_docs/tree/main/prototypes/firmware/state_machine_test/code/lib/state_machine) van belang, en de implementaties daarvan  ( [**ConcreteStates**](https://github.com/LukevLuijn/robox_docs/blob/main/prototypes/firmware/state_machine_test/code/include/ConcreteStates.h) & [**Game**](https://github.com/LukevLuijn/robox_docs/blob/main/prototypes/firmware/state_machine_test/code/include/Game.h))

Voor een visuele implementatie op de microcontroller is er gekozen om telkens wanneer je niet wint of verliest ('again state') een blauw lampje aan te zetten, als je wint gaat het groene lampje aan en als je verliest het rode lampje.

Het resultaat is te zien in [dit](https://github.com/LukevLuijn/robox_docs/blob/main/prototypes/firmware/state_machine_test/assets/state_machine_test_clip_00.mp4?raw=true) filmpje.


# Literatuurlijst

Sourcemaking. (z.d.-d). Design Patterns and Refactoring. State Pattern. Geraadpleegd op 30 mei 2022, van [https://sourcemaking.com/design_patterns/state](https://sourcemaking.com/design_patterns/state)
