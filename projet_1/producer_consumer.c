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

int main(int argc, char **argv ){
    n_p = atoi(argv[1]);
    n_c = atoi(argv[2]);
    if(n_p<=0){
        perror("no producers\n");
    }
    if(n_c){
        perror("no consumers\n");
    }
    return 0;
}

