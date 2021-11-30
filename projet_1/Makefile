CC=gcc
all: source/philosopher_problem.c source/producer_consumer.c
	$(CC) -o executable/philosopher_problem source/philosopher_problem.c -lpthread
	$(CC) -o executable/producer_consumer source/producer_consumer.c -lpthread
	$(CC) -o executable/writer_reader source/writer_reader.c -lpthread

clean:
	rm -f executable/philosopher_problem
	rm -f executable/producer_consumer
	rm -f executable/writer_reader

performance_philosopher:
	$(CC) -o executable/philosopher_problem source/philosopher_problem.c -lpthread
	bash philosopher_shell.sh

performance_writer_reader:
	$(CC) -o executable/writer_reader source/writer_reader.c -lpthread
	bash writer_reader_shell.sh

performance_producer_consumer:
	$(CC) -o executable/producer_consumer source/producer_consumer.c -lpthread
	bash producer_consumer_shell.sh

philosopher_problem: source/philosopher_problem.c
	$(CC)  source/philosopher_problem.c -o executable/philosopher_problem -lpthread


producer_consumer: source/producer_consumer.c
	$(CC) source/producer_consumer.c -o executable/producer_consumer -lpthread

writer_reader: source/writer_reader.c
	$(CC) source/writer_reader.c -o executable/writer_reader -lpthread