#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//gcc -o test philosopher_problem.c -lpthread
typedef enum {hungry, eating, thinking} state;
state* state_p;
int n_p;
sem_t* my_sem_p;
sem_t my_mutex_buffer;
//gcc -o test philosopher_problem.c -lpthread
//function to see if philosopher can take both forks
//return 1 if ok
//return 0
void test(int id_p){
    //must look if on both sides no one is eating
    if(state_p[id_p]== hungry && state_p[(id_p-1+n_p)%n_p]!=eating && state_p[(id_p+1)%n_p]!= eating){
        state_p[id_p] = eating;
        sem_post(&my_sem_p[id_p]); //increment value;
    }
}

void eat(int id_p){
    sem_wait(&my_mutex_buffer);//my_mutex_buffer lock
    state_p[id_p]=hungry;

    test(id_p); //philosopher eating

    sem_post(&my_mutex_buffer);
    sem_post(&my_sem_p[id_p]);
}
void rest(int id_p){
    sem_wait(&my_mutex_buffer);
    state_p[id_p] = thinking;

    //test left
    test((id_p-1+n_p)%n_p);
    //test right
    test((id_p+1)%n_p);
    sem_post(&my_mutex_buffer);
}
void *run_philosopher(void *args){
    int n_cycle = 0;
    int id_p= *(int*) args;
    while(n_cycle<100000){ //run 100000 cycles
        n_cycle++;
        eat(id_p);
        rest(id_p);

    }
    //cycle finished
    pthread_exit(NULL);
}

int main(int argc, char **argv ) {

    n_p = atoi(argv[1]); //number of philosophers
    if(n_p <= 0){
        perror("no philosophers, please give a value\n");
        return 0;
    }

    pthread_t threads[n_p];

    //allocate memory
    state_p =(state*) malloc(sizeof(state)*n_p);
    my_sem_p = (sem_t*) malloc(sizeof(sem_t) * n_p);
    int* p_index = (int*) malloc(sizeof (int)*n_p);

    //initialise everything
    for(int i =0; i<n_p; i++){
        sem_init(&my_sem_p[i], 0, 0);
        state_p[i] = thinking;
        p_index[i] = i;
    }
    sem_init(&my_mutex_buffer, 0, 1); //value given as 1 to act as a my_mutex_buffer


    //launch the threads
    for(int i =0; i<n_p;i++){
        int create_error=pthread_create(&threads[i],NULL, run_philosopher,(void *) (&p_index[i]));
        if(create_error){
            fprintf(stderr,"error with thread %d\n" ,i);
            return 0;
        }
    }

    //clean up everything
    for(int i=0;i<n_p;i++){
        int join_error=pthread_join(threads[i],NULL);
        int destroy_error=sem_destroy(&my_sem_p[i]);
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
    free(my_sem_p);
    free(p_index);
    sem_destroy(&my_mutex_buffer);


    return 0;
}
