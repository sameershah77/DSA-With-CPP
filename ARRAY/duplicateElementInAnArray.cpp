#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int findDuplicate(vector<int>& nums) {
        // This is optimal solution
        int ans =-1;
        for(int i=0;i<nums.size();i++) {
            int index = abs(nums[i]);
            if(nums[index] <0) {
                ans = index;
                break;
            }
            nums[index] *= -1;
        }
        return ans;

        // sort(nums.begin(),nums.end());

        // for(int i=0;i<nums.size()-1;i++) {
        //     if(nums[i]==nums[i+1]) {
        //         return nums[i];
        //     }
        // }
        // return -1;

    }

int main() {
    vector<int> arr = {1,2,2,3,4,5,6,7,8,9};
    int ans = findDuplicate(arr);
    cout<<"Duplicate element is "<<ans<<endl;

}