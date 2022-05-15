# WIPER CONTROL SYSTEM #

## INTRODUCTION ##

Wiper is an essential component that used to wipe raindrops or any water from the vehicle’s windscreen. The previous system
used to activate the wiper manually and the process of pulling up the wiper is difficult to be handled. In this, we propose an unmanned wiper which senses rain and starts automatically and switches off automatically when the rain
stops. By using this, there will be no need for physical intervention of human to control the speed of the wiper The objectives of this project are to upgrade the older cars system by providing automatic
wiping system, to improve the system by using sensor with actuator and to design a basic program that will fully operate with
the system. The concept of this proposed wiper system is similar with other existing conventional wiper. In spite of removing
water from windscreen, this system also will be upgraded to an automatic control system by using a STM32f407 microcontroller and rain sensor. Our system uses rain sensor to detect rain, this signal is then processed by microcontroller to take the desired action. The rain sensor works on the principle of using water for completing its circuit, so when rain falls on it it’s circuit gets completed and sends out a signal to the microcontroller. The microcontroller now processes this data and controls the motor.

## FEATURES ##

* The Mega-Guard Wiper Control System (WCS) controls up to 9 windshield wipers. Each wiper has its own on/off  button and fore and aft wipers are grouped together for simultaneous on/off control.
* The wipers are synchronized with each other. The washing function includes spraying, wiping and purging. 

## OVERVIEW ##

The windshield wiper control module drives the wiper motor based on the the current state of the wiper switch, mostly to support the intermittent wipe feature. This is also  known  as the wiper delay module.A mechanism can handle one function or multiple of functions. In this case, our project is about windshield wiper mechanism which is intended to wipe a  maximum area of a windshield. 
- Some applications are as follows:-
- Ø I improved visibility of car windshield during rain.
- The wiper has been controlled by a water level sensor which regulate t.
- A cycle being the forward and return movement of the windscreen wiper.
- After tuning the switch on the wiper should start and clear the screen the wiper motor through sensing the level of water or rain.

## REQUIREMENTS ##

### HIGH LEVEL REQUIREMENTS ###

|  ID	  |   Description |
|-------------|:----------------------:|
| HLR1   |    These systems detect droplets of rain on the windshield and automatically turn on and adjust the wiper system in accordance to the level of precipitation. |
| HLR2	  |    A windscreen wiper or windshield wiper is a device used to remove rain, snow, ice and debris from a windscreen or windshield. |
| HLR3   |	   Quality and reliability  wiper systems meet the highest technical requirements and are the basis for vehicles with sophisticated features. |
| HLR4   |    Almost all motor vehicle, including trains, aircraft and watercraft, are equipped with such wipers, which are usually an essential requirement. |
| HLR5   |    Our project brings forward this system to automate the wiper system having no need for manual intervention. |

### LOW LEVEL REQUIREMENTS ###

| ID	   |  Description |
|-----------:|:------------------------:|
| LLR1	 | A new mechatronic reversing system can now be used to clean the windshield with two wiper arms, whereby one wiper arm is powered directly and the other indirectly using a connection link. |
| LLR2	 | Wiper motor is automatically ON during the time of rainfall. |
| LLR3	 | Existing system manually used control stalk to activate wiper and the process of pulling up wiper is difficult to be handled. |
| LLR4	 | Lower level parsing¶. Under the hood, the Requirement class does most of the heavy lifting. class requirements. |
| LLR5	 | These systems detect droplets of rain on the windshield and automatically turn on and adjust the wiper system. |


## WORKING PRINCIPLE ##

Consider the automobile as microcontroller. If the button is hit, the first LED (red) will turn on. Pressing the button again the wiper will start and the second LED (blue) will turn on for the desired rate. If the button is pressed again, the third LED (green) will turn on and the wiper's speed will be increased in comparison to the previous one. The fourth press will turn on the fourth LED (orange) and the wiper speed will be increased in accordance with the previous one. The microcontroller (vehicle) is turned off after the fifth click.

## SWOT ANALYSIS ##

### STRENGTH ###
* It helps in saving money by switching off the irrigation system when it rains. This saves money by cutting off bills on electricity consumption.
* It extends life of rain sensor based systems such as car wiper, irrigation systems by running them only when it is necessary.
* Rain sensors help save water during rain events and hence water is available during summer and emergency applications such as firefighting etc.
* Operating principle is very easy.
* It consumes less power for operation.

### WEAKNESS ###
* The rain sensor based system functions when water falls on the sensor directly. ➨The cost of overall system increases as additional components are needed along with rain sensor. 
* In order to avoid false detection of rain, it requires rain sensors to take decision after few minutes.

### OPPORTUNITIES ###
* Technological Growth
* Automation in Automotive industries

### THREATS ###
* Strong Competitors
* No proper regulation
* Poor Implementation leads to system failure

 
## 4-W's & 1-H ##

### WHAT ###
* Rain sensor turns off irrigation system within minutes when rain water falls. Here it consists of water absorbing expansion disks which swell in presence of rain drops. After some amount of rain falls, electrical switch gets depressed. As a result, regular cycle of irrigation is bypassed and automatic irrigation system is switched off. Disks shrink when dry condition is reached and reverse action takes place.

### WHEN ###
* When there is a change in the weather,the wipers work automatically.

### WHY ###
* This projects helps the users to achieve the clear path when there is a change of weather.

### HOW ###
* So here we propose an automatic wiper system that automatically switches 'ON' on detecting rain and stops when rain stops and dust sensor is also added,when it detects dust it will wipe. Our project brings forward this system to automate the wiper system having no need for manual intervention. For this purpose we use rain sensor and dust sensor along with microcontroller to drive the wiper motor. Our system uses rain sensor to detect rain and dust sensor to detect the dust, this signal is then processed by microcontroller to take the desired action. The rain sensor works on the principle of using water for completing its circuit, so when rain falls on it it’s circuit gets completed and sends out a signal to the microcontroller, similarly when dust is appearing in the car glass surface it will detect, and gives signal to the microcontroller. The microcontroller now processes this data and controls the motor.This system is equally useful version. Features


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
