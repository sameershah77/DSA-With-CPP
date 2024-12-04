#include<iostream>
using namespace std;


// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
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
  
    Node* reverse(Node* head) {
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
    Node* findMiddleNode(Node* head) {

        //LL have more than 1 node

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
                
            }
            
        }
        return slow;

    }

    void reorderList(Node* head) {
        if(head == NULL || head->next == NULL) {
            return;
        }

        Node* middleNode = findMiddleNode(head);

        Node* second = reverse(middleNode->next);
        middleNode->next = NULL;
        Node* first = head;

        while(second != NULL && first != NULL) {
            Node* temp1 = first->next;
            Node* temp2 = second->next;
            first->next = second;
            second->next =  temp1;
            first = temp1;
            second = temp2;
        }
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

    cout<<endl<<endl<<endl<<"Code after reordering"<<endl<<endl;

    reorderList(a);

    print(a);
    cout<<endl;

}