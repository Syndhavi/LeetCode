class Solution {
private:
    void bfs(int i,int j,int orig_color,const vector<vector<int>>& image,vector<vector<int>>& vis){
        vis[i][j]=1;
        int m=image.size();
        int n=image[0].size();
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
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && image[nrow][ncol]==orig_color){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int orig_color=image[sr][sc];
        bfs(sr,sc,orig_color,image,vis);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1) image[i][j]=color;
            }
        }
        return image;
    }
};