//
// Created by Camil on 03/12/2021.
//
//
//#ifndef PROJET_1_TEST_SET_LIB_H
//#define PROJET_1_TEST_SET_LIB_H
//
//#endif //PROJET_1_TEST_SET_LIB_H
typedef struct {
    int lock_val;
}my_mutex_t;
void my_mutex_init(my_mutex_t* my_mutex);
void my_mutex_lock(my_mutex_t *my_mutex);
void my_mutex_unlock(my_mutex_t *my_mutex);