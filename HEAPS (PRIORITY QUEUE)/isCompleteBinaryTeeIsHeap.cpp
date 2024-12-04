#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node() {
        right = NULL;
        left = NULL;
        data = data;
    }

    Node(int data) {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

pair<bool,int> isHeap(Node* root){

    if(root == NULL) {
        pair<bool,int> p = make_pair(true,INT_MIN);
        return p;
    }

    if(root->left == NULL && root->right == NULL) {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }


    pair<bool,int> leftAns = isHeap(root->left);
    pair<bool,int> rightAns = isHeap(root->right);

    if(leftAns.first == true && rightAns.first == true && root->data > leftAns.second && root->data > rightAns.second) {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    else {
        pair<bool,int> p = make_pair(false,root->data);
    }

}
int main() {
            //             root
            //       a               b
            //   c       d       e       f 


        Node* root = new Node(200);
        Node* a = new Node(180);
        Node* b = new Node(170);
        Node* c = new Node(100);
        Node* d = new Node(110);
        Node* e = new Node(150);
        Node* f = new Node(80);


        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;

        pair<bool,int> p = isHeap(root);

        if(p.first == true) {
            cout<<"Given Tree is a Heap"<<endl;
        }
        else {
            cout<<"Given Tree is not a Heap"<<endl;
        }

}