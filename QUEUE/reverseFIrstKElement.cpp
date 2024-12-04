#include<iostream>
#include<queue>
using namespace std;
void reverse(queue<int> &q,int k) {
    if(k == 0) {
        return;
    }
    int x = q.front();
    q.pop();
    reverse(q,k-1);
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
    q.push(60);
    q.push(70);
    q.push(80);
    int k=4;
    //initially queue is 10,20,30,40,50
    reverse(q,k);
    int n = q.size()-k;
    while(n != 0) {
        int temp = q.front();
        q.pop();
        q.push(temp);
        n--;
    }

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

}