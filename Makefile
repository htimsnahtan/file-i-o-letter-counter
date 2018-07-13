CXX = g++
CXXFLAGS = -std=c++0x

OBJS = count_letters.o output_letters.o main.o

SRCS = count_letters.cpp output_letters.cpp main.cpp libraryFunctions.cpp

HEADERS = count_letters.hpp output_letters.hpp libraryFunctions.hpp

assignment1: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o letterFrequencyCounter
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm ${OBJS}