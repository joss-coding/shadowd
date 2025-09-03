#ifndef MACROS_H
#define MACROS_H
#include <string.h>

#define ini(res, tabs) \
    if(res){ \
        response_append_l((res)->mess, "\n"); \
        TAB_SETTER((res)->mess, (int)tabs); \
        response_append_l((res)->mess, "===== Iniciando %s =====\n", __func__);\
    }

#define fin(res, tabs) \
    if(res){ \
        TAB_SETTER((res)->mess, (int)tabs); \
        response_append_l((res)->mess, "===== Finalizando %s =====\n", __func__); \
    }

#define TAB_SETTER(res, tabs) \
    if(res){ \
        for(int i = 0; i < (int)tabs; i++){ \
            response_append_l(res, "    "); \
        }\
    }
#define DBG_ALLOC(res, varName, size, tabs) \
    if(res){ \
        TAB_SETTER(res->mess, tabs); \
        response_append_l(res->mess, "[%s] 🟦 [ALLOC] %s (%zu bytes) ... ", __func__, varName, (size_t)(size)); \
    }

#define DBG_ALLOC_OK(res) \
    if(res)response_append_l(res->mess, "✅ OK\n");

#define DBG_ALLOC_FAIL(res, varName, size) \
    if(res){\
        response_append_l(res->mess, "❌ FAIL\n"); \
        TAB_SETTER(res->log, 1); \
        response_append_l(res->log, "[%s] ERROR: No se pudieron asignar %zu bytes para %s\n", __func__, (size_t)(size), varName); \
    }
#define RES_SINC(response, res) \
    response_append_l(response->mess, res.mess->data); \
    response_append_l(response->log, res.log->data); \
    response_append_l(response->buff, res.buff->data); \
    response_append_l(response->warn, res.warn->data);

// Macro para restar seguro
#define SAFE_SUB(d_a, a, d_b, b, out, response) do {                         \
    size_t _x = (size_t)(a); \
    size_t _y = (size_t)(b); \
    if (_x >= _y) { \
        *(out) = _x - _y; \
    } else { \
        *(out) = _y - _x; \
        if (response) { \
            TAB_SETTER((response)->warn, 1); \
            response_append_l((response)->warn, \
                "[SAFE_SUB] Aviso: valor esperado de %s (%zu) < al de %s (%zu),\n" \
                " se usó valor absoluto (%zu)\n", d_a, _x, d_b, _y, *(out));     \
        } \
    } \
} while (0);

#endif //MACROS_H