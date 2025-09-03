#include <stdio.h>
#include "System/buffer_utils.h"
#include "System/memory_utils.h"
#include "System/macros.h"
#include "System/paths_utils.h"

int main() {
    Logguer res;
    logguer_init(&res);
    ini(&res, 1);
    response_append_l(res.buff, "Test log\n");
    response_append(&res, 2, res.buff, "    Test log 2 \n");
    
    Response* cwd_test = alloc_buffer(&res, 2, "cwd_test");
    safe_getcwd(&res, 2, cwd_test);
    
    fin(&res, 1);
    printf("buff: \n[\n    %s\n]\n", res.buff->data);
    printf( "log: \n[\n    %s\n]\n", res.log->data);
    printf("mess: \n[\n    %s\n]\n", res.mess->data);
    printf("warn: \n[\n    %s\n]\n", res.warn->data);
    printf( "cwd: \n[\n    %s\n]\n", cwd_test->data);
    logguer_free(&res);
    return 0;
}