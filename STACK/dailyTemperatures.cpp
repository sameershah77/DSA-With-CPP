#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        
        for(int i = 0; i < temperatures.size(); ++i){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }



int main() {

    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> ans = dailyTemperatures(temperatures);

    cout<<"Answer is "<<endl;

    for(auto val: ans) {
        cout<<val<<" ";
    }
    cout<<endl;

}