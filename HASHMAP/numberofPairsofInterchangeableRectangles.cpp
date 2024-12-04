#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.

// Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).

// Return the number of pairs of interchangeable rectangles in rectangles.

 

// Example 1:

// Input: rectangles = [[4,8],[3,6],[10,20],[15,30]]
// Output: 6
// Explanation: The following are the interchangeable pairs of rectangles by index (0-indexed):
// - Rectangle 0 with rectangle 1: 4/8 == 3/6.
// - Rectangle 0 with rectangle 2: 4/8 == 10/20.
// - Rectangle 0 with rectangle 3: 4/8 == 15/30.
// - Rectangle 1 with rectangle 2: 3/6 == 10/20.
// - Rectangle 1 with rectangle 3: 3/6 == 15/30.
// - Rectangle 2 with rectangle 3: 10/20 == 15/30.
// Example 2:

// Input: rectangles = [[4,5],[7,8]]
// Output: 0
// Explanation: There are no interchangeable pairs of rectangles.

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int> mp;
        long long result = 0;
        for(auto val: rectangles) {
            double ratio = (double)val[0]/val[1];
            if(mp.find(ratio) != mp.end()) {
                result += mp[ratio];
            }
            mp[ratio]++;
        }
        return result;
    }

int main() {

    vector<vector<int>> rectangles = {{4,8},{3,6},{10,20},{15,30}};

    cout<<"Answer is "<<interchangeableRectangles(rectangle);

}