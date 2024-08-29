

CC = g++
TARGET = server
DEPEND = main.cpp control.cpp network.cpp database.cpp  
FLAGS = -pthread -std=c++11  -lsqlite3

${TARGET}: ${DEPEND}
	${CC} -o $@  $^  ${FLAGS}



clean:
	rm ${TARGET} -rf
