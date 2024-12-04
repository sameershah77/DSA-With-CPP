#include<iostream>
#include<queue>
using namespace std;

int main() {
    
    cout<<endl<<endl<<endl;

    cout<<"Max Heap"<<endl<<endl;
    
    
    
    //it is a max heap
    priority_queue<int> pqMax;

    pqMax.push(3);                              //      10
    pqMax.push(4);                              //    7    4
    pqMax.push(10);                             //  3
    pqMax.push(7);
    cout<<"Size of heap is "<<pqMax.size()<<endl;
    cout<<"Top element is "<<pqMax.top()<<endl;
    pqMax.pop();
    cout<<"Top element is "<<pqMax.top()<<endl;
    pqMax.pop();
    pqMax.pop();
    pqMax.pop();


    if(pqMax.empty()) {
        cout<<"Max heap is empty"<<endl;
    }
    else {
        cout<<"Max heap is not empty"<<endl;
    }


    cout<<endl<<endl<<endl;

    cout<<"Min Heap"<<endl<<endl;


    //it is a Min heap
    priority_queue<int,vector<int>,greater<int>> pqMin;

    pqMin.push(3);                                     //       3
    pqMin.push(4);                                     //     4   7
    pqMin.push(10);                                    //   10
    pqMin.push(7);
    cout<<"Size of heap is "<<pqMin.size()<<endl;
    cout<<"Top element is "<<pqMin.top()<<endl;
    pqMin.pop();
    cout<<"Top element is "<<pqMin.top()<<endl;
    pqMin.pop();
    pqMin.pop();
    pqMin.pop();


    if(pqMin.empty()) {
        cout<<"Min heap is empty"<<endl;
    }
    else {
        cout<<"Min heap is not empty"<<endl;
    }

    
}