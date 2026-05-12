#ifndef __A4988_H
#define __A4988_H


#define TIMER_TICK_FREQ      1000000.0f  // 对应 PSC 80-1
#define MOTOR_STEPS_PER_REV  200.0f
#define A4988_MICROSTEP      16.0f       // ！！必须是 16，因为你插满了跳线 ！！


void A4988_SetDirection(uint8_t dir);
void A4988_RunConstantSpeed(float rpm);
void A4988_Stop(void);

#endif
