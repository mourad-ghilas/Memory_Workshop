/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// int main(int argc, char *argv[])
// {
//     char *str = malloc(sizeof(char) * 10);
//     str = "Hello world!";
//     printf("%s\n", str);
//     return 0;
// }

// void *my_malloc(size_t size)
// {

//     void *ptr = sbrk(size);
//     if (ptr == NULL) {
//         return NULL;
//     } 
//     return ptr;
// }

// int main(int argc, char *argv[])
// {
//     char* hello = NULL;
//     hello = my_malloc(0);
//     if (hello == NULL) {
//         return 84;
//     }
//     return 0;
// }


typedef struct metadata {
    size_t size;
    struct metadata* next;
} metadata_t;

void* my_malloc(size_t size)
{
    metadata_t* cur_block;
    metadata_t* new_block;
    void* allocated_memory;

    if (size <= 0) {
        return NULL;
    }

    cur_block = sbrk(0);
    if (sbrk(sizeof(metadata_t) + size) == (void*)-1) {
        return NULL;
    }

    allocated_memory = cur_block;

    // new_block = cur_block;
    // new_block->size = size;
    // new_block->next = NULL;

    return allocated_memory;
}

int main(int argc, char *argv[])
{
    char* str = NULL;
    str = my_malloc(13);
    char *ptr = "hello world!";
    int i = 0;
    while (ptr[i] != '\0') {
        str[i] = ptr[i];
        i++;
    }
    str[i] = '\0';
    printf("%s\n", str);
    return 0;
}

