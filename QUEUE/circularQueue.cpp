#include <iostream>
using namespace std;

class CirQueue{
        public:
        int size;
        int *arr;
        int front;
        int rear;

        CirQueue(int size) {
                this->size = size;
                arr = new int[size];
                front = -1;
                rear = -1;
        }

        void push(int data)  {
                //Queue Full
                if((front == 0 && rear == size-1) || rear == front-1) {
                        cout << "Q is fulll, cannot insert" << endl;
                }
                //single element case - > first element
                else if(front == -1) {
                        front = rear = 0;
                        arr[rear] = data;
                }
                //circular nature
                else if(rear == size-1 && front != 0 ) {
                        rear = 0;
                        arr[rear] = data;
                }
                //normal flow
                else{
                        rear++;
                        arr[rear]= data;
                } 
        }

        void pop() {
                //empty check
                if(front == -1 ) {
                        cout << "Q is empty , cannot pop" << endl;
                }
                //single element
                else if (front == rear) {
                        arr[front] = -1;
                        front = -1;
                        rear = -1;  
                }
                //circular nature
                else if(front == size-1) {
                        front = 0;
                }
                //normal flow
                else {
                        front++;
                }
        }
        
        int getFront() {
            //if queue is empty
            if(front == -1) {
                cout<<"There is no eny element. Queue is empty"<<endl;
                return -1;
            }
            else {
                return arr[front];
            }
        }
        
        bool isEmpty() {
            if(front == -1) {
                return true;
            }
            else {
                return false;
            }
        }
        void print() {
                for(int i=0; i<size; i++) {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
};





int main() {
    CirQueue q(5);
    q.print();
    q.push(10);
    q.print();
        q.push(10);
    q.print();
        q.push(10);
    q.print();
        q.push(10);
    q.print();


  return 0;
}