#include<iostream>
#include<vector>
using namespace std;

int main () {
    vector<int> arr = {-1,2,4,-1,4,-5,-3,7,-6,3,-3,-4,-2};
    int start =0;
    int end = arr.size()-1;
    int i=0;
    cout<<"Original Array "<<endl;
     for(auto val :arr) {
        cout<<val<<" ";
    }
    cout<<endl;
    int count = 1;
    while (i != end) {
        if(arr[i]<0) {
            swap(arr[start],arr[i]);
            i++;
            start++;
            count ++;
        }
        else {
            swap(arr[end],arr[i]);
            end--;
            
        }
    } 
    cout<<endl;
    cout<<"After seperating "<<endl;

    for(auto val :arr) {
        cout<<val<<" ";
    }
    cout<<endl;
  
    vector<int> brr;
    for(int k=0;k<arr.size();k++) {
        if(arr[k] > 0) {
            brr.push_back(arr[k]);
        }
    }

    

        vector<int> crr;
    for(int k=0;k<arr.size();k++) {
        if(arr[k] < 0) {
            crr.push_back(arr[k]);
        }
    }




 int s = 0;
 int e = brr.size()-1;
    while (s<=e) {
        swap(brr[s],brr[e]);
        s ++;
        e --;

    }



    vector<int> ans;
 for(int z=0;z<brr.size();z++) {
        ans.push_back(brr[z]);
    }

    for(int l=0;l<crr.size();l++) {
        ans.push_back(crr[l]);
    }
    cout<<"After maintaining correct order of positive number and moving negative number end of the array :- "<<endl;


    for(auto val :ans) {
        cout<<val<<" ";
    }







}