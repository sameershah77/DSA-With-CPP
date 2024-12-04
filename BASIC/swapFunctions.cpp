#include <iostream.>
using namespace std;

void swapUsingTwoPointerApproch(int arr[], int n) {

    int start = 0;
    int end = n - 1;
    while (start <= end) {
        
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
     
void swapUsingXorOperator(int arr[], int n) {

    int start = 0;
    int end = n - 1;
    while (start < end) {

       arr[start] ^= arr[end];
       arr[end] ^= arr[start];
       arr[start] ^= arr[end];
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int n1;
    int n2;
    cout<<"Enter the size of firts array :- ";
    cin>>n1;
    cout<<endl;
    cout<<"Enter the size of second array :- ";
    cin>>n2;

    int arr1[n1];
    int arr2[n2];

    cout<<endl;

    cout<<"Enter the Elements of firts array :- ";
    cout<<endl;

    for (int i=0;i<n1; i++) {
        cin>>arr1[i];

    }
    
      cout<<"Enter the Elements of second array :- ";
      cout<<endl;
    for (int i=0;i<n2; i++) {
        cin>>arr2[i];
    }

        cout <<"swapUsingTwoPointerApproch :- ";

        swapUsingTwoPointerApproch(arr1,n1);
        printArray(arr1,n1);
        
        cout <<"swapUsingXorOperator :- ";

        swapUsingXorOperator(arr2,n2);
        printArray(arr2,n2);
  
  return 0;

}