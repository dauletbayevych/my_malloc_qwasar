#include "../include/include.h"

void *set_to_zero(void *ptr, size_t size){

    unsigned char *new = ptr;

    while (size > 0){
        *new = 0;
        new++;
        size--;
    }

    return new;
}
void *_my_calloc(size_t size, size_t size_of){

    if(size == 0 || size > available_size)
        return NULL;

    void *new = _my_malloc(size * size_of);

    set_to_zero(new, size);

    return new;
}
