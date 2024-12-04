#include<iostream>
using namespace std;

// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

 

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// Example 2:

// Input: n = 25
// Output: 1389537
 

// Constraints:

// 0 <= n <= 37
// The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

    int tribonacci(int n) {

    int T0 = 0;
    int T1 = 1;
    int T2 = 1;

    if(n == 0) return T0;
    if(n == 1) return T1;
    if(n == 2) return T2;

    int i = 3;
    int temp = 0;
    
    while(i <= n) {
        temp = T0 + T1 + T2;
        T0 = T1;
        T1 = T2;
        T2 = temp;
        i++;
    }
    return temp;
        
    }

int main() {
    int n = 5;
    cout<<"Answer is "<<tribonacci(n)<<endl;
}