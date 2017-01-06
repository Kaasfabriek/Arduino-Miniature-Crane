void setup ()

{
  pinMode (9, OUTPUT); // Deze pin zal de HC-05 pen 34 (key pin) trekken HIGH om module te schakelen naar AT-modus
  pinMode (13, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  digitalWrite (9, HIGH);
  Serial.begin (9600);
  Serial.println ( "Enter AT commando's:");
  Serial1.begin (38400); // HC-05 standaard snelheid in de AT-commando meer
  delayGrab();
  Serial1.println ("AT+ORGL");
  delayGrab();
  Serial1.println ("AT+RESET");
  delayGrab();
  Serial1.println ("AT+ROLE=0");
  delayGrab();
  Serial1.println ("AT+POLAR=1,0");
  delayGrab();
  Serial1.println ("AT+RESET");
  delayGrab();
  delay(3000);
  Serial1.println ("AT+INIT");
  Serial.println ("AT+INIT");
  delayGrab();  
  Serial1.println ("AT+INQ");/**/
  Serial.println ("AT+INQ");
  delayGrab();
  digitalWrite(13, 1);
}

void delayGrab(){
  while (Serial1.available ()) {
    Serial.write (Serial1.read ());
  }
  delay(700);
}

void loop() {
  delay(100);

  String reading = "";
  // put your main code here, to run repeatedly:
  while (Serial1.available ()) {
    char inchar = Serial1.read();
    reading = reading + inchar;
  }

  if(reading != ""){
    Serial.println(reading); 
    if(reading == "#b=1#"){
      digitalWrite(3, 1);
    }else if(reading == "#b=2#"){
      digitalWrite(5, 1);
    }else if(reading == "#b=3#"){
      digitalWrite (6, 1);
    }else if(reading == "#b=4#"){
      digitalWrite (7, 1);
    }else if(reading == "#b=7#"){
      digitalWrite (2, 1);
    }else if(reading == "#b=9#"){
      digitalWrite (8, 1);
    }else if(reading == "#b=A#"){
      digitalWrite (10, 1);
    }else if(reading == "#b=8#"){
      digitalWrite (11, 1);
    } else {
      digitalWrite (3, 0);
      digitalWrite (5, 0);
      digitalWrite (6, 0);
      digitalWrite (7, 0);
      digitalWrite (2, 0);
      digitalWrite (8, 0);
      digitalWrite (10, 0);
      digitalWrite (11, 0);
    }
  }
  // Houd het lezen van Arduino Serial Monitor en te versturen naar HC-05
  while (Serial.available ()) {
    Serial1.write (Serial.read ());
  }

}
