#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

// Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

 

// Example 1:

// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// Explanation: The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// The third fraction is 2/5.
// Example 2:

// Input: arr = [1,7], k = 1
// Output: [1,7]

class Info{
    public:
    int first;
    int second;
    float fraction;
    Info(float frac,int f, int s) {
        first = f;
        second = s;
        fraction = frac;
    }
};
class compare{
    public:
    bool operator()(Info* a, Info* b) {
        return a->fraction > b->fraction;
    }
};
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<Info*,vector<Info*>,compare> minHeap;
        for(int i=0; i<arr.size()-1; i++) {
            for(int j=i+1; j<arr.size(); j++) {
                float x = float(arr[i])/float(arr[j]);
                Info* temp = new Info(x,arr[i],arr[j]);
                minHeap.push(temp);
            }
        }
        vector<int> ans;
        while(k>1) {
            minHeap.pop();
            k--;
        }
        Info* temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->first);
        ans.push_back(temp->second);
        return ans;
    }

    int main() {
        vector<int> arr = {1,2,3,5};
        int k = 3;

        vector<int> ans = kthSmallestPrimeFraction(arr,k);
        cout<<k<<"th smallest prime factor are "<<endl;
        cout<<ans[0]<<","<<ans[1]<<endl;
        // The fractions to be considered in sorted order are:
        // 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
        // The 3rd fraction is 2/5.

    }