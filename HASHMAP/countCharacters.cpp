#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main() {

    //unordered map
    cout<<"Unordered Map"<<endl<<endl;
    string s = "uysdgdbixfuhbsoidauaho";
    unordered_map<char,int> m;
    for(int i=0; i<s.size(); i++) {
        char ch = s[i];
        m[ch]++;
    }

    for(auto val:m) {
        cout<<val.first<<" -> "<<val.second<<endl;
    }





    //ordered map
    cout<<endl<<endl;
    cout<<"Ordered Map"<<endl<<endl;
    string x = "uysdgdbixfuhbsoidauaho";
    map<char,int> mp;
    for(int i=0; i<x.size(); i++) {
        char ch = x[i];
        mp[ch]++;
    }

    for(auto val:mp) {
        cout<<val.first<<" -> "<<val.second<<endl;
    }



}