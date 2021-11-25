#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/testing
long global=0;
pthread_mutex_t mutex_global;
int increment(int i) {
    return i+1;
}
void *func(void * param) {
    for(int j=0;j<1000000;j++) {
        pthread_mutex_lock(&mutex_global);
        global=increment(global);
        pthread_mutex_unlock(&mutex_global);
    }
    return(NULL);
}
int main (int argc, char *argv[]) {
    int NTHREADS = 4;
    pthread_t thread[NTHREADS];
    int err;
    for(int i=0;i< NTHREADS;i++) {
        err=pthread_create(&(thread[i]),NULL,&func,NULL);
        if(err!=0)
            perror("pthread_create");
    }
    /*...*/
    for(int i=NTHREADS-1;i>=0;i--) {
        err=pthread_join(thread[i],NULL);
        if(err!=0)
            perror("pthread_join");
    }
    printf("global: %ld\n",global);
    return(EXIT_SUCCESS);
}
