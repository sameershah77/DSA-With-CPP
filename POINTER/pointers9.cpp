#include<iostream>
#include<algorithm>
using namespace std;
void solve(int *arr){
   
    cout<<sizeof(arr)<<endl;//4/8/16 depending upon system architechture 
    // arr paas nahi hua hai pointer paas hua hai array ka iss liye 

        cout<<"arr : "<<arr<<endl;
    cout<<"&arr : "<<&arr<<endl;

    arr[3]=50;



}
int main() {
    int arr[20] = {1,2,3,4,5,6,7};
    cout<<"Inside main function"<<endl;

    cout<<sizeof(arr)<<endl;//20*4 = 80
    cout<<"arr : "<<arr<<endl;
    cout<<"&arr : "<<&arr<<endl;    

    for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";

    }
    cout<<endl<<endl<<endl;
    cout<<"Inside solve function"<<endl;

    solve(arr);

    cout<<"Again inside main function : "<<endl;
      for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";

    }
}