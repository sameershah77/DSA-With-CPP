#include<iostream>
using namespace std;

// these type of question in solved by using binaryy search , using search space we use it   ;;;;;

int findSqrt(int n) {

    int start=0;
    int  end = n;
    int mid = start + (end - start)/2;
    int target = n;
    int ans = -1;

    while (start <= end) {
        if(mid*mid == target) {
            return mid;

        }
        if(mid*mid < target) {
            // search in rigth
            ans = mid;
            start = mid+1;
        } 
        else {
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
    return ans;

}


int main() {
    int n;
    cout<<"Enter the number to find square root :- ";
    cin>>n;

    int ans = findSqrt(n);

    cout<<"Square roort of "<<n<<" is "<<ans<<endl;
    int precision;
    cout<<"Enter precision number :- ";
    cin>>precision;

    double step = 0.1;
    double finalAns = ans;
    for(int i=0;i<precision;i++) {
        for(double j=finalAns;j*j<=n;j=j+step) {
            finalAns = j;
        }
        step = step/10;
    }
    cout<<"Final answer is "<<finalAns<<endl;
    
}