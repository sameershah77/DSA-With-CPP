#include<iostream>
#include<vector>
using namespace std;
// in Binary Search there are three types of problem
// 1. classic or basic direct using BS we can solve
// 2. Using search space like square root of element or divide two number problem
// 3. Using Index based this is the example of third type . it is very important

int oddElement(vector<int> arr) {
    int start = 0;
    int end = arr.size();
    int mid = start+(end-start)/2;
    while(start<=end) {
        if (start == end) {
            return start;//or we can return end also
        }
        if(mid%2==0) {
            if(arr[mid]==arr[mid+1]) {
                start = mid +2;
            }
            else {
                end = mid;
            }
        }
        else {
            if(arr[mid-1]==arr[mid]) {
                start = mid +1;
            }
            else {
                end = mid -1;
            }
        }
        mid = start + (end -start)/2;
    }
    return -1;
}

int main() {
    vector<int> arr = {1,1,4,4,3,7,7,9,9,3,3,8,8,2,2,1,1};
    int ans = oddElement(arr);
    cout<<"The element is "<<arr[ans]<<endl;
}