#include<iostream>
#include<vector>
using namespace std;
    int countPrimes(int n) {
        if(n==0) return 0;
        int count = 0;
        vector<bool> prime (n,true);

        prime[0] = prime[1] = false;

        for(int i=2; i<n; i++ ) {
            if(prime[i]) {
                count ++;

                for(int j=2*i; j<n; j=j+i ) {
                    prime[j] = false;
                }
            }
        }
        return count;
    }

int main() {

    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int ans = countPrimes(n);
    cout<<"Number of prime no. is "<<ans<<endl;


}