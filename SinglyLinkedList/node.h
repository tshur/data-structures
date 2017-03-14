// FILE: node.h
// AUTHOR: Tim Shur
// PROVIDES: A class for a singly linked list Node within the namespace
//     tim_struct.
//
// INVARIANT for the Node class:
//
//
// CONSTRUCTORS for the Node class:
//
//
// MODIFICATION MEMBER FUNCTIONS for the Node class:
//
//
// CONSTANT MEMBER FUNCTIONS for the Node class:
//
//
// NON-MEMBER FUNCTIONS for the Node class:
//
//
// VALUE SEMANTICS for the Node class:
//     The copy constructor and assignment operator are valid for the Node
//     class.
//

#ifndef SINGLY_NODE_H
#define SINGLY_NODE_H

#include <cstdlib>

namespace tim_struct
{
    // Node class begins here
    template <class Item>
    class Node
    {
    public:
        Node(const Item& init_data = Item(), Node* init_link = NULL)
        {
            data_field = init_data;
            link_field = init_link;
        }

        void set_data(const Item& new_data) { data_field = new_data; }
        void set_link(Node* new_link) { link_field = new_link; }

        Item& data() { return data_field; }
        const Item& data() const { return data_field; }

        Node* link() { return link_field; }
        const Node* link() const { return link_field; }

    private:
        Item data_field;
        Node* link_field;
    };


    // Node_Iterator class begins here
    template <class Item>
    class Node_Iterator
    {
    public:
        // CONSTRUCTOR
        Node_Iterator(Node<Item>* initial = NULL) { current = initial; }

        // COPY CONSTRUCTOR
        Node_Iterator(const Node_Iterator& source) {
            current = source.current;
        }

        // ASSIGNMENT OPERATOR
        void operator = (const Node_Iterator& source) {
            current = source.current;
        }

        // DEREFERENCING OPERATOR
        Item& operator * () const { return current->data(); }

        // PRE-FIX INCREMENT
        Node_Iterator& operator ++() {
            current = current->link();
            return *this;
        }

        // POST-FIX INCREMENT
        Node_Iterator operator ++(int) {
            Node_Iterator original(current);
            current = current->link();
            return original;
        }

        // EQUALITY OPERATOR
        bool operator == (const Node_Iterator other) const {
            return current == other.current;
        }

        // INEQUALITY OPERATOR
        bool operator != (const Node_Iterator other) const {
            return current != other.current;
        }

    private:
        Node<Item>* current;
    };


    // Const_Node_Iterator class begins here
    template <class Item>
    class Const_Node_Iterator
    {
    public:
        // CONSTRUCTOR
        Const_Node_Iterator(const Node<Item>* initial = NULL) { current = initial; }

        // COPY CONSTRUCTOR
        Const_Node_Iterator(const Const_Node_Iterator& source) {
            current = source.current;
        }

        // ASSIGNMENT OPERATOR
        void operator = (const Const_Node_Iterator& source) {
            current = source.current;
        }

        // DEREFERENCING OPERATOR
        const Item& operator * () const { return current->data(); }

        // PRE-FIX INCREMENT
        Const_Node_Iterator& operator ++() {
            current = current->link();
            return *this;
        }

        // POST-FIX INCREMENT
        Const_Node_Iterator  operator ++(int) {
            Const_Node_Iterator original(current);
            current = current->link();
            return original;
        }

        // EQUALITY OPERATOR
        bool operator == (const Const_Node_Iterator other) const {
            return current == other.current;
        }

        // INEQUALITY OPERATOR
        bool operator != (const Const_Node_Iterator& other) const {
            return current != other.current;
        }

    private:
        const Node<Item>* current;
    };
}

#endif /* SINGLY_NODE_H */
