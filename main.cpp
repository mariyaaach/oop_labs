#include "lib.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        Money firstAmount;
        firstAmount.input();

        Money secondAmount;
        secondAmount.input();
        if (firstAmount > secondAmount){
            Money finalAmount1 = firstAmount + secondAmount;
            Money finalAmount2 = firstAmount - secondAmount;
            cout << "Amount1 + Amount2 = ";
            finalAmount1.print();
            cout << "Amount1 - Amount2 = ";
            finalAmount2.print();   
        }
        else if (firstAmount < secondAmount){
            Money finalAmount1 = firstAmount + secondAmount;
            Money finalAmount2 = secondAmount - firstAmount;
            cout << "Amount1 + Amount2 = ";
            finalAmount1.print();
            cout << "Amount2 - Amount1 = ";
            finalAmount2.print();
        }
        if (firstAmount > secondAmount) {
            cout << "The first amount is greater than the second" << endl;
        } 
        else if (firstAmount < secondAmount) {
            cout << "The first amount is less than the second" << endl;
        } 
        else {
            cout << "The amounts are equal" << endl;
        }
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}