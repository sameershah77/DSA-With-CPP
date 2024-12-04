#include<iostream>
#include<queue>
using namespace std;

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:


// Input: root = [2,1,3]
// Output: true
// Example 2:


// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};

Node* BST(Node* root,int data) {
    
    if(root == NULL) {
        //this is the first node
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = BST(root->left,data);
    }
    else {
        root->right = BST(root->right,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1) {
        root = BST(root,data);
        cin>>data;
    }
    return;
}

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
            cout<<temp->data<<"  ";
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
    bool solve(Node* root, long long int lowerBound, long long int upperBound) {
        if(root == NULL) {
            return true;
        }

        if(root->data < upperBound && root->data > lowerBound) {
            bool leftAns = solve(root->left,lowerBound,root->data);
            bool rightAns = solve(root->right,root->data,upperBound);
            return leftAns && rightAns;
        }
        else {
            return false;
        }
    }
    bool isValidBST(Node* root) {
        long long int lowerBound = -4294967296;
        long long int upperBound = 4294967296;
        bool ans = solve(root,lowerBound,upperBound);
        return ans;
    }
int main() {
    Node* root = NULL;
    cout<<"ENter the data for node :- "<<endl;
    takeInput(root);
    cout<<"Printing Bnary Search Tree"<<endl<<endl;

    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    if(isValidBST(root)) {
        cout<<"BST is valid"<<endl;
    }
    else {
        cout<<"BST is invalid"<<endl;
    }
 
}