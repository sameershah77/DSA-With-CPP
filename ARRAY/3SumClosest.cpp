#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
	void Solve(vector<int> &nums, int x, int i, int T,int& ans,int& mx)
	{

	
		int n = nums.size();
		int L = i;
		int R = n - 1;
		while (L < R)
		{
			int val = (nums[x] + nums[L] + nums[R]);
			if (abs(T - val) < mx)
			{
				ans = val;
				mx = abs(T - val);
			}
			else if (val > T) R--;
			else L++;
		}
	}

	int threeSumClosest(vector<int> &nums, int target)
	{
		int mx = INT_MAX;
                int ans = 0;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; i++)
		{
			if (i == 0 || nums[i - 1] != nums[i])
			{
				Solve(nums, i, i + 1, target,ans,mx);
			}
		}

		return ans;
	}

    int main() {

    vector<int> arr = {1,2,3,4,5}; 
    int target = 3;

    cout<<"The closest sum is "<<threeSumClosest(arr,target)<<endl;
    return 0;

}


