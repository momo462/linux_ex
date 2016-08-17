#pragma once

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define _PATH_NAME_ "/home/momo/homework/4msg"
#define _PROJ_ID_  0x6666
#define _SIZE_ 1024

struct msgbuf
{
   long mtype;
   char mtext[_SIZE_];
};
extern int server_type;
extern int client_type;
//create msg queue
int create_msg_queue();

int get_msg_queue();

//
void destory_msg_queue(int msg_id);

//
void send_msg_queue(int msg_id,const char *in,int type);

//
void recv_msg_queue(int msg_id,char *out,int type);
