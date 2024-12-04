#include<iostream>
#include<vector>
using namespace std;

int missingElement(vector<int> arr) {
    int digit;
    int diff;
    for(int i=0;i<arr.size();i++) {
        if(arr[i] != i+1)  {
            digit=i;
            diff = arr[i-1]-arr[i-2];
            break;
        }
    }
    return digit + diff;
}

int main() {
    vector<int> arr={1,2,3,4,5,6,8,9};
    int ans = missingElement(arr);
    cout<<"Missing element is "<<ans;
}