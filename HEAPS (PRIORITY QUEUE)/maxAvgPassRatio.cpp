#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
// Example 2:

// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485

class StudentClass{
    public: 
    int pass;
    int total;

    StudentClass(int pass, int total) {
        this->pass = pass;
        this->total = total;
    }
};

class Comp{
    public:
    //calculating dalta
    bool operator()(StudentClass* a, StudentClass* b) {

        double delta1 = (a->pass + 1)/(double)(a->total + 1) - (a->pass)/(double)(a->total);
        double delta2 = (b->pass + 1)/(double)(b->total + 1) - (b->pass)/(double)(b->total);

        return delta1 < delta2;
    }
};

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<StudentClass*,vector<StudentClass*>,Comp> maxHeap;

        for(auto val: classes) {
            StudentClass* temp = new StudentClass(val[0],val[1]);
            maxHeap.push(temp);
        }

        while(extraStudents-- ) {
            StudentClass* temp = maxHeap.top();
            maxHeap.pop();
            temp->pass++;
            temp->total++;
            maxHeap.push(temp);
        }

        double passRatio = 0;

        while(maxHeap.empty() != true) {
            StudentClass* temp = maxHeap.top();
            maxHeap.pop();
            passRatio += (temp->pass)/(double)(temp->total);
        }
        
        double avgPassRatio = passRatio/classes.size();
        return avgPassRatio;
    }

int main() {
    vector<vector<int>>classes = {{2,4},{3,9},{4,5},{2,10}}; 
    int extraStudents = 4;

    double ans = maxAverageRatio(classes,extraStudents);

    cout<<"Answer is "<<ans<<endl;

}
