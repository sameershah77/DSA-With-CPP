#include<iostream>
#include<vector>
using namespace std;

// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

// Example 1:

// Input: grid = [[1,3],[2,2]]
// Output: [2,4]
// Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
// Example 2:

// Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
// Output: [9,5]
// Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n+1, 0);
        vector<int> ans;
        for(auto row: grid) {
            for(auto num: row) {
                freq[num]++;
                if(freq[num] == 2) {
                    ans.push_back(num);
                }
            }
        }

        for(int i=1; i<freq.size(); i++) {
            if(freq[i] == 0) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
int main() {
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};

    vector<int> ans = findMissingAndRepeatedValues(grid);

    cout<<"Reapeted Number is "<<ans[0]<<endl;
    cout<<"Missing Number is "<<ans[1]<<endl;
}