#include<iostream>
#include<vector>
using namespace std;


    int spaceOptimization(int &n) {

        int nMinusTwo = 1;
        int nMinusOne = 2;
        int curr;
        if(n==1) {
            return nMinusTwo;
        }
        if(n==2) {
            return nMinusOne;
        }

        for(int i=3 ; i<=n; i++) {
            curr = nMinusOne + nMinusTwo;
            nMinusTwo = nMinusOne;
            nMinusOne = curr;
        }

        return curr;
    }
    int climbStairs(int n) {
        return spaceOptimization(n);
    }

int main() {
    int n;
    cout<<"ENter number : ";
    cin>>n;

    cout<<"There are "<<climbStairs(n)<<" ways to reach top "<<endl;

}