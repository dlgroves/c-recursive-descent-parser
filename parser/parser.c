#ifndef PARSER
#define PARSER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#define STRSAME(A,B) strcmp(A, B) == 0

void parse(StringMem *contents)
{
	ErrorDetails *errorDetails = (ErrorDetails *)malloc(sizeof(ErrorDetails));
	errorDetails->line = 1;
	errorDetails->expectation = 0;
	if(!start(contents, errorDetails))
	{
		fprintf(stderr, "Line %d: Expected: %s, actual: %s\n", 
			errorDetails->line, errorDetails->expected, errorDetails->actual);
		free(errorDetails);
		exit(3);
	}
	free(errorDetails);
}

Boolean start(StringMem *contents, ErrorDetails *errorDetails)
{
	if(STRSAME(contents->data[contents->ptr], "START"))
	{
		contents->ptr++;
		errorDetails->line++;
		if(zero(contents, errorDetails) || one(contents, errorDetails) || 
				end(contents, errorDetails))
		{
			return TRUE;
		}
		else
		{
			errorDetails->expected = "ZERO or ONE or END";
			errorDetails->actual = contents->data[contents->ptr];
			return FALSE;
		}
	}
	else
	{
		errorDetails->expected = "START";
		errorDetails->actual = contents->data[contents->ptr];
		return FALSE;
	}
}

Boolean one(StringMem *contents, ErrorDetails *errorDetails)
{
	if(STRSAME(contents->data[contents->ptr], "ONE"))
	{
		printf("%d\n", 1);
		contents->ptr++;
		errorDetails->line++;
		if(zero(contents, errorDetails) || one(contents, errorDetails) || 
				end(contents, errorDetails))
		{
			return TRUE;
		}
		else
		{
			errorDetails->expected = "ZERO or ONE or END";
			errorDetails->actual = contents->data[contents->ptr];
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

Boolean zero(StringMem *contents, ErrorDetails *errorDetails)
{
	if(STRSAME(contents->data[contents->ptr], "ZERO"))
	{
		printf("%d\n", 0);
		contents->ptr++;
		errorDetails->line++;
		if(zero(contents, errorDetails) || one(contents, errorDetails) || 
				end(contents, errorDetails))
		{
			return TRUE;
		}
		else
		{
			errorDetails->expected = "ZERO or ONE or END";
			errorDetails->actual = contents->data[contents->ptr];
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

Boolean end(StringMem *contents, ErrorDetails *errorDetails)
{
	if(STRSAME(contents->data[contents->ptr], "END"))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
#endif