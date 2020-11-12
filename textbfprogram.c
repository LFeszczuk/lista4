#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<setjmp.h>

int sig=0;
int sigcnt=0;
void sighandler(int signum){

 sigcnt++;
 printf("Sygnal przechwycony");
sig = signum;    
}
void sighandler2(int signum){

 sigcnt++;
 for(int i=0;i<10000;i++)
 {}
 printf("Sygnal przechwycony");
sig = signum;    
}
main()
{
int i; i=0;
//int *ip;

signal(SIGALRM,sighandler);
signal(SIGTERM,SIG_BLOCK);
signal(SIGUSR1,SIG_IGN);
signal(SIGUSR2,sighandler2);
do{
printf("tyle było powtorzen %d",i);
sleep(1);
i++;
} while(1);
return 0;
}
