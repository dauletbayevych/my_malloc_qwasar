#include "../include/include.h"

void _my_memcpy(void *dest, void *src, size_t size){

    char* cdest = (char*)dest;
    char* csrc = (char*)src;

    for(size_t i = 0; i < size; i++){
        cdest[i] = csrc[i];
    }

}
void *_my_realloc(void *ptr, size_t size){

    if(size <= 0 || size > available_size)
        return NULL;

    void *new = _my_malloc(size);

    size_t i = 0;
    for(i = 0 ; i < heap.block_size; i++){
        if(ptr == heap.blocks[i].address)
            break;
    }

    _my_memcpy(new, ptr, align(size)); 
     
    _my_free(ptr);

    return new;
}
