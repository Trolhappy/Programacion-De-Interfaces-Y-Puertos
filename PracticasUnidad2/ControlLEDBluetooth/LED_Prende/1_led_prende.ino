int ledPin = 8;

void setup ()
 { 

Serial.begin(9600) ;
pinMode (ledPin, OUTPUT);
 }

void loop () { 
if (Serial.available ()>0) { 
char data = Serial.read ();
if (data=="1" ) { 


digitalWrite(ledPin, HIGH);
Serial.println("LED ON");
}else if (data =='0') { 
digitalWrite (ledPin, LOW);
Serial.println("LED OFF");

    }
  }
}