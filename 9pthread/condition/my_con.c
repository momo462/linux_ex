#include <stdio.h>
//#include "debug.h"
#include <stdlib.h>
#include <pthread.h>

typedef struct node
{
  int data;
  struct node *next;
}node_t,*node_p,**node_pp;

node_p head=NULL;
void  alloc_node(node_pp node,int data)
{
  *node=(node_p)malloc(sizeof(node_t));
  node_p newnode=*node;
  newnode->data=data;
  //printf("alloc :%d ",newnode->data);
  newnode->next=NULL;
}
void init()
{
  alloc_node(&head,0);
}
int is_empty()
{
  if(head->next==NULL)
  {
    return 0;
  }
  else
    return -1;
}
int push_front(node_p head,int data)
{

  node_p tmp;
  alloc_node(&tmp,data);
  if(tmp==NULL)
  {
    return -1;
  }
  tmp->next=head->next;
  head->next=tmp;
  return 0;
}
void pop_front(node_p head,int *data)
{
  if(is_empty()==0)
  {
    return;
  }
  node_p tmp=head->next;
  *data=tmp->data;
  head->next=tmp->next;
  free(tmp);
}
void show(node_p head)
{
  node_p phead=head->next;
  while(phead)
  {
    printf("%d ",phead->data);
    phead=phead->next;
  }
  printf("\n");
}

pthread_cond_t cond1;
pthread_mutex_t lock1,lock2,lock3;

//消费者等生产者通知
void *consumer(void *arg)
{
	while(1)
	{
	  //pthread_mutex_lock(&lock2);
	  pthread_mutex_lock(&lock1);
	  while(is_empty(head)==0)
	  {
		 printf("consumer is not ready!\n");
		//1、释放mutex 2、阻塞等待 3、被唤醒，metux获得
	       pthread_cond_wait(&cond1,&lock1);
		 printf("consumer is ready!\n");
	  }

	  int data=0;
	  pop_front(head,&data);
	  printf("consumer is done...%d\n",data);
	  pthread_mutex_unlock(&lock1);
    //pthread_mutex_unlock(&lock2);
    sleep(1);
	}
}
//生产者生产
void *producter(void *arg)
{

 	while(1)
	{
    //pthread_mutex_lock(&lock3);
		pthread_mutex_lock(&lock1);
		int data=rand()%1234;
		push_front(head,data);
		pthread_mutex_unlock(&lock1);
   // pthread_mutex_unlock(&lock3);
		printf("producter is done ...%d\n",data);
		sleep(1);
		pthread_cond_signal(&cond1);
	}
}
int main()
{
   init(head);
  pthread_t id1,id2,id3,id4;
  pthread_cond_init(&cond1,NULL);
  pthread_mutex_init(&lock1,NULL);
  pthread_mutex_init(&lock2,NULL);
  pthread_mutex_init(&lock3,NULL);
  pthread_create(&id1,NULL,consumer,(void *)1);
 // pthread_create(&id3,NULL,consumer,(void *)2);
  pthread_create(&id2,NULL,producter,(void*)1);
 // pthread_create(&id4,NULL,producter,(void*)2);
 
   pthread_join(id1,NULL);
   pthread_join(id2,NULL);
  // pthread_join(id3,NULL);
  // pthread_join(id4,NULL);
   pthread_cond_destroy(&cond1);
   pthread_mutex_destroy(&lock1);
   pthread_mutex_destroy(&lock2);
   pthread_mutex_destroy(&lock3);
}
//int main()
//{
//  init(head);
//  int i=0;
//  for(i;i<10;i++)
//  {
//    push_front(head,i);
//    show(head);
//  
// }
// for(i=0;i<10;i++)
// {
//   int a;
//   pop_front(head,&a);
//   show(head);
// }
//  return 0;
//}
