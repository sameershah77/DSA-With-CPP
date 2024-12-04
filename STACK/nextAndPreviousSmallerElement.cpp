#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> previousSmallerElement(vector<int>& input) {

    vector<int> ans2(input.size());
    stack<int> st;
    st.push(-1);

        //left to right
        for(int i=0; i<input.size(); i++) {
            int currElement =  input[i];

            //stack me top ka element bada hai jab tak currElement se
            while(st.top() >= currElement) {
                st.pop();
            }

            //chota element mill chuka hai currElement
            ans2[i] = st.top();


            //push kardo currElement ko stack me
            st.push(currElement);
        }

        return ans2;
}


vector<int> nextSmallerElement(vector<int>& input) {

    vector<int> ans1(input.size());
    stack<int> st;
    st.push(0);

        //right to left
        for(int i=input.size()-1; i>=0; i--) {
            int currElement =  input[i];

            //stack me top ka element bada hai jab tak currElement se
            while(st.top() >= currElement) {
                st.pop();
            }

            //chota element mill chuka hai currElement
            ans1[i] = st.top();


            //push kardo currElement ko stack me
            st.push(currElement);
        }

        return ans1;
}

int main() {

    vector<int> input = {2,1,5};

    vector<int> ans1 = nextSmallerElement(input);

    vector<int> ans2 = previousSmallerElement(input);


    cout<<"Input array is " <<endl;
    for(auto val : input) {
        cout<<val<<" ";
    }


    cout<<endl<<"Next smaller element is "<<endl;
    for(auto val : ans1) {
        cout<<val<<" ";
    }


    cout<<endl<<"Previous smaller element is "<<endl;
    for(auto val : ans2) {
        cout<<val<<" ";
    }




    cout<<endl;
}