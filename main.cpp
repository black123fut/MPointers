
#include "MPointer.h"
#include "MPointerGC.h"


#include <iostream>

using namespace std;

int main() {
    cout << "HOLA" << endl;

    MPointer<int> pointer1 = MPointer<int>::New();
    MPointer<int> pointer2 = MPointer<int>::New();

    *pointer1 = 4;
    pointer2 = pointer1;
    *pointer2 = 6;

    cout << &pointer1<< endl;
    return 0;
}