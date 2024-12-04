#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
    public:
    
    unordered_map<int,list<int>> adjList;

    void addEdge(int u, int v, int direction) {
        //direction->0 = undirected graph
        //direction->1 = directed graph

        adjList[u].push_back(v);
        if(direction == 0) {
            //direction->0 = undirected graph
            adjList[v].push_back(u);
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

    
    void bfs(int src,unordered_map<int,bool>& visited) {
        
        queue<int>q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            cout<<front<<" ";
            for(auto i: adjList[front]) {
                if(visited.find(i) == visited.end()) {
                q.push(i);
                visited[i] = true;
                }
            }
        }
    }
};

int main() {
    Graph g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,4,0);
    g.addEdge(3,5,0);
    g.addEdge(4,6,0);
    g.addEdge(4,7,0);


    cout<<"Adjacency List"<<endl;

    g.printAdjList();

    cout<<endl;
    unordered_map<int,bool> visited;
    cout<<"Printing BFS"<<endl;
    //to handle disconnected graph
    for(int i=0; i<=7; i++) {
        if(visited[i] == false) {
            g.bfs(i,visited);
        }
    }
    //it not effect on time and space complexity   


       
}