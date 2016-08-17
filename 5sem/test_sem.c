#include "comm.h"

int main()
{
  int semset_num= 1;
  int sem_id=creat_sem_set(semset_num);
  int s=init_sem(sem_id,0,1);
  pid_t pid=fork();
  if(pid==0)
  {
    while(1)
    {
      int sem_id_child=get_sem_set();
       P(sem_id_child,0);
       printf("A");
       fflush(stdout);
       usleep(rand()%10000);
       printf("A");
       fflush(stdout);
       usleep(rand()%12345);
       V(sem_id_child,0);
    }
  }
  else{
    while(1)
    {
       P(sem_id,0);
       printf("B");
       fflush(stdout);
       usleep(rand()%12233);
       printf("B");
       fflush(stdout);
       usleep(rand()%12233);
       V(sem_id,0);
    }
    wait(NULL);
  }
  destory_sem_set(sem_id);
  return 0;
}
