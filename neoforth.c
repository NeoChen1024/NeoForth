/* ========================================================================== *\
||				   NeoForth				      ||
||                                 Neo_Chen                                   ||
\* ========================================================================== */

/* ========================================================================== *\
||   This is free and unencumbered software released into the public domain.  ||
||									      ||
||   Anyone is free to copy, modify, publish, use, compile, sell, or	      ||
||   distribute this software, either in source code form or as a compiled    ||
||   binary, for any purpose, commercial or non-commercial, and by any	      ||
||   means.								      ||
||									      ||
||   In jurisdictions that recognize copyright laws, the author or authors    ||
||   of this software dedicate any and all copyright interest in the	      ||
||   software to the public domain. We make this dedication for the benefit   ||
||   of the public at large and to the detriment of our heirs and	      ||
||   successors. We intend this dedication to be an overt act of	      ||
||   relinquishment in perpetuity of all present and future rights to this    ||
||   software under copyright law.					      ||
||									      ||
||   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,	      ||
||   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       ||
||   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   ||
||   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR        ||
||   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,    ||
||   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    ||
||   OTHER DEALINGS IN THE SOFTWARE.					      ||
||									      ||
||   For more information, please refer to <http://unlicense.org/>            ||
\* ========================================================================== */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <assert.h>
#include "neoforth.h"

enum code_words
{
	ENTER,
	NEXT
};

code_t code[CODESIZE];

void push(cell_t *stack, cell_t *sp, cell_t data)
{
	stack[(*sp)++] = data;
}

cell_t pop(cell_t *stack, cell_t *sp)
{
	return stack[--*sp];
}

void enter(void)
{
	return;
}

static cell_t w = 0;	// Working register
static cell_t ip = 0;	// Instruction Pointer
static cell_t dsp = 0;	// Data Stack Pointer
static cell_t rsp = 0;	// Return-Address Stack Pointer

static cell_t ds[DSSIZE];	// Data Stack
static cell_t rs[RSSIZE];	// Return Stack

int main(int argc, char **argv)
{
	int i = 0;
	for(i = 0; i < CODESIZE; i++)
		code[i] = NULL;

	while(code[ip] != NULL)
		code[ip++]();
	return EXIT_SUCCESS;
}
