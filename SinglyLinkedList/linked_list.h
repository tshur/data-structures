// FILE: linked_list.h
// AUTHOR: Tim Shur
// PROVIDES: A class for a SinglyLinkedList within the namespace tim_struct.
//
// INVARIANT for the SinglyLinkedList class:
//
//
// CONSTRUCTORS for the SinglyLinkedList class:
//
//
// MODIFICATION MEMBER FUNCTIONS for the SinglyLinkedList class:
//
//
// CONSTANT MEMBER FUNCTIONS for the SinglyLinkedList class:
//
//
// NON-MEMBER FUNCTIONS for the SinglyLinkedList class:
//
//
// VALUE SEMANTICS for the SinglyLinkedList class:
//     The copy constructor and assignment operator are valid for the
//     SinglyLinkedList class.
//
// DYNAMIC MEMORY usage by the SinglyLinkedList class:
//     If there is insufficient memory, the following functions will call
//     bad_alloc:

#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

namespace tim_struct
{
    template <class Item>
    class SinglyLinkedList
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        typedef std::size_t size_type;

        // CONSTRUCTOR, COPY CONSTRUCTOR, AND DESTRUCTOR
        SinglyLinkedList();
        SinglyLinkedList(const SinglyLinkedList& source);
        ~SinglyLinkedList();

        // MODIFICATION MEMBER FUNCTIONS
        void head_insert(const Item& entry);
        void insert(Node<Item>* prev, const Item& entry);
        Item head_remove();
        Item remove(Node<Item>* prev);

        // CONSTANT MEMBER FUNCTIONS
        size_type length() const { return many_nodes; }
        size_type occurrences(const Item& target) const;
        Node<Item>* search(const Item& target) const;
        const Node<Item>* search(const Item& target) const;

    private:
        Node<Item>* head_ptr;
        Node<Item>* tail_ptr;
        size_type many_nodes;
    };

    // NON-MEMBER FUNCTIONS

}

#include "linked_list.cxx"
#endif /* SINGLY_LIST_H */
