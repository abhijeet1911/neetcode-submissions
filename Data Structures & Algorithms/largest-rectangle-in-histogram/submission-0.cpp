class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>rightsmaller(n);
        vector<int>leftsmaller(n);
        int area=0;
        int maxarea=0;
        int width;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            rightsmaller[i]=st.empty()?n:st.top();
            st.push(i);

        }
        st={};
         for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            leftsmaller[i]=st.empty()?-1:st.top();
            st.push(i);

        }
        
        for(int i=0;i<n;i++){
            width=rightsmaller[i]-leftsmaller[i]-1;
            area=width*heights[i];
            maxarea=max(area,maxarea);

        }
        return maxarea;

    }
};
