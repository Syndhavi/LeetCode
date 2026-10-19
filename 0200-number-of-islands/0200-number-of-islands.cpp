class Solution {
    void bfs(int row,int col,vector<vector<int>>& vis,const vector<vector<char>>& grid){
        vis[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                    int nrow=r+delrow[i];
                    int ncol=c+delcol[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(!vis[r][c] && grid[r][c]=='1'){
                    cnt++;
                    bfs(r,c,vis,grid);
                }
            }
        }
        return cnt;
    }
};