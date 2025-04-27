#include "srv_stdio_keypad.h"
#include <stdio.h>
/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

#define SRV_KEYBOARD_READ_DELAY 100 // 1 second timeout for reading a key

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int srv_stdio_keypad_get_key(FILE *stream) {
  char customKey;
  do {
      customKey = customKeypad.getKey();
  } while (!customKey);

  delay(SRV_KEYBOARD_READ_DELAY); // Debounce delay

  return customKey;
}

void srv_stdio_keypad_setup() {
  // 4. Initializare periferii
  // nu necesita, e initializat prin configuratia de definitie, vezi mai sus

  // 5. Definire stream
  FILE *my_stream = fdevopen(NULL, srv_stdio_keypad_get_key);
  stdin = my_stream;
}
  
