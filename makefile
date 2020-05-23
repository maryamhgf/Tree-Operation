CC_EXEC = g++
CC_FLAGS = -std=c++11

CC = ${CC_EXEC} ${CC_FLAGS}

BUILD_DIR = build

all: 1.out

1.out:  ${BUILD_DIR}/main.o  ${BUILD_DIR}/Tree.o  ${BUILD_DIR}/Node.o  ${BUILD_DIR}/Integer_Node.o  ${BUILD_DIR}/Operator_Node.o  ${BUILD_DIR}/Exceptions.o 
	g++  ${BUILD_DIR}/main.o ${BUILD_DIR}/Tree.o ${BUILD_DIR}/Node.o ${BUILD_DIR}/Integer_Node.o ${BUILD_DIR}/Operator_Node.o ${BUILD_DIR}/Exceptions.o -o ${BUILD_DIR}/1.out


${BUILD_DIR}/main.o: main.cpp Tree.hpp Node.hpp Integer_Node.hpp Operator_Node.hpp Exceptions.hpp
	${CC} -c main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Exceptions.o: Exceptions.cpp Exceptions.hpp
	${CC} -c Exceptions.cpp -o ${BUILD_DIR}/Exceptions.o

${BUILD_DIR}/Node.o: Node.cpp Node.hpp Exceptions.hpp Tree.hpp
	${CC} -c Node.cpp -o ${BUILD_DIR}/Node.o

${BUILD_DIR}/Integer_Node.o: Integer_Node.cpp Integer_Node.hpp Node.hpp Exceptions.hpp
	${CC} -c Integer_Node.cpp -o ${BUILD_DIR}/Integer_Node.o

${BUILD_DIR}/Operator_Node.o: Operator_Node.cpp Operator_Node.hpp Node.hpp Exceptions.hpp
	${CC} -c Operator_Node.cpp -o ${BUILD_DIR}/Operator_Node.o

${BUILD_DIR}/Tree.o: Tree.cpp Tree.hpp Node.hpp Integer_Node.hpp Operator_Node.hpp Exceptions.hpp
	${CC} -c Tree.cpp -o ${BUILD_DIR}/Tree.o

.PHONY: clean
clean:
	rm -rf build/ && mkdir -p build