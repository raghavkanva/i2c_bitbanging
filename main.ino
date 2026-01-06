#include "lcd_system.h"


int main(void)
{
  timer1_init();
  i2c_init();

  lcd_init();

  lcd_set_cursor(0, 0);
  lcd_print("Slots: 23");

  uint8_t h, m, s;
  rtc_get_time(&h, &m, &s);

  lcd_set_cursor(1, 0);
  lcd_print("Time(IST)");
  lcd_print_num(h);
  lcd_print(":");
  lcd_print_num(m);
  lcd_print(":");
  lcd_print_num(s);


  delay_ms(2000);

  while (1)
  {
    lcd_command(0x18);  // Hardware shift left
    delay_ms(300);
  }
}


