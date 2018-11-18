#include<Layer.h>
/*
Assumptionss !!
the Password is a 4 distinct numbers from 0 to 9
the Check_Keypad function returns 0 if not input



*/

#define NOINPUT 0
#define DENIED 0
#define OK 1

double TempValue;
uint8_t Access = DENIED; // 0 denied 1 ok
uint8_t NumberOfTries = 0;
uint8_t Password[] = {1,2,3,4};

inline void delay(long period){
  _delay_ms(period);
}


ISR(TIMER OC){
  if(LED is still on turn off after 15 sec then turn off this timer OC);
  LED_OFF();
}
ISR(SYSTEM INT){
  *count for one minute and if one minute or more is reached
  *change SystemTimerOF to 1
}
ISR(SWITCH INT){
  reset counting in system timer Interrupt
  if (DisplayTemp == 0 ){
    DisplayTemp = 1;
  }
}


void AccessDenied() {
  LCD_Clear();
  LCD_PrintString("Access NOT OK");
  Buzzer_ON();
  delay(5000);
  Buzzer_OFF();
}
void AccessOK() {
  LCD_Clear();
  LCD_PrintString("Access OK");
  LED_ON();
  Enable_Timer_OC();
  Timer_SETOC();
}
uint8_t ComparePassword(uint8_t *PasswordTry){
  //returns 1 if the Password is correct
  if ((Password[0] == PasswordTry[0]) && (Password[1] == PasswordTry[1])
      && (Password[2] == PasswordTry[2]) && (Password[3] == PasswordTry[3]) ) {
    return 1;
  }else{
    return 0;
  }
}
void PasswordInput(void) {
  if (NumberOfTries == 3) {
    AccessDenied();
    NumberOfTries = 0;
    return;
  }//else continue on

  uint8_t CurrentPress = 0,NumberOfPresses = 0,PasswordTry[4] ={0,0,0,0};

  while (NumberOfPresses < 4) {
    CurrentPress = Check_Keypad();
    if (CurrentPress =! NOINPUT) {
      LCD_PrintChar('*');
      PasswordTry[NumberOfPresses] = CurrentPress;
      NumberOfPresses++;
    }
  }
  //After Taking a Password from user
  if (ComparePassword(PasswordTry)) {
    Access = OK;
  }else{
    NumberOfTries++;
  }
}



int main(void) {
  //Init
  DIO_Init();
  ADC_Init();
  UART_Init();
  KeyPad_Init();
  LCD_Init();
  Timer_Init();
  Temp_Sensor_Init();
  Interrupts_Init(); //sets the values of OC etc

  //Loop
  while (1) {
    while (Access != OK) {
      LCD_Clear();
      LCD_PrintString("Please Enter Password");
      PasswordInput();
    }
    AccessOK();//Access ok
    Enable_SystemTimer();//timer that loses access after one minute from start
    Enable_SwitchInterrupt();

    while (Access == OK) {
      if(SystemTimerOF == 1){
        SystemTimerOF = 0;
         /*Checks a variable which indicates
          wether 1 minute has passed
          since access has been given to user */
        break;
      }
      if (DisplayTemp == 1) {
        LCD_Clear();
        TempValue = Get_Temp();
        LCD_PrintFloat(TempValue);

        if ((uint8_t)TempValue >= 40) {
          LCD_PrintString("Tempreature Too High");
          Buzzer_ON();
          delay(50);
          Buzzer_OFF();
        }

      }
    }
    Access = DENIED;
    DisplayTemp = 0;
    Disable_SystemTimer();
    Disable_SwitchInterrupt();
  }

  return 0;
}
