#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[],int start,int end) {
    int pivotIndex=start;
    int count =0;
    for(int i=start+1;i<=end;i++) {
        if(arr[i]<=arr[pivotIndex]) {
            count ++;
        }
    }

    int rightIndex = start+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;

    int i=start;
    int j=end;
    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i]<=arr[pivotIndex]) {
            i++;
        }
        while(arr[j]>arr[pivotIndex]) {
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }


    return pivotIndex;



}

void quickSort(int arr[],int start,int end) {

    if(start>=end) {
        return;
    }   

    //partitioning logic

    int p=partition(arr,start,end);
    //left array
    quickSort(arr,start,p-1);
    //right array
    quickSort(arr,p+1,end);


}

int main() {

  int arr[] = {8,1,3,4,20,50,50,50,50,50,5,1,1,1,1,2,2,2,50,30};
  int n = 20;

  int s = 0;    
  int e = n-1;
  quickSort(arr, s, e);

  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;

}