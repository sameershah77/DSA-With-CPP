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

Node* reverseRecursion(Node* &prev, Node* &curr) {
    if(curr==NULL) {
        return prev;
    }

    // 1 case solve 
    Node* next = curr->next;
    curr->next = prev;
    reverseRecursion(curr,next);
}


Node* reverseLoop(Node* &head) {
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





int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Printing elements of LL"<<endl;

    print(first);

    cout<<endl<<endl<<endl<<"Code for reverse of Linked List"<<endl<<endl;
    cout<<"Using Recursion"<<endl;
    Node* prev = NULL;
    Node* curr = first;

    Node* newReverseLL1 = reverseRecursion(prev,curr);

    print(newReverseLL1);




    cout<<endl<<endl<<endl<<"Using Loop"<<endl;


    Node* newReverseLL2 = reverseLoop(newReverseLL1);

    print(newReverseLL2);
    cout<<endl<<endl<<endl;







}