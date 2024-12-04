#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

    //first approch
    string frequencySort(string s) {
        unordered_map<char,int> freq;           //for frequency of characters
        priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
        s="";   
        while(!maxheap.empty()){
            int count = maxheap.top().first;
            char ch = maxheap.top().second;
            while(count != 0) {
                s+=ch;
                count--;
            }
            maxheap.pop();
        }
        return s;
    }

    //second approch : it is better 
    string frequencySort1(string s) {
        vector<int> freqSmall(26,0);
        vector<int> freqCapital(26,0);
        vector<int> freqDigits(10,0);

        for(auto ch: s) {
            if('a' <= ch && ch <= 'z') {
                freqSmall[ch-'a']++;
            }
            else if(('A' <= ch && ch <= 'Z')){
                freqCapital[ch-'A']++;
            }
            else {
                freqDigits[ch-'0']++;
            }
        }

        priority_queue<pair<int,char>> maxHeap;

        for(int i=0; i<26; i++) {
            int count = freqSmall[i];
            if(count != 0) {
                maxHeap.push({count,i+'a'});
            }
            count = freqCapital[i];
            if(count != 0) {
                maxHeap.push({count,i+'A'});
            }
            if(i<10) {
                int count = freqDigits[i];
                if(count != 0) {
                    maxHeap.push({count,i+'0'});
                }
            }
        }
        string str = "";
        while(maxHeap.empty() == false) {
            int count = maxHeap.top().first;
            int ch = maxHeap.top().second;
            maxHeap.pop();
            while(count != 0) {
                str += ch;
                count--;
            }
        }

        return str;
    }

int main() {

    string s = "Tree";

    string ans = frequencySort(s);
    cout<<"Answer is "<<ans<<endl;

}