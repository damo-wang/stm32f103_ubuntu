.syntax unified
.cpu cortex-m3
.thumb

/* 定义堆栈大小 */
.equ  Stack_Size, 0x400
.section .stack
.align 3
.globl __StackTop
__StackTop: .space Stack_Size

/* 中断向量表 */
.section .isr_vector
.globl __isr_vector
__isr_vector:
    .word __StackTop         /* 栈顶地址 */
    .word Reset_Handler      /* 复位处理函数 */
    .word Default_Handler    /* NMI */
    .word Default_Handler    /* HardFault */
    /* 其他中断向量可简化为Default_Handler */

.text
.global Reset_Handler
Reset_Handler:
    bl main                  /* 跳转到主程序 */
    b .                      /* 若返回则死循环 */

Default_Handler:
    b .                      /* 死循环处理未实现的中断 */
