/*

Programmer: Sonia Sharma
Date Created: May 18th, 2021
Program: Traffic Lights Part 1
Description: This program is a simulation of traffic lights between cars 1 traffic & cars 2 traffic

Notes: cars 1 = car traffic using lights 1
	   cars 2 = car traffic using lights 2
*/


/**********************************************************************************************************************
Pins: Connected to pins 1-12
- pins 0, 1, 2, 3, 4, 5, 6,7, 8, 9 , 10, 11, 12
Components: 10 LED lights, 10 resistors with a value of 220R
**********************************************************************************************************************/


/*********************************************************************************************************************
Global Variables & Constants: Initialize each LED to their pin value, and delay time when transitioning between traffic 
                              lights.
*********************************************************************************************************************/
const int L1Rd = 8; //initialize red LED car light in Lights 1 to pin 8
const int L1Ylw = 9; //initialize yellow LED car light in Lights 1 to pin 9
const int L1Grn = 10; //initialize green LED car light in Lights 1 to pin 10

const int P1Rd = 11; //initialize red LED pedestrian light in Lights 1 to pin 11
const int P1Wht = 12; //initialize white LED pedestrian light in Lights 1 to pin 12


const int L2Rd = 0; //initialize red LED car light in Lights 2 to pin 0
const int L2Ylw = 1; //initialize yellow LED car light in Lights 2 to pin 1
const int L2Grn = 2; //initialize green LED car light in Lights 2 to pin 2 

const int P2Rd = 3; //initialize red LED pedestrian light in Lights 2 to pin 3
const int P2Wht = 4; //initialize white LED pedestrian light in Lights 2 to pin 4 

int LEDdelay4 = 4000; /*pause the code above delay function, when called, for 4 seconds
                        stores the transition time between green light and yellow light*/
int LEDdelay2 = 2000; /*pause the code above delay function, when called, for 2 seconds
					   stores the transition time between yellow light and red light*/


/*********************************************************************************************************************
Functions Used: setup(), loop(), Cars1Moving(), Cars2Moving()
*********************************************************************************************************************/


/*********************************************************************************************************************
Setup Function - this code runs once and is used to setup stuff(initialize pin modes)
*********************************************************************************************************************/
void setup()
{
  pinMode(L1Rd, OUTPUT);
  pinMode(L1Ylw, OUTPUT);
  pinMode(L1Grn, OUTPUT);
  pinMode(P1Rd, OUTPUT);
  pinMode(P1Wht, OUTPUT);
  pinMode(L2Rd, OUTPUT);
  pinMode(L2Ylw, OUTPUT);
  pinMode(L2Grn, OUTPUT);
  pinMode(P2Rd, OUTPUT);
  pinMode(P2Wht, OUTPUT);
}


/*********************************************************************************************************************
Loop Function - loops the code within the body & runs forever
*********************************************************************************************************************/
void loop()
{
  Cars1Moving();// this function runs when cars 1 are IN motion and cars 2 are NOT moving
  Cars2Moving();// this function runs when cars 2 are IN motion and cars 1 are NOT moving
}


/*********************************************************************************************************************
Cars1Moving Function:
- Let cars 1 traffic light be green(cars 1 are in motion)and pedestrian light be red. 
- Let cars 2 traffic lights be red(cars 2 stay in place) and pedestrian light be white
*********************************************************************************************************************/
void Cars1Moving()
{
  
  /*********************************************************************************************************************
  Code for when traffic lights for cars 1 is green and cars 2 is red 
  *********************************************************************************************************************/
  
  // Logic for cars 1(Lights 1)
  digitalWrite(L1Rd, LOW); /*turn OFF red traffic light from the previous function before code loops 
   						     in order for the green light to be ON and let cars 1 drive*/
  digitalWrite(P1Wht, LOW); /*turn OFF white pedestrian light from the previous function before code loops
  							  in order for the red pedestrian light to turn ON and for the pedestrians to stop walking*/
  
  digitalWrite(L1Grn, HIGH); //turn ON green traffic light in order to start the traffic lights simulation							
  digitalWrite(P1Rd, HIGH); /*turn ON red pedestrian light for pedestrians to stop walking and let the cars drive
                              at green and yellow light,to prevent accidents*/
  
  // Logic for cars 2(Lights 2); Traffic Light is Red 
  digitalWrite(L2Ylw, LOW); /*turn OFF yellow traffic light from the previous function before code loops
  							  in order for the red light to be ON and make cars 2 stop driving*/
  digitalWrite(P2Rd, LOW); /*turn OFF red pedestrian light from the previous function before code loops
  							 in order for the white pedestrian light to turn ON and allow the pedestrians to walk*/
  
  digitalWrite(L2Rd, HIGH); //turn ON red traffic light in order for cars 2 to stop and let cars 1 to drive*/ 
  digitalWrite(P2Wht, HIGH); /*turn ON white pedestrian light in order for the pedestrians to 
  							   walk safely to the other side before cars 2 traffic drives*/
  
  delay(LEDdelay4); //allow cars 1 to drive and make cars 2 stop, within the time
  
  
  /*********************************************************************************************************************
  Code for when traffic lights for cars 1 is yellow light and cars 2 is red 
  *********************************************************************************************************************/
  
  // Logic for cars 1(Lights 1); Traffic light is Yellow
  digitalWrite(L1Grn, LOW); //turn OFF green light in order for the traffic light to transition to yellow
  
  digitalWrite(L1Ylw, HIGH);//turn ON yellow light to make cars 1 slow down as they drive past/approach the traffic light
  /*Let the red pedestrian light remain ON since cars 1 might still be in motion. Therefore, we don't need to
  call the function again*/
  
  /*Logic for Lights 2; Traffic light is STILL Red
  - Let the red traffic light remain ON since cars 2 have to remain still due to cars 1 still being in motion. 
  - Let the white pedestrian light remain ON since people can still walk since cars 2 traffic light is red.
  Therefore, we don't need to call the functions again*/
  
  delay(LEDdelay2); //allow cars 1 to slow down and make cars 2 remain at rest, within the time  
}


/**********************************************************************************************************************
Cars2Moving Function:
- Let cars 1 traffic lights(Lights 1) be red(cars 1 are NOT in motion) and pedestrian light be white
- Let cars 2 traffic lights(Lights 2) be green (cars 2 are IN motion) and pedestrian light be red
**********************************************************************************************************************/
void Cars2Moving()
{
  
  /**********************************************************************************************************************
  Code for when traffic lights for cars 2 is green and cars 1 is red 
  **********************************************************************************************************************/
  
  // Logic for Lights 1 traffic lights (Red)
  digitalWrite(L1Ylw, LOW); /*turn OFF yellow traffic light from the previous function
  						      in order for the red light to be ON and stop cars 1 stop from driving*/
  digitalWrite(P1Rd, LOW); /*turn OFF red pedestrian light from the previous function 
  							 in order for the white pedestrians light to turn ON and let the pedestrians walk*/  
  
  digitalWrite(L1Rd, HIGH); //turn ON red traffic light in order for cars 1 to stop and let cars 2 to drive
  digitalWrite(P1Wht, HIGH); /*turn ON white pedestrian light in order for the pedestrians to 
  							   walk safely to the other side before cars 1 traffic can drive*/ 
  
  // Logic for Lights 2 traffic lights(Green)
  digitalWrite(L2Rd, LOW); /*turn OFF red traffic light from the previous function 
   						     in order for the green light to be ON and let cars 2 drive*/
  digitalWrite(P2Wht, LOW); /*turn OFF white pedestrian light from the previous function
  							 in order for the red pedestrian light to turn ON and for the pedestrians to stop walking*/
  
  digitalWrite(L2Grn, HIGH);// turn ON green traffic light in order to start the traffic lights simulation
  digitalWrite(P2Rd, HIGH);/* turn ON red pedestrian light for pedestrians to stop walking and let the cars go
                              at green and yellow light,to prevent accidents*/
  
  delay(LEDdelay4); //allow cars 2 to move and make cars 1 stop, within the time
  
  
  /**********************************************************************************************************************
  Code for when traffic lights for cars 1 is yellow and cars 2 is red 
  **********************************************************************************************************************/
  
  /*Logic for Lights 1 traffic lights(Red)
  - Let the red traffic light remain ON since cars 1 have to remain still due to cars 2 still being in motion. 
  - Let the white pedestrian light remain ON since people can still walk since cars 1 traffic light is red.
  Therefore, we don't need to call the functions again*/ 
  
  // Logic for Lights 2 traffic lights (Yellow)
  digitalWrite(L2Grn, LOW); //turn OFF green light in order for the traffic light to transition to yellow
  
  digitalWrite(L2Ylw, HIGH); //turn ON yellow light to make cars 2 slow down as they drive past/approach the traffic light
  /*Let the red pedestrian light remain ON since cars 2 might still be in motion. Therefore, we don't need to
  call the function again*/
  
  delay(LEDdelay2); //allow cars 2 to slow down and make cars 1 remain at rest, within the time     
  
}
