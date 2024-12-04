#include<iostream>
#include<vector>
using namespace std;

// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

 

// Example 1:


// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]



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
    Node* partition(Node* &head, int x) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        Node* temp = head;
        vector<int> less;
        vector<int> equal;
        while(temp != NULL) {
            if(temp->data >= x) {
                equal.push_back(temp->data);
            }
            else {
                less.push_back(temp->data);
            }
            temp = temp->next;
        }

        Node* dummy = new Node(-1);
        temp = dummy;
        for(auto val: less) {
            Node* newNode = new Node(val);
            temp->next = newNode;
            temp = newNode;
        }
        Node* dummy2 = new Node(-1);
        temp->next = dummy2->next;
        for(auto val: equal) {
            Node* newNode = new Node(val);
            temp->next = newNode;
            temp = newNode;
        }

        return dummy->next;
    }
int main() {

    Node* a = new Node(10);
    Node* b = new Node(40);
    Node* c = new Node(30);
    Node* d = new Node(20);
    Node* e = new Node(50);
    Node* f = new Node(20);


    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;



    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After Partitioning LL"<<endl<<endl;
    int x = 30;

    Node* newHead = partition(a,x);


    print(newHead);



}