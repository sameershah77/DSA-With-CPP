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


    int getLength(Node* &head) {
        Node* temp = head;

        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    Node* removeZeroSumSublists(Node* head) {

        if(head == NULL) {
            return head;
        }

        Node* temp = new Node(-1);

        temp->next = head;

        Node* i  = temp;

        Node* j = i->next;
        while( i!= NULL) {
            int sum = 0;
            j  = i->next;
            while(j!= NULL) {
                sum += j->data;
                if(sum == 0) {
                    i->next = j->next;
                }
                j = j->next;
            }
            i = i->next;
        }
        return temp->next;

    }
int main() {

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(-3);
    Node* d = new Node(3);
    Node* e = new Node(5);

    

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;



    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After removing consicative nodes wich makes zero in LL"<<endl<<endl;

    Node* newHead = removeZeroSumSublists(a);


    print(newHead);

}