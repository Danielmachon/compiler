#include <stdio.h>					//File stuff
#include <stdlib.h>					//Malloc

#include "streamer/streamer.h"

long read_src(const char *file, const char **buf)
{
	FILE *f = fopen(file, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *bytes = malloc(fsize + 1);
	fread(bytes, 1, fsize, f);
	fclose(f);
	
	return fsize;
}

int main(int argc, char **argv)
{
	/* Read the source file */
	const char *buf;
	int r = read_src("source_file.c", &buf);
	
	/* Streamer object */
	struct streamer *s = streamer_init(buf);
}