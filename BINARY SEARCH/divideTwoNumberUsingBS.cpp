#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int divide(int dividend,int divisor) {
    long long int s=0;
    long long int e=abs(dividend);
    long long int mid = s + (e-s)/2;
    int ans =-1;

    if(dividend == INT_MIN && divisor == -1) {
        return INT_MAX ;
    }

    if(dividend == INT_MIN && divisor == 1) {
        return INT_MIN ;
    }

    while (s<=e) {
        if(abs(mid*divisor) == abs(dividend)) {
            ans = mid;
            
        }
        if (abs(mid*divisor) > abs(dividend)) {
            e=mid -1;
        } else {
            ans = mid;
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    if((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0) ) {
        return ans;
    }
    else {
        return -ans;
    }
      
}



int main() {
    int dividend;
    cout<<"Enter Dividend :- ";
    cin>>dividend;

    int divisor;
    cout<<"Enter Divisor :- ";
    cin>>divisor;
    int ans = divide(dividend,divisor);
    cout<<"Answer is "<<ans<<endl;
}