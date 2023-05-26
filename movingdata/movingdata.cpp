#include <iostream>
#include "binarySearchTree.h"

using namespace std;

void display(SET<int, char*>* p) {
    if (p != NULL) cout << p->key << ", " << p->other << endl;
    else cout << "not found" << endl;
}

int main() {
    SET<int, char*> a[] = { {10, (char*)"aaa"}, {8, (char*)"bbb"}, {21, (char*)"ccc"}, {87, (char*)"ddd"},
          {56, (char*)"eee"}, {4, (char*)"fff"}, {11, (char*)"ggg"}, {3, (char*)"hhh"},
          {22, (char*)"iii"}, {7, (char*)"jjj"} };

    binarySearchTree<int, char*> tree;

    for (int i = 0; i < 10; ++i) {
        tree.insert(a[i]);
    }

    for (int i = 1; i <= 10; ++i) {
        display(tree.findKth(i));
    }
    return 0;
}