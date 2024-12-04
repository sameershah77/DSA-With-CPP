#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
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

class NodeData{
    public:

    int size;
    int minVal;
    int maxVal;

    bool validBST;
    NodeData() {

    }
    NodeData(int size, int min, int max, bool valid) {
        this->size = size;
        this->minVal = min;
        this->maxVal = max;
        this->validBST = valid;

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

    NodeData largestBST(Node* root, int &ans,Node* &temp) {

        if(root == NULL) {
            NodeData temp(0,INT_MAX,INT_MIN,true);
            return temp;
        }

        NodeData leftAns = largestBST(root->left,ans,temp);
        NodeData rightAns = largestBST(root->right,ans,temp);

        NodeData currNode;

        currNode.size = leftAns.size + rightAns.size +1;
        currNode.minVal = min(root->data,leftAns.minVal);
        currNode.maxVal = max(root->data,rightAns.maxVal);


        if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data<rightAns.minVal)) {
            currNode.validBST = true;

        }
        else{
            currNode.validBST = false;
        }

        if(currNode.validBST) {
            temp = root;
            ans = max(ans,currNode.size);
        }

        return currNode;

    }

    void BSTsum(Node* root, int &sum) {
        if(root == NULL) {
            return;
        }

        if(root->left) {
            BSTsum(root->left,sum);
        }

        sum += root->data;

        if(root->right) {
            BSTsum(root->right,sum);
        }
    }


    int main() {

            //             root
            //       a               b
            //   c       d       e       f 
            // g   h   i   j   k   l   m   n 

        Node* root = new Node(150);
        Node* a = new Node(35);
        Node* b = new Node(200);
        Node* c = new Node(23);
        Node* d = new Node(1);
        Node* e = new Node(190);
        Node* f = new Node(210);
        Node* g = new Node(2);
        Node* h = new Node(3);
        Node* i = new Node(6);
        Node* j = new Node(8);
        Node* k = new Node(180);
        Node* l = new Node(195);
        Node* m = new Node(205);
        Node* n = new Node(220);

        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;
        c->left = g;
        c->right = h;
        d->left = i;
        d->right = j;
        e->left = k;
        e->right = l;
        f->left = m;
        f->right = n;


        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);

        int ans = 0;
        int sum = 0;
        Node* temp;
        largestBST(root,ans,temp);

        BSTsum(temp,sum);
        cout<<ans<<endl;
        cout<<sum<<endl;
    }


