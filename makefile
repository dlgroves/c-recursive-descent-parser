CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -g 
TARGET = rdp
DEPS = data/reader.c parser/parser.c

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(DEPS)
	
clean: 
	$(RM) $(TARGET)