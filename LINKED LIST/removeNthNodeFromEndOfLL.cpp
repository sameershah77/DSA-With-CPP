#include<iostream>
using namespace std;
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:
// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
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
  
    Node* removeNthFromEnd(Node* &head, int n) {
        int count = 0;
        // corner case 
        if(head == NULL || head->next == NULL)
            return NULL;
        Node *temp = head;

        // count the number of nodes 
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int i = 1;
        count = count-n;  // need to traverse till this node 
        temp = head;
        while(i < count ){
            i++;
            temp = temp->next;
        }

        if(count == 0){
            head = head->next;
            return head;
        }
        temp->next = temp->next->next;
        return temp->next;

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
    Node* x = removeNthFromEnd(a,2);
    cout<<endl;
    cout<<"Deleted element is "<<x->data<<endl;
    print(a);


}
    

    