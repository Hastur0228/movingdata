#include <iostream>
#include "binarySearchTree.h"

using namespace std;

void display(SET<int, char*>* p) {
    if (p != NULL) cout << p->key << ", " << p->other << endl;
    else cout << "not found" << endl;
}

int main() {
    SET<int, char*> a[] = 
    { {10, (char*)"aaa"}, {8, (char*)"bbb"}, {21, (char*)"ccc"}, {87, (char*)"ddd"},
         {56, (char*)"eee"}, {4, (char*)"fff"}, {11, (char*)"ggg"}, {3, (char*)"hhh"},
         {22, (char*)"iii"}, {7, (char*)"jjj"} };

    binarySearchTree<int, char*> tree;
    SET<int, char*> x;
    SET<int, char*>* p;

    for (int i = 0; i < 10; ++i) {
        tree.insert(a[i]);
    }

    for (int i = 9; i >= 0; i--) {
        cout << "now find: " << i << ", ";
        display(tree.find(a[i].key));
    }
    for (int i = 0; i < 20; ++i) {
        tree.remove(i);
    }
    cout << endl;
    display(tree.find(23));
    cout << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "now find: " << a[i].key << ", ";
        display(tree.find(a[i].key));
    }

    return 0;
}
