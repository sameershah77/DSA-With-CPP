#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:

// Input: strs = [""]
// Output: [[""]]

// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

    void groupAnagrams(vector<string>& strs,vector<vector<string>> &ans) {
        map<string,vector<string>> mp;

        for(auto str:strs) {
            string s = str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }

     
        for(auto it:mp) {
            ans.push_back(it.second);
        }

    }

int main() {


    vector<string> s = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans;
    groupAnagrams(s,ans);


    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[0].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}