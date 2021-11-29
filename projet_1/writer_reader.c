//
// Created by Camil on 26/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int n_w;
int n_r;
//int current_w =0;
int r_current =0;
pthread_mutex_t w_mutex;
pthread_mutex_t r_mutex;
sem_t r_sem;
sem_t w_sem;
void* writer(void* args){
    int w_count=0;
    while(w_count<=20){
        w_count++;

        sem_wait(&w_sem);
        fprintf(stdout,"writing\n");
        while(rand()>RAND_MAX/10000);
        sem_post(&w_sem);

    }
    fprintf(stdout,"writing FINISHED\n");
    pthread_exit(NULL);
}
void* reader(void* args){
    int r_count=0;
    while(r_count<=30){
        r_count++;
        sem_wait(&r_sem);
        pthread_mutex_lock(&r_mutex);
        r_current++;
        if(r_current== 1){
            sem_wait(&w_sem); //if this is the first r then bloc w
        }
        pthread_mutex_unlock(&r_mutex);
        sem_post(&r_sem);

        //execution critical
        fprintf(stdout,"reading currently : %d\n",r_current);
        while (rand() > RAND_MAX/10000);

        pthread_mutex_lock(&r_mutex);
        r_current--;
        if(r_count<=0){
            sem_post(&w_sem);//wake up writer when no writer
        }
        pthread_mutex_unlock(&r_mutex);
    }
    fprintf(stdout,"READER FINSH\n");
    pthread_exit(NULL);
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

    sem_init(&w_sem,0,1);
    sem_init(&r_sem,0,1);

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
    sem_destroy(&w_sem);
    sem_destroy(&r_sem);


}
