#include<iostream>
#include<queue>
using namespace std;


void reverse(queue<int> q) {
    if(q.empty() == true) {
        return;
    }


    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);

    return;
}
int main() {
    queue<int> q;


    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    //initially queue is 10,20,30,40,50

    reverse(q);


    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

}