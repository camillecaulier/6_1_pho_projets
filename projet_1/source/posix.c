//
// Created by Camil on 02/12/2021.
//

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n_threads;
pthread_mutex_t mutex_test;

void *test(void *args){
    int cycles = 0;
    while(cycles <= 6400/n_threads){
        cycles++;
        pthread_mutex_lock(&mutex_test);
        while (rand() > RAND_MAX/10000);

        pthread_mutex_unlock(&mutex_test);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv ) {
    n_threads = atoi(argv[1]);
    if(n_threads<=0){
        perror("no threads");
        return 0;
    }

    pthread_t threads[n_threads];
    pthread_mutex_init(&mutex_test,0);

    for(int i=0; i < n_threads ; i++){
        int create_error=pthread_create(&threads[i],NULL,test,NULL);
        if(create_error){
            fprintf(stderr,"error with thread creation %d\n",i);
        }
    }


    for(int i =0; i< n_threads; i++){
        int destroy_error= pthread_join(threads[i], NULL);
        if(destroy_error){
            fprintf(stderr,"error with thread join %d \n",i);
        }
    }

    //my_mutex_destroy(&mutex_test);
    return 0;


}