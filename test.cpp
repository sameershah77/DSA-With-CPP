#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr{4,2};

    for(auto val: arr) {
        cout<<val<<" ";
    }
}