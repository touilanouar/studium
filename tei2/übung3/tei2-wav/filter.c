#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ECHO_LENGTH 1000

union char2float
{
	char c[4];
	float f;
}floatConvert;

long fileSize(FILE *ptr)
{
	fseek(ptr,0L,SEEK_END);
	long end = ftell(ptr);
	rewind(ptr);
	long begin = ftell(ptr);
	return end-begin;
}
void saveFile(FILE *in, union char2float *out,int index)
{
        int t;
	for(t=0;t<index;t++)
        {
                fprintf(in,"%c",out[t].c[0]);
                fprintf(in,"%c",out[t].c[1]);
                fprintf(in,"%c",out[t].c[2]);
                fprintf(in,"%c",out[t].c[3]);
        }
}

void echoFilter(FILE *in,FILE *out,union char2float *trans,union char2float *transOut)
{	
	int t = 0;
	int index = 0;
	//union char2float *trans=malloc(fileSize(in));
	//union char2float *transOut=malloc(fileSize(out));
	float echo[ECHO_LENGTH];
	for(t = 0;t<ECHO_LENGTH;t++)
	{
		echo[t]=0;
	}
	//-------read file
	while(!feof(in))
	{
		trans[index].c[0] = fgetc(in);
		trans[index].c[1] = fgetc(in);
		trans[index].c[2] = fgetc(in);
		trans[index].c[3] = fgetc(in);
		transOut[index].f = 0;
		index++;
	}
	// Copy header
	for(t = 0;t<25;t++)
	{
		transOut[t].f=trans[t].f;
	}
	// FILTER
	for(t=25;t<index;t++)
	{
		transOut[t].f = trans[t].f+echo[t%ECHO_LENGTH];
		echo[t%ECHO_LENGTH] = trans[t].f;
	}
	saveFile(out,transOut,index);
	
}
void tiefFilter(FILE *in,FILE *out,union char2float *trans,union char2float *transOut)
{
	float filter[20];
	int t;
	int i;
	int index = 0;
	//-------read file
        while(!feof(in))
        {
                trans[index].c[0] = fgetc(in);
                trans[index].c[1] = fgetc(in);
                trans[index].c[2] = fgetc(in);
                trans[index].c[3] = fgetc(in);
                transOut[index].f = 0;
                index++;
        }
        // Copy header
        for(t = 0;t<25;t++)
        {
                transOut[t].f=trans[t].f;
        }
	// FILTER

	for(t=25;t<index;t++)
	{
		float sum = 0;
		filter[t%20]=trans[t].f;
		for(i=0;i<20;i++)
		{
			sum += filter[i]/20.0;
		}
		transOut[t].f= sum;
	}
	saveFile(out,transOut,index);
}
void rifFilter()
{}
void adaptFilter()
{}
int main(int argc, char**argv)
{
	FILE *fileIn;
	FILE *fileOut;
	FILE *fileIn1;
        FILE *fileOut1;

//------------ Datein öffnen
	fileIn = fopen("test.wav","rb");
	fileOut = fopen("filter.wav","wb");
	union char2float *trans=malloc(fileSize(fileIn));
	union char2float *transOut=malloc(fileSize(fileOut));
	echoFilter(fileIn,fileOut,trans,transOut);
	//fclose(fileIn);
	fclose(fileOut);
	//fileIn = fopen("test.wav","rb");
	rewind(fileIn);
        fileOut = fopen("filtertief.wav","wb");
	tiefFilter(fileIn,fileOut,trans,transOut);
	
}
