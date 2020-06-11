#pragma once
#include <iostream>
using namespace std;

string interface_function_1() {
    string a;

    while (a != "YES" || a != "NO" || a != "n" || a != "y" || a != "N" || a != "Y") {
        cin >> a;

        if (a == "YES" || a == "Y" || a == "y")
            return "1";

        if (a == "NO" || a == "N" || a == "n")
            return "0";

        cout << "Incorrect answer! Please, use YES(y) or NO(n)" << endl;

    }
    return "00";
}

string interface_function_2() {
    string a;
    cout << "Working with: (1)binary tree, (2)heap or (3)exit from program" << endl;
    while (a != "1" || a != "2" || a != "3") {
        cin >> a;

        for (int i = 0; i < 3; i++)
            if (a == to_string(i))
                return a;

        cout << "Incorrect answer! Please, put 1, 2 or 3" << endl;
    }
    return "00";
}

string interface_function_3() {
    string a;
    cout << "What do you want to do with binary tree: (1)insert element, (2)find a specific element, (3)delete element, "
            "(4)see tree, (5)make forward pass or (6)exit from program" << endl;
    while (a != "1" || a != "2" || a != "3" || a != "4" || a != "5" || a != "6") {
        cin >> a;

        for (int i = 0; i < 6; i++)
            if (a == to_string(i))
                return a;

        cout << "Incorrect answer! Please, put 1, 2, 3, 4, 5 or 6" << endl;
    }
    return "00";
}

string interface_function_4() {
    string a;
    cout << "What do you want to do with heap: (1)insert element, (2)delete element, (3)find a specific element, "
            "(4)see heap or (5)exit from program" << endl;
    while (a != "1" || a != "2" || a != "3" || a != "4" || a != "5") {
        cin >> a;

        for (int i = 0; i < 5; i++)
            if (a == to_string(i))
                return a;

        cout << "Incorrect answer! Please, put 1, 2, 3, 4 or 5" << endl;
    }
    return "00";
}