#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
 
    cout<<"Size of queue is "<<q.size()<<endl;

    q.pop();

    cout<<"Size of queue is "<<q.size()<<endl;

    cout<<"Front element is "<<q.front()<<endl;
    cout<<"Back element is "<<q.back()<<endl;

    if(q.empty()) {
        cout<<"Queue is empty"<<endl;
    }
    else {
        cout<<"Queue is not empty"<<endl;
    }
    cout<<"Elements in Queue is "<<endl;
    while(q.empty() != true) {
        cout<<q.front()<<" ";
        q.pop();
    }

}