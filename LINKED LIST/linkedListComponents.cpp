#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;



// ou are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

// Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

 

// Example 1:


// Input: head = [0,1,2,3], nums = [0,1,3]
// Output: 2
// Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
// Example 2:


// Input: head = [0,1,2,3,4], nums = [0,3,1,4]
// Output: 2
// Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

    int numComponents(ListNode* head, vector<int>& nums) {
        if(head == NULL)
            return 0;
        unordered_set<int> s{nums.begin(),nums.end()};
        int count = 0;
        while(head != NULL){
            if(s.find(head->val) != s.end()){
                count++;
                while(head->next != NULL && s.find(head->next->val) != s.end()) {
                    head = head->next;
                }  
            }
            head = head->next;
        }
        return count;
    }
int main() {
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);
    ListNode* d = new ListNode(40);

    
    a->next = b;
    b->next = c;
    c->next = d;

    vector<int> nums = {10,20,40};

    int ans = numComponents(a,nums);

    cout<<"Answer is "<<ans<<endl;
}