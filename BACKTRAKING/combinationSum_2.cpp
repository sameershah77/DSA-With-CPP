#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]


// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

    void combinationSum2(vector<int>& candidates, int target, vector<vector<int>> &ans,vector<int> v,int index) {
        //base condition
        if(target == 0) {
            ans.push_back(v);
            return;
        }

        if(target < 0) {
            return;
        }

    
        unordered_map<int,bool> visited;
        for(int i=index;i<candidates.size(); i++) {
            if(visited.find(candidates[i]) != visited.end()) {
                continue;
            } else {
                visited[candidates[i]] =true;
            }

            v.push_back(candidates[i]);
            combinationSum2(candidates,target-candidates[i],ans,v,i+1);
            v.pop_back();

        }

    }

    int main() {

        int n;
        cout<<"Enter the size of array "<<endl;
        cin>>n;
        vector<int> candidates(n);

        cout<<"Enter the elements in candidates "<<endl;
        for(int i=0;i<candidates.size();i++) {
            cin>>candidates[i];
        }
        cout<<endl<<endl;
        cout<<"Your array looks like "<<endl<<endl;
        for(int i=0;i<candidates.size();i++) {
            cout<<candidates[i]<<" ";
        }

        int target;

        cout<<endl;
        cout<<"Enter the value of target ";
        cin>>target;

        cout<<endl;

        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;

        vector<int> v;
        int index  = 0;
        combinationSum2(candidates,target,ans,v,index);

        int row = ans.size();
        int col = ans[0].size();
        cout<<"Combination sum is "<<endl<<endl;
       int count =0;
        for(int i=0;i<row;i++) {
            count++;
            cout<<target<<" = ";
            for(int j=0;j<col;j++) {
                cout<<ans[i][j]<<"   ";
            }
            cout<<endl;
        }
 cout<<"The largest number is garbage value ,, ignore it "<<endl<<endl<<endl;

    cout<<"Total number of combinations is "<<count<<endl<<endl;

    }

