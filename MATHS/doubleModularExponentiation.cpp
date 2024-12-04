#include<iostream>
#include<vector>
using namespace std;


// You are given a 0-indexed 2D array variables where variables[i] = [ai, bi, ci, mi], and an integer target.

// An index i is good if the following formula holds:

// 0 <= i < variables.length
// ((aibi % 10)ci) % mi == target
// Return an array consisting of good indices in any order.

 

// Example 1:

// Input: variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
// Output: [0,2]
// Explanation: For each index i in the variables array:
// 1) For the index 0, variables[0] = [2,3,3,10], (23 % 10)3 % 10 = 2.
// 2) For the index 1, variables[1] = [3,3,3,1], (33 % 10)3 % 1 = 0.
// 3) For the index 2, variables[2] = [6,1,1,4], (61 % 10)1 % 4 = 2.
// Therefore we return [0,2] as the answer.
// Example 2:

// Input: variables = [[39,3,1000,1000]], target = 17
// Output: []
// Explanation: For each index i in the variables array:
// 1) For the index 0, variables[0] = [39,3,1000,1000], (393 % 10)1000 % 1000 = 1.
// Therefore we return [] as the answer.

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        
        vector<int> ans;
        
        for(int i = 0; i<variables.size(); i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            int n1 = 1;

            for(int j = 0; j<b; j++) {
                n1 = (n1*a)%10;
            }

            int n2 = 1;

            for(int j = 0; j<c; j++) {
                n2 = (n1*n2)%m;
            }

            if(n2 == target) {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
int main() {

    vector<vector<int>> variables = {{2,3,3,10},{3,3,3,1},{6,1,1,4}};
    int target = 2;

    vector<int> ans = getGoodIndices(variables,target);

    cout<<"Answer is "<<endl;

    for(auto val: ans) {
        cout<<val<<" ";
    }

}