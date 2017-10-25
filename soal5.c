#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
pthread_t tid[100];
void* cari(void* args){
	char *string;	
	int n=0;
	FILE *f;
	f=fopen("Novel.txt","r");
	while(!feof(f)){
		fscanf(f,"%s",string);
		if(strcmp(string,args)==0) n++;	
	}
	printf("%s = %d\n", args,n);
	return NULL;
}
int main(void){
	int i=0;
	char nama[100];
	while(1)
	{
		scanf("%s",nama);
		pthread_create(&(tid[i]),NULL,&cari,(void*) nama);
		pthread_join(tid[i],NULL);
		i++;
	}
	return 0;
}
