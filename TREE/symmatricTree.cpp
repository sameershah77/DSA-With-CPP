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
                cout<<temp->data<<"   ";
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
    bool isMirror(Node* left, Node* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        bool ans1 = left->data == right->data;
        bool ans2 = isMirror(left->left , right->right);
        bool ans3 = isMirror(left->right , right->left);
        return ans1 && ans2 && ans3;
    }

    //this is main code
    bool isSymmetric(Node* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }

    int main() {


            //             root
            //       a               b
            //   c       d       e       f 


        Node* root = new Node(1);
        Node* a = new Node(2);
        Node* b = new Node(2);
        Node* c = new Node(3);
        Node* d = new Node(4);
        Node* e = new Node(4);
        Node* f = new Node(3);


        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;



        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);

        if(isSymmetric(root)) {
            cout<<"Tree is symmatric"<<endl;
        }
        else {
            cout<<"Tree is not symmatric"<<endl;
        }
    }


