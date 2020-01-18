

pa1: clean main.o OnOptionsMenu.o Employee.o
	g++ -o pa1 main.o OnOptionsMenu.o Employee.o 
main.o: main.cpp Binary_tree.h Search_tree.h errorcode.h
	g++ -c -g -Wall main.cpp
OnOptionsMenu.o: OnOptionsMenu.h OnOptionsMenu.cpp
	g++ -c -g -Wall OnOptionsMenu.cpp
Employee.o: Employee.cpp Employee.h
	g++ -c -g -Wall Employee.cpp

# clean:
# 	rm -f *.o  

clean:
	del -F *.o 
	del -F *.exe
	del -F pa1  

