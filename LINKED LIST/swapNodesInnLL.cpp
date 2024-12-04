#include<iostream>
#include<algorithm>
using namespace std;
// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]

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
    Node* swapNodes(Node* head, int k) {
        int startK = k;
        int endK = getLength(head)-k+1;

        Node* right  = head;
        Node* left = head;
        int i=1;
        while(i<startK) {
            right = right->next;
            i++;
        }
        i=1;
        while(i<endK) {
            left = left->next;
            i++;
        }
        swap(right->data,left->data);
        return head;
    }
int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);

    
    Node* h = new Node(80);
    Node* i = new Node(90);
    Node* j = new Node(100);
    Node* k = new Node(110);

    

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




    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After merging LL"<<endl<<endl;

    Node* newHead = swapNodes(a,3);


    print(newHead);



}