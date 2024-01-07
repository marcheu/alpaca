APPNAME = mycgi
SOURCES = $(shell find . -type f -name '*.cc' |xargs)
HEADERS = $(shell find . -type f -name '*.h' |xargs)

CXX = g++
OPT = -O0 $(INCLUDES) -Wall -Wsign-compare -Wpointer-arith -Wcast-qual -Wcast-align

LIB = -lm -lcgicc

INCLUDES = -I/usr/include -I.

all:	$(APPNAME)
	@wc $(SOURCES) $(HEADERS)
	@echo OK.

$(APPNAME):
	$(CXX) $(OPT) -o $(APPNAME) $(SOURCES) $(LIB)

clean:
	@echo Cleaning up...
	@rm -f nohup.out core gmon.out *.o *~ $(APPNAME)
	@echo Done.

classe:
	@indent -lc0 -sc -ss -ts8 -d0 -br -brs -lp -i8 -bli0 -npsl -l1000 src/*.cc src/*.h
	@echo Classe.

