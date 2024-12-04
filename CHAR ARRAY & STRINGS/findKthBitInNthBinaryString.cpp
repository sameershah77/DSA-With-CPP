#include<iostream>
#include<string>
using namespace std;


// Given two positive integers n and k, the binary string Sn is formed as follows:

// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

// For example, the first four strings in the above sequence are:

// S1 = "0"
// S2 = "011"
// S3 = "0111001"
// S4 = "011100110110001"
// Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 

// Example 1:

// Input: n = 3, k = 1
// Output: "0"
// Explanation: S3 is "0111001".
// The 1st bit is "0".
// Example 2:

// Input: n = 4, k = 11
// Output: "1"
// Explanation: S4 is "011100110110001".
// The 11th bit is "1".

   string invertAndReverse(string s) {
        string x = "";
        for(auto val:s) {
            if(val == '1') {
                x+= '0';
            }
            else {
                x+= '1';
            }
        }

        int i=0;
        int j=s.size()-1;

        while(i<=j) {
            swap(x[i],x[j]);
            i++;
            j--;
        }
        return x;
    }
    char findKthBit(int n, int k) {

        int i=1;
        string prev = "0";
        string curr = "";
        while(i<=n) {
            curr = prev+'1'+invertAndReverse(prev);
            prev = curr;
            i++;
        }
        return curr[k-1];
    }
int main() {

    int n = 4;
    int k = 7;

    cout<<findKthBit(n,k)<<" is the "<<k<<"th bit in "<<n<<"th binary string"<<endl;
// S1 = "0"
// S2 = "011"
// S3 = "0111001"
// S4 = "011100110110001"
}