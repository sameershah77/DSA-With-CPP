#include<iostream>
using  namespace std;

void swapAlternate(int arr[],int n) {

    for(int i =0;i <n;i +=2) {

        if (i+1<n) {
            // 
           int temp;
           temp = arr[i+1];
           arr[i+1] = arr[i];
           arr[i] = temp;
        //    
        // Or use Swap function
        }
    }

}

void printAlternate(int arr[],int n) {


    for (int i =0;i<n ; i ++) {

            cout<<arr[i] << " " ;

    }
    cout<< endl;
}


int main () {


int even [8] = {2,3,4,5,7,9,0,1};
int odd[5] = {3,6,9,0,1};

swapAlternate(even,8);
printAlternate(even,8);


swapAlternate(odd,5);
printAlternate(odd,5);


}