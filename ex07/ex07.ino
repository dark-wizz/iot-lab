int s[] = {8, 9, 10, 11};
int out = 12;
int color[4]; //red, blue, clear, green
void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++)
    pinMode(s[i], OUTPUT);
    pinMode(out, INPUT);
    digitalWrite(s[0], HIGH);
    digitalWrite(s[1], HIGH);
}

void loop() {
  int c=0;
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++){
      digitalWrite(s[2], i);
      digitalWrite(s[3], j);
      color[c++] = pulseIn(out, LOW);
    }
  Serial.println("Red: "+String(color[0])+"\tBlue: "+
  String(color[1]) +"\tGreen: "+String(color[2]));
  delay(2000);
}
