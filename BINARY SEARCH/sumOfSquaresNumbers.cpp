#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


    bool judgeSquareSum(int c,vector<int> &arr) {
        long long int a = 0;
        long long int b = sqrt(c);

        while(a <= b) {
            if(a*a + b*b == c) {
                arr.push_back(a);
                arr.push_back(b);
                return true;
            }
            else if(a*a + b*b > c) {
                b--;
            }
            else {
                a++;
            }
        }
    
    return false;
    }
int main() {
    vector<int> arr;
    int n;
    cout<<"Enter number ";
    cin>>n;
    
    if(judgeSquareSum(n,arr)) {
        cout<<"sum of squares numbers are valid here "<<endl;
        cout<<arr[0]<<"*"<<arr[0]<<" + "<<arr[1]<<"*"<<arr[1]<<" = "<<n<<endl;
    }
    else {
        cout<<"sum of squares numbers are Not valid here "<<endl;
    }
}   