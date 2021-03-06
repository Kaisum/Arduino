char serialByte = '0';
const byte  LEDPIN = 13; 
const int led2 = 5;

void setup() 
{
    pinMode(LEDPIN, OUTPUT);
 
    // communication with the host computer
    Serial.begin(9600);  
    pinMode(led2,OUTPUT);
    Serial.println("Do not power the BT module");
    Serial.println(" ");
    Serial.println("On the BT module, press the button switch (keep pressed, and at the same time power the BT module");
    Serial.println("The LED on the BT module should now flash on/off every 2 seconds");
    Serial.println("Can now release the button switch on the BT module");
    Serial.println(" ");
    Serial.println("After entering AT mode, type 1 and hit send");
    Serial.println(" ");
 
 
    // wait for the user to type "1" in the serial monitor
    while (serialByte !='1')
    {
        if ( Serial1.available() )   {  serialByte = Serial1.read();  }
    }  
 
 
    // communication with the BT module on serial1
    Serial1.begin(38400);
 
    // LED to show we have started the serial channels
    digitalWrite(LEDPIN, HIGH);  
 
    Serial.println(" ");
    Serial.println("AT mode.");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
    Serial.println("The HC-05 accepts commands in both upper case and lower case");
    Serial.println(" "); 
}
 
 
void loop() 
{
    // listen for communication from the BT module and then write it to the serial monitor
    if ( Serial1.available() )   {  Serial.write( Serial1.read() );  }
    digitalWrite(led2,HIGH);
    // listen for user input and send it to the HC-05
   if ( Serial.available() )   {  Serial1.write( Serial.read() );  }
}
