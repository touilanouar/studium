#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#define ECHO_LENGTH 2000
 
int t = 0;
union char2float

{
     char c[4];
     float f;
};

long fileSize(FILE * file)

{

    fseek(file, 0L, SEEK_END);

    long end = ftell(file);

    rewind(file);

    long begin = ftell(file);

    return end-begin;

}
/*void echoFilter(float *echo,int index,union char2float *transOut,union ch$
{
   for ( t=25;t<index;t++){
   transOut[t].f = trans[t].f + echo[t%ECHO_LENGTH]; // + sin(2*M_PI *$
   echo[t%ECHO_LENGTH]=trans[t].f;
   }
}*/

int main(int argc, char**argv)

{

  FILE *fileIn;
  FILE *fileOut;
 // #define ECHO_LENGTH 2000
  float echo[ECHO_LENGTH];
  //float *echo=malloc(ECHO_LENGTH);
  float filter[20];
  fileIn = fopen("test.wav","rb");
  fileOut = fopen("transformed2.wav","wb");
  union  char2float *trans=malloc(fileSize(fileIn));
  union  char2float *transOut=malloc(fileSize(fileIn));
  for (t=0;t<ECHO_LENGTH;t++){

      echo[t]=0;;

  }

  // --- read file "example.pcm"
  int index=0;
  while(!feof(fileIn)){
       trans[index].c[0] = fgetc(fileIn);
       trans[index].c[1] = fgetc(fileIn);
       trans[index].c[2] = fgetc(fileIn);
       trans[index].c[3] = fgetc(fileIn);
       transOut[index].f = 0;
       index++;
  }
  for ( t=0;t<25;t++) // copy header
      transOut[t].f = trans[t].f;

  // Echo erzeugen, indem man das Originalsignal verzögert um ECHO_LENGTH hinzuaddiert
/*  for ( t=25;t<index;t++){
      transOut[t].f = trans[t].f + echo[t%ECHO_LENGTH]; // + sin(2*M_PI *t/15.0)*0.5;
      echo[t%ECHO_LENGTH]=trans[t].f;
  }
*/
 // echoFilter(echo,index,&transOut,&trans);

  // Tiefpass auf das Originalsignal (nur tiefe Frequenzen komen durch)
	int i;
  for ( t=25;t<index;t++){

      float sum=0;

      filter[t%20]=trans[t].f;

      // Mittellung der letzten 20 Audiowerte

      for (i=0;i<20;i++){

               sum += filter[i]/20.0;

      }

      transOut[t].f = sum;

  }



  // -----------------------------------------------------------------------------------------
  // ***********************FIR-FILTER***********************************
 
  // --- save file "exampleTransformed.pcm"
  for (t=0;t<index;t++){
         fprintf(fileOut,"%c",transOut[t].c[0]);
         fprintf(fileOut,"%c",transOut[t].c[1]);
         fprintf(fileOut,"%c",transOut[t].c[2]);
         fprintf(fileOut,"%c",transOut[t].c[3]);
  }
  fclose(fileIn);
  fclose(fileOut);

}
/*void echoFilter(float echo,int index,union char2float *transOut,union char2float *trans)
{
	for ( t=25;t<index;t++){
      transOut[t].f = trans[t].f + echo[t%ECHO_LENGTH]; // + sin(2*M_PI *$
      echo[t%ECHO_LENGTH]=trans[t].f;
  }

}*/
void tiefPass()
{
}
void firFilter()
{
}
void adaptFilter()
{
}
void saveFile()
{

}
