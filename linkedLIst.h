#pragma once
#include <ios>

class LinkedList
 {
public:
    LinkedList() = default;
    LinkedList(const LinkedList &) = delete;
    LinkedList(const LinkedList &&) = delete;
    LinkedList &operator=(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &&) = delete;
    ~LinkedList ();

    class const_iterator;
    const_iterator begin() const noexcept { return const_iterator(const_cast<Node *>(head.next));}
    const_iterator end() const noexcept { return const_iterator(const_cast<Node *> (&head));}

     struct Node {
        int data = 0;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    Node head{0, &head, &head};
    size_t size_ = 0;


    size_t size()const noexcept{ return size_; }
    bool empty() const noexcept{ return size() == 0;}

    void removeNode (Node*) noexcept;
    void basic_insert(Node*, int);

    void addNode(int);

    void clear () noexcept;

    // iterator (type?)
public:
    class const_iterator{
        const_iterator(Node *current);
        friend const_iterator LinkedList::begin() const noexcept;
        friend const_iterator LinkedList::end() const noexcept;

    public:
        const_iterator() = default;
        const_iterator &operator++();
        const_iterator operator++(int);
        const_iterator &operator--();
        const_iterator operator--(int);
        const int &operator*() const;
        const int* operator->() const;
    //private:
        Node *cur = nullptr;

        friend bool operator==(const const_iterator &l1, const const_iterator &l2) noexcept;
        friend bool operator!=(const LinkedList::const_iterator &l1, const LinkedList::const_iterator &l2) noexcept;
    };
};

bool operator==(const LinkedList::const_iterator &l1, const LinkedList::const_iterator &l2) noexcept;
bool operator!=(const LinkedList::const_iterator &l1, const LinkedList::const_iterator &l2) noexcept;
std::ostream &operator<<(std::ostream &, const LinkedList &li);



