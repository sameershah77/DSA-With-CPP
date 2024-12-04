#include<iostream>
using namespace std;


class Heap{
    public:
    int size;
    int arr[100];


    Heap() {
        size = 0;
    }
    //T.C. logN
    void insert(int data) {
        size = size+1;
        int index = size;
        arr[index] = data;

        while(index > 1) {
            int parantIndex = index/2;
            if(arr[index] > arr[parantIndex]) {
                swap(arr[index],arr[parantIndex]);
                index = parantIndex;
            }
            else {
                break;
            }
        }

    }


    //T.C. logN
    void remove() {
        //replace root value with last value
        arr[1] == arr[size];
        //remove last value
        size--; 
 
        //place root value at its correct position

        int index = 1;
        while(index < size) {
            int leftChildIndex = 2*index;
            int rightChildIndex = 2*index+1;

            int largest = index;

            if(leftChildIndex < size && arr[largest] < arr[leftChildIndex]) {
                largest = leftChildIndex;
            }
            if(rightChildIndex < size && arr[largest] < arr[rightChildIndex]) {
                largest = rightChildIndex;
            }

            if(largest == index) {
                break;
                return;
            } 
            else {
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
    }
};
int main() {
    // Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 20;
    // h.arr[4] = 40;
    // h.arr[5] = 45;
    // h.size = 5;

    // cout<<"Printing heap"<<endl;
    // for(int i=0; i<=h.size; i++) {
    //     cout<<h.arr[i]<<" ";
    // }
    // cout<<endl;
    // h.insert(120);

    // cout<<"Printing heap after insertion"<<endl;
    // for(int i=0; i<=h.size; i++) {
    //     cout<<h.arr[i]<<" ";
    // }


    cout<<endl<<endl<<"ANother heap"<<endl;

    Heap h2;
    h2.insert(10);
    h2.insert(20);
    h2.insert(30);
    h2.insert(40);
    h2.insert(50);
    h2.insert(60);

    for(int i=0; i<=h2.size; i++) {
        if(i==0) {
            cout<<-1<<" ";    
        }
        else{
            cout<<h2.arr[i]<<" ";
        }
        
    }
    cout<<endl;


                       
}