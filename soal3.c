#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
int status[2];
pthread_t tid[3];
void* loting(void *arg){
	pthread_t id=pthread_self();
	if(pthread_equal(id,tid[0])==0){
		int ikan;
		while(status[0]>=1 && status[1]>=1 && status[0]<=100 && status[1]<=100){
			printf("Beri makan ikan!\n1. Lohan %d\n2. Kepiting %d\n",status[0],status[1]);
			scanf("%d", &ikan);
			if(ikan==1) status[0]+=10;
			else status[1]+=10;
		}
		printf("Wah u gagals!\n");
	}
	else if(pthread_equal(id,tid[1])==0){
		while(status[0]>=1 && status[1]>=1 && status[0]<=100 && status[1]<=100){
			sleep(1);
			status[0]-=15;
		}
	}
	else if(pthread_equal(id,tid[2])==0){
		while(status[0]>=1 && status[1]>=1 && status[0]<=100 && status[1]<=100){
			sleep(1);
			status[1]-=10;
		}
	}
	return NULL;
}
int main(void){
	status[0]=100;
	status[1]=100;
	int i=0;
	int err;
	while(i<3){
		err=pthread_create(&(tid[i]),NULL,&loting,NULL);
		i++;
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_join(tid[2],NULL);
	return 0;
}
