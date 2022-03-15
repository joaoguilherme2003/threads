# threads

Neste codigo foi utilizado o conceito de threads.

Thread é um pequeno programa que trabalha como um subsistema, sendo uma forma de um processo se autodividir em duas ou mais tarefas.

No algoritmo foi pedido ao números inteiro para que fosse calculado a media e encontrado o maior e o menor inteiro.

Foi utilizado 4 threads, a thread no main pra ler e printar os dados, uma para calcular a media, uma para achar o menor numero e uma para achar o maior numero.

Declaração das bibliotecas, funções e variaveis globais.

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int quant_num;
int average;
int minimum;
int maximum;
int arr[1024];

void *max();
void *min();
void *media();

```
Main
```c
int main()
{
  int num = 0, t;
  scanf("%d", &quant_num);
  
  for (int i = 1; i < quant_num + 1; i++) {
    scanf("%d", &num);
    arr[i] = num; 
  } 

  pthread_t thread1; 
  pthread_t thread2; 
  pthread_t thread3; 
  
  t = pthread_create(&thread1, NULL, &media, NULL); 
  pthread_join(thread1, NULL); 
  
  t = pthread_create(&thread2, NULL, &min, NULL); 
  pthread_join(thread2, NULL); 
  
  t = pthread_create(&thread3, NULL, &max, NULL);
  pthread_join(thread3, NULL); 
  
  printf("The average value is %d", average);
  printf("\nThe minimum value is %d", minimum);
  printf("\nThe maximum value is %d", maximum); 
  
  return 0; 
}
```
Lendo dados
```c
int num = 0, t;
  scanf("%d", &quant_num);
  
  for (int i = 1; i < quant_num + 1; i++) {
    scanf("%d", &num);
    arr[i] = num; 
  } 
```
Uso das threads: primeiro foi declarado e depois utilizadas a funçao pthread_create para encaminharmos a thread para a determinada funçao e a pthread_join para as threads não entrem em desordem.

```c
  pthread_t thread1; 
  pthread_t thread2; 
  pthread_t thread3; 
  
  t = pthread_create(&thread1, NULL, &media, NULL); 
  pthread_join(thread1, NULL); 
  
  t = pthread_create(&thread2, NULL, &min, NULL); 
  pthread_join(thread2, NULL); 
  
  t = pthread_create(&thread3, NULL, &max, NULL);
  pthread_join(thread3, NULL);
```
Print dos dados
```c
  printf("The average value is %d", average);
  printf("\nThe minimum value is %d", minimum);
  printf("\nThe maximum value is %d", maximum); 
```
Funções de max, min e media
```c
void *media() 
{ 
  int sum = 0;
  for(int i = 1; i <= quant_num; i++) {
    sum = sum + arr[i]; 
  }
  average = sum / quant_num; 
}

void *min() 
{ 
  minimum = arr[1]; 
  for(int i = 1; i < quant_num; i++) {
    if(minimum > arr[i])
    {
      minimum = arr[i]; 
    }
  }
} 

void *max() 
{ 
  maximum = arr[1]; 
  for(int i = 1; i <= quant_num; i++) {
    if(maximum < arr[i]) {
      maximum = arr[i]; 
    }
  }
}
```
# Funções Makefile

Make = Cria o aplicativo binario do codigo.

Make run = Executa o aplicativo.

Make clean = Apaga o aplicativo binario.
