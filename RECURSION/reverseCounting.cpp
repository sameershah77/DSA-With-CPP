#include<iostream>
using namespace std;
void count(int n) {
    // base case
    if(n==0) {
        return ;
    }

    cout<<n<<" ";

count(n-1);

}

int main() {
    int n;
    cout<<"Enter the value of n :- ";
    cin>>n;
    count(n);
    
}