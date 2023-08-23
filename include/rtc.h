#ifndef __RTC_H
#define __RTC_H

#include "typedefs.h"

/**
 * @brief Returns TRUE if the RTC is currently in nighttime bounds.
 * 
 * Original function: 0x02013948 (arm9)
 */
BOOL __attribute__((long_call)) RTC_IsNight(void);

#endif // __RTC_H