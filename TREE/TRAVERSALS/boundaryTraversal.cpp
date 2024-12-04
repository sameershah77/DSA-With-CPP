#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;


// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

// Example 1:

// Input:
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9
   
// Output: 1 2 4 8 9 6 7 3
// Explanation:


 

// Example 2:

// Input:
//             1
//            /
//           2
//         /  \
//        4    9
//      /  \    \
//     6    5    3
//              /  \
//             7     8

// Output: 1 2 4 6 5 7 8
// Explanation:



// As you can see we have not taken the right subtree.


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

    //code for left boundary
void printLeftBoundary(Node* root,vector<int> &arr) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL)  {
        return;
    }
    arr.push_back(root->data);

    if(root->left != NULL) {
        printLeftBoundary(root->left,arr);
    } 
    else {
        printLeftBoundary(root->right,arr);
    }

    return;

}
    //code for leaf node
void printLeafNodes(Node* root,vector<int> &arr) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        arr.push_back(root->data);
        return;
    }

    printLeafNodes(root->left,arr);
    printLeafNodes(root->right,arr);
    return;
}
    //code for right boundary
void printRightBoundary(Node* root,vector<int> &arr) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL)  {
        return;
    }
    

    if(root->right != NULL) {
        printRightBoundary(root->right,arr);
    } 
    else {
        printRightBoundary(root->left,arr);
    }

    arr.push_back(root->data);

    return;
}



//Boundary Traversal - > this is main code

void boundaryTraversal(Node* root,vector<int> &arr) {
    if(root == NULL) {
        return;
    }

    arr.push_back(root->data);

    printLeftBoundary(root->left,arr);

    printLeafNodes(root,arr);

    printRightBoundary(root->right,arr);

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

        cout<<"Your boundaries are "<<endl;

    vector<int> arr;
    boundaryTraversal(root,arr);


    for(auto val:arr) {
        cout<<val<<" ";
    }
    cout<<endl;

    }


