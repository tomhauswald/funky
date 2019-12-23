#include <stdlib.h>

typedef struct {
    uint8_t* data;
    size_t stride;
    size_t count;
    size_t capacity;
} fk_vector_t;

void fk_vector_init( fk_vector_t* v, 
                     size_t stride, 
                     size_t initial_capacity );

void fk_vector_grow(fk_vector_t* v);

void fk_vector_push(fk_vector_t* v, char const* data);