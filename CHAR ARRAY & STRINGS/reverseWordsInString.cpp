#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

    string reverseWords(string s) {

        vector<string> arr;
        int i=0;
        int j=s.size()-1;
        while(s[i] == ' ') {
            i++;
        }
        while(s[j] == ' ') {
            j--;
        }
        string x="";

        while(i<=j) {
            if(s[i] != ' ') {
                x+=s[i];
            }    
            else {
                if(s[i+1] != ' ') {
                    arr.push_back(x);
                x="";
                } 
            }
            i++;
        }
        arr.push_back(x);

        reverse(arr.begin(),arr.end());

        x = arr[0];
        for(i=1;i<arr.size(); i++) {
            x +=" "+ arr[i];
        }

        return x;
    }
int main() {
    string x = "My name is sameer shah    ";

    cout<<endl<<reverseWords(x)<<endl;

    x = "a good   example";

    cout<<endl<<reverseWords(x)<<endl;

    x = "blue is sky the";

    cout<<endl<<reverseWords(x)<<endl;

    x = "  hello world  ";

    cout<<endl<<reverseWords(x)<<endl;
}