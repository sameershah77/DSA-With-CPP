#include<iostream>
#include<stack>
using namespace std;


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

    int target = 80;
    insertAtBottom(st,target);

    cout<<endl<<endl<<"Stack after insertion "<<target<<" at Bottom"<<endl<<endl;

    while(st.empty() == false) {
        cout<<"|  "<<st.top()<<"  |"<<endl;
        st.pop();

    }

}