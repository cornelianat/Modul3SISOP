#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t lock;
int awal=2;
int simpan;
int c=0;


void *faktorial(void* end)
{
    printf("\n");

    //pthread_mutex_lock(&lock);
    //printf("%s\n",(char*)end);
  
    int jawaban=0;
    int a = (int) end;
    int jawab=(int)strtol((char *)end,NULL,10);
    int temp=jawab;
    //printf("%d\n",jawab);
    int isPrime;
        for(int i=jawab-1; i>=1; i--)
        {
            jawab=jawab*i;
        }
        printf("Hasil %d!=%d\n",temp,jawab);

    //printf ("awal is %d, simpan is %d", awal, simpan);
    //pthread_mutex_unlock(&lock);

    return NULL;
}

int main (int argc, char *argv[]){
    pthread_t tid[1000];
    int t, no;

    for(int i=0;i<argc-1;i++)
    {
        //scanf("%d",&simpan);
	//printf("%s",argv[i+1]);
        pthread_create(&(tid[i]),NULL,&faktorial,(void *)argv[i+1]);
    }

    //s=simpan;
   
    for (int i=0;i<argc-1;i++)
    {
        pthread_join((tid[i]),NULL);
    }

    printf ("\n");

    pthread_mutex_destroy (&lock);

}
