#include<iostream>
#include<queue>
using namespace std;


class MyStack {
public:
    void reverse(queue<int> &q) {
        if(q.empty() == true) {
            return;
        }

        int x = q.front();
        q.pop();
        reverse(q);
        q.push(x);
        return;
    }
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        reverse(q);
        int x = q.front();
        q.pop();
        reverse(q);
        return x;
    }
    
    int top() {
        reverse(q);
        int x = q.front();
        reverse(q);
        return x;
    }
    
    bool empty() {
        if(q.empty()) {
            return true;
        }
        return false;
    }
};
int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"TOp of stack is "<<s.top()<<endl;
    s.pop();
    cout<<"TOp of stack is "<<s.top()<<endl;

    cout<<"Elements in queue is "<<endl;

    while(s.empty() == false) {
        cout<<" | "<<s.top()<<" | "<<endl;
        s.pop();
    }

}