#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

// Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

// Example 1:

// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]
// Example 2:

// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]
class Info{
    public:
    int freq;
    int element;
    Info(int freq, int element) {
        this->freq = freq;
        this->element = element;
    }
};

class Comp{
    public:
    bool operator()(Info* a, Info* b) {
        bool ans = a->freq < b->freq;
        return a->freq < b->freq;
    }
};


    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() == 1 || barcodes.size() == 0) {
            return barcodes;
        }
        
        unordered_map<int,int> freq;

        for(auto val: barcodes) {
            freq[val]++;
        }

        barcodes.clear();

        priority_queue<Info*, vector<Info*>, Comp> maxHeap;

        for(auto val: freq) {
            Info* temp = new Info(val.second,val.first);
            maxHeap.push(temp);
        }

        while(maxHeap.top()->freq > 0) {
            Info* p1 = maxHeap.top();
            maxHeap.pop();

            barcodes.push_back(p1->element);
            p1->freq--;

            Info* p2 = maxHeap.top();
            maxHeap.pop();

            if(p2->freq > 0) {
                barcodes.push_back(p2->element);
                p2->freq--;
            }

            maxHeap.push(p1);
            maxHeap.push(p2);
        }
        return barcodes;
    }

int main() {

    vector<int> barcodes = {1,1,1,2,2,2,3,3,3};

    vector<int> ans = rearrangeBarcodes(barcodes);

    cout<<"Answer is "<<endl;
    for(auto val: ans) {
        cout<<val<<" ";
    }

    
}