#include<iostream>
using namespace std;

// Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: s = "aa"
// Output: 0
// Explanation: The optimal substring here is an empty substring between the two 'a's.
// Example 2:

// Input: s = "abca"
// Output: 2
// Explanation: The optimal substring here is "bc".
// Example 3:

// Input: s = "cbzxy"
// Output: -1
// Explanation: There are no characters that appear twice in s.

    int maxLengthBetweenEqualCharacters(string s) {
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            for(int j=i+1; j<s.size(); j++) {
                if(s[i] == s[j]) ans = max(ans,j-i);
            }
        }
        return ans-1;
    }


int main() {
    string s = "abca";
    cout<<"Answer is "<<maxLengthBetweenEqualCharacters(s)<<endl;

}