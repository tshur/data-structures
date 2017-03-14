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

#include "node.h"   // Provides the Node class
#include <cstdlib>  // Provides size_t
#include <iostream> // Provides ostream

namespace tim_struct
{
    template <class Item>
    class SinglyLinkedList
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        typedef std::size_t size_type;
        typedef Node_Iterator<Item> iterator;
        typedef Const_Node_Iterator<Item> const_iterator;

        // CONSTRUCTOR, COPY CONSTRUCTOR, AND DESTRUCTOR
        SinglyLinkedList();
        SinglyLinkedList(const SinglyLinkedList& source);
        ~SinglyLinkedList();

        // MODIFICATION MEMBER FUNCTIONS
        void head_insert(const Item& entry);
        void insert(Node<Item>* prev, const Item& entry);
        Item head_remove();
        Item remove(Node<Item>* prev);
        bool operator = (const SinglyLinkedList& source);

        // CONSTANT MEMBER FUNCTIONS
        size_type length() const { return many_nodes; }
        size_type occurrences(const Item& target) const;
        Node<Item>* search(const Item& target) const;

        // ITERATOR FUNCTIONS
        iterator begin() { return iterator(head_ptr); }
        const_iterator begin() const { return const_iterator(head_ptr); }
        iterator end() { return iterator(); }
        const_iterator end() const { return const_iterator(); }

    private:
        Node<Item>* head_ptr;
        Node<Item>* tail_ptr;
        size_type many_nodes;
    };

    // NON-MEMBER FUNCTIONS
    template <class Item>
    std::ostream& operator << (std::ostream& outs, const SinglyLinkedList<Item>& list);

}

#include "linked_list.cxx"
#endif /* SINGLY_LIST_H */
