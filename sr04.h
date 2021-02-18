#include<Arduino.h>

#define ECHO_PIN 30
#define TRIG_PIN 32

// Toggle the assigned pin HIGH for the assigned time in milliseconds.
void sendTrigger(int triggerPin, int triggerTime_ms);
unsigned long measurePulse(int readPin);
int conversion(unsigned long duration_us);
void initializeGPIO_SR04();
