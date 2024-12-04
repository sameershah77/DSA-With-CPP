#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;


// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

 

// Example 1:


// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:

// Input: root = [1,2]
// Output: 1
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

Node* builtTree() {
    int data;
    cout<<"Enter the data : ";
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    //step A : creat a Node
    Node* root = new Node(data);

    //step B : creat left Node
    cout<<"Enter data in left of "<<data<<" node : ";
    root->left = builtTree();

    //step C : creat right Node
    cout<<"Enter data in right of "<<data<<" node : ";
    root->right = builtTree();

    return root;
}

//this is code
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int ans = max(left,right)+1;
        return ans;
    }
    int solve(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int leftDiameter = solve(root->left);
        int rightDiameter = solve(root->right);
        int overal = maxDepth(root->left) + 1 + maxDepth(root->right);
        int ans = max(leftDiameter,max(rightDiameter,overal));

        return ans;
    }
    int diameterOfBinaryTree(Node* root) {
        return solve(root) - 1; // -1 becouse we counting no of edges not nodes
    }

int main() {


        Node* root = new Node();

        root = builtTree();
        //type 100 90 80 -1 70 -1 -1 60 -1 -1 50 40 -1 30 -1 -1 20 10 -1 -1 -1 


        cout<<"Diemeter of tree is "<<maxDepth(root)<<endl;
}