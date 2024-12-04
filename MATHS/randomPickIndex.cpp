#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
        
    }
    
    int pick(int target) {
        int n = nums.size();

        int index = rand()%n;

        if(nums[index] == target) {
            return index;
        }
        else {
            while(nums[index] != target) {
                index = rand()%n;
            }
            return index;
        }
    }
};
int main() {
    vector<int> arr = {1,2,3,3,3};

    Solution* temp = new Solution(arr);

    cout<<"Answer is "<<endl;
    cout<<temp->pick(3)<<endl;
    cout<<temp->pick(1)<<endl;
    cout<<temp->pick(3)<<endl;
    cout<<temp->pick(2)<<endl;

}