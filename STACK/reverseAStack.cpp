#include<iostream>
#include<stack>
using namespace std;


//reverse of stack without using another stack




void insertAtBottom(stack<int>& st,int target){

    if(st.empty()) {
        st.push(target);
        return;
    }

    int topData = st.top();
    st.pop();
    insertAtBottom(st,target);
    st.push(topData);

}


void reverseStack(stack<int>& st) {
    if(st.empty()==true) {
        return;
    }

    int target = st.top();
    st.pop();

    //reverse recursive call
    reverseStack(st);

    //insert at bottom call

    insertAtBottom(st,target);
}


int main() {
    stack<int> st;


    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<"Your Original stack is "<<endl<<endl;

    while(st.empty() == false) {
        cout<<"|  "<<st.top()<<"  |"<<endl;
        st.pop();

    }


    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);


    reverseStack(st);

    cout<<endl<<endl<<"After reverse of Stack"<<endl<<endl;


    while(st.empty() == false) {
        cout<<"|  "<<st.top()<<"  |"<<endl;
        st.pop();

    }


}