TARGET = testbinarysearchTree
OBJS = binarysearchtree.o testbinarysearchtree.o
CFLAG = -I../include -std=c++0x

all: ${OBJS}
${OBJS}: %.o: %.cpp
	g++ -c -g ${CFLAG} $<

all: ${TARGET}	
${TARGET}: %: %.o
	g++ -o $@ $< binarysearchtree.o

clean:
	rm -f ${TARGET}	 *.o