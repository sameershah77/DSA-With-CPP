#include<iostream>
using namespace std;
//TC = O(n) SC = O(i)
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


Node* reverse(Node* &head) {
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

bool isPalindrome(Node* &head) {
    if(head==NULL) {
        return false;
    }
    if(head->next==NULL) {
        return true;
    }

    //step 1: find middle of LL
    Node* middleNode = findMiddleNode(head);

    //step 2: reverse karo middle ke aage wale nodes

    Node* reverseLLKaHead = reverse(middleNode->next);


    


    Node* temp1 = head;
    Node* temp2 = reverseLLKaHead;

    while(temp2 != NULL) {
        if(temp1->data != temp2->data) {
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }

    }
    return true;
}





int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* x = new Node(30);
    Node* fourth = new Node(20);
    Node* fifth = new Node(10);

    first->next = second;
    second->next = third;
    third->next = x;
    x->next = fourth;
    fourth->next=fifth;

    cout<<"Printing elements of LL"<<endl;

    print(first);

    cout<<endl<<endl;

    if(isPalindrome(first)) {
        cout<<"LL is a palindrome"<<endl;
    }
    else {
        cout<<"LL is not a palindrome"<<endl;
    }



}