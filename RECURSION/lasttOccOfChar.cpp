#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;
void solve(string s,char x,int &ans,int i) {
    if(i>=s.size()) {
        return;
    }

    if(s[i]==x) {
        ans = i;
    }

    solve(s,x,ans,i+1);
}

int main() {
    string s;
    cout<<"Enter string : ";
    cin>>s;

    char x;
    cout<<"Enter character : ";
    cin>>x;

    
    int ans = INT_MIN;
     solve(s,x,ans,0);
     cout<<ans<<endl;
}