#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;



// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]
 
class Info{
    public:
    int data;
    int row;
    int col;
    Info(int data,int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
    public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Info*,vector<Info*>,compare> minHeap;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        vector<int> ans;

        for(int i=0; i<k; i++) {
            Info* temp = new Info(nums[i][0],i,0);
            minHeap.push(temp);
            mini = min(mini,temp->data);
            maxi = max(maxi,temp->data);
        }

        int startAns = mini;
        int endAns = maxi;

        while(minHeap.empty() == false) {
            Info* top = minHeap.top();
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;

            minHeap.pop();


            //update mini
            mini = topElement;


            //check for answer range
            int previosRange = maxi - mini;
            int currentRange = endAns - startAns;

            if(previosRange < currentRange) {
                startAns = mini;
                endAns = maxi;
            }

            //check for element in same array
            if(topCol+1 < nums[topRow].size()) {
                Info* newInfo = new Info(nums[topRow][topCol+1],topRow,topCol+1);
                maxi = max(maxi, newInfo->data);
                minHeap.push(newInfo);
            }
            else {
                //there is no any element in same array
                break;
            }


        }
        
        ans.push_back(startAns);
        ans.push_back(endAns);


        return ans;      
    }
int main(){
    vector<vector<int>> list = {{4,10,15,24,26}
                               ,{0,9,12,20}
                               ,{5,18,22,30}};
    // all the range for this above exmaple are
    //0->5, 5->10, 4->9, 9->18, 10->18, 12->18, 15->20, 18->24, 20->24
    vector<int> ans = smallestRange(list);


    cout<<endl;

    cout<<endl<<"Your smallest range covering all the list is "<<endl;
    cout<<ans[0]<<" -> "<<ans[1]<<endl;
}