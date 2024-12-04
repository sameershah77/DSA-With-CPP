#include<iostream>
#include<vector>
#include<sorting>
#include<queue>
using namespace std;

// Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

// A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

// Note that points on the edge of a vertical area are not considered included in the area.

 

// Example 1:

// ​
// Input: points = [[8,7],[9,9],[7,4],[9,7]]
// Output: 1
// Explanation: Both the red and the blue area are optimal.
// Example 2:

// Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
// Output: 3

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        // Using Heap
        priority_queue<int> maxHeap;

        for(auto val: points) {
            maxHeap.push(val[0]);
        }

        int maxDiff = 0;

        while(maxHeap.size() > 1) {
            int top = maxHeap.top();
            maxHeap.pop();
            
            int diff = top - maxHeap.top();
            if(diff == 0) {
                continue;
            }
            else {
                diff = top - maxHeap.top();
                maxDiff = max(maxDiff, diff);
            }
        }
        return maxDiff;

        // using Sorting 

        // sort(points.begin(), points.end());
        // int maxDiff = 0;
        // for(int i=1; i<points.size(); i++) {
        //     maxDiff = max(maxDiff, points[i][0] - points[i-1][0]);
        // }
        // return maxDiff;

    }
    
int main() {

    vector<vector<int>> points= {{8,7},{9,9},{7,4},{9,7}};

    cout<<"Answer is "<<maxWidthOfVerticalArea(points)<<endl;

}