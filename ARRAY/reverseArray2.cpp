#include<iostream>
using namespace std;
void reverse(int arr[],int n) {
    //  here is the changes 

    for (int i =0;i < n/2;i ++) {

        int firstVal = arr[i];
        int secondVal = arr[n-i-1];
        arr[i] = secondVal;
        arr[n-i-1] = firstVal;
        
    }
    // 



}
void printArray(int arr[],int n) {
     for (int i =0;i <n;i ++) {
        cout<< arr[i] <<" " ;
     }
     cout << endl; 


}


int main() {

    int even [6] = {1,2,3,4,5,6};
    int odd [5] = {1,2,3,4,5};
    
    reverse(even,6);
    reverse(odd,5);
    printArray(even,6);
    printArray(odd,5);

}