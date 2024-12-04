#include<iostream>
#include<stack>
using namespace std;


int main() {

    string s = "SAMEER SHAH";

    stack<char> st;
    int i=0;
    while(i<s.size()) {
        st.push(s[i]);
        i++;
    }


    while(st.empty() == false) {
        cout<<st.top();
        st.pop();
    } 
}
