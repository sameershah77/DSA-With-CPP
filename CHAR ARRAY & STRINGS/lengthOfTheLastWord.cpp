#include<iostream>
#include<string.h>
using namespace std;


// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal 
// substring
//  consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.


// Example 2:

// Input: s = "   fly me   to   the moon  "

// Output: 4
// Explanation: The last word is "moon" with length 4.


    int lengthOfLastWord(string s) {
        int count = 0;
        int j=0;


        for(int i=s.size()-1; i>=0 ; i--) {
            if(s[i]==' ') {
                j++;
            }
            else {
                break;
            }
        }

        for(int i=s.size()-j-1;i>=0;i--) {
            if(isalpha(s[i])) {
                count++;
            }
            else {
                break;
            }
        }
        return count;
        
    }
int main() {

    string s = "My name is sameer";
    int n = lengthOfLastWord(s);
    cout<<"Length of last word is "<<n<<endl;


}