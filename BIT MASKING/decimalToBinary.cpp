#include<iostream>
#include<math.h>
using namespace std;
int bToD(int n) {
    int binary = 0;
    int i=0;

    while(n>0) {
        int bit = (n&1);
        binary = bit*pow(10,i++)+binary;
        n=n>>1;
    }
    ;
    return binary;
    ;
}

int dToB(int n) {
    int decimal = 0;
    int i=0;
    while(n>0) {
        int bit = n%10;
        decimal = decimal+bit*pow(2,i++);
        n /= 10;
    }
    
    return decimal;
}

int main() {

    int n = 10;
    cout<<"Binary of "<<n<<" is "<<bToD(n)<<endl;;

}