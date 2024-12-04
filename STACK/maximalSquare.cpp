#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:


// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0


    vector<int> previousSmallerElementsIndex(vector<int>& input) {

        vector<int> ans2(input.size());
        stack<int> st;
        st.push(-1);

            //left to right
            for(int i=0; i<input.size(); i++) {
                int currElement =  input[i];

                //stack me top ka element bada hai jab tak currElement se
                while(st.top() != -1 && input[st.top()] >= currElement) {
                    st.pop();
                }

                //chota element mill chuka hai currElement
                ans2[i] = st.top();


                //push kardo currElement ko stack me
                st.push(i);
            }

            return ans2;
    }


    vector<int> nextSmallerElementsIndex(vector<int>& input) {

        vector<int> ans1(input.size());
        stack<int> st;
        st.push(-1);

            //right to left
            for(int i=input.size()-1; i>=0; i--) {
                int currElement =  input[i];

                //stack me top ka element bada hai jab tak currElement se
                while(st.top() != -1 && input[st.top()] >= currElement) {
                    st.pop();
                }

                //chota element mill chuka hai currElement
                ans1[i] = st.top();


                //push kardo currElement ko stack me
                st.push(i);
            }

            return ans1;
    }
    int largestRectangleArea(vector<int>& heights) {
        

        vector<int> next = nextSmallerElementsIndex(heights);

        vector<int> previous = previousSmallerElementsIndex(heights);

        int maxArea = 0;

        int size = heights.size();

        for(int i=0; i<size; i++) {
            int length = heights[i];

            if(next[i] == -1) {//this is very important condition
                next[i] = size;
            }

            int width = next[i] - previous[i] - 1;

            if(length<width) {
                int area = length*length;
                maxArea = max(maxArea,area);
            }
            else {
                int area = width*width;
                maxArea = max(maxArea,area);
            }
        }

        return maxArea;
    }

    int maximalSquare(vector<vector<int>>& v) {


        int row = v.size();
        int col = v[0].size();



        
        int area = largestRectangleArea(v[0]);
        for(int i=1; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(v[i][j] != 0) {
                    v[i][j] += v[i-1][j];
                }
                else {
                    v[i][j] = 0;
                }
            }

            
            area = max(area,largestRectangleArea(v[i]));

        }
        return area;
    }


    int main() {

        vector<vector<int>> arr =  {{1,0,1,0,0},
                                    {1,0,1,1,1},
                                    {1,1,1,1,1},
                                    {1,0,0,1,0}};

        int ans = maximalSquare(arr);

        cout<<"The maximal square area is "<<ans<<endl;


    }
