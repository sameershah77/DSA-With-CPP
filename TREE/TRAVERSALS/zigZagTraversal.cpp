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

    void reverse(queue<int> &q) {
        if(q.empty() == true) {
            return;
        }


        int x = q.front();
        q.pop();
        reverse(q);
        q.push(x);

        return;
    }
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root == NULL) {
            return ans;
        }
        q.push(root);
        q.push(NULL);

        queue<int> Q;
        int x = 0;
        while(q.empty() != true) {
            Node* temp = q.front();
            q.pop();
            if(temp == NULL) {
                x++;
                vector<int> arr;
                if(x%2==0) {
                    reverse(Q);
                }
                while(Q.empty() != true) {
                    arr.push_back(Q.front());
                    Q.pop();
                }
                ans.push_back(arr);
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
        vector<vector<int>> arr = zigzagLevelOrder(root);

        for(int i=0; i<arr.size(); i++) {
            for(int j=0; j<arr[arr.size()-1].size()-1; j++) {
                if(arr[i][j]<0 || arr[i][j] > 150) {
                    cout<<"-"<<" ";
                }
                else {
                    cout<<arr[i][j]<<" ";
                }
                
            }
            cout<<endl;
        }
}