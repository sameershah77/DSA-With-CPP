#include<iostream>
using namespace std;

int power(int x,int y) {
    int ans = 1;
 
    for(int i = 1;i <= y;i ++) {
        ans = ans * x;
    
    }
    return ans;
}

int main () {
    cout<<"Enter the numbers "<<endl;
    int a,b;
    cin>> a >> b;
    int answer = power(a,b);
    cout<<"Power is " << answer;

    return 0;

}