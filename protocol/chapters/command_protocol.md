
## Start command

|Name|H|#|Description|Syntax|Response|
|:---|:---|:---|:---|:---|:---|
|SET_START|```S```|0|Send out command to start the robot, when received the robot will start homing it's axes.|```<S0[]>```|No|

**!table** - *Start commands*

## Movement command

|Name|H|#|Description|Syntax|Response|
|:---|:---|:---|:---|:---|:---|
|SET_INVERSE|```M```|0|Send movement command with cartesian coordinates.|```<M0[X,Y,Z,G]>```|No|
|SET_FORWARD|```M```|1|Send movement command with angle positions.      |```<M1[A0,A1,A2,A3]>```|No|
|SET_GRIPPER|```M```|2|Send movement command with gripper PWM values.   |```<M2[G0,G1]>```|No|

**!table** - *Movement commands*

## Stop command

|Name|H|#|Description|Syntax|Response|
|:---|:---|:---|:---|:---|:---|
|SET_PAUSE  |```E```|0|Send stop command with duration, this will pause the robot for the given amount of time.|```<E0[ms]>```|No|
|STOP_ROBOT |```E```|1|Send stop command, this will move the robot to the idle position and disable all the joints.|```<E1[]>```|No|
|ESTOP_ROBOT|```E```|2|Send E-stop command, this will stop the robot directly and disable all the joints.|```<E2[]>```|No|

**!table** - *Stop commands*

## Data command

|Name|H|#|Description|Syntax|Response|
|:---|:---|:---|:---|:---|:---|
|GET_RUNTIME        |```D```|0|Send out data command for runtime data.|```<D0[]>```|Yes|
|GET_DYNAIC         |```D```|1|Send out data command for dynamic data.|```<D1[]>```|Yes|
|GET_STATIC         |```D```|2|Send out data command for static data.|```<D2[]>```|Yes|
|SET_SPEED_ACCEL    |```D```|3|Send out command to set new speed and accel values.|```<D3[speed,accel]>``` |No|
|SET_VERBOSITY      |```D```|4|Send out command to set new verbosity values.|```<D4[E,W,I,D]>```|No|
|SET_FRAME_OFFSET   |```D```|5|Send out command to set new a frame offset value.|```<D5[offset]>```|No|
|SET_GRIP_OFFSET    |```D```|6|Send out command to set new a gripper offset value.|```<D6[offset]>```|No|
|SET_IDLE_POSITIONS |```D```|7|Send out command to set new idle positions.|```<D7[P0,P1,P2,P3]>```|No|
|HOMING_COMPLETE    |```D```|8|Send out command to let the user know the homing sequence is complete.|```<D8[]>```|No|

**!table** - *Data commands*
