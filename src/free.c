#include "../include/include.h" 

void merge_empty_blocks(){

    for(size_t i = 0; i < heap.block_size-1; i++){
        if(heap.blocks[i].allocated == 0 && heap.blocks[i+1].allocated == 0){
            heap.blocks[i].size += heap.blocks[i+1].size;
            shift_back(i);
            heap.block_size -= 1;
        }
    }

}

void my_free(void *ptr){

    if(ptr == NULL)
        printf("Trying to free an invalid pointer.\n");

    for(size_t i = 0; i < heap.block_size; i++){
        if(heap.blocks[i].address == ptr){
            heap.blocks[i].allocated = 0;
            merge_empty_blocks();
            return;
        }
    }

    printf("Trying to free an invalid pointer.\n");
}
