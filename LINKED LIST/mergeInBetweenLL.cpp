#include<iostream>
using namespace std;


// You are given two linked lists: list1 and list2 of sizes n and m respectively.

// Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

// The blue edges and nodes in the following figure indicate the result:


// Build the result list and return its head.

 

// Example 1:


// Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
// Output: [0,1,2,1000000,1000001,1000002,5]
// Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
// Example 2:


// Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
// Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
// Explanation: The blue edges and nodes in the above figure indicate the result.

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
    Node* mergeInBetween(Node* list1, int a, int b, Node* list2) {

        Node* dummy1 = new Node(-1);
        dummy1->next = list1;

        int i=0;
        Node* temp1 = list1;
        Node* temp2 = list1;
        while(i<a) {
            dummy1 = temp1;
            temp1 = temp1->next;
            i++;
        }
        i=0;
        while(i<b) {
            temp2 = temp2->next;
            i++;
        }

        dummy1->next = list2;
        Node* x = list2;

        while(x->next != NULL) {
            x=x->next;
        }

        x->next = temp2->next;
    return list1;
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
    g->next = NULL;


    h->next = i;
    i->next = j;
    j->next = k;




    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After merging LL"<<endl<<endl;
    int x = 2;
    int y = 5;
    Node* newHead = mergeInBetween(a,x,y,h);


    print(newHead);



}