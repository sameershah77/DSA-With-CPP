#include<iostream>
#include<queue>

using namespace std;
// Given an input stream str of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

// NOTE:
// 1. You need to find the answer for every i (0 <= i < n)
// 2. In order to find the solution for every i you need to consider the string from starting position till ith position.
 

// Example 1:

// Input: str = "aabc"
// Output: "a#bb"
// Explanation: For every ith character we will
// consider the string from index 0 till index i first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - there are two non repeating characters 'b' and 'c', 
// first non-repeating character is 'b' because 'b' comes before
// 'c' in the stream.
// Example 2:

// Input: str = "zz"
// Output: "z#"
// Explanation: For every character first non
// repeating character is as follow-
// "z" - first non-repeating character is 'z'
// "zz" - no non-repeating character so '#'

		string FirstNonRepeating(string str){
		    // Code here
		    
		    string ans = "";
		    int freq[26] = {0};
		    queue<char> q;
		    
		    for(int i=0; i<str.size(); i++) {
		        char currChar = str[i];
		        
		        //increament frequency
		        freq[currChar - 'a']++;
		        
		        //push in queue
		        q.push(currChar);
		        
		        while(q.empty() == false) {
		            if(freq[q.front() - 'a'] == 1) {
		                ans.push_back(q.front());
		                break;
		            }
		            else{
		                q.pop();
		            }


		        }
		        
		        
		        if(q.empty() == true) {
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}
int main() {
    string str = "aabc";
    string ans = FirstNonRepeating(str);

    cout<<ans<<endl;
}