#
#
# use g++ as c++ compiler
# -std=c++11   - use c++11 features
#
CC=g++ -std=c++11
#
# -Wall : print out all compiler warning message
# -I    : include library file contains .h files
# include mySQL .h 
# CFLAGS = -c -Wall -I/usr/include/mysql 
# 
# To see all the g++ option, use man g++
#

CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient

all: student

student: student.o  studentFunc.o
	$(CC) student.o studentFunc.o -o student $(LFLAGS)

student.o: student.cpp student.h
	$(CC) $(CFLAGS) student.cpp

studentFunc.o: studentFunc.cpp student.h
	$(CC) $(CFLAGS) studentFunc.cpp
clean:
	rm *.o student

run:
	./student
