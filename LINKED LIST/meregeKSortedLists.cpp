#include<iostream>
#include<vector>
using namespace std;

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []




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
            cout<<"|"<<temp->data<<"| -> ";
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



	Node* mergeTwoLists(Node* l1, Node* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> data <= l2 -> data)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}


    Node* mergeKLists(vector<Node*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }

        Node* temp = lists[0];

        for(int i=1; i<lists.size(); i++) {
            Node* curr = lists[i];
						if(curr != NULL){
							temp = mergeTwoLists(temp,curr);
						}
            	
        }
        return temp;
    }

int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(8);

    Node* i = new Node(90);
    Node* j = new Node(100);
    Node* k = new Node(110);
    Node* l = new Node(120);
    

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;


    e->next = f;
    f->next = g;
    g->next = h;
    h->next = NULL;

    i->next = j;
    j->next = k;
    k->next = l;

    vector<Node*> arr = {a,e,i};

    cout<<endl<<"Original LL"<<endl;

    for(auto var: arr){
        print(var);
        cout<<endl;
    }

    cout<<endl<<endl<<"After Merging K LL"<<endl<<endl;

    Node* newHead = mergeKLists(arr);

    print(newHead);


}