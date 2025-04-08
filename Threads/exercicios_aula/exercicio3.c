// 1. Implemente um sistema em que há três threads que tem a responsabilidade 
// de ler o valor de um sensor e some ao valor de uma variável global e em uma 
// variável local. Você deve simular a contagem com operação de incremento simples (+=1 ou ++). 
// Print a variável local a cada 1 segundo e incremente a variável a cada 1 segundo. 
// O programa deve chegar ao fim quando a soma da variável global chegar a 100. 
// Ao fim, você consegue observar qual condição:
//  a. Todas as threads tem o mesmo valor na variável interna?
//  b. O print da variável global segue um incremento linear?

#include	<pthread.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

int global_sum = 0;

void thread_sum(void *thread_id) {
    int local_sum = 0;
    int *local_id = (int*)thread_id; 
    while(global_sum<100){
        local_sum++;
        global_sum++;
        printf("Thread %d: soma global = %d; soma local = %d\n", *local_id, global_sum, local_sum);
        sleep(1);
    }
}

int main( int argc, char *argv[]) {
    pthread_t tid;

    for(int i=0;i<3;i++){
        pthread_create(&tid, NULL, (void *) thread_sum, (void *)&i); // o i não funciona...
    }

    pthread_join( tid, NULL);
}