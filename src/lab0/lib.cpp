// Copyright 2023 SomeName

#include "lib.h"

int choco(int n, int m) {
    if (n <= 0 || m <= 0){
        return 0;
    }
    return ((n - 1) + (m - 1));
}
