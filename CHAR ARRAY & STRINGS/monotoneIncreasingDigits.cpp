#include<iostream>
using namespace std;


// An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

// Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

 

// Example 1:

// Input: n = 10
// Output: 9
// Example 2:

// Input: n = 1234
// Output: 1234
// Example 3:

// Input: n = 332
// Output: 299

    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        if(num.size() == 1) {
            return n;
        }            

        char prev = num[0];
        bool flag = false;

        int index = 0;

        for(int i=1; i<num.size(); i++) {

            char curr = num[i];
            if(prev-'0' <= curr-'0' && flag == false) {
                prev = curr;
            }
            else if(prev-'0' > curr-'0' && flag == false){
                num[i-1] = ((prev-'0')-1)+'0';
                index = i-1;
                flag = true;
            }

            if(flag == true) {
                num[i] = '9';
            }
        }    

        index--;

        while(index >= 0) {
            if(num[index] > num[index+1]){
                num[index+1] = '9';
                num[index] = ((num[index]-'0')-1)+'0';
            }
            else {
                break;
            }
            index--;
        }
        return stoi(num);
    }
int main() {

    int n = 34542;

    cout<<"Answer is "<<monotoneIncreasingDigits(n)<<endl;

}