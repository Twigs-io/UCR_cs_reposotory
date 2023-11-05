#include "BSTree.h"

BSTree::BSTree(){
    root=nullptr;
}

BSTree::~BSTree(){
    destructorhelper(root);
    root=nullptr;
}

void BSTree::destructorhelper(Node* n){
    if(n!=nullptr){
        destructorhelper(n->left);
        destructorhelper(n->right);
        delete(n);
    }
}

void BSTree::insert(const string &item) {
    Node* temp = new Node(item);

    if(root == nullptr){
        root = temp;
        return;
    }
    
    Node* cur = root;
    while(cur != NULL){
        if(temp->data < cur->data){
            if(cur->left == NULL){
                cur->left = temp;
                cur = NULL;
            }
            else{
                cur = cur->left;
            }
        }
        else if(cur->data == temp->data){
            cur->cnt+=1;
            return;
        }
        else{
            if(cur->right == NULL){
                cur->right = temp;
                cur = NULL;
            }
            else{
                cur = cur->right;
            }

        }
    }
}
void BSTree::remove(const string &key){
    Node* curr = root, *parent = nullptr;
    Node* suc = nullptr;

    while(curr!=nullptr){
        if(curr->data == key){
            break;
        }
        else if(curr->data < key){
            parent = curr;
            curr = curr->right;
        }
        else{
            parent = curr;
            curr = curr->left;
        }
    }

    if(curr == nullptr){
        return;
    }
    if(curr->cnt > 1){
        curr->cnt--;
        return;
    }
    if (curr->left == nullptr && curr->right == nullptr) { // Remove leaf
        if (parent == nullptr) 
            root = nullptr;
        else if (key < parent->data) 
            parent->left = nullptr;
        else
            parent->right = nullptr;
    }
    else{
        if (curr->left != nullptr) {                // Remove node with only left child
            suc = curr->left;
            while (suc->right != nullptr){
                suc = suc->right;
            }
        }
        else{                // Remove node with only right child
            suc = curr->right;
            while (suc->left != nullptr){
                suc = suc->left;
            }
        }                                    // Remove node with two children
        string successorData = suc->data;
        int succount = suc->cnt;
        suc->cnt=0;
        remove(successorData);    // Remove successor
        curr->data=successorData;
        curr->cnt=succount;
    }
    return;
}

bool BSTree::search(const string &key) const{
    Node* temp = root;
    while(temp != nullptr){
        if(key > temp->data){
            temp = temp->right;
        }
        else if(key < temp->data){
            temp = temp->left;
        }
        else{
            return true;
        }
    }
    return false;
}



string BSTree::largest() const{
    if(root==nullptr) return "";
    Node* temp = root;
    while(temp->right!=nullptr){
        temp=temp->right;
    }
    return temp->data;
}

string BSTree::smallest() const{
    if(root==nullptr) return "";
    
    Node* temp = root;
    while(temp->left!=nullptr){
        temp=temp->left;
    }
    return temp->data;
}

int BSTree::height(const string &key){
    if(root==nullptr) return -1;
    Node* temp = root;
    while(temp!=nullptr){
        if(key > temp->data){
            temp = temp->right;
        }
        else if(key < temp->data){
            temp = temp->left;
        }
        else{
            return heights(temp);
        }
    }
    return -1;
}

int BSTree::heights(Node* a){
    if(a == nullptr){
        return -1;
    }
    else{
        int left = heights(a->left);
        int right = heights(a->right);
        return max(left, right)+1;
    }
}

void BSTree::preOrder(){
    preOrder(root);
    return;
}

void BSTree::preOrder(Node* a){
    if(a == nullptr)    return;

    cout << a->data << "("<< a->cnt << ")"<< ", ";
    preOrder(a->left);
    preOrder(a->right);
}

void BSTree::postOrder(){
    postOrder(root);
}

void BSTree::postOrder(Node* a){
    if(a == nullptr)    return;

    postOrder(a->left);
    postOrder(a->right);
    cout << a->data << "("<< a->cnt << ")"<< ", ";
}

void BSTree::inOrder(){
    inOrder(root);
}

void BSTree::inOrder(Node* a)
{
    if(a == nullptr)    return;

    inOrder(a->left);
    cout << a->data << "("<< a->cnt << ")"<< ", ";
    inOrder(a->right);
}