#include<iostream>
using namespace std;

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

Node* removeLoop(Node* &head) {

    if(head==NULL) {
        return NULL;
    }


    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast=fast->next;
        if(fast != NULL) {
            fast=fast->next;
            slow=slow->next;
        }

        if(fast == slow) {
            slow=head;
            break;
        }
    }
    Node* prevNode = fast;

    while(slow != fast) {
        prevNode = fast;
        slow=slow->next;
        fast=fast->next;
    }
    prevNode->next = NULL;
    return slow;// we can return fast also becouse both areequal at this time
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
    h->next = i;//this will starting point at h=80
    i->next = j;
    j->next = k;
    k->next = l;
    l->next = h;//it is loop in h to l
    

    //there is loop between h to l after calling removeLoop function the loop wil remove and print a to l 
    a = removeLoop(a);
    print(a);


}