#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

// difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
// worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
// Every worker can be assigned at most one job, but one job can be completed multiple times.

// For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
// Return the maximum profit we can achieve after assigning the workers to the jobs.

 

// Example 1:

// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
// Example 2:

// Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
// Output: 0

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        
        int n = profit.size();

        vector<pair<int,int>> Pair;

        for(int i=0; i<n; i++) {
            Pair.push_back({profit[i],difficulty[i]});
        }

        sort(Pair.begin(), Pair.end());

        for(int i=0; i<worker.size(); i++) {
            for(int j=Pair.size()-1; j >= 0; j--) {
                if(Pair[j].second <= worker[i]) {
                    ans += Pair[j].first;
                    break;
                }
            }
        }
        return ans;
    }

int main(){

    vector<int> difficulty = {2,4,6,8,10}, profit = {10,20,30,40,50}, worker = {4,5,6,7};

    cout<<"Answer is "<<maxProfitAssignment(difficulty,profit,worker)<<endl;

}