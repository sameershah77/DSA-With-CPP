#include<iostream>
#include<string>
using namespace std;

    int expandAroundIndex(string s, int left, int right) {
        int count = 0;
        //jab tak match karega, tab tak count increment kardo and i piche and j aaage kardo
        while(left >= 0 && right <s.length() && s[left] == s[right] ) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        int n = s.length();

        for(int center=0; center<n; center++) {
            //odd
            int oddKaAns = expandAroundIndex(s, center, center);
            totalCount = totalCount + oddKaAns;
            //even
            int evenKaAns = expandAroundIndex(s,center,center+1);
            totalCount = totalCount + evenKaAns;
        }
 
        return totalCount;
    }

    int main() {

        string s ;
        cout<<"Enter a string"<<endl;
        getline(cin,s);
        int x = countSubstrings(s);
        cout<<"Total number of Substring is "<<x<<endl;

    }



