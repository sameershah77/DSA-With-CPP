#include<iostream>
#include<vector>
using namespace std;

// You are given an array of strings words and a string chars.

// A string is good if it can be formed by characters from chars (each character can only be used once).

// Return the sum of lengths of all good strings in words.

 

// Example 1:

// Input: words = ["cat","bt","hat","tree"], chars = "atach"
// Output: 6
// Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
// Example 2:

// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// Output: 10
// Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


    bool canForm(string word, vector<int> freq) {
        int i = 0;
        while(i<word.size()) {
            if(freq[word[i]-'a'] != 0) {
                freq[word[i]-'a']--;
            }
            else {
                return false;
            }
            i++;
        }
       return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(auto val: chars) {
            freq[val - 'a']++;
        }
        int count = 0;
        for(auto val: words) {
            if(canForm(val,freq)) {
                count += val.size();
            }
        }
        return count; 
    }


int main() {
    vector<string> words = {"cat","bt","hat","tree"}; 
    string chars = "atach";

    cout<<"Answer is "<<countCharacters(words,chars)<<endl;
}