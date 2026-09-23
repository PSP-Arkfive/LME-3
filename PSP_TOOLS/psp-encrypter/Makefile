CC			= gcc
CFLAGS		= -Wall -Os -Iinclude
TARGET		= psp-encrypter
OBJS		= crypto.o kirk_engine.o main.o
LDFLAGS		= -lz
PREFIX      = /usr/local


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

all: $(TARGET)

install:
	@mv $(TARGET) $(PREFIX)/bin

uninstall:
	@cd $(PREFIX)/bin; rm -f $(TARGET)

clean:
	@rm -f *.o $(TARGET) *.exe *.exe.stackdump