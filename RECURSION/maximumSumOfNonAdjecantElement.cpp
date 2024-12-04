#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void solve(vector<int> arr,int i,int sum,int& maxi) {

    if(i>=arr.size()) {
        maxi = max(maxi,sum);

        return;
    } 


    //include
    solve(arr,i+2,sum+arr[i],maxi);

    //exclude
    solve(arr,i+1,sum,maxi);

}



int main() {
    vector<int> arr = {1,2,3,5,4};

    int i=0;
    int maxi=INT_MIN;
    int sum=0;
    
    solve(arr,i,sum,maxi);
    if(maxi==INT_MIN) {
        maxi=0;
    }

    cout<<"Maximum sum is "<<maxi<<endl;
  

}