#include<iostream>
#include<vector>
using namespace std;

    //normal recursion T.C. O(2^N)  S.C. O(N)
    int recursion(int n) {
        if(n==0 || n==1) {
            return n;
        }

        int fibN = recursion(n-1) + recursion(n-2);
        return fibN;
    }

    //top down approach  T.C. O(N)  S.C. O(N + N) = S.C. O(N)
    int solve(int n, vector<int>& dp) {
        if(n == 0 || n == 1) {
            return n;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        dp[n] = solve(n-1,dp) + solve(n-2,dp);
        return dp[n];
    }
    int topDown(int n) {
        vector<int> dp(n+1,-1);
        int ans = solve(n,dp);
        return ans;
    }

    
    //bottom up approach (Tabulation method)  T.C. O(N)  S.C. O(N)

    int bottomUp(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;

        if(n==0) {
            return dp[0];
        }

        for(int i=2 ; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }


    //space optimisation  T.C. O(N)  S.C. O(1)
    int spaceOptimization(int n) {

        int nMinusTwo = 0;
        int nMinusOne = 1;
        int curr;
        if(n==0) {
            return nMinusTwo;
        }

        for(int i=2 ; i<=n; i++) {
            curr = nMinusOne + nMinusTwo;
            nMinusTwo = nMinusOne;
            nMinusOne = curr;
        }

        return curr;
    }


int main() {
    int n;
    cout<<"ENter number to calculate fibonacci : ";
    cin>>n;


    cout<<"Using Rescursion"<<endl;

    cout<<"Your "<<n<<"th Fibonacci Number is "<<recursion(n)<<endl;

    cout<<endl<<endl;

    cout<<"Using top down"<<endl;

    cout<<"Your "<<n<<"th Fibonacci Number is "<<topDown(n)<<endl;

    cout<<endl<<endl;

    cout<<"Using bottom up (tabulation method)"<<endl;

    cout<<"Your "<<n<<"th Fibonacci Number is "<<bottomUp(n)<<endl;

    cout<<endl<<endl;

    cout<<"Space optimization"<<endl;

    cout<<"Your "<<n<<"th Fibonacci Number is "<<spaceOptimization(n)<<endl;

}