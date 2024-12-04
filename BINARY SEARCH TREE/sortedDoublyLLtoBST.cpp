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

    Node* sortedDLLtoBST(Node* &head, int &n) {
        if(n <= 0 || head == NULL) {
            return NULL;
        }
        int k = n-n/2-1;
        int l = n/2;
        if(n%2 != 0) {
            k = n/2;
            l = n/2;
        }
        Node* leftSubTree = sortedDLLtoBST(head,k);

        Node* root = head;
        root->left = leftSubTree;
        head = head->right;

        root->right = sortedDLLtoBST(head,l);
        return root;

    }


    int main() {


 
        Node* a = new Node(10);
        Node* b = new Node(20);
        Node* c = new Node(30);
        Node* d = new Node(40);
        Node* e = new Node(50);
        Node* f = new Node(60);
        Node* g = new Node(70);

        a->right = b;
        b->left = a;
        b->right = c;
        c->left = b;
        c->right = d;
        d->left = c;
        d->right = e;
        e->left = d;
        e->right = f;
        f->left = e;
        f->right = g;
        g->left = f;
        g->right = NULL;
        cout<<"Doubly LL is "<<endl;
        Node* temp = a;
        int n=0;
        while(temp != NULL) {
            cout<<"| "<<temp->data<<" |-> ";
            n++;
            temp = temp->right;
        }

        

        Node* root = sortedDLLtoBST(a,n);
        cout<<endl<<endl;
        cout<<"Tree will be "<<endl;
        levelOrderTraversal(root);


    }


