#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
  int fd=open("./fifo",O_WRONLY);
  if(fd<0)
  {
    perror("open:");
  }
  char buf[1024];

  while(1)
  {
   printf("please enter #");
   fflush(stdout);
   ssize_t s=read(1,buf,sizeof(buf));
   if(s>0)
   {  
     buf[s-1]='\0';
     write(fd,buf,sizeof(buf)-1);
   }
  }
  close(fd);
  return 0;
}
