class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int area=0;
        int maxarea=0;
        int i=0;
        int j=n-1;
        while(i<j){
            int w=j-i;
            int h=min(heights[i],heights[j]);
            area=w*h;
            maxarea=max(area,maxarea);
            if(heights[i]>heights[j]) j--;
            else i++;
        }

      return maxarea;  
    }
};
