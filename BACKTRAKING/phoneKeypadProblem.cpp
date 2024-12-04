#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

// T.C O(4^n)   S.C O(4^n)

    void solve(vector<string>& ans,string digits,vector<string>& mapping,int index,string output) {
        if(index>=digits.size()) {
            ans.push_back(output);
            return;
        }

        int digit = digits[index]-'0';
        string value = mapping[digit];

        for(int i=0;i<value.size();i++) {
            output.push_back(value[i]);
            solve(ans,digits,mapping,index+1,output);
            output.pop_back();
        }
    }


    void letterCombinations() {
        string digits = "23";
        int index=0;
        vector<string> ans;

        vector<string> mapping(9);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        string output="";
        solve(ans,digits,mapping,index,output);

        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
 
        
    }


