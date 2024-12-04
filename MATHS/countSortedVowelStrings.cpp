#include<iostream>
using namespace std;

// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

// A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
// Example 2:

// Input: n = 2
// Output: 15
// Explanation: The 15 sorted strings that consist of vowels only are
// ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
// Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
// Example 3:

// Input: n = 33
// Output: 66045

    int countVowelStrings(int n) {
        int a = 1;
        int e = 1;
        int i = 1;
        int o = 1;
        int u = 1;

        while(--n) {
            u = u;
            o += u;
            i += o;
            e += i;
            a += e; 
        }

        return a+e+i+o+u;	
    }


int main() {

    int n = 2;

    cout<<"Answer is "<<countVowelStrings(n)<<endl;

}