#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

int num_files=5;
// Semaphores for each file, 1 => can write
sem_t *lck;

void* reader(void* tid){
  while(true){
    sem_wait( &lck[(long)tid] );
    sleep(1);
    cout<<(long)tid<<" read "<<endl;
    sem_post( &lck[(long)tid]);
  }
}

void* writer(void* tid){
  while(true){
    sem_wait( &lck[(long)tid] );
    sleep(1);
    cout<<(long)tid<<" written "<<endl;
    sem_post( &lck[(long)tid]);
  }
}

int main(){
  lck= new sem_t[num_files];
  for(int i=0;i<num_files;i++){
    sem_init(&lck[i],0,1);
  }

  pthread_t rdr,wtr;

  for(int i=0;i<num_files;i++){
    pthread_create(&wtr,NULL,writer,(void*)i);
    pthread_create(&rdr,NULL,reader,(void*)i);
  }
  pthread_exit(NULL);
}
