#include <stdio.h>
#include "comm.h"

int main()
{

  //server创建消息队列
  int msg_id=create_msg_queue();
  //如果sever先收数据再发数据
  char buf[1024];
  int done=0;
  while(!done)
  {
    memset(buf,'\0',sizeof(buf));
    recv_msg_queue(msg_id,buf,client_type);
    printf("client #%s\n",buf);
    printf("Please Enter #");
    fflush(stdout);
    ssize_t r=read(0,buf,sizeof(buf)-1);
    if(r<0)
    {
      perror("read");
    }
    else
    {
      buf[r-1]='\0';//bug
    }
    send_msg_queue(msg_id,buf,server_type); 
  }
  destory_msg_queue(msg_id);
  return 0;
}
