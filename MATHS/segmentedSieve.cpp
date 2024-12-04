#include<iostream>
#include<vector>
using namespace std;
    int countPrimes(int low ,int high) {
        if(high==0) return 0;
        
        int count = 0;
        vector<bool> prime (high-low+1,true);
     
        prime[0] = prime[1] = false;

        for(int i=low; i<high; i++ ) {
            if(prime[i]) {
                count ++;

                for(int j=2*i; j<high; j=j+i ) {
                    prime[j] = false;
                }
            }
        }
        int n=0;
        for(int i=low;i<high;i++){
            cout<<i<<"->"<<prime[i]<<endl;

        }
        return count; 
  
    }

int main() {

    int low;
    cout<<"Enter a starting number : ";
    cin>>low;
    int high;
    cout<<"Enter a ending number : ";
    cin>>high;
    int ans = countPrimes(low,high);
    cout<<"Number of prime no. is "<<ans<<endl;
}