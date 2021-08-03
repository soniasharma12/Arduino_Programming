/*
 
Programmer: Sonia Sharma
Date Created: June 21st, 2021
Program: Awesomeness Project; Grey Matter Mind Game
Description: This program is a mind game! User has to slide the switch in order to start the game. Once the switch is slid, 
			 user has to pay attention to whcih LED(s) turns on, and has to press the button corresponding to that LED. 
             If the user chooses the correct LED pattern, they'll gain a point. If the user does not choose the right LED, 
             they'll lose a life. User has 16 lives until the game is over.

Library Credits: Library originally added 18 Apr 2008 by David A. Mellis
		 Library modified 5 Jul 2009 by Limor Fried
 
*/

/*****************************************************************************************************************************
Pins: Connected to pins 3,4,5,7,8,9,11,12,13,A1,A2,A4,5V,GND
Components: 3 Pushbuttons(input), 3 LEDs(output), 1 Slide Switch(input), 2 Resistors with a value of 220R & 1k R, &
			LiquidCrystal Display(output)
*****************************************************************************************************************************/


/****************************************************************************************************************************
Functions Used: setup(), loop(), DisplayScore(), ReduceLives(), GameOver()
Conditions Used: if...else, for loops
****************************************************************************************************************************/


/*****************************************************************************************************************************
Libraries Used: LiquidCrystal 
*****************************************************************************************************************************/
// import the LiquidCrystal library module
#include<LiquidCrystal.h>


/****************************************************************************************************************************
Global Variables & Constants: Initialize variables to their pin values
****************************************************************************************************************************/
LiquidCrystal lcd(9,8,7,6,5,4);// initialize the library with the numbers of the interface pins

byte randNum;// this variable will randomly turn on any of the LEDs
byte score=0;// this variable stores the user's score; increments/decrements based on the user's performance
byte lives=16;// this variable stores the amount of lives the user has left until the game ends
byte array[256];// this variable stores an array till 256 

bool buttonState;// this variable represents if the button is pressed by the user

// Initialize buttons as boolean values for conditions
bool RedBtn;
bool GreenBtn;
bool BlueBtn;

const int slideSwitch = 3;// initialize slide switch to pin 3

const int RedLED =13;// initialize red LED to pin 13
const int GreenLED =12;// initialize green LED to pin 12
const int BlueLED =11;// initialize blue LED to pin 11


byte heart[8]= // heart graphic
{// this array variable represents the heart graphic, which will represent the amount of lives user has
  B00000,// turn off all pixels in this row
  B00000,// turn off all pixels in this row 
  B01010,// turn on 2nd and 4th pixel in this row
  B11111,// turn on all pixels in this row
  B01110,// turn on 2nd,3rd, & 4th pixel in this row
  B00100,// turn on middle pixel in this row
  B00000,// turn off all pixels in this row
  B00000,// turn off all pixels in this row
  
};// end of heart graphic


/****************************************************************************************************************************
Setup Function - this code runs once and is used to setup stuff 
****************************************************************************************************************************/
void setup()
{
  pinMode(RedLED, OUTPUT);// setup red LED as an output
  pinMode(GreenLED, OUTPUT);// setup green LED as an output
  pinMode(BlueLED, OUTPUT);// setup blue LED as an output
  
  pinMode(A1, INPUT_PULLUP);// setup red LED's pushbutton as an input pullup
  pinMode(A2, INPUT_PULLUP);// setup green LED's pushbutton as an input pullup
  pinMode(A4, INPUT_PULLUP);// setup blue LED's pushbutton as an input pullup
  
  pinMode(slideSwitch, INPUT_PULLUP);// set up slide switch as an input pullup
 
  randomSeed(analogRead(0));// allows to randomly generate numbers 
  lcd.begin(16,2);// set up the LCD's number of columns and rows
  
}// end of setup() function


/****************************************************************************************************************************
Loop Function - loops the code within the body & runs forever
****************************************************************************************************************************/
void loop()
{
  lcd.clear();// clear any graphics or displays on the LCD 
  
  if(digitalRead(slideSwitch)==LOW)
  {// while the slide switch is switched to the RIGHT, execute the following code
    
    DisplayScore();// call function to display score
    
    for(int i=0 ; i<score ;i++)
    {// increment i as long as it's less than score, and run the following loop
      randNum = random(1,4);// generate a random number from the range of 1-3
      array[i]=randNum;// let the array variable at i store the value of the randomly generated number
    
      delay(100);
      /*
      Logic for turn the LEDs ON:
      - at position randNum(from 1-3), add 10 to it to digitally read the pin at that postion
      e.g
      if the randNum==1, add 10, which equals 11, and read the LED pin at the total's position. This goes for each number from 1-3
      1 + 10 = 11, therefore digitalWrite(11, HIGH) which is the Blue LED
      2 + 10 = 12, therefore digitalWrite(12, HIGH) which is the Green LED
      3 + 10 = 13, therefore digitalWrite(13, HIGH) which is the Red LED
      */
      digitalWrite(randNum+10,HIGH);// randomly turn ON anyone 1 of the 3 LEDs
      delay(450);// let the LED remain on for 0.45 seconds
      digitalWrite(randNum+10,LOW);// turn OFF the LED
      delay(200);// let the LED remain off for 0.2 seconds
   
    }// end of for loop
  
    for(int j=0 ; j<score ;)
    {// as long as j is less than the user's score, execute the following loop
      
      RedBtn = digitalRead(A1);// store pin A1 to red button
      GreenBtn = digitalRead(A2);// store pin A2 to green button
      BlueBtn = digitalRead(A4);// store A4 to blue button
      
      if(array[j]==1&&RedBtn&&GreenBtn&&!BlueBtn)
      {//if the randomly generated number at position j is 1 & user presses the correct button(BlueBtn), execute the following
        j++;
      }// end of if statement
    
      else if(array[j]==2&&RedBtn&&!GreenBtn&&BlueBtn)
      {// else, if the randomly generated number at position j is 2 & user presses the correct button(GreenBtn), execute the following
        j++;// increment j by 1; this will increase user's score and allow them to complete the next pattern
      }// end of else if statement
    
      else if(array[j]==3&&!RedBtn&&GreenBtn&&BlueBtn)
      {// else,if the randomly generated number at position j is 3 & user presses the correct button(RedBtn), execute the following
        j++;
      }// end of else if statement
    
      else if(RedBtn&&GreenBtn&&BlueBtn)
      {// else if none of the buttons are pressed, execute the following code
        continue;// skip the conditions above in the for loop and continue with the next iteration
      }// end of else if statement
    
      else
      {// else if the user selects the wrong button, execute the following code
        lives--;// decrement lives by 1
		if(lives)
        {// if the user still has lives
          ReduceLives();// call function to display amount of lives left
        }// end of if statement
      
        else
        {
          buttonState=false;
        }// end of else statement
      
        break;// leave the loop
        
      }// end of else statement
    
      delay(100);// display screen for 0.1 seconds
    
    }// end of for loop
    
    buttonState = true, RedBtn, BlueBtn, GreenBtn;
    if(buttonState)
    {// if the button is pressed, execute the following code
      score++;// increment the score by 1
      DisplayScore();// call this function to display the user's score
    }// end of if statement
    
    else
    {
      score = 0;
      lives = 16;
      buttonState = true;
      GameOver();// call this function to display game over prompt
    }// else statement
    
  }// end of while

  if(digitalRead(slideSwitch)==HIGH)
  {// if the slide switch is switched to the LEFT, execute the following code
    lcd.clear();// clear any graphics/words on the LCD
    lcd.setCursor(1,0);// set cursor to column 0, row 0 (top left)
    lcd.print("-Memory Game-");// print this statement
    lcd.setCursor(0,1);// set cursor to column 0, row 1
    lcd.print("Slide Switch..");// print this statement
    delay(2000);// display message for 2 seconds
  }// end of if statement
  
}// end of loop() function


/****************************************************************************************************************************
ReduceLives Function - this function stores and displays the amount of lives the user has left
****************************************************************************************************************************/
void ReduceLives()
{
  lcd.clear();// clear any graphics/words on the LCD
  lcd.createChar(0,heart);// create heart graphic to represent amount of lives user has left
  
  for(int i=0 ; i<lives ;i++)
  {// as long as i is less than the user's lives, increment it by 1 and execute the following loop
    int x = i;// store i's value in variable x
    lcd.setCursor(x,1);// set cursor to column x, row 0
    lcd.write((byte)0);// display heart graphic of lives
    x--;// decrement heart graphic by 1 each time user gets the pattern incorrect
  }// end of for loop
  
  lcd.setCursor(0,0);// set cursor to column 0, row 1
  lcd.print(lives);// display the amount of lives user has left
  lcd.print(" lives left");// print this statement
  delay(1500);// display this message for 1.5 seconds
  score--;// decrement user's score by 1

}// end of reduceLives() function


/****************************************************************************************************************************
DisplayScore Function - this function displays the user's score
****************************************************************************************************************************/
void DisplayScore()
{
  lcd.clear();// clear any graphics/words on the LCD
  lcd.setCursor(1,0);// set cursor to column 1, row 0
  lcd.print("-Score Board-");// print this statement 
  lcd.setCursor(7,1);// set cursor to column 7, row 1
  lcd.print(score-1);// display user's score -1
  
}// end of displayScore() function


/****************************************************************************************************************************
GameOver Function - this function is called when the user has 0 lives left and lost the game
****************************************************************************************************************************/
void GameOver()
{
    lcd.clear();// clear any graphics/words on the LCD
    lcd.setCursor(2,0);// set cursor to column 3, row 0
    lcd.print("Game Over!");// print this statement
    delay(1000);// display message for 1 second
  
}// end of gameOver() function
