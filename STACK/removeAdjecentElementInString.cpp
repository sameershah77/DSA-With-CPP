#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

    //using stack

    string removeDuplicates(string s) {
        string ans = "";
        stack<char> st;
        for(auto ch:s) {
            if(st.empty() == false && st.top() == ch) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        while(st.empty() == false) {
            ans += st.top();
            st.pop();
        }


        reverse(ans.begin(),ans.end());
        return ans;
        
    }
int main () {
    string s;
    cout<<"Enter a string with duplicate element"<<endl;
    getline(cin,s);
    string x = removeDuplicates(s);
    cout<<x<<endl;


}

