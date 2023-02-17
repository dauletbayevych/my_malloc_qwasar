/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: My_malloc 
 *
 *        Version:  1.0
 *        Created:  11/30/2021 01:53:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chris Dallat, Khalil Masree  
 *   Organization:  ELU 
 *
 * =====================================================================================
 */
#include "../include/include.h" 

int main(){

    char *src = _my_malloc(100);
    char *dest = _my_malloc(100);
    char *t = _my_malloc(100);
    char *r = _my_malloc(100);

    strcpy(src, "heloo");
    printf("src: %s src: %ld address: %p \n", src, strlen(src), src);
    strcpy(dest, "helo");
    strcpy(t, "hlo");
    strcpy(r, "o");

    _my_free(src);
    char *c = _my_realloc(dest, 3);
    printf("c: %s c: %ld address: %p \n", c, strlen(c), c);
    _my_free(dest);

    char *s = _my_malloc(20);
    strcpy(s, "mama");

    char *k = _my_malloc(30);
    strcpy(k, "ho");

    char *f = _my_malloc(50);
    strcpy(f, "bk");

    char *n = _my_malloc(9);
    strcpy(n, "ma");

    char *m = _my_calloc(30, sizeof(char));
    printf("r: %s r: %ld address: %p \n", r, strlen(r), r);
    printf("t: %s t: %ld address: %p \n", t, strlen(t), t);
    printf("k: %s k: %ld address: %p \n", k, strlen(k), k);
    printf("s: %s s: %ld address: %p \n", s, strlen(s), s);
    printf("f: %s s: %ld address: %p \n", f, strlen(f), f);
    printf("m: %s m: %ld address: %p \n", m, strlen(m), m);
    printf("n: %s n: %ld address: %p \n", n, strlen(n), n);

    printf("\n");
    for(size_t i = 0 ; i < heap.block_size; i++){
        printf("{size: %ld Address: %p allocated: %d}\n", heap.blocks[i].size, heap.blocks[i].address, heap.blocks[i].allocated);
    }

    return 0;
    /* _my_free(dest); */
}

