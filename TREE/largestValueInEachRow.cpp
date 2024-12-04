#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

// Example 1:


// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]
// Example 2:

// Input: root = [1,2,3]
// Output: [1,3]
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

    vector<int> largestValues(Node* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<Node* > q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            int maxi = INT_MIN;
            for(int i = 0; i < n; i++){
                Node* node = q.front();
                q.pop();
                maxi = max(maxi, node -> data);
                if(node -> left)
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);
            }
            ans.push_back(maxi);
        }
        return ans;
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

        vector<int> ans = largestValues(root);

        cout<<"Answer are"<<endl;
        for(auto val: ans) {
            cout<<val<<" ";
        }
}