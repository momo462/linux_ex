#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
pthread_cond_t cond;
typedef struct ListNode
{
	int data;
    struct ListNode* next;
}node,*node_p, **node_pp;

node_p head=NULL;
void alloc_list(node_pp head,int _data)
{
	*head=(node_p)malloc(sizeof(node));
	(*head)->data=_data;
    (*head)->next=NULL;
	
	return;
}
void PushFront(node_p list,int _data)
{
   node_p tmp;
   alloc_list(&tmp,_data);
   tmp->next=list->next;
   list->next=tmp;
}
int isempty(node_p list)
{
	return list->next==NULL?1:0;
}
void PopFront(node_p list,int *data)
{
	if(!isempty(list))
	{
		node_p del=list->next;
	    list->next=del->next;
		*data=del->data;
	    free(del);
	}

}
void show(node_p list)
{
    node_p start=list->next;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
	printf("\n");
}

void *consum(void* arg)
{
	while(1)
	{
	  pthread_mutex_lock(&lock);
	  if(!isempty(head))
	  {
		  int data=0;
	      PopFront(head,&data);
	      printf("%d\n",data);
	  }
	  printf("haha.....\n");
	  pthread_mutex_unlock(&lock);
	  sleep(5);
	}

}
void *product(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		int data=rand()%1234;
		PushFront(head,data);
		printf("%d\n",data);
		pthread_mutex_unlock(&lock);
		sleep(1);
	}

}
int main()
{
	int i=0;
    alloc_list(&head,0);
    pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_t id1,id2;
    pthread_create(&id1,NULL,consum,NULL);
	pthread_create(&id2,NULL,product,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);
	return 0;
}
