/*
 * error.c
 *
 *  Created on : Jul 23, 2017
 *  Author     : Michael A. Morris
 *  Description: Provides error outputs.
 *  Copyright  : Copyright 2017, GPLv3
 */

#include <stdio.h>

#include "common.h"
#include "error.h"
#include "ScannerPascal.h"

extern char    *tokenp;
extern BOOLEAN print_flag;

/*
 * Error Messages   Keyed to the enumeration type ERROR_CODE in
 *                  error.h.
 */

char *error_messages[] = {
    "No Error",
	"Syntax Error",
	"Too Many Syntax Errors",
	"Failed to open source file",
	"Unexpected end of file",
	"Invalid number",
	"Invalid fraction",
	"Invalid exponent",
	"Too many digits",
	"Real literal out of range",
	"Integer literal out of range",
	"Missing right parenthesis",
	"Invalid expression",
	"Invalid assignment statement",
	"Missing identifier",
	"Missing :=",
	"Undefined identifier",
	"Stack overflow",
	"Invalid statement",
	"Unexpected token",
	"Missing ; ",
	"Missing DO",
	"Missing UNTIL",
	"Missing THEN",
	"Invalid FOR control variable",
	"Missing OF",
	"Invalid constant",
	"Missing constant",
	"Missing : ",
	"Missing END",
	"Missing TO or DOWNTO",
	"Redefined identifier",
	"Missing = ",
	"Invalid type",
	"Not a type identifier",
	"Invalid subrange type",
	"Not a constant identifier",
	"Missing .. ",
	"Incompatible types",
	"Invalid assignment target",
	"Invalid identifier usage",
	"Incompatible assignment",
	"Min limit greater than max limit",
	"Missing [ ",
	"Missing ] ",
	"Invalid index type",
	"Missing BEGIN",
	"Missing period",
	"Too many subscripts",
	"Invalid field",
	"Nesting too deep",
	"Missing PROGRAM",
	"Already specified in FORWARD",
	"Wrong number of actual parameters",
	"Invalid VAR parameter",
	"Missing variable",
	"Code segment overflow",
	"Unimplemented feature",
};

/*
 * Globals
 */

int error_count = 0;

/*
 * Function Definitions
 */

void error(ERROR_CODE code)
{
    extern int buffer_offset;		// Defined in ScannerPascal.c

    char message_buffer[MAX_PRINT_LINE_LENGTH];
    char *message = error_messages[code];
    int  offset   = buffer_offset - 2;

    /*
     * Print the arrow pointing to the token just scanned.
     */

    offset += ((print_flag) ? 8 : 0);
    sprintf(message_buffer, "%*s^\n", offset, " ");
    if(print_flag) {
    	print_line(message_buffer);
    } else {
    	printf(message_buffer);
    }

    /*
     * Print the error message.
     */

    sprintf(message_buffer, " *** ERROR: %s.\n", message);
    if(print_flag) {
    	print_line(message_buffer);
    } else {
    	printf(message_buffer);
    }

    *tokenp = '\0';
    ++error_count;

    if(MAX_SYNTAX_ERRORS < error_count) {
    	sprintf(message_buffer, "Too many syntax errors. Aborted.\n");
        if(print_flag) {
        	print_line(message_buffer);
        } else {
        	printf(message_buffer);
        }

        exit(-TOO_MANY_SYNTAX_ERRORS);
    }
}
