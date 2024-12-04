#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void findMedian(priority_queue<int>& maxHeap,priority_queue<int,vector<int>,greater<int>>& minHeap,double &median, int element) {
    if(maxHeap.size() == minHeap.size()) {
        if(element > median) {
            minHeap.push(element);
            median = minHeap.top();
        }
        else {
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }
    else if(maxHeap.size() > minHeap.size()) {

        if(element > median) {
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
        else {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }

    }
    else{
        //maxHeap.size() < minHeap.size()

        if(element > median) {
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
        else {
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2.0;
        }
    }
}

int main() {
    int arr[] = {4,2,5,6,8,9,4,3,1,7};
    int n = 10;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    double median = 0;
    for(int i=0; i<n; i++) {
        int element = arr[i];
        findMedian(maxHeap,minHeap,median,element);
        for(int j=0; j<=i; j++) {
            cout<<arr[j]<<" ";
        }
        cout<<" -> Median is "<<median<<endl;
    }


}