#include "comm.h"
int server_type= 1;
int client_type= 2;
//create msg queue
static int comm_msg_queue(int flag)
{
  key_t  key=ftok(_PATH_NAME_,_PROJ_ID_);
  if(key<0)
  {
    perror("ftok:");
    return -1;
  }
  int msg_id=msgget(key,flag);
  if(msg_id< 0)
  {
    perror("msgget:");
    return -1;
  }
  return msg_id;
}
int create_msg_queue()
{
  int flag=IPC_CREAT|IPC_EXCL|0666;
  return comm_msg_queue(flag);
}
int get_msg_queue()
{
  int flag=IPC_CREAT;
  return comm_msg_queue(flag);
}

//
void destory_msg_queue(int msg_id)
{
  if(msgctl(msg_id,IPC_RMID,0)==0)
  {
    return;
  }
  else
  {
    perror("msgctl");
  }
}


//
void send_msg_queue(int msg_id,const char *in,int type)
{
  struct msgbuf m1;
  memset(m1.mtext,'\0',sizeof(m1.mtext));
  m1.mtype=type;
  strcpy(m1.mtext,in);
  ssize_t send=msgsnd(msg_id,&m1,sizeof(m1.mtext),0);
  if(send<0)
  {
    perror("msgsnd");
  }
}


void recv_msg_queue(int msg_id,char *out,int type)
{

  struct msgbuf m1;
  memset(m1.mtext,'\0',sizeof(m1.mtext));
  m1.mtype=type;
  ssize_t recv=msgrcv(msg_id,&m1,sizeof(m1.mtext),type,0);
  if(recv<0)
   {
 	perror("msgrcv");
  }
  strcpy(out,m1.mtext);
}

