#include<iostream>
#include<queue>
using namespace std;


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
    int findMax(Node *root) {
        if(root == NULL) {
            return -1;
        }
        while(root->right != NULL) {
            root = root->right;
        }  
         return root->data;
        //code here
    }
    int findMin(Node *root) {
        //code here
        if(root == NULL) {
            return -1;
        }
        while(root->left != NULL) {
            root = root->left;
        }
        return root->data;
    }
//this is main code


int main() {
    Node* root = NULL;
    cout<<"ENter the data for node :- "<<endl;
    takeInput(root);

    cout<<"Printing Bnary Search Tree"<<endl<<endl;

    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    cout<<"Minimum is "<<findMin(root)<<endl;
    cout<<"Maximum is "<<findMax(root)<<endl;



  
}