#include "System/log_utils.h"

void tab_setter(Response* res, int tab_count) {
    for (int i = 0; i < tab_count; i++) {
        response_append(res, "    ");
    }
}

void dbg_alloc(Responses* res, char* name, size_t size, int tab_count) {
    tab_setter(res->mess, tab_count);
    response_append(res->mess, "[%s] 🟦 [ALLOC] %s (%zu bytes) ... ", __func__, varName, (size_t)(size));
}

void dbg_alloc_ok(Responses* res){
    response_append(res->mess, "✅\n");
}

void dbg_alloc_fail(Responses* res, char* name, size_t size){
    response_append(res->mess, "❌\n");
    response_append(res->log, "    [%s] ❗ [ALLOC_FAIL] %s (%zu bytes)\n", __func__, varName, (size_t)(size));
}

void res_sinc(Responses* responses, Responses* res){
    response_append(response->mess, res.mess->data);
    response_append(response->log, res.log->data);
    response_append(response->buff, res.buff->data);
    response_append(response->warn, res.warn->data);
}

void safe_sub(size_t _x, size_t _y, size_t* out, Responses* response){
    do {
        if (_x >= _y) {
            *out = _x - _y;
        } else {
            *out = _y - _x;
            if response {
                TAB_SETTER((response)->warn, 1);
                response_append((response)->warn, "    [SAFE_SUB] Aviso: valor esperado (%zu) < semilla (%zu),\n    se usó valor absoluto (%zu)\n", _x, _y, *(out));
            }
        }
    } while (0) 
}

