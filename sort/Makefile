CFLAG = -g -std=c++11
OBJS = mainTest.o sort.o
sortTest: mainTest.o sort.o
	g++ ${CFLAG} -o sortTest mainTest.o sort.o

all: ${OBJS}
${OBJS}: %.o: %.cpp
	g++ ${CFLAG} -c $<


clean:
	rm -f *.o sortTest

