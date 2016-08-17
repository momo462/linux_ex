#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#define _PATH_NAME_ "/home/momo/homework/4msg"
#define _PROJ_ID_  0x6666
 union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };
//struct sembuf{
//     	     unsigned short sem_num;  /* semaphore number */
//           short          sem_op;   /* semaphore operation */
//           short          sem_flg;  /* operation flags */
//	};
int creat_sem_set(int semset_num);
int get_sem_set();
void destory_sem_set(int sem_id);
int P(int sem_id,int which);
int V(int sem_id,int which);
int init_sem(int sem_id,int which,int val);
