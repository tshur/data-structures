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

namespace tim_struct
{
    template <class Item>
    class Node
    {
    public:
        typedef Item value_type;

        Node(const Item& init_data = Item(), const Node* init_link = NULL);

        void set_data(const Item& new_data) { data_field = new_data; }
        void set_link(const Node* new_link) { link_field = new_link; }

        Item data() const { return data_field; }

        Node* link() const { return link_field; }
        const Node* link() const { return link_field; }

    private:
        Item data_field;
        Node* link_field;
    };
}

#endif /* SINGLY_NODE_H */
