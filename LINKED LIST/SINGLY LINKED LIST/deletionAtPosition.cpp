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
    ~Node() {
        cout<<"Node with value "<<this->data<<" deleted succesfully "<<endl;
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

void deleteAtPosition(Node* &head,Node * &tail, int position) {
    if(head==NULL) {
        cout<<"Cannot delete , Linked List is empty"<<endl;
    }
    //deletion at head
    if(position==1) {
        Node* temp = head;
        head=head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    //deletion at tail
    int len = findLength(head);
    if(position>=len) {
        Node* prev = head;
        int i=1;
        while(i<len-1) {
            prev=prev->next;
            i++;
        }
        Node* temp = tail;
        prev->next = NULL;
        tail=prev;
        delete temp;
        return;
    }

    //deletion at random position
    int i=1;
    Node* prev = head;

    while(i<position-1) {
        prev=prev->next;
        i++;
    }
    Node* temp = prev->next;
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;

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
    cout<<endl<<endl;
    cout<<"Original Linked List"<<endl;
    print(head);
    cout<<endl;


    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"Length is "<<findLength(head)<<endl;
    cout<<endl;

    int position = 1;
    cout<<"Deletion at head "<<position<<endl<<endl;
    deleteAtPosition(head,tail,position);
    print(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"Length is "<<findLength(head)<<endl;
    cout<<endl;

    position=16;
    cout<<"Deletion at tail "<<position<<endl<<endl;
    deleteAtPosition(head,tail,position);
    print(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"Length is "<<findLength(head)<<endl;
    cout<<endl;

    position=7;
    cout<<"Deletion at "<<position<<endl<<endl;
    deleteAtPosition(head,tail,position);
    print(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"Length is "<<findLength(head)<<endl;


}