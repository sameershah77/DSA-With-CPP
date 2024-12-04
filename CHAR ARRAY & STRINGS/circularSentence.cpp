#include<iostream>
using namespace std;


    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        if(sentence[0] != sentence[n-1]) {
            return false;
        }

        for(int i=0; i<n; i++) {
            if(sentence[i] == ' ' && i+1<n) {
                if(sentence[i-1] != sentence[i+1]) {
                    return false;
                }
            }
        }
        return true;
    }
int main() {
    string s = "leetcode exercises sound delightful";

    if(isCircularSentence(s)) {
        cout<<"Sentence is circular"<<endl;
    }else {
        cout<<"Sentence is not circular"<<endl;
    }
}