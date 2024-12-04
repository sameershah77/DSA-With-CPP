#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
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
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;

}

void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head==NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int findLength(Node* &head) {
    Node* temp = head;
    int len=0;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(Node* &head,Node * &tail, int position,int data) {
    if(head==NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // insertion at start i.e head
    if(position == 0) {
        insertAtHead(head,tail,data);
        return;
    }
    // insert at end i.e tail
    int len = findLength(head);
    if(position >= len) {
        insertAtTail(head,tail,data);
        return;
    }



    // step 1 : Find position : prev Node and curr Node to insert new node
    int i=1;
    Node* prev = head;
    while(i < position) {
        prev=prev->next;
        i++;
    }
    Node* curr = prev->next;

    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
    
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;


    //Insertion at head
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,80);


    //Insertion at tail
    insertAtTail(head,tail,-10);
    insertAtTail(head,tail,-20);
    insertAtTail(head,tail,-30);
    insertAtTail(head,tail,-40);
    insertAtTail(head,tail,-50);
    insertAtTail(head,tail,-60);
    insertAtTail(head,tail,-70);
    insertAtTail(head,tail,-80);


    cout<<"Original Linked List"<<endl;
    print(head);//now length is 16
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"length is "<<findLength(head)<<endl;
    cout<<endl<<endl;

    cout<<"Insertion at random position"<<endl;
    int data = 5;
    int position = 8;
    cout<<"Inserting "<<data<<" at "<<position<<endl;
    insertAtPosition(head,tail,position,data);
    print(head);//now length is 17
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"length is "<<findLength(head)<<endl;
    cout<<endl<<endl;


    cout<<"Insertion at start (0 position)"<<endl;
    data = 5;
    position = 0;
    cout<<"Inserting "<<data<<" at "<<position<<endl;
    insertAtPosition(head,tail,position,data);
    print(head);//now length is 18
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"length is "<<findLength(head)<<endl;
    cout<<endl<<endl;


    cout<<"Insertion at end (last position)"<<endl;
    data = 5;
    position = 23;// if position is greater or equal to size of LL, it insert in last only
    cout<<"Inserting "<<data<<" at "<<position<<endl;
    insertAtPosition(head,tail,position,data);
    print(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"length is "<<findLength(head)<<endl;
    cout<<endl<<endl;
}