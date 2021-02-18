#include<Arduino.h>

// Arduino code to read from the SR04
// Datasheet available: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
// definte IO for sr04



// Assign GPIO to ECHO and TRIG pins on SR04
void initializeGPIO_SR04()
{
  pinMode(30, INPUT);
  pinMode(32, OUTPUT);
}


// Toggle the assigned pin HIGH for the assigned time in milliseconds.
void sendTrigger(int triggerPin, int triggerTime_ms)
{
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(triggerTime_ms);
  digitalWrite(triggerPin, LOW);
}

// This function measures an incoming pulse on the readPin - it waits for the pin to go high
// and returns the elapsed microseconds of the high duration
// TODO: Manage overflow of micros() function
unsigned long measurePulse(int readPin)
{
  unsigned long startTime_us, duration_us;
  
  while(!digitalRead(readPin))
  {
    ;
  }

  startTime_us = micros();

  while(digitalRead(readPin))
  {
    ;
  }

  duration_us = micros() - startTime_us;

  return duration_us;
}

// This function converts a microsecond duration to a distance as specified in the SR04 datasheet and returns the
// distance in cm.
int conversion(unsigned long duration_us)
{
  int range;
  
  range = duration_us / 58;

  return range;
}
