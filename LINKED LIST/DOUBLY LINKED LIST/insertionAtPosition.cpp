#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;
    Node() {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }


};

    void print(Node* &head) {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    int getLength(Node* &head) {
        Node* temp = head;
        int len=0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void insertAtHead(Node* &head,Node* &tail, int data) {
        if(head==NULL) {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }


        Node* newNode = new Node(data);
        head->prev = newNode;
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
        newNode->prev = tail;

        tail = newNode;
    }

    void insertAtPosition(Node* &head, Node* &tail, int data,int position) {
        if(head==NULL) {
            Node* newNode = new Node(data);
            head=newNode;
            tail=newNode;
            return;
        }

        if(position==1) {
            insertAtHead(head,tail,data);
            return;
        }

        int len = getLength(head);

        if(position > len) {
            insertAtTail(head,tail,data);
            return;
        }


        int i=1;
        Node* prevNode = head;
        while(i<position-1) {
            prevNode=prevNode->next;
            i++;
        }
        Node* currNode = prevNode->next;

        Node* newNode = new Node(data);

        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    first->prev = NULL;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = NULL;   

    Node* head = first;
    Node* tail = third;

    cout<<endl;
    print(head);
    cout<<"Length is "<<getLength(head);


    
    cout<<endl;
    insertAtHead(head,tail,101);

    print(head);
    cout<<"Length is "<<getLength(head);



    cout<<endl;
    insertAtTail(head,tail,501);

    print(head);
    cout<<"Length is "<<getLength(head);


    
    cout<<endl;
    insertAtPosition(head,tail,701,4);

    print(head);
    cout<<"Length is "<<getLength(head);

}