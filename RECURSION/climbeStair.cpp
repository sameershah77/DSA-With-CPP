#include<iostream>
using namespace std;
int climbeStair(int n) {
    // base case
    if(n==0 || n==1) {
        return 1;
    }
    if(n==2) {
        return 2;
    }
    int ans = climbeStair(n-1) + climbeStair(n-2);
    return ans;
}

int main() {
    int n;
    cout<<"Enter the number of Stair :- ";
    cin>>n;
    int ans = climbeStair(n);

    cout<<"Total number of ways to reach Top Stair is "<<ans<<endl;
    
}