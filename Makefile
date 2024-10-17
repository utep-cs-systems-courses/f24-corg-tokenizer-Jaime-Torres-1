CC = gcc
CFLAGS = -Wall -g
TARGET = tokenizer
OBJ = main.o tokenizer.o history.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
