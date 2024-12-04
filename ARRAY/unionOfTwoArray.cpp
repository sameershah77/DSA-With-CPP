#include<iostream>
#include<vector>
using namespace std;

int main () {
    int sizeArr = 5;
    int sizeBrr = 5;
    int arr[] = {1,2,3,4,5};
    int brr[] = {6,7,8,9,0};

    vector<int> ans;

    for (int i=0;i<sizeArr;i++) {
        ans.push_back(arr[i]);
    } 
    for(int j=0;j<sizeBrr;j++) {
        ans.push_back(brr[j]);
    }

    for(int k=0; k<ans.size();k++) {
        cout<<ans[k]<<" ";
    }
    cout<<endl;
}