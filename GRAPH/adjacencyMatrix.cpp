#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;

    vector<vector<int>> adjMat (n,vector<int>(n,0));

    int e;
    cout<<"Enter number of Edges"<<endl;
    cin>>e;

    cout<<"Make edges"<<endl;
    for(int i=0; i<e; i++) {
        int u,v;
        cin>>u>>v;

        adjMat[u][v] = 1;
    }

    cout<<"Printing Adjacency Matrix"<<endl;

    for(auto row: adjMat) {
        for(auto col: row) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



    
}