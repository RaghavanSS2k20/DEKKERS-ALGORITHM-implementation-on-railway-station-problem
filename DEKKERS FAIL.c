#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int REQUEST[2] = {0, 0};
//#include<windows.h>
int accessing_cs[2] = {0, 0};
int turn=0;
void criticalSection(int itr,int number){
        printf("CRITICAL SECTION ACCESED ON ITERATION %d AND BY PROCESS %d\n",itr,number);

}
//1st process or second one
void *dekker(void *FIRST_OR_SECOND) {
        int *arg = FIRST_OR_SECOND;
        int num = *arg;
/*      printf("Let us check for  how many process does this  dekkers algo. holds");
        printf("Enter number of threads you need to load the processor : ");
        int numb;
        scanf("%d",&numb);*/
        int other = (num + 1) % 2;
        //looped so that representation of multiple process on multiple core
        
 
        for (int i = 0; i < 10000; i++) {
                REQUEST[num] = 1;
                while (REQUEST[other]) {
                        if (turn != num) {
                                REQUEST[num] = 0;
                                while (turn != num);
                                REQUEST[num] = 1;
                        }
                }
                // Critical section
                criticalSection(i,num);
                accessing_cs[num] = 1;
                        // MAKING PROCESS STAY busy wait
                //sleep(1000)
                //makewait(20000)
                for (int j = 0; j < 100000; j++);
                accessing_cs[num] = 0;
                turn = other;
                REQUEST[num] = 0;
        }
        //return  pthread_t()
        return NULL;
}


/*
 A checker that will run infinitely, checking if both threads in dekker algorithm were
 in the critical section at the same time, violating mutual exclusion

 prints when  the mutual exclusion is violated
*/
void *checker(void *vargs) {
        while (1) {
        if (accessing_cs[0] && accessing_cs[1]) {
                        printf("BOTH WERE INSIDE!!!!\n");
                        exit(1);
                        return NULL;
                }
        }
        return NULL;
}

int main() {
        pthread_t t1;
        pthread_t t2;
        int num1 = 0;
        int num2 = 1;
        pthread_t t_check;

        pthread_create(&t_check, NULL, checker, NULL);
        pthread_create(&t1, NULL, dekker, &num1);
        pthread_create(&t2, NULL, dekker, &num2);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        printf("WE ARE OKAY, MUTUAL EXLUSION PRESERVED\n");
        exit(0);
}