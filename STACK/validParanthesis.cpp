#include<iostream>
#include<stack>
using namespace std;

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false

    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            char currChar = s[i];

            if(currChar == '(' || currChar == '[' || currChar == '{') {
                //opening brackets 
                st.push(currChar);
            }
            else {
                //closing brackets

                if(st.empty() == false) {
                    //stack is not empty
                    char topChar = st.top();

                    if(currChar == ')' && topChar == '(') {
                        st.pop();
                    } 
                    else if(currChar == ']' && topChar == '[') {
                        st.pop();
                    }
                    else if(currChar == '}' && topChar == '{') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                } else {
                    //stack is empty
                    return false;
                }
            }
        }

        if(st.empty() == true) {
            return true;
        }

        return false;
        
    }
int main() {

    string s = "(){}[]({[]})";

    bool ans = isValid(s);
    cout<<endl<<endl<<"Your expression is "<<s<<endl;

    if(ans) {
        cout<<endl<<"Given paranthesis expression is Valid"<<endl<<endl;
    }else {
        cout<<endl<<"Given paranthesis expression is Invalid"<<endl<<endl;
    }

cout<<"______________________________________________"<<endl;
    s = "({)}";

    ans = isValid(s);

    cout<<endl<<endl<<"Your expression is "<<s<<endl;

    if(ans) {
        cout<<endl<<"Given paranthesis expression is Valid"<<endl<<endl;
    }else {
        cout<<endl<<"Given paranthesis expression is Invalid"<<endl<<endl;
    }

}