#include "stm32f103xb.h"

// 简单延时函数
void delay(volatile uint32_t n) {
    while (n--) {
        __asm("NOP");
    }
}

int main(void) {
    // 使能GPIOC时钟
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // 设置PC13为推挽输出
    GPIOC->CRH &= ~GPIO_CRH_MODE13;   // 清除MODE13
    GPIOC->CRH |= GPIO_CRH_MODE13_1;  // 设置为输出最大速度
    GPIOC->CRH &= ~GPIO_CRH_CNF13;    // 设置为普通推挽输出

    GPIOC->BSRR = GPIO_BSRR_BS13;  // 设置PC13为高电平

    while (1) {
        // 点亮LED
        GPIOC->BSRR = GPIO_BSRR_BS13;  // 设置PC13为高电平
        delay(1000000);
        
        // 熄灭LED
        GPIOC->BSRR = GPIO_BSRR_BR13;  // 设置PC13为低电平
        delay(1000000);
    }
}
