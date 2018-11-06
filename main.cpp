#include <iostream>
#include "strategy.cpp"
using namespace std;

int main() {
    CNTax a;
    SalesOrder b(&a);
    b.CalculateTax();

    cout << "Hello, World!" << endl;
    return 0;
}