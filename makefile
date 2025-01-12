all:
	gcc -Wall -g -o stack_queue stack.c queue.c
	g++ -Wall -g -o linkedlist linkedlist.cpp

clean:
	rm -f stack_queue linkedlist
