#include "MPointer.h"
#include "MPointerGC.h"

#include <iostream>

using namespace std;

int main() {

    MPointer<int> pointer1 = MPointer<int>::New();
    MPointer<int> pointer2 = MPointer<int>::New();
    pointer1 = 7;

    cout << &pointer1<< endl;
    cout << "ID: " << pointer1.getID() << endl;
    cout << "ID: " << pointer2.getID() << endl;
    return 0;
}