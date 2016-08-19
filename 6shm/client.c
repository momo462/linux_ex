#include "comm.h"

int main()
{
  int shm_id=get_shm();
  char *buf;
  buf=(char *)at(shm_id);
  while(1)
  {
    memset(buf,'\0',sizeof(buf));
    int i=0;
    for(i;i<sizeof(buf);i++)
    {
      buf[i]='A';
    }
    buf[strlen[buf]]='\0';
  }
}
