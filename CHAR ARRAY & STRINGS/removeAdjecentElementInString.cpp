#include<iostream>
#include<string>
using namespace std;


    string removeDuplicates(string s) {
        string ans = "";

        int i=0;
        while(i < s.length()) {

            if(ans.length()>0) {

                 if(ans[ans.length()-1] == s[i]) {
                ans.pop_back();
                }
                else {
                    ans.push_back(s[i]);
                }

            }
            else {
                 ans.push_back(s[i]);

            }
           
            i++;
        }
        return ans;
        
    }
int main () {
    string s;
    cout<<"Enter a string with duplicate element"<<endl;
    getline(cin,s);
    string x = removeDuplicates(s);
    cout<<x<<endl;


}