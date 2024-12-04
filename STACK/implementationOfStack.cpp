#include<iostream>
using namespace std;

class Stack{
    public:
    int top;
    int* arr;
    //this size variable is the size of array not size of stack. size of stack gives belove getSize function
    int size;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    //functtions 

    void push(int data) { 
        if(size - top > 1) {
            //scape available
            top++;
            arr[top] = data;
        }
        else {
            cout<<"Stack Overlow, Stack is not epmty"<<endl;
            return;
        }

    }

    

    void pop() {
        if(top == -1) {
            cout<<"Stack Underflow, Stack is empty"<<endl;
            return;
        }
        else {
            top--;
        }

    }
    //this function gives the size of stack i.e. number of elements presents in stack and above size variable is size of array both are different
    int getSize() {
        return top+1;
    }

    int getTop() {
        if(top == -1) {
            cout<<"There is no elements in Stack"<<endl;
        }
        else {
            return arr[top];
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {

    Stack st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<endl<<endl;

    cout<<"The size of stack is "<<st.getSize()<<endl;

    cout<<"Currant elements in stack is "<<endl;
    while(st.isEmpty() != true) {
        cout<<st.getTop()<<" ";
        st.pop();
       
    }
    cout<<endl<<endl;

    cout<<"The size of stack is "<<st.getSize()<<endl;




}