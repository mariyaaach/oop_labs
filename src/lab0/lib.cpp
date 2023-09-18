// Copyright 2023 SomeName

#include "lib.h"

int ChopTheChocolate(int row, int column) {
    if (row <= 0 || column <= 0){
        return 0;
    }
    int total = ((row - 1) + (column - 1));

    return total;

}
