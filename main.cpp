#include <iostream>
#include "lib.h"

using namespace std;

int main() {
    int rowOfChocolate, columnOfChocolate;
    cout << "This program will help you find out the minimum number of partitions you can split a chocolate bar into." << std::endl;
    cout << "Enter the number of rows and columns of the chocolate: ";
    cin >> rowOfChocolate >> columnOfChocolate;
    int countOfParts = chopTheChocolate(rowOfChocolate, columnOfChocolate);
    cout << "The minimum number of partitions required is: " << countOfParts << endl;

}