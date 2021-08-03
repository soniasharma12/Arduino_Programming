/*
 
Programmer: Sonia Sharma
Date Created: June 15th, 2021
Program: Awesomeness Project; Card Generator
Description: This program generates any card from the card deck! User has to slide the switch to the right in 
			 order to start the program and to shuffle the cards. Once the user presses the push button, the LCD will display
             a random generated with its number and suit, and will turn on the LED colour corresponding to the suit colour. 

Library Credits: Library originally added 18 Apr 2008 by David A. Mellis
		 Library modified 5 Jul 2009 by Limor Fried
         
*Note: court refers to face cards with a King, Queen, or Jack*
 
*/

/*****************************************************************************************************************************
Pins: Connected to pins 1,2,3,4,5,8,9,10,11,12,A1,5V,GND
Components: 1 Button(input), 1 Slide switch(input), 5 resistors with a value of 220R & 1kR, 1 RGB LED(output),
			& LiquidCrystal Display(output)
*****************************************************************************************************************************/


/****************************************************************************************************************************
Functions Used: setup(), loop(), CardNum(), CardSuit(), CardAnimation(), RGBColour()
Conditions Used: while, if...else
****************************************************************************************************************************/


/*****************************************************************************************************************************
Libraries Used: LiquidCrystal 
*****************************************************************************************************************************/
// import the LiquidCrystal library module
#include<LiquidCrystal.h>


/****************************************************************************************************************************
Global Variables & Constants: Initialize variables to their pin values
****************************************************************************************************************************/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// initialize the library with the numbers of the interface pins

const int slideSwitch = 1;// initialize slide switch to pin 
const int button = A1;// initialize push button to analog pin A1

byte randNum; // this variable displays the randomly generated number of the card
byte randNumSuit;// this variable displays the randomly generated suit of the card

const int R = 10;// initialize red pin of the RGB LED to digital pin 10
const int B = 9;// initialize blue pin of the RGB LED to digital pin 9
const int G = 8;// initialize green pin of the RGB LED to digital pin 8

// Initialize 4 array variables, of byte type, to create each suit
byte spades[8]=
{// this array variable represents spades
  B00100,// turn ON middle pixel in this row 
  B01110,// turn ON 2nd, 3rd, & 4th pixels in this row 
  B11111,// turn ON all pixels in this row 
  B11111,// turn ON all pixels in this row 
  B11111,// turn ON all pixels in this row 
  B00100,// turn ON middle pixel in this row
  B00100,// turn ON middle pixel in this row
  B01110,// turn ON 2nd, 3rd, & 4th pixels in this row 
  
};// spades variable

byte clubs[8]= 
{// this array variable represents clubs
  B00000,// all pixels are OFF in this row
  B01110, // turn ON 2nd, 3rd, & 4th pixels in this row 
  B01110,// turn ON 2nd, 3rd, & 4th pixels in this row 
  B11111,// turn ON all pixels in this row 
  B11111,// turn ON all pixels in this row 
  B01110,// turn ON 2nd, 3rd, & 4th pixels in this row 
  B00100,// all pixels are OFF in this row
  B01110,// all pixels are OFF in this row
  
};// clovers variable

byte hearts[8]= 
{// this array variable represents hearts
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row 
  B01010,// turn ON 2nd, and 4th pixel in this row
  B11111,// turn ON all pixels in this row 
  B01110,// turn ON 2nd, 3rd, & 4th pixels in this row 
  B00100,// turn ON middle pixel in this row
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  
};// hearts variable

byte diamonds[8]=
{// this array variable represents diamonds
  B00000,// all pixels are OFF in this row
  B00100,// turn ON middle pixel in this row 
  B01110,// turn ON 2nd, 3rd, & 4th pixels in this row 
  B11111,// turn ON all pixels in this row 
  B01110,// turn ON 2nd, 3rd, & 4th pixels in this row 
  B00100,// turn ON middle pixel in this row
  B00000,// all pixels are OFF in this row
  B00000,// all pixels are OFF in this row
  
};// diamonds variable


/****************************************************************************************************************************
Setup Function - this code runs once and is used to setup stuff 
****************************************************************************************************************************/
void setup()
{
  pinMode(button, INPUT);// setup push button as an input
  pinMode(slideSwitch, OUTPUT);// setup slide switch as an output
  
  pinMode(R, OUTPUT);// setup red pin of the RGB LED as an output
  pinMode(G, OUTPUT);// setup blue pin of the RGB LED as an output
  pinMode(B, OUTPUT);// setup green pin of the RGB LED as an output
  
  lcd.begin(16,2);// set up the LCD's number of columns and rows
  randomSeed(analogRead(0));/*used to randomly generate a card. Grab the value from A0 and use it as the seed;
  							with nothing connected to analog pin A0, the pin will float between values 0 to 1023*/ 
  
}// end of setup() function


/****************************************************************************************************************************
Loop Function - loops the code within the body & runs forever
****************************************************************************************************************************/
void loop()
{
  lcd.createChar(1, spades);// create a graphic for SPADES at the array value the variable is stored at
  lcd.createChar(2, clubs);// create a graphic for CLUBS at the array value the variable is stored at
  lcd.createChar(3, hearts);// create a graphic for HEARTS at the array value the variable is stored at
  lcd.createChar(4, diamonds);// create a graphic for DIAMONDS at the array value the variable is stored at
  
  /*---------------------------------------------------------------------------------------------------------------------------
  Code for when the switch is switched to the RIGHT: Run the following code ONLY IF the switch is to the RIGHT 
  ---------------------------------------------------------------------------------------------------------------------------*/
  lcd.clear();// clear any graphics or displays on the LCD before running the following loop
  
  /***********************************************************************************************************************************
  Code for when the button is NOT pressed & switch IS to the RIGHT: If the button IS NOT pressed by the user, execute the following loop
  ***********************************************************************************************************************************/
  while(digitalRead(button)==LOW && digitalRead(slideSwitch)==LOW)
  {
    lcd.setCursor(1,0);// set cursor to column 1, row 0
    lcd.print("Press Button..");// print this statement to prompt the user to press the button to land on a card face
    CardAnimation();// call the card animation function to indicate that the cards are shuffling
    
  }// end of while loop
  
  /************************************************************************************************************************************
  Code for when the button IS pressed & switch IS still to the RIGHT: If the button IS pressed by the user, leave the loop and execute 
  																	  the following code
  ************************************************************************************************************************************/
  if(digitalRead(button)==HIGH && digitalRead(slideSwitch)==LOW)
  {
    lcd.clear();// clear any graphics or displays on the LCD before running the code below
    CardNum();// call this function to display the card's number once the user presses the button
    delay(1000);// display the card face for 1 second
  }// end of if statement
  
  /*---------------------------------------------------------------------------------------------------------------------------
  Code for when the switch is switched to the LEFT: Run the following condition ONLY IF the switch is switched to the LEFT
  ---------------------------------------------------------------------------------------------------------------------------*/
  else
  {
    // turn off RGB LED
    digitalWrite(R,LOW);
  	digitalWrite(G,LOW);
  	digitalWrite(B,LOW);
    
    lcd.clear();// clear the graphics/words off the lcd
    lcd.setCursor(0,0);// set cursor to column 0, row 0
    lcd.print("Card Generator!");// print this message to welcome the user
    lcd.setCursor(0,1);// set the cursor to column 0, row 1
    lcd.print("Slide Switch...");// print this statement to prompt the user to slide the witch in order to shuffle the cards
    delay(2000);// display the above statements for 2 seconds
  }// end of else statement  
  
}// end of loop() function


/****************************************************************************************************************************
 CardNum Function - this function randomly generates a number for the randomly generated card 
****************************************************************************************************************************/
void CardNum()
{
  randNum = random(1,14);// generate a random number from the range of 1-13(cards numbers + court)
  lcd.setCursor(2,0);// set cursor to column2, row 0
  lcd.print("You got...");// print this statement to the display the card face user landed on
  
  // Ace + Court cards conditions
  lcd.setCursor(3,1);// set cursor to column 3, row 1
  
  if(randNum==1)
  {// if the random number generated is a 1, the card is an Ace, and execute the following code
    lcd.print("Ace");// display that the card is an Ace instead of its number
  }// end of if statement
  
  else if(randNum==11)
  {//else if the random number generated is 11, the card is a Jack, and execute the following code
    lcd.print("Jack");// display that the card is a Jack instead of its number
  }// end of else if statement
  
  else if(randNum==12)
  {//else if the random number generated is 12, the card is a Queen, and execute the following code
    lcd.print("Queen");// display that the card is a Queen instead of its number
  }// end of else if statement
  
  else if(randNum==13)
  {//else if the random number generated is 13, the card is a King, and execute the following code
    lcd.print("King");// display that the card is a King instead of its number
  }// end of else if statement
  
  else
  {//else if the random number generated is less than 11 but higher than 1, it's a regular card number, and execute the following code
    lcd.setCursor(4,1);// set cursor to column 4, row 1
    lcd.print(randNum);// display the card number
  }// end of else statement
  
  lcd.print(" of ");// apart of the card statement
  CardSuit();// call this function to display the card's suit
  
}// end of CardNum()


/****************************************************************************************************************************
 CardSuit Function - this function randomly generates a suit for the randomly generated card 
****************************************************************************************************************************/
void CardSuit()
{
  randNumSuit = random(1,5);// generate a random number from the range of 1-4(number through 1-4 represents each suit of a card)
  lcd.write(byte(randNumSuit));// write graphic of the landed card face to the LCD; display suit graphic of the card face the user landed on
  /*
  randNumSuit == 1 will be SPADES
  randNumSuit == 2 will be CLUBS
  randNumSuit == 3 will be HEARTS
  randNumSuit == 4 will be DIAMONDS
  */
  
  if(randNumSuit == 1 || randNumSuit == 2)
  {// if the random suit number generated is a 1 OR 2 (Spades OR Clubs), execute the following code
    RGBColour(0,0,255);// turn RGB LED colour to BLUE
  }// end of if statement
  
  else if (randNumSuit == 3 || randNumSuit == 4)
  {// if the random suit number generated is a 3 OR 4 (Hearts OR Diamonds), execute the following code
    RGBColour(255,0,0);// turn RGB LED colour to RED
  }// end of else if statement
  
  delay(3000);// display card face & LED for 3 seconds
  
}// end of CardSuit()


/****************************************************************************************************************************
 CardAnimation Function - this function displays the card number, its suit, and the colour of its suit(with the LEDs) as it 
 					      changes every 0.1 seconds, to indicate to the user that the cards are currently shuffling
****************************************************************************************************************************/
void CardAnimation()
{
  // LCD animation
  randNum = random(1,11);// generate a random card number from the range of 1-10
  randNumSuit = random(1,5);// generate a random suit number from the range of 1-4 to display any one of the 4 graphics
  lcd.setCursor(4,1);// set cursor to column 4, row 1
  lcd.print(randNum);// display the random generated card number
  lcd.print(" of ");// apart of card statement
  lcd.write(byte(randNumSuit));// display the random generated suit graphic
  lcd.print(" ");// wont allow any graphics/words to display after beyond the suit graphic within row 1
  
  // RGB LED animation
  RGBColour(0,0,255);// turn RGB LED colour to BLUE
  delay(100);// display LEDs for 0.1 seconds
  RGBColour(255,0,0);// turn RGB LED colour to RED
  delay(100);// display LED for 0.1 seconds
  
}// end of CardAnimation()


/****************************************************************************************************************************
 RGBColour Function - this function stores the colour value of each pin through its parameters
 					 1st parameter -> RValue = hue colour value stored at red pin
                     2nd parameter -> GValue = hue colour value stored at green pin
                     3rd parameter -> BValue = hue colour value stored at blue pin
****************************************************************************************************************************/
void RGBColour(int RValue, int GValue, int BValue)
{
  analogWrite(R, RValue);// at red pin(R), store this hue colour value(RValue)
  analogWrite(G, GValue);// at green pin(G), store this hue colour value(GValue)
  analogWrite(B, BValue);// at blue pin(B), store this hue colour value(BValue)

}// end of RGBColour()
