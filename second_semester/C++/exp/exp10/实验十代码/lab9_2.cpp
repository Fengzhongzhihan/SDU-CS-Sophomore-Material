#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {
    // Create two integer linked lists A and B
    LinkedList<int> A;
    LinkedList<int> B;

    // Insert 5 elements into A
    A.insertRear(1);
    A.insertRear(2);
    A.insertRear(3);
    A.insertRear(4);
    A.insertRear(5);

    // Insert 5 elements into B
    B.insertRear(6);
    B.insertRear(7);
    B.insertRear(8);
    B.insertRear(9);
    B.insertRear(10);

    // Append elements of B to the end of A
    B.reset();  // Start at the beginning of list B
    while (!B.endOfList()) {
        A.insertRear(B.data());
        B.next();
    }

    // Print elements of A after appending B
    A.reset();
    cout << "Elements of linked list A after appending B: ";
    while (!A.endOfList()) {
        cout << A.data() << " ";
        A.next();
    }
    cout << endl;

    return 0;
}
