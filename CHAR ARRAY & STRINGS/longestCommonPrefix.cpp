#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".
    string longestCommonPrefix(vector<string>& strs) {
        string ans  = "";
        int x = 0;
        while(true) {
            char currChar = 0;
            for(auto str:strs) {
                if(x>=str.size()) {
                    currChar = 0;
                    break;
                }
                if(currChar == 0) {
                    currChar = str[x];
                }
                else if(currChar != str[x]) {
                    currChar = 0;
                    break;
                }
            }
            if(currChar==0) {
                break;
            }
            ans.push_back(currChar);
            x++;
        }
        return ans;
    }
int main() {
    vector<string> strs = {"flower","flow","flight"};
    string ans  = longestCommonPrefix(strs);

    cout<<"Longest common prefix is ' "<<ans<<" '"<<endl;

}