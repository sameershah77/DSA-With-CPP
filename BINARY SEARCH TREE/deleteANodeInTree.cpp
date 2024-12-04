#include<iostream>
#include<queue>
using namespace std;

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.
// Example 3:

// Input: root = [], key = 0
// Output: []
 
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

//this is main code

    Node* deleteNode(Node* root, int key) {
        if(root == NULL) {
            return root;
        }

        if(root->data == key) {
            if(root->left == NULL && root->right == NULL) {
                //leaf node
                return NULL;
            }
            else if(root->left == NULL && root->right != NULL) {
                Node* child = root->right;
                return child;
                //element present in right
            }
            else if(root->left != NULL && root->right == NULL) {
                //element present in left
                Node* child = root->left;
                return child;
            }
            else {
                //element present in both side left and right
                //finding inorder predecessor . we can also find inorder successor 
                int predecessor = findMax(root->left);
                root->data = predecessor;
                root->left = deleteNode(root->left,predecessor);
			    return root;
            }
        }
        else if(root->data > key) {
            root->left = deleteNode(root->left,key);
        }
        else {
            root->right = deleteNode(root->right,key);
        }

        return root;
    }

int main() {
    Node* root = NULL;
    cout<<"ENter the data for node :- "<<endl;
    takeInput(root);

    cout<<"Printing Bnary Search Tree"<<endl<<endl;


    levelOrderTraversal(root);
    cout<<endl<<endl;
    
    cout<<"Enter key "<<endl;
    int key;
    cin>>key;
    root = deleteNode(root,key);
    cout<<"AFter deletion of "<<key<<endl;
    cout<<endl<<endl;
    levelOrderTraversal(root);
    cout<<endl<<endl;
    
  
}