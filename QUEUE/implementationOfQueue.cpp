#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    //this size variable is the size of array not size of queue. size of queue gives belove getSize function
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }


    void push(int data) {
        //for first element
        if(front == -1) {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
                //queue is full
        if(rear == size) {
            cout<<"Queue Overflow"<<endl;
        }
        else {
            //queue is not full
            arr[rear] = data;
            rear++;
        }
    }


    void pop() {
        //if queue is empty
        if(front == rear) {
            cout<<"Queue Underflow"<<endl;
        }
        else {
            arr[front] = -1;//we not delete data but increament front 
            front++;

            //after increament of front agar front and rear same ho gaye toh 0 se start hoga (to decrease memory wastage)
            if(front == rear) {
                front = 0;
                rear = 0;
            }

        }
    }

    int getFront() {

        //if queue is empty
        if(front == rear) {
            cout<<"There is no eny element. Queue is empty"<<endl;
            return -1;
        }
        else {
            return arr[front];
        }
    }
    int getBack() {
        if(front == rear) {
            cout<<"There is no eny element. Queue is empty"<<endl;
            return -1;
        }
        else {
            return arr[rear-1];
        }
    }

    int getSize() {
        return rear - front;
    }

    bool isEmpty() {
        if(front == rear) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {


    Queue q(10);
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);


    cout<<"Size of queue is "<<q.getSize()<<endl;

    q.pop();

    cout<<"After pop Size of queue is "<<q.getSize()<<endl;

    cout<<"Front element is "<<q.getFront()<<endl;
    cout<<"Back element is "<<q.getBack()<<endl;

    if(q.isEmpty()) {
        cout<<"Queue is empty"<<endl;
    }
    else {
        cout<<"Queue is not empty"<<endl;
    }
    cout<<"Elements in Queue is "<<endl;
    while(q.isEmpty() != true) {
        cout<<q.getFront()<<" ";
        q.pop();
    }

    

}