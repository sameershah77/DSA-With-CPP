#include<iostream>
#include<stack>
using namespace std;


//sort stack without using another stack




void insertSorted(stack<int>& st,int target){

    if(st.empty() || st.top()>=target) {
        st.push(target);
        return;
    }

    int topData = st.top();
    st.pop();
    insertSorted(st,target);
    st.push(topData);

}


void sortStack(stack<int>& st) {
    if(st.empty()==true) {
        return;
    }

    int target = st.top();
    st.pop();

    //sort using recursive call
    sortStack(st);

    //insert at correct position call

    insertSorted(st,target);
}


int main() {
    stack<int> st;


    st.push(10);
    st.push(30);
    st.push(10);
    st.push(80);
    st.push(40);
    st.push(20);
    st.push(50);
    st.push(60);
    st.push(70);

    cout<<"Your Original stack is "<<endl<<endl;

    while(st.empty() == false) {
        cout<<"|  "<<st.top()<<"  |"<<endl;
        st.pop();

    }


    
    st.push(10);
    st.push(30);
    st.push(10);
    st.push(80);
    st.push(40);
    st.push(20);
    st.push(50);
    st.push(60);
    st.push(70);
    sortStack(st);

    cout<<endl<<endl<<"After Sorting of Stack"<<endl<<endl;


    while(st.empty() == false) {
        cout<<"|  "<<st.top()<<"  |"<<endl;
        st.pop();

    }


}