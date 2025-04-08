/**
 * A pthread program illustrating how to
 * create a simple thread and some of the pthread API
 * This program implements the summation function where
 * the summation operation is run as a separate thread.
 *
 * Most Unix/Linux/OS X users
 * gcc thrd.c -lpthread
 */

 #include <pthread.h>
 #include <stdio.h>
 
 int sum; /* this data is shared by the thread(s) */
 
 void *th_teclado(void *param); 
 void *th_soma(void *param); 
 void *th_imprime(void *param); 
 
 
 int main(){
     pthread_t tid_teclado, tid_soma, tid_imprime; /* the thread identifier */
     pthread_attr_t attr; /* set of attributes for the thread */
 
     pthread_attr_init(&attr);
     
     pthread_create(&tid_teclado,&attr,th_teclado,NULL);
     pthread_join(tid_teclado,NULL);
     pthread_create(&tid_soma,&attr,th_soma,NULL);
     pthread_create(&tid_imprime,&attr,th_imprime,NULL);
     
     /* now wait for the thread to exit */
     
     pthread_join(tid_soma,NULL);
     pthread_join(tid_imprime,NULL);
     
     printf("Processo principal finalizou apos todas as threads finalizarem\n");
     return 0;
 }
 
 /**
  * The thread will begin control in this function
  */
 void *th_teclado(void *param){
     while(1){
         printf("Entre com o valor a ser somado: \n");
         scanf("%d", &sum);
         pthread_exit(0);
     }
 }
 
 void *th_soma(void *param){
     sum+= 10;
     pthread_exit(0);
 }
 
 void *th_imprime(void *param){
     printf("Sum: %d\n", sum);
     pthread_exit(0);
 }
 