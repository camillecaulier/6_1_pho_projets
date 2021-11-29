CC=gcc
all: philosopher_problem.c producer_consumer.c
	$(CC) -o philosopher_problem philosopher_problem.c -lpthread
	$(CC) -o producer_consumer producer_consumer.c -lpthread
	$(CC) -o writer_reader writer_reader.c -lpthread

clean:
	rm philosopher_problem
	rm producer_consumer
	rm writer_reader

performance_philosopher:
	bash philosopher_shell.sh

philosopher_problem: philosopher_problem.c
	$(CC) -o philosopher_problem philosopher_problem.c -lpthread