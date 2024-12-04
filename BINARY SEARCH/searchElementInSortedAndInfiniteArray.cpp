#include<iostream>
#include<vector>
using namespace std;

void findRangeInStream(vector<int>& arr, int key, int& start, int& end) {
    int val = arr[start];
    while(key > val) {
        start = end;
        end = end*2;
        val = arr[end];
    }
}

int binarySearch(vector<int>& arr, int start, int end, int key) {
    while(start < end) {
        int mid = start + (end-start)/2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,2,5,8,11,15,18,23,28,30,37,47,49,50,53,58};
    int key = 49;

    int start = 0;
    int end = 1;
    findRangeInStream(arr,key, start, end);

    int ans = binarySearch(arr,start,end,key);

    if(ans == -1) {
        cout<<"Key not found"<<endl;
    }
    else{
        cout<<"key found at "<<ans<<endl;
    }
}