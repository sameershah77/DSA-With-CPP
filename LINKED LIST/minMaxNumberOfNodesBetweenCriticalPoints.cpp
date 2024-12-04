#include<iostream>
#include<climits>
#include<vector>
using namespace std;


// A critical point in a linked list is defined as either a local maxima or a local minima.

// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

// Example 1:


// Input: head = [3,1]
// Output: [-1,-1]
// Explanation: There are no critical points in [3,1].


// Example 2:


// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
// Explanation: There are three critical points:
// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
// The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
// The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.


// Example 3:


// Input: head = [1,3,2,2,3,2,2,2,7]
// Output: [3,3]
// Explanation: There are two critical points:
// - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
// - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
// Both the minimum and maximum distances are between the second and the fifth node.
// Thus, minDistance and maxDistance is 5 - 2 = 3.
// Note that the last node is not considered a local maxima because it does not have a next node.

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


    vector<int> nodesBetweenCriticalPoints(Node* head) {

        vector<int> ans={-1,-1};

        Node* prevNode = head;

        if(prevNode == NULL) return ans;

        Node* currNode = head->next;

        if(currNode == NULL) return ans;

        Node* nextNode = head->next->next;

        if(nextNode == NULL) return ans;

        int firstCP = -1;
        int lastCP = -1;
        int minDistance = INT_MAX;
        int i = 1;
        while(nextNode != NULL){
            bool isCP=((currNode->data > prevNode->data && currNode->data > nextNode->data)||(currNode->data < prevNode->data&&currNode->data < nextNode->data))?true:false;
            if(isCP && firstCP==-1){
                firstCP = i;
                lastCP = i;
            }
            else if(isCP){
                minDistance = min(minDistance,i-lastCP);
                lastCP = i;
            }
            i++;
            prevNode = prevNode->next;
            currNode = currNode->next;
            nextNode = nextNode->next;
        }

        if(firstCP == lastCP) {
            return ans;
        } else {
             ans[0] = minDistance;
             ans[1] = lastCP - firstCP;
         }
         return ans;
    }
  



int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(30);
    Node* f = new Node(60);
    Node* g = new Node(30);
    Node* h = new Node(80);
    Node* i = new Node(10);
    Node* j = new Node(100);
    Node* k = new Node(30);
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
    cout<<endl<<endl;

    vector<int> ans  = nodesBetweenCriticalPoints(a);
    if(ans[0] == -1 && ans[1] == -1) {
        cout<<"There is no any Critical points exsist "<<endl;
    }else {
        cout<<"Minimum distance between two Critical Points is "<<ans[0]<<endl;
        cout<<"Maximum distance between two Critical Points is "<<ans[1]<<endl;   
    }


}
    

      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  