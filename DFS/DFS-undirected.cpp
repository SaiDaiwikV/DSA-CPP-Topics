#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std;

class Graph{
    int V; // Number of vertices
    list <int> *adj; // Pointer to an array containing adjacency lists

    public:
        void DFSUtil(int v, bool visited[]); // Utility function for DFS
        Graph(int V); // Constructor

        void addEdge(int v, int w); // Function to add an edge to the graph

        void DFS(int v); // Function to perform DFS traversal from a given source vertex
};

Graph::Graph(int V){
    this->V = V; // Initialize the number of vertices
    adj = new list<int>[V]; // Create an array of adjacency lists
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w); // Add w to v’s list
    adj[w].push_back(v); // Add v to w’s list (for undirected graph)
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true; // Mark the current node as visited
    cout << v << " "; // Print the current node

    list<int>::iterator i;
    for(i = adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            DFSUtil(*i,visited); // Recur for all the vertices adjacent to this vertex
        }
    }
}

void Graph::DFS(int v){
    bool *visited = new bool[V]; // Mark all the vertices as not visited
    for(int i = 0;i<V;i++){
        visited[i] = false;
    }

    DFSUtil(v,visited); // Call the recursive helper function to print DFS traversal
}

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}