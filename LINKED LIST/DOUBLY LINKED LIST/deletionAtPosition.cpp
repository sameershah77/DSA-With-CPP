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

    void deletionAtPosition(Node* &head, Node* &tail, int position) {
        if(head==NULL) {
            cout<<"Linked List is empty , can't Delete"<<endl;
            return;
        }

        if(head->next==NULL) {
            Node* temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            return;
        }
    //deletion at head
        if(position == 1) {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            return;
        }


        int len = getLength(head);
        if(position > len) {
            cout<<"Please enter valid position"<<endl;
        }
        //deletion at tail
        if(position == len) {
            Node* temp = tail;
            tail=tail->prev;
            temp->prev = NULL;
            tail->next = NULL;
            delete temp;
            return;
        }


        // deletion at random

        //step 1: find prevNode , currNode , nextNode
        int i = 1;
        Node* prevNode = head;
        while(i<position-1) {
            prevNode = prevNode->next;
            i++;
        }

        Node* currNode = prevNode->next;
        Node* nexNode = currNode->next;

        //step 2:
        prevNode->next = nexNode;
        //step 3:
        nexNode->prev = prevNode;
        //step 4:
        currNode->next = NULL;
        //step 5:
        currNode->prev = NULL;
        
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




    cout<<endl<<endl<<endl<<"Code for deletion"<<endl<<endl;

    cout<<endl;
    int position = 1;
    cout<<"Deletion at head"<<endl;
    deletionAtPosition(head,tail,position);
    print(head);
    cout<<"Length is "<<getLength(head);

    cout<<endl;
    position = 5;
    cout<<"Deletion at tail"<<endl;
    deletionAtPosition(head,tail,position);
    print(head);
    cout<<"Length is "<<getLength(head);


    cout<<endl;
    position = 3;
    cout<<"Deletion at random"<<endl;
    deletionAtPosition(head,tail,position);
    print(head);
    cout<<"Length is "<<getLength(head);

}