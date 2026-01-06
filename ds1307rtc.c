#include "lcd_system.h"

uint8_t bcd_to_dec(uint8_t bcd) {
  return (((bcd >> 4) * 10) + (bcd & 0x0F));
}
void rtc_get_time(uint8_t *hh, uint8_t *mm, uint8_t *ss) {
  start();
  write_byte(RTC_W);
  write_byte(0x00);
  stop();

  start();                 // Repeated START
  write_byte(RTC_R);

  uint8_t sec_bcd  = read_byte(true);  

  //RTC automatically increments the pointer to next address
  uint8_t min_bcd  = read_byte(true);  
  uint8_t hour_bcd = read_byte(false); // NACK to indicate the last read cycle

  stop();                  // STOP condition

  *ss = bcd_to_dec(sec_bcd & 0x7F);
  *mm = bcd_to_dec(min_bcd);
  *hh = bcd_to_dec(hour_bcd & 0x3F);
}