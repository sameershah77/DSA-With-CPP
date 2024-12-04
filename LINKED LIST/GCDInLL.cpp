#include<iostream>
using namespace std;


// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]


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

    int gcd(int A, int B) { 
	  
	    if(A==0) {
	        return B;
	    }
	    if(B==0) {
	        return A;
	    }
	    
	    while(A>0 && B>0) {
	        if(A>B) {
	            A=A-B;
	        }
	        else if(B>=A) {
	            B=B-A;
	        }
	        
	    }
	    if(A==0) {
	        return B;
	    }
	    return A;
	      
	}

    Node* insertGreatestCommonDivisors(Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        Node* prevNode = head;
        Node* nextNode = head->next;

        while(nextNode != NULL) {
            int ans = gcd(prevNode->data,nextNode->data);
            Node* newNode = new Node(ans);
            prevNode->next = newNode;
            newNode->next = nextNode;

            prevNode = prevNode->next->next;
            nextNode = nextNode->next;
        }

        return head;
    }
int main() {

    Node* a = new Node(18);
    Node* b = new Node(6);
    Node* c = new Node(10);
    Node* d = new Node(3);
       

    a->next = b;
    b->next = c;
    c->next = d;




    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After adding GCD in LL"<<endl<<endl;

    Node* newHead = insertGreatestCommonDivisors(a);


    print(newHead);



}