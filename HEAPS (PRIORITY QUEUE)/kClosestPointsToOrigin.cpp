#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

// Example 1:


// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.
class Info{
    public:
    int x;
    int y;
    int diff;
    Info(int diff,int x,int y) {
        this->x = x;
        this->y = y;
        this->diff = diff;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b) {
        return a->diff < b->diff;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        

        int row = points.size();
        int col = points[0].size();
        vector<vector<int>> ans;

        priority_queue<Info*,vector<Info*>,compare> maxHeap;
        for(int i=0; i<k; i++) {
                int x1 = 0;
                int y1 = 0;
                int x2 = points[i][0];
                int y2 = points[i][1];
                int diff = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                Info* temp = new Info(diff,x2,y2);
                maxHeap.push(temp);
        }


        for(int i=k; i<row; i++) {
                int x1 = 0;
                int y1 = 0;
                int x2 = points[i][0];
                int y2 = points[i][1];
                int diff = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                Info* temp = new Info(diff,x2,y2);

            if(maxHeap.top()->diff >= diff) {
                cout<<maxHeap.top()->diff<<endl;
                maxHeap.pop();
                maxHeap.push(temp);
            } 
        }
        while(k--) {
            Info* temp = maxHeap.top();
            maxHeap.pop();
            int x = temp->x;
            int y = temp->y;
            vector<int> arr;
            arr.push_back(x);
            arr.push_back(y);
            ans.push_back(arr);
        }
        return ans;
    }
int main() {
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k=2;

    vector<vector<int>> ans = kClosest(points,k);

    cout<<"The "<<k<<" closest points to origin are :- "<<endl;
    for(auto val: ans) {
        for(auto i:val) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    



}