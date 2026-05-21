class Solution {
public:
   vector<int>getleftmax(vector<int>height,int n){
    vector<int>l(n);
    l[0]=height[0];
    for(int i=1;i<n;i++){
        l[i]=max(l[i-1],height[i]);
    }
    return l;

   }
   vector<int>getrightmax(vector<int>height,int n){
    vector<int>r(n);
    r[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        r[i]=max(r[i+1],height[i]);
    }
    return r;
    
   }
 
    int trap(vector<int>& height) {
     int n=height.size();
     vector<int>leftmax=getleftmax(height,n);
     vector<int>rightmax=getrightmax(height,n);
     int sum=0;
     for(int i=0;i<n;i++){
        int h=min(leftmax[i],rightmax[i])-height[i];
        sum+=h;

     }
        
     return sum;
    
    }
};
