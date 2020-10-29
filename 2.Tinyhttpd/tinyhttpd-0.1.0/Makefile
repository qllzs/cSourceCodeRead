CC?= gcc
CFLAGS?= -W -Wall 
LIBS?=  -lpthread #linux build no need -lsocket

Target = httpd
Source= httpd.c

all: $(Target)

$(Target): $(Source)
	$(CC) $(CFLAGS)  -o $(Target) $(Source) $(LIBS)

.Phony:clean
clean:
	rm $(Target)
