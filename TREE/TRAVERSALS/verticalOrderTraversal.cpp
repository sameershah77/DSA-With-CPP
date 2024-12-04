#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

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

    void verticalTraversal(Node* root,vector<vector<int>> &arr) {
        if(root == NULL) {
            return;
        }

        map<int,map<int,vector<int>>> mp;
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(q.empty() == false) {
            auto temp = q.front();
            q.pop();
            Node* frontNode = temp.first;

            int hd = temp.second.first; // hd is the horizontal distance , initially it was 0
            int level = temp.second.second;

                      
            mp[hd][level].push_back(frontNode->data);            
            if(frontNode->left != NULL) {
                q.push({frontNode->left,{hd-1,level+1}});
            }

            if(frontNode->right != NULL) {
                q.push({frontNode->right,{hd+1,level+1}});
            }            
        }
        
        // map<int,map<int,vector<int>>> mp;

        for(auto val: mp) {
            // arr.push_back(val.second);
            vector<int> temp;
            for(auto i:val.second) {

                sort((i.second).begin(),(i.second).end());
                for(auto j:i.second) {
                    temp.push_back(j);
                }
            }
            arr.push_back(temp);
        }  
    }
    int main() {

    //        10
    //     /      \
    //   20        30
    //  /   \    /    \
    // 40   60  90    100

        Node* root = new Node(10);
        Node* a = new Node(20);
        Node* b = new Node(30);
        Node* c = new Node(40);
        Node* d = new Node(60);
        Node* e = new Node(90);
        Node* f = new Node(100);


        root->left = a;
        root->right = b;
        a->left = c;
        a->right = d;
        b->left = e;
        b->right = f;


        vector<vector<int>> arr;

        verticalTraversal(root,arr);

        cout<<endl;

        cout<<"The Vertically Traversal elements are "<<endl;
        for(auto val:arr) {
            for(int i=0; i<arr.size(); i++) {
                    cout<<val[i]<<" ";
              
            }
            cout<<endl;
        }
        cout<<endl;

    }


