//
// Created by Camil on 01/12/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct my_mutex_t{
    int lock_val;
}my_mutex_t;

int n_threads;
my_mutex_t mutex_test;

void my_mutex_init(my_mutex_t* my_mutex){
    my_mutex->lock_val = 0;
}

void my_mutex_lock(my_mutex_t *my_mutex){
    __asm__("enter:;"
            "xchgl %%eax, %0;"
            "testl %%eax, %%eax;"
            "jnz enter;"
            :"=m"(my_mutex->lock_val)
            :"a"(1)));
}

void my_mutex_unlock(my_mutex_t *my_mutex){
    __asm__("xchgl %%eax, %0;"
            :"=m"(my_mutex->lock_val)
            :"a"(0)));
}

void my_mutex_destroy(my_mutex_t *my_mutex){
    free(my_mutex);
}
void *test(void *args){
    int cycles = 0;
    while(cylces <= 6400/n_threads){
        cycles++;
        my_mutex_lock(mutex_test);
        while (rand() > RAND_MAX/10000);
        my_mutex_unlock(mutex_test);
    }
}

int main(int argc, char **argv ) {
    n_threads = atoi(argv[1]);
    if(n_threads<=0){
        perror("no threads");
        return 0;
    }

    pthread_t threads[n_threads];
    my_mutex_init(mutex_test);

    for(int i; i < n_threads ; i++){
        int create_errror=pthread_create(&threads[i],NULL,test,NULL);
        if(create_errror){
            fprintf(stderr,"error with thread creation %d\n",i);
        }
    }

    my_mutex_destroy(mutex_test);
    for(int i =0; i< n_threads; i++){
        int destroy_error= pthread_join(threads[i], NULL);
        if(destroy_error){
            fprintf(stderr,"error with thread join %d \n",i);
        }
    }

    return 0;


}



