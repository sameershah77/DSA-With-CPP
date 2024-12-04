#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
// Given the root of a binary tree, invert the tree, and return its root.

 

// Example 1:


// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// Example 2:


// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:

// Input: root = []
// Output: []
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

// this is code
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


    Node* invertTree(Node* root) {
        if(root == NULL) {
            return root;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }

    int main() {


        Node* root = new Node();

        root = builtTree();
        //type 100 90 80 -1 70 -1 -1 60 -1 -1 50 40 -1 30 -1 -1 20 10 -1 -1 -1 
        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);
        root = invertTree(root);
        cout<<"Inverted tree is "<<endl;
        levelOrderTraversal(root);
    }


