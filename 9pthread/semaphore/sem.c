#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int round[64];
sem_t space_nums;
sem_t data_nums;

void *consumer(void *arg)
{
  int index=0;
  while(1)
  {
    sem_wait(&data_nums);
    int num=round[index];
    printf("%d consumeris done...%d\n",index,num);
    sem_post(&space_nums);
    index++;
    index%=64;
    sleep(1);

  }
}

void *producter(void *arg)
{
  int index=0;
  while(1)
  {
    //space_nums--;
    sem_wait(&space_nums);
    int num=rand()%123;
    round[index]=num;
    printf("%d producteris done...%d\n",index,num);
    sem_post(&data_nums);
    index++;
    index%=64;
    sleep(1);
  }
}
int main()
{
  pthread_t id1,id2,id3,id4;
  sem_init(&space_nums,0,64);
  sem_init(&data_nums,0,0);
  pthread_create(&id1,NULL,consumer,(void *)1);
  //pthread_create(&id3,NULL,consumer,(void *)2);
  pthread_create(&id2,NULL,producter,(void *)1);
  //pthread_create(&id4,NULL,producter,(void *)2);

  pthread_join(id1,NULL);
  //pthread_join(id3,NULL);
  //pthread_join(id4,NULL);
  pthread_join(id2,NULL);

  sem_destroy(&space_nums);
  sem_destroy(&data_nums);
}
