/*
 * symtab.c
 *
 *  Created on: Jul 28, 2017
 *      Author: morrisma
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "error.h"
#include "symtab.h"

/*
 * Globals
 */

SYMTAB_NODE_PTR symtab_root = NULL;     // top level symbol table pointer

/*
 * SYMTAB_NODE_PTR search_symtab(char *name, SYMTAB_NODE_PTR np)
 *
 *      Search for name in the the symbol table pointed to by np. Return
 *      a pointer to the entry if found, or NULL is not found.
 */

SYMTAB_NODE_PTR search_symtab(char *name, SYMTAB_NODE_PTR np)
{
	int cmp;    // result of string compare: { < 0, == 0, > 0}

	/*
	 * Loop to check each node in the referenced symbol table. Return if
	 * there is a match, else continue search down the left or right
	 * sub-tree.
	 */

	while(NULL != np) {
		cmp = strcmp(name, np->name);
		if(0 == cmp) return(np);                    // name in symbol table
		np = ((cmp < 0) ? np->left : np->right);    // return sub-tree
	}
	return(NULL);
}

/*
 * SYMTAB_NODE_PTR enter_symtab(char *name, SYMTAB_NODE_PTR *npp)
 *
 *      Enter name into the symbol table, and return pointer to new entry.
 */

SYMTAB_NODE_PTR enter_symtab(char *name, SYMTAB_NODE_PTR *npp)
{
	int cmp;    // result of string compare: { < 0, == 0, > 0}

	SYMTAB_NODE_PTR new_nodep;
	SYMTAB_NODE_PTR np;

	/*
	 * Create new node for name if not found in the symbol table.
	 */

	new_nodep = alloc_struct(SYMTAB_NODE);
	new_nodep->name = alloc_bytes(strlen(name));
	strcpy(new_nodep->name, name);
	new_nodep->left = new_nodep->right = new_nodep->next = NULL;
	new_nodep->info = NULL;
	new_nodep->defn.key = UNDEFINED;
	new_nodep->level = new_nodep->label_index = 0;

	/*
	 * Loop to search for the insertion point in current symbol table
	 */

	while(NULL != (np = *npp)) {
		cmp = strcmp(name, np->name);
		npp =((cmp < 0) ? &(np->left) : &(np->right));
	}

	*npp = new_nodep;   // put new_nodep into left/right sub-tree
	return(new_nodep);
}
