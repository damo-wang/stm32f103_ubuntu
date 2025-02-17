#ifndef __STM32F103XB_H
#define __STM32F103XB_H

#include <stdint.h>

// STM32F103 寄存器定义
#define RCC_BASE   0x40021000U
#define GPIOC_BASE 0x40011000U

#define RCC    ((RCC_TypeDef*) RCC_BASE)
#define GPIOC  ((GPIO_TypeDef*) GPIOC_BASE)

// RCC 寄存器结构体
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} RCC_TypeDef;

// GPIO 寄存器结构体
typedef struct {
    volatile uint32_t CRH;
    volatile uint32_t CRL;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;

#define RCC_APB2ENR_IOPCEN  (1 << 4)

// GPIO_CRH 寄存器配置
#define GPIO_CRH_MODE13      (0x3 << 20)   // MODE13 mask
#define GPIO_CRH_MODE13_0    (1 << 20)     // MODE13 bit 0
#define GPIO_CRH_MODE13_1    (2 << 20)     // MODE13 bit 1
#define GPIO_CRH_CNF13       (0x3 << 22)   // CNF13 mask
#define GPIO_CRH_CNF13_0     (1 << 22)     // CNF13 bit 0
#define GPIO_CRH_CNF13_1     (2 << 22)     // CNF13 bit 1

#define GPIO_BSRR_BS13       (1 << 13)
#define GPIO_BSRR_BR13       (1 << (13 + 16))

#endif /* __STM32F103XB_H */
