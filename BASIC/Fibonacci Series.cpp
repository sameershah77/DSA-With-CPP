#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n = 10;
	int x =0;
	int y =1;
	cout<<x<<" "<<y<<" ";
	for(int i =1;i <=n;i ++) {
	    int nextNum = x + y ;
	    cout<<nextNum<<" ";
	    x=y;
	    y=nextNum;
	}
	
	return 0;
}
