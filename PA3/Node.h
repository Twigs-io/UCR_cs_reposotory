#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

class Node {
    private:
        string data;
        int cnt;
        Node* left=NULL;
        Node* right=NULL;
    public:
        Node(string d);
        friend class BSTree;
};
#endif