#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

unsigned char *header="\x89PNG\r";
unsigned char *end="IEND\xae\x42\x60\x82";
int loop=1;

void main(int argc,char *argv[]){
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
if(done==5){
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
if(done==8){done=0;printf("Found png %d=>%s\n",loop-1,fn);fclose(out);break;}
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
