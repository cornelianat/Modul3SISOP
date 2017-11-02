#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
pthread_t tid[100];
char nov[2000];
int l;
void* ifah(void* arg){
	char *nuz=(char*)arg;
//	char *nuz;
//	nuz=(char*)arg;
	int n=strlen(nuz);
	int a,b,ifah=0;
	for(a=0;a<l-n;a++){
		int flag=1;
		for(b=0;b<n;b++){
			if(nov[a+b]!=nuz[b]){
				flag=0;
				break;
			}
		}
		if(flag) ifah++;
	}
	printf("%s = %d\n", nuz,ifah);
}
//void* fina(void* arg){
//	char *nuz=(char*)arg;
//	int n=strlen(nuz);
//	int a,b,fina=0;
//	for(a=0;a<l-n;a++){
//		int flag=1;
//		for(b=0;b<n;b++){
//			if(nov[a+b]!=nuz[b]){
//				flag=0;
//				break;
//			}
//		}
//		if(flag) fina++;
//	}
//	printf("%s = %d\n", nuz,fina);
//}
int main(int argc, char** argv){
	FILE *f;
	f=fopen("Novel.txt","r");
	char c;
	int i=0;
	do{
		c=fgetc(f);
		nov[i]=c;
		i++;
	}while(c!=EOF);
	for(i=1;i<argc;i++){
		pthread_create(&(tid[i]),NULL,&ifah,(void*)argv[i]);
		pthread_join(tid[i],NULL);
	}
//	char nama1[100],nama2[100];
//	scanf("%s %s", &nama1,&nama2);
//	l=strlen(nov);
//	pthread_create(&(tid1),NULL,&ifah,(void*)nama1);
//	pthread_create(&(tid2),NULL,&fina,(void*)nama2);
//	pthread_join(tid1,NULL);
//	pthread_join(tid2,NULL);
}
