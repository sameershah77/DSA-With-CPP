       
       
       
       
       
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"

// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"

// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"


int main() {

    string num1; 
    string num2;
    cout<<"Enter numbers to add"<<endl;
    cin>>num1;
    cin>>num2;
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        int carry = 0;
        string ans  = "";
        while(p1>=0 || p2>=0) {

        int n1 = (p1>=0 ? num1[p1]:'0')-'0';
        int n2 = (p2>=0 ? num2[p2]:'0')-'0';

            int currSum = n1+n2+carry;
            int digit = currSum%10;
            carry = currSum/10;
            ans.push_back(digit+'0');
            p1--;
            p2--;


        }


        if(carry != 0) {
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());

        cout<<"Your summation is "<<ans<<endl;
}
       
    