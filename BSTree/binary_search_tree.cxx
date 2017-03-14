// FILE: linked_list.cxx
// AUTHOR: Tim Shur
// IMPLEMENTS: The functions of the Point class (see point.h for documentation)

#include <cstdlib>  // Provides NULL
#include <cassert>  // Provides assert

namespace tim_struct
{
    // CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
    template <class Item>
    BinarySearchTree()
    {
        root = NULL;
        many_nodes = 0;
    }

    template <class Item>
    BinarySearchTree(const BinarySearchTree& source)
    {

    }

    template <class Item>
    ~BinarySearchTree()
    {

    }

    // MODIFICATION MEMBER FUNCTIONS
    template <class Item>
    void insert(const Item& entry)
    {

    }

    template <class Item>
    void delete(const BTNode<Item>* target)
    {

    }

    template <class Item>
    void operator = (const BinarySearchTree& source)
    {

    }

    // CONSTANT MEMBER FUNCTIONS
    template <class Item>
    BTNode<Item>* search(const Item& target) const
    {

    }

    template <class Item>
    size_type occurrences(const Item& target) const
    {

    }

    // (PRINT) TRAVERSAL -- TO ADD GENERAL PROCESS
    template <class Item>
    void preorder(BTNode<Item>* root_ptr = root)
    {

    }

    template <class Item>
    void inorder(BTNode<Item>* root_ptr = root)
    {

    }

    template <class Item>
    void postorder(BTNode<Item>* root_ptr = root)
    {

    }
}
