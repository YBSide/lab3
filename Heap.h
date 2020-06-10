#pragma once
#include <iostream>

using namespace std;

template <typename T>
class heap {
private:
    struct branch {
        T data;
        int availability = 0;
    };
    int max_size = 1000;
    branch *elements;
    int size = 0;

public:
    explicit heap() {
        elements = new branch[max_size];
    }

public:
    void add(T item) {
        int i = size, previous;
        T tmp;
        elements[i].data = item;
        elements[i].availability = 1;
        previous = (i-1)/2;

        while(previous >= 0 && i > 0)  {
            if(elements[i].data > elements[previous].data) {
                tmp = elements[i].data;
                elements[i].data = elements[previous].data;
                elements[previous].data = tmp;
                if (elements[previous].availability == 0) {
                    elements[previous].availability = 1;
                    elements[i].availability = 0;
                }
            }

            i = previous;
            previous = (i-1)/2;
        }

        size += 1;
    }

    void delete_element(T item) {
        int target_index = 0, flag = 0;

        for (int i = 0; i < size; i++) {
            if (item == elements[i].data && elements[i].availability == 1) {
                target_index = i;
                flag = 1;
            }
        }

        int i = target_index;

        if (flag == 1) {
            while (i < size && (elements[2*i + 1].availability != 0 || elements[2*i + 2].availability != 0 ||
                    elements[i].availability != 0)) {

                if (elements[2*i + 2].availability != 0 && elements[2*i + 2].data > elements[2*i + 1].data) {
                    elements[i].data = elements[2*i + 2].data;
                    elements[i].availability = 1;
                    elements[2*i + 2].availability = 0;
                    i = 2*i + 2;
                }
                else if (elements[2*i + 1].availability != 0 && elements[2*i + 2].data < elements[2*i + 1].data) {
                    elements[i].data = elements[2*i + 1].data;
                    elements[i].availability = 1;
                    elements[2*i + 1].availability = 0;
                    i = 2*i + 1;
                } else
                    elements[i].availability = 0;
            }
        }
    }

    void print_heap() {
        int i = 0;
        int j = 1;
        while(i < size) {
            while((i < j) && (i < size)) {
                if (elements[i].availability != 0)
                    cout << elements[i].data << " ";
                i++;
            }
            cout << endl;
            j = j * 2 + 1;
        }
    }

    string search(T item) {
        for (int i = 0; i < size; i++) {
            if(elements[i].data == item && elements[i].availability == 1)
                return "element found\n";
        }
        return "not found\n";
    }

    ~heap() {
        delete[] elements;
    }
};

