#include<iostream>
using namespace std;

// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

// Example 1:


// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
// Example 2:


// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
// Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.


class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node() {
        right = NULL;
        left = NULL;
        val = val;
    }

    Node(int val) {
        this->val = val;
        right = NULL;
        left = NULL;
    }
};


    void inorder(Node* root, int l, int h, int &sum) {
        if(root == NULL) {
            return;
        }

        if(root->val >= l && root->val <= h) {
            sum += root->val;
            inorder(root->left,l,h,sum);
            inorder(root->right,l,h,sum);
        }
        else if(root->val < l) {
            inorder(root->right,l,h,sum);
        }
        else {
            inorder(root->left,l,h,sum);
        }
        return;     
           
    }
    int rangeSumBST(Node* root, int low, int high) {
        int sum = 0;
        inorder(root, low, high,sum);
        return sum;
    }
int main() {
    
        Node* root = new Node(10);
        Node* a = new Node(5);
        Node* b = new Node(15);
        Node* c = new Node(3);
        Node* d = new Node(7);
        Node* e = NULL;
        Node* f = new Node(18);


        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;

        int low = 7;
        int high = 15;

        cout<<"Range sum is "<<rangeSumBST(root,low,high)<<endl;
}