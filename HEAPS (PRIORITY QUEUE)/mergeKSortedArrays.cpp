#include<iostream>
#include<queue>
using namespace std;
class Info {
    public:
    int data;
    int row;
    int col;

    Info(int data,int row,int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }

};
class compare{
    public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArray(int arr[3][4], int n, int k) {
    priority_queue<Info*,vector<Info*>, compare> minHeap;

    for(int i=0; i<k; i++) {
        Info* temp = new Info(arr[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(minHeap.empty() == false) {
        Info* temp = minHeap.top();

        int topElement = temp->data;
        int topCol = temp->col;
        int topRow = temp->row;

        minHeap.pop();
        ans.push_back(topElement);

        if(topCol + 1 < n) {
            Info* newInfo = new Info(arr[topRow][topCol+1],topRow,topCol+1);
            minHeap.push(newInfo);
        } 
    }
    return ans;

}

int main() {
    int arr[3][4] = {{2,4,6,8},{1,3,7,9},{3,7,8,14}};

    int k = 3;
    int n = 4;

    vector<int> ans = mergeKSortedArray(arr,n,k);
    cout<<endl<<"Your merged k sorted arrays are"<<endl<<endl;
    for(auto val: ans) {
        cout<<val<<" ";
    }

}