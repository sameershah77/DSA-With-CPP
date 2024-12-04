#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:


// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
// Example 2:


// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
// Example 3:

// Input: root = [2,1], p = 2, q = 1
// Output: 2
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



    void levelOrderTraversal(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(q.empty() != true) {
            //step 1:
            Node* temp = q.front();
            //step 2:
            q.pop();

            if(temp == NULL) {
                cout<<endl;
                if(q.empty()==false) {
                    q.push(NULL);
                }
            }
            else {
                //step 3:
                cout<<temp->data<<"   ";
                //step 4:
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
    }

    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root == NULL) {
            return root;
        }
        //case 1 : p & q is < then root
        if(p->data < root->data && q->data < root->data) {
            return lowestCommonAncestor(root->left,p,q);
        }
        //case 2 : p & q is > then root
        if(p->data > root->data && q->data > root->data) {
            return lowestCommonAncestor(root->right,p,q);
        }
        //case 3 : p is < root & q is > root or p is > root & q is < root
        return root;
    }

    int main() {

            //             root
            //       a               b
            //   c       d       e       f 

        Node* root = new Node(500);
        Node* a = new Node(250);
        Node* b = new Node(750);
        Node* c = new Node(125);
        Node* d = new Node(375);
        Node* e = new Node(625);
        Node* f = new Node(875);


        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;
 

        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);
        Node* p = e;
        Node* q = f;
        cout<<"Lowest common ancestor is "<<lowestCommonAncestor(root,p,q)->data;
    }


