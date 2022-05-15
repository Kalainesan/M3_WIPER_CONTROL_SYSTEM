# FLOW CHART #

![beh_dia](https://user-images.githubusercontent.com/102134305/168486498-a08893d1-1930-4bc9-aa41-98a6942468e5.png)

# STRUCTURE DIAGRAM #

![struct_diag](https://user-images.githubusercontent.com/102134305/168486500-b88dc400-a65b-45f4-9e65-490ad6d327a5.png)

# UML DIAGRAM #

![uml_diag](https://user-images.githubusercontent.com/102134305/168486501-a97d7610-33ce-4de6-a630-ea911ffd101b.png)

# TEST PLAN AND OUTPUT #

| TEST ID | DESCRIPTION | EXPECTED I/P | ACTUAL O/P | EXPECTED O/P | STATUS |
| :------------:  | :------------------: | :------------------: | :-----------------: | :-------------------: | :--------------------: |
| H_01               | To monitor surroundings temperature | DHT 11 Temperature sensor is used to detect temperature | According to Temperature values wiper is operated | According to Temperature values automatic wiper is operated |PASSED |
| H_02               | To monitor Rain condition | Rain Sensor is used to detect the rain condition |According to Rain condition wiper is operated  | According to Rain condition wiper is operated | PASSED|
| H_03               | To monitor temperature and Rain conditions | Sensor values are detected | 4 LED lights are opearted accordingly | 4 LED lights are opearted accordingly | PASSED|
|L_04               | To get displayed in LCD | LCD is connected to STM32 Microcontroller | Displays the wiper movenment conditions | Displays the wiper movenment conditions | PASSED|
| H_05               | To make wiper movenments | Servomotor is connetced to STM32 Micrrocontroller | Wiper is moved accordingly | Wiper is moved accordingly |PASSED|


# OUTPUT #

![output_1](https://user-images.githubusercontent.com/102134305/168486226-ea2814c5-2c15-4ce4-a50a-1f6a341bdde9.jpg)


![output_2](https://user-images.githubusercontent.com/102134305/168486228-2bde9feb-cd3f-4aa1-91cd-32318cce2d03.jpg)
