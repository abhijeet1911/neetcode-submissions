class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mpp;
        int len=0;
        int maxlen=0;
        int i=0;
        
       for(int j=0;j<n;j++){
        if(mpp.find(s[j])!=mpp.end()&&mpp[s[j]]>=i){
            i=mpp[s[j]]+1;

        }
        mpp[s[j]]=j;
        len=j-i+1;
        maxlen=max(maxlen,len);
       }
       return maxlen;
    }
};
