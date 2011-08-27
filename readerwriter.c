#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int counter;
pthread_mutex_t fileavbl;
pthread_mutex_t forcounter;

void writer()
{
    pthread_mutex_lock(&fileavbl);
    printf("Writer is  writing now...\n");
    printf("Writing complete\n");
    pthread_mutex_unlock(&fileavbl);
}

void reader()
{
    int readcount;
    pthread_mutex_lock(&forcounter);
    counter++;
    readcount=counter;
    pthread_mutex_unlock(&forcounter);
    printf("Reader number %d is waiting for file lock \n",readcount);
    pthread_mutex_lock(&fileavbl);
    pthread_mutex_unlock(&fileavbl);
    printf("Reader #%d is now reading file and counter is set to %d\n",readcount,counter);
    pthread_mutex_lock(&forcounter);
    counter--;
    pthread_mutex_unlock(&forcounter);
}

int main()
{
    pthread_mutex_init(&fileavbl,NULL);
    pthread_mutex_init(&forcounter,NULL);
    pthread_t read[4],write;
    pthread_create(&read[0],NULL,(void *)reader,NULL);
    pthread_create(&read[1],NULL,(void *)reader,NULL);
    pthread_create(&read[2],NULL,(void *)reader,NULL);
    pthread_create(&read[3],NULL,(void *)reader,NULL);
    pthread_create(&write,NULL,(void *)writer,NULL);
    pthread_join(read[0],NULL);//,(void *)read,NULL);
    pthread_join(read[1],NULL);//,(void *)read,NULL);
    pthread_join(read[2],NULL);//,(void *)read,NULL);
    pthread_join(read[3],NULL);//,(void *)read,NULL);
    pthread_join(write,NULL);//,(void *)write,NULL);
    printf("Finally counter is %d\n",counter);
    return 0;
}
