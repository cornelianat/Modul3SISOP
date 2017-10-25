#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
struct list{
int jml;
char sen[100];
};
int n;
pthread_t tid[2];
void* tred(void *arg){
struct list li[100];
char nama[100];
int j,i;
pthread_t id=pthread_self();
if(pthread_equal(id,tid[0])){
for(i=0;i<n;i++){
if(li[i].jml>0) printf("%s\n",li[i].sen);
}
}
else{
int flag;
scanf("%s %d",nama,&j);
for(i=0;i<n;i++){
if(strcmp(li[i].sen,nama)==0){
li[i].jml+=j;
flag=0;
break;
}
else flag=1;
}
if(flag){
strcpy(li[n].sen,nama);
li[n].jml=j;
n++;
}
}
//return NULL;
}
int main(){
int err;
n=0;
char command[100];
char argument[100];
char *path="/home/farizmpr/nuzha";
chdir(path);
printf("Sistem Informasi\n1. Lihat Senjata\n2. Tambah Senjata\n");
while(1){
scanf("%s",command);
if(strcmp(command,"lihat")==0) err=pthread_create(&(tid[0]),NULL,&tred,NULL);
else err=pthread_create(&(tid[1]),NULL,&tred,NULL);
}
}
