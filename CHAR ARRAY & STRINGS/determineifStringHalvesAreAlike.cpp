#include<iostream>
using namespace std;
// You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

// Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

// Return true if a and b are alike. Otherwise, return false.

 

// Example 1:

// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
// Example 2:

// Input: s = "textbook"
// Output: false
// Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
// Notice that the vowel o is counted twice.

    char helper(char ch) {
        if(ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a'-'A';
        }

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return ch;
        }
        return '0';
    } 
    bool halvesAreAlike(string s) {

        int count = 0;

        for(int i=0; i<s.size(); i++) {
            if(helper(s[i]) != '0') {
                if(i < s.size()/2) {
                    count++;
                }
                else {
                    count--;
                }
            }
        }

        return count == 0 ? true : false;       
    }

int main() {

    string s = "sameer";

    cout<<halvesAreAlike(s)<<endl;

    s = "book";

    cout<<halvesAreAlike(s)<<endl;

}