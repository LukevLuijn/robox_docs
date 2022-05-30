
# 1. Command protocol <a name="chapter0"></a>


## 1.1. Start command <a name="chapter1"></a>

|Name|H|#|Description|Syntax|Response|
|:---|:---|:---|:---|:---|:---|
|SET_START|```S```|0|Send out command to start the robot, when received the robot will start homing it's axes.|```<S0[]>```|No|

**!table** - *Start commands*

## 1.2. Movement command <a name="chapter2"></a>

|Name|H|#|Description|Syntax|Response|
|:---|:---|:---|:---|:---|:---|
|SET_INVERSE|```M```|0|Send movement command with cartesian coordinates.|```<M0[X,Y,Z,G]>```|No|
|SET_FORWARD|```M```|1|Send movement command with angle positions.      |```<M1[A0,A1,A2,A3]>```|No|
|SET_GRIPPER|```M```|2|Send movement command with gripper PWM values.   |```<M2[G0,G1]>```|No|

**!table** - *Movement commands*

## 1.3. Stop command <a name="chapter3"></a>

|Name|H|#|Description|Syntax|Response|
|:---|:---|:---|:---|:---|:---|
|SET_PAUSE  |```E```|0|Send stop command with duration, this will pause the robot for the given amount of time.|```<E0[ms]>```|No|
|STOP_ROBOT |```E```|1|Send stop command, this will move the robot to the idle position and disable all the joints.|```<E1[]>```|No|
|ESTOP_ROBOT|```E```|2|Send E-stop command, this will stop the robot directly and disable all the joints.|```<E2[]>```|No|

**!table** - *Stop commands*

## 1.4. Data command <a name="chapter4"></a>

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

# 2. Response protocol <a name="chapter5"></a>


## 2.1. Runtime data response <a name="chapter6"></a>

> Runtime data response syntax:
> ```#D0[CURRENT_POS_00,CURRENT_POS_01,CURRENT_POS_02,CURRENT_POS_03,IS_RUNNING_00,IS_RUNNING_01,IS_RUNNING_02,IS_RUNNING_03,POSITION_X,POSITION_Y,POSITION_Z,GRIPPER_SIG_00,GRIPPER_SIG_01]*```


| Index | Field                | Type          | Description                                 |
| :---: | :------------------- | :------------ | :------------------------------------------ |
|  00   | ```CURRENT_POS_00``` | float         | Current position segment 00                 |
|  01   | ```CURRENT_POS_01``` | float         | Current position segment 01                 |
|  02   | ```CURRENT_POS_02``` | float         | Current position segment 02                 |
|  03   | ```CURRENT_POS_03``` | float         | Current position segment 03                 |
|  04   | ```IS_RUNNING_00```  | bool          | If segment 00 is currently moving.          |
|  05   | ```IS_RUNNING_01```  | bool          | If segment 01 is currently moving.          |
|  06   | ```IS_RUNNING_02```  | bool          | If segment 02 is currently moving.          |
|  07   | ```IS_RUNNING_03```  | bool          | If segment 03 is currently moving.          |
|  08   | ```POSITION_X```     | float         | Cartesian coordinate X of gripper position. |
|  09   | ```POSITION_Y```     | float         | Cartesian coordinate Y of gripper position. |
|  10   | ```POSITION_Z```     | float         | Cartesian coordinate Z of gripper position. |
|  11   | ```GRIPPER_SIG_00``` | unsigned char | Current PWM value for gripper pin 0.        |
|  12   | ```GRIPPER_SIG_01``` | unsigned char | Current PWM value for gripper pin 1.        |

**!table** - *Runtime data response*

## 2.2. Static data response <a name="chapter7"></a>

> Static data response syntax:
> ```#D1[HALL_SENSOR_00,HALL_SENSOR_01,HALL_SENSOR_02,HALL_SENSOR_03,MOTOR_STP_00,MOTOR_DIR_00,MOTOR_ENB_00,MOTOR_STP_01,MOTOR_DIR_01,MOTOR_ENB_01,MOTOR_STP_02,MOTOR_DIR_02,MOTOR_ENB_02,MOTOR_STP_03,MOTOR_DIR_03,MOTOR_ENB_03,GRIPPER_SIGNAL_00,GRIPPER_SIGNAL_01,MAX_HEIGHT_SEGMENT_00,MIN_HEIGHT_SEGMENT_00,MAX_ANGLE_SEGMENT_01,MIN_ANGLE_SEGMENT_01,MAX_ANGLE_SEGMENT_02,MIN_ANGLE_SEGMENT_02,MAX_ANGLE_SEGMENT_03,MIN_ANGLE_SEGMENT_03,MAX_SPEED_SEGMENT_00,MAX_ACCEL_SEGMENT_00,MAX_SPEED_SEGMENT_01,MAX_ACCEL_SEGMENT_01,MAX_SPEED_SEGMENT_02,MAX_ACCEL_SEGMENT_02,MAX_SPEED_SEGMENT_03,MAX_ACCEL_SEGMENT_03,LENGTH_SEGMENT_01,LENGTH_SEGMENT_02,LEAD_SCREW_PITCH,MICRO_STEPPING_00,MICRO_STEPPING_01,MICRO_STEPPING_02,MICRO_STEPPING_03,STEPS_PER_MILLIMETER_00,STEPS_PER_DEGREE_01,STEPS_PER_DEGREE_02,STEPS_PER_DEGREE_03]*```

| Index | Field                         | Type           | Description                            |
| :---: | :---------------------------- | :------------- | :------------------------------------- |
|  00   | ```HALL_SENSOR_00```          | unsigned char  | Hall sensor 0 pin.                     |
|  01   | ```HALL_SENSOR_01```          | unsigned char  | Hall sensor 1 pin.                     |
|  02   | ```HALL_SENSOR_02```          | unsigned char  | Hall sensor 2 pin.                     |
|  03   | ```HALL_SENSOR_03```          | unsigned char  | Hall sensor 3 pin.                     |
|  04   | ```MOTOR_STP_00```            | unsigned char  | Step pin motor 0.                      |
|  05   | ```MOTOR_DIR_00```            | unsigned char  | Direction pin motor 0.                 |
|  06   | ```MOTOR_ENB_00```            | unsigned char  | Enable pin motor 0.                    |
|  07   | ```MOTOR_STP_01```            | unsigned char  | Step pin motor 1.                      |
|  08   | ```MOTOR_DIR_01```            | unsigned char  | Direction pin motor 1.                 |
|  09   | ```MOTOR_ENB_01```            | unsigned char  | Enable pin motor 1.                    |
|  10   | ```MOTOR_STP_02```            | unsigned char  | Step pin motor 2.                      |
|  11   | ```MOTOR_DIR_02```            | unsigned char  | Direction pin motor 2.                 |
|  12   | ```MOTOR_ENB_02```            | unsigned char  | Enable pin motor 2.                    |
|  13   | ```MOTOR_STP_03```            | unsigned char  | Step pin motor 3.                      |
|  14   | ```MOTOR_DIR_03```            | unsigned char  | Direction pin motor 3.                 |
|  15   | ```MOTOR_ENB_03```            | unsigned char  | Enable pin motor 3.                    |
|  16   | ```GRIPPER_SIGNAL_00```       | unsigned char  | Gripper signal pin 01.                 |
|  17   | ```GRIPPER_SIGNAL_01```       | unsigned char  | Gripper signal pin 02.                 |
|  18   | ```MAX_HEIGHT_SEGMENT_00```   | unsigned short | Maximal height segment 00.             |
|  19   | ```MIN_HEIGHT_SEGMENT_00```   | unsigned short | Minimal height segment 00.             |
|  20   | ```MAX_ANGLE_SEGMENT_01```    | unsigned short | Maximal angle segment 01.              |
|  21   | ```MIN_ANGLE_SEGMENT_01```    | unsigned short | Minimal angle segment 01.              |
|  22   | ```MAX_ANGLE_SEGMENT_02```    | unsigned short | Maximal angle segment 02.              |
|  23   | ```MIN_ANGLE_SEGMENT_02```    | unsigned short | Minimal angle segment 02.              |
|  24   | ```MAX_ANGLE_SEGMENT_03```    | unsigned short | Maximal angle segment 03.              |
|  25   | ```MIN_ANGLE_SEGMENT_03```    | unsigned short | Minimal angle segment 03.              |
|  26   | ```MAX_SPEED_SEGMENT_00```    | unsigned short | Maximal speed segment 00.              |
|  27   | ```MAX_ACCEL_SEGMENT_00```    | unsigned short | Maximal acceleration segment 00.       |
|  28   | ```MAX_SPEED_SEGMENT_01```    | unsigned short | Maximal speed segment 01.              |
|  29   | ```MAX_ACCEL_SEGMENT_01```    | unsigned short | Maximal acceleration segment 01.       |
|  30   | ```MAX_SPEED_SEGMENT_02```    | unsigned short | Maximal speed segment 02.              |
|  31   | ```MAX_ACCEL_SEGMENT_02```    | unsigned short | Maximal acceleration segment 02.       |
|  32   | ```MAX_SPEED_SEGMENT_03```    | unsigned short | Maximal speed segment 03.              |
|  33   | ```MAX_ACCEL_SEGMENT_03```    | unsigned short | Maximal acceleration segment 03.       |
|  34   | ```LENGTH_SEGMENT_01```       | unsigned short | Fysical length segment 01.             |
|  35   | ```LENGTH_SEGMENT_02```       | unsigned short | Fysical length segment 02.             |
|  36   | ```LEAD_SCREW_PITCH```        | unsigned short | Thread pitch of the used lead screw.   |
|  37   | ```MICRO_STEPPING_00```       | unsigned short | Microstepping configuration segment 00 |
|  38   | ```MICRO_STEPPING_01```       | unsigned short | Microstepping configuration segment 01 |
|  39   | ```MICRO_STEPPING_02```       | unsigned short | Microstepping configuration segment 02 |
|  40   | ```MICRO_STEPPING_03```       | unsigned short | Microstepping configuration segment 03 |
|  41   | ```STEPS_PER_MILLIMETER_00``` | float          | Steps per millimeter value segment 00. |
|  42   | ```STEPS_PER_DEGREE_01```     | float          | Steps per degree value segment 01.     |
|  43   | ```STEPS_PER_DEGREE_02```     | float          | Steps per degree value segment 02.     |
|  44   | ```STEPS_PER_DEGREE_03```     | float          | Steps per degree value segment 03.     |

**!table** - *Static data response*

## 2.3. Dynamic data response <a name="chapter8"></a>

> Dynamic data response syntax:
> ```#D2[CURRENT_SPEED_00,CURRENT_ACCEL_00,CURRENT_SPEED_01,CURRENT_ACCEL_01,CURRENT_SPEED_02,CURRENT_ACCEL_02,CURRENT_SPEED_03,CURRENT_ACCEL_03,VERBOSITY_ERROR,VERBOSITY_WARNING,VERBOSITY_INFO,VERBOSITY_DEBUG,FRAME_HEIGHT_OFFSET,GRIPPER_HEIGHT_OFFSET,ACTUAL_ZERO_POS_SEG_00,IDLE_POS_SEGMENT_00,IDLE_POS_SEGMENT_01,IDLE_POS_SEGMENT_02,IDLE_POS_SEGMENT_03]*```

| Index | Field                        | Type           | Description                                               |
| :---: | :--------------------------- | :------------- | :-------------------------------------------------------- |
|  00   | ```CURRENT_SPEED_00```       | float          | Current speed segment 00.                                 |
|  01   | ```CURRENT_ACCEL_00```       | float          | Current acceleration segment 00.                          |
|  02   | ```CURRENT_SPEED_01```       | float          | Current speed segment 01.                                 |
|  03   | ```CURRENT_ACCEL_01```       | float          | Current acceleration segment 01.                          |
|  04   | ```CURRENT_SPEED_02```       | float          | Current speed segment 02.                                 |
|  05   | ```CURRENT_ACCEL_02```       | float          | Current acceleration segment 02.                          |
|  06   | ```CURRENT_SPEED_03```       | float          | Current speed segment 03.                                 |
|  07   | ```CURRENT_ACCEL_03```       | float          | Current acceleration segment 03.                          |
|  08   | ```VERBOSITY_ERROR```        | bool           | Current verbosity setting Error                           |
|  09   | ```VERBOSITY_WARNING```      | bool           | Current verbosity setting Warning                         |
|  10   | ```VERBOSITY_INFO```         | bool           | Current verbosity setting Info                            |
|  11   | ```VERBOSITY_DEBUG```        | bool           | Current verbosity setting Debug                           |
|  12   | ```FRAME_HEIGHT_OFFSET```    | unsigned short | Current frame height offset.                              |
|  13   | ```GRIPPER_HEIGHT_OFFSET```  | unsigned short | Current gripper height offset.                            |
|  14   | ```ACTUAL_ZERO_POS_SEG_00``` | unsigned short | Actual zero position, after frame and gripper conversion. |
|  15   | ```IDLE_POS_SEGMENT_00```    | unsigned short | Idle position segment 00.                                 |
|  16   | ```IDLE_POS_SEGMENT_01```    | unsigned short | Idle position segment 01.                                 |
|  17   | ```IDLE_POS_SEGMENT_02```    | unsigned short | Idle position segment 02.                                 |
|  18   | ```IDLE_POS_SEGMENT_03```    | unsigned short | Idle position segment 03.                                 |

**!table** - *Dynamic data response*






# 3. Log protocol <a name="chapter9"></a>



> Log message syntax: ```@verbosityIndex[messageString;caller;file;lineNum;variables]*```

|Index|Variable|Description|Values|
|:---:|:---|:---|:---|
|00|**```@```**|Log message start char|```@```|
|01|**verbosityIndex**|Index of severity.|0..3 [ERROR,WARNING,INFO,DEBUG]|
|02|**messageString**|Actual message string.|String|
|03|**caller**|Caller of log message.|String|
|04|**file**|File name of caller.|String|
|05|**lineNum**|Line number of caller.|uint16_t|
|06|**variables**|Variable string, seperated by comma.|String|
|07|**```*```**|Log message stop char|```*```|

**!table** - *Log message protocol*



