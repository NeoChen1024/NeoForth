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

#pragma once

#define CODESIZE	(1<<16)
#define DSSIZE		(1<<12)
#define RSSIZE		(1<<12)

typedef unsigned int cell_t;
typedef void(* code_t)(void);

void push(cell_t *stack, cell_t *sp, cell_t data);
cell_t pop(cell_t *stack, cell_t *sp);
