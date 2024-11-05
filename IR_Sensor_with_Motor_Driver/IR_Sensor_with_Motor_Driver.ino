// Arduino Line Follower Robot Code
// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
int IRR = 12;//ir sensor Right
int IRL = 13;//ir sensor Left

void setup(){ 

pinMode(IRR, INPUT); 
pinMode(IRL, INPUT); 
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT); 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 

delay(1000);

}

void loop(){  
//if Right Sensor and Left Sensor are at White color 
if((digitalRead(IRR) == 0)&&(digitalRead(IRL) == 0)){forward();}   
//if Right Sensor is Black and Left Sensor is White  
if((digitalRead(IRR) == 1)&&(digitalRead(IRL) == 0)){turnRight();} 
//if Right Sensor is White and Left Sensor is Black 
if((digitalRead(IRR) == 0)&&(digitalRead(IRL) == 1)){turnLeft();}  
//if Right Sensor and Left Sensor are at Black color 
if((digitalRead(IRR) == 1)&&(digitalRead(IRL) == 1)){Stop();} 
}

void forward(){  //forword
analogWrite(enA, 255); 
analogWrite(enB, 255); 
digitalWrite(in1, HIGH);  
digitalWrite(in2, LOW);  
digitalWrite(in3, HIGH);   
digitalWrite(in4, LOW); 
}

void turnRight(){ //turnRight
analogWrite(enA, 180); 
analogWrite(enB, 0); 
digitalWrite(in1, HIGH);  
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW);   
digitalWrite(in4, LOW);  
}

void turnLeft(){ //turnLeft
analogWrite(enA, 0); 
analogWrite(enB, 180); 
digitalWrite(in1, LOW);  
digitalWrite(in2, LOW);   
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);   
}

void Stop(){ //stop
analogWrite(enA, 0); 
analogWrite(enB, 0); 
digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);
}
