#include <Keyboard.h>
const int key[5] = {2, 3, 4, 5, 6};
unsigned long timestart;
int marcokey = 0;
void setup() {
  for (int i = 0; i < 5; i++)
  {
    pinMode(key[i], INPUT);
  }
  //Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < 5; i++)
  {
    if (digitalRead(key[i]) == 1)
    {
      if (millis() - timestart > 200)
      {
        timestart = millis();
        marcokey = i + 1;
        //Serial.println(marcokey);
        switch (marcokey)
        { case 0:
            break;
          case 1: //2
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press('m');
            Keyboard.releaseAll();
            break;
          case 2: //3
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press('d');
            Keyboard.releaseAll();
            break;
          case 3: //4
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press('s');
            Keyboard.releaseAll();
            break;
          case 4: //5
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('m');
            Keyboard.releaseAll();
            break;
          case 5: //6
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_DELETE);
            Keyboard.releaseAll();
            break;
          default:
            marcokey = 0;
            break;
        }
      }
    }
  }
}
