/**
 * Simple recursive descent parser
 *
 * program = "START" block "END"
 * block = "ONE" | "ZERO"
 * 
 * Author: Douglas Groves
 * Date: 02/10/2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data/reader.h"
#include "parser/parser.h"

#define NO_OF_ARGS 2
#define ARG_FILENAME 1
#define ERROR_MSG_INVALID_ARGS "Usage: parse FILENAME\n"
#define ERROR_INVALID_ARGS 1

void checkArgs(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	FILE *fp;
	StringMem *model;
	checkArgs(argc, argv);
	open(&fp, argv[ARG_FILENAME]);
	model = getContents(fp);
	parse(model);
	cleanup(model);
}

void checkArgs(int argc, char *argv[])
{
	if(argc != NO_OF_ARGS)
	{
		fprintf(stderr, "%s", ERROR_MSG_INVALID_ARGS);
		exit(ERROR_INVALID_ARGS);
	}
}
