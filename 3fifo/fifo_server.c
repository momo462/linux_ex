#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
//写端
int main()
{
  int ret=mkfifo("./fifo",S_IFIFO|0644);
  if(ret<0)
  {
    perror("mkfifo:");
  }
  int fd=open("./fifo",O_RDONLY);
  if(fd<0)
  {
    perror("open:");
  }
  //write
  char buf[1024];

  while(1)
  {
    memset(buf,'\0',sizeof(buf));
    ssize_t wr=read(fd,buf,sizeof(buf)-1);
    if(wr>0)
    { 
      printf("client# %s\n",buf);
    }

  }
  close(fd);
  return 0;
}
