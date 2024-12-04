#include<iostream>
#include<queue>
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

    void inorder(Node* root,vector<int> &nums) {
        if(root == NULL) {
            return;
        }

        inorder(root->left,nums);
        nums.push_back(root->data);
        inorder(root->right,nums);
    }


    void postorder(Node* &root,vector<int> &nums,int &i) {
        if(root == NULL) {
            return;
        }

        postorder(root->left,nums,i);
        postorder(root->right,nums,i);
        root->data = nums[i++];

    }








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
            cout<<temp->data<<"  ";
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

int main() {
            //             root
            //       a               b
            //   c       d       e       f 


        Node* root = new Node(200);
        Node* a = new Node(180);
        Node* b = new Node(220);
        Node* c = new Node(170);
        Node* d = new Node(190);
        Node* e = new Node(210);
        Node* f = new Node(230);


        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;

        cout<<endl;
        cout<<"Your Complete BST is "<<endl;
        levelOrderTraversal(root);
        cout<<endl<<endl;

        cout<<"Your Heap is "<<endl;


        vector<int> nums;
        //first we find inorder
        inorder(root,nums);

        int i=0;
        postorder(root,nums,i);

        levelOrderTraversal(root);






}