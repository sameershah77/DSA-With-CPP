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

void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    //LNR
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

    return;

}
void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    //NLR
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

    return;

}
void postOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    //LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

    return;

}
int main() {
    Node* root = NULL;
    cout<<"ENter the data for node :- "<<endl;
    takeInput(root);
    cout<<"Printing Bnary Search Tree"<<endl<<endl;

    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;

    cout<<"InOrder Traversal"<<endl;
    inOrder(root);
    cout<<endl<<endl;

    cout<<"PreOrder Traversal"<<endl;
    preOrder(root);
    cout<<endl<<endl;    

    cout<<"PostOrder Traversal"<<endl;
    postOrder(root);
    cout<<endl<<endl;    
}