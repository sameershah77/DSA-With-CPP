#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

    string removeKdigits(string str, int k) {

        if(k >= str.length()) {
            return "0";
        }
        if(k == 0) {
            return str;
        }        
        stack <char> s;
        
        s.push(str[0]);
        
        for(int i = 1; i<str.length(); i++){
            while(k>0 && !s.empty() && str[i]<s.top()){
                k--;
                s.pop();
            }
            s.push(str[i]);
            
			// We pop any preceeding zeroes
            if(s.size() == 1 && str[i] == '0') {
                s.pop();   
            }
        }
        
		// For cases like "12345" where every str[i] > s.top()
        while(k && !s.empty()){
            k--;
            s.pop();
        }
        string res = "";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());

        return res.size() == 0 ? "0" : res;
    }
int main() {

    string num = "1432219";
    int k = 3;

    cout<<"answer is "<<removeKdigits(num,k)<<endl;


}