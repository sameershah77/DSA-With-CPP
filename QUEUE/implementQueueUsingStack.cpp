#include<iostream>
#include<stack>
using namespace std;



class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        
        if (s1.empty() == true && s2.empty() == true) {
            return -1;
        }
        if(s2.empty() == true) {
            while(s1.empty() == false) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty()==false)
            return s2.top();
        else{
            while(s1.empty()==false){
                s2.push(s1.top());
                s1.pop();
            }
           
            return s2.top();
        } 
    }
    
    bool empty() {
        if(s1.empty() == true && s2.empty() == true) {
            return true;
        }
        return false;
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<"Top element is "<<q.peek()<<endl;

    q.pop();
    cout<<"Top element is "<<q.peek()<<endl;
    cout<<"Elements in Queue"<<endl;
    while(!q.empty()) {
        cout<<q.peek()<<" ";
        q.pop();
    }

}