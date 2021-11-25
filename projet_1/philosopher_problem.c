#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//gcc -o test philosopher_problem.c -lpthread
typedef enum {hungry, eating, thinking} state;
state* state_p;
int n_p;
sem_t* sem_p;
sem_t mutex;
//gcc -o test philosopher_problem.c -lpthread
//function to see if philosopher can take both forks
//return 1 if ok
//return 0
void test(int id_p){
    //must look if on both sides no one is eating
    if(state_p[id_p]== hungry && state_p[(id_p-1)%n_p]!=eating && state_p[(id_p+1)%n_p]!= eating){
        state_p[id_p] = eating;
        sem_post(&sem_p[id_p]); //increment value;
    }
}

void eat(int id_p){
    sem_wait(&mutex);//mutex lock
    state_p[id_p]=hungry;
    test(id_p);
    sem_post(&mutex);
    sem_post(&sem_p[id_p]);
}
void rest(int id_p){
    sem_wait(&mutex);
    state_p[id_p] = thinking;
    //test left
    test((id_p-1)%n_p);
    //test right
    test((id_p+1)%n_p);
    sem_post(&mutex);
}
void *run_philosopher(void *args){
    int n_cycle = 0;
    int id_p= *(int*) args;
    while(n_cycle<10000){ //run 10000 cycles
        n_cycle++;
        eat(id_p);
        rest(id_p);
    }
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
            fprintf(stderr,"error with thread %d\n" ,i);
            return 0;
        }
    }

    //clean up everything
    for(int i=0;i<n_p;i++){
        int join_error=pthread_join(threads[i],NULL);
        int destroy_error=sem_destroy(&sem_p[i]);
        if(join_error){
            fprintf(stderr,"error with thread join %d\n" ,i);
            return 0;
        }
        if(destroy_error){
            fprintf(stderr,"error with sem destroy %d\n" ,i);
            return 0;
        }
    }
    free(state_p);
    free(sem_p);
    sem_destroy(&mutex);


    return 0;
}
