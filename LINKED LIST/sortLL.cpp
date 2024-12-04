#include<iostream>
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
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
  



	Node* merge(Node* l1, Node* l2) {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL) {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL) {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> data <= l2 -> data) {
			l1 -> next = merge(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else {
			l2 -> next = merge(l1, l2 -> next);
			return l2;            
		}
	}


    Node* findMiddleNode(Node* &head) {

        
        if(head==NULL) {
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
    Node* sortList(Node* &head) {
        if(head==NULL) {
            return head;
        }
        if(head->next==NULL) {
            return head;
        }

        Node* mid = findMiddleNode(head);
        Node* leftList = head;
        Node* rightList = mid->next;
        mid->next=NULL;

        leftList = sortList(leftList);
        rightList = sortList(rightList);

        Node* mergedLL = merge(leftList,rightList);
        return mergedLL;
    }




int main() {

    Node* a = new Node(10);
    Node* b = new Node(40);
    Node* c = new Node(30);
    Node* d = new Node(70);
    Node* e = new Node(10);
    Node* f = new Node(40);
    Node* g = new Node(20);
    Node* h = new Node(90);
    Node* i = new Node(90);
    Node* j = new Node(130);
    Node* k = new Node(15);
    Node* l = new Node(12);
    

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

    Node* x = sortList(a);
    cout<<endl<<endl<<"After sorting"<<endl;
    cout<<endl;
    print(x);
    cout<<endl<<endl;


}
    

    









