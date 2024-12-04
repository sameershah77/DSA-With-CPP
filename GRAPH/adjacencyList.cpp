#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;

    addEdge(int u, int v, int direction) {
        //direction->0 = undirected graph
        //direction->1 = directed graph

        adjList[u].push_back(v);
        if(direction == 0) {
            //direction->0 = undirected graph
            adjList[u].push_back(v);
        }
    }

    void printAdjList() {
        for(auto val: adjList) {
            cout<<val.first<<" -> ";
            for(auto i: val.second) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(0,3,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,1,1);

    cout<<"Adjacency List"<<endl;

    g.printAdjList();
       
}