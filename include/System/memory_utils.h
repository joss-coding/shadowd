#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H
#include "buffer_utils.h"

void* alloc(void* ptr, size_t size, char* name, Logguer* log, int tabs);
Response* alloc_buffer(Logguer* log, int tabs, char* name);
void free_buffer(Response* res);
#endif //MEMORY_UTILS_H