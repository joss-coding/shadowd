#include "System/paths_utils.h"
#include "System/macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void safe_getcwd(Logguer* log, size_t tabs, Response* res) {
    size_t size = 2;
    ini(log, tabs)
    while (1) {
        response_reserve(log, tabs+1, res, size);
        
        if (!res) {
            perror("malloc");
            fin(log, tabs);
            return;
        }

        if (getcwd(res->data, size) != NULL) {
            fin(log, tabs);
            return; // éxito
        }

        if (errno != ERANGE) { 
            // si no es error de tamaño, abortamos
            perror("getcwd");
            fin(log, tabs);
            return;
        }

        size = res->cap; // buffer demasiado pequeño → duplicamos tamaño
    }
}