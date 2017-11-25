SRC = device_lib.c
CC = gcc
AR = ar r
LIB_OUTPUT = device_lib.a
O_OUTPUT = device_lib.o
CFLAGS = -I ../include

libMake: 
		@$(CC) $(CFLAGS) -c $(SRC)
		@$(AR) $(LIB_OUTPUT) $(O_OUTPUT)
	
clean:
		@rm device_lib.a
		@rm device_lib.o