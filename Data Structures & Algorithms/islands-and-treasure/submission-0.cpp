class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0) return ;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    q.push({i,j});
                }
            }}
            vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();
                for(auto dir:dirs){
                    int nr=r+dir.first;
                    int nc=c+dir.second;
        if(nr>=0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 2147483647){
            grid[nr][nc]=1+grid[r][c];
            q.push({nr,nc});
        }
               
                }

                
            }
            
      
    }
};
