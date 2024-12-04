#include<iostream>
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

void insertAtTail(Node* &head,Node* &tail,int data) {

    //step 0 check for Null
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //step 1 creat a node
    Node* newNode = new Node(data);
    //step 2 point to tail
    tail->next = newNode;
    //step 3 change tail 
    tail = newNode;
       

}
void insertAtHead(Node* &head,Node* &tail,int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //step 1    creat a node
    Node* newNode = new Node(data);
    //step 2    points to head
    newNode->next = head;
    //step 3    change head
    head = newNode;
    
}

int main() {

    Node* head = new Node(10);
    Node* tail = new Node(10);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,80);
    insertAtHead(head,tail,90);



    cout<<endl<<"Printing elements of LL"<<endl;

    print(head);//70 60 50 40 30 20 10


    // when head is already Null

    Node* head2 = NULL;
    Node* tail2 = NULL;
    insertAtHead(head2,tail2,40);
    insertAtHead(head2,tail2,30);
    insertAtHead(head2,tail2,50);
    insertAtHead(head2,tail2,60);
    insertAtHead(head2,tail2,70);
    insertAtHead(head2,tail2,80);
    insertAtHead(head2,tail2,90);
    insertAtTail(head2,tail2,33);
    
    
    
    cout<<endl;
 

    cout<<"Printing elements of LL"<<endl;

    print(head2); //70 60 50 40 30 33 
}