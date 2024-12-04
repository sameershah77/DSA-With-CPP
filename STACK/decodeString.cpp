#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

 

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"
    string decodeString(string s) {
        string ans = "";
        stack<string> st;
        string number = "";

        for (int i = 0; i < s.size(); i++) {
            string t = string(1, s[i]);

            if (isdigit(s[i])) {
                number += s[i];
                continue;
            }

            if (s[i] == '[') {
                st.push(number);
                number.clear();
            }

            if (s[i] == ']') {
                string tempString = "";

                while (st.top() != "[") {
                    tempString += st.top();
                    st.pop();
                }

                st.pop();
                int temp = stoi(st.top());
                st.pop();

                for (int j = 0; j < temp; j++) {
                    ans += tempString;
                }

                st.push(ans);
                ans.clear();
                continue;
            }

            st.push(t);
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans; 
    }
int main() {

    string s = "3[a2[c]]";

    string ans = decodeString(s);

    cout<<"Your decoded string is : "<<ans<<endl;
}