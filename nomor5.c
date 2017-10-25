#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t lock;
int awal=2;
int simpan;
int c=0;


void *baca(void* end)
{
    printf("\n");

    FILE *ptr_file;

    ptr_file = fopen("Novel.txt","r"); // my input text file

    printf("%d",wordcount);
    return NULL;
}

int main (int argc, char *argv[])
{
    pthread_t tid[1000];
    int t, no;
     char jawab=(char*) end;
    char buf[200];
    char key[] = "Fina"; // the string I am searching for
    int wordcount = 0;

    for(int i=0;i<argc-1;i++)
    {

        pthread_create(&(tid[i]),NULL,&baca,(void *)argv[i+1]);
        while (fgets(buf,200, ptr_file)!=NULL)
        {
            if((strstr(buf,key)) !=NULL)
            {
                wordcount++;
            }
        }
    }

    //s=simpan;

    for (int i=0;i<argc-1;i++)
    {
        pthread_join((tid[i]),NULL);
    }

    printf ("\n");

    pthread_mutex_destroy (&lock);

}
