#define tx_delay 4

void setup() {
  pinMode(12,OUTPUT);
  digitalWrite(12,0);
  Serial.begin(115200);
}
int tx_num(int num){
    digitalWrite(12,1);
    delay(tx_delay * 16);
    digitalWrite(12,0);
    delay(tx_delay * 1);
    for (int bit_idx = 0; bit_idx < 12; bit_idx++){
        int tx_bit = ("%d\n",num & (0x800 >> bit_idx));
        digitalWrite(12,tx_bit ? 1:0);
        Serial.print(tx_bit ? "1":"0");
        delay(tx_delay);
    }
    digitalWrite(12,0);
}

void loop() {
  for(int i=0; i < 4050; i++){
    Serial.print(i);
    Serial.print("  ");
    tx_num(i);
    Serial.println("");
  }
}
