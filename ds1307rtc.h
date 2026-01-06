#ifdef __cplusplus
extern "C" {
#endif


#define RTC_ADDR  0x68          //7-bit I2C address
#define RTC_W     (RTC_ADDR<<1)   //Wr=0 --> Write mode
#define RTC_R     ((RTC_ADDR<<1) | 1) //RD=1 --> Read Mode

uint8_t bcd_to_dec(uint8_t bcd);
void rtc_get_time(uint8_t *hh, uint8_t *mm, uint8_t *ss);

#ifdef __cplusplus
}
#endif