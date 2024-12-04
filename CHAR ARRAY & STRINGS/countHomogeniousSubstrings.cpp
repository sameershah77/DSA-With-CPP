#include<iostream>
#include<math.h>
using namespace std;


    int countHomogenous(string s) {
        char prev = '#';
        int count = 1;
        int sum = 0;
        long long int MOD = pow(10,9)+7;

        for(auto val: s) {
            if(val != prev) {
                count = 1;
                prev = val;
            }
            sum = (sum + count)%MOD;
            count++;
        }
        return sum;
    }
int main() {
    string s = "abbcccaa";
    int ans = countHomogenous(s);

    cout<<"Number of Homogenious Substrings are "<<ans<<endl;

}