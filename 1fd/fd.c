#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
  //关闭stdout
   close(1);
   int fd=open("./log",O_CREAT|O_WRONLY,0644);
   if(fd< 0)
   {
    printf("%d \t %s\n",errno,strerror(errno));
    return 1;
   }
   printf("fd=%d\n",fd);
   int count =5;
   while(count -- >0)
   {
    printf("hello world %d\n",count);
    fflush(stdout);
   }
   close(fd);
   return 0;
 }
