#include <iostream>

#include "lib.h"

using namespace std;

int main(){
    int row, column, ans;
    cout << "Enter the number of rows and columns of the chocolate" << endl;
    cin >> row >> column;
    ans = choco(row, column);
    cout << ans << endl;

}