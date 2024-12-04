#include<iostream>
#include<string.h>
using namespace std;
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, ??more than once.
//Example :
// Input: s = "hello"
// Output: "holle"


    bool isVowel(char ch) {
        if(ch=='a'||ch=='e'||ch =='i'||ch =='o'||ch =='u'||ch=='A'||ch=='E'||ch =='I'||ch =='O'||ch =='U') {
            return true;
        }
        return false;;
    }
    string reverseVowels(string s) {
        int l=0;
        int h=s.size()-1;

        while(l<h) {
            if(isVowel(s[l]) && isVowel(s[h])) {
                swap(s[l],s[h]);
                l++;
                h--;
            }
            else if(isVowel(s[l]) && isVowel(s[h])==0) {
                h--;
            }
            else if(isVowel(s[h]) && isVowel(s[l])==0) {
                l++;
            }
            else {
                l++;
                h--;
            }
        }
        return s;
        
    }

int main() {

    string s;
    cout<<"Enter a string : ";
    cin>>s;


    string ans = reverseVowels(s);


    cout<<"Your answer is "<<ans<<endl;





}