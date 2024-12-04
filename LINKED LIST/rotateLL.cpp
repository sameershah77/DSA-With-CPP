#include<iostream>
using namespace std;


// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]


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

    Node* rotateRight(Node* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return head;
        }
        int len = getLength(head);
        int newK = k%len;

        if(newK == 0) {
            return head;
        }
        int newPrevNodePosition = len - newK - 1;
        Node* newPrevNode = head;
        int i= 0;
        while(i < newPrevNodePosition) {
            newPrevNode = newPrevNode->next;
            i++;
        }
        Node* newHead = newPrevNode->next;


        newPrevNode->next = NULL;

        Node* it = newHead;
        while(it->next != NULL) {
            it = it->next;
        }

        it->next = head;
        return newHead;
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

    Node* newHead = rotateRight(a,3);


    print(newHead);



}