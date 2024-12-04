#include<iostream>
#include<vector>
using namespace std;

// You are given two integers m and n, which represent the dimensions of a matrix.

// You are also given the head of a linked list of integers.

// Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

// Return the generated matrix.

 

// Example 1:


// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// Explanation: The diagram above shows how the values are printed in the matrix.
// Note that the remaining spaces in the matrix are filled with -1.
// Example 2:


// Input: m = 1, n = 4, head = [0,1,2]
// Output: [[0,1,2,-1]]
// Explanation: The diagram above shows how the values are printed from left to right in the matrix.
// The last space in the matrix is set to -1.
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
    int getLength(Node* head) {
        int len = 0;
        while(head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    } 
    
    vector<vector<int>> generateMatrix(int m, int n, Node* head) {

        vector<vector<int>> matrix(m,vector<int>(n,-1));
        Node* temp = head;
        int row = m;
        int col = n;
        
        int count = 0;
        int totalElement = row*col;

        int length = getLength(temp);

        if(length < totalElement) {
            while(temp->next != NULL) {
                temp = temp->next;
            }
        }

        while(length < totalElement) {
            Node* newNode = new Node(-1);
            temp->next = newNode;
            temp = temp->next;
            length++;
        }

        //Index Initialising
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        while(count < totalElement) {
            //print first row
            for(int index = startingCol;index <= endingCol && count < totalElement;index++) {
                matrix[startingRow][index] = head->data;
                head = head->next;
                count++;
            }
            startingRow++;
            //print last coloumn
              for(int index = startingRow;index <= endingRow && count < totalElement;index++) {
                matrix[index][endingCol] = head->data;
                head = head->next;
                count++;
            }
            endingCol--;


        //print last row
            for(int index = endingCol;index >= startingCol && count < totalElement;index-- ){
                matrix[endingRow][index] = head->data;
                head = head->next;
                count++;
            }
            endingRow--;

              //print first coloumn
            for(int index = endingRow;index >= startingRow && count < totalElement;index-- ){
                matrix[index][startingCol] = head->data;
                head = head->next;
                count++;
            }
            startingCol++;
        }

    return matrix;        
    }

int main () {
    int m;
    cout<<"Enter number of row  :- ";
    cin>>m;

    int n;
    cout<<"Enter number of cols :- ";
    cin>>n;

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



    cout<<"Your spiral matrix is :- "<<endl;

    vector<vector<int>> matrix = generateMatrix(m,n,a);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}