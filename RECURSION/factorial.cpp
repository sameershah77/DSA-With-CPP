#include<iostream>
using namespace std;
int factorial(int n) {
    // base case
    if(n==1) {
        return 1;
    }
    int ChotiProblem = factorial(n-1);
    int badiProblem = ChotiProblem*n;
    return badiProblem;

}

int main() {
    int n;
    cout<<"Enter the value of n :- ";
    cin>>n;
    int ans = factorial(n);
    cout<<"Your answer is "<<ans<<endl;
}