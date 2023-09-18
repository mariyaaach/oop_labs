#include <iostream>

#include "lib.h"

using namespace std;

int main(){
    int row, column, answer;
    cout << "This program will help you find out for what minimum number of partitions you can split a chocolate bar." << endl;
    cout << "Enter the number of rows and columns of the chocolate." << endl;
    cin >> row >> column;
    answer = ChopTheChocolate(row, column);
    cout << answer << endl;

}