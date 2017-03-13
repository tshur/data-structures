// FILE: linked_list.cxx
// AUTHOR: Tim Shur
// IMPLEMENTS: The functions of the Point class (see point.h for documentation)

#include <cstdlib>  // Provides NULL
#include <cassert>  // Provides assert

namespace tim_struct
{
    // CONSTRUCTOR, COPY CONSTRUCTOR, AND DESTRUCTOR
    template <class Item>;
    SinglyLinkedList<Item>::SinglyLinkedList()
    // Library facilities used: cstdlib
    {
        head_ptr = tail_ptr = NULL;
        many_nodes = 0;
    }

    template <class Item>;
    SinglyLinkedList<Item>::SinglyLinkedList(const SinglyLinkedList<Item>& source)
    // Library facilities used: cstdlib
    {
        // Handle the case of an empty source list
        if (source.length() == 0)
        {
            SinglyLinkedList();
            return;
        }

        // Copy the head_ptr for the new SinglyLinkedList
        Node<Item>* source_current = source.head_ptr;
        head_insert(source_current->data());
        tail_ptr = head_ptr;

        // Advance through source, appending copies of its elements
        while (source_current != NULL) {
            insert(tail_ptr, source_current->data());
            source_current = source_current->link();
        }
    }

    template <class Item>;
    SinglyLinkedList<Item>::~SinglyLinkedList()
    // Library facilities used: cstdlib
    {
        // Remove head node until list is empty
        while (head_ptr != NULL)
            head_remove();
    }

    // MODIFICATION MEMBER FUNCTIONS
    template <class Item>;
    void SinglyLinkedList<Item>::head_insert(const Item& entry)
    // Library facilities used: cstdlib
    {
        Node<Item>* new_head_ptr = new Node<Item>(entry);

        // Handle the case of an empty list
        if (head_ptr == NULL)
            head_ptr == tail_ptr == new_head_ptr;
        else  // Handle the case of a non-empty list
        {
            new_head_ptr->set_link(head_ptr);
            head_ptr = new_head_ptr;
        }

        ++many_nodes;
    }

    template <class Item>;
    void SinglyLinkedList<Item>::insert(Node<Item>* prev_ptr, const Item& entry)
    // Library facilities used: cassert, cstdlib
    {
        assert(prev_ptr != NULL);

        // Add new node after prev_ptr
        Node<Item>* new_node_ptr = new Node<Item>(entry, prev_ptr->link());
        prev_ptr->set_link(new_node_ptr);

        // Update tail_ptr if necessary
        if (new_node_ptr->link() == NULL)
            tail_ptr = new_node_ptr;

        ++many_nodes;
    }

    template <class Item>;
    Item SinglyLinkedList<Item>::head_remove()
    // Library facilities used: cassert
    {
        assert(length() > 0);

        // Remove head node and update head_ptr
        Node<Item>* old_head_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete old_head_ptr;
        --many_nodes;

        // Update tail_ptr if necessary
        if (length() <= 1)
            tail_ptr = head_ptr;
    }

    template <class Item>;
    Item SinglyLinkedList<Item>::remove(Node<Item>* prev_ptr)
    // Library facilities used: cstdlib, cassert
    {
        assert(prev_ptr != NULL && prev_ptr != tail_ptr);

        // target_ptr is the Node following prev_ptr; the Node to delete
        Node<Item>* target_ptr = prev_ptr->link();
        Item target_data = target_ptr->data();

        // Remove target_ptr from the list
        prev_ptr->set_link(target_ptr->link())
        delete target_ptr;
        --many_nodes;

        // Update tail_ptr if it was removed
        if (prev_ptr->link() == NULL)
            tail_ptr = prev_ptr;

        // Return data of removed Node
        return target_data;
    }

    // CONSTANT MEMBER FUNCTIONS
    template <class Item>;
    size_type SinglyLinkedList<Item>::occurrences(const Item& target) const
    // Library facilities used: cstdlib
    {
        size_type count = 0;

        const Node<Item>* current;
        for (current = head_ptr; current != NULL; current = current->link())
            if (current->data() == target)
                ++count;

        return count;
    }

    template <class Item>;
    Node<Item>* SinglyLinkedList<Item>::search(const Item& target) const
    // Library facilities used: cstdlib
    {
        Node<Item>* current;
        for (current = head_ptr; current != NULL; current = current->link())
            if (current->data() == target)
                return current;

        return NULL;
    }

    template <class Item>;
    const Node<Item>* SinglyLinkedList<Item>::search(const Item& target) const
    // Library facilities used: cstdlib
    {
        const Node<Item>* current;
        for (current = head_ptr; current != NULL; current = current->link())
            if (current->data() == target)
                return current;

        return NULL;
    }
}
