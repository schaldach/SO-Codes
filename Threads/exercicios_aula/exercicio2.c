// Faça uma aplicação que tenha um vetor de 10 valores, gerados 
// randomicamente ou com entrada do usuário. Com o vetor preenchido, 
// eles devem gerar uma soma e um produto (resultado de uma multiplicação). 
// Você deve usar pelo menos duas threads para cada operação (soma e multiplicação)
// e utilizar os dados no vetor original.

#include	<pthread.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

int vetor[10] = {0,0,0,0,0,0,0,0,0,0};
int sum;
int mul;
int i;

void thread_mul(void) {
    mul = 1;
    for(i=0;i<10;i++){
        mul = mul*vetor[i];
    }
}

void thread_sum(void) {
    sum = 0;
    for(i=0;i<10;i++){
        sum += vetor[i];
    }
}

int main( int argc, char *argv[]) {
    pthread_t t1, t2;

    for(i=0;i<10;i++){
        vetor[i] = rand()%28;
    }

    for(i=0;i<10;i++){
        printf("%d\n", vetor[i]);
    }    

    pthread_create(&t1, NULL, (void *) thread_mul, NULL);
    pthread_create(&t2, NULL, (void *) thread_sum, NULL);

    pthread_join( t1, NULL);
    pthread_join( t2, NULL);

    printf("soma é %d\n", sum);
    printf("produto é %d\n", mul);
}
// tudo certo!