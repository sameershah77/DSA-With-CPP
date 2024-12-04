#include<iostream>
using namespace std;


class Stack {
    public:
    int size;
    int* arr;
    int top1;
    int top2;

    Stack(int size) {
        
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data) {
        if(top2 - top1 == 1) {
            //space not available
            cout<<"Overflow in Stack 1"<<endl;
        }
        else {
            top1++;
            arr[top1] = data;
        }
    }
    void pop1() {
        if(top1 == -1) {
            //stack1 is empty
            cout<<"Underflow in Stack 1"<<endl;
        }
        else {
            top1--;
        }
    }


    void push2(int data) {
        if(top2 - top1 == 1) {
            //space not available
            cout<<"Overflow in Stack 2"<<endl;
        }
        else {
            top2--;
            arr[top2] = data;
        }
    }
    void pop2() {
        if(top2 == size) {
            //stack 2 is empty
            cout<<"Underflow in Stack 2"<<endl;
        }
        else {
            top2++;
        }
    }

    void print() {
        cout<<endl<<endl;
        cout<<"Top 1 : "<<top1<<endl;
        cout<<"Top 2 : "<<top2<<endl;
        for(int i=0; i<size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }



};
int main() {

    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();    
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();    
    s.push1(50);
    s.print();


    s.push2(100);
    s.print();
    s.push2(110);
    s.print();
    s.push2(130);
    s.print();
    
    

}