#include<iostream>
using namespace std;

void checkChar(string str,int n,char key,int i) {
    if(i>=n) {
        return ;
    }

    if(str[i]==key) {
        cout<<i<<" ";
    }

    checkChar(str,n,key,i+1);
}

int main () {

    string str = "sameershah";

    char key = 'h';
    int n = str.length();
    int i=0;
   
    cout<<"Answer char is present at index "<<endl;
     checkChar(str,n,key,i);
}