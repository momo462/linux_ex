#include "comm.h"

int main()
{
  int msg_id=get_msg_queue();
  int done=0;
  char buf[1024];
  while(!done)
  {
    //发数据
    printf("Please Enter# ");
    fflush(stdout);
    ssize_t s=read(0,buf,sizeof(buf)-1);
    if(s<0)
    {
       perror("read");
    }
    else
    {
      buf[s-1]='\0';
    }
    send_msg_queue(msg_id,buf,client_type);
    memset(buf,'\0',sizeof(buf));
    recv_msg_queue(msg_id,buf,server_type);
    printf("server # %s\n",buf);

  }
  return 0;
}
