a4: main.o graph_functions.o
	gcc -Wall -std=c99 main.o graph_functions.o -lm -o a4

main.o: main.c graph.h
	gcc -Wall -std=c99 -c main.c

graph_functions.o: graph_functions.c graph.h
	gcc -Wall -std=c99 -c graph_functions.c 

clean:
	rm -f *.o a4