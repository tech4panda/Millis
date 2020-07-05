#include <millis.h>

void myFunction();

Millis ms(1000);

void setup() {
  Serial.begin(9600); //for debug
}

void loop() {
  ms.toCall(myFunction);
}

void myFunction(){
  Serial.print("time:" + String(int(millis()/1000)));
  //do something
}
