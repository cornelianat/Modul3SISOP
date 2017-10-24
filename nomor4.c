#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t lock;
int awal=2;
int simpan;
int c=0;


void *prime(void* end)
{
    printf("\n");

    pthread_mutex_lock(&lock);

    int jawaban=0;
    int *a = (int *) end;
    int jawab=*a;
    int isPrime;
        for(int i=jawab-1; i>=1; i--)
        {
            jawab=jawab*i;
            //printf("%d",jawab);
        }
        printf("%d",jawab);

    //printf ("awal is %d, simpan is %d", awal, simpan);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main (){
    pthread_t tid[1000];
    int t, no;
   // scanf("%c",&fakt);
    printf ("how many threads?\n");
    scanf ("%d",&t);

    for(int i=0;i<t;i++)
    {
        scanf("%d",&simpan);
        pthread_create(&(tid[i]),NULL,prime,&simpan);
    }

    //s=simpan;
    for (int i=0;i<t;i++)
    {

    }

    for (int i=0;i<t;i++)
    {
        pthread_join((tid[i]),NULL);
    }

    printf ("\n");

    pthread_mutex_destroy (&lock);

}
