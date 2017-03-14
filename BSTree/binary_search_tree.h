// FILE: binary_search_tree.h
// AUTHOR: Tim Shur
// PROVIDES: A class for a BinarySearchTree within the namespace tim_struct.
//
// INVARIANT for the BinarySearchTree class:
//
//
// CONSTRUCTORS for the BinarySearchTree class:
//
//
// MODIFICATION MEMBER FUNCTIONS for the BinarySearchTree class:
//
//
// CONSTANT MEMBER FUNCTIONS for the BinarySearchTree class:
//
//
// NON-MEMBER FUNCTIONS for the BinarySearchTree class:
//
//
// VALUE SEMANTICS for the BinarySearchTree class:
//     The copy constructor and assignment operator are valid for the
//     BinarySearchTree class.
//
// DYNAMIC MEMORY usage by the BinarySearchTree class:
//     If there is insufficient memory, the following functions will call
//     bad_alloc:

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binary_tree_node.h"

namespace tim_struct
{
    template <class Item>
    class BinarySearchTree
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;

        // CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& source);
        ~BinarySearchTree();

        // MODIFICATION MEMBER FUNCTIONS
        void insert(const Item& entry);
        void delete(const BTNode<Item>* target);
        void operator = (const BinarySearchTree& source);

        // CONSTANT MEMBER FUNCTIONS
        BTNode<Item>* search(const Item& target) const;
        size_type occurrences(const Item& target) const;
        size_type length() const { return many_nodes; }

        // (PRINT) TRAVERSAL -- TO ADD GENERAL PROCESS
        void preorder(BTNode<Item>* root_ptr = root);
        void inorder(BTNode<Item>* root_ptr = root);
        void postorder(BTNode<Item>* root_ptr = root);

    private:
        BTNode<Item>* root;
        size_type many_nodes;
    };

    // NON-MEMBER FUNCTIONS
}


#include "binary_search_tree.cxx"
#endif /* BINARY_SEARCH_TREE_H */
