//
// Created by Camil on 01/12/2021.
//

//#ifndef PROJET_1_MY_SEMAPHORE_H
//#define PROJET_1_MY_SEMAPHORE_H

//#endif //PROJET_1_MY_SEMAPHORE_H

typedef struct my_sem_t{
    int value;
    int mutex;

}my_sem_t;

void my_sem_init(my_sem_t *my_sem, int value);

void my_sem_wait(my_sem_t *my_sem);

void my_sem_post(my_sem_t *my_sem);