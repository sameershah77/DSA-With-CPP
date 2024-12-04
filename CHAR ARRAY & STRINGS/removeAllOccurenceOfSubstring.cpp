#include<iostream>
#include<string>
using namespace std;

    string removeOccurrences(string s, string part) {
       int pos = s.find(part);

       while (pos != string::npos) {
           s.erase(pos,part.length());
           pos = s.find(part);
       }
       return s;
    }

    
int main () {
    string s;
    cout<<"Enter a string "<<endl;
    getline(cin,s);
    string p;
    cout<<"Enter a Substring to remove ";
    getline(cin,p);
    string x = removeOccurrences(s,p);
    cout<<x<<endl;


}