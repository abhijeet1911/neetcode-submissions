class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int left=0;
        int right=n-1;
        int down=m-1;
        int dir=0;
        vector<int>result;
        while(top<=down  && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
                
                }
                top++;
                dir++;
            }
              if(dir==1){
                for(int i=top;i<=down;i++){
                result.push_back(matrix[i][right]);
                
                }
                right--;
                dir++;
            }
              if(dir==2){
                if(top<=down){
                for(int i=right;i>=left;i--){
                result.push_back(matrix[down][i]);
                
                }
                down--;}
                dir++;
            }
            if(dir==3){
                if(left<=right){
                for(int i=down;i>=top;i--){
                result.push_back(matrix[i][left]);
                
                }
                left++;}
                dir++;
            }
            if(dir==4){
                dir=0;
            }
        }
        return result;
    }
};
