CC=arm-none-eabi-gcc
MACH=cortex-m4
BOARD = STM32F4-Discovery
MCU = STM32F407VG
CFLAGS=-c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS=-nostdlib -T stm32_ls.ld -Wl,-Map=finalled.map
all: main.o stm32f407xx_gpio_driver.o stm32_startup.o finalled.elf

TARGET =finalled.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f407xx_gpio_driver.o:stm32f407xx_gpio_driver.c
	$(CC) $(CFLAGS) -o $@ $^
 
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^	

finalled.elf:main.o stm32f407xx_gpio_driver.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

run: ${TARGET}
	-qemu-system-gnuarmeclipse.exe -M ${BOARD} -mcu ${MCU} --image $(TARGET)

clean:
	rm -rf *.o *.elf *.gchCC=arm-none-eabi-gcc
MACH=cortex-m4
BOARD = STM32F4-Discovery
MCU = STM32F407VG
CFLAGS=-c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS=-nostdlib -T stm32_ls.ld -Wl,-Map=finalled.map
all: main.o stm32f407xx_gpio_driver.o stm32_startup.o finalled.elf

TARGET =finalled.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f407xx_gpio_driver.o:stm32f407xx_gpio_driver.c
	$(CC) $(CFLAGS) -o $@ $^
 
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^	

finalled.elf:main.o stm32f407xx_gpio_driver.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

run: ${TARGET}
	-qemu-system-gnuarmeclipse.exe -M ${BOARD} -mcu ${MCU} --image $(TARGET)

clean:
	rm -rf *.o *.elf *.gch
