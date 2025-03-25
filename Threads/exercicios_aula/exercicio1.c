// Desenvolver uma aplicação de leia uma entrada do teclado, 
// some com uma constante e imprima na tela o dado resultante da soma. 
// Divida as tarefas em threads usando a biblioteca pthread (preferencialmente).

#include	<pthread.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

int constante = 9;
int sum = 0; // é o espaço de memória compartilhado
// threads não retornam dados, são sempre void (pois são pequenos processos)

void alteraValor( int delta) {
	sum = constante + delta;
}

void thread_print(void) {
	while(1){
		sleep(1);
		printf("A soma é igual a %d\n", sum);
	}
}

void thread_input(void) {
	char teclado[1000];
	while(1){
		fgets( teclado, 1000, stdin);
		printf("Digite novo valor:\n");
		fgets( teclado, 1000, stdin);
		alteraValor(atoi(teclado));
	}
}

int main( int argc, char *argv[]) {

    pthread_t t1, t2;

    pthread_create(&t1, NULL, (void *) thread_input, NULL);
    pthread_create(&t2, NULL, (void *) thread_print, NULL);

    pthread_join( t1, NULL);
    pthread_join( t2, NULL);
}