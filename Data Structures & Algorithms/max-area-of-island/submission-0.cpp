class Solution {
public:
 int dfs(int r,int c,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    
    if(r<0 || c<0 || r>=n||c>=m|| grid[r][c]==0) return 0 ;
       grid[r][c]=0;
       int area=1;
       
       area+= dfs(r,c-1,grid);
       area+=dfs(r,c+1,grid);
       area+=dfs(r-1,c,grid);
       area+=dfs(r+1,c,grid);
       return area;
 }





    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row=grid.size();
        int col=grid[0].size();
        int maxisland=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    int area=dfs(r,c,grid);
                    maxisland=max(area,maxisland);

                }

            }
        }
        return maxisland;
    }
};
