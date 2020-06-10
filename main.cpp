#include <iostream>
#include "BinaryTree.h"
#include "Tests.h"
#include "Interface.h"
using namespace std;


int main() {

    cout << "Do you want to run tests? (YES(y) or NO(n))" << endl;
    string answer = interface_function_1();
    if (answer == "1")
        tests();

    cout << "Do you want to use this program by yourself? (YES(y) or NO(n))" << endl;
    answer = interface_function_1();
    if (answer == "0") {
        cout << "Goodbye! Have a nice day/night!" << endl;
        return 0;
    }


    answer = interface_function_2();
    if (answer == "3") {
        cout << "Goodbye! Have a nice day/night!" << endl;
        return 0;
    }

    if (answer == "1") {

        binary_tree<int> binary_tree;
        for (int i = 0; i < 5; i++)
            binary_tree.add_(rand() % 100);
        cout << "The tree was created for you" << endl;
        binary_tree.print_tree_();

        answer = interface_function_3();
        int input;
        while (answer != "6") {

            if (answer == "1") {
                cout << "Enter new element: ";
                cin >> input;
                binary_tree.add_elem_(input);
            }

            if (answer == "2") {
                cout << "Which element you want to check: ";
                cin >> input;
                binary_tree.search_(input);
                cout << "Element found" << endl;
            }

            if (answer == "3") {
                cout << "Which element you want to delete: ";
                cin >> input;
                binary_tree.del_elem_(input);
            }

            if (answer == "4") {
                binary_tree.print_tree_();
                cout << endl;
            }

            if (answer == "5") {
                cout << "Forward pass: ";
                cout << binary_tree.forward_pass_() << endl;
            }

            if (answer == "6") {
                cout << "Goodbye! Have a nice day/night!" << endl;
                binary_tree.free_tree_();
                return 0;
            }
            answer = interface_function_3();
        }
        binary_tree.free_tree_();
    }

    if (answer == "2") {

        heap<int> heap;
        for (int i = 0; i < 5; i++)
            heap.add(rand() % 100);
        cout << "The heap was created for you" << endl;
        heap.print_heap();

        answer = interface_function_4();
        int input_;
        while (answer != "5") {

            if (answer == "1") {
                cout << "Enter new element: ";
                cin >> input_;
                heap.add(input_);
            }

            if (answer == "2") {
                cout << "Which element you want to delete: ";
                cin >> input_;
                heap.delete_element(input_);
            }

            if (answer == "3") {
                cout << "Which element you want to check: ";
                cin >> input_;
                cout << heap.search(input_);
            }

            if (answer == "4") {
                heap.print_heap();
                cout << endl;
            }

            if (answer == "5") {
                cout << "Goodbye! Have a nice day/night!" << endl;
                return 0;
            }
            answer = interface_function_4();
        }
    }

    return 0;
}
