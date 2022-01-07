#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define PCALLS 200

void* phonecall(void* vargp);
void print_array(pthread_t arr[]);

volatile int next_id = 1;
sem_t lock;
sem_t operators;

int main(void)
{
  //int seconds = argc;     //Total number of seconds for the debate

  pthread_t calls[PCALLS];     //Total number of phonecalls
  void* return_values[PCALLS]; //Return values of thread function

  //Semaphores
  sem_init(&lock, 0 , 1);      //Thread ID incrementer, 1 at a time
  sem_init(&operators, 0 , 2); //Available operators

  //loop that creates a new thread for each call and assigns next_id
  for(int i= 0; i < PCALLS; ++i)
  {  
    pthread_create(&calls[i], NULL, phonecall, (void *) &next_id);
    pthread_join(&calls[i], void **__thread_return)
  }
  
  // print_array(calls);

  return 0;
}


void* phonecall(void* vargp)
{
  //Only lets one thread in at a time, should be quick though
  sem_wait(&lock);
  int id = *((int*) (vargp));     //Local variable exclusive to each thread --> LOADING VARIABLE
  next_id++;
  sem_post(&lock);

  // if(next_id == 200)
  // {
  //   sem_destroy(&lock);   //thread with id value 200 may come before lower numbers
  // }

  // sem_wait(&operators);
  // //Handler question from phonecall
  // sem_post(&operators);
}

void print_array(pthread_t arr[])
{
  for(int i = 0; i < 200; i++)
  {
    
  }
}