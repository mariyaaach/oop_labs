#include "container.h"
#include "factorial.h"
#include <iostream>
#include <map>


int main() {
    // std::map with custom allocator
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>, 10>> myMap;
    for (int i = 0; i < 10; ++i) {
        myMap[i] = factorial(i);
    }
    for (const auto& pair : myMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    // Custom container with custom allocator
    MyContainer<int, 5> myContainer;
    for (int i = 0; i < 10; ++i) {
        myContainer.push_back(i);
    }
    myContainer.print();

    return 0;
}