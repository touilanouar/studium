#include<stdio.h>
#include<stdlib.h>
#include"wave.c"

void readSubChunks(FILE* ptr)
{

	chunkheader ch;
	wavheader wh;
	long ft = 0;
	fseek(ptr,0,SEEK_SET);
	fread(&wh,sizeof(wh),1,ptr);
	while(!feof(ptr)){
		fseek(ptr,ch.chunk_size,SEEK_CUR);
		fread(&ch,sizeof(ch),1,ptr);
        	printf("chunk_ID : %.4s\n",ch.chunk_id);
		ft = ftell(ptr)+ch.chunk_size;
		if((ft) == (wh.riff_chunk_header.chunk_size+8)){
			break;
		}
	}

}

int main()
{
	FILE* ptr;
	wavheader head;
	int read = 0;
	float *signal;
	signal = (float *) malloc(sizeof(float));
	if((ptr = fopen("test.wav","rb"))== NULL)
	{
		printf("Datei könnte nicht geöffnet werden !!\n");
	}else{
		printf("Datei wird geöffnet ...\n");
	}
	read = fread(&head,sizeof(head),1,ptr);
	printf("CHUNK_ID : %.4s\n",head.riff_chunk_header.chunk_id);
	printf("CHUNK_SIZE : %u\n",head.riff_chunk_header.chunk_size);
	printf("RIFF_FORMAT : %.4s\n",head.riff_format);
	printf("FMT_CHUNK_ID : %.4s\n",head.fmt_chunk_header.chunk_id);
	printf("FMT_CHUNK_SIZE : %u\n",head.fmt_chunk_header.chunk_size);
	printf("FORMAT_TYPE : %u\n",head.format_type);
	printf("CHANNELS : %u\n",head.channels);
	printf("SAMPLE_RATE : %u\n",head.sample_rate);
	printf("BYTERATE : %u\n",head.byterate);
	printf("BLOCK_ALIGH : %u\n",head.block_align);
	printf("BITS_PER_SAMPLE : %u\n",head.bits_per_sample);
  	readSubChunks(ptr);
	fclose(ptr);
  return 0;
}
