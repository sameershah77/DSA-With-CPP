#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
    int findLongestChain(vector<vector<int>>& pairs) {
        for(int i=0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
        }
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
        }
        for(auto it:pairs){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        priority_queue<int>pq;
        for(auto it:pairs){
            if(pq.size()>0 && pq.top()>=it[0]){
                continue;
            }
            else
                pq.push(it[1]);
        }
        return pq.size();
    }
int main() {
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};

    int ans = findLongestChain(pairs);

    cout<<"Answer is "<<ans<<endl;
}