#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
const int mod = 1e9+7;

void bfs ( vector< vector<int> >& grid, int sr, int sc, vector< vector<bool> > &visited ){

    int sourceColor = grid[sr][sc];
    int nrows = grid.size(), ncolumns = grid[0].size();

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
            if ( nr >= 0  && nr < nrows && nc >= 0 && nc < ncolumns && grid[nr][nc] == sourceColor && !visited[nr][nc] ){
                pendingVertices.push({nr, nc});
                visited[nr][nc] = true;
            }
        } 
    }
}

void dfs (  vector<vector<int>> &grid , int sr , int sc , vector<vector<bool>> &visited ){

    int sourceColor = grid[sr][sc];
    int nrows = grid.size(), ncolumns = grid[0].size();

    visited[sr][sc] = true;

    int dr[] = {1, 0, -1, 0 };
    int dc[] = {0, -1, 0, 1 };
    for ( int i = 0 ; i < 4 ; i++ ){
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if ( nr >= 0  && nr < nrows && nc >= 0 && nc < ncolumns && grid[nr][nc] == sourceColor && !visited[nr][nc] ){
            dfs ( grid, nr, nc, visited );
        }
    }
    return;

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    int nrows = image.size(), ncolumns = image[0].size();
    vector<vector<bool>> visited ( nrows, vector<bool>(ncolumns, false) );
    bfs ( image, sr, sc, visited );

    vector<vector<int>> ans = image;
    for ( int ir = 0 ; ir < nrows ; ir++ ){
        for ( int jc = 0 ; jc < ncolumns ; jc++ ){
            if ( visited[ir][jc] ){
                ans[ir][jc] = newColor;
            }
        }
    }
    return ans;

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

