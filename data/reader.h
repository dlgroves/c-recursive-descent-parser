#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stringAndMemoryUsage
{
	char **data;
	int lines;
	int ptr;
} StringMem;

void open(FILE **file, char *filename);
StringMem *getContents(FILE *file);
void resize(StringMem *stringAndMem, int size);
void cleanup(StringMem *contents);

#endif