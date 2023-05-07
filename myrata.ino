/* Arduino Mouse Emulation 
 *  
 *  learnelectronics
 *  based on an original sketch by   by: Jim Lindblom date: 1/12/2012
 *  17 MAR 2017
 *  
 *  www.youtube.com/c/learnelectronics
 *  arduino0169@gmail.com
 */

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                              LIBRARY
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Mouse.h>

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                             VARIABLES
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int horzPin = A0;                                                                                 // Analog output of horizontal joystick pin
int vertPin = A1;                                                                                 // Analog output of vertical joystick pin
int selPin0 = 9;                                                                                  //click left
int selPin1 = 8;                                                                                  //low velocity mouse
int selPin2 = 7;                                                                                  //click right
int selPin3 = 6;                                                                                  //Scroll up
int selPin4 = 5;                                                                                  //high velocity mouse
int selPin5 = 4;                                                                                  //Scroll down
int selPin6 = 3;                                                                                  //wheel middle click



int vertZero, horzZero;                                                                           // Stores the initial value of each axis, usually around 512
int vertValue, horzValue;                                                                         // Stores current analog output of each axis
int sensitivity = 100;                                                                      // Higher sensitivity value = slower mouse, should be <= about 500
int velocity = 0;

int mouseClickFlag0 = 0;
int mouseClickFlag1 = 0;
int mouseClickFlag2 = 0;
int mouseClickFlag3 = 0;
int mouseClickFlag4 = 0;
int mouseClickFlag5 = 0;
int mouseClickFlag6 = 0;


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                              SETUP
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  pinMode(horzPin, INPUT);                                                                        // Set both analog pins as inputs
  pinMode(vertPin, INPUT);
  pinMode(selPin0, INPUT);                                                                         // set button select pin as input
  digitalWrite(selPin0, HIGH);                                                                     // Pull button select pin high
  pinMode(selPin1, INPUT);                                                                         // set button select pin as input
  digitalWrite(selPin1, HIGH);                                                                     // Pull button select pin high
  pinMode(selPin2, INPUT);                                                                         // set button select pin as input
  digitalWrite(selPin2, HIGH);                                                                     // Pull button select pin high
  pinMode(selPin3, INPUT);                                                                         // set button select pin as input
  digitalWrite(selPin3, HIGH);                                                                     // Pull button select pin high
  pinMode(selPin4, INPUT);                                                                         // set button select pin as input
  digitalWrite(selPin4, HIGH);                                                                     // Pull button select pin high
  pinMode(selPin5, INPUT);                                                                         // set button select pin as input
  digitalWrite(selPin5, HIGH);                                                                     // Pull button select pin high
  pinMode(selPin6, INPUT);                                                                         // set button select pin as input
  digitalWrite(selPin6, HIGH);                                                                     // Pull button select pin high
  
  delay(1000);                                                                                    // short delay to let outputs settle
  vertZero = analogRead(vertPin);                                                                 // get the initial values
  horzZero = analogRead(horzPin);                                                                 // Joystick should be in neutral position when reading these

}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            MAIN LOOP
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop()
{
  vertValue = analogRead(vertPin) - vertZero;                                                     // read vertical offset
  horzValue = analogRead(horzPin) - horzZero;                                                     // read horizontal offset

/*
  Serial.print("x ");
  Serial.println(horzValue);
  Serial.print("y ");
  Serial.println(vertValue);
 */
 

                                                                                                  // Mouse.move(xpos,ypos,wheel)
                                                                                                  // Mouse.move is always relative to the last position of the mouse cursor

  if (vertValue != 0){
    Mouse.move(0, vertValue/sensitivity, 0);
    delay(velocity);
    }  
    
    // move mouse on y axis
  if (horzValue != 0){
    Mouse.move((horzValue/sensitivity)*-1, 0, 0);
    delay(velocity);
  }                                         // move mouse on x axis
                                                     



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            left click
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    
  if ((digitalRead(selPin0) == 0) && (!mouseClickFlag0))                                            // if the joystick button is pressed
  {
    mouseClickFlag0 = 1;
    Mouse.press(MOUSE_LEFT);                                                                      // click the left button down
  }
  else if ((digitalRead(selPin0))&&(mouseClickFlag0))                                               // if the joystick button is not pressed
  {
    mouseClickFlag0 = 0;
    Mouse.release(MOUSE_LEFT);                                                                    // release the left button
  }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            middle click
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((digitalRead(selPin6) == 0) && (!mouseClickFlag6))                                            // if the joystick button is pressed
  {
    mouseClickFlag6 = 1;
    Mouse.press(MOUSE_MIDDLE);                                                                      // click the left button down
  }
  else if ((digitalRead(selPin6))&&(mouseClickFlag6))                                               // if the joystick button is not pressed
  {
    mouseClickFlag6 = 0;
    Mouse.release(MOUSE_MIDDLE);                                                                    // release the left button
  }


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            right click
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((digitalRead(selPin2) == 0) && (!mouseClickFlag2))                                            // if the joystick button is pressed
  {
    mouseClickFlag2 = 1;
    Mouse.press(MOUSE_RIGHT);                                                                      // click the left button down
  }
  else if ((digitalRead(selPin2))&&(mouseClickFlag2))                                               // if the joystick button is not pressed
  {
    mouseClickFlag2 = 0;
    Mouse.release(MOUSE_RIGHT);                                                                    // release the left button
  }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            scroll up
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((digitalRead(selPin3) == 0) && (!mouseClickFlag3))                                            // if the joystick button is pressed
  {
    mouseClickFlag3 = 1;
    Mouse.move(0, 0, 5);
    delay(10);                                                                                      // click the left button down
  }
  else if ((digitalRead(selPin3))&&(mouseClickFlag3))                                               // if the joystick button is not pressed
  {
    mouseClickFlag3 = 0;
                                                                        // release the left button
  }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            scroll down
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((digitalRead(selPin5) == 0) && (!mouseClickFlag5))                                            // if the joystick button is pressed
  {
    mouseClickFlag5 = 1;
    Mouse.move(0, 0, -5);
    delay(10);                                                                                      // click the left button down                                                                      // click the left button down
  }
  else if ((digitalRead(selPin5))&&(mouseClickFlag5))                                               // if the joystick button is not pressed
  {
    mouseClickFlag5 = 0;                                                                    // release the left button
  }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            high velocity
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((digitalRead(selPin4) == 0) && (!mouseClickFlag4))                                            // if the joystick button is pressed
  {
    mouseClickFlag4 = 1;
    velocity = 0;                                                                      // click the left button down
  }
  else if ((digitalRead(selPin4))&&(mouseClickFlag4))                                               // if the joystick button is not pressed
  {
    mouseClickFlag4 = 0;
                                                                                        // release the left button
  }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                            low velocity
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((digitalRead(selPin1) == 0) && (!mouseClickFlag1))                                            // if the joystick button is pressed
  {
    mouseClickFlag1 = 1;
    velocity = 10;                                                                      // click the left button down
  }
  else if ((digitalRead(selPin1))&&(mouseClickFlag1))                                               // if the joystick button is not pressed
  {
    mouseClickFlag1 = 0;
                                                                                                    // release the left button
  }



  
}
