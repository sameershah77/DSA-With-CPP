#include<iostream>
#include<vector>
using namespace std;


// Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:

// Jumbo Burger: 4 tomato slices and 1 cheese slice.
// Small Burger: 2 Tomato slices and 1 cheese slice.
// Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].

 

// Example 1:

// Input: tomatoSlices = 16, cheeseSlices = 7
// Output: [1,6]
// Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese.
// There will be no remaining ingredients.
// Example 2:

// Input: tomatoSlices = 17, cheeseSlices = 4
// Output: []
// Explantion: There will be no way to use all ingredients to make small and jumbo burgers.
// Example 3:

// Input: tomatoSlices = 4, cheeseSlices = 17
// Output: []
// Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.


    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices %2 != 0 || tomatoSlices < cheeseSlices) return {};
        vector<int> ans;
        int small = cheeseSlices;
        int large = 0;
        while(true) {
            int val = (small*2 + large*4);
            if(val == tomatoSlices) {
                ans.push_back(large);
                ans.push_back(small);
                return ans;
            }
            if(small < 0) {
                return ans;
            }
            small--;
            large++;
        }
        return ans;
    }

int main() {
    int tomatoSlices = 16; 
    int cheeseSlices = 7;
    vector<int>ans = numOfBurgers(tomatoSlices,cheeseSlices);

    cout<<"Jumbo burger will be "<<ans[0]<<endl;
    cout<<"Small burger will be "<<ans[1]<<endl;
}