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
  



    Node* megreNodes(Node* head) {
        if(head==NULL) {
            return head;
        }

        Node* currNode = head;
        Node* nextNode = head->next;
        Node* newLastNode = NULL;
        int sum = 0;
        while(nextNode != NULL) {
            if(nextNode->data != 0) {
                sum += nextNode->data;
            }
            else {
                currNode->data = sum;
                newLastNode = currNode;
                currNode = currNode->next;
                sum = 0;
            }
            nextNode = nextNode->next;
        }

        newLastNode->next = NULL;
        return head;
    }


int main() {

    Node* a = new Node(0);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(0);
    Node* e = new Node(50);
    Node* f = new Node(0);
    Node* g = new Node(70);
    Node* h = new Node(80);
    Node* i = new Node(0);
    Node* j = new Node(100);
    Node* k = new Node(110);
    Node* l = new Node(0);
    

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



    cout<<"Printing elements of LL"<<endl<<endl;

    print(a);

    Node* ans = megreNodes(a);
    cout<<endl<<endl;
    cout<<"After merging Nodes between zeros "<<endl<<endl;
    print(ans);


}