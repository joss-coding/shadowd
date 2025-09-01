#include "System/memory_utils.h"
#include <stdlib.h>

void* alloc(size_t size, char* name, Responses* res, int tabs) {
    DBG_ALLOC(res, name, size, tabs);
    void* result = malloc(size);
    if(result){
        DBG_ALLOC_OK(res);
    }else{
        DBG_ALLOC_FAIL(res, name, size);
    }
    return result;
}

Response* alloc_buffer(Responses* res, int tabs, char* name){
    Response* result = alloc(sizeof(Response), name, res, tabs);
    if(!result) return NULL;
    response_init_f(result, 1);
    return result;
}

void free_buffer(Response* res){
    response_free_f(res);
    free(res);
}

void ini(Responses* res, int tabs){
    response_append(res->mess, "\n");
    TAB_SETTER(res->mess, tabs);
    response_append(res->mess, "===== Iniciando %s =====\n");
}

void fin(Responses* res, int tabs){
    TAB_SETTER(res->mess, tabs);
    response_append(res->mess, "===== Finalizando %s =====\n");
}
