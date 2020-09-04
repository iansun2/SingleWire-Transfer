#define rx_delay 4

void setup() {
  pinMode(3,INPUT);
  Serial.begin(115200);
}
int rx_num(){
    int high_count = 0;
    float num = 0;
    while(high_count < 28){
      if(!digitalRead(3)){
        high_count = 0;
      }
      else{
        high_count ++;
      }
      delay(rx_delay/2);
    }
    while(digitalRead(3)){}
    delay(rx_delay*1.5);
    for(int i=0; i<12; i++){
      Serial.print(digitalRead(3)? "1":"0");
      if(digitalRead(3)){
        num += pow(2,11-i);
      }
      delay(rx_delay);
    }
    Serial.print("   ");
    Serial.print(num);
    Serial.println(" ");
}

void loop() {
  rx_num();
}
