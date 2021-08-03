/*
 
Programmer: Sonia Sharma
Date Created: June 9th, 2021
Program: Interactive Dice Complex Program
Description: This program creates a rolling the dice and allows the user to decrease the tilt sensor to roll the dice and then 
			 press the push button to display a randomly generated dice face they landed on, for 3 seconds
Library Credits: Library originally added 18 Apr 2008 by David A. Mellis
		 Library modified 5 Jul 2009 by Limor Fried
 
*/

/*****************************************************************************************************************************
Pins: Connected to pins 2,3,4,5,9,11,12, A1, 5V, GND
Components: 1 Button(input), 1 Tilt Sensor(input) 3 Resistors with a value of 220R and 1k R, LiquidCrystal Display(output)
-----------------------------------------------------------------------------------------------------------------------

- LCD VCC pin to 5V
- LCD V0, RW, and LED Cathode pins to GND
- LCD RS pin to digital pin 12
- LCD E pin to digital pin 11
- LCD DB4 pin to digital pin 5
- LCD DB5 pin to digital pin 4
- LCD DB6 pin to digital pin 3
- LCD DB7 pin to digital pin 2
- LCD LED Anode pin to 220R Resistor to 5V
- Push Button; Terminal 1b to analog pin A1, Terminal 2 to 1k R Resistor to GND, Terminal 2a to 5V
- Tilt Sensor; Terminal 1 to 1k R Resistor and pin 9, Terminal 2 to GND

Note: The term "face user landed on" means the face of the dice the user rolls that it lands on
*****************************************************************************************************************************/


/****************************************************************************************************************************
Functions Used: setup(), loop()
Conditions Used: while, if...else
****************************************************************************************************************************/


/*****************************************************************************************************************************
Libraries Used: LiquidCrystal 
*****************************************************************************************************************************/
// import the LiquidCrystal library module
#include <LiquidCrystal.h> 

/****************************************************************************************************************************
Global Variables & Constants: Initialize variables to their pin values, and delay times when displaying/transitioning 
							  between each face.
****************************************************************************************************************************/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the library with the numbers of the interface pins

const int button = A1;// initialize push button to analog pin A1
int tiltSensor = 9;// initialize tilt sensor to pin 9
byte randNum;// this variable will display the random generated number of the dice face 
int viewTime = 3000;// allow the user to view the dice face for 3 seconds
int animationTime = 5;// transition time (0.005 seconds) between each dice face when the dice is rolling 

// Initialize 6 array variables, of byte type, to create each face of the dice
byte face1[8]=
{// this array variable represents face 1 of the dice; 1 dot in the middle
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B00100,// the middle pixel in this row is ON 
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row

};// face 1 variable

byte face2[8]=
{// this array variable represents face 2 of the dice; 2 dots in a diagonal pattern 
  B00000,// all pixels are OFF in this row
  B10000,// first pixel in this row is ON 
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B00001,// last pixel in this row is ON 
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row

};// face 2 variable

byte face3[8]=
{// this array variable represents face 3 of the dice; 3 dots in a diagonal pattern 
  B00000,// all pixels are OFF in this row
  B00001,// last pixel in this row is ON 
  B00000,// all pixels are OFF in this row
  B00100,// middle pixel in this row is ON 
  B00000,// all pixels are OFF in this row
  B10000,// first pixel in this row is ON 
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row

};// face 3 variable

byte face4[8]=
{// this array variable represents face 4 of the dice; 4 dots in each corner
  B00000,// all pixels are OFF in this row
  B10001,// first and last pixel in this row are ON 
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  B10001,// first and last pixel in this row are ON 
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row

};// face 4 variable

byte face5[8]=
{// this array variable represents face 4 of the dice
  B00000,// all pixels are OFF in this row
  B10001,// first and last pixel in this row are ON
  B00000,// all pixels are OFF in this row
  B00100,// middle pixel in this row is ON
  B00000,// all pixels are OFF in this row
  B10001,// first and last pixel in this row are ON
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row

};// face 5 variable

byte face6[8]=
{// this array variable represents face 4 of the dice
  B00000,// all pixels are OFF in this row
  B10001,// first and last pixel in this row are ON
  B00000,// all pixels are OFF in this row
  B10001,// first and last pixel in this row are ON
  B00000,// all pixels are OFF in this row
  B10001,// first and last pixel in this row are ON
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row

};// face 6 variable


/****************************************************************************************************************************
Setup Function - this code runs once and is used to setup stuff (CHECK)
****************************************************************************************************************************/
void setup()
{
  pinMode(button, INPUT);// setup pushbutton as an input
  pinMode(tiltSensor, INPUT);// setup tilt sensor as an input
  lcd.begin(16, 2);// set up the LCD's number of columns and rows
  randomSeed(analogRead(0));/*used to randomly generate the dice faces. Grab the value from A0 and use it as the seed;
  							with nothing connected to analong pin A0, the pin will float between values 0 to 1023*/    
  
}// end of setup() function


/****************************************************************************************************************************
Loop Function - loops the code within the body & runs forever
****************************************************************************************************************************/
void loop()
{
  lcd.createChar(1, face1);// create a graphic for FACE 1 at the array value the variable is stored at
  lcd.createChar(2, face2);// create a graphic for FACE 2 at the array value the variable is stored at
  lcd.createChar(3, face3);// create a graphic for FACE 3 at the array value the variable is stored at
  lcd.createChar(4, face4);// create a graphic for FACE 4 at the array value the variable is stored at
  lcd.createChar(5, face5);// create a graphic for FACE 5 at the array value the variable is stored at
  lcd.createChar(6, face6);// create a graphic for FACE 6 at the array value the variable is stored at 
  
  /*---------------------------------------------------------------------------------------------------------------------------
  Code for when the tilt sensor IS TILTED: Run the following code ONLY IF the tilt sensor is TILTED
  ---------------------------------------------------------------------------------------------------------------------------*/
  
  lcd.clear();// clear any graphics or displays on the LCD before running the following loop
  
  /****************************************************************************************************************************
  Code for when the button is NOT pressed & sensor IS tilted: If the button IS pressed by the user, execute the following loop
  ****************************************************************************************************************************/
  while(digitalRead(button)== LOW && digitalRead(tiltSensor)== LOW)
  {
    lcd.setCursor(0, 0);// set cursor to column 0, row 0 (top left)  
    lcd.print("Press to Roll: ");// print this statement to prompt the user to press the button to land on a face
    
    /*********************************************************************************************************************
    Code for dice animation: this body of code displays the dice face and its number, as it changes every 0.005 seconds to 
    						 indicate to the user that the dice is currenlty rolling
    **********************************************************************************************************************/
    randNum = random(1,7);// generate a random number from the range of 1-6(numbers through 1-6 represents each face of the dice)
    lcd.print(randNum);// display the number of the face
    lcd.setCursor(0,1);// set cursor to column 0, row 1 (bottom left)
    lcd.write(byte(randNum));// display the graphic of the random face
    delay(animationTime);// display face for 0.005 seconds
    
  }// end of while loop
  
  /****************************************************************************************************************************
  Code for when the button IS pressed & sensor IS still tilted: If the button IS pressed by the user, leave the loop and execute 
  																the following code
  ****************************************************************************************************************************/
  if(digitalRead(button)== HIGH && digitalRead(tiltSensor)== LOW)
  {
    lcd.clear();// clear any graphics or displays on the LCD before running the code below
    randNum = random(1,7);// generate a random number from the range of 1-6(numbers through 1-6 represents each face of the dice)
    lcd.setCursor(0, 0);// set cursor to column 0, row 0 (top left) 
    lcd.print("You Rolled: ");// print this statement to display the face user landed on
    lcd.print(randNum);// print the number of the face user landed on beside the above print statement 
    lcd.setCursor(0,1);// set cursor to column 0, row 1 (bottom left)
    lcd.write(byte(randNum));// write graphic of the landed face to the LCD; display dice graphic of the face the user landed on
    delay(viewTime);// allow the user to view the face of the dice for 3 seconds
    
  }// end of if statement
  
  
  /*---------------------------------------------------------------------------------------------------------------------------
  Code for when the tilt sensor is NOT TILTED: Run the following condition ONLY IF the tilt sensor is NOT TILTED
  ---------------------------------------------------------------------------------------------------------------------------*/
  else
  {
  	lcd.clear();// clear the graphics/words off the lcd 
    lcd.setCursor(0,0);// set cursor to column 0, row 0 (top left)
    lcd.print("Dice Game!");// print this message to welcome the user
    lcd.setCursor(0,1);// set cursor to column 0, row 1 (bottom left)
    lcd.print("Tilt Sensor...");// print this statement to prompt the user to tilt the tilt sensor in order to roll the dice
   	delay(2000);// display the above statement for 2 seconds
  
  }//  end of else statement
    
}// end of loop() function
