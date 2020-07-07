class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
         int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int tmp=ans;
                if(grid[i][j]){
                    if(i==0)
                        ans++;
                    if(j==0)
                        ans++;
                    if(i==grid.size()-1)
                        ans++;
                    if(j==grid[0].size()-1)
                        ans++;
                    if(i>0 and grid[i-1][j]==0)
                        ans++;
                    if(i+1<grid.size() and grid[i+1][j]==0)
                        ans++;
                    if(j>0 and grid[i][j-1]==0)
                        ans++;
                    if(j+1<grid[0].size() and grid[i][j+1]==0)
                        ans++;
                }
            }
        }
        return ans;
    }
};
