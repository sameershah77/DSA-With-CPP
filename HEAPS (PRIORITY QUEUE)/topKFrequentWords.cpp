#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;



// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.



// class Solution {
// public:
// class Info{
//     public:
//     string s;
//     int count;
//     Info(string s, int count) {
//         this->s = s;
//         this->count = count;
//     }
// };

// class compare{
//     public:
//     bool operator()(Info* a, Info* b) {
//         return a->count > b->count;
//     }
// };
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string,int> mp;

//         for(auto val: words) {
//             mp[val]++;
//         }

//         priority_queue<Info*,vector<Info*>,compare> minHeap;

//         for(auto val : mp) {
//             Info* temp = new Info(val.first,val.second);
            
//                 if(minHeap.size() < k) {
//                     minHeap.push(temp);
//                 }
//                 else if(minHeap.top()->count < temp->count) {
//                     minHeap.pop();
//                     minHeap.push(temp);
//                 }
//                 cout<<minHeap.top()->s<<endl;
                        
//         }
//         vector<string> ans;

//         while(minHeap.empty() == false) {
            
//             ans.push_back(minHeap.top()->s);
//             minHeap.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };






    // comparator
    
    struct comparator
    {
        bool operator() (pair<int, string>& a, pair<int, string>& b)
        {
            if(a.first == b.first)           // if frequency are equal put lexicographically greater element on top
            {
                return a.second < b.second;
            }
            else                            // if frequency are not equal put the elements on top which has less frequency
            {
                return a.first > b.first;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        
        // declare a map which store the frequency of words
        
        unordered_map<string, int> mp;
        
        for(auto word : words)
        {
            mp[word]++;
        }
        
        // declare a priority queue
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        
        for(auto x : mp)
        {
            if(pq.size() < k)             // firstly push k elements into pq
            {
                pq.push({x.second, x.first});
            }
            else
            {
                if(pq.top().first < x.second || (pq.top().first == x.second && pq.top().second > x.first))
                {
                    pq.pop();
                    
                    pq.push({x.second, x.first});
                }
            }
        }
        
        // push all the elements from pq to res
        
        vector<string> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            
            pq.pop();
        }
        
        // reverse the res
        
        reverse(res.begin(), res.end());
        
        return res;
    }


int main() {
    

   vector<string> s = {"i","love","leetcode","i","love","coding"};
   int k = 2;

    vector<string> ans = topKFrequent(s,k);

    for(auto val:ans) {
        cout<<val<<" ";
    }

}