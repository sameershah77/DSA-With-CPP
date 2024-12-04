#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
    vector<int> factorial(int N){
        // code here
        int carry=0;
        vector<int> ans;
        ans.push_back(1);
        for(int i=2;i<=N;i++) {
            for(int j=0;j<ans.size();j++) {
                int x= ans[j]*i + carry;
                ans[j] = x%10;
                carry = x/10;
            }
            while(carry){
                ans.push_back(carry%10);
                carry = carry/10;
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main() {
    int n;
    cout<<"Enter a number :-";
    cin>>n;
    
    vector<int> ans = factorial(n);
    cout<<"Factorial of "<<n<<" is ";
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<"";
    }

}

