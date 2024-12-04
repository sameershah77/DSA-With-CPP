#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:

// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// Example 3:

// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [[1,3],[2,3]]
// Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
class Pair{
    public:
    int sum,first,second;
    Pair(int sum, int first, int second) {
        this->sum = sum;
        this->first = first;
        this->second = second;
    }
};
class compare{
    public:
    bool operator()(Pair* a, Pair* b)  {
        return a->sum < b->sum;
    }
};
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        priority_queue<Pair*,vector<Pair*>,compare> maxHeap;
        
        for(int i=0; i<size1; i++) {
            for(int j=0; j<size2; j++) {
                int currSum = nums1[i] + nums2[j];
                Pair* temp = new Pair(currSum,nums1[i],nums2[j]);
                if(maxHeap.size() < k) {
                    maxHeap.push(temp);
                }
                else if(currSum < maxHeap.top()->sum) {
                    maxHeap.pop();
                    maxHeap.push(temp);
                }
                else {
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        

        while(maxHeap.empty() == false) {
            vector<int> arr;
            Pair* top = maxHeap.top();
            maxHeap.pop();
            arr.push_back(top->first);
            arr.push_back(top->second);
            ans.push_back(arr);
        }

        return ans;
    }
int main() {
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;

    vector<vector<int>> ans = kSmallestPairs(nums1,nums2,k);;

    cout<<"The smallest "<<k<<" sum pairs are "<<endl;
    for(auto val: ans) {
        for(auto i:val) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    //the all pairs are [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
}