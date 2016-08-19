#include "comm.h"

static int comm_shm(int size,int flag)
{
   key_t key=ftok(_PATH_NAME_,_PROJ_ID_);
   if(key<0)
   {
     perror("ftok");
   }
   int shm_id=shmget(key,size,flag);
   if(shm_id < 0)
   {
    perror("shmget");
   }
   return shm_id;
}
int creat_shm(int size)
{
  int flag=IPC_CREAT|IPC_EXCL|0666;
  return comm_shm(size,flag);
}

int get_shm()
{
  int flag=IPC_CREAT;
  return comm_shm(0,flag);
}

void destroy_shm(int shm_id)
{
  if(shmctl(shm_id,IPC_RMID,NULL)<0)
  {
    perror("shmctl");
  }
}
void *at(int shm_id)
{
  void *p=shmat(shm_id,NULL,0);
  if(p==NULL)
  {
    perror("shmat");
  }
  return p;
}

void dt(char *addr)
{
  if(shmdt((void *)addr)<0)
  {
    perror("shmdt");
  }
}
