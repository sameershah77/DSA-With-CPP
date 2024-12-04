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
    Node* findMiddleNode(Node* &head) {

        if(head==NULL) {
            cout<<"LL is empty"<<endl;
            return head;
        }
        if(head->next==NULL) {
            return head;
        }
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
    Node* deleteMiddle(Node* head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        Node* temp = head;
        Node* middle = findMiddleNode(temp);
        temp = head;
        while(temp->next != middle) {
            temp = temp->next;
        }
        temp->next = NULL;
        temp->next = middle->next;
        
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



    cout<<endl<<endl<<endl<<"After deletion of middle node "<<endl<<endl;

    Node* ans = deleteMiddle(a);


    print(ans);

}

