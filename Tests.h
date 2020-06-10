#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "Heap.h"
using namespace std;



void tests() {
    int test_data[5] = {7, 23, 46, 35, 54};

    binary_tree<int> test_binary_tree;
    for (int i : test_data)
        test_binary_tree.add_(i);

    heap<int> test_heap;
    for (int i : test_data)
        test_heap.add(i);



    if(test_binary_tree.forward_pass_() == "7 23 46 35 54 ")
        cout << "Test 1 passed!" << endl;
    else
        cout << "Test 1 failed" << endl;

    test_binary_tree.del_elem_(1);
    if(test_binary_tree.forward_pass_() == "7 23 46 35 54 ")
        cout << "Test 2 passed!" << endl;
    else
        cout << "Test 2 failed" << endl;

    test_binary_tree.del_elem_(46);
    if(test_binary_tree.forward_pass_() == "7 23 54 35 ")
        cout << "Test 3 passed!" << endl;
    else
        cout << "Test 3 failed" << endl;

    test_binary_tree.add_elem_(16);
    if(test_binary_tree.forward_pass_() == "7 23 16 54 35 ")
        cout << "Test 4 passed!" << endl;
    else
        cout << "Test 4 failed" << endl;

    if(test_binary_tree.search_(35) == 35)
        cout << "Test 5 passed!" << endl;
    else
        cout << "Test 5 failed" << endl;

    auto ext_tree = test_binary_tree.subtree_extraction(23);
    if(ext_tree->forward_pass_() == "23 16 54 35 ")
        cout << "Test 6 passed!" << endl;
    else
        cout << "Test 6 failed" << endl;

    if(test_heap.search(87) == "not found\n")
        cout << "Test 7 passed!" << endl;
    else
        cout << "Test 7 failed" << endl;

    if(test_heap.search(35) == "element found\n")
        cout << "Test 8 passed!" << endl;
    else
        cout << "Test 8 failed" << endl;

    test_binary_tree.free_tree_();
    ext_tree->free_tree_();
    delete ext_tree;

}
