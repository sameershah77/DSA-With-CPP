#include<iostream>
#include<vector>
using namespace std;


// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2








/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:

    int val;
    vector<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()==true) {
            //if vector is empty
            pair<int,int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else {
            //if vector is non empty
            pair<int,int> p;
            p.first = val;
            p.second = min(val,st[st.size()-1].second);
            st.push_back(p);

        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1].first;
    }
    //this is the immportant function to find minimum in O(1);
    int getMin() {
        return st[st.size()-1].second;
    }
};


int main() {
    MinStack s;
    s.push(30);
    s.push(20);
    s.push(40);
    s.push(10);
    s.push(50);

    s.pop();

    int ans = s.getMin();

    

    cout<<"The minimum emelemt is "<<ans<<endl;


}