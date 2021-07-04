OUT = template
CFLAGS = -T stm32f051r8.ld
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -mthumb-interwork
CFLAGS += -mfloat-abi=soft -mfpu=fpv4-sp-d16
CFLAGS += -nostdlib
CFLAGS += -I.
CFLAGS += -Iinc

SRC = stm32f051r8_startup.c
SRC += ./src/main.c

$(OUT):
	arm-none-eabi-gcc -g -o $(OUT).elf $(CFLAGS) $(SRC)
	arm-none-eabi-objcopy -O binary $(OUT).elf $(OUT).bin
	
.PHONY:  clean flash info disassemle openocd
disassemble:
	arm-none-eabi-gcc -g -Wa,-adhln -o $(OUT).s $(CFLAGS) $(SRC)
clean:
	rm $(OUT).elf $(OUT).bin
flash: 
	st-flash write $(OUT).bin 0x8000000
info:
	st-info --probe
openocd:
	openocd -f "interface/stlink-v2.cfg" -f "target/stm32f0x.cfg"
