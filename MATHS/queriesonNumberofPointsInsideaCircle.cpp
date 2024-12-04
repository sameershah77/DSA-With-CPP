#include<iostream>
#include<vector>
using namespace std;


// You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.

// You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.

// For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.

// Return an array answer, where answer[j] is the answer to the jth query.

 

// Example 1:


// Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
// Output: [3,2,2]
// Explanation: The points and circles are shown above.
// queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.
// Example 2:


// Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
// Output: [2,3,2,4]
// Explanation: The points and circles are shown above.
// queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.



    bool isInCircle(vector<int> & circle, vector<int> & point) {
        double distanceToCenter = sqrt(pow(point[0] - circle[0], 2) + pow(point[1] - circle[1], 2));

        if (distanceToCenter <= static_cast<double>(circle[2])) return true;
        return false;
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int circles = queries.size();
        int pointsSize = points.size();
        vector<int> ans(circles, 0);

        for (int i = 0; i < circles; i++) {
            for (int j = 0; j < pointsSize; j++) {
                if (isInCircle(queries[i], points[j]) == true) ans[i]++;
            }
        }
        return ans;
    }
int main() {

    vector<vector<int>> points = {{1,3},{3,3},{5,3},{2,2}}; 
    vector<vector<int>> queries = {{2,3,1},{4,3,1},{1,1,2}};

    vector<int> ans = countPoints(points,queries);

    cout<<"Answer is "<<endl;
    for(auto val: ans) {
        cout<<val<<" ";
    }
    cout<<endl;

}