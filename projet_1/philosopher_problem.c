#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


typedef enum {hungry, eating, thinking} state;
state* state_p;
int n_p;
sem_t* sem_p;
sem_t mutex;

//function to see if philosopher can take both forks
//return 1 if ok
//return 0
int test(int id_p){
    //must look if on both sides no one is eating
}


void pickup_fork(int id_p){

}

void eat(int id_p){

}

void *run_philosopher(void *args){
    int n_cycle = 0;
    int id_p= *(int*) args;
    while(n_cycle<10000){ //run 10000 cycles
        n_cycle++;
    }
    return NULL;
}

int main(int argc, char **argv ) {

    n_p = atoi(argv[1]); //number of philosophers
    if(n_p <= 0){
        perror("no philosophers, please give a value\n");
    }

    pthread_t threads[n_p];

    state_p =(state*) malloc(sizeof(state)*n_p);
    sem_p = (sem_t*) malloc(sizeof(sem_t)*n_p);

    for(int i =0; i<n_p; i++){
        sem_init(&sem_p[i],0,1);
        state_p[i] = thinking;
    }
    sem_init(&mutex,0,0); //value given as zero to act as a mutex

    //launch the threads
    for(int i =0; i<n_p;i++){
        int create_error=pthread_create(&threads[i],NULL, &run_philosopher, &i);
        if(create_error){
            printf("error with thread %d\n" ,i,stderr);
            return 0;
        }
    }

    //clean up everything
    for(int i=0;i<n_p;i++){
        int join_error=pthread_join(threads[i],NULL);
        int destroy_error=sem_destroy(&sem_p[i]);
        if(join_error){
            printf("error with thread join %d\n" ,i,stderr);
            return 0;
        }
        if(destroy_error){
            printf("error with sem destroy %d\n" ,i,stderr);
            return 0;
        }
    }
    free(state_p);
    free(sem_p);

    return 0;
}
