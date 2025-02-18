# Makefile for STM32F103C8T6
TARGET = main
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
CFLAGS = -mcpu=cortex-m3 -mthumb -g -Wall -O2
LDFLAGS = -T stm32f103c8t6.ld -nostartfiles -lm -lc -lgcc

# 源文件列表
SRC = main.c startup_stm32f103c8t6.s

# 使用 patsubst 函数将 .c 和 .s 后缀都替换为 .o 后缀
OBJ = $(patsubst %.c, %.o, $(patsubst %.s, %.o, $(SRC)))

# 生成 .bin 文件
$(TARGET).bin:$(TARGET).elf
	arm-none-eabi-objcopy -O binary $(TARGET).elf $(TARGET).bin

# 编译规则
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.s
	$(AS) $< -o $@

# 链接规则
$(TARGET).elf:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(TARGET).elf

# clean 规则
clean:
	rm -f *.o $(TARGET).elf $(TARGET).bin
