OBJECTS = boot.o kernel.o
CC = gcc
CFLAGS =  -m32 -fno-builtin -fno-stack-protector \
			 -Wall -Wextra -Werror -c
CEXTRAFLAGS = -nostdlib -nostdinc -nostartfiles -nodefaultlibs 
LDFLAGS = -N -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf32

all: kernel os.iso

kernel: $(OBJECTS)
	@ld $(LDFLAGS) $(OBJECTS) -o iso/boot/kernel
	@echo "--> Compiled Kernel"

os.iso: kernel
	@echo "--> Generating os.iso file"
	@genisoimage -R                              \
				-b boot/grub/stage2_eltorito    \
				-no-emul-boot                   \
				-boot-load-size 4               \
				-A MKS                          \
				-boot-info-table                \
				-o os.iso                       \
				iso
	@echo "--> Completed building OS"

%.o: %.c
	@$(CC) $(CFLAGS) $<
	@echo "--> Compiled $<"

%.o: %.asm
	@$(AS) $(ASFLAGS) $<
	@echo "--> Compiled $<"

clean:
	@rm -rf *.o iso/boot/kernel os.iso