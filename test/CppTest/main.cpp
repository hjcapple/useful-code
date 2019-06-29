#include <iostream>
#include "CloverTest.h"
#include "ScopeGuard.h"

CLOVER_TEST {
    void *p = nullptr;
    {
        p = malloc(1000);
        ON_SCOPE_EXIT {
            free(p);
            p = nullptr;
        };
    }
    ensure(p == nullptr);
}

int main(int argc, const char * argv[]) {
    return 0;
}
