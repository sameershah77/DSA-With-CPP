#include<iostream>
#include<unordered_map>
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
//this is main code
bool checkForLoop(Node* &head) {
    if(head == NULL) {
        return false;
    }
    if(head->next == NULL) {
        return false;
    }
    Node* temp = head;

    unordered_map<Node*, bool> freq;
    while(temp != NULL) {
        if(freq.find(temp) != freq.end()) {
            freq[temp] = true;
        }
        else {
            return true;
        }
        temp = temp->next;
    }
    return false;
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
    l->next = h;//it is loop in h to l


    if(checkForLoop(a)) {
        cout<<"Loop is present in given LL"<<endl;
    }
    else {
        cout<<"Loop is not present in given LL"<<endl;
    }

}