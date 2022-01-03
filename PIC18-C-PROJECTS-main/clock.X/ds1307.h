#ifndef DS1307_H
#define	DS1307_H

#ifndef __XC_H
#include <xc.h>
#endif 

#include <stdint.h>

#define     RTC_WRITE_ADDR      (0xD0)
#define     RTC_READ_ADDR       (0xD1)

void Set_Time_Date(void);
int BCD_2_DEC(int to_convert);
int DEC_2_BCD (int to_convert);
void Update_Current_Date_Time();

struct time {
    volatile uint8_t sec;
    volatile uint8_t min;
    volatile uint8_t hour;
    volatile uint8_t date;
    volatile uint8_t month;
    volatile uint8_t year;
}current_time, set_time = {0, 30, 20, 17, 10, 21};



#endif	/* DS1307_H */

