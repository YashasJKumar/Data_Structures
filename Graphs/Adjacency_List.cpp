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

void bfs_v2(vector<int> adj[], bool visited[], int source)
{
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        cout<<temp<<" ";

        for(int x : adj[temp])
            if(!visited[x])
                q.push(x);
    }
}

void bfs_disconnected_graph(vector<int> adj[], int v)
{
    bool visited[v];
    for(int i = 0;i<v;i++)
        visited[i] = false;
    for(int i = 0;i < v;i++)
        if(!visited[i])
            bfs_v2(adj,visited,i);
}

int no_of_connected_components(vector<int> adj[], int v)
{
    bool visited[v];
    int count = 0;
    for(int i = 0;i<v;i++)
        visited[i] = false;
    for(int i = 0;i < v;i++)
        if(!visited[i]) {
            bfs_v2(adj, visited, i);
            count++;
        }
    return count;
}

void dfs_rec(vector<int> adj[], int s, bool visited[])
{
    // Mark the source vertex as visited.
    visited[s] = true;

    cout<<s<<" ";

    for(int u : adj[s])
        if(!visited[u])
            dfs_rec(adj, u, visited);
}

void dfs(vector<int> adj[], int v)
{
    // T.C - O(V+E)
    bool visited[v];

    for(int i = 0;i < v;i++)
        visited[i] = false;

    dfs_rec(adj,0,visited);
    /*
     * If the graph is disconnected. Call the dfs_Rec() for every non visited vertex.
     * for(int i = 0;i < v;i++){
     *      if(visited[i] == false)
     *          dfs_Rec(adj, i, visited);
     * }
     */
    cout<<endl;
}

void dfs_2(vector<int> adj[],int v, int s)
{
    // The Stack Approach
    bool visited[v];

    for(int i = 0;i < v;i++)
        visited[i] = false;

    stack<int> st;
    st.push(s);
    visited[s] = true;

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();

        cout<<cur<<" ";

        // Reverse iterate.
        for(auto it = adj[cur].rbegin();it != adj[cur].rend();it++)
        {
            if(!visited[*it]){
                visited[*it] = true;
                st.push(*it);
            }
        }
    }
    cout<<endl;
}

int main()
{
    int v = 5;

    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,2,4);

    print_graph(adj, v);

    bfs(adj, v, 0);

    dfs(adj,v);

    dfs_2(adj,v, 0);
    return 0;
}