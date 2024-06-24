#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'

/**
SAMPLE INPUT : Undirected Graph
15 15
0 1
0 2
1 6
6 9 
9 10
6 7
7 8
2 3
2 11
11 5
3 4
4 11
12 13
13 14
12 14 
*/

// ________________ INTERNL OPERATIONS FUNCTIONS _________________
void dfs ( vector< vector<int> > &adj , int sv , vector <bool> &visited, vector <int> &ans ){
    
    visited[sv] = true;
    ans.push_back(sv);
    for ( auto nv : adj[sv] ){
        if ( !visited[nv] ){
            dfs ( adj, nv, visited, ans );
        }
    }

}

void bfs ( vector< vector<int> > &adj , int sv , vector <bool> &visited, vector <int> &ans ){

    queue <int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while ( !pendingVertices.empty() ){
        auto cv = pendingVertices.front();
        pendingVertices.pop();

        ans.push_back(cv);
        for ( auto nv : adj[cv] ){
            if ( !visited[nv] ){
                pendingVertices.push(nv);
                visited[nv] = true;
            }
        }
    }

}

// ________________  FUNCTIONS TO BE CALLED BY THE solve() FUNCTION ________________

void sortNeighbours ( vector < vector<int> > &adj ){

    int n = adj.size();
    for ( int iv = 0 ; iv < n ; iv++ ){
        sort( adj[iv].begin(), adj[iv].end() );
    }

}

void printAdjecencyList( vector< vector<int> > &adj ){

    cout << "The adjecency list for the following graph is: " << endl;
    int n = adj.size();
    for ( int iv = 0 ; iv < n ; iv++ ){
        cout << iv << " : [ ";
        for ( auto nv : adj[iv] ){
            cout << nv << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
} 

void printDFS ( vector < vector<int> > &adj ){

    cout << "The DFS of the following graph is: " << endl;

    int n = adj.size();
    vector <bool> visited(n, false);
    vector <int> ans;

    for ( int iv = 0 ; iv < n ; iv++ ){
        if ( !visited[iv] ){
            dfs(adj, iv, visited, ans );
        }
    }

    for ( auto val : ans )  cout << val << " ";
    cout << endl << endl;

}

void printBFS ( vector < vector<int> > &adj ){

    cout << "The BFS of the following graph is: " << endl;

    int n = adj.size();
    vector <bool> visited(n, false);
    vector <int> ans;

    for ( int iv = 0; iv < n ; iv++ ){
        if ( !visited[iv] ){
            bfs(adj, iv, visited, ans );
        }
    }

    for ( auto val : ans )  cout << val << " "; cout << endl << endl;

}

void countConnectedComponents ( vector < vector<int> > &adj ){

    /**
     * @brief In 1 dfs call all of the nodes which are interconnected (belong to the same component ) become visited
     *        no. of connected component = no. of unique dfs calls we are making
     */

    int n = adj.size();
    int connectedComponent = 0;
    vector <bool> visited(n, false);
    vector <int> ans;

    for ( int iv = 0 ; iv < n ; iv++ ){
        if ( !visited[iv] ){
            dfs(adj, iv, visited, ans );
            connectedComponent++;
        }
    }

    cout << "The number of connected components of the following graph are: " << connectedComponent << endl << endl;

}


// ___________________ MAIN FUNCTIONS ________________________ 

void solve(){

    int n = 0, e = 0;
    cin >> n >> e;

    vector < vector<int> > adj(n);
    for ( int i = 0 ; i < e ; i++ ){
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sortNeighbours(adj);
    // printAdjecencyList(adj);
    printDFS(adj);
    printBFS(adj);
    countConnectedComponents(adj);

}

int32_t main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while ( T-- ){
        solve();
    }

    return 0;
}
