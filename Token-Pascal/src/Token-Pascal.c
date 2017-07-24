/*
 ============================================================================
 Name        : Token-Pascal.c
 Author      : Michael A. Morris
 Version     : 0.0.1
 Copyright   : Copyright 2017, GPLv3
 Description : Tokenizer Program for Pascal in C, ANSI-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "error.h"
#include "ScannerPascal.h"

/*
 * int main(int, char **)   Loop to tokenize source file
 */

extern TOKEN_CODE token;

int main(int argc, char *argv[])
{
    /*
     * Initialize Scanner.
     */

	init_scanner(argv[1]);

    /*
     * Repeatedly get tokens until period or end of file.
     */

    do {
    	get_token();
    	if(END_OF_FILE == token) {
    		error(UNEXPECTED_END_OF_FILE);
    		break;
    	}

    	print_token();
    } while(PERIOD != token);

    quit_scanner();

    return 0;
}
