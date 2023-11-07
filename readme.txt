Krishna Garg

Program -> stacktest.c
Description: 
Takes in strings from the stanard input and pops them onto a stack and then returns the input in reverse order. Will return all the strings until EOF or the entered max number of elements value is reached

Linking: 
stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

Compiling:
stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

Running: 
./stacktest [max number of elements]



----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Program -> stacktest2.c
Description: 
Takes in a list of strings and returns them in the same order however the strings themselves will be reversed. Will return all the strings until EOF or the entered max number of elements value is reached

Linking: 
stacktest2: stacktest2.o stack.o
	gcc -g stacktest2.o stack.o -o stacktest2

Compiling:
stacktest2.o: stacktest2.c stack.h
	gcc -g -c stacktest2.c
	

Running: 
./stacktest2 [max number of elements]



How to get the input from a text file
./stacktest [max number of elements] < foo.txt
or 
./stacktest2 [max number of elements] < foo.txt


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


For reference:
./stacktest2 [max number of elements] | ./stacktest [max number of elements] 

and 

./stacktest [max number of elements] | ./stacktest2 [max number of elements] 

Should return the same stdout

Same case with 

cat foo.txt| ./stacktest [max number of elements] | ./stacktest2 [max number of elements] 

and 

cat foo.txt| ./stacktes2 [max number of elements] | ./stacktest [max number of elements] 

