#include <iostream>
#include "linked_list.h"

using namespace std;
using namespace tim_struct;

int main()
{
    SinglyLinkedList<double> list1;
    list1.head_insert(5.0);
    list1.head_insert(3.0);
    Node<double>* three = list1.search(3.0);
    list1.insert(three, 4.0);
    cout << list1 << endl;

    return 0;
}
