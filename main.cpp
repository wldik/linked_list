#include <iostream>
#include "linkedLIst.h"

using namespace std;

int main()
{
    LinkedList listq;
    LinkedList::const_iterator iter1;

    for (int i = 49; i >= -56; i--){ //populating the linked list
        listq.addNode(i);
    }


    auto iter = listq.begin(); // iterating untill we find the address for 7
    while (*iter != -8){
        ++iter;
    }

    LinkedList::Node * p = iter.cur;

    p->next->data = p->next->next->data;

    p->data = p->next->next->prev->next->data;

    cout<< listq << endl;
    cout <<   p->data << endl;

    return 0;
}
