#include<iostream>
using namespace std;
void reverse(int arr[],int n) {

 int start = 0;
 int end = n-1;
    while (start<=end) {
        swap(arr[start],arr[end]);
        start ++;
        end --;

    }


}
void printArray(int arr[],int n) {
    int ans =0;
     for (int i =0;i <n;i ++) {
        cout<< arr[i] <<" " ;
        ans = ans + arr[i];
     }
     cout << endl; 
     cout<<ans<<endl;


}


int main() {

    int even [6] = {2,5,7,4,0,6,};
    int odd [5] = {2,4,9,9,0};
    
    reverse(even,6);
    reverse(odd,5);
    printArray(even,6);
    printArray(odd,5);

}