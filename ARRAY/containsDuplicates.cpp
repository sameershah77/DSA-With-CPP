#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n-1; i++) {
                if (nums[i] == nums[i+1])
                    return true;
        }
        return false;
    }
main () {

    vector<int> arr = {1,2,1,3,4,5,5};
    if(containsDuplicate(arr)) {
        cout<<"It contains duplicate"<<endl;
    }
    else {
        cout<<"It doesn't contains duplicate"<<endl;
    }

}