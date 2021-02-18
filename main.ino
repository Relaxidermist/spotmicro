#include <Arduino_FreeRTOS.h>
#include "sr04.h"



// define two tasks for Blink and AnalogRead
void TaskBlink( void *pvParameters );
void ReadRange( void *pvParameters );
void TaskLegs( void *pvParameters );

void setup() {
  // put your setup code here, to run once:
  // Now set up two tasks to run independently.
    Serial.begin(9600);
  
    xTaskCreate(TaskBlink, "Blink", 128, NULL, 2, NULL );
    xTaskCreate(TaskRangeRead, "ReadRange", 128, NULL, 1, NULL);
    xTaskCreate(TaskLegs, "ControlLegs", 128, NULL, 1, NULL);
 
// Now the task scheduler, which takes over control of scheduling individual task

}

void loop() {
  // put your main code here, to run repeatedly:

}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
void TaskBlink(void *pvParameters) // This is a task.
{
    (void) pvParameters;
 
// initialize digital pin 13 as an output.
    pinMode(13, OUTPUT);
 
    for (;;) // A Task shall never return or exit.
    {
        digitalWrite(13, HIGH); // turn the LED on (HIGH is the voltage level)
        vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
        digitalWrite(13, LOW); // turn the LED off by making the voltage LOW
        vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    }
}


void TaskRangeRead(void *pvParameters)
{
  (void) pvParameters;
  
  initializeGPIO_SR04();
  
  for(;;)
  {
    sendTrigger(TRIG_PIN, 10);
    Serial.println(conversion(measurePulse(ECHO_PIN)));
    vTaskDelay(100);
  }
}



void TaskLegs(void *pvParameters)
{
  (void) pvParameters;

  for(;;)
  {
    vTaskDelay(100);
  }
}
