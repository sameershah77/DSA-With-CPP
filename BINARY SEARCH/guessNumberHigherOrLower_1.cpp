#include<iostream>
using namespace std;


    int guess(int& num) {

        //supposed picked element is 8
        int n = 5;

        if(num < n)  {
            return -1;
        }
        if(num > n) {
            return 1;
        }
        return 0;
    }

    int guessNumber(int n) {
        
        int s = 1;
        int e = n;

        int mid = s+(e-s)/2;

        while(s<=e) {
            int ans = guess(mid);

            if(ans == 0) {
                return mid;
            }
            else if(ans == -1) {
                e = mid-1;
            }
            else if(ans == 1) {
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return mid;;
    }
int main() {

    int n = 10;
    int ans = guessNumber(n);
    cout<<"Answer is "<<ans<<endl;

}