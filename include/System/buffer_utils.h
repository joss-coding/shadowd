#ifndef BUFFER_UTILS_H
#define BUFFER_UTILS_H
#include <stddef.h>
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
} Logguer;

int response_init(Logguer* log, size_t tabs, Response* res);
int logguer_init(Logguer *res);
int response_reserve(Logguer* log, size_t tabs, Response *res, size_t extra);
int response_append(Logguer* log, size_t tabs, Response *res, const char *fmt, ...);
int response_append_l(Response *res, const char *fmt, ...);
void logguer_free(Logguer* res);
void response_free(Response* res);
#endif //BUFFER_UTILS_H