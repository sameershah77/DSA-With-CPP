#include<iostream>
#include<vector>
#include<string.h>
using namespace std;



void solve(vector<string>& ans,int rem_open,int rem_close,int used_open,int used_close,string output) {
    if(rem_close==0 && rem_open==0) {
        ans.push_back(output);
        return;
    }

    //including open bracket
    if( rem_open > 0) {

        // use this is if not want to add ( in output in recursive call
        // output.push_back('(');
        solve(ans,rem_open-1,rem_close,used_open+1,used_close,output+"(");
        // output.pop_back();
    }
    //including open bracket

        if(used_open > used_close) {
        // use this is if not want to add ) in output in recursive call
        // output.push_back(')');
        solve(ans,rem_open,rem_close-1,used_open,used_close+1,output+")");
        // output.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        int rem_open = n;
        int rem_close = n;
        int used_open = 0;
        int used_close = 0;
        string output = "";
        solve(ans,rem_open,rem_close,used_open,used_close,output);
        return ans;
    }

int main() {

    int n;
    cout<<"Enter number of pairs of brackets :- ";
    cin>>n;
    vector<string> str = generateParenthesis(n);

    cout<<"Following is the valid possible generated parenthesis "<<endl;
    for(int i=0;i<str.size();i++) {
        cout<<str[i]<<endl;
    }



}