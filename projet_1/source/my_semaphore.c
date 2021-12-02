//
// Created by Camil on 01/12/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "test_test_set_lib.h"


typedef struct my_sem_t{
    int value;
    my_mutex_t mutex;

}my_sem_t;

void my_sem_init(my_sem_t * my_sem, int value){
    my_sem->value = value;
    my_mutex_init(&my_sem->mutex);
}

void my_sem_wait(my_sem_t *my_sem){
    while(1){
        my_mutex_lock(&my_sem->mutex);
        if(my_sem->value>0){
            my_sem->value--;
            my_mutex_unlock(&my_sem->mutex);
            break;
        }
        my_mutex_unlock(&my_sem->mutex);
    }
}

void my_sem_post(my_sem_t *my_sem){
    my_mutex_lock(&my_sem->mutex);
    my_sem->value++;
    my_mutex_unlock(&my_sem->mutex);
}