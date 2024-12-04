#include<iostream>
using namespace std;

// Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

// Implement the Solution class:

// Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
// int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
 

// Example 1:


// Input
// ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
// [[[1, 2, 3]], [], [], [], [], []]
// Output
// [null, 1, 3, 2, 2, 3]

// Explanation
// Solution solution = new Solution([1, 2, 3]);
// solution.getRandom(); // return 1
// solution.getRandom(); // return 3
// solution.getRandom(); // return 2
// solution.getRandom(); // return 2
// solution.getRandom(); // return 3
// // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.


 
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
 
class Solution {
    int len = 0;
    Node* head;
public:
    Solution(Node* head) {
        this->head = head;
        Node* temp = head;

        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

    }
    
    int getRandom() {
        int randIndex = rand()%len; // this is important function
        Node* temp = head;
        for(int i=0; i<randIndex; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
};

 
int main() {


    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Solution* x = new Solution(first);

    cout<<"1st random value is "<<x->getRandom()<<endl;
    cout<<"2nd random value is "<<x->getRandom()<<endl;
    cout<<"3rd random value is "<<x->getRandom()<<endl;
    cout<<"4th random value is "<<x->getRandom()<<endl;
    cout<<"5th random value is "<<x->getRandom()<<endl;


}