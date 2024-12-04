#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

// For each index i, names[i] and heights[i] denote the name and height of the ith person.

// Return names sorted in descending order by the people's heights.

 

// Example 1:

// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.
// Example 2:

// Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
// Output: ["Bob","Alice","Bob"]
// Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

class Object{
    public: 
    string name;
    int height;

    Object(string name, int height) {
        this->name = name;
        this->height = height;
    }

};

bool Comp(Object* a, Object* b) {
    return a->height > b->height;
}



    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<Object*> result;
        int n = names.size();
        for(int i=0; i<n; i++) {
            Object* temp = new Object(names[i],heights[i]);
            result.push_back(temp);
        }

        sort(result.begin(),result.end(),Comp);

        vector<string> ans;

        for(auto val: result) {
            ans.push_back(val->name);
        }
        return ans;
    }

int main() {
    vector<string> names = {"Mary","John","Emma"}; 
    vector<int> heights = {180,165,170};

    vector<string> ans = sortPeople(names,heights);
    cout<<endl;
    cout<<"Answer is "<<endl; 

    for(auto val: ans) {
        cout<<val<<" ";
    }
    cout<<endl;
}