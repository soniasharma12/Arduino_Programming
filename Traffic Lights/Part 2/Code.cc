/*

Programmer: Sonia Sharma
Date Created: May 27th, 2021
Program: Traffic Lights Part 2
Description: This program is a simulation of traffic lights including a button for the pedestrians to press and cross 
	         the road safely 
             
*/


/**********************************************************************************************************************
Pins: Connected to pins 1, 2, 6(Btn), 11, 12, 13, GND, and 5V
Components: 1 button, 5 LED lights, 6 resistors; five with a value of 220R and one with a value of 10k R
**********************************************************************************************************************/


/*********************************************************************************************************************
Global Variables & Constants: Initialize each LED and button to their pin value, and delay time when transitioning 
							  between traffic lights.
Notes:                              
- CarRd, CarYlw, CarGrn = variables for LED car traffic lights
- PedRd, PedWht = variables for pedestrian lights
- Btn = variable for pedestrian button
*********************************************************************************************************************/
const int CarRd = 11; //initialize red LED car light to pin 11
const int CarYlw = 12; //initialize yellow LED car light to pin 12
const int CarGrn = 13; //initialize green LED car light to pin 13

const int PedRd = 1; //initialize red LED pedestrian light to pin 1
const int PedWht = 2; //initialize white LED pedestrian light to pin 2

const int Btn = 6; // initialize button to pin 6


int LEDdelay3 = 3000; /*pause the code above delay function, when called, for 4 seconds
                        stores the transition time between green light and yellow light*/
int LEDdelay2 = 2000; /*pause the code above delay function, when called, for 2 seconds
					   stores the transition time between yellow light and red light*/


/*********************************************************************************************************************
Functions Used: setup(), loop(), WalkNow()
Conditions Used: do....while loop
*********************************************************************************************************************/


/*********************************************************************************************************************
Setup Function - this code runs once and is used to setup stuff(initialize pin modes)
*********************************************************************************************************************/
void setup()
{
  pinMode(CarRd, OUTPUT);
  pinMode(CarYlw, OUTPUT);
  pinMode(CarGrn, OUTPUT);
  pinMode(PedRd, OUTPUT);
  pinMode(PedWht, OUTPUT);
  pinMode(Btn, INPUT);
}// end of setup() function


/*********************************************************************************************************************
Loop Function - loops the code within the body & runs forever
*********************************************************************************************************************/
void loop()
{
  // if user presses DOES NOT press the button, loop and execute the following code
  
  /*********************************************************************************************************************
  Code to check if the user DOES NOT press the pedestrian button, let the green car traffic light remain on and make 
  pedestrians remain at rest since their light will remain red
  *********************************************************************************************************************/
  
  // Logic for cars traffic light to be Green OR transitioning from Red to Green when loop runs
  digitalWrite(CarRd, LOW); /*turn OFF red traffic light from the previous function before code loops 
   						     in order for the green light to be ON and let cars drive*/
  digitalWrite(PedWht, LOW); /*turn OFF white pedestrian light from the previous function before code loops
  							  in order for the red pedestrian light to turn ON and for the pedestrians to stop walking*/
  
  digitalWrite(CarGrn, HIGH); //turn ON green traffic light in order to start the traffic lights simulation							
  digitalWrite(PedRd, HIGH); /*turn ON red pedestrian light for pedestrians to stop walking and let the cars drive
                              at green and yellow light,to prevent accidents*/ 
  do
  {
     // this loop is empty on purpose
  }while(digitalRead(Btn)==0);
 
  
  /*********************************************************************************************************************
  WalkNow() function runs when the button is pressed, which makes the cars slow down and then NOT move, and pedestrians 
  are IN motion once cars have stopped 
  *********************************************************************************************************************/
  WalkNow();
  
}// end of loop() function


/*********************************************************************************************************************
WalkNow Function:
- Let cars traffic light turn yellow (cars are slowing down) first,then transition to red and pedestrian light be white
*********************************************************************************************************************/
void WalkNow()
{
  /*********************************************************************************************************************
  Code to check if the user DOES press the pedestrian button, let the traffic lights for cars turn yellow and shortly 
  transition to red, therefore cars stop driving, and the white pedestrian light turns on to allow them to walk safely
  *********************************************************************************************************************/
  // if user presses the button, leave the loop in loop() and execute the following code
  
  delay(LEDdelay2);// make the pedestrians wait before the traffic lights transition (from green to yellow)
  
  // Logic for cars traffic light transitioning from Green to Yellow
  digitalWrite(CarGrn, LOW); //turn OFF green light in order for the traffic light to transition to yellow
  
  digitalWrite(CarYlw, HIGH);//turn ON yellow light to make cars slow down as they drive past/approach the traffic light
  /*Let the red pedestrian light remain ON from the else statement since cars might still be in motion. 
  Therefore, we don't need to call the function again*/
  
  delay(LEDdelay2); //allow cars to slow down and make pedestrians remain at rest, within the time
    
  // Logic for cars traffic light transitioning from Yellow to Red 
  digitalWrite(CarYlw, LOW); /*turn OFF yellow traffic light from the previous function
  						      in order for the red light to be ON and stop cars from driving*/
  digitalWrite(PedRd, LOW); /*turn OFF red pedestrian light from the previous function 
  							 in order for the white pedestrians light to turn ON and let the pedestrians walk*/  
  
  digitalWrite(CarRd, HIGH); //turn ON red traffic light in order for cars to stop
  digitalWrite(PedWht, HIGH); /*turn ON white pedestrian light in order for the pedestrians to 
  							   walk safely to the other side before cars can drive*/ 
  
  delay(LEDdelay3); //allow pedestrians to walk and make cars stop, within the time

}
