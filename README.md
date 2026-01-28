

# STM32F401RBT6 Bare-Metal Programming

Smart Weather Monitoring System Project :

Task 1: Every 1 second, read date & time from DS1307 RTC and write into the LCD Main menu.

void Task1_ReadRTC_WriteLCD_1Sec(void);

 

Task 2: Every 5 seconds, read the temperature from the LM35 temperature sensor and write it to the global variable lm35_data, and set the lm35_flag.

void Task2_ReadLM35_WriteLCD_5Sec(void);

 

Task 3: Whenever LM35_flag is set, read the temperature value from the lm35_data variable and send it to the kernel Masters webserver using ESP8266 Wi-Fi Module and reset the lm35_flag.

Void Task3_Wi-Fi_Tx(void);

 Task 4: SWMS Configuration:  Whenever ENTER switch presses, invoke the Task5 function. Using the Task5 function, the user can configure the date and time.

 void Task5_SWMS_Config(void);

 

## Author
Balu Tameneni

