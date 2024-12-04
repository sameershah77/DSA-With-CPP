#include<iostream>
using namespace std;


// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

// Return the decimal value of the number in the linked list.

// The most significant bit is at the head of the linked list.

 

// Example 1:


// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10
// Example 2:

// Input: head = [0]
// Output: 0
 

// Constraints:
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

    int getDecimalValue(Node* head) {
        int sum = 0;
        while(head != NULL) {
            sum *= 2;
            sum += head->data;
            head=head->next;
        }
        return sum;
    }

int main() {

    Node* a = new Node(1);
    Node* b = new Node(0);
    Node* c = new Node(1);


    a->next = b;
    b->next = c;



    cout<<endl<<"Original LL"<<endl;

    print(a);
    cout<<endl<<endl;

    int ans = getDecimalValue(a);

    cout<<"answer is "<<ans<<endl;


}