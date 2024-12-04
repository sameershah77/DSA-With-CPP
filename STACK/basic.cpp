#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();

    cout<<"Toap element is "<<st.top()<<endl;

    cout<<"size of stack is "<<st.size()<<endl;

    if(st.empty()) {
        cout<<"Stack is empty"<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }

    cout<<"Printing elements of stack"<<endl;

    while(st.empty() == false) {
        cout<<st.top()<<" ";
        st.pop();
    }



}