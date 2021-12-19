// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    void travel(vector<int> adj[], int des , int it , int &ans){
        if(it == des){
            ans++;
            return;
        }
        for(auto i : adj[it]){
            travel(adj , des , i , ans);
        }
    }
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        if(source == destination) return 1;
        int ans = 0;
        for(auto it : adj[source]){
            travel(adj , destination , it , ans);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
    #endif
    
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends