#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
  struct stat s1;
  if(argc!=2)
  {
    perror("argc less");
  }
  stat(argv[1],&s1);
  printf("id:%lx\t inode:%lx\t proc_id:%x\n",s1.st_dev,s1.st_ino,ftok(argv[1],0x57));
}
