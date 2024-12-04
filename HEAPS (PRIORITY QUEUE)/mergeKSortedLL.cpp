#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
}


class compare{
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};
    Node* mergeKLists(vector<Node*>& lists) {
        int k = lists.size();
        if(k == 0) {
            return NULL;
        }

        priority_queue<Node*,vector<Node*>,compare> minHeap;
        for(int i=0; i<k; i++) {
            if(lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }
        Node* head = NULL;
        Node* tail = NULL;
        while(minHeap.empty() == false) {
            Node* temp = minHeap.top();
            minHeap.pop();

            if(head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }

            if(tail->next != NULL) {
                minHeap.push(tail->next);
            }
        }
        return head;
    }


int main() {

    //LL1
    Node* a1 = new Node(10);
    Node* b1 = new Node(30);
    Node* c1 = new Node(50);
    Node* d1 = new Node(70);
    Node* e1 = new Node(90);

    a1->next = b1;
    b1->next = c1;
    c1->next = d1;
    d1->next = e1;

    //LL2
    Node* a2 = new Node(10);
    Node* b2 = new Node(20);
    Node* c2 = new Node(40);
    Node* d2 = new Node(60);
    Node* e2 = new Node(80);

    a2->next = b2;
    b2->next = c2;
    c2->next = d2;
    d2->next = e2;


    //LL3
    Node* a3 = new Node(50);
    Node* b3 = new Node(70);
    Node* c3 = new Node(100);
    Node* d3 = new Node(130);
    Node* e3 = new Node(140);

    a3->next = b3;
    b3->next = c3;
    c3->next = d3;
    d3->next = e3;
    vector<Node*> list = {a1,a2,a3};
    Node* ans = mergeKLists(list);
    

    cout<<endl<<"Your k sorted LL are "<<endl<<endl;
    print(ans);



}