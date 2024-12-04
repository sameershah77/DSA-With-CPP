#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

// Return the array after sorting it.

 

// Example 1:

// Input: arr = [0,1,2,3,4,5,6,7,8]
// Output: [0,1,2,4,8,3,5,6,7]
// Explantion: [0] is the only integer with 0 bits.
// [1,2,4,8] all have 1 bit.
// [3,5,6] have 2 bits.
// [7] has 3 bits.
// The sorted array by bits is [0,1,2,4,8,3,5,6,7]
// Example 2:

// Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
// Output: [1,2,4,8,16,32,64,128,256,512,1024]
// Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.


    static int countBit(int n) {
        int cnt = 0 ;
        while(n) {
            int val = n%2;
            n = n/2;
            if(val == 1)
                cnt++;
        }
        return cnt ;
    }
    static bool comp(int x, int y) {   
        int bitCountX = countBit(x);
        int bitCountY = countBit(y);
        
        if (bitCountX == bitCountY) 
            return x < y;

        return bitCountX < bitCountY;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp) ;
        return arr ;
    }
int main() {
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    cout<<"Answer is "<<endl;
    arr = sortByBits(arr);
    for(auto val: arr) {
        cout<<val<<" ";
    }

}