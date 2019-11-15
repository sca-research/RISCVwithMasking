CC  = riscv64-unknown-elf-gcc

target = BitSlicedAES
obj    = key_schedule.o bs.o aes.o BitSlicedAES.o
$(target): $(obj)
	$(CC) -o $(target) $(obj)

key_schedule.o: key_schedule.c key_schedule.h
	$(CC) -c key_schedule.c -o $@
bs.o:  bs.c bs.h
	$(CC) -c bs.c -o $@

aes.o: aes.c aes.h
	$(CC) -c aes.c -o $@

BitSlicedAES.o: BitSlicedAES.c 
	$(CC) -c BitSlicedAES.c -o $@



clean:
	rm -f $(obj) BitSlicedAES
