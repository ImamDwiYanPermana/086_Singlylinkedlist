#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    int noMhs;
    char nama[20];
    Node* next;
};

class list {
    Node* START;
public:
    list();
    void addnode();
    bool Search(int nim, Node** current, Node** previous);
    bool listEmpty();
    bool delnode(int element);
    void traverse();
};

