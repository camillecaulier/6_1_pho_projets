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
	$(CC) -o philosopher_problem philosopher_problem.c -lpthread
	bash philosopher_shell.sh

performance_writer_reader:
	$(CC) -o writer_reader writer_reader.c -lpthread
	bash writer_reader_shell.sh
philosopher_problem: philosopher_problem.c


producer_consumer: producer_consumer.c
	$(CC) producer_consumer.c -o producer_consumer -lpthread

writer_reader: writer_reader.c
	$(CC) writer_reader.c -o writer_reader -lpthread