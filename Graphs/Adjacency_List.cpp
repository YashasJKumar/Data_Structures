#include "iostream"
#include "vector"
#include "queue"
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print_graph(vector<int> adj[], int v)
{
    for(int i = 0;i < v;i++)
    {
        cout<<i<<" : ";
        for(int j : adj[i])
            cout<<j<<" ";
        cout<<endl;
    }
}

void bfs(vector<int> adj[], int v, int source)
{
    //Create a boolean visited array to keep track of discovered vertices.
    bool visited[v];

    //Initialize false for all
    for(int i = 0; i < v;i++)
        visited[i] = false;

    //Create a queue & enqueue the source & mark it as visited
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!(q.empty()))
    {
        int ele = q.front();
        q.pop();

        cout<<ele<<" ";

        // Check for the unvisited but adjacent elements for the popped ele & enqueue them.
        for(int i : adj[ele])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout<<endl;
}

int main()
{
    int v;
    cout<<"Enter number of Vertices: ";
    cin>>v;

    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,2,4);

    print_graph(adj, v);

    bfs(adj, v, 0);

    return 0;
}