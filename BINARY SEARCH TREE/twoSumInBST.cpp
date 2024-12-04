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
    void inorder(Node* root, vector<int> &arr) {
        if(root == NULL) {
            return;
        }

        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    string findTarget(Node* root, int k) {
        vector<int> arr;
        inorder(root,arr);

        int start = 0;
        int end = arr.size()-1;

        while(start < end) {
            int sum = arr[start] + arr[end];
            if(sum == k) {
                string x = to_string(arr[start]);
                string y = to_string(arr[end]);
                return x + " & " + y;
            }

            if(sum < k) {
                start++;
            }
            else {
                end--;
            }
        }
        return  "not found";
    }
    int main() {

            //             root
            //       a               b
            //   c       d       e       f 

        Node* root = new Node(500);
        Node* a = new Node(250);
        Node* b = new Node(750);
        Node* c = new Node(125);
        Node* d = new Node(375);
        Node* e = new Node(625);
        Node* f = new Node(875);


        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;
 

        cout<<"Original tree is "<<endl;
        levelOrderTraversal(root);
        int k = 1000;
        cout<<"Answer is "<<findTarget(root,k);
    }


