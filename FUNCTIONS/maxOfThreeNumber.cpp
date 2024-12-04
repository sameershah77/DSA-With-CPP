#include<iostream>
using namespace std;

int maxOfThree(int x,int y,int z) {
    if(x>y && x >z) {
        return x;
    }
    else if(y>z && y>x) {
        return y;
    }
    else {
        return z;
    }


}

int main () {
    cout<<"Enter the numbers "<<endl;
    int a,b,c;
    cin>> a >> b >>c ;
    int answer = maxOfThree(a,b,c);
    cout<<"Maximum Number Is " << answer;

    return 0;

}