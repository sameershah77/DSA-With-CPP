#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;



// You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.

// Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.

// You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i]. The ID of each student is unique.

// Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more than one student has the same points, the one with the lower ID ranks higher.

 

// Example 1:

// Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
// Output: [1,2]
// Explanation: 
// Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.
// Example 2:

// Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
// Output: [2,1]
// Explanation: 
// - The student with ID 1 has 1 positive feedback and 1 negative feedback, so he has 3-1=2 points. 
// - The student with ID 2 has 1 positive feedback, so he has 3 points. 
// Since student 2 has more points, [2,1] is returned.
class Student{
    public:
    int id;
    int points;
    Student(int id, int points) {
        this->id = id;
        this->points = points;
    }
};

class Comp{
    public:
    bool operator()(Student* a, Student* b) {

        if(a->points == b->points && a->id < b->id) {
            return false;
        }
        else if(a->points == b->points && a->id > b->id) {
            return true;
        }
        else if(a->points > b->points) {
            return false;
        }
        else {
            return true;
        }
        return false;
    }
};

    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& report, vector<int>& student_id, int k) {

        map<string,bool> positive;

        map<string,bool> negative;

        for(auto val: pf) {
            positive[val] = true;
        }

        for(auto val: nf) {
            negative[val] = true;
        }

        priority_queue<Student*,vector<Student*>,Comp> maxHeap;

        int n = report.size(); // size of report and student_id is same
        for(int i=0; i<n; i++) {
            string s = report[i];

            int points = 0;
            int a = 0;
            int b = 0;

            while(b<=s.size()) {
                if(isalpha(s[b])) {
                    b++;
                }
                else {
                    string x = s.substr(a,b-a);
                    b++;
                    a = b;

                    if(positive[x] == true) {
                        points += 3;
                    }
                    if(negative[x] == true) {
                        points--;
                    }
                }
            }
            
            Student* temp = new Student(student_id[i],points);
            maxHeap.push(temp);
        }

        vector<int> ans;

        while(k--) {
            Student* temp = maxHeap.top();
            ans.push_back(temp->id);
            maxHeap.pop();
        }
        return ans;
    }
int main() {
    vector<string> positive_feedback = {"smart","brilliant","studious"};
    vector<string> negative_feedback = {"not"};
    vector<string> report = {"this student is not studious","the student is smart"};
    vector<int> student_id = {1,2}; 
    int k = 2;

    vector<int> ans = topStudents(positive_feedback,negative_feedback,report,student_id,k);

    cout<<"Answer is "<<endl;

    for(auto val: ans) {
        cout<<val<<" ";
    }
}