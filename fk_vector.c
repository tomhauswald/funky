#include "fk_vector.h"

void fk_vector_init( fk_vector_t* v, 
                     size_t stride, 
                     size_t initial_capacity ) {
    
    v->data     = (uint8_t*) malloc(stride * initial_capacity);
    v->stride   = stride;
    v->count    = 0;
    v->capacity = initial_capacity;
}

void fk_vector_grow(fk_vector_t* v) {

    uint8_t* old_data = v->data;
    uint8_t* new_data = (uint8_t*) malloc(2 * v->capacity * v->stride);
    
    FK_FOREACH_LINEAR(
        new_data, 
        v->count * v->stride,
        FK_ITEM = old_data[FK_INDEX]
    );
    free(old_data);

    v->capacity *= 2;
    v->data = new_data;
}

void fk_vector_push(fk_vector_t* v, char const* data) {
    if(v->count >= v->capacity) fk_vector_grow(v);
    for(size_t byte = 0; byte < v->stride; ++byte) {
        v->data[v->count * v->stride + byte] = data[byte];
    }
    v->count++;
}