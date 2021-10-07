/*
Author : Vishwesh GM
Contact : vishweshgm@outlook.com
*/

uint32_t Appl_u32HighPulseLength_us, Appl_u32LowPulseLength_us;
uint32_t Appl_u32PeriodOfPWM;
float Frequency, DutyCycle;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(8,INPUT); /*Pulse Input from opto*/
}

// the loop routine runs over and over again forever:
void loop() {

  Appl_u32HighPulseLength_us = pulseIn(8,HIGH);
  Appl_u32LowPulseLength_us = pulseIn(8,LOW);
  Appl_u32PeriodOfPWM = Appl_u32HighPulseLength_us+Appl_u32LowPulseLength_us;
  Frequency = 1000000.0/Appl_u32PeriodOfPWM;
  Serial.println(Frequency);
}
