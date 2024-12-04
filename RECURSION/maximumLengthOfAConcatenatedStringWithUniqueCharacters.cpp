#include<iostream>
#include<vector>
using namespace std;


// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.
// Example 2:

// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
// Example 3:

// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
// Explanation: The only string in arr has all 26 characters.


    bool compare(vector<int> &selected,string &currString){
        vector<int> selfCheck(26,0);
        for(int i=0;i<currString.size();i++){
            if(selfCheck[currString[i] - 'a'] == 1) return false;
            selfCheck[currString[i] - 'a'] = 1;
        }
        for(int i=0;i<currString.size();i++){
            if(selected[currString[i]-'a'] == 1) return false;
        }
        return true;
    }
    int f(int i,vector<string> &arr,vector<int> &selected,int len){
        if(i == arr.size()){
            return len;
        }
        string currString = arr[i];
        if(compare(selected,currString) == false){
            return f(i+1,arr,selected,len);
        }
        else
        {
            //pick
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 1;
            }
            len += currString.size();
            int op1 = f(i+1,arr,selected,len);
            
            //skip
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 0;
            }
            len -= currString.size();
            int op2 = f(i+1,arr,selected,len);
            
            return max(op1,op2);
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return f(0,arr,selected,0);
    }

    int main() {
        vector<string> arr = {"un","iq","ue"};

        int length = maxLength(arr);
        cout<<"Maximum length is "<<length<<endl;
    }