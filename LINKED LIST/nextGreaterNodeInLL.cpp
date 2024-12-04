#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// You are given the head of a linked list with n nodes.

// For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

// Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

// Example 1:


// Input: head = [2,1,5]
// Output: [5,5,0]
// Example 2:


// Input: head = [2,7,4,3,5]
// Output: [7,0,5,5,0]

class Node{
    public:

    int data;
    Node *next;
    int value;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;

    }



};

    void print(Node* head) {
        Node *temp = head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void nextGreaterElement(vector<int> &arr,vector<int> &ans){
        stack<int> s;
        s.push(0);
        for(int i = arr.size()-1; i>=0; i--){
            int curr = arr[i];
            while(s.top()<=curr && s.top() != 0){
                s.pop();
            }
            // ans store karana h
            ans[i] = s.top();

            // stack mein push kara doonga
            s.push(curr);
        }
        
    }
    
    vector<int> nextLargerNodes(Node* head) {
        vector<int> arr;
        while(head != NULL) {
            arr.push_back(head->data);
            head=head->next;
        }
        vector<int> ans(arr.size());
        nextGreaterElement(arr,ans);
        
        return ans;
    }


int main() {

    Node* a = new Node(2);
    Node* b = new Node(7);
    Node* c = new Node(4);
    Node* d = new Node(3);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);


    

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;





    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"Next greater elements are "<<endl<<endl;

    vector<int> arr = nextLargerNodes(a);

    for(auto val: arr) {
        cout<<val<<" ";
    }
    cout<<endl;



}