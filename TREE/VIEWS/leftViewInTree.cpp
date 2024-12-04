#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
using namespace std;
// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Example 1:

// Input:
//    1
//  /  \
// 3    2
// Output: 1 3

// Example 2:

// Input:

// Output: 10 20 40
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
    //method 1
    void leftView(Node* root, vector<int> &arr,int level) {
    if(root == NULL) {
        return;
    }
    
    
    if(level == arr.size()) {
        arr.push_back(root->data);
    }
    //left
    leftView(root->left,arr,level+1);
    //right
    leftView(root->right,arr,level+1);
    
    
    return;
}






//method 2
    void leftViewUsingLevelOrder(Node* root,vector<int> &ans) {

        queue<Node*> q;
        if(root == NULL) {
            return;
        }
        q.push(root);
        q.push(NULL);


        queue<int> Q;
        
        while(q.empty() != true) {
            Node* temp = q.front();
            q.pop();
            if(temp == NULL) {
                if(Q.empty() == false) {
                    ans.push_back(Q.front());
                }
                while(Q.empty() != true) {
                    Q.pop();
                }

                
                if(q.empty()==false) {
                    q.push(NULL);
                }
            }
            else {
                Q.push(temp->data);
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
        return;
    }
    int main() {

            //             root
            //       a               b
            //   c       d       e       f 
            // g   h   i   j   k   l   m   n 

        Node* root = new Node(150);
        Node* a = new Node(140);
        Node* b = new Node(130);
        Node* c = new Node(120);
        Node* d = new Node(110);
        Node* e = new Node(100);
        Node* f = new Node(90);
        Node* g = new Node(80);
        Node* h = new Node(20);
        Node* i = new Node(10);
        Node* j = new Node(50);
        Node* k = new Node(30);
        Node* l = new Node(30);
        Node* m = new Node(20);
        Node* n = new Node(10);

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


        cout<<"Method 1"<<endl;



        vector<int> arr;
        int level = 0;
        leftView(root,arr,level);
        cout<<endl;

        cout<<"The left view elements are "<<endl;
        for(auto val:arr) {
            cout<<val<<" ";
        }
        cout<<endl;




        cout<<"Method 2"<<endl;




        vector<int> arr2;


        leftViewUsingLevelOrder(root,arr2);

        cout<<endl;

        cout<<"The left view elements are "<<endl;
        for(auto val:arr2) {
            cout<<val<<" ";
        }
        cout<<endl;
    }


