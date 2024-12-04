#include<iostream>
#include<queue>
#include<string>
using namespace std;


// You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

// Return the string that represents the kth largest integer in nums.

// Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

 

// Example 1:

// Input: nums = ["3","6","7","10"], k = 4
// Output: "3"
// Explanation:
// The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
// The 4th largest integer in nums is "3".
// Example 2:

// Input: nums = ["2","21","12","1"], k = 3
// Output: "2"
// Explanation:
// The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
// The 3rd largest integer in nums is "2".
// Example 3:

// Input: nums = ["0","0"], k = 2
// Output: "0"
// Explanation:
// The numbers in nums sorted in non-decreasing order are ["0","0"].
// The 2nd largest integer in nums is "0".

    class comparator {
        public:
        bool operator()(string &s1,string &s2) {
            if(s1.length()>s2.length()) {
                return true;
            }
            else if(s1.length()<s2.length()) {
                return false;
            }
            else {
                for(int i=0;i<s1.length();i++) {
                    
                    if(s1[i]-'0'>s2[i]-'0') {
                        return true;
                    }
                    else if(s1[i]-'0'<s2[i]-'0') {
                        return false;
                    }
                }
                return false;
            }
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
      
        priority_queue<string,vector<string>,comparator>minHeap;
        
        for(auto val:nums) {
            minHeap.push(val);
            
            if(minHeap.size()>k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
int main() {

    vector<string> nums = {"3","6","7","10"};
    int k=3;

    string ans = kthLargestNumber(nums,k);

    cout<<k<<"th largest integer is "<<ans<<endl;

}