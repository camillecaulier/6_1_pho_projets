//
// Created by Camil on 25/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
///mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1
int n_p;
int n_c;
pthread_mutex_t mutex_buffer;
int buffer[8];
int count;
sem_t n_places_free;
sem_t n_places_taken;
int total_elem;
pthread_mutex_t mutex_total_elem;
void* producer(void* args){
    while(1){
        sem_wait(&n_places_free);
        pthread_mutex_lock(&mutex_buffer);
        if(total_elem>= 1024){//check we don't surpass 1024 values
            pthread_mutex_unlock(&mutex_buffer);
            break;
        }

        buffer[count]=rand();
        count++;
        total_elem++;
        //printf("[prducdes %d\n",total_elem);
        pthread_mutex_unlock(&mutex_buffer);
        sem_post(&n_places_taken);
        while(rand()>RAND_MAX/10000);

    }
    sem_post(&n_places_taken);
    pthread_exit(NULL);
}

void* consumer(void* args){
    while(1){

        sem_wait(&n_places_taken);
        pthread_mutex_lock(&mutex_buffer);
        if(total_elem>=1024 && count==0){
            pthread_mutex_unlock(&mutex_buffer);
            break;
        }

        count--;
        //printf("%d\n",total_elem);
        pthread_mutex_unlock(&mutex_buffer);
        sem_post(&n_places_free);

        while(rand()>RAND_MAX/10000);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv ){
    n_p = atoi(argv[1]);
    n_c = atoi(argv[2]);
    if(n_p<=0){
        perror("no producers\n");
    }
    if(n_c<=0){
        perror("no consumers\n");
    }

    pthread_t p_threads[n_p];
    pthread_t c_threads[n_c];
    sem_init(&n_places_free,0,8);
    sem_init(&n_places_taken,0,0);
    pthread_mutex_init(&mutex_buffer, NULL);

    for(int i=0;i<n_p;i++){
        if(pthread_create(&p_threads[i],NULL,producer,NULL)){
            perror("error with producer thread creation\n");
        }
    }
    for(int i=0;i<n_c;i++){
        if(pthread_create(&c_threads[i],NULL,consumer,NULL)){
            perror("error with consumer thread creation\n");
        }
    }

    for(int i=0;i<n_p;i++){
        if(pthread_join(p_threads[i],NULL)){
            perror("error with producer thread destruction\n");
        }
    }
    for(int i=0;i<n_c;i++){
        if(pthread_join(c_threads[i],NULL)){
            perror("error with consumer thread destruction\n");
        }
    }
    sem_destroy(&n_places_free);
    sem_destroy(&n_places_taken);
    pthread_mutex_destroy(&mutex_buffer);


    return 0;
}

