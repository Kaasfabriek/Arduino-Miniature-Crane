int vorige = 0;
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
  Serial1.println ("AT+NAME=RIJWERK");
  delayGrab();
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
    uit();
    if(reading == "#b=1#"){
      digitalWrite(3, 1);
      vorige = 1;
    }else if(reading == "#b=17#" || reading == "#b=71#"){
      digitalWrite(3, 1);
      digitalWrite (2, 1);
      vorige = 2;
    }else if(reading == "#b=19#" || reading == "#b=91#"){
      digitalWrite(3, 1);
      digitalWrite (8, 1);
      vorige = 3;
    }else if(reading == "#b=1A#" || reading == "#b=A1#"){
      digitalWrite(3, 1);
      digitalWrite (10, 1);
      vorige = 4;
    }else if(reading == "#b=18#" || reading == "#b=81#"){
      digitalWrite(3, 1);
      digitalWrite (11, 1);
      vorige = 5;
    }
    else if(reading == "#b=2#"){
      digitalWrite(5, 1);
      vorige = 6;
    }else if(reading == "#b=27#" || reading == "#b=72#"){
      digitalWrite(5, 1);
      digitalWrite (2, 1);
      vorige = 7;
    }else if(reading == "#b=29#" || reading == "#b=92#"){
      digitalWrite(5, 1);
      digitalWrite (8, 1);
      vorige = 8;
    }else if(reading == "#b=2A#" || reading == "#b=A2#"){
      digitalWrite(5, 1);
      digitalWrite (10, 1);
      vorige = 9;
    }else if(reading == "#b=28#" || reading == "#b=82#"){
      digitalWrite(5, 1);
      digitalWrite (11, 1);
      vorige = 10;
    }
    else if(reading == "#b=3#"){
      digitalWrite (6, 1);
      vorige = 11;
    }else if(reading == "#b=37#" || reading == "#b=73#"){
      digitalWrite (6, 1);
      digitalWrite (2, 1);
      vorige = 12;
    }else if(reading == "#b=39#" || reading == "#b=93#"){
      digitalWrite (6, 1);
      digitalWrite (8, 1);
      vorige = 13;
    }else if(reading == "#b=3A#" || reading == "#b=A3#"){
      digitalWrite (6, 1);
      digitalWrite (10, 1);
      vorige = 14;
    }else if(reading == "#b=38#" || reading == "#b=83#"){
      digitalWrite (6, 1);
      digitalWrite (11, 1);
      vorige = 15;
    }
    else if(reading == "#b=4#"){
      digitalWrite (7, 1);
      vorige = 16;
    }else if(reading == "#b=47#" || reading == "#b=74#"){
      digitalWrite (7, 1);
      digitalWrite (2, 1);
      vorige = 17;
    }else if(reading == "#b=49#" || reading == "#b=94#"){
      digitalWrite (7, 1);
      digitalWrite (8, 1);
      vorige = 18;
    }else if(reading == "#b=4A#" || reading == "#b=A4#"){
      digitalWrite (7, 1);
      digitalWrite (10, 1);
      vorige = 19;
    }else if(reading == "#b=48#" || reading == "#b=84#"){
      digitalWrite (7, 1);
      digitalWrite (11, 1);
      vorige = 20;
    }
    else if(reading == "#b=7#"){ 
      digitalWrite (2, 1);
      vorige = 21;
    }else if(reading == "#b=9#"){
      digitalWrite (8, 1);
      vorige = 22;
    }else if(reading == "#b=A#"){
      digitalWrite (10, 1);
      vorige = 23;
    }else if(reading == "#b=8#"){
      digitalWrite (11, 1);
      vorige = 24;
    }
    
    else {
    
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

void uit() {
  digitalWrite (3, 0);
      digitalWrite (5, 0);
      digitalWrite (6, 0);
      digitalWrite (7, 0);
      digitalWrite (2, 0);
      digitalWrite (8, 0);
      digitalWrite (10, 0);
      digitalWrite (11, 0);
}


