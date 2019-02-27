TARGET = testBinarySearchTree
OBJS = binarySearchTree.o testBinarySearchTree.o
CFLAG = -I../include -std=c++0x

all: ${OBJS}
${OBJS}: %.o: %.cpp
	g++ -c -g ${CFLAG} $<

all: ${TARGET}	
${TARGET}: %: %.o
	g++ -o $@ $< binarySearchTree.o

clean:
	rm -f ${TARGET}	 *.o