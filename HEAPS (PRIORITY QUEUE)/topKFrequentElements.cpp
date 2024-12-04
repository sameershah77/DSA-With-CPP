#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> maxHeap;
        for(auto val: mp) {
            pair<int,int> p = make_pair(val.second,val.first);
            maxHeap.push(p);
        }        
        vector<int> ans;
        while(k--) {
            pair<int,int> p = maxHeap.top();
            maxHeap.pop();
            int data = p.second;
            int count = p.first;
            ans.push_back(data);
        }
        return ans;
    }

int main() {
    vector<int>nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = topKFrequent(nums,k);
    cout<<endl<<"Top "<<k<<" Frequent elements are "<<endl;
    for(auto val : ans) {
        cout<<val<<" ";
    }
    cout<<endl;


}