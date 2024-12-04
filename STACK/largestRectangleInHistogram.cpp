#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

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

        int maxArea = INT_MIN;

        int size = heights.size();

        for(int i=0; i<size; i++) {
            int length = heights[i];

            if(next[i] == -1) {//this is very important condition
                next[i] = size;
            }

            int width = next[i] - previous[i] - 1;

            int area = length * width;

            maxArea = max(maxArea,area);
        }

        return maxArea;
    }



int main() {
    vector<int> arr1 = {2,1,5,6,2,3};
    int ans1 = largestRectangleArea(arr1);


    vector<int> arr2 = {2,4};
    int ans2 = largestRectangleArea(arr2);

    vector<int> arr3 = {2,1,7,6,2,3};
    int ans3 = largestRectangleArea(arr3);

    cout<<endl<<endl<<"Largest area of ractangle in Histogram in ";
    for(auto val: arr1) {
        cout<<val<<" ";
    }
    cout<<" is "<<ans1;


    cout<<endl<<endl<<"Largest area of ractangle in Histogram in ";
    for(auto val: arr2) {
        cout<<val<<" ";
    }
    cout<<" is "<<ans2;


    cout<<endl<<endl<<"Largest area of ractangle in Histogram in ";
    for(auto val: arr3) {
        cout<<val<<" ";
    }
    cout<<" is "<<ans3;


}