#include "headfile.h"

#define A4988_DIR_PORT      GPIOA
#define A4988_DIR_PIN       GPIO_PIN_7

void A4988_SetDirection(uint8_t dir)
{
    // 在切换方向前，建议先调用 A4988_Stop() 停止PWM，防止高速切换导致电机卡死
    HAL_GPIO_WritePin(A4988_DIR_PORT, A4988_DIR_PIN, dir ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
/**
  * @brief  使用硬件PWM驱动电机以恒定转速运行
  * @param  rpm: 目标转速 (转/分钟)
  */
void A4988_RunConstantSpeed(float rpm)
{
    // 如果设置的速度接近0，直接停止定时器输出
    if (rpm <= 0.01f) 
    {
        HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
        return;
    }

    // 1. 计算目标 PWM 频率 (Hz)
    // 算法: (每分钟转速 / 60秒) * 一圈物理步数 * 细分数
    float target_freq = (rpm / 60.0f) * MOTOR_STEPS_PER_REV * A4988_MICROSTEP;

    // 2. 动态计算定时器的 ARR (自动重装载寄存器)
    // 算法: (定时器频率 / 目标PWM频率) - 1
    uint32_t arr_value = (uint32_t)(TIMER_TICK_FREQ / target_freq) - 1;

    // 3. 计算 50% 占空比的 CCR (捕获/比较寄存器)
    uint32_t pulse_value = (arr_value + 1) / 2;

    // 4. 将计算好的值写入定时器底层寄存器
    // 相比于重新初始化定时器，直接写寄存器速度极快，且不会打断当前运行状态
    __HAL_TIM_SET_AUTORELOAD(&htim3, arr_value);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse_value);

    // 5. 启动 PWM 输出
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

/**
  * @brief  急停电机 (直接关闭PWM)
  */
void A4988_Stop(void)
{
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
}




