#include<iostream>
using namespace std;

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]
// Example 2:


// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]


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

    Node* oddEvenList(Node* &head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        int count = 1;
        Node* temp = head;

        Node* oddHead = NULL;
        Node* oddTail = NULL;
        Node* evenHead = NULL;
        Node* evenTail = NULL;

        while(temp != NULL) {
            if(count%2 == 0) {
                //for even
                if(evenHead == NULL) {
                    evenHead = temp;
                    evenTail = temp;
                    
                    temp=temp->next;
                }
                else {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                    temp = temp->next;
                }
            }
            else {
                //for odd
                if(oddHead == NULL) {
                    oddHead = temp;
                    oddTail = temp;
                    
                    temp=temp->next;
                }
                else {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                    temp = temp->next;
                }
            }
            count++;
        }


        evenTail->next = NULL;
        oddTail->next = evenHead;
        return oddHead;
    }




int main() {

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;




    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After Changes LL"<<endl<<endl;
    Node* newHead = oddEvenList(a);
    print(newHead);



}