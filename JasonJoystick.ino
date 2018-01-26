#include "Keyboard.h"

const int  MAX_PIN = 13;
const int  LOOP_DELAY = 20; // Lower value causes inputs to be read faster.

int key[] = {
  KEY_LEFT_ARROW,   // Pin 0  Player 1 Left
  KEY_RIGHT_ARROW,  // Pin 1  Player 1 Right
  KEY_DOWN_ARROW,   // Pin 2  Player 1 Down
  KEY_UP_ARROW,     // Pin 3  Player 1 Up
  KEY_LEFT_CTRL,    // Pin 4  Player 1 SW 1
  KEY_LEFT_ALT,     // Pin 5  Player 1 SW 2
  ' ',              // Pin 6  Player 1 SW 3
  KEY_LEFT_SHIFT,   // Pin 7  Player 1 SW 4  
  'z',              // Pin 8  Player 1 SW 5    
  'x',              // Pin 9  Player 1 SW 6
  '1',              // Pin 10 Player 1 Start
  '5',              // Pin 11 Player 1 Coin
  KEY_RETURN,       // Pin 12
  '$',              // Pin 13 
  '[',              // PIN 14 (A0) Unused
  '[',              // PIN 15 (A1) Unused
  '[',              // PIN 16 (A2) Unused
  '[',              // PIN 17 (A3) Unused
  '[',              // PIN 18 (A4) Unused
  '[',              // PIN 19 (A5) Unused
};  
  
int  prevState[MAX_PIN+1];

void setup() 
{ 
  for (int i=0; i <= MAX_PIN; i++)
  {
    pinMode(i, INPUT_PULLUP);
    prevState[i] = HIGH;
  }
  Keyboard.begin();
}

void loop() 
{  
  for (int i=0; i < MAX_PIN; i++)
  {
    int state = digitalRead(i);
    if (state != prevState[i])
    {
      if (state == HIGH)
        Keyboard.release(key[i]);
      else
        Keyboard.press(key[i]);
    }
    prevState[i] = state;
  }
  delay(LOOP_DELAY);
}

