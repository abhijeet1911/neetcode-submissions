class Solution {
public:
 void dfs(int r,int c,vector<vector<char>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    if(r<0 || c<0 || r>=n||c>=m|| grid[r][c]=='0') return ;
       grid[r][c]='0';
       dfs(r,c-1,grid);
       dfs(r,c+1,grid);
       dfs(r-1,c,grid);
       dfs(r+1,c,grid);
 }



    int numIslands(vector<vector<char>>& grid) {
         if(grid.empty()) return 0;
        int row=grid.size();
        int col=grid[0].size();
        int island=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]=='1'){
                    island++;
                    dfs(r,c,grid);

                }

            }
        }
        return island;
    }
};
