#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
    bool comp1(char first,char second) {
        return first>second;
    }


     bool comp2(int first,int second) {
        return first>second;
    }



    int main() {
        string str = "sameer";

        cout<<"Before custom comparator "<<endl;
        sort(str.begin(),str.end());
        cout<<str<<endl;
        cout<<"After custom comparator "<<endl;
        sort(str.begin(),str.end(),comp1);
        cout<<str<<endl;

        vector<int> arr = {4,2,5,1,6,8};
         cout<<"Before custom comparator "<<endl;
         sort(arr.begin(),arr.end());

         for(auto var:arr) {
            cout<<var<<" ";

        }
        cout<<endl;

        cout<<"After custom comparator "<<endl;
        sort(arr.begin(),arr.end(),comp2);
        for(auto var:arr) {
            cout<<var<<" ";

        }


    }



