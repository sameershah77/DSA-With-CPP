#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
// Given a binary tree, determine if it is 
// height-balanced
// .
// Height-Balanced
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
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
    int height(Node*& root) {
        if(root == NULL) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left,right)+1;
        return ans;
    }
    bool isBalanced(Node* root) {
        if(root == NULL) {
            return true;
        }
        //1 case

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool ans1 = (diff <= 1); 

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(ans1 && leftAns && rightAns) {
            return true;
        }
        return false;
    }

    int main() {


        Node* root = new Node();

        root = builtTree();
        //type 100 90 80 -1 70 -1 -1 60 -1 -1 50 40 -1 30 -1 -1 20 10 -1 -1 -1 
        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);

        isBalanced(root)?cout<<"Tree is balanced"<<endl : cout<<"Tree is Unbalanced"<<endl;


    }


