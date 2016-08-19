#include "comm.h"


int main()
{
  //创建
  int shm_id=creat_shm(4096);
  //读
  char *buf=(char *)at(shm_id);
  while(1)
  { 
    
    printf("client: %s",buf);
    fflush(stdout);
//   printf("please enter:");
//    fflush(stdout);
//    memset(buf,'\0',sizeof(buf));
//    ssize_t  s=read(0,buf,sizeof(buf));
//    if(s<0)
//    {
//      perror("read");
//    }
//    else{
//      buf[s-1]='\0';
//    }
  }
  dt(buf);
  destroy_shm(shm_id);
  return 0;
}
