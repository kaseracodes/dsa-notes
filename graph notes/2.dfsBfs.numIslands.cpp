#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'

// problem link: https://leetcode.com/problems/number-of-islands/description/

void dfs ( vector< vector<char> >& grid, int sr, int sc, vector< vector<bool> > &visited ){

    visited[sr][sc] = true;
    int nrows = grid.size(), ncolumns = grid[0].size();

    // {top, left, down, right} --> {tldr}
    int dr[4] = {-1, 0, 1, 0 };
    int dc[4] = {0, -1, 0, 1 };

    for ( int i = 0 ; i < 4 ; i++ ){
        int nr = sr + dr[i];
        int nc = sc + dc[i];

        /**
            {nr, nc} lies outside the grid - not a valid neighbour
            if ( nr < 0 || nr > nrows || nc < 0 || nc > ncolumns ){
                continue;
            }

            // {nr, nc} lies inside the grid but is not a land but a water body - not a valid neighbour
            if ( grid[nr][nc] == 0 ){
                continue;
            }
        */

        if ( nr >= 0 && nr < nrows && nc >= 0 && nc < ncolumns && grid[nr][nc] == '1' && !visited[nr][nc] ){
            dfs(grid, nr, nc, visited );
        }
    }

}

void bfs ( vector< vector<char> >& grid, int sr, int sc, vector< vector<bool> > &visited ){

    queue < pair<int, int> > pendingVertices;
    pendingVertices.push({sr, sc});
    visited[sr][sc] = true;

    while ( !pendingVertices.empty() ){
        auto cv = pendingVertices.front();
        pendingVertices.pop();

        int cr = cv.first;  // current-row
        int cc = cv.second; // current-column

        int dr[4] = {1, -1, 0, 0 };
        int dc[4] = {0, 0, -1, 1 };

        for ( int i = 0 ; i < 4 ; i++ ){
            int nr = cr + dr[i];
            int nc = cc + dc[i];  

            // {nr, nc} lies outside the grid - not a valid neighbour
            if ( nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() ){
                continue;
            }

            // {nr, nc} lies inside the grid but is not a land but a water body - not a valid neighbour
            if ( grid[nr][nc] == '0' ){
                continue;
            }   

            if ( !visited[nr][nc] ){
                pendingVertices.push({nr, nc});
                visited[nr][nc] = true;
            }
        } 
    }
}

int numIslands(vector<vector<char>>& grid) {

    int nrows = grid.size(), ncolumns = grid[0].size();
    vector < vector<bool> > visited ( nrows , vector <bool>(ncolumns, false) );

    int countComponents = 0;

    for ( int ir = 0 ; ir < nrows ; ir++ ){
        for ( int jc = 0 ; jc < ncolumns ; jc++ ){
            if ( !visited[ir][jc] && grid[ir][jc] == '1' ){
                bfs ( grid, ir, jc, visited );
                countComponents++;
            }
        }
    }

    return countComponents;

}


void solve(){
    
    

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

