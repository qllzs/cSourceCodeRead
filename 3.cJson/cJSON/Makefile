CC?= gcc
CFLAGS?= -g -o2 -Werror -Wall
LiBS?= -lm

SOURCE=$(wildcard *.c)

TARGET=cJsonTest

all:
	@echo $(SOURCE)
	$(CC) $(SOURCE)  -o $(TARGET) $(LiBS)


.PHONY:clean
clean:
	rm -rf $(TARGET)

