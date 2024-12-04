#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
using namespace std;
// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3 4     25
//                      /    \      
//                  10       14

// For the above tree the output should be 5 10 4 14 25.

// Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.
 

// Example 1:

// Input:
//        1
//      /   \
//     3     2
// Output: 3 1 2
// Explanation:
// First case represents a tree with 3 nodes
// and 2 edges where root is 1, left child of
// 1 is 3 and right child of 1 is 2.

// Thus nodes of the binary tree will be
// printed as such 3 1 2.
// Example 2:

// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 40 20 60 30
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
    void bottomView(Node* root,vector<int> &arr) {
        if(root == NULL) {
            return;
        }

        map<int,int> mp;

        queue<pair<Node*,int>> q;

        q.push(make_pair(root,0));

        while(q.empty() == false) {

            pair<Node*,int> temp = q.front();
            q.pop();
            int d = temp.second; // d is the horizontal distance , initially it was 0
            Node* frontNode = temp.first;


            mp[d] = frontNode->data;


            if(frontNode->left) {
                q.push(make_pair(frontNode->left,d-1));
            }
            if(frontNode->right) {
                q.push(make_pair(frontNode->right,d+1));
            }

            
        }

        for(auto val: mp) {
            arr.push_back(val.second);
        }

        
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


        vector<int> arr;
        bottomView(root,arr);
        cout<<endl;

        cout<<"The bottom view elements are "<<endl;
        for(auto val:arr) {
            cout<<val<<" ";
        }
        cout<<endl;

    }


