#include<iostream>
using namespace std;

// T.C. O(n!)  S.C  O(n)

void permutation(string &str,int i,int & count) {

    if(i>=str.length()) {
      cout<<str<<" "<<endl;
      count++;
      return;
    }
    int j;
    for(j=i;j<str.length();j++) {
        swap(str[i],str[j]);


    permutation(str,i+1,count);


        swap(str[i],str[j]);
    }
    
    
    

}

int main () {
    string str;
    cout<<"Type your string :- ";
    getline(cin,str);
    int i=0;
    
    cout<<"Your Permutations are :- "<<endl;
    int count = 0;
    permutation(str,i,count);

    cout<<"Total number of Subsequences are "<<count<<endl;

}