#include <stdio.h>
#include <pthread.h>
//#include <stdlib.h>
//#include <string.h>
int index=0;
pthread_mutex_t lock;
void *count(void *arg)
{
  pthread_mutex_lock(&lock);
  int i=0;
  for(i=0;i<5000;i++)
  {
    int val=index;
    printf("count=%d\n",index);
    index+=1;
  }
  pthread_mutex_unlock(&lock);
  return NULL;
}
int main()
{
  pthread_t id1,id2;
  pthread_mutex_init(&lock,NULL);
  pthread_create(&id1,NULL,count,NULL);
  pthread_create(&id2,NULL,count,NULL);

  pthread_join(id1,NULL);
  pthread_join(id2,NULL);
  pthread_mutex_destroy(&lock);
}
//通过return退出当前线程
//void *thread1(void *arg)
//{
//  printf("thread1\n");
//  return (void *)1;
//}
////通过pthread_exit退出当前线程
//void *thread2(void *arg)
//{
//  printf("thread2\n");
//  pthread_exit((void *)2);
//}
////通过被其他进程pthread_cancel掉
//void *thread3(void *arg)
//{
//  while(1){
//    printf("thread3\n");
//    sleep(1);
//  }
//}
//int main()
//{
//  pthread_t p3;
//  void * ret3;
//  int thread=pthread_create(&p3,NULL,thread3,NULL);
//  if(thread!=0)
//  {
//    printf("pthread_create is failed %s\n",strerror(thread));
//  }
//  sleep(3);
//  pthread_detach(p3);
//  pthread_cancel(p3);
//
// // int pj=pthread_join(p3,&ret3);
//  //if(pj!=0)
//  //{
//   // printf("pthread_join %s\n",strerror(pj));
//  //}
// // printf("thread3 return :%d\n",(int)ret3);
//  return 0;
//}
////int main()
//{
//  pthread_t p2;
//  void * ret2;
//  int thread=pthread_create(&p2,NULL,thread2,NULL);
//  if(thread!=0)
//  {
//    printf("pthread_create is failed %s\n",strerror(thread));
//  }
//  int pj=pthread_join(p2,&ret2);
//  if(pj!=0)
//  {
//    printf("pthread_join %s\n",strerror(pj));
//  }
//  printf("thread2 return :%d\n",(int)ret2);
//  return 0;
//}
//int main()
//{
//  pthread_t p1;
//  void * ret1;
//  int thread=pthread_create(&p1,NULL,thread1,NULL);
//  if(thread!=0)
//  {
//    printf("pthread_create is failed %s\n",strerror(thread));
//  }
//  int pj=pthread_join(p1,&ret1);
//  if(pj!=0)
//  {
//    printf("pthread_join %s\n",strerror(pj));
//  }
//  printf("thread1 return :%d\n",(int)ret1);
//  return 0;
//}
//pthread_t p1;
//void *pthreadrun(void * arg)
//{
// // printf("i am a new thread %d\n",(int)arg);
//  printf("%s:pid is:%d,tid is：%u\n",(char *)arg,getpid(),p1);//pthread_self());
//  return NULL;
//}
//int main()
//{
//  //pthread_t p1;
//  int thread=pthread_create(&p1,NULL,pthreadrun,"the new thread");
//  if(thread!=0)
//  {
//      //因为错误码没有由errno获得，是由thread这个返回值获得，所以需要把thread转化以下，不能直接用perror
//      printf("pthread_create is failed :%s\n",strerror(thread));
//  }
//  printf("the main thread:pid is %d,tid is:%u\n",getpid(),pthread_self());
//  
//  //sleep一秒，是为了尽可能在主线程运行时，os更大程度会调度到子线程。
//  sleep(1);
//  return 0;
//}
