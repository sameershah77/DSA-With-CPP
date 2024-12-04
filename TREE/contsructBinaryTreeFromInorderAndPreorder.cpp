#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
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
    Node* solve(vector<int>& preorder, vector<int>& inorder,int& size,int& preIndex,int startInorder,int endInorder) {
        if(preIndex >= size || startInorder > endInorder) {
            return NULL;
        }

        //step A: find root
        int element = preorder[preIndex];
        preIndex++;
        Node* root = new Node(element);
        int pos = findPos(inorder,size,element);


        //step B : root->left using recursion
        root->left = solve(preorder,inorder,size,preIndex,startInorder,pos-1);

        //step C : root->right using recursion
        root->right = solve(preorder,inorder,size,preIndex,pos+1,endInorder);

        return root;
    }
    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        int preIndex = 0;
        int startInorder = 0;
        int endInorder = size-1;
        return solve(preorder,inorder,size,preIndex,startInorder,endInorder);
    }

int main() {

        vector<int> preorder = {3,9,20,15,7};
        vector<int> inorder = {9,3,15,20,7};
        Node* root = buildTree(preorder,inorder);

        
        levelOrderTraversal(root);
}