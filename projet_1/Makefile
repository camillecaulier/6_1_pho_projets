CC=gcc
all: source/philosopher_problem.c source/producer_consumer.c source/test_set.c source/test_test_set.c
	$(CC) -o executable/philosopher_problem source/philosopher_problem.c -lpthread
	$(CC) -o executable/producer_consumer source/producer_consumer.c -lpthread
	$(CC) -o executable/writer_reader source/writer_reader.c -lpthread
	$(CC) -o executable/test_set source/test_set.c -lpthread
	$(CC) -o executable/test_test_set source/test_test_set.c -lpthread
	$(CC) -o executable/philosopher_problem_mod source/philosopher_problem_mod.c source/my_semaphore.c source/test_test_set.c -lpthread
	$(CC) -o executable/producer_consumer_mod source/producer_consumer_mod.c -lpthread
	$(CC) -o executable/writer_reader_mod source/writer_reader_mod.c -lpthread

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
	$(CC)  -o executable/philosopher_problem source/philosopher_problem.c -lpthread


producer_consumer: source/producer_consumer.c
	$(CC) -o executable/producer_consumer source/producer_consumer.c -lpthread

writer_reader: source/writer_reader.c
	$(CC) -o executable/writer_reader source/writer_reader.c -lpthread