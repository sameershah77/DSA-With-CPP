#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1


    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto ch : s) {
            m[ch]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
int main() {
    string s = "loveleetcode";

    cout<<"The first unique character is at "<<firstUniqChar(s)<<endl;

}