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
    cout<<"Enter first number EX: 12 : ";
    cin>>a;
    int b;
    cout<<"Enter second number EX: 18 : ";
    cin>>b;


    // GCD(a,b) = GCD(a-b,b)    ,a>b

    //LCM(a,b) * GCD(a,b) = a*b
    //LCM(a,b) = (a*b)/GCD(a,b)
    int ans = (a*b)/gcd(a,b);
    cout<<"LCM is "<<ans<<endl;


}