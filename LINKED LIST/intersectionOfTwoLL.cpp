#include<iostream>
#include<climits>
#include<vector>
using namespace std;


class Node{
    public:

    int data;
    Node *next;


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


    Node* getIntersectionNode(Node* &headA, Node* &headB) {
        Node* a = headA;
        Node* b = headB;


        while(a->next != NULL && b->next != NULL) {
            if(a == b) {
                return a;
            }

            a = a->next;
            b = b->next;
        }

        if(a->next == NULL) {
            //B is greater or equal
            //we need to find out how much bigger it is 
            int bLen = 0;
            while(b->next != NULL) {
                bLen++;
                b = b->next;
            }

            while(bLen--) {
                headB = headB->next;
            }
        } 
        else {
            //A is greater or equal
            //we need to find out how much bigger it is 
            int aLen = 0;
            while(a->next != NULL) {
                aLen++;
                a = a->next;
            }

            while(aLen--) {
                headA = headA->next;
            }
        }

        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
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






    Node* A = new Node(1);
    Node* B = new Node(2);
    Node* C = new Node(3);
    Node* D = new Node(4);
    Node* E = new Node(3);
    Node* F = new Node(6);

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;
    F->next = d;



    cout<<"LL 1"<<endl;

    print(a);

    cout<<endl<<endl;
    cout<<"LL 2"<<endl;
    print(A);

    cout<<endl<<endl;

    Node* ans = getIntersectionNode(A,a);

    cout<<"LL1 and LL2 Intersect at "<<ans->data<<endl<<endl;
}
