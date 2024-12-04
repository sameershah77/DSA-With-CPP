#include<iostream>
using namespace std;;

// Pass by referance in function using referance variable;

void temp(int &var) {
    var = var + 30;
}


//This is important question 
int* solve() {
    cout<<"Inside solve "<<endl;
    int a=5;
    int *ans =&a;
    cout<<&a<<endl;
    cout<<"solve me "<<ans<<endl;
    cout<<&ans<<endl;
    return ans;
}


int main() {

int a=5;
cout<<"Before function "<<endl;
cout<<a<<endl;//5

temp(a);



cout<<"After function "<<endl;
cout<<a<<endl;//35


cout<<endl<<endl<<endl;

int *ans = solve();
cout<<"Inside main "<<endl;
cout<<ans<<endl;;

cout<<&ans<<endl;


}