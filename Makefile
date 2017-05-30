
GP_PARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
AS_PARAMS = --32
LD_PARAMS = -melf_i386

objects = runix_loader.o runix_kernel.o global_descriptor_table.o port.o interrupts.o interruptstubs.o keyboard.o 


%.o : %.cpp
	g++ $(GP_PARAMS) -o $@ -c $<
	
%.o : %.s
	as $(AS_PARAMS) -o $@ $<
	
runix_kernel.bin : runix_linker.ld $(objects)
	ld $(LD_PARAMS) -T $< -o $@ $(objects)
	
install : runix_kernel.bin
	sudo cp $< /boot/runix_kernel.bin	
	
runix_kernel.iso : runix_kernel.cpp
	make runix_kernel.o
	make runix_kernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp runix_kernel.bin iso/boot/runix_kernel.bin
	echo 'set timeout=0'                      		> iso/boot/grub/grub.cfg
	echo 'set default=0'                     		>> iso/boot/grub/grub.cfg
	echo ''                                  		>> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' 		>> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/runix_kernel.bin'    	>> iso/boot/grub/grub.cfg
	echo '  boot'                            		>> iso/boot/grub/grub.cfg
	echo '}'                                 		>> iso/boot/grub/grub.cfg
	grub-mkrescue --output=runix_kernel.iso iso	
	rm -r iso

.PHONY : clean

clean : 
	rm -f $(objects) runix_kernel.bin runix_kernel.iso  
