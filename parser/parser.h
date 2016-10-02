#ifndef PARSER_H
#define PARSER_H

#include "../data/reader.h"

typedef enum boolean
{
	FALSE, TRUE
} Boolean;

typedef struct errorDetails
{
	char *expected;
	char *actual;
	int line;
	int expectation;
} ErrorDetails;

void parse(StringMem *contents);
Boolean start(StringMem *contents, ErrorDetails *error);
Boolean one(StringMem *contents, ErrorDetails *error);
Boolean zero(StringMem *contents, ErrorDetails *error);
Boolean end(StringMem *contents, ErrorDetails *error);
#endif
