TARGET = testbinarysearchtree
OBJS = binarysearchtree.o testbinarysearchtree.o
CFLAG = -I../include

all: ${OBJS}
${OBJS}: %.o: %.cpp
	g++ -c ${CFLAG} $<

all: ${TARGET}	
${TARGET}: %.o
	g++ -o $@ $< binarysearchtree.o

clean:
	rm -f ${TARGET}	 *.o