#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
// substring
// .

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0


    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLength = 0;

        for(int i=0; i<s.size(); i++) {
            char currChar = s[i];

            if(currChar == '(') {
                //opening bracket
                st.push(i);
            } 
            else {
                //closing bracket
                st.pop();
                if(st.empty() == true) {
                    //stack is empty
                    st.push(i);
                }
                else {
                    //stack is non empty
                    int len = i - st.top();
                    maxLength = max(maxLength,len);
                }
            }
        }
        return maxLength;
    }
int main() {
    string s1 = "((()))";
    int ans1 = longestValidParentheses(s1);

    cout<<endl<<endl<<"Longest length of valid parenthesis in "<<s1<<" is "<<ans1<<endl<<endl;

    string s2 = "(()";
    int ans2 = longestValidParentheses(s2);

    cout<<endl<<endl<<"Longest length of valid parenthesis in "<<s2<<" is "<<ans2<<endl<<endl;

    string s3 = "(()()(())";
    int ans3 = longestValidParentheses(s3);

    cout<<endl<<endl<<"Longest length of valid parenthesis in "<<s3<<" is "<<ans3<<endl<<endl;

}

