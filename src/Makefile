SRC = Interprete.c
CC = gcc
LIB = device_lib.a 
APP = roboticFinger
OUT = ../$(APP)
CFLAGS = -w -I ../include
LFLAGS = ../lib/$(LIB)

all: $(APP)

$(APP):
		@$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LFLAGS)
		@echo "Creating executable \"$(APP)\""

clean:
		@rm $(OUT)
		@echo "Deleting executables"