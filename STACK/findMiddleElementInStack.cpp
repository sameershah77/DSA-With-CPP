#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>& st, int totalSize,int &middle) {
    if(st.size() == totalSize/2+1) {
        middle = st.top();
        return ;
    }


    int temp = st.top();
    st.pop();

    //recursive call
    printMiddle(st,totalSize,middle);

    st.push(temp);
}

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    
    int totalSize = st.size();
    int middle = -1;
    printMiddle(st,totalSize,middle);


    cout<<"Middle element is "<<middle<<endl;
}