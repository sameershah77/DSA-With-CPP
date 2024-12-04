#include<iostream>
using namespace std;


// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

 

// Example 1:


// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:


// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:



// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

class Node{
    public:

    int data;
    Node *next;
    Node* random;
    int value;

    Node() {
        this->data = 0;
        this->next = NULL;
        this->random = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;

    }



};

    void print(Node* head) {
        Node *temp = head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }

        //step 1: clone A -->A'
        Node* it = head; // iterator over old head

        while(it != NULL) {
            Node* cloneNode = new Node(it->data);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = it->next->next;
        }

        //step 2: assign randoms in clone
        it = head;

        while(it != NULL) {
            Node* cloneNode = it->next;
            cloneNode->random = it->random ?it->random->next:NULL;
            it = it->next->next;
        }


        //step 3: detach A' from A

        it = head;
        Node* cloneHead = it->next;
        while(it != NULL) {
            Node* cloneNode = it->next;
            it->next = it->next->next;
            if(cloneNode->next != NULL) {
                cloneNode->next = cloneNode->next->next;
            }
            it = it->next;
        }

        return cloneHead;


    }

int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);


    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;


    a->random = NULL;
    b->random = a;
    c->random = e;
    d->random = c;
    e->random = a;

    cout<<endl<<"Original LL"<<endl;

    print(a);
    cout<<endl;
    cout<<"Clone LL"<<endl;
    Node* cloneHead = copyRandomList(a);
    print(cloneHead);



}