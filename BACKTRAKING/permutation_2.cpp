#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]


// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]



// Method 1 using set


    void permutation2(vector<vector<int>> &ans,vector<int>&nums,int index) {
        if(index >= nums.size() ) {
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++) {
            swap(nums[i],nums[index]);
            permutation2(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }


int main () {

        
        vector<int> nums = {1,2,1,5};


        vector<vector<int>>ans;
        int index =0;
        permutation2(ans,nums,index);
        
        set<vector<int>> st;

        for(auto i:ans) {
            st.insert(i);
        }


        ans.clear();
        for(auto j:st) {
            ans.push_back(j);
        }

        int count =0;

        for(int i=0; i<ans.size(); i++) {
            count++;
            for(int j=0; j<ans[0].size(); j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

        
        cout<<"Total number of permutations is "<<count<<endl<<endl;



}




// Method 2 using map






//     void permutation2(vector<vector<int>> &ans,vector<int>&nums,int index) {
//         if(index >= nums.size() ) {
//             ans.push_back(nums);
//             return;
//         }
//         unordered_map<int,bool> visited;

//         for(int i=index;i<nums.size();i++) {
//             if(visited.find(nums[i]) != visited.end()) {
//                 continue;
//             } else {
//                 visited[nums[i]] =true;
//             }

//             swap(nums[i],nums[index]);
//             permutation2(ans,nums,index+1);
//             swap(nums[i],nums[index]);
//         }
//     }


// int main () {

        
//         vector<int> nums = {1,2,1,5};


//         vector<vector<int>>ans;
//         int index =0;
//         permutation2(ans,nums,index);
        
//         for(int i=0; i<ans.size(); i++) {
//             for(int j=0; j<ans[0].size(); j++) {
//                 cout<<ans[i][j]<<" ";
//             }
//             cout<<endl;
//         }


// }