#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;


// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"



// Example 2:

// Input: s = "aaab"
// Output: ""

    string reorganizeString(string s) {


        int hash[26] = {0};

        for(int i=0; i<s.size(); i++) {
            hash[s[i]-'a']++;
        }



        char most_freq_char;
        int max_freq = INT_MIN;

        for(int i=0; i<26; i++) {
            if(hash[i] > max_freq) {
                max_freq = hash[i];
                most_freq_char = i + 'a';
            }
        }
        
        int index = 0;

        while(max_freq > 0 && index <s.size()) {
            s[index] = most_freq_char;
            max_freq--;
            index += 2;
        }

        if(max_freq != 0) {
            return "NOT Found";
        }
        hash[most_freq_char -'a']=0;

        for(int i=0; i<26; i++) {
            while(hash[i] > 0) {
                if(index>=s.size()) {
                    index=1;
                }

                s[index] = i + 'a';
                index += 2;
                hash[i]--;
            }
        }
        return s;
    }

int main() {

    cout<<reorganizeString("aab")<<endl;
    cout<<reorganizeString("aaab")<<endl;    
    cout<<reorganizeString("aabbcd")<<endl;
    cout<<reorganizeString("abbccddghj")<<endl;


}