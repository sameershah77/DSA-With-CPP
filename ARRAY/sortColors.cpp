#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        int temp = nums[minIndex];
        nums[minIndex] = nums[i];
        nums[i] = temp;
    }
}

int main () {
    int n;
    cout<<"Enter the size of array :- ";
    cin>>n;
       vector<int> arr(n);
        cout<<"Please insert only '0' , '1' or '2' "<<endl;
       cout<<"Insert elements in array :- "<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<endl;
    cout<<"Your Original array is :- "<<endl;
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    sortColors(arr);






    cout<<"Your sorted colored array is :- "<<endl;
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    
}