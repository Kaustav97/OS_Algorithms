#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

int buffsz=5,num_threads=3;
sem_t empty,full;

void* producer(void* tid){
  while(true){
    sem_wait(&empty);
    cout<<(long)tid<<" produced "<<endl;
    sleep(2);
    sem_post(&full);
  }
}

void* consumer(void* tid){
  while(true){
    sem_wait(&full);
    sleep(2);
    cout<<(long)tid<<" consumed "<<endl;
    sem_post(&empty);
  }
}

int main(){
  sem_init(&empty,0,buffsz);
  sem_init(&full,0,0);

  pthread_t prod,cons;

  for(int i=0;i<num_threads;i++){
    pthread_create(&prod,NULL,producer,(void*)i);
    pthread_create(&cons,NULL,consumer,(void*)i);
  }
  pthread_exit(NULL);

}
