#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>

void rdbacktrace() {
    void *buffer[100] = {NULL};
    char **trace = NULL;
    int i = 0;
    int size = 0;

    size = backtrace(buffer, 100);
    trace = backtrace_symbols(buffer, size);
    if (NULL == trace) {
        return;
    }

    printf("----------mytrace (tid: %ld)----------\n", syscall(SYS_gettid));
    for (i = 0; i < size; ++i) {
        printf("%s\n", trace[i]);
    }

    free(trace);
}
