#include "linkedLIst.h"
#include <iostream>

LinkedList:: ~LinkedList (){
    clear();
}

void LinkedList:: clear () noexcept{
    while(!empty())
        removeNode(head.next);
}

void LinkedList:: removeNode(Node *node) noexcept {
    auto temp = node -> prev;
    node->next->prev = temp;
    temp->next = node->next;
    delete node;
    --size_;
}

void LinkedList:: basic_insert(Node *node, int elem) {
    auto cur = new Node {elem, node, node->next};
    node->next->prev = cur;
    node->next = cur;
    ++size_;
}

void LinkedList:: addNode(int elem){
    basic_insert(&head, elem);
}

// iterator

LinkedList::const_iterator::const_iterator(Node *current):
    cur(current){}

LinkedList::const_iterator &LinkedList::const_iterator::operator++(){ // preincrement op
    cur = cur->next;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int){ // postincrement op
    auto tmp = *this;
    cur = cur->next;
    return tmp;
}

LinkedList::const_iterator &LinkedList::const_iterator::operator--(){
    cur = cur->prev;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int){
    auto tmp = *this;
    cur = cur->prev;
    return tmp;
}

 const int &LinkedList::const_iterator::operator*() const{
    return cur->data;
}

bool operator==(const LinkedList::const_iterator &l1, const LinkedList::const_iterator &l2) noexcept{
    return (l1.cur == l2.cur) || (!l1.cur && !l2.cur);
}

bool operator!=(const LinkedList::const_iterator &l1, const LinkedList::const_iterator &l2) noexcept{
    return (l1.cur != l2.cur);
}

std::ostream &operator<<(std::ostream &f, const LinkedList &li){
    for (const auto &i: li )
        f << i << " ";
    return f;
}
