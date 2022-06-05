// OPERATING SYSTEMS PACKAGE SEM-4
// LET US ASSUME THAT THERE ARE TWO TRACKS AND ONE CROSS. IT IS OBIVIOUS THAT ONLY ONE TRAIN MUST PASS THROUGH THE CROSS AT A TIME
// SINCE THERE ARE TWO TRACKS LET US ASSUME THAT DRIVING A TRAIN FROM TRACK ONE AND TWO ARE THREADS ONE AND TWO RESPECTIVELY...AND HENCE
// CROSS IS CRITICAL SYSTEM WHICH IMPLIES THIS IS A CRITICAL SECTION PROBLEM
#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <sched.h>


#define false 0
#define true 1
typedef int bool;
//#define bool int


pthread_t tid[2];
volatile int x = 0;
bool FROM_TRACK_ONE = false;
bool FROM_TRACK_TWO = false;
int turn = 1;

void * criticalSection(int n) {

  x++;
printf("THE CROSS IS ACCESED BY %d\n",n);
}

void* FROM_ROUTE_ONE() {
  FROM_TRACK_ONE = true;//
  while(FROM_TRACK_TWO) {
    if(turn == 2) {
      FROM_TRACK_ONE = false;
      pthread_yield();//
      while(turn != 1) {

      }
      FROM_TRACK_ONE = true;
    }
  }
  criticalSection(1);
  turn = 2;
  FROM_TRACK_ONE = false;
}

void* FROM_ROUTE_2() {
  FROM_TRACK_TWO = true;
  while(FROM_TRACK_ONE) {
    if(turn == 1) {
      FROM_TRACK_TWO = false;
      pthread_yield();
      while(turn != 2) {

      }
      FROM_TRACK_TWO = true;
    }
  }
  criticalSection(2);
  turn = 1;
  FROM_TRACK_TWO = false;
}


void* ACCESS_CROSS_ROUTE() {
  int i;
  for(i = 0; i < 50000; i++) {
    pthread_t id = pthread_self();
    if(pthread_equal(id,tid[0])){
      FROM_ROUTE_ONE();
    } else if(pthread_equal(id, tid[1])) {
      FROM_ROUTE_2();
    }
  }
}
/*
DONT PANIC JUST ALGO
main(){
   int thread_no = 1;
   startThreads();
}
Thread1(){
   do {
      // entry section
      // wait until threadno is 1
      while (threado == 2)
            ;
      // critical section
      // exit section
      // give access to the other thread
      threadno = 2;
      // remainder section
   } while (completed == false)
}
Thread2(){
   do {
      // entry section
      // wait until threadno is 2
      while (threadno == 1)
            ;
      // critical section
      // exit section
      // give access to the other thread
      threadno = 1;
      // remainder section
   } while (completed == false)
}*/

int main() {
  pthread_attr_t myattr;
  cpu_set_t cpuset;//............googling helps

  pthread_attr_init(&myattr);
  CPU_ZERO(&cpuset);
  CPU_SET(0, &cpuset);
        //CPU_SET(i, &mask);

  pthread_attr_setaffinity_np(&myattr, sizeof(cpu_set_t), &cpuset);

  pthread_create(&(tid[0]), &myattr, &ACCESS_CROSS_ROUTE, NULL);
  pthread_create(&(tid[1]), &myattr, &ACCESS_CROSS_ROUTE, NULL);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  printf("Final output of x : ");
  printf("x: %i\n", x);
}