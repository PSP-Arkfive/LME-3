CC			= gcc
CFLAGS		= -Wall -Os -Iinclude
TARGET		= psp-btcnf
OBJS		= main.o
PREFIX      = /usr/local

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

all: $(TARGET)

install:
	@mv $(TARGET) $(PREFIX)/bin

uninstall:
	@cd $(PREFIX)/bin; rm -f $(TARGET)

clean:
	@rm -f *.o $(TARGET) *.exe *.exe.stackdump
