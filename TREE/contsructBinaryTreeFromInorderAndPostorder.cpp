#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
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

    int findPos(vector<int>& inorder,int size,int element) {
        for(int i=0; i<size; i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int>& postorder, vector<int>& inorder,int& size,int& postIndex,int startInorder,int endInorder) {
        if(postIndex < 0 || startInorder > endInorder) {
            return NULL;
        }

        //step A: find root
        int element = postorder[postIndex];
        postIndex--;
        Node* root = new Node(element);
        int pos = findPos(inorder,size,element);

        //step B : root->right using recursion
        root->right = solve(postorder,inorder,size,postIndex,pos+1,endInorder);

        //step C : root->left using recursion
        root->left = solve(postorder,inorder,size,postIndex,startInorder,pos-1);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postIndex = size-1;
        int startInorder = 0;
        int endInorder = size-1;
        return solve(postorder,inorder,size,postIndex,startInorder,endInorder);       
    }
int main() {

        vector<int> postorder = {9,15,7,20,3};
        vector<int> inorder = {9,3,15,20,7};
        Node* root = buildTree(inorder,postorder);

        
        levelOrderTraversal(root);
}