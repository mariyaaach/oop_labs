#include "lib.h"

int chopTheChocolate(int rowOfChocolate, int columnOfChocolate) {
    if (rowOfChocolate <= 0 || columnOfChocolate <= 0) {
        return 0;
    }

    int countOfParts = (rowOfChocolate - 1) + (columnOfChocolate - 1);

    return countOfParts;
}