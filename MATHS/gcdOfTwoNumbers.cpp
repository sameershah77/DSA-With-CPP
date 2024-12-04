#include<iostream>
using namespace std;

// GCD(a,b) = GCD(a-b,b)    ,a>b
    int gcd(int A, int B) { 
	  
	    if(A==0) {
	        return B;
	    }
	    if(B==0) {
	        return A;
	    }
	    
	    while(A>0 && B>0) {
	        if(A>B) {
	            A=A-B;
	        }
	        else if(B>=A) {
	            B=B-A;
	        }
	        
	    }
	    if(A==0) {
	        return B;
	    }
	    return A;
	      
	}

int main() {

    int a;
    cout<<"Enter first number EX: 72 : ";
    cin>>a;
    int b;
    cout<<"Enter second number EX: 24 : ";
    cin>>b;
    int ans = gcd(a,b);
    cout<<"GCD/HCF is "<<ans<<endl;


}