class Solution {
private:
    void bfs(int i,int j,const vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int x=0;x<4;x++){
                int nrow=r+delrow[x];
                int ncol=c+delcol[x];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(grid[0][i]==1 && vis[0][i]==0) bfs(0,i,grid,vis);
            if(grid[m-1][i]==1 && vis[m-1][i]==0) bfs(m-1,i,grid,vis);
        }
        for(int i=1;i<m-1;i++){
            if(grid[i][0]==1 && vis[i][0]==0) bfs(i,0,grid,vis);
            if(grid[i][n-1]==1 && vis[i][n-1]==0) bfs(i,n-1,grid,vis);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};