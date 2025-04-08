#include	<pthread.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

int global_sum = 0;
pthread_mutex_t exclusao_mutua = PTHREAD_MUTEX_INITIALIZER; 

void thread_sum(void *thread_id) {
    int local_sum = 0;
    int *local_id = (int*)thread_id; 
    while(global_sum<100){
        local_sum++;

        pthread_mutex_lock( &exclusao_mutua); /*Trava a seção critica*/
        global_sum++;
        pthread_mutex_unlock( &exclusao_mutua);/*destrava a seção critica*/

        printf("Thread %d: soma global = %d; soma local = %d\n", *local_id, global_sum, local_sum);
        // sleep(1);
    }
}

int main( int argc, char *argv[]) {
    pthread_t tid;

    for(int i=0;i<3;i++){
        pthread_create(&tid, NULL, (void *) thread_sum, (void *)&tid); // o i não funciona...
    }

    pthread_join( tid, NULL);
}

