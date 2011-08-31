//Sleeps pauses the thread, not the process.
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void printalot()
{
    int i=1;
    while(1) {
        printf("Hi! I am %d \n",i++);
    }
}

void sleepalot()
{
    printf("I am about to sleep...\n");
    sleep(10);
    printf("And I'm up already!\n");exit(0);
}

int main()
{
    pthread_t print,sleep;
    pthread_create(&print,NULL,(void *)printalot,NULL);
    pthread_create(&sleep,NULL,(void *)sleepalot,NULL);
    pthread_join(sleep,NULL);
    pthread_join(print,NULL);
    return 0;
}
