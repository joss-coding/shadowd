#ifndef BUFFER_UTILS_H
#define BUFFER_UTILS_H
#include <stddef.h>
#include "log_utils.h"

typedef struct {
    char            *data;      //| Puntero al buffer
    size_t            len;      //| Longitud actual (sin contar el '\0')
    size_t            cap;      //| Capacidad reservada
} Response;

typedef struct {
    Response*   buff; //| Response para buffer;
    Response*    log; //| Response para log
    Response*   mess; //| Response para mensajes
    Response*   warn; //| Response para advertencias
} Responses;

int response_init_f(Response* res, size_t initia_capacity);
int response_init(Responses *res, size_t initial_capacity);
int response_reserve(Response *res, size_t extra);
int response_append(Response *res, const char *fmt, ...);
void response_free(Responses *res);
void response_free_f(Response* res);
void response_clear(Response* res);
#endif //BUFFER_UTILS_H