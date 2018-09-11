#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <execinfo.h>
#include <signal.h>
#include <ucontext.h>
#include <unistd.h>

#define HEADER_LENGTH 5
#define END_LENGTH 8

unsigned char *header="\x89PNG\r";
unsigned char *end="IEND\xae\x42\x60\x82";
int loop=1;

void sh(int sig,siginfo_t inff,void* ptrr){
  void *array[52];
  char **messages;
  int size;
  
  printf("Signal %d (%s) received!\n\nDumping Stacks...",sig,strsignal(sig));
  size=backtrace(array,52);
  messages=backtrace_symbols(array,size);
  
  for(int i=0;i<size && messages!=NULL;i++){
    printf("#%d: %s\n",i,messages[i]);
  }
  free(messages);
  exit(sig);
  
}

void main(int argc,char *argv[]){
  struct sigaction sa;
  sa.sa_sigaction=sh;
  sa.sa_flags=SA_RESTART|SA_SIGINFO;
  sigaction(SIGSEGV,&sa,(struct sigaction *)NULL);
  
if(argc!=2){
printf("getpng <file>\n");exit(1);
}
FILE *file=fopen(argv[1],"rb");
int gett=0;
int done=0;
char fn[128]={0};
while(1){
gett=fgetc(file);
if(gett==EOF){exit(0);}
if(gett==header[done]){
done++;
if(done==HEADER_LENGTH){
done=0;
memset(fn,128,0);
sprintf(fn,"%s_%d.png",argv[1],loop);
loop++;
FILE *out=fopen(fn,"wb");
fputc('\x89',out);fputc('P',out);fputc('N',out);fputc('G',out);fputc('\r',out);
while(1){
gett=fgetc(file);
if(gett==EOF){printf("ERROR: EOF TOO FIRST\n");exit(3);}
fputc(gett,out);
if(gett==end[done]){
done++;
if(done==END_LENGTH){done=0;printf("Found png %d=>%s\n",loop-1,fn);fclose(out);break;}
continue;
  }
if(done!=0){done=0;}

   }
   }continue;
  }
  if(done!=0){done=0;}

 }
 //if(done!=0){done=0;}
}
