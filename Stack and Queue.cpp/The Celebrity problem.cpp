class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        int top = 0;
        int bottom = n-1;
        
        while(top < bottom){
            if(mat[top][bottom] == 0 && mat[bottom][top] == 0){
                top++;
                bottom--;
                continue;
            }
            
            if(mat[top][bottom] == 1){
                top++;
            }
            
            if(mat[bottom][top] == 1){
                bottom--;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(i == top) continue;
            if(mat[top][i] != 0) return -1;
            if(mat[i][top] != 1) return -1;
        }
        
        return top;
    }
};