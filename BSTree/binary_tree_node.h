// FILE: binary_tree_node.h
// AUTHOR: Tim Shur
// PROVIDES: A class for a BTNode within the namespace tim_struct.
//
// INVARIANT for the BTNode class:
//
//
// CONSTRUCTORS for the BTNode class:
//
//
// MODIFICATION MEMBER FUNCTIONS for the BTNode class:
//
//
// CONSTANT MEMBER FUNCTIONS for the BTNode class:
//
//
// NON-MEMBER FUNCTIONS for the BTNode class:
//
//
// VALUE SEMANTICS for the BTNode class:
//     The copy constructor and assignment operator are valid for the
//     BTNode class.
//
// DYNAMIC MEMORY usage by the BTNode class:
//     If there is insufficient memory, the following functions will call
//     bad_alloc:

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <cstdlib>  // Provides NULL
#include <iostream> // Provides cout and endl

namespace tim_struct
{
    template <class Item>
    class BTNode
    {
    public:
        BTNode(const Item& init_data = Item(), BTNode* init_left = NULL, BTNode* init_right = NULL) {
            data_field = init_data;
            left_child = init_left;
            right_child = init_right;
        }

        void set_data(const Item& new_data) { data_field = new_data; }
        void set_left(BTNode* new_left) { left_child = new_left; }
        void set_right(BTNode* new_right) { right_child = new_right; }

        Item& data() { return data_field; }
        const Item& data() const { return data_field; }

        BTNode* left() { return left_child; }
        const BTNode* left() const { return left_child; }
        BTNode* right() { return right_child; }
        const BTNode* right() const { return right_child; }
        bool isLeaf() const {
            return left_child == NULL && right_child == NULL;
        }

    private:
        Item data_field;
        BTNode* left_child;
        BTNode* right_child;
    };

    // NON-MEMBER UTILITY FUNCTIONS
    template <class Item>
    void node_destroy(BTNode<Item>* target) {
        delete target;
    }

    template <class Item>
    void node_print(BTNode<Item>* target) {
        std::cout << " " << target->data() << " " << std::endl;
    }

    template <class Item>
    BTNode<Item>* tree_insert(BTNode<Item>* root, const Item& entry) {
        if (root == NULL)
            root = new BTNode<Item>(entry);
        else if (entry > root->data())
            root->set_right(tree_insert(root->right(), entry));
        else
            root->set_left(tree_insert(root->left(), entry));

        return root;
    }

    template <class Item>
    BTNode<Item>* tree_copy(BTNode<Item>* root) {
        if (root == NULL)
            return NULL;
        return new BTNode<Item>*(root->data(), tree_copy(root->left()),
                                               tree_copy(root->right()));
    }
}

#endif /* BINARY_TREE_NODE_H */
