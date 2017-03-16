// FILE: linked_list.cxx
// AUTHOR: Tim Shur
// IMPLEMENTS: The functions of the Point class (see point.h for documentation)

#include <cstdlib>  // Provides NULL
#include <cassert>  // Provides assert
#include <iostream>

namespace tim_struct
{
    // CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
    template <class Item>
    BinarySearchTree<Item>::BinarySearchTree()
    {
        root = NULL;
        many_nodes = 0;
    }

    template <class Item>
    BinarySearchTree<Item>::BinarySearchTree(const BinarySearchTree& source)
    {
        root = tree_copy(source.root);
        many_nodes = source.many_nodes;
    }

    template <class Item>
    BinarySearchTree<Item>::~BinarySearchTree()
    {
        clear();
    }

    // MODIFICATION MEMBER FUNCTIONS
    template <class Item>
    void BinarySearchTree<Item>::insert(const Item& entry)
    {
        root = tree_insert(root, entry);
        ++many_nodes;
    }

    template <class Item>
    void BinarySearchTree<Item>::remove(const BTNode<Item>* target)
    {

    }

    template <class Item>
    void BinarySearchTree<Item>::clear()
    {
        postorder(node_destroy, root);
        many_nodes = 0;
    }

    template <class Item>
    void BinarySearchTree<Item>::operator = (const BinarySearchTree& source)
    {
        clear();
        this->BinarySearchTree(source);
    }

    // CONSTANT MEMBER FUNCTIONS
    template <class Item>
    BTNode<Item>* BinarySearchTree<Item>::search(const Item& target) const
    {
        BTNode<Item>* current = root;
        while (current != NULL)
        {
            if (target == current->data())
                return current;
            else if (target > current->data())
                current = current->right();
            else
                current = current->left();
        }

        return NULL;  // Not found
    }

    template <class Item>
    typename BinarySearchTree<Item>::size_type BinarySearchTree<Item>::occurrences(const Item& target) const
    {
        size_type count = 0;
        BTNode<Item>* current = root;
        while (current != NULL)
        {
            if (target > current->data())
                current = current->right();
            else {
                if (target == current->data())
                    ++count;
                current = current->left();
            }
        }

        return count;
    }

    // NON-MEMBER FUNCTIONS
    // TRAVERSAL -- Process f is a function of a BTNode
    template <class Item>
    void preorder(void f(BTNode<Item>*), BTNode<Item>* root_ptr)
    {
        if (root_ptr == NULL)
            return;

        f(root_ptr);
        preorder(f, root_ptr->left());
        preorder(f, root_ptr->right());
    }

    template <class Item>
    void inorder(void f(BTNode<Item>*), BTNode<Item>* root_ptr)
    {
        if (root_ptr == NULL)
            return;

        inorder(f, root_ptr->left());
        f(root_ptr);
        inorder(f, root_ptr->right());
    }

    template <class Item>
    void rinorder(void f(BTNode<Item>*), BTNode<Item>* root_ptr)
    {
        if (root_ptr == NULL)
            return;

        inorder(f, root_ptr->right());
        f(root_ptr);
        inorder(f, root_ptr->left());
    }

    template <class Item>
    void postorder(void f(BTNode<Item>*), BTNode<Item>* root_ptr)
    {
        if (root_ptr == NULL)
            return;
        std::cout << root_ptr->data() << std::endl;
        postorder(f, root_ptr->left());
        postorder(f, root_ptr->right());
        std::cout << root_ptr->data() << std::endl;
        f(root_ptr);
    }
}
