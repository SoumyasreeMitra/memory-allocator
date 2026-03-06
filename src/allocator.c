#include "../include/allocator.h"
#include <unistd.h>

typedef struct block {
    size_t size;
    int free;
    struct block* next;
} block;

#define BLOCK_SIZE sizeof(block)

static block* freeList = NULL;

/* Find a free block */
block* find_free_block(size_t size) {
    block* curr = freeList;

    while (curr) {
        if (curr->free && curr->size >= size)
            return curr;

        curr = curr->next;
    }

    return NULL;
}

/* Request memory from OS */
block* request_space(block* last, size_t size) {

    block* b = sbrk(0);
    void* request = sbrk(size + BLOCK_SIZE);

    if (request == (void*) -1)
        return NULL;

    if (last)
        last->next = b;

    b->size = size;
    b->free = 0;
    b->next = NULL;

    return b;
}

/* Allocate memory */
void* my_malloc(size_t size) {

    block* b;

    if (!freeList) {

        b = request_space(NULL, size);
        if (!b)
            return NULL;

        freeList = b;

    } else {

        block* last = freeList;
        b = find_free_block(size);

        if (!b) {

            while (last->next)
                last = last->next;

            b = request_space(last, size);

            if (!b)
                return NULL;

        } else {

            b->free = 0;

        }
    }

    return (b + 1);
}

/* Free memory */
void my_free(void* ptr) {

    if (!ptr)
        return;

    block* b = (block*)ptr - 1;
    b->free = 1;

}