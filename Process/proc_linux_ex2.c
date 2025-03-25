#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid, pid1;

	pid = fork();
	pid1 = getpid();
	// printf("pid = %d, pid1 = %d\n", pid, pid1);

	pid = fork();
	pid1 = getpid();
	// printf("pid = %d, pid1 = %d\n", pid, pid1);

	pid = fork();
	pid1 = getpid();
	printf("pid = %d, pid1 = %d\n", pid, pid1);

	// o que entendi é que o pid, da forma que está sendo feito,
	// basicamente vai dizer o pid do processo filho gerado a partir de fork
	// por isso que os novos filhos todos tem pid = 0, pois acabaram de ser gerados,
	// não possuem processos filhos. já todos os processos pais tem um valor dado no pid, que
	// é o pid do filho gerado. o pid1 representa o pid do processo que está sendo executado.
	// olhando para os logs faz sentido.

	return 0;
}