//
// Created by Camil on 01/12/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "my_semaphore.h"
#include "test_test_set_lib.h"


///mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1
int n_p;
int n_c;
pthread_mutex_t my_mutex_buffer;
int buffer[8];
int count;
my_sem_t n_places_free;
my_sem_t n_places_taken;
int total_elem;
pthread_mutex_t mutex_total_elem;
void* producer(void* args){
    while(1){

        pthread_mutex_lock(&my_mutex_buffer);

        if(total_elem>= 1024){//check we don't surpass 1024 values
            my_sem_post(&n_places_taken);
            pthread_mutex_unlock(&my_mutex_buffer);
            break;
        }
        total_elem++;
        pthread_mutex_unlock(&my_mutex_buffer);
        my_sem_wait(&n_places_free);

        pthread_mutex_lock(&my_mutex_buffer);
        buffer[count]=rand();
        count++;

        //critcal section

        //printf("[prducdes %d\n",total_elem);
        pthread_mutex_unlock(&my_mutex_buffer);
        my_sem_post(&n_places_taken);
        while(rand()>RAND_MAX/10000);
    }
    //sem_post(&n_places_taken);

    pthread_exit(NULL);
}

void* consumer(void* args){
    while(1){


        my_sem_wait(&n_places_taken);
        pthread_mutex_lock(&my_mutex_buffer);
        if(total_elem>=1024 && count==0){
            my_sem_post(&n_places_taken);
            pthread_mutex_unlock(&my_mutex_buffer);
            break;
        }

        count--;
        pthread_mutex_unlock(&my_mutex_buffer);
        my_sem_post(&n_places_free);
        //taken element and runs request/process
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
    count =0;
    pthread_t p_threads[n_p];
    pthread_t c_threads[n_c];
    my_sem_init(&n_places_free,8);
    my_sem_init(&n_places_taken,0);
    pthread_mutex_init(&my_mutex_buffer, NULL);

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

    //sem_destroy(&n_places_free);
    //sem_destroy(&n_places_taken);
    pthread_mutex_destroy(&my_mutex_buffer);

    return 0;
}

