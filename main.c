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
