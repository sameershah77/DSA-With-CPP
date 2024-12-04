#include<iostream>
using namespace std;

// Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

// The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

// The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

 

// Example 1:

// Rectangle Area
// Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
// Output: 45
// Example 2:

// Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
// Output: 16
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int boxOneLenght = ax2 - ax1;
        int boxOneHeigth = ay2 - ay1;

        int boxTwoLenght = bx2 - bx1;
        int boxTwoHeigth = by2 - by1;

        int areaOfBoxOne = boxOneLenght*boxOneHeigth;
        int areaOfBoxTwo = boxTwoLenght*boxTwoHeigth;

        int commonX1 = max(ax1,bx1);
        int commonY1 = max(ay1,by1);

        int commonX2 = min(ax2,bx2);
        int commonY2 = min(ay2,by2);

        int commonAreaLength = commonX2 - commonX1;
        int commonAreaHeigth = commonY2 - commonY1;
        int commonArea = 0;

        if(commonAreaLength > 0 && commonAreaHeigth > 0) {
            commonArea = commonAreaLength*commonAreaHeigth;
        } 

        return areaOfBoxOne + areaOfBoxTwo - commonArea;
    }
int main() {

    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;

    int ans = computeArea(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2);

    cout<<"Total area occupied by both Rectangle's are "<<ans<<" unit square"<<endl;

}