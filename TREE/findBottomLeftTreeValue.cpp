#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

// Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

// Example 1:


// Input: root = [2,1,3]
// Output: 1
// Example 2:


// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7


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

    void solve(Node* root, int &maxDepth, int &leftVal, int depth) {
        if(root == NULL) {
            return;
        }

        solve(root->left,maxDepth,leftVal,depth+1);
        solve(root->right,maxDepth,leftVal,depth+1);

        if(depth > maxDepth) {
            maxDepth = depth;
            leftVal = root->data;
        }

    }
    int findBottomLeftValue(Node* root) {
        int maxDepth = 0;
        int depth = 0;
        int leftVal = root->data;
        solve(root,maxDepth,leftVal,depth);
        return leftVal;
    }


    int main() {

            //             root
            //       a               b
            //           d       e       f 
            //         i   j   k   l   m   n 

        Node* root = new Node(150);
        Node* a = new Node(140);
        Node* b = new Node(130);
  
        Node* d = new Node(110);
        Node* e = new Node(100);
        Node* f = new Node(90);


        Node* i = new Node(10);
        Node* j = new Node(50);
        Node* k = new Node(30);
        Node* l = new Node(30);
        Node* m = new Node(20);
        Node* n = new Node(10);

        root->left = a;
        root->right = b;

        a->right = d;
        b->left = e;
        b->right = f;

        d->left = i;
        d->right = j;
        e->left = k;
        e->right = l;
        f->left = m;
        f->right = n;


        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);

        cout<<"your bottom left element is "<<findBottomLeftValue(root)<<endl;


    }


