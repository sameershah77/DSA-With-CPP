#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced
//  binary search tree.

 

// Example 1:


// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:


// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node() {
        right = NULL;
        left = NULL;
        data = data;
    }

    Node(int data) {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};



    void levelOrderTraversal(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(q.empty() != true) {
            //step 1:
            Node* temp = q.front();
            //step 2:
            q.pop();

            if(temp == NULL) {
                cout<<endl;
                if(q.empty()==false) {
                    q.push(NULL);
                }
            }
            else {
                //step 3:
                cout<<temp->data<<"   ";
                //step 4:
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
    }

    Node* solve(vector<int>& nums,int start, int end) {
        if(start > end) {
            return NULL;
        }

        int mid = start + (end-start)/2;
        int element = nums[mid];
        Node* root = new Node(element);

        root->left = solve(nums,start,mid-1);
        root->right = solve(nums,mid+1,end);
        return root; 
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        return solve(nums,start,end);
    }
    int main() {


        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        Node* root = sortedArrayToBST(arr);

        cout<<"yout tree is "<<endl;
        levelOrderTraversal(root);


    }


