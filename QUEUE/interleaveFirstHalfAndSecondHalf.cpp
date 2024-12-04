#include<iostream>
#include<queue>
using namespace std;
// You are given a queue Q of N integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

 

// Example 1:

// Input:
// N = 4
// Q = {2,4,3,1}
// Output:
// {2,3,4,1}
// Explanation:
// After the mentioned rearrangement of the first half
// and second half, our final queue will be {2,3,4,1}.
 

// Example 2:

// Input:
// N = 2
// Q = {3,5}
// Output:
// {3,5}
// Explanation:
// After the mentioned rearrangement of the first half
// and second half, our final queue will be {3,5}.
    void rearrangeQueue(queue<int> &q){

        queue<int> p;
        int size = q.size();
        int n=q.size()/2;
        while(n != 0) {
            p.push(q.front());
            q.pop();
            n--;
        }
        
        int k=0;
        while(k<size) {
            if(k%2 == 0) {
                q.push(p.front());
                p.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
            k++;
        }

        
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
    q.push(90);
    q.push(100);
    rearrangeQueue(q);

    cout<<"Interleave "<<endl;

    while(q.empty() != true) {
        cout<<q.front()<<" ";
        q.pop();
    }
}