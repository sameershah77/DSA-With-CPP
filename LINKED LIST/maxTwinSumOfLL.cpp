#include<iostream>
#include<limits.h>
using namespace std;

// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

// Example 1:


// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
// There are no other nodes with twins in the linked list.
// Thus, the maximum twin sum of the linked list is 6. 
// Example 2:


// Input: head = [4,2,2,3]
// Output: 7
// Explanation:
// The nodes with twins present in this linked list are:
// - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
// - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
// Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
// Example 3:


// Input: head = [1,100000]
// Output: 100001
// Explanation:
// There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.


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

    Node* findMiddle(Node* head) {

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
    int pairSum(Node* head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        Node* middle = findMiddle(head);
        middle->next = reverse(middle->next);

        middle = middle->next;
        int maxSum = INT_MIN;

        while(middle != NULL) {
            int sum = head->data + middle->data;
            if(sum > maxSum) {
                maxSum = sum;
            }
            head = head->next;
            middle = middle->next;
        }
        return maxSum;
    }
int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);

    
    Node* h = new Node(70);
    Node* i = new Node(60);
    Node* j = new Node(20);
    Node* k = new Node(10);

    

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




    cout<<endl<<"Original LL"<<endl;

    print(a);

    cout<<endl<<endl<<"After LL"<<endl<<endl;

    int n = pairSum(a);

    cout<<"MAximum twin sum is "<<n<<endl; 

}