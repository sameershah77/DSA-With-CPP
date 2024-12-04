 #include<iostream>
using namespace std;

// Implementation of Binary Search;

int binarySearch(int arr[],int size,int key) { 
    
    
    int start = 0;
    int end = size -1;
    
    // int mid = (start + end)/2; Chalaki hai yeh;;
    // iski jagah yeh likhna 

    int mid = start + (end-start)/2;  // To prevent Run time Error;


     while (start <= end) {

         if (arr[mid]==key) {
            return  mid;
        }

        if (key > arr[mid]) {
            start = mid +1;
        } else {

            end = mid -1;
        }
            mid = start + (end - start)/2;
        }
    return -1;   

}

int main() {

       
    int even [6] = {1,5,8,10,12,14};
    int odd [9] = {1,2,3,5,6,8,9,10,45};


    int evenIndex = binarySearch(even,6,1);
    int oddIndex = binarySearch(odd,9,10);



    cout<< "1 is in the index of " << evenIndex << endl;

    cout<< "10 is in the index of " << oddIndex << endl;


}