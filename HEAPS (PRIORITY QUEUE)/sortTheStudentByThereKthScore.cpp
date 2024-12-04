#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.

// You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.

// Return the matrix after sorting it.

 

// Example 1:


// Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
// Output: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
// Explanation: In the above diagram, S denotes the student, while E denotes the exam.
// - The student with index 1 scored 11 in exam 2, which is the highest score, so they got first place.
// - The student with index 0 scored 9 in exam 2, which is the second highest score, so they got second place.
// - The student with index 2 scored 3 in exam 2, which is the lowest score, so they got third place.
// Example 2:


// Input: score = [[3,4],[5,6]], k = 0
// Output: [[5,6],[3,4]]
// Explanation: In the above diagram, S denotes the student, while E denotes the exam.
// - The student with index 1 scored 5 in exam 0, which is the highest score, so they got first place.
// - The student with index 0 scored 3 in exam 0, which is the lowest score, so they got second place.

class Object{
    public:
    int max;
    vector<int> nums;
    Object(int max, vector<int> nums) {
        this->max = max;
        this->nums = nums;
    }
};
class Comp{
    public:
    bool operator()(Object* a, Object* b) {
        return a->max < b->max;
    }
};

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        int row = score.size();
        int col = score[0].size();
        priority_queue<Object*,vector<Object*>,Comp> maxHeap;

        for(int i=0; i<row; i++) {
            int max = score[i][k];
            Object* temp = new Object(max,score[i]);
            maxHeap.push(temp);
        }
        
        score.clear();

        while(maxHeap.empty() != true) {
            Object* temp = maxHeap.top();
            maxHeap.pop();

            score.push_back(temp->nums);
        }
        return score;
    }

int main() {

    vector<vector<int>> score = {{10,6,9,1},{7,5,11,2},{4,8,3,15}};

    cout<<"Before Sorting"<<endl;
    for(auto val: score) {
        for(auto i: val) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    int k = 2;
    score = sortTheStudents(score,k);


    cout<<"After Sorting"<<endl;
    for(auto val: score) {
        for(auto i: val) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

}