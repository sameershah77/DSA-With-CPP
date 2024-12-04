#include<iostream>
#include<queue>
using namespace std;

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
class Info{
    public:
    char data;
    int count;
    Info(char d,int c) {
        this->data = d;
        this->count = c;
    } 
};

class compare{
    public:
    bool operator()(Info* a, Info* b) {
        return a->count < b->count;
    }
};

    string reorganizeString(string s) {

        int freq[26] = {0};
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
        }

        priority_queue<Info*,vector<Info*>,compare> maxHeap;

        for(int i=0; i<26; i++) {
            if(freq[i] != 0) {
                Info* temp = new Info(i+'a',freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while(maxHeap.size() > 1) {
            Info* first = maxHeap.top();
            maxHeap.pop();
            Info* second = maxHeap.top();
            maxHeap.pop();

            ans += first->data;
            ans += second->data;
            first->count--;
            second->count--;
            if(first->count != 0) {
                maxHeap.push(first);
            }
            if(second->count!= 0) {
                maxHeap.push(second);
            }
        
        }

        if(maxHeap.size() == 1) {
            Info* temp  = maxHeap.top();
            maxHeap.pop();
            if(temp->count == 1) {
                ans += temp->data;
            }
            else {
                return "";
            }
        }
        return ans;
    }
int main() {

    string s = "aab";
    string ans = reorganizeString(s);

    cout<<"Re organised string of "<<s<<" is '"<<ans<<"'"<<endl<<endl;
}