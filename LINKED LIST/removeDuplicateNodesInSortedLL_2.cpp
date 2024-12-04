#include<iostream>
using namespace std;

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]

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

    Node* deleteDuplicates(Node* head) {
        Node* dummy = new Node(0);
        dummy->next = head;

        Node* prev = dummy;

        while(head != NULL) {
            if(head->next != NULL && head->data == head->next->data) {
                while(head->next != NULL && head->data == head->next->data) {
                    head = head->next;
                }
                prev->next = head->next;
                head=head->next;
            }
            else {
                prev=prev->next;
                head=head->next;
            }
        }
        return dummy->next;
    }

int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(20);
    Node* d = new Node(20);
    Node* e = new Node(50);
    Node* f = new Node(50);
    Node* g = new Node(50);
    Node* h = new Node(80);
    Node* i = new Node(80);
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

    cout<<endl<<endl<<endl<<"Code after removing duplicates in LL"<<endl<<endl;

    Node* newNode = deleteDuplicates(a);
    cout<<endl;
    print(newNode);
    cout<<endl<<endl;

}