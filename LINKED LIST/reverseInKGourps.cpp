#include<iostream>
using namespace std;
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
  
int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        temp=temp->next;
        len++;
    }
    return len;
}

Node* reverseInKGroups(Node* &head,int k) {
    if(head==NULL) {
        return head;
    }
    int len = getLength(head);
    if(k > len) {
        return head;
    }
    // step 1: reverse first k nodes in LL
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = currNode->next;

    int count = 0;
    while(count<k) {
        nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
        
        count++;
    }
    // step 2 : remaining ko recurssion sambhal lega
    if(nextNode != NULL) {
        head->next = reverseInKGroups(nextNode,k);
    }
    //step 3 : modified LL ka head prevNode ban jayega
    return prevNode;
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



    cout<<"Printing elements of LL"<<endl;

    print(a);

    cout<<endl<<endl<<endl<<"Code for reverse of Linked List in K Gourps"<<endl<<endl;

    a = reverseInKGroups(a,3);

    print(a);

}