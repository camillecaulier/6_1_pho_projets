//
// Created by Camil on 01/12/2021.
//

#ifndef PROJET_1_TEST_TEST_SET_H
#define PROJET_1_TEST_TEST_SET_H

#endif //PROJET_1_TEST_TEST_SET_H
typedef struct my_mutex_t{
    int lockval;
}my_mutex_t;

void my_mutex_init(my_mutex_t* my_mutex);

void my_mutex_lock(my_mutex_t* my_mutex);

void my_mutex_unlock(my_mutex_t* my_mutex);