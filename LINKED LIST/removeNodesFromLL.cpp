#include<iostream>
using namespace std;


// You are given the head of a linked list.

// Remove every node which has a node with a strictly greater value anywhere to the right side of it.

// Return the head of the modified linked list.

 

// Example 1:


// Input: head = [5,2,13,3,8]
// Output: [13,8]
// Explanation: The nodes that should be removed are 5, 2 and 3.
// - Node 13 is to the right of node 5.
// - Node 13 is to the right of node 2.
// - Node 8 is to the right of node 3.
// Example 2:

// Input: head = [1,1,1,1]
// Output: [1,1,1,1]
// Explanation: Every node has value 1, so no nodes are removed.


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


    int getLength(Node* &head) {
        Node* temp = head;

        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    Node* reverse(Node* &head) {
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        
    }
    // Node* removeNodes(Node* head) {
    //     Node* temp = head;
    //     temp = reverse(temp);
    //     vector<int> ans;
    //     int n = INT_MIN;
    //     while(temp != NULL) {
    //         if(temp->data >= n) {
    //             ans.push_back(temp->val);
    //             n=temp->val;
    //         }
    //         temp=temp->next;
    //     }

    //     Node* dummy = new Node(-1);
    //     Node* curr = dummy;
    //     for(int i=0; i<ans.size(); i++) {
    //         Node* newNode = new Node(ans[i]);
    //         curr->next = newNode;
    //         curr = newNode;
    //     }
    //     return reverse(dummy->next);
    // }



    Node* removeNodes(Node* head) {
        head=reverse(head);
        Node* temp=head;
        while(temp!=NULL and temp->next!=NULL){
            if(temp->data>temp->next->data){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return reverse(head);
   }
int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(140);
    Node* d = new Node(40);
    Node* e = new Node(70);
    Node* f = new Node(60);
    Node* g = new Node(70);
    Node* h = new Node(80);
    Node* i = new Node(90);
    Node* j = new Node(10);
    Node* k = new Node(80);
    Node* l = new Node(10);
    

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;
    i->next = j;
    j->next = k;
    k->next = l;



    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After removing LL"<<endl<<endl;


    Node* newHead = removeNodes(a);


    print(newHead);

    cout<<endl<<endl;


}