#ifndef __A4988_H
#define __A4988_H


#define MOTOR_STEPS_PER_REV 200.0f      // 步进电机一圈的物理步数 (1.8°电机填200)
#define A4988_MICROSTEP     16.0f       // 你硬件上设置的细分数 (根据实际拨码开关/跳线帽修改)
#define TIMER_TICK_FREQ     3200000.0f  // 定时器计数频率 (80MHz / 25 = 3.2MHz)

void A4988_SetDirection(uint8_t dir);
void A4988_RunConstantSpeed(float rpm);
void A4988_Stop(void);

#endif
