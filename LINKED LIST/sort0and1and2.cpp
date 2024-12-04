#include<iostream>
using namespace std;
//TC = O(n) SC = O(1)
class Node{
    public:

    int data;
    Node* next;


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



// this function use counting method in which we replace data of LL with new value
void sortZeroOneTwo1(Node* &head) {
    int zero = 0;
    int one = 0;
    int two = 0;
    Node* temp = head;

    while(temp != NULL) {

        if(temp->data==0) zero++;
        if(temp->data==1) one++;
        if(temp->data==2) two++;
        temp=temp->next;
    }
    
    temp=head;

        while(zero--) {
            temp->data = 0;
            temp = temp->next;
        }
        while(one--) {
            temp->data = 1;
            temp = temp->next;
        }
        while(two--) {
            temp->data = 2;
            temp = temp->next;
        }
   
}




// this function gives optimised solution and it done without replacing the data of original LL
Node* sortZeroOneTwo2(Node* &head) {
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    if(head->next==NULL) {
        return head;
    }

     
    //create dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //travers the original linked list and make three diff LL for zero one and two

    Node* curr = head;

    while(curr != NULL) {
        if(curr->data==0) {
            // take out zero wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            

            //appendthe xzro node in zeroHead wali LL
            zeroTail->next = temp;
            zeroTail = temp;
            
        }
        else if(curr->data==1) {
            // take out one wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            

            //appendthe one node in oneHead wali LL
            oneTail->next = temp;
            oneTail = temp;
            
        }else if(curr->data==2) {
            // take out two wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            

            //appendthe two node in twoHead wali LL
            twoTail->next = temp;
            twoTail = temp;
            
        }
    }


    //modify one wali LL: delete dummy node of one wali LL
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;



    //modify two wali LL: delete dummy node of two wali LL
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;



    //joining LL

    if(oneHead != NULL) {
        //one wali LL is non empty
        zeroTail->next = oneHead;
        if(twoHead != NULL) {
            oneTail->next = twoHead;
        }
    }
    else {
        //one wali LL is empty
        if(twoHead != NULL) {
            zeroTail->next = twoHead;
        }
    }


    //Now modify zero wali LL: delete dummy node of zero wali LL

    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;
    

    return zeroHead;
}


int main() {

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(0);
    Node* d = new Node(0);
    Node* e = new Node(2);
    Node* f = new Node(2);
    Node* g = new Node(1);
    Node* h = new Node(0);
    Node* i = new Node(2);
    Node* j = new Node(1);
    Node* k = new Node(1);
    Node* l = new Node(0);
    

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
    l->next = NULL;



    cout<<endl<<"Original Linked List"<<endl;

    print(a);

    cout<<endl<<endl<<endl<<"After sorting using counting method "<<endl<<endl;

    Node* temp = sortZeroOneTwo2(a);

    print(temp);

}