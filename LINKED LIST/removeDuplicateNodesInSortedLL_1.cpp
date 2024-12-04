#include<iostream>
using namespace std;

//TC = O(n) SC = O(1)
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
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


Node* removeDuplicates(Node* head) {
    Node* currNode = head;

    while(currNode != NULL) {
        if((currNode->next != NULL) && (currNode->data == currNode->next->data)) {
            currNode->next=currNode->next->next;
        }
        else {
            currNode=currNode->next;    
        }
    }
    return head;
}


int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(20);
    Node* d = new Node(20);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);
    Node* h = new Node(70);
    Node* i = new Node(90);
    Node* j = new Node(90);
    Node* k = new Node(90);
    Node* l = new Node(120);
    

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

    cout<<endl<<endl<<"After removing duplicates in LL"<<endl;

    a = removeDuplicates(a);
    print(a);

}