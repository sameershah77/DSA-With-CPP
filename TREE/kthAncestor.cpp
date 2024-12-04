#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
// Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

// Example 1:



// Input:
// K = 2 Node = 4
// Output: 1
// Explanation:
// Since, K is 2 and node is 4, so we
// first need to locate the node and
// look k times its ancestors.
// Here in this Case node 4 has 1 as his
// 2nd Ancestor aka the Root of the tree.
// Example 2:

// Input:
// k=1 
// node=3
//       1
//     /   \
//     2     3

// Output:
// 1
// Explanation:
// K=1 and node=3 ,Kth ancestor of node 3 is 1.
// Your Task:
// You are asked to complete the function kthAncestor() which accepts root of the tree, k and node as input parameters, and returns the kth ancestor of Node which contains node as its value.
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
bool solve(Node* root,int& k, int node,int& ans) {
    if(root == NULL) {
        return false;
    }
    
    if(root->data == node) {
        return true;
    }
    
    bool leftAns = solve(root->left,k,node,ans);
    bool rightAns = solve(root->right,k,node,ans);
    if(leftAns || rightAns) {
        k--;
    }
    
    if(k==0) {

        ans = root->data;
        k=-1;
    }
    return leftAns || rightAns;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    solve(root,k,node,ans);
    return ans;
}

    int main() {


        Node* root = new Node();

        root = builtTree();
        //type 100 90 80 -1 70 -1 -1 60 -1 -1 50 40 -1 30 -1 -1 20 10 -1 -1 -1 
        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);
        int k = 3;
        int node = 20;
        int ans = kthAncestor(root,k,node);
        cout<<"Your kth ancestor is "<<ans<<endl;

    }


