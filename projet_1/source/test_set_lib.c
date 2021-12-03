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



void my_mutex_init(my_mutex_t* my_mutex){
    my_mutex->lock_val = 0;
}

void my_mutex_lock(my_mutex_t *my_mutex){
    __asm__("enter:;"
            "xchgl %%eax, %0;"
            "testl %%eax, %%eax;"
            "jnz enter;"
            :"=m"(my_mutex->lock_val)
            :"a"(1));
}

void my_mutex_unlock(my_mutex_t *my_mutex){
    __asm__("xchgl %%eax, %0;"
            :"=m"(my_mutex->lock_val)
            :"a"(0));
}

void my_mutex_destroy(my_mutex_t *my_mutex){
    //free(my_mutex->lock_val);
    free(my_mutex);
}




