#ifndef LOG_UTILS_H
#define LOG_UTILS_H
#include "buffer_utils.h"

void tab_setter(Response* res, int tab_count);
void dbg_alloc(Responses* res, char* name, size_t size, int tab_count);
void dbg_alloc_ok(Responses* res);
void dbg_alloc_fail(Responses* res, char* name, size_t size);
void res_sinc(Responses* response, Response* res);
void safe_sub(size_t a, size_t b, size_t* result, Responses* res);

#endif // Log_Utils_H