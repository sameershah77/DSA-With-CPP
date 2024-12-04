#include<iostream>
#include<vector>
using namespace std;


// An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

// Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

// Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

 

// Example 1:

// Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
// Output: true
// Example 2:

// Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
// Output: false
// Example 3:

// Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
// Output: false



    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1 = rec1[0];
        int ay1 = rec1[1];

        int ax2 = rec1[2];
        int ay2 = rec1[3];


        int bx1 = rec2[0];
        int by1 = rec2[1];

        int bx2 = rec2[2];
        int by2 = rec2[3];

        int commonX1 = max(ax1,bx1);
        int commonY1 = max(ay1,by1);

        int commonX2 = min(ax2,bx2);
        int commonY2 = min(ay2,by2);

        long long int AreaLength = commonX2 - commonX1;
        long long int AreaHeigth = commonY2 - commonY1;

        long long int area = 0;
        if(AreaLength > 0 && AreaHeigth > 0) {
            area = AreaLength*AreaHeigth;
        } 

        return area > 0 ? true : false;
    }
int main() {

    vector<int> rec1 = {0,0,2,2}; 
    vector<int> rec2 = {1,1,3,3};

    if(isRectangleOverlap(rec1,rec2)) {
        cout<<"Both rectangles are overlaping"<<endl;
    }
    else {
        cout<<"they are not overlaping"<<endl;
    }

}