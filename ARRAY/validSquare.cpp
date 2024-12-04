#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

// The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

// A valid square has four equal sides with positive length and four equal angles (90-degree angles).

 

// Example 1:

// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: true
// Example 2:

// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
// Output: false
// Example 3:

// Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
// Output: true

    int getLength(pair<int,int> x,pair<int,int> y) {
        return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
  
        vector<pair<int,int>> v;
        v.push_back({p1[0],p1[1]});
        v.push_back({p2[0],p2[1]});
        v.push_back({p3[0],p3[1]});
        v.push_back({p4[0],p4[1]});
        sort(v.begin(),v.end());
        //SQUARE: all sides are equal and diagonals are also equal;
        //RHOMBUS: all sides are equal but diagonals maynot be equal;
        int s1= getLength(v[0],v[1]);
        int s2= getLength(v[0],v[2]);
        int s3= getLength(v[1],v[3]);
        int s4= getLength(v[2],v[3]);
        int d1= getLength(v[0],v[3]);
        int d2= getLength(v[1],v[2]);
        if (s1==0 || s2==0 || s3==0 || s4==0 || d1==0 || d2==0)return false;
        if (s1==s2 && s1==s3 && s1==s4 && d1==d2)return true;
        return false;
    }
int main() {
    vector<int> p1 = {0,0};
    vector<int> p2 = {1,1};
    vector<int> p3 = {1,0};
    vector<int> p4 = {0,1};
    cout<<"Square 1: "<<endl;

    bool ans1 = validSquare(p1,p2,p3,p4);
    if(ans1) {
        cout<<"points are forming a valid square"<<endl;
    }
    else {
        cout<<"points not are forming a valid square"<<endl;
    }


    vector<int> k1 = {0,0};
    vector<int> k2 = {1,1};
    vector<int> k3 = {1,0};
    vector<int> k4 = {0,12};
    cout<<"Square 2: "<<endl;
    bool ans2 = validSquare(k1,k2,k3,k4);
    if(ans2) {
        cout<<"points are forming a valid square"<<endl;
    }
    else {
        cout<<"points not are forming a valid square"<<endl;
    }



}