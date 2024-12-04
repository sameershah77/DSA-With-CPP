#include<iostream>
using namespace std;


int factorial(int n) {

    int fact=1;
        for (int i=1;i <=n ;i ++) {
            fact = fact * i;
            }
            return fact;
}

int nCr(int n,int r) {

    int nom = factorial(n);
    int denom = factorial(r) * factorial(n-r);

    return nom/denom;

}

int main() {
    int n,r;
cout<< nCr(10,5) <<endl;


}
