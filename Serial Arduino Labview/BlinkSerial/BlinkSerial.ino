/*
  Change Blink based on Serial input

 */

String inString = "";     // string to hold input
int delay_ms = 100;       // LED blinking delay in ms 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);  // open and set serial to 9600 bps
}

// the loop function runs over and over again forever
void loop() {
   // Read incoming string until hit \n 
   while (Serial.available() > 0) {
    int inChar = Serial.read();  
    if (inChar != '\n') { 
      // As long as the incoming byte
      // is not a newline,
      // convert the incoming byte to a char
      // and add it to the string
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value as a float:
    else {
      Serial.print("Input string: ");
      Serial.print(inString);
      Serial.print("\nAfter conversion to float:");
      Serial.println(inString.toFloat());   // Convert string to float
      delay_ms = inString.toInt();          // Convert string to int
      // clear the string for new input:
      inString = "";
    }
  }
 
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delay_ms);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(delay_ms);              // wait for a second
  Serial.print("Blinking rate: ");
  Serial.println(delay_ms);
  
}
