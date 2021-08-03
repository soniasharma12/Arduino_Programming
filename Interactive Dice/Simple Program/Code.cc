/*

Programmer: Sonia Sharma
Date Created: June 9th, 2021
Program: Interactive Dice Simple Program
Description: This program allows the user to roll the dice until button is pressed by them, and then will display a 
			 dice face for 3 seconds
             
*/


/*******************************************************************************************************************************
Pins: Connected to pins 13, 12, 11, 5, 4, 3, 2, A1, GND, and 5V
Components: 7 LEDs, 8 Resistors with a value of 1k R, and 1 push button
*******************************************************************************************************************************/


/******************************************************************************************************************************
Global Variables & Constants: Initialize each LED and button to their pin values, and delay times when displaying/transitioning 
							  between each face.
******************************************************************************************************************************/
const int LED1 = 13;// initialize LED 1 to pin 13
const int LED2 = 12;// initialize LED 2 to pin 12
const int LED3 = 11;// initialize LED 3 to pin 11
const int LED4 = 5;// initialize LED 4 to pin 5
const int LED5 = 4;// initialize LED 5 to pin 4
const int LED6 = 3;// initialize LED 6 to pin 3
const int LED7 = 2;// initialize LED 7 to pin 2

int button = A1;// initialize push button to analog pin A1
int viewTime = 3000;// allow the user to view the face of the dice for 3 seconds
int animationTime= 100;// transition time of 0.1 seconds between each face(LEDs) to indicate the dice is rolling
byte randNum;// this variable will store the randomly generated number of the dice face 

/******************************************************************************************************************************
Functions Used: setup(), loop(), DiceAnimation(), Face1(), Face2(), Face3(), Face4(), Face5(),Face6(),  
Conditions Used: if...else, while loop
******************************************************************************************************************************/


/******************************************************************************************************************************
Setup Function - this code runs once and is used to setup stuff(initialize pin modes)
******************************************************************************************************************************/
void setup()
{
  pinMode(LED1, OUTPUT);// set LED 1 as an output
  pinMode(LED2, OUTPUT);// set LED 2 as an output
  pinMode(LED3, OUTPUT);// set LED 3 as an output
  pinMode(LED4, OUTPUT);// set LED 4 as an output
  pinMode(LED5, OUTPUT);// set LED 5 as an output
  pinMode(LED6, OUTPUT);// set LED 6 as an output
  pinMode(LED7, OUTPUT);// set LED 7 as an output
  pinMode(button, INPUT);// set button as an input
  randomSeed(analogRead(0));/*used to randomly generate the dice faces. Grab the value from A0 and use it as the seed;
  							with nothing connected to analong pin A0, the pin will float between values 0 to 1023*/
    
}// end of setup() function


/******************************************************************************************************************************
Loop Function - loops the code within the body & runs forever
******************************************************************************************************************************/
void loop()
{

  DiceAnimation();// run the dice animation; LEDs transition in ascending order 
  
  /****************************************************************************************************************************
  Code for when the button is ON: If the button IS pressed by the user, run the following code
  ****************************************************************************************************************************/
  while(digitalRead(button) == HIGH)
  {// while the button is pressed, execute the following conditions
    randNum = random(1,7);// generate a random number from the range of 1-6(numbers through 1-6 represents each face of the dice) 
  
  	if(randNum == 1)
  	{// if the user lands on face 1, call Face1 function
      Face1();
  	}
  
  	else if(randNum == 2)
  	{// else if the user lands on face 2, call Face2 function
      Face2();
  	}
  
  	else if(randNum == 3)
  	{// else if the user lands on face 3, call Face3 function
      Face3();    
  	}
  
  	else if(randNum == 4)
  	{// else if the user lands on face 4, call Face4 function
      Face4();     
  	}
  
  
  	else if(randNum == 5)
  	{// else if the user lands on face 5, call Face5 function
      Face5();     
  	}
  
  	else
  	{// else if the user lands on face 6, call Face6 function
      Face6();   
  	}
    
    delay(viewTime);// allow user to view the face of the dice when rolled for 3 seconds 
    
  }// end of if statement  

}// end of loop() function


/******************************************************************************************************************************
Face 1 Function - Middle LED light (LED4) will turn ON if user ROLLS a 1, and rest of the LEDs are OFF
******************************************************************************************************************************/
void Face1()
{
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);// turn on LED
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);  
}// end of Face1 function


/******************************************************************************************************************************
Face 2 Function - 2 LEDs diagonal(LED2 and LED5) will turn ON if user ROLLS a 2, and rest of the LEDs are OFF
******************************************************************************************************************************/
void Face2()
{
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);// turn on LED
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);// turn on LED
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);  
}// end of Face2 function


/******************************************************************************************************************************
Face 3 Function - 3 LEDs diagonal(LED3, LED4, and LED5) will turn ON if user ROLLS a 3, and rest of the LEDs are OFF
******************************************************************************************************************************/
void Face3()
{
  digitalWrite(LED1, HIGH);// turn on LED
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);// turn on LED
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, HIGH);// turn on LED
}// end of Face3 function


/******************************************************************************************************************************
Face 4 Function - 4 LEDs(LED1, LED3, LED5, LED7 ) will turn ON if user ROLLS a 4, and rest of the LEDs are OFF
******************************************************************************************************************************/
void Face4()
{
  digitalWrite(LED1, HIGH);// turn on LED
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);// turn on LED
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);// turn on LED
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, HIGH); // turn on LED
}// end of Face4 function


/******************************************************************************************************************************
Face 5 Function - 5 LEDs(LED1, LED3, LED4, LED5, LED7) will turn ON if user ROLLS a 5, and rest of the LEDs are OFF
******************************************************************************************************************************/
void Face5()
{
  digitalWrite(LED1, HIGH);// turn on LED
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);// turn on LED
  digitalWrite(LED4, HIGH);// turn on LED
  digitalWrite(LED5, HIGH);// turn on LED
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, HIGH); // turn on LED
}// end of Face5 function


/******************************************************************************************************************************
Face 6 Function - 6 LEDs(LED1, LED2, LED3, LED5, LED6, LED7) will turn ON if user ROLLS a 6, and rest of the LEDs are OFF
******************************************************************************************************************************/
void Face6()
{
  digitalWrite(LED1, HIGH);// turn on LED
  digitalWrite(LED2, HIGH);// turn on LED
  digitalWrite(LED3, HIGH);// turn on LED
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);// turn on LED
  digitalWrite(LED6, HIGH);// turn on LED
  digitalWrite(LED7, HIGH); // turn on LED  
}// end of Face6 function


/******************************************************************************************************************************
DiceAnimation Function - This function displays the dice face, which turns on the indicated LEDs for that specific face,
						 as it changes every 0.005 seconds to indicate to the user that the dice is currenlty rolling
******************************************************************************************************************************/
void DiceAnimation()
{
  Face1();// display dice pattern for Face 1; turn on the LEDs indicated within the Face1 function
  delay(animationTime);// change face every 0.1 seconds
  
  Face2();// display dice pattern for Face 2; turn on the LEDs indicated within the Face2 function
  delay(animationTime);// change face every 0.1 seconds
  
  Face3();// display dice pattern for Face 3; turn on the LEDs indicated within the Face3 function
  delay(animationTime);// change face every 0.1 seconds
  
  Face4();// display dice pattern for Face 4; turn on the LEDs indicated within the Face4 function
  delay(animationTime);// change face every 0.1 seconds
  
  Face5();// display dice pattern for Face 5; turn on the LEDs indicated within the Face5 function  
  delay(animationTime);// change face every 0.1 seconds
  
  Face6();// display dice pattern for Face 6; turn on the LEDs indicated within the Face6 function
  delay(animationTime);// change face every 0.1 seconds
}// end of DiceAnimation function
