#include<iostream>
#include<algorithm>
using namespace std;
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "God Ding"
// Output: "doG gniD"
    string reverseWords(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {   // when i is a non-space
                int j = i;
                while(j < s.length() && s[j] != ' ') {
                    j++;
                 } // move j to the next space
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        return s;
    }

int main () {
    string s = "Let's take LeetCode contest";

    string ans = reverseWords(s);

    cout<<ans<<endl;

}     