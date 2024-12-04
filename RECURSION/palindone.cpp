#include<iostream>
#include<string.h>
using namespace std;

bool palindrone(string s,int start,int end) {
    if(start >= end) {
        return true;
    }

    if(s[start] != s[end]) {
        return false;
    }

    palindrone(s,start+1,end-1);
}

int main() {
    string s;
    cout<<"Entter string : ";
    cin>>s;
    bool ans = palindrone(s,0,s.size()-1);
    if(ans) {
        cout<<"It is palindrone"<<endl;
    }
    else {
        cout<<"It is not palindrone"<<endl;
    }
}