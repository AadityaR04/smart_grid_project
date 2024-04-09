void setup() {
  // put your setup code here, to run once:

  

  pinMode(5, OUTPUT); //Load1 (Red- Most Critical)
  pinMode(6, OUTPUT); //Load2 (Yellow- Less Critical)
  pinMode(7, OUTPUT); //Load3 (White - Least Critical)
  pinMode(8, OUTPUT); //Grid+Buck
  pinMode(12, OUTPUT); //Boost to Load
  pinMode(4, OUTPUT); //Parallel

}

void loop() {
  // put your main code here, to run repeatedly:
  //Discharge Cycle:
  
  digitalWrite(8, LOW); // Grid Disconnected

  digitalWrite(5, HIGH); //C1 ON
  digitalWrite(6, HIGH); //C2 ON
  digitalWrite(7, HIGH); //C3 ON
  
  digitalWrite(12, HIGH); //Boost ON
  digitalWrite(4, LOW); //Parallel OFF

  delay(5000); //assuming SOC is 30%
  digitalWrite(7, LOW); //C3 OFF

  delay(3000); //assuming SOC is 25%
  digitalWrite(6, LOW); //C2 OFF

  delay(2000);

  //Charge Cycle:

  digitalWrite(8, HIGH); //Grid ON
  digitalWrite(12, LOW); // Battery OFF
  delay(2000);
  digitalWrite(4, HIGH); // Parallel ON
  
  delay(2000);
  digitalWrite(6, HIGH); //C2 ON

  delay(2000);
  digitalWrite(7, HIGH); //C1 ON

  delay(5000); //assuming SOC is 80% again

  //digitalWrite(6, HIGH);
  //digitalWrite(7, HIGH); //simultaneous switching
  
}
