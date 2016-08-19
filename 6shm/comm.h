#pragma once

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#define _PATH_NAME_ "/tmp"
#define _PROJ_ID_ 0666
int  creat_shm(int size);
int get_shm();
void destroy_shm(int shm_id);
void* at(int shm_id);
void dt(char *addr);
