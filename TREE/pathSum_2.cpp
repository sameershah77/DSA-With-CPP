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



// this is code
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


    void solve(Node*& root, int &targetSum, vector<int> &path,int &sum, vector<vector<int>> &ans){
        if(root == NULL) {
            return;
        }
            
        if(root->left == NULL && root->right == NULL) {
            path.push_back(root->data);
            sum +=  root->data;
            if(sum == targetSum) {
                ans.push_back(path);
            }
            path.pop_back();
            sum -= root->data;            
            return;
        }

        path.push_back(root->data);
        sum += root->data;
        solve(root->left,targetSum,path,sum,ans);
        solve(root->right,targetSum,path,sum,ans);

        //backtrack
        path.pop_back();
        sum -= root->data;
        
    }

    
    vector<vector<int>> pathSum(Node*& root, int &targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        solve(root,targetSum,path,sum,ans);
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


        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);
        int targetSum = 410;
        vector<vector<int>> arr = pathSum(root,targetSum);

        cout<<endl<<"Your paths sum for "<<targetSum<<" are "<<endl<<endl;
        for(int i=0; i<arr.size(); i++) {
            for(int j=0; j<arr[0].size(); j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }


