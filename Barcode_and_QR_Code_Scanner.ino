
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// Initialize the library with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Initialize software serial for the barcode scanner
SoftwareSerial mySerial(3, 4); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); // set the data rate for the SoftwareSerial port

  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Print a welcome message to the LCD
  lcd.print("Scan Barcode:");
delay(5000); // Display the message for 5 seconds
}

void loop() {
  if (mySerial.available()) { // Check if there is Incoming Data in the Serial Buffer.
    lcd.clear();
    lcd.setCursor(0, 0); // Set cursor to the first line
    
    while (mySerial.available()) { // Keep reading Byte by Byte from the Buffer till the Buffer is empty
      char input = mySerial.read(); // Read 1 Byte of data and store it in a character variable
      Serial.print(input); // Print the Byte to Serial Monitor
      
      lcd.print(input); // Print the Byte to the LCD
    }
    
    Serial.println();
    delay(5000); // Display the message for 5 seconds
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scan Barcode:");
  }
}
