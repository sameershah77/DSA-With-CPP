#include<iostream>
#include<climits>
using namespace std;


// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

// Example 1:

// Input: n = 3
// Output: 3
// Explanation: Initially, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
// Example 2:

// Input: n = 1
// Output: 0


    int minSteps(int n) {
        if (n == 1)
            return 0;

        int minQuotient= 1;
        int currentValue = n;
        int result = 0;
        
        while (currentValue != 1) {
            int mini = INT_MAX;
            for (int j = 1; j <= n; ++j) {
                if (currentValue % j == 0) {
                    auto tmp = currentValue / j;
                    if (tmp != 1) {
                        mini = min(mini, tmp);
                        minQuotient = j;
                    }
                }
            }
            result += mini;
            currentValue = minQuotient;
        }

        return result;
    }

int main() {

    int n = 4;
    cout<<"Answer is "<<minSteps(n)<<endl;
    
}