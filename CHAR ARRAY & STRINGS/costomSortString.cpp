#include<iostream>
#include<unordered_map>
using namespace std;


// You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.

 

// Example 1:

// Input: order = "cba", s = "abcd"
// Output: "cbad"
// Explanation: 
// "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
// Example 2:

// Input: order = "cbafg", s = "abcd"
// Output: "cbad"

    string customSortString(string order, string s) {
        unordered_map<int,int> mp;
        for(auto val :s) {
            mp[val]++;
        }
        string ans = "";
        for(auto val :order) {
            while(mp[val]>0) {
                mp[val]--;
                ans += val; 
            }
        }

        for(auto val :mp) {
            while (val.second > 0) { 
                ans += val.first;
                val.second--;
            }
        }

        return ans;
    }
int main() {

    string order = "cba";
    string s = "abcd";

    string ans = customSortString(order,s);

    cout<<"Answer is "<<ans<<endl;

}