CFLAGS?=	-Wall -ggdb -W -O
CC?=		gcc
LIBS?=
LDFLAGS?=
PREFIX?=	/usr/local
VERSION=1.5
TMPDIR=/tmp/webbench-$(VERSION)

# 2020-10-13 lyq   
# = 是最基本的赋值
# := 是覆盖之前的值
# ?= 是如果没有被赋值就赋值等号后面的值
# += 是添加等号后面的值

#CFLAGS： 指定头文件（.h文件）的路径，
#如：CFLAGS=-I/usr/include -I/path/include。
#同样地，安装一个包时会在安装路径下建立一个include目录，当安装过程中出现问题时，
#试着把以前安装的包的include目录加入到该变量中来。

#LDFLAGS：gcc 等编译器会用到的一些优化参数，也可以在里面指定库文件的位置。
#用法：LDFLAGS=-L/usr/lib -L/path/to/your/lib。
#每安装一个包都几乎一定的会在安装目录里建立一个lib目录。
#如果明明安装了某个包，而安装另一个包时，它愣是说找不到，
#可以抒那个包的lib路径加入的LDFALGS中试一下。

#LIBS：告诉链接器要链接哪些库文件，如LIBS = -lpthread -liconv


all:   webbench tags

tags:  *.c
	-ctags *.c


install: webbench
	install -s webbench $(DESTDIR)$(PREFIX)/bin	
	install -m 644 webbench.1 $(DESTDIR)$(PREFIX)/man/man1	
	install -d $(DESTDIR)$(PREFIX)/share/doc/webbench
	install -m 644 debian/copyright $(DESTDIR)$(PREFIX)/share/doc/webbench
	install -m 644 debian/changelog $(DESTDIR)$(PREFIX)/share/doc/webbench

webbench: webbench.o Makefile
	$(CC) $(CFLAGS) $(LDFLAGS) -o webbench webbench.o $(LIBS) 

clean:
	-rm -f *.o webbench *~ core *.core tags
#1、如果makefile执行的命令前面加了@符号，则不显示命令本身而只显示结果。 
#2、通常make执行的命令出错（该命令的退出状态非0）就立刻终止，不再执行后续命令，
#但是如果命令前面加上“-”，即使这条命令出错，makefile也会继续执行后续命令的。

tar:   clean
	-debian/rules clean
	rm -rf $(TMPDIR)
	install -d $(TMPDIR)
	cp -p Makefile webbench.c socket.c webbench.1 $(TMPDIR)
	install -d $(TMPDIR)/debian
	-cp -p debian/* $(TMPDIR)/debian
	ln -sf debian/copyright $(TMPDIR)/COPYRIGHT
	ln -sf debian/changelog $(TMPDIR)/ChangeLog
	-cd $(TMPDIR) && cd .. && tar cozf webbench-$(VERSION).tar.gz webbench-$(VERSION)

webbench.o:	webbench.c socket.c Makefile

.PHONY: clean install all tar
