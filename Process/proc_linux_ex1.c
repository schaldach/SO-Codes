#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 5;

int main(){
	pid_t pid;

	pid = fork();
	
	if (pid == 0) { /* child process */
		value += 15;
		return 0;
	}
	else if (pid > 0) { /* parent process */
		wait(NULL);
		printf ("PARENT: value = %d\n",value); /* LINE A */
		return 0;
	}
}

// gerando .S (que é o assembly) com "gcc -S proc_linux_ex2.c"

// gerando executável com "gcc -o {qualquer_nome} proc_linux_ex2.c"
// e então só executando o executável digitando o nome dele no terminal, "./{qualquer_nome}"
// se não tiver nenhum print no arquivo vai parecer que não acontece nada, mas ele rodou