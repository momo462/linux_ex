#include "comm.h"

static int comm_sem_set(int semset_num,int flag)
{
  key_t key=ftok(_PATH_NAME_,_PROJ_ID_);
  int sem_id=semget(key,semset_num,flag);
  if(sem_id<0)
  {
    perror("semget");
  }
  return sem_id;
}
int creat_sem_set(int semset_num)
{ 
  int flag=IPC_CREAT|IPC_EXCL|0666;
  return comm_sem_set(semset_num,flag);
}
int get_sem_set()
{
   int flag=IPC_CREAT;
   return comm_sem_set(0,0);
}
void destory_sem_set(int sem_id)
{
  if(semctl(sem_id,0,IPC_RMID)<0)
  {
    perror("semctl");
  }
}
int init_sem(int sem_id,int which,int val)
{
  union semun _un;
  _un.val=val;
  int s=semctl(sem_id,which,SETVAL,_un);
  if(s<0)
  {
    perror("semctl");
  }
  else
  {
    return s;
  }
  
}
int P(int sem_id,int which)
{
  struct sembuf se;
  se.sem_num=which;
  se.sem_op= -1;
  se.sem_flg=0;
  int ret=semop(sem_id,&se,1);

}
int V(int sem_id,int which)
{
  struct sembuf se;
  se.sem_num=which;
  se.sem_op=1;
  se.sem_flg=0;
  int ret=semop(sem_id,&se,1);
}
