class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int m=matrix.size();
     int n=matrix[0].size();
     int i=0;
     int j=m*n-1;
     while(i<=j){
        int mid=i+(j-i)/2;
        if(matrix[mid/n][mid%n]>target) j=mid-1;
        else if(matrix[mid/n][mid%n]<target) i=mid+1;
        else return true;
     }
     return false;


    }
};
