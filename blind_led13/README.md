# stm32f103_ubuntu

| ubuntu下纯命令行开发stm32

## 工具链：arm-none-eabi-
## 烧写器：st-link v2
    连接好后，使用st-info --probe检查硬件是否连接成功

---
### 下载命令：
#### 方法一
https://www.st.com.cn/zh/development-tools/stm32cubeprog.html#
从上面网址下载linux版本

```
STM32_Programmer_CLI -c port=SWD -w xxx.hex
```

#### 方法二

```
openocd -f interface/stlink-v2.cfg -f target/stm32f1x.cfg
telnet localhost 4444
flash write_image erase /tmp/test.bin 0x08000000

```
