#include<iostream>
using namespace std;

// Given a 0-indexed string s, permute s to get a new string t such that:

// All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
// The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
// Return the resulting string.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 
// Example 1:

// Input: s = "lEetcOde"
// Output: "lEOtcede"
// Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
// Example 2:

// Input: s = "lYmpH"
// Output: "lYmpH"
// Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".

    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        int freq[128]={0};

        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) {
                freq[(int)s[i]]++;
            }
        }
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(freq[idx]==0) {
                    idx++;
                }
                s[i]=(char)idx;
                freq[idx]--;
            }
        }
        return s;
    }
int main() {
    
    string s = "lEetcOde";

    cout<<"Answer is "<<sortVowels(s)<<endl;

}