# TEST PLAN AND OUTPUT #

| TEST ID | DESCRIPTION | EXPECTED I/P | ACTUAL O/P | EXPECTED O/P | STATUS |
| :------------:  | :------------------: | :------------------: | :-----------------: | :-------------------: | :--------------------: |
| H_01               | To monitor surroundings temperature | DHT 11 Temperature sensor is used to detect temperature | According to Temperature values wiper is operated | According to Temperature values automatic wiper is operated |PASSED |
| H_02               | To monitor Rain condition | Rain Sensor is used to detect the rain condition |According to Rain condition wiper is operated  | According to Rain condition wiper is operated | PASSED|
| H_03               | To monitor temperature and Rain conditions | Sensor values are detected | 4 LED lights are opearted accordingly | 4 LED lights are opearted accordingly | PASSED|
|L_04               | To get displayed in LCD | LCD is connected to STM32 Microcontroller | Displays the wiper movenment conditions | Displays the wiper movenment conditions | PASSED|
| H_05               | To make wiper movenments | Servomotor is connetced to STM32 Micrrocontroller | Wiper is moved accordingly | Wiper is moved accordingly |PASSED|
