#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph{
    public:
    
    unordered_map<int,vector<int>> adjList;

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

    void dfs(int src,unordered_map<int,bool>& visited) {
        cout<<src<<" ";
        visited[src] = true;
        for(auto val: adjList[src]) {
            if(visited[val] == false) {
                dfs(val,visited);
            }
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

    bool checkCycleUnBFS(int src,unordered_map<int,bool>& visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        unordered_map<int,int> parent;
        parent[src] = -1;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(auto nbr: adjList[front]) {
                if(visited[nbr] == false) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = front;
                }
                else {
                    if(parent[front] != nbr) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkCycleUnDFS(int src,unordered_map<int,bool>& visited,int parent) {
        visited[src] = true;
        for(auto nbr: adjList[src]) {
            if(visited[nbr] == false) {
                bool furtherAns = checkCycleUnDFS(nbr,visited,src);
                if(furtherAns) {
                    return true;
                }
            }
            else {
                if(nbr != parent) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g;

    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);
    g.addEdge(2,3,0);
    g.addEdge(2,5,0);
    g.addEdge(3,6,0);
    g.addEdge(5,6,0);

    cout<<"Adjacency List"<<endl;

    g.printAdjList();

    cout<<"BFS"<<endl;
    unordered_map<int,bool> visited1;
    g.bfs(0,visited1);

    cout<<endl<<"DFS"<<endl;
    unordered_map<int,bool> visited2;
    g.dfs(0,visited2);


    // Cycle Detection Logic
    cout<<endl<<"Check Cycle In Undirectional Graph using BFS"<<endl;
    unordered_map<int,bool> visited3;
    if(g.checkCycleUnBFS(0,visited3)) {
        cout<<"Cycle is present"<<endl;
    }
    else {
        cout<<"Cycle is absent"<<endl;
    }


    cout<<endl<<"Check Cycle In Undirectional Graph using DFS"<<endl;
    unordered_map<int,bool> visited4;
    if(g.checkCycleUnDFS(0,visited4,-1)) {
        cout<<"Cycle is present"<<endl;
    }
    else {
        cout<<"Cycle is absent"<<endl;
    }



}