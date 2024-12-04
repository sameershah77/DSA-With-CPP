#include<iostream>
using namespace std;
// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
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





    // this function used Tortoise or Slow fast or two pointer approach
Node* findMiddleNode(Node* &head) {

    
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return head;
    }
    if(head->next==NULL) {
        return head;
    }

    //LL have more than 1 node

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        
    }
    return slow;

}
int findLength(Node* &head,int len){
    Node* temp = head;

    while(temp!=NULL) {
        len++;
        temp=temp->next;
    }
    return len;
}

int main() {

    Node* head = new Node(10);
    Node* tail = NULL;
    insertAtHead(head,tail,20); 
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,80);
    insertAtHead(head,tail,90);
    insertAtHead(head,tail,100);



    cout<<endl<<"Printing elements of LL"<<endl;

    print(head);

    cout<<endl<<endl<<endl<<"Code to find middle node"<<endl<<endl;


    cout<<"Tortoise or slow fast algorithm"<<endl;
    Node* ans = findMiddleNode(head);

    cout<<"Middle Node is "<<ans->data<<endl;

    cout<<endl<<endl;
    cout<<"Using length"<<endl<<endl;
    //using this the middle node in odd length is length/2+1 

    int length = findLength(head,0);
    int i=1;
    Node* temp = head;


    while(i != length/2 + 1) {
        i++;
        temp=temp->next;
    }
    cout<<"Middle Node is "<<temp->data<<endl;
    
}