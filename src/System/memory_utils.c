#include "System/memory_utils.h"
#include <stdlib.h>
#include "System/macros.h"

void* alloc(void* ptr, size_t size, char* name, Logguer* log, int tabs) {
    DBG_ALLOC(log, name, size, tabs);
    void* result = realloc(ptr, size);
    if(result){
        DBG_ALLOC_OK(log);
    }else{
        DBG_ALLOC_FAIL(log, name, size);
    }
    return result;
}

Response* alloc_buffer(Logguer* log, int tabs, char* name){
    Response* result = alloc(NULL, sizeof(Response), name, log, tabs);
    if(!result) return NULL;
    response_init(log, tabs, result);
    return result;
}

void free_buffer(Response* res){
    response_free(res);
    free(res);
}