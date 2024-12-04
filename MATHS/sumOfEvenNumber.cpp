#include<iostream>
using namespace std;


int sum(int n) {
    int sum =0;
    for(int i=2; i<n;i+=2 ) {
        sum = sum +i;
    }
    return sum;


}
int main () {
    cout<<"Enter the Numbers "<<endl;
    int n;
    cin>>n;
    int answer = sum(n);
    
    cout<<"Sum of Even number is  " << answer;

    return 0;

}