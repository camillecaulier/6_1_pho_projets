CC=gcc
all: source/philosopher_problem.c source/producer_consumer.c source/test_set_lib.c source/test_test_set_lib.c
	$(CC) -o executable/philosopher_problem source/philosopher_problem.c -lpthread
	$(CC) -o executable/producer_consumer source/producer_consumer.c -lpthread
	$(CC) -o executable/writer_reader source/writer_reader.c -lpthread
	$(CC) -o executable/test_set source/test_set_performance.c source/test_set_lib.c  -lpthread
	$(CC) -o executable/test_test_set_performance source/test_test_set_performance.c source/test_test_set_lib.c -lpthread
	$(CC) -o executable/philosopher_problem_mod source/philosopher_problem_mod.c source/my_semaphore.c source/test_test_set_lib.c -lpthread
	$(CC) -o executable/producer_consumer_mod source/producer_consumer_mod.c source/my_semaphore.c source/test_test_set_lib.c -lpthread
	$(CC) -o executable/writer_reader_mod source/writer_reader_mod.c source/my_semaphore.c source/test_test_set_lib.c -lpthread
	$(CC) -o executable/posix source/posix.c -lpthread

clean:
	rm -f executable/philosopher_problem
	rm -f executable/producer_consumer
	rm -f executable/writer_reader
	rm -f executable/test_set
	rm -f executable/test_test_set
	rm -f executable/philosopher_problem_mod
	rm -f executable/producer_consumer_mod
	rm -f executable/writer_reader_mod

performance_philosopher:
	$(CC) -o executable/philosopher_problem source/philosopher_problem.c -lpthread
	bash shell/philosopher_shell.sh

performance_writer_reader:
	$(CC) -o executable/writer_reader source/writer_reader.c -lpthread
	bash shell/writer_reader_shell.sh

performance_producer_consumer:
	$(CC) -o executable/producer_consumer source/producer_consumer.c -lpthread
	bash shell/producer_consumer_shell.sh

performance_test_set_vs_test_test_set:
	$(CC) -o executable/test_set source/test_set.c -lpthread
	$(CC) -o executable/test_test_set_performance source/test_test_set_performance.c source/test_test_set_lib.c -lpthread
	bash shell/test_shell.sh

performance_all:
	make all
	bash shell/philosopher_shell.sh
	bash shell/writer_reader_shell.sh
	bash shell/producer_consumer_shell.sh
	bash shell/test_shell.sh

plot_all:
	python python_files/philosopher_problem.py
	python python_files/producer_consumer.py
	python python_files/writer_reader.py
	python python_files/test.py
philosopher_problem: source/philosopher_problem.c
	$(CC)  -o executable/philosopher_problem source/philosopher_problem.c -lpthread


producer_consumer: source/producer_consumer.c
	$(CC) -o executable/producer_consumer source/producer_consumer.c -lpthread

writer_reader: source/writer_reader.c
	$(CC) -o executable/writer_reader source/writer_reader.c -lpthread