#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.

    string reverseOnlyLetters(string s) {

        int low =0;
        int high = s.size()-1;
        while (low<high) {
            if(isalpha(s[low]) && isalpha(s[high])) {
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(isalpha(s[low])&& !isalpha(s[high])) {
                high--;
            }
            else if(isalpha(s[high])&& !isalpha(s[low])) {
                low++;
            }
            else {
                low++;
                high--;
            }
        }
        return s;
        
    }

 
int main() {
    string s="a-bC-dEf-ghIj";

    string ans = reverseOnlyLetters(s);
    cout<<"Reverse of "<<s<<" is "<<endl<<ans<<endl;




}