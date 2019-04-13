/*welkom bij mijn eerst post op github

LET OP WEERSTANDEN BIJ DE PLUS VAN DE LED'S
  
piezo 
plus 4 (PWM)
gnd gnd

beelscherm
scl 21 communication
sda 20 communication
vcc 5v
gnd gnd

led rood 8 gnd gnd
led blauw 6 gnd gnd
led groen 3 gnd gnd

servo 
5v
gnd gnd
7 (PWM)

3,3v 3,3v
rst 5 (PWM)
gnd gnd
miso 50 (DIGITAL)
mosi 51 (DIGITAL)
sck 52 (DIGITAL)
sda 53 (DIGITAL)
*/
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>


Servo myservo;  //creates servo to control

const int rs = 44, en = 45, d4 = 46, d5 = 47, d6 = 49, d7 = 48;
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int R=3;
int G=8;
int B=6;

void setup() 
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  
  lcd.begin(16, 2);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Place your card near reader");
  lcd.print("Place your card");
  lcd.print("lace your card");
  lcd.print("ace your card");
  lcd.print("ce your card");
  lcd.print("e your card");
  lcd.print(" ");
  lcd.print("your card");
  lcd.print("our card");
  lcd.print("ur card");
  lcd.print("r card");
  lcd.print(" card");
  lcd.print("card");
  lcd.print("ard");
  lcd.print("rd");
  lcd.print("d");
  lcd.setCursor(0, 1);
  lcd.print("Near reader");
  lcd.print("ear reader");
  lcd.print("ar reader");
  lcd.print("r reader");
  lcd.print(" reader");
  lcd.print("reader");
  lcd.print("eader");
  lcd.print("ader");
  lcd.print("der");
  lcd.print("er");
  lcd.print("r");
  lcd.setCursor(0, 0);
  myservo.attach(7);//attatches servo to pin 7
  myservo.write(179);
}

void loop() 
{
  analogWrite(B, 255);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  lcd.clear();
  Serial.print("UID tag :");
  lcd.print("ID:");
  lcd.print("D:");
  lcd.print(":");
  byte letter;
  String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     lcd.print(mfrc522.uid.uidByte[i], HEX);
     lcd.print((mfrc522.uid.uidByte[i] & 0x0F) << 4, HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "62 80 E8 1C") //change here the UID of the card/cards that you want to give access
  {
    delay(2000);
    lcd.clear();
    Serial.println("Scanning Database");
    lcd.print("Scanning");
    lcd.print("canning");
    lcd.print("anning");
    lcd.print("nning");
    lcd.print("ning");
    lcd.print("ing");
    lcd.print("ng");
    lcd.print("g");
    lcd.setCursor(0, 1);
    lcd.print("Database");
    lcd.print("atabase");
    lcd.print("tabase");
    lcd.print("abase");
    lcd.print("base");
    lcd.print("ase");
    lcd.print("se");
    lcd.print("e");
    lcd.setCursor(0, 0);
    delay(5000);
    lcd.clear();
        analogWrite(B, 0);
    Serial.print("Authorized access");
     lcd.print("Authorized");
     lcd.print("uthorized");
     lcd.print("thorized");
     lcd.print("horized");
     lcd.print("orized");
     lcd.print("rized");
     lcd.print("ized");
     lcd.print("zed");
     lcd.print("ed");
     lcd.print("d");
    analogWrite(R, 127);
        analogWrite(B, 0);
    tone(4, 900, 100);
    lcd.clear();
    Serial.println("Unlocking...");
    lcd.print("Unlocking...");
    lcd.print("nlocking...");
    lcd.print("locking...");
    lcd.print("ocking...");
    analogWrite(R, 127);
        analogWrite(B, 0);
    lcd.print("cking...");
    lcd.print("king...");
    lcd.print("ing...");
    lcd.print("ng...");
    lcd.print("g...");
    lcd.print("...");
    lcd.print("..");
    lcd.print(".");
    lcd.clear();
    analogWrite(R, 127);
        analogWrite(B, 0);
    delay(1000);
    myservo.write(100);
    delay(15);
    Serial.println("Unlocked");
    lcd.print("Unlocked");
    lcd.print("nlocked");
    lcd.print("locked");
    lcd.print("ocked");
    lcd.print("cked");
    lcd.print("ked");
    lcd.print("ed");
    lcd.print("d");
    delay(5000);
    lcd.clear();
    analogWrite(R, 127);
        analogWrite(B, 0);
    Serial.println("Relocking...");
    lcd.print("Relocking...");
    lcd.print("elocking...");
    lcd.print("locking...");
    lcd.print("ocking...");
    lcd.print("cking...");
    lcd.print("king...");
    lcd.print("ing...");
    lcd.print("ng...");
    lcd.print("g...");
    lcd.print("...");
    lcd.print("..");
    lcd.print(".");
    delay(1000);
    lcd.clear();
    analogWrite(G, 127);
        analogWrite(B, 0);
    myservo.write(179);
    delay(15);
    Serial.println("Locked");
    lcd.print("Locked");
    lcd.print("ocked");
    lcd.print("cked");
    lcd.print("ked");
    lcd.print("ed");
    lcd.print("d");
    analogWrite(R, 127);
    delay(100); 
    lcd.clear();
    analogWrite(R, 0);
    analogWrite(G, 0);
  }else{
    delay(1000);
    lcd.clear();
    Serial.println("Scanning Database");
    lcd.print("Scanning");
    lcd.print("canning");
    lcd.print("anning");
    lcd.print("nning");
    lcd.print("ning");
    lcd.print("ing");
    lcd.print("ng");
    lcd.print("g");
    lcd.setCursor(0, 1);
    lcd.print("Database");
    lcd.print("atabase");
    lcd.print("tabase");
    lcd.print("abase");
    lcd.print("base");
    lcd.print("ase");
    lcd.print("se");
    lcd.print("e");
    lcd.setCursor(0, 0);
    delay(5000);
    lcd.clear();
    Serial.println("Access denied");
    lcd.print("Access denied");
    lcd.print("ccess denied");
    lcd.print("cess denied");
    lcd.print("ess denied");
    lcd.print("ss denied");
    lcd.print("s denied");
    lcd.print(" denied");
    lcd.print("denied");
    lcd.print("enied");
    lcd.print("nied");
    lcd.print("ied");
    lcd.print("ed");
    lcd.print("d");
    analogWrite(B, 0);
    tone(4, 900, 1000);
    analogWrite(G, 255);
    delay(500);
    analogWrite(G, 0);
    delay(500);
    tone(4, 1900, 1000);
    analogWrite(G, 255);
    delay(500);
    analogWrite(G, 0);
    delay(500);
    tone(4, 900, 1000);
    analogWrite(G, 255);
    delay(500);
    analogWrite(G, 0);
    delay(500);
    tone(4, 1900, 1000);
    analogWrite(G, 255);
    delay(500);
    analogWrite(G, 0);
    delay(500);
    tone(4, 900, 1000);
    analogWrite(G, 255);
    delay(500);
    analogWrite(G, 0);
    delay(500);
    tone(4, 1900, 1000);
    analogWrite(G, 255);
    delay(500);
    analogWrite(G, 0);
    delay(100);
  }
 lcd.clear();
   Serial.println("Place your card near reader");
  lcd.print("Place your card");
  lcd.print("lace your card");
  lcd.print("ace your card");
  lcd.print("ce your card");
  lcd.print("e your card");
  lcd.print(" ");
  lcd.print("your card");
  lcd.print("our card");
  lcd.print("ur card");
  lcd.print("r card");
  lcd.print(" card");
  lcd.print("card");
  lcd.print("ard");
  lcd.print("rd");
  lcd.print("d");
  lcd.setCursor(0, 1);
  lcd.print("Near reader");
  lcd.print("ear reader");
  lcd.print("ar reader");
  lcd.print("r reader");
  lcd.print(" reader");
  lcd.print("reader");
  lcd.print("eader");
  lcd.print("ader");
  lcd.print("der");
  lcd.print("er");
  lcd.print("r");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
   Serial.println (" ");
}
