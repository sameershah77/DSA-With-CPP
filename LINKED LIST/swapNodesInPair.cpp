#include<iostream>
using namespace std;



// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]
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
  
int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        temp=temp->next;
        len++;
    }
    return len;
}
    //using array
    // Node* swapPairs(Node* head) {


    //  vector<int> arr;
    //     while(head != NULL) {
    //         arr.push_back(head->val);
    //         head=head->next;
    //     }
    // for(int i=0; i<arr.size(); i=i+2) {
    //     if(i+1<arr.size()) {
    //         swap(arr[i],arr[i+1]);
    //     }
    // }

    // Node* temp = new Node(-1);
    // Node* x = temp;
    // for(int i=0; i<arr.size(); i++) {
    //     Node* newNode = new Node(arr[i]);
    //     temp->next = newNode;
    //     temp=temp->next;

    // }
    // return x->next;
    // }

    Node* swapPairs(Node* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        Node* dummyNode = new Node();

        Node* prevNode = dummyNode;
        Node* currNode = head;

        while(currNode != NULL && currNode->next != NULL) {
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        return dummyNode->next;


    }



int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);
    Node* h = new Node(80);
    Node* i = new Node(90);
    Node* j = new Node(100);
    Node* k = new Node(110);
    Node* l = new Node(120);
    

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;
    i->next = j;
    j->next = k;
    k->next = l;



    cout<<"Printing elements of LL"<<endl;

    print(a);

    cout<<endl<<endl<<endl<<"Code after swapping of Linked List in K Gourps"<<endl<<endl;


    Node* newNode = swapPairs(a);
    cout<<endl;
    print(newNode);
    cout<<endl<<endl;

}