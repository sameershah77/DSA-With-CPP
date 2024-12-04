#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

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

    int minDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        int ans = max(left,right)+1;//this +1 include root node count 
        return ans;
    }

int main() {


        Node* root = new Node();

        root = builtTree();
        //type 100 90 80 -1 70 -1 -1 60 -1 -1 50 40 -1 30 -1 -1 20 10 -1 -1 -1 


        cout<<"maximum height of tree is "<<minDepth(root)<<endl;
}