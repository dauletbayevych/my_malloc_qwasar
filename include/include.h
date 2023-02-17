
// LIBRARIES

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

#define ALIGNMENT 16
#define MAX_CAP 1024
#define CHUNK_SIZE (1 << 16)

typedef struct block{
    size_t size;
    char allocated;
    void *address;
}block_t;

typedef struct heap_s{
    size_t block_size;
    block_t blocks[MAX_CAP];
}heap_t;

extern heap_t heap;
extern void *mem;
extern size_t available_size;

#ifndef MALLOC_H
#define MALLOC_H

void *_my_malloc(size_t);

#endif

// ---------------------------------------

#ifndef REALLOC_H
#define REALLOC_H

void *_my_realloc(void*,size_t);

#endif

// ---------------------------------------

#ifndef CALLOC_H
#define CALLOC_H

void *_my_calloc(size_t,size_t);

#endif

// ---------------------------------------
#ifndef UTILITY_H
#define UTILITY_H

size_t align(size_t);
size_t chunk_align(size_t);
heap_t add_blocks(size_t);
void memory_map(size_t);
void shift_back(size_t);

#endif

// ---------------------------------------

#ifndef FREE_H
#define FREE_H

#define _my_free(ptr) (my_free(ptr)); (ptr = NULL);
void my_free(void*);

#endif

// ---------------------------------------

