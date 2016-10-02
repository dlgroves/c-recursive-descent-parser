#ifndef READER
#define READER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

#define ERROR_MSG_INVALID_FILENAME "Unable to open %s\n"
#define ERROR_INVALID_FILENAME 2
#define FILE_MODE "r"

#define INITIAL_SIZE 2
#define LINE_SIZE 50
#define INCREMENT 10

void open(FILE **file, char *filename)
{
	*file = fopen(filename, FILE_MODE);
	if(*file == NULL)
	{
		fprintf(stderr, ERROR_MSG_INVALID_FILENAME, filename);
		exit(ERROR_INVALID_FILENAME);
	}
}

StringMem *getContents(FILE *file)
{
	StringMem *container = NULL;
	char ch;
	int h = 0, v = 0;
	container = (StringMem *)malloc(sizeof(StringMem));
	container->lines = INITIAL_SIZE;
	container->ptr = 0;
	container->data = (char **)malloc(INITIAL_SIZE * sizeof(char *));
	container->data[v] = (char *)malloc(LINE_SIZE * sizeof(char));
	while((ch = fgetc(file)) != EOF)
	{
		if(ch == '\n')
		{
			//add null terminator
			container->data[v][h] = '\0';
			//reset h and v counters
			h = 0;
			v++;
			//resize the array if we have run out of space
			if(v > container->lines - 1)
			{
				resize(container, INCREMENT);
				container->data[v] = (char *)malloc(LINE_SIZE * sizeof(char));
			}
			else
			{
				container->data[v] = (char *)malloc(LINE_SIZE * sizeof(char));
			}
			continue;
		}
		container->data[v][h] = ch;
		h++;
	}
	fclose(file);
	container->data[v][h] = '\0';
	return container;
}

void resize(StringMem *stringAndMem, int size)
{
	char **copy = NULL;
	int oldSize = stringAndMem->lines; 
	stringAndMem->lines += size;
	copy = (char **)malloc(stringAndMem->lines * sizeof(char *));
	for(int i = 0; i < oldSize; i++)
	{
		copy[i] = stringAndMem->data[i];
	}
	free(stringAndMem->data);
	stringAndMem->data = copy;
}

void cleanup(StringMem *contents)
{
	for(int i = 0; i < contents->lines; i++)
	{
		if(contents->data[i] != NULL)
		{
			free(contents->data[i]);
		}
	}
	free(contents->data);
	free(contents);
}
#endif
