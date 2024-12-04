#include<iostream>
using namespace std;

void subSequence(string str,string outputString,int i,int & count) {

    if(i>=str.length()) {
        cout<< outputString <<endl;
        count++;
        return;
    }
    
    //Include
  
    subSequence(str,outputString + str[i],i+1,count);

    //Exclude

    subSequence(str,outputString,i+1,count); 

}

int main () {
    string str;
    cout<<"Type your string :- ";
    getline(cin,str);

    string outputString = "";
    int i=0;
    cout<<"Your Subsequences are :- "<<endl;
    int count = 0;
    subSequence(str,outputString,i,count);

    cout<<"Total number of Subsequences are "<<count<<endl;

}