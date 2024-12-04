#include<iostream>
#include<vector>
using namespace std;
// Problem no. 658 LeetCode



    //Using two pointer approach
    vector<int> twoPointer(vector<int>& arr, int k, int x) {

        int low =0;
        int high =arr.size()-1;
        vector<int> ans;
        while(high-low>=k) {
            if(x-arr[low] > arr[high]-x) {
                low++;
            }
            else {
                high--;
            }
        }
        for(int i=low;i<=high;i++) {
            ans.push_back(arr[i]);
        }
        return ans;
        
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointer(arr,k,x);
    }

int main() {
    vector<int> arr={12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k=4;
    int x=30;
    vector<int> ans=findClosestElements(arr,k,x);
    cout<<"Closest element is " ;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}