#include<iostream>
#include<queue>
using namespace std;



    //T.C O(N)      S.C O(N)
    int kthSmallestMinHeap(int arr[], int n, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<n; i++) {
            pq.push(arr[i]);
        }

        while(k > 1) {
            k--;
            pq.pop();
        }

        return pq.top();
    }

    //this is better approach
    //T.C O(NlogK)      S.C O(k)
    int kthSmallestMaxHeap(int arr[], int n, int k) {
        priority_queue<int> pq;
        
        for(int i=0; i<k; i++) {
            pq.push(arr[i]);
        }
        for(int i=k; i<n; i++) {
            if(pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }




int main() {

    int arr[] = {2,6,9,4,5,3,7,13,17};
    int n = 9;
    int k = 3;

    int ans = kthSmallestMaxHeap(arr,n,k);
    cout<<k<<"th smallest element is "<<ans<<endl;


    cout<<endl<<endl;

    int ans2 = kthSmallestMinHeap(arr,n,k);
    cout<<k<<"th smallest element is "<<ans2<<endl;
}