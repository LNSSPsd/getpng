#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char header[4]={0x89,0x50,0x4E,0x47};
char end[4]={0xAE,0x42,0x60,0x82};
int loop=1;

void main(int argc,char *argv[]){
if(argc!=2){
printf("getpng <file>\n");exit(1);
}
FILE *file=fopen(argv[1],"rb");
int gett;
int done=0;
char fn[128]={0};
while(1){
gett=fgetc(file);
if(gett==EOF){exit(0);}
if(gett==header[done]){
done++;
if(done==4){
done=0;
memset(fn,128,0);
sprintf(fn,"%d.png",loop);
loop++;
FILE *out=fopen(fn,"wb");
while(1){
gett=fgetc(file);
if(gett==EOF){printf("ERROR: EOF TOO FIRST\n");exit(3);}
fputc(gett,out);
if(gett==end[done]){
done++;
if(done==4){printf("Found png %d=>%d.png\n",loop-1,loop-1);fclose(out);break;}
continue;
  }
if(done!=0){done=0;}

   }
   }
  }
  if(done!=0){done=0;}
 }
 //if(done!=0){done=0;}
}
