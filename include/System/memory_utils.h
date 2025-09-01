#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H
#include "buffer_utils.h"

void ini(Responses* res, int tabs);
void fin(Responses* res, int tabs);
void* alloc(size_t size, char* name, Responses* res, int tabs);
Response* alloc_buffer(Responses* res, int tabs, char* name);
void free_buffer(Response* res);

#endif //MEMORY_UTILS_H