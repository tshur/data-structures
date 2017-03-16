#include "binary_search_tree.h"
#include <iostream>

using namespace std;
using namespace tim_struct;

int main()
{
    BinarySearchTree<double> tree;
    tree.insert(5.0);
    tree.insert(7.0);
    tree.insert(3.0);
    tree.insert(8.0);
    tree.clear();
    //inorder(node_print, tree.get_root());
    return 0;
}
