//
// Created by Camil on 26/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int n_w;
int n_r;
pthread_mutex_t w_mutex;
pthread_mutex_t r_mutex;
void* writer(void* args){
    int w_count=0;
    while(w_count<=640){
        w_count++;

    }
}
void* reader(void* args){
    int r_count=0;
    while(r_count<=2560){
        r_count++;

    }
}

int main(int argc, char** argv){
    n_w = atoi(argv[1]);
    n_r = atoi(argv[2]);
    if(n_w <= 0){
        perror("no writer\n");
    }
    if(n_r <= 0){
        perror("no reader\n");
    }

    pthread_t w_threads[n_w];
    pthread_t r_threads[n_r];

    pthread_mutex_init(&w_mutex,NULL);
    pthread_mutex_init(&r_mutex, NULL);

    for(int i =0; i<n_w;i++){
        if(pthread_create(&w_threads[i],NULL,writer,NULL)){
            perror("error with writer thred creation\n");
        }
    }
    for(int i =0; i<n_r;i++){
        if(pthread_create(&r_threads[i],NULL,reader,NULL)){
            perror("error with reader thread creation\n");
        }
    }
    for(int i=0;i<n_w;i++){
        if(pthread_join(w_threads[i],NULL)){
            perror("error with writer thread destruction\n");
        }
    }
    for(int i=0;i<n_r;i++){
        if(pthread_join(r_threads[i],NULL)){
            perror("error with reader thread destruction\n");
        }
    }
    pthread_mutex_destroy(&w_mutex);
    pthread_mutex_destroy(&r_mutex);

}
